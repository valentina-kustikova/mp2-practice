#include "tarithmetic.h"



void TArithmeticExpression::Parse()
{
	string currentElement;
	for (char c : infix) {
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
			if (!currentElement.empty()) {
				lexems.push_back(currentElement);
				currentElement = "";
			}
			lexems.push_back(string(1, c));
		}
		else if (isdigit(c) || c == '.') {
			currentElement += c;
		}
		else if (isalpha(c)) {
			currentElement += c;
		}
	}
	if (!currentElement.empty()) {
		lexems.push_back(currentElement);
	}
}
void TArithmeticExpression::ToPostfix() {
	Parse();
	Stack<string> st;
	string stackItem;
	for (string item : lexems) {
		if (item == "(") {
			st.Push(item);
		}
		else if (item == ")") {
			stackItem = st.Top();
			st.Pop();
			while (stackItem != "(") {
				postfix.push_back(stackItem);
				stackItem = st.Top();
				st.Pop();
			}
		}
		else if (item == "+" || item == "-" || item == "*" || item == "/") {
			while (!st.IsEmpty()) {
				stackItem = st.Top();
				st.Pop();
				if (priority[item] <= priority[stackItem])
					postfix.push_back(stackItem);
				else {
					st.Push(stackItem);
					break;
				}
			}
			st.Push(item);
		}
		else {
			double value = 0.0;
			if (IsConst(item)) {
				value = stod(item);
			}
			operands.insert({ item, value });
			postfix.push_back(item);
		}
	}
	while (!st.IsEmpty()) {
		stackItem = st.Top();
		st.Pop();
		postfix.push_back(stackItem);
	}
}

bool TArithmeticExpression::IsOperator(const string& lexem) const
{
	bool flag = false;
	for (const auto& c : priority)
	{
		if (lexem == c.first)
		{
			flag = true;
		}
	}
	return flag;

}

bool TArithmeticExpression::IsConst(const string& lexem) const
{
	bool flag = true;
	for (int i = 0; i < lexem.size(); i++)
	{
		if (!isdigit(lexem[i]))
		{
			flag = false;
		}
	}
	return flag;

}

TArithmeticExpression::TArithmeticExpression(const string& infix) :infix(infix) {
	ToPostfix();
}

map<string, int> TArithmeticExpression::priority = {

	{"(",1},{")",1},{"+",2},{"-",2}, {"*",3},{"/",3}
};

bool TArithmeticExpression::isCorrectInfixExpression()
{
	int openParentheses = 0;
	int closeParentheses = 0;

	for (char c : infix)
		if (c == '(')
			openParentheses++;
		else if (c == ')')
			closeParentheses++;
	return openParentheses == closeParentheses;
}



void TArithmeticExpression::SetValues()
{
	double value;
	for (auto& op : operands)
	{
		if (!IsConst(op.first))
		{
			cout << "Enter value of " << op.first << ":";
			cin >> value;
			operands[op.first] = value;
		}
	}
}

double TArithmeticExpression::Calculate(const map<string, double>& values)
{
	for (auto& val : values) {
		try {
			operands.at(val.first) = val.second;
		}
		catch (out_of_range& e) {}
	}

	Stack<double> st;
	double leftOperand, rightOperand;
	for (string lexem : postfix) {
		if (lexem == "+") {
			rightOperand = st.Top();
			st.Pop();
			leftOperand = st.Top();
			st.Pop();
			st.Push(leftOperand + rightOperand);
		}
		else if (lexem == "-") {
			rightOperand = st.Top();
			st.Pop();
			leftOperand = st.Top();
			st.Pop();
			st.Push(leftOperand - rightOperand);
		}
		else if (lexem == "*") {
			rightOperand = st.Top();
			st.Pop();
			leftOperand = st.Top();
			st.Pop();
			st.Push(leftOperand * rightOperand);
		}
		else if (lexem == "/") {
			rightOperand = st.Top();
			st.Pop();
			leftOperand = st.Top();
			st.Pop();
			if (rightOperand == 0) {
				throw"Error";
			}
			st.Push(leftOperand / rightOperand);
		}
		else {
			st.Push(operands[lexem]);
		}
	}
	return st.Top();
}

double TArithmeticExpression::Calculate()
{
	return Calculate(operands);
}



