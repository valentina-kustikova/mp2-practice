#include "tarithmeticexpression.h"

map<string, int> TArithmeticExpression::priority = {
	{"*", 3},
	{"/", 3},
	{"+", 2},
	{"-", 2},
	{"(", 1},
	{")", 1}
};

bool TArithmeticExpression::IsOperator(const string& isopr) const {
	bool flag = false;
	for (const auto& opr : priority) {
		if (isopr == opr.first) {
			flag = true;
			break;
		}
	}
	return flag;
}
bool TArithmeticExpression::IsConst(const string& isopd) const {
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
int TArithmeticExpression::FindOperator(int pos) const {
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

void TArithmeticExpression::ConvertInfix() {
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

void TArithmeticExpression::CorrectnessCheck() {
	int op_bracket = 0;
	int cl_bracket = 0;
	int dot = 0;

	string exp = "Incorrect arithmetic expression";

	if (infix[0] == '+' || infix[0] == '*' || infix[0] == '/' || infix[0] == ')') throw exp;
	if (infix[infix.size() - 1] == '+' || infix[infix.size() - 1] == '-' || infix[infix.size() - 1] == '*' || infix[infix.size() - 1] == '/' || infix[infix.size() - 1] == '(') throw exp;

	if (infix[0] == '(') op_bracket++;
	else if (infix[0] == '.') dot++;
	if (infix[infix.size() - 1] == ')') cl_bracket++;
	else if (infix[infix.size() - 1] == '.') dot++;

	for (int i = 1; i < infix.size()-1; i++) {
		char elem = infix[i];
		if (elem == '(')
			op_bracket++;
		else if (elem == ')') {
			if (infix[i - 1] == '(' || infix[i - 1] == '+' || infix[i - 1] == '-' || infix[i - 1] == '*' || infix[i - 1] == '/') throw exp;
			cl_bracket++;
		}
		else if (elem == '.')
			dot++;
		else if (elem == '+' || elem == '-' || elem == '*' || elem == '/') {
			if (dot > 1) throw exp;
			dot = 0;
			if (infix[i - 1] == '+' || infix[i - 1] == '-' || infix[i - 1] == '*' || infix[i - 1] == '/' || infix[i - 1] == '(') throw exp;
		}
	}
	if (op_bracket != cl_bracket) throw exp;
}

void TArithmeticExpression::Parse() {
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

void TArithmeticExpression::ToPostfix() {
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
		else if (token == "+" || token == "-" || token == "*" || token == "/") {
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

TArithmeticExpression::TArithmeticExpression(const string& _infix) {
	infix = _infix;
	ToPostfix();
}

TArithmeticExpression::TArithmeticExpression(const TArithmeticExpression& ae) {
	infix = ae.infix;
	postfix = ae.postfix;
	lexems = ae.lexems;
	operands = ae.operands;
}

string TArithmeticExpression::GetStringPostfix() const {
	string pf;
	for (const string& item : postfix)
		pf += item + " ";
	if (!pf.empty())
		pf.pop_back();
	return pf;
}

vector<string> TArithmeticExpression::GetOperands() const {
	vector<string> op;
	for (const auto& item : operands)
		if (!IsConst(item.first))
			op.push_back(item.first);
	return op;
}
void TArithmeticExpression::SetValues() {
	double val;
	for (auto& op : operands) {
		if (!IsConst(op.first)) {
			cout << "Enter value of " << op.first << ": ";
			cin >> val;
			operands[op.first] = val;
		}
	}
}
void TArithmeticExpression::SetValues(map<string, double>& values) {
	if (&values != &operands) {
		for (auto& val : values) {
			try {
				operands.at(val.first) = val.second;
			}
			catch (out_of_range& e) {}
		}
	}
}
void TArithmeticExpression::ClearValues() {
	for (auto& op : operands) {
		if (!IsConst(op.first))
			operands.at(op.first) = 0.0;
	}
}


double TArithmeticExpression::Calculate(const map<string, double>& values) {
	if (&values != &operands) {
		for (auto& val : values) {
			try {
				operands.at(val.first) = val.second;
			}
			catch (out_of_range& e) {}
		}
	}

	TStack<double> st;
	double leftOp, rightOp;
	for (string lexem : postfix) {
		if (lexem == "+") {
			rightOp = st.Top();
			st.Pop();
			leftOp = st.Top();
			st.Pop();
			st.Push(leftOp + rightOp);
		}
		else if (lexem == "-") {
			rightOp = st.Top();
			st.Pop();
			leftOp = st.Top();
			st.Pop();
			st.Push(leftOp - rightOp);
		}
		else if (lexem == "*") {
			rightOp = st.Top();
			st.Pop();
			leftOp = st.Top();
			st.Pop();
			st.Push(leftOp * rightOp);
		}
		else if (lexem == "/") {
			rightOp = st.Top();
			st.Pop();
			leftOp = st.Top();
			st.Pop();
			if (rightOp == 0) {
				string exp = "Error: division by 0";
				throw exp;
			}
			st.Push(leftOp / rightOp);
		}
		else {
			st.Push(operands[lexem]);
		}
	}
	return st.Top();
}
double TArithmeticExpression::Calculate() {
	return Calculate(operands);
}