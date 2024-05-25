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

bool TPolynom::is_operator(const string& isopr) const { // opr : priority can't be char 
	bool flag = false;
	for (const auto& opr : priority) {
		if (isopr == opr.first) {
			flag = true;
			break;
		}
	}
	return flag;
}
bool TPolynom::is_const(const string& isopd) const {
	bool flag = true;
	for (int i = 0; i < isopd.size(); i++)
		if (isopd[i] < '0' || isopd[i] > '9') {
			if (isopd[i] != '.')
				flag = false;
			break;
		}
	return flag;
}
bool TPolynom::is_variable(const string& str) const {
	return (str == "x" || str == "y" || str == "z");
}

// If found any operator, returns index. Else returns -1.
int TPolynom::find_operator(const string& name, int pos) const {
	if (pos < 0 || pos >= name.size()) return -1;

	int ind = -1;
	for (int i = pos; i < name.size(); i++) {
		string isopr;
		isopr += name[i];

		if (is_operator(isopr)) {
			ind = i;
			break;
		}
	}
	return ind;
}

void TPolynom::convert_infix(string& name) {
	string nospaces;
	for (int i = 0; i < name.size(); i++) {
		if (name[i] != ' ')
			nospaces += name[i];
	}
	name = nospaces;

	string tmp;
	if (name[0] == '-') tmp += "0-";
	else if (name[0] == '.') tmp += "0.";
	else if (name[0] == '(') tmp += '(';
	else tmp += name[0];

	for (int i = 1; i < name.size() - 1; i++) {
		char elem = name[i];
		if (elem == ' ') {
			continue;
		}
		else if (elem == '-') {
			if (name[i - 1] == '(')
				tmp += '0';
			tmp += '-';
		}
		else if (elem == '(') {
			if (name[i - 1] == ')' || name[i - 1] == '.' || (name[i - 1] >= '0' && name[i - 1] <= '9'))
				tmp += '*';
			tmp += '(';
		}
		else if (elem == '.') {
			if (name[i - 1] < '0' || name[i - 1] > '9') {
				if (name[i - 1] == ')')
					tmp += '*';
				tmp += '0';
			}
			tmp += '.';
			if (name[i + 1] < '0' || name[i + 1] > '9') {
				tmp += '0';
				if (name[i + 1] == '(')
					tmp += '*';
			}
		}
		else if (elem >= '0' && elem <= '9') {
			if (name[i - 1] == ')')
				tmp += '*';
			tmp += elem;
		}
		else {
			tmp += elem;
		}
	}
	if (name[name.size() - 1] == '.') tmp += ".0";
	else if (name[name.size() - 1] == ')') tmp += ')';
	//else tmp += name[name.size() - 1];
	else if (tmp.size() != 1) tmp += name[name.size() - 1];
	name = tmp;
}

void TPolynom::correctness_check(const string& name) const {
	int op_bracket = 0;
	int cl_bracket = 0;
	int dot = 0;

	string exp = "Incorrect arithmetic expression";

	if (name[0] == '+' || name[0] == '*' || name[0] == '/' ||
		name[0] == ')' || name[0] == '^') throw exp;
	if (name[name.size() - 1] == '+' || name[name.size() - 1] == '-' ||
		name[name.size() - 1] == '*' || name[name.size() - 1] == '/' ||
		name[name.size() - 1] == '(' || name[name.size() - 1] == '^') throw exp;

	if (name[0] == '(') op_bracket++;
	else if (name[0] == '.') dot++;
	if (name[name.size() - 1] == ')') cl_bracket++;
	else if (name[name.size() - 1] == '.') dot++;

	for (int i = 1; i < name.size() - 1; i++) {
		char elem = name[i];
		if (elem == '(')
			op_bracket++;
		else if (elem == ')') {
			if (name[i - 1] == '(' || name[i - 1] == '+' || name[i - 1] == '-' ||
				name[i - 1] == '*' || name[i - 1] == '/' || name[i - 1] == '^') throw exp;
			cl_bracket++;
		}
		else if (elem == '.')
			dot++;
		else if (elem == '+' || elem == '-' || elem == '*' || elem == '/' || elem == '^') {
			if (dot > 1) throw exp;
			dot = 0;
			if (name[i - 1] == '+' || name[i - 1] == '-' || name[i - 1] == '*' ||
				name[i - 1] == '/' || name[i - 1] == '(' || name[i - 1] == '^') throw exp;
		}
	}
	if (op_bracket != cl_bracket) throw exp;
}

