#include "tarithmeticexpression_str.h"

map<string, int> TArithmeticExpression_str::priority = {
	{"*", 3},
	{"/", 3},
	{"+", 2},
	{"-", 2},
	{"(", 1},
	{")", 1}
};

bool TArithmeticExpression_str::IsOperator(const string& isopr) const {
	bool flag = false;
	for (const auto& opr : priority) {
		if (isopr == opr.first) {
			flag = true;
			break;
		}
	}
	return flag;
}
bool TArithmeticExpression_str::IsConst(const string& isopd) const {
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
int TArithmeticExpression_str::FindOperator(int pos) const {
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
//int TArithmeticExpression_str::FindLastOperator(int offset_from_end) const {
//	if (offset_from_end < 0 || offset_from_end >= infix.size()) throw "ERROR: Position out of range";
//	
//	int ind = -1;
//	for (int i = infix.size() - 1 - offset_from_end; i >= 0; i--) {
//		string isopr;
//		isopr += infix[i];
//
//		if (IsOperator(isopr)) {
//			ind = i;
//			break;
//		}
//	}
//	return ind;
//}

//double TArithmeticExpression_str::StringToValue(const string& str) const {
//	if (!IsConst(str)) throw "ERROR: Invalid argument";
//	
//	double value = stod(str);
//
//	return value;
//	
//	//int dot = -1, dotcount = 0;
//	//for (int i = 0; i < str.size(); i++) {
//	//	if (str[i] == '.') {
//	//		dot = i;
//	//		dotcount++;
//	//	}
//	//}
//	//if (dotcount > 1) throw "ERROR: too many dots string number";
//	//if (dot == -1) dot = str.size();
//	//double fraction_lenght;
//
//	//
//	//double value = 0.0;
//	//double fraction = 0.0;
//	//double fraction_grade = 1.0;
//	//double grade = 10.0;
//	//
//
//	//for (int i = 0; i < dot; i++) {
//	//	value *= 10;
//	//	value += str[i] - '0';
//	//}
//	//for (int i = dot + 1; i < str.size(); i++) {
//	//	fraction *= 10;
//	//	fraction += str[i] - '0';
//	//	fraction_grade *= 10;
//	//}
//	//value += fraction_grade;
//
//	//return value;
//}


void TArithmeticExpression_str::ConvertInfix() {
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
			if (infix[i - 1] == ')' || (infix[i - 1] >= '0' && infix[i - 1] <= '9'))
				tmp += '*';
			tmp += '(';
		}
		else if (elem == '.') {
			if (infix[i - 1] < '0' || infix[i - 1] > '9')
				tmp += '0';
			tmp += '.';
			if (infix[i + 1] < '0' || infix[i + 1] > '9')
				tmp += '0';
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
void TArithmeticExpression_str::Parse() {
	// »ƒ≈я: подсчитывать кол-во операторов, чтобы можно было добавл€ть в операторы функции
	// »ƒ≈я: ищем унарный минус (он первый или перед ним "(") -> перед ним вписываем константу 0
	//		 примеры: -A+B -> 0-A+B; B+(-A+C) -> B+(0-A+C)
	
	ConvertInfix();

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

void TArithmeticExpression_str::ToPostfix() {
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

TArithmeticExpression_str::TArithmeticExpression_str(const string& _infix) {
	infix = _infix;
	ToPostfix();
}

string TArithmeticExpression_str::GetStringPostfix() const {
	string pf;
	for (const string& item : postfix)
		pf += item + " ";
	if (!pf.empty())
		pf.pop_back();
	return pf;
}

vector<string> TArithmeticExpression_str::GetOperands() const {
	vector<string> op;
	for (const auto& item : operands)
		if (!IsConst(item.first))
			op.push_back(item.first);
	return op;
}
void TArithmeticExpression_str::SetValues() {
	double val;
	for (auto& op : operands) {
		if (!IsConst(op.first)) {
			cout << "Enter value of " << op.first << ": ";
			cin >> val;
			operands[op.first] = val;
		}
	}
}
void TArithmeticExpression_str::SetValues(map<string, double>& values) {
	for (auto& val : values) {
		try {
			operands.at(val.first) = val.second;
		}
		catch (out_of_range& e) {}
	}
}
void TArithmeticExpression_str::ClearValues() {
	for (auto& op : operands) {
		if (!IsConst(op.first))
			operands.at(op.first) = 0.0;
	}
}


double TArithmeticExpression_str::Calculate(const map<string, double>& values) {
	for (auto& val : values) {
		try {
			operands.at(val.first) = val.second;
		}
		catch (out_of_range& e) {}
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
			st.Push(leftOp / rightOp);
		}
		else {
			st.Push(operands[lexem]);
		}
	}
	return st.Top();
}
double TArithmeticExpression_str::Calculate() {
	return Calculate(operands);
}