#include "expression.h"
#include <iostream>
#include <string>
#include <map>

Expression::Expression(const string& infx) : infix(infx)
{
	priority = { {"(",1},{")",1},{"+",2},{"-",2}, {"*",3},{"/",3} };
	ToPostfix();
	InToPostfix();
}

void Expression::Parse()
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

vector<string> Expression::GetOperands() const
{
	vector<string> op;
	for (const auto& item : operands)
		if (!IsConst(item.first))
		{
			op.push_back(item.first);
		}
	return op;
}

bool Expression::IsOperator(const string& lecsem) const
{
	bool flag = false;
	for (const auto& c : priority)
	{
		if (lecsem == c.first)
		{
			flag = true;
			break;
		}
	}
	return flag;

}


void Expression::SetValues()
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

bool Expression::IsConst(const string& lecsem) const
{
	bool hasDot = false;
	bool flag = true;
	for (char c : lecsem) {
		if (!std::isdigit(c)) {
			if (c == '.' && !hasDot) {
				hasDot = true;
			}
			else {
				flag = false;
				break;
			}
		}
	}
	return flag;

}

void Expression::ToPostfix() {
	Parse();
	TStack<string> st(lexems.size());
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
				operands.insert({ item, value });
			}
			postfix.push_back(item);
		}
	}
	while (!st.IsEmpty()) {
		stackItem = st.Top();
		st.Pop();
		postfix.push_back(stackItem);
	}
}

double Expression::Calculate(const map<string, double>& values)
{
	//for (auto& val : values) {
	//	try {
	//		operands.at(val.first) = val.second;
	//	}
	//	catch (out_of_range& e) {}
	//}
	for (auto & val : values)
	{
		operands[val.first] = val.second;
	}
	TStack<double> st;
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
			try
			{
				st.Push(operands.at(lexem));
			}
			catch (const std::out_of_range& e)
			{
				std::cout << "Please, enter " << lexem << std::endl;
				double value;
				std::cin >> value;
				operands[lexem] = value;
				st.Push(value);
			}
		}
	}
	return st.Top();
}

double Expression::Calculate()
{
	TStack<double> st;
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
			try
			{
				st.Push(operands.at(lexem));
			}
			catch (const std::out_of_range& e)
			{
				std::cout << "Please, enter " << lexem << std::endl;
				double value;
				std::cin >> value;
				operands[lexem] = value;
				st.Push(value);
			}
			
		}
	}
	return st.Top();
}

//double Expression::Calculate()
//{
//	return Calculate(operands);
//}

bool IsOperandNotScobes(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool Expression::isCorrectInfixExpression()
{
	int openParentheses = 0;
	int closeParentheses = 0;
	if (infix[0] == '*' || infix[0] == '/' || infix[0] == '+' || infix[0] == ')')
	{
		return false;
	}
	for (int i = 1; i < infix.size(); i++) 
	{
		bool isOperator1 = IsOperandNotScobes(infix[i]);
		bool isOperator2 = IsOperandNotScobes(infix[i-1]);
		if (isOperator1 && isOperator2)
			return false;
	}
	TStack<char> scobes(infix.size());
	for (char c : infix) {
		if (c == '(')
		{
			scobes.Push('(');
		}
		else if (c == ')') {
			if (scobes.IsEmpty())
			{
				return false;
			}
			if (scobes.Top() == '(')
			{
				scobes.Pop();
			}
		}
		else if (c == ' ')
			return false;
	}
	return scobes.IsEmpty();
}

void Expression::ShowPostfix()
{
	for (int i = 0; i < postfix.size(); i++)
	{
		cout << postfix[i] << " ";
	}
	cout << endl;
}

void Expression::InToPostfix()
{
	for (const auto& elem : postfix) {
		str_postfix += elem; 
	}
}