void TPolynom::parse(string& name) {
	convert_infix(name);
	correctness_check(name);

	vector<string> lexems;
	int firstind, secondind;
	string token;

	firstind = find_operator(name);
	secondind = find_operator(name, firstind + 1);
	if (firstind == -1) {
		lexems.push_back(name);
		to_monoms(lexems);
		return;
	}
	if (firstind > 0) {
		lexems.push_back(name.substr(0, firstind));
	}
	while (secondind != -1) {
		string opr = name.substr(firstind, 1);
		string opd = name.substr(firstind + 1, secondind - firstind - 1);

		lexems.push_back(opr);
		if (opd != "")
			lexems.push_back(opd);
		firstind = secondind;
		secondind = find_operator(name, firstind + 1);
	}
	lexems.push_back(name.substr(firstind, 1));
	if (firstind != name.size() - 1)
		lexems.push_back(name.substr(firstind + 1));

	to_monoms(lexems);
}


// ======================================================= //

void TPolynom::to_monoms(vector<string>& _lexems) {
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
			add_monom(monom);

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
					if (!is_variable(lexems[i + 1]) && !is_operator(lexems[i + 1])) {
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
					if (!is_variable(lexems[i + 1]) && !is_operator(lexems[i + 1])) {
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
					if (!is_variable(lexems[i + 1]) && !is_operator(lexems[i + 1])) {
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
				if (!is_const(lexems[i])) {
					string exp = "Error: not valid operand";
					throw exp;
				}
				coeff *= stod(lexems[i]);
			}
		}
	}

	TMonom monom(next_const_sign * coeff, degX, degY, degZ);
	add_monom(monom);
}


void TPolynom::add_monom(const TMonom& m) {
	if (m.get_coeff() == 0) return;

	while (!monoms->ended()) {
		TNode<TMonom>* curr = monoms->get_curr();

		if (m == curr->data) {
			double coeff = m.get_coeff() + curr->data.get_coeff();
			if (coeff == 0.0f) {
				monoms->remove(curr->data);
				return;
			}
			else {
				curr->data.set_coeff(coeff);
				return;
			}
		}

		else if (m < curr->data) {
			monoms->insert_before(m, curr->data);
			return;
		}

		else {
			monoms->next();
		}
	}

	monoms->insert_last(m);
}


TPolynom::TPolynom() {
	monoms = new TRingList<TMonom>;
}
TPolynom::TPolynom(const string& _name) {
	monoms = new TRingList<TMonom>;
	string name = _name;
	if (name.size() == 0) name += "0";

	parse(name);
}
TPolynom::TPolynom(TRingList<TMonom>& ringlist) {
	monoms = new TRingList<TMonom>;

	ringlist.reset();
	while (!ringlist.ended()) {
		add_monom(ringlist.get_curr()->data);
		ringlist.next();
	}
	ringlist.reset();
}
TPolynom::TPolynom(TPolynom& polynom) {
	monoms = new TRingList<TMonom>(*polynom.monoms);
}
TPolynom::~TPolynom() {
	if (monoms) delete monoms;
}


