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

bool TPolynom::IsOperator(const string& isopr) const {
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
	
	monoms->Reset();
	while (!monoms->IsEnded()) {
		TMonom* curr = &monoms->GetCurrent()->key;
		
		if (m == *curr) {
			double coeff = m.get_coeff() + (*curr).get_coeff();
			if (coeff == 0.0f) {
				monoms->Remove(*curr);
				return;
			}
			else {
				(*curr).set_coeff(coeff);
				return;
			}
		}

		else if (m < *curr) {
			monoms->InsertBefore(m);
			return;
		}

		else {
			monoms->Next();
		}
	}
	
	monoms->InsertLast(m);
}


TPolynom::TPolynom() {
	monoms = new TList<TMonom>;
}
TPolynom::TPolynom(const string& _name) {
	monoms = new TList<TMonom>;
	string name = _name;

	Parse(name);
}
TPolynom::TPolynom(const TList<TMonom>& ringlist) {
	monoms = new TList<TMonom>(ringlist);

}
TPolynom::TPolynom(TPolynom& polynom) {
	monoms = new TList<TMonom>(*polynom.monoms);
}
TPolynom::~TPolynom() {
	if (monoms) delete monoms;
}




const TPolynom& TPolynom::operator=(TPolynom& polynom) {
	if (monoms) delete monoms;
	monoms = new TList<TMonom>(*polynom.monoms);

	return (*this);
}

TPolynom TPolynom::operator+(TPolynom& polynom) {
	TPolynom res(*this);

	polynom.monoms->Reset();
	while (!polynom.monoms->IsEnded()) {
		TMonom curr_monom = polynom.monoms->GetCurrent()->key;
		res.AddMonom(curr_monom);
		polynom.monoms->Next();
	}

	return res;
}
TPolynom TPolynom::operator-(TPolynom& polynom) {
	TPolynom res(*this);

	polynom.monoms->Reset();
	while (!polynom.monoms->IsEnded()) {
		TMonom curr_monom = polynom.monoms->GetCurrent()->key;
		curr_monom.set_coeff((-1) * curr_monom.get_coeff());
		res.AddMonom(curr_monom);
		polynom.monoms->Next();
	}

	return res;
}
TPolynom TPolynom::operator*(TPolynom& polynom) {
	TPolynom res;
	
	monoms->Reset();
	while (!monoms->IsEnded()) {
		TMonom curr1 = monoms->GetCurrent()->key;
		
		polynom.monoms->Reset();
		while (!polynom.monoms->IsEnded()) {
			TMonom curr2 = polynom.monoms->GetCurrent()->key;
			res.AddMonom(curr1 * curr2);
			polynom.monoms->Next();
		}
		
		monoms->Next();
	}

	return res;
}
double TPolynom::operator()(double x, double y, double z) {
	double res = 0;

	monoms->Reset();
	while (!monoms->IsEnded()) {
		res += monoms->GetCurrent()->key.value(x, y, z);
		monoms->Next();
	}

	return res;
}

TPolynom TPolynom::dif_x() {
	TPolynom res;
	
	monoms->Reset();
	while (!monoms->IsEnded()) {
		TMonom monom = monoms->GetCurrent()->key.dif_x();
		res.AddMonom(monom);
		monoms->Next();
	}

	return res;
}
TPolynom TPolynom::dif_y() {
	TPolynom res;

	monoms->Reset();
	while (!monoms->IsEnded()) {
		TMonom monom = monoms->GetCurrent()->key.dif_y();
		res.AddMonom(monom);
		monoms->Next();
	}

	return res;
}
TPolynom TPolynom::dif_z() {
	TPolynom res;

	monoms->Reset();
	while (!monoms->IsEnded()) {
		TMonom monom = monoms->GetCurrent()->key.dif_z();
		res.AddMonom(monom);
		monoms->Next();
	}

	return res;
}


string TPolynom::get_string() {
	string res = "";
	monoms->Reset();
	
	
	if (monoms->IsEnded()) {
		return res;
	} 
	else {
		res += monoms->GetCurrent()->key.get_string();
		monoms->Next();
		while (!monoms->IsEnded()) {
			string monom = monoms->GetCurrent()->key.get_string();
			if (monom[0] == '-') res += monom;
			else res += "+" + monom;
			monoms->Next();
		}
	}	
	return res;
}
ostream& operator<<(ostream& out, TPolynom& monom) {
	return out << monom.get_string();
}
