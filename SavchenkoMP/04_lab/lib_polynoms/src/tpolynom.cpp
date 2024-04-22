#include "tpolynom.h"

map<string, int> TPolynom::priority = {
	{"^", 4},
	{"*", 3},
	{"/", 3},
	{"+", 2},
	{"-", 2},
	{"(", 1},
	{")", 1}
};

bool TPolynom::IsOperator(const string& isopr) const { // opr : priority can't be char 
	bool flag = false;
	for (const auto& opr : priority) {
		if (isopr == opr.first) {
			flag = true;
			break;
		}
	}
	return flag;
}
bool TPolynom::IsConst(const string& isopd) const {
	bool flag = true;
	for (int i = 0; i < isopd.size(); i++)
		if (isopd[i] < '0' || isopd[i] > '9') {
			if (isopd[i] != '.')
				flag = false;
			break;
		}
	return flag;
}
bool TPolynom::IsVariable(const string& str) const {
	return (str == "x" || str == "y" || str == "z");
}

// If found any operator, returns index. Else returns -1.
int TPolynom::FindOperator(const string& name, int pos) const {
	if (pos < 0 || pos >= infix.size()) return -1;

	int ind = -1;
	for (int i = pos; i < infix.size(); i++) {
		string isopr;
		isopr += infix[i];

		if (IsOperator(isopr)) {
			ind = i;
			break;
		}
	}
	return ind;
}

void TPolynom::ConvertInfix(string& name) {
	string nospaces;
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] != ' ')
			nospaces += infix[i];
	}
	infix = nospaces;

	string tmp;
	if (infix[0] == '-') tmp += "0-";
	else if (infix[0] == '.') tmp += "0.";
	else if (infix[0] == '(') tmp += '(';
	else tmp += infix[0];

	for (int i = 1; i < infix.size() - 1; i++) {
		char elem = infix[i];
		if (elem == ' ') {
			continue;
		}
		else if (elem == '-') {
			if (infix[i - 1] == '(')
				tmp += '0';
			tmp += '-';
		}
		else if (elem == '(') {
			if (infix[i - 1] == ')' || infix[i - 1] == '.' || (infix[i - 1] >= '0' && infix[i - 1] <= '9'))
				tmp += '*';
			tmp += '(';
		}
		else if (elem == '.') {
			if (infix[i - 1] < '0' || infix[i - 1] > '9') {
				if (infix[i - 1] == ')')
					tmp += '*';
				tmp += '0';
			}
			tmp += '.';
			if (infix[i + 1] < '0' || infix[i + 1] > '9') {
				tmp += '0';
				if (infix[i + 1] == '(')
					tmp += '*';
			}
		}
		else if (elem >= '0' && elem <= '9') {
			if (infix[i - 1] == ')')
				tmp += '*';
			tmp += elem;
		}
		else {
			tmp += elem;
		}
	}
	if (infix[infix.size() - 1] == '.') tmp += ".0";
	else if (infix[infix.size() - 1] == ')') tmp += ')';
	else tmp += infix[infix.size() - 1];
	infix = tmp;
}