bool TPolynom::operator<(TPolynom& polynom) {
	reset();
	while (!ended()) {
		polynom.reset();
		while (!polynom.ended()) {
			if (!(get_current_monom() < polynom.get_current_monom())) {
				return false;
			}
			polynom.next();
		}
		next();
	}
	reset();
	polynom.reset();
	return true;
}
bool TPolynom::operator>(TPolynom& polynom) {
	reset();
	while (!ended()) {
		polynom.reset();
		while (!polynom.ended()) {
			if (!(get_current_monom() >= polynom.get_current_monom())) {
				return false;
			}
			polynom.next();
		}
		next();
	}
	reset();
	polynom.reset();
	return true;
}
bool TPolynom::operator<=(TPolynom& polynom) {
	reset();
	while (!ended()) {
		polynom.reset();
		while (!polynom.ended()) {
			if (!(get_current_monom() <= polynom.get_current_monom())) {
				return false;
			}
			polynom.next();
		}
		next();
	}
	reset();
	polynom.reset();
	return true;
}
bool TPolynom::operator>=(TPolynom& polynom) {
	reset();
	while (!ended()) {
		polynom.reset();
		while (!polynom.ended()) {
			if (!(get_current_monom() >= polynom.get_current_monom())) {
				return false;
			}
			polynom.next();
		}
		next();
	}
	reset();
	polynom.reset();
	return true;
}
bool TPolynom::operator==(TPolynom& polynom) {
	reset();
	while (!ended()) {
		polynom.reset();
		while (!polynom.ended()) {
			if (!(get_current_monom() == polynom.get_current_monom())) {
				return false;
			}
			polynom.next();
		}
		next();
	}
	reset();
	polynom.reset();
	return true;
}
bool TPolynom::operator!=(TPolynom& polynom) {
	return !((*this) == polynom);
}


const TPolynom& TPolynom::operator=(const TPolynom& polynom) {
	if (this == &polynom) return (*this);

	if (monoms) delete monoms;
	monoms = new TRingList<TMonom>(*polynom.monoms);

	return (*this);
}


TPolynom TPolynom::operator+(TPolynom& polynom) {
	TPolynom res(*this);

	polynom.reset();
	while (!polynom.ended()) {
		TMonom curr_monom = polynom.get_current_monom();
		res.add_monom(curr_monom);
		polynom.next();
	}
	polynom.reset();

	return res;
}
TPolynom TPolynom::operator-() {
	TPolynom res(*this);

	res.reset();
	while (!res.ended()) {
		TNode<TMonom>* curr = res.get_curr();
		double coeff = (-1) * curr->data.get_coeff();
		curr->data.set_coeff(coeff);
		res.next();
	}
	res.reset();

	return res;
}
TPolynom TPolynom::operator-(TPolynom& polynom) {
	TPolynom res(-polynom + (*this));

	return res;
}
TPolynom TPolynom::operator*(TPolynom& polynom) {
	TPolynom res;

	reset();
	while (!ended()) {
		TMonom curr1 = get_current_monom();

		polynom.reset();
		while (!polynom.ended()) {
			TMonom curr2 = polynom.get_current_monom();
			res.add_monom(curr1 * curr2);
			polynom.next();
		}

		next();
	}

	polynom.reset();
	reset();

	return res;
}
double TPolynom::operator()(double x, double y, double z) {
	double res = 0;

	reset();
	while (!ended()) {
		res += get_current_monom()(x, y, z);
		next();
	}
	reset();

	return res;
}


TPolynom TPolynom::dif_x() {
	TPolynom res;

	reset();
	while (!ended()) {
		res.add_monom(get_current_monom().dif_x());
		next();
	}
	reset();

	return res;
}
TPolynom TPolynom::dif_y() {
	TPolynom res;

	reset();
	while (!ended()) {
		res.add_monom(get_current_monom().dif_y());
		next();
	}
	reset();

	return res;
}
TPolynom TPolynom::dif_z() {
	TPolynom res;

	reset();
	while (!ended()) {
		res.add_monom(get_current_monom().dif_z());
		next();
	}
	reset();

	return res;
}


string TPolynom::get_string() {
	if (monoms->size() == 0) return "0.000000";

	string res = "";
	reset();
	if (get_curr() == nullptr) {
		return res;
	}
	else {
		res += get_current_monom().get_string();
		next();
		while (!ended()) {
			string monom = get_current_monom().get_string();
			if (monom[0] == '-') res += monom;
			else res += "+" + monom;
			next();
		}
	}
	reset();

	return res;
}
ostream& operator<<(ostream& out, TPolynom& monom) {
	return out << monom.get_string();
}



void TPolynom::reset() {
	monoms->reset();
}
void TPolynom::next() {
	monoms->next();
}
bool TPolynom::ended() {
	return monoms->ended();
}
TNode<TMonom>* TPolynom::get_curr() {
	return monoms->get_curr();
}
TMonom TPolynom::get_current_monom() {
	return monoms->get_curr()->data;
}