#include "tpolynom.h"

TPolynom::TPolynom() {
	monoms = nullptr;
}
TPolynom::TPolynom(const string _name) {
	name = _name;
	monoms = nullptr;
}
TPolynom::TPolynom(const TRingList<TMonom>& ringlist) {
	monoms = new TRingList<TMonom>(ringlist);
	name = "";
}
TPolynom::TPolynom(const TPolynom& polynom) {
	name = polynom.name;
	monoms = new TRingList<TMonom>(*polynom.monoms);
}
TPolynom::~TPolynom() {
	if (monoms) delete monoms;
}

const TPolynom& TPolynom::operator=(const TPolynom& polynom) {

}

TPolynom TPolynom::operator+(const TPolynom& polynom) {

	throw "NOT IMPLEMENTED";
}
TPolynom TPolynom::operator-(const TPolynom& polynom) {

	throw "NOT IMPLEMENTED";
}
TPolynom TPolynom::operator*(const TPolynom& polynom) {

	throw "NOT IMPLEMENTED";
}
double TPolynom::operator()(double x, double y, double z) {

	throw "NOT IMPLEMENTED";
}

TPolynom TPolynom::dif_x() const {

	throw "NOT IMPLEMENTED";
}
TPolynom TPolynom::dif_y() const {

	throw "NOT IMPLEMENTED";
}
TPolynom TPolynom::dif_z() const {

	throw "NOT IMPLEMENTED";
}


/// ============================================= ///

map<string, int> TPolynom::priority = {
	{"^", 4},
	{"*", 3},
	{"/", 3},
	{"+", 2},
	{"-", 2},
	{"(", 1},
	{")", 1}
};

void TPolynom::Parse() {
	ConvertInfix();
	CorrectnessCheck();

	int firstind, secondind;;
	string token;

	firstind = FindOperator();
	secondind = FindOperator(firstind + 1);
	if (firstind == -1) {
		lexems.push_back(name);
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
		secondind = FindOperator(firstind + 1);
	}
	lexems.push_back(name.substr(firstind, 1));
	if (firstind != name.size() - 1)
		lexems.push_back(name.substr(firstind + 1));
}
void TPolynom::ToPostfix() {
	Parse();
	TStack<string> st;
	string stackToken;
	for (string token : lexems) {
		if (token == "(") {
			st.Push(token);
		}
		else if (token == ")") {
			stackToken = st.Top();
			st.Pop();
			while (stackToken != "(") {
				postfix.push_back(stackToken);
				stackToken = st.Top();
				st.Pop();
			}
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
			while (!st.IsEmpty()) {
				stackToken = st.Top();
				st.Pop();
				if (priority[token] <= priority[stackToken])
					postfix.push_back(stackToken);
				else {
					st.Push(stackToken);
					break;
				}
			}
			st.Push(token);
		}
		else {
			double value = 0.0;
			if (IsConst(token)) {
				value = stod(token);
			}
			operands.insert({ token, value });
			postfix.push_back(token);
		}
	} // for
	while (!st.IsEmpty()) {
		stackToken = st.Top();
		st.Pop();
		postfix.push_back(stackToken);
	}
}

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

int TPolynom::FindOperator(int pos) const {
	if (pos < 0 || pos >= name.size()) return -1;

	int ind = -1;
	for (int i = pos; i < name.size(); i++) {
		string isopr;
		isopr += name[i];

		if (IsOperator(isopr)) {
			ind = i;
			break;
		}
	}
	return ind;
}

void TPolynom::ConvertInfix() {
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
	else tmp += name[name.size() - 1];
	name = tmp;
}
void TPolynom::CorrectnessCheck() {
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