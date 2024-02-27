#include "tpolynom.h"

map<string, int> TArithmeticExpression::priority = {
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

// If found any operator, returns index. Else returns -1.
int TPolynom::FindOperator(int pos) const {
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

void TPolynom::ConvertInfix() {
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

void TPolynom::CorrectnessCheck() {
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

void TPolynom::Parse() {
	ConvertInfix();
	CorrectnessCheck();

	int firstind, secondind;;
	string token;

	firstind = FindOperator();
	secondind = FindOperator(firstind + 1);
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
		secondind = FindOperator(firstind + 1);
	}
	lexems.push_back(infix.substr(firstind, 1));
	if (firstind != infix.size() - 1)
		lexems.push_back(infix.substr(firstind + 1));
}


// ======================================================= //

TPolynom::TPolynom() {
	monoms = new TRingList<TMonom>;
}
TPolynom::TPolynom(const string _name) {
	name = _name;
	monoms = new TRingList<TMonom>;
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

	throw "NOT IMPLEMENTED";
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