void TPolynom::CorrectnessCheck(const string& name) const {
	int op_bracket = 0;
	int cl_bracket = 0;
	int dot = 0;

	string exp = "Incorrect arithmetic expression";

	if (infix[0] == '+' || infix[0] == '*' || infix[0] == '/' ||
		infix[0] == ')' || infix[0] == '^') throw exp;
	if (infix[infix.size() - 1] == '+' || infix[infix.size() - 1] == '-' ||
		infix[infix.size() - 1] == '*' || infix[infix.size() - 1] == '/' ||
		infix[infix.size() - 1] == '(' || infix[infix.size() - 1] == '^') throw exp;

	if (infix[0] == '(') op_bracket++;
	else if (infix[0] == '.') dot++;
	if (infix[infix.size() - 1] == ')') cl_bracket++;
	else if (infix[infix.size() - 1] == '.') dot++;

	for (int i = 1; i < infix.size() - 1; i++) {
		char elem = infix[i];
		if (elem == '(')
			op_bracket++;
		else if (elem == ')') {
			if (infix[i - 1] == '(' || infix[i - 1] == '+' || infix[i - 1] == '-' ||
				infix[i - 1] == '*' || infix[i - 1] == '/' || infix[i - 1] == '^') throw exp;
			cl_bracket++;
		}
		else if (elem == '.')
			dot++;
		else if (elem == '+' || elem == '-' || elem == '*' || elem == '/' || elem == '^') {
			if (dot > 1) throw exp;
			dot = 0;
			if (infix[i - 1] == '+' || infix[i - 1] == '-' || infix[i - 1] == '*' ||
				infix[i - 1] == '/' || infix[i - 1] == '(' || infix[i - 1] == '^') throw exp;
		}
	}
	if (op_bracket != cl_bracket) throw exp;
}

void TPolynom::Parse(string& name) {
	ConvertInfix(name);
	CorrectnessCheck(name);

	vector<string> lexems;
	int firstind, secondind;
	string token;

	firstind = FindOperator(name);
	secondind = FindOperator(name, firstind + 1);
	if (firstind == -1) {
		lexems.push_back(infix);
		return;
	}
	if (firstind > 0) {
		lexems.push_back(infix.substr(0, firstind));
	}
	while (secondind != -1) {
		string opr = infix.substr(firstind, 1);
		string opd = infix.substr(firstind + 1, secondind - firstind - 1);

		lexems.push_back(opr);
		if (opd != "")
			lexems.push_back(opd);
		firstind = secondind;
		secondind = FindOperator(name, firstind + 1);
	}
	lexems.push_back(infix.substr(firstind, 1));
	if (firstind != infix.size() - 1)
		lexems.push_back(infix.substr(firstind + 1));

	ToMonoms(lexems);
}


// ======================================================= //

void TPolynom::ToMonoms(vector<string>& _lexems) {
	double coeff = 1;
	int degX = 0, degY = 0, degZ = 0;
	int next_const_sign = 1;

	vector<string> lexems;
	for (const string& token : _lexems) {
		if (token != "*" && token != "^") {
			lexems.push_back(token);
		}
	}

	for (int i = 0; i < lexems.size(); i++) {
		if (lexems[i] == "+" || lexems[i] == "-") {
			TMonom monom(next_const_sign * coeff, degX, degY, degZ);
			AddMonom(monom);

			if (lexems[i] == "+") next_const_sign = 1;
			else next_const_sign = -1;
			coeff = 1;
			degX = 0;
			degY = 0;
			degZ = 0;
		}
		else {

			if (lexems[i] == "x") {
				if (i < lexems.size() - 1) {
					if (!IsVariable(lexems[i + 1]) && !IsOperator(lexems[i + 1])) {
						degX += stoi(lexems[i + 1]);
						i++;
					}
					else {
						degX += 1;
					}
				}
				else {
					degX += 1;
				}
			}

			else if (lexems[i] == "y") {
				if (i < lexems.size() - 1) {
					if (!IsVariable(lexems[i + 1]) && !IsOperator(lexems[i + 1])) {
						degY += stoi(lexems[i + 1]);
						i++;
					}
					else {
						degY += 1;
					}
				}
				else {
					degY += 1;
				}
			}

			else if (lexems[i] == "z") {
				if (i < lexems.size() - 1) {
					if (!IsVariable(lexems[i + 1]) && !IsOperator(lexems[i + 1])) {
						degZ += stoi(lexems[i + 1]);
						i++;
					}
					else {
						degZ += 1;
					}
				}
				else {
					degZ += 1;
				}
			}

			else {
				if (!IsConst(lexems[i])) {
					string exp = "Error: not valid operand";
					throw exp;
				}
				coeff *= stod(lexems[i]);
			}
		}
	}

	TMonom monom(next_const_sign * coeff, degX, degY, degZ);
	AddMonom(monom);
}


void TPolynom::AddMonom(const TMonom& m) {
	if (m.get_coeff() == 0) return;

	//TNode<TMonom>* tmp = monoms->first();
	while (!monoms->IsEnded()) {
		TNode<TMonom>* curr = monoms->GetCurrent();

		if (m == curr->key) {
			double coeff = m.get_coeff() + curr->key.get_coeff();
			if (coeff == 0.0f) {
				monoms->Remove(curr->key);
				return;
			}
			else {
				curr->key.set_coeff(coeff);
				return;
			}
		}

		else if (m < curr->key) {
			monoms->InsertBefore(m, curr->key);
			return;
		}

		else {
			monoms->Next();
		}
	}

	monoms->InsertLast(m);
}


TPolynom::TPolynom() {
	monoms = new TRingList<TMonom>;
}
TPolynom::TPolynom(const string& _name) {
	monoms = new TRingList<TMonom>;
	string name = _name;

	Parse(name);
}
TPolynom::TPolynom(TRingList<TMonom>& ringlist) {
	//monoms = new TRingList<TMonom>(ringlist); // œ–Œ¬≈–»“‹ Õ¿ ”œŒ–ﬂƒŒ◊≈ÕÕŒ—“‹
	monoms = new TRingList<TMonom>;

	ringlist.Reset();
	while (!ringlist.IsEnded()) {
		AddMonom(ringlist.GetCurrent()->key);
		ringlist.Next();
	}
	ringlist.Reset();
}
TPolynom::TPolynom(TPolynom& polynom) {
	monoms = new TRingList<TMonom>(*polynom.monoms);
}
TPolynom::~TPolynom() {
	if (monoms) delete monoms;
}




const TPolynom& TPolynom::operator=(const TPolynom& polynom) {
	if (this == &polynom) return (*this);

	if (monoms) delete monoms;
	monoms = new TRingList<TMonom>(*polynom.monoms);

	return (*this);
}


TPolynom TPolynom::operator+(TPolynom& polynom){
	TPolynom res(*this);

	polynom.Reset();
	while (!polynom.IsEnded()) {
		TMonom curr_monom = polynom.GetCurrentMonom();
		res.AddMonom(curr_monom);
		polynom.Next();
	}
	polynom.Reset();

	/*
	polynom.monoms->Reset();
	TNode<TMonom>* tmp_p = polynom.monoms->first();
	while (tmp_p != polynom.monoms->stop()) { // !this->monoms.IsEnded()
		TMonom curr_monom = tmp_p->key;
		res.AddMonom(curr_monom);
		tmp_p = tmp_p->pNext;
	}
	*/

	return res;
}
TPolynom TPolynom::operator-() {
	TPolynom res(*this);

	res.Reset();
	while (!res.IsEnded()) {
		TNode<TMonom>* curr = res.GetCurrent();
		double coeff = (-1) * curr->key.get_coeff();
		curr->key.set_coeff(coeff);
		res.Next();
	}
	res.Reset();

	/*
	TNode<TMonom>* tmp = res.monoms->first();
	while (tmp != res.monoms->stop()) { // !this->monoms.IsEnded()
		double coeff = (-1) * tmp->key.get_coeff();
		tmp->key.set_coeff(coeff);
		tmp = tmp->pNext;
	}
	*/

	return res;
}
TPolynom TPolynom::operator-(TPolynom& polynom) {
	TPolynom res(-polynom + (*this));

	return res;
}
TPolynom TPolynom::operator*(TPolynom& polynom) {
	TPolynom res;

	Reset();
	while (!IsEnded()) {
		TMonom curr1 = GetCurrentMonom();

		polynom.Reset();
		while (!polynom.IsEnded()) {
			TMonom curr2 = polynom.GetCurrentMonom();
			res.AddMonom(curr1 * curr2);
			polynom.Next();
		}

		Next();
	}

	polynom.Reset();
	Reset();

	/*
	TNode<TMonom>* tmp = monoms->first();
	while (tmp != monoms->stop()) { // !this->monoms.IsEnded()
		TMonom curr1 = tmp->key;

		TNode<TMonom>* tmp_p = polynom.monoms->first();
		while (tmp_p != polynom.monoms->stop()) { // !this->monoms.IsEnded()
			TMonom curr2 = tmp_p->key;
			res.AddMonom(curr1 * curr2);
			tmp_p = tmp_p->pNext;
		}

		tmp = tmp->pNext;
	}
	*/

	return res;
}
double TPolynom::operator()(double x, double y, double z) {
	double res = 0;

	Reset();
	while (!IsEnded()) {
		res += GetCurrentMonom()(x, y, z);
		Next();
	}
	Reset();

	/*
	TNode<TMonom>* tmp = monoms->first();
	while (tmp != monoms->stop()) {
		res += tmp->key(x, y, z);
		tmp = tmp->pNext;
	}
	*/

	return res;
}


TPolynom TPolynom::dif_x() {
	TPolynom res;

	Reset();
	while (!IsEnded()) {
		res.AddMonom(GetCurrentMonom().dif_x());
		Next();
	}
	Reset();

	/*
	TNode<TMonom>* tmp = monoms->first();
	while (tmp != monoms->stop()) {
		TMonom monom = tmp->key.dif_x();
		res.AddMonom(monom);
		tmp = tmp->pNext;
	}
	*/

	return res;
}
TPolynom TPolynom::dif_y() {
	TPolynom res;

	Reset();
	while (!IsEnded()) {
		res.AddMonom(GetCurrentMonom().dif_y());
		Next();
	}
	Reset();

	/*
	TNode<TMonom>* tmp = monoms->first();
	while (tmp != monoms->stop()) {
		TMonom monom = tmp->key.dif_y();
		res.AddMonom(monom);
		tmp = tmp->pNext;
	}
	*/

	return res;
}
TPolynom TPolynom::dif_z() {
	TPolynom res;

	Reset();
	while (!IsEnded()) {
		res.AddMonom(GetCurrentMonom().dif_z());
		Next();
	}
	Reset();

	/*
	TNode<TMonom>* tmp = monoms->first();
	while (tmp != monoms->stop()) {
		TMonom monom = tmp->key.dif_z();
		res.AddMonom(monom);
		tmp = tmp->pNext;
	}
	*/

	return res;
}


string TPolynom::get_string() {
	if (monoms->GetSize() == 0) return "0.000000";

	string res = "";
	Reset();
	if (GetCurrent() == nullptr) {
		return res;
	}
	else {
		res += GetCurrentMonom().get_string();
		Next();
		while (!IsEnded()) {
			string monom = GetCurrentMonom().get_string();
			if (monom[0] == '-') res += monom;
			else res += "+" + monom;
			Next();
		}
	}
	Reset();

	/*
	string res = "";
	TNode<TMonom>* tmp = monoms->first();


	if (tmp == monoms->stop()) {
		return res;
	}
	else {
		res += tmp->key.get_string();
		tmp = tmp->pNext;
		while (tmp != monoms->stop()) {
			string monom = tmp->key.get_string();
			if (monom[0] == '-') res += monom;
			else res += "+" + monom;
			tmp = tmp->pNext;
		}
	}
	*/

	return res;
}
ostream& operator<<(ostream& out, TPolynom& monom) {
	return out << monom.get_string();
}



void TPolynom::Reset() {
	monoms->Reset();
}
void TPolynom::Next() {
	monoms->Next();
}
bool TPolynom::IsEnded() {
	return monoms->IsEnded();
}
TNode<TMonom>* TPolynom::GetCurrent() {
	return monoms->GetCurrent();
}
TMonom TPolynom::GetCurrentMonom() {
	return monoms->GetCurrent()->key;
}