#include "tarithmeticexpression.h"
#include "tstack.h"

#include <iostream>
#include <map>
#include <vector>
#include <string>

TArithmeticExpression::TArithmeticExpression(const std::string& infx) : infix(infx) {
	priority = { {"+", 1},{"-", 1},{"*", 2},{"/", 2} };
	ToPostfix();
}

std::string TArithmeticExpression::GetInfix() const {
	return infix;
}

bool TArithmeticExpression::IsOperator(char c) const {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

bool TArithmeticExpression::IsConst(const std::string& str) const {
	bool flag = true;
	for (int i = 0; i < str.size(); i++)
		if (str[i] < '0' || str[i] > '9') {
			if (str[i] != '.')
				flag = false;
			break;
		}
	return flag;
}

void TArithmeticExpression::Check() {
	if (infix.empty()) {
		throw std::exception("got empty string");
	}
	if (infix[0] == '+' || infix[0] == '*' || infix[0] == '/' || infix[0] == '.' || infix[0] == ')') {
		throw std::exception("arithmetic expression start with operator");
	}
	int opening_brackets = 0, closing_brackets = 0, points = 0;
	if (infix[0] == '(') {
		if (infix[1] == ')' || infix[1] == '+' || infix[1] == '*' || infix[1] == '/' || infix[1] == '.') {
			throw std::exception("operator after opening bracket");
		}
		opening_brackets++;
	}
	for (int i = 1; i < infix.size() - 2; i++) {
		if (IsOperator(infix[i]) || infix[i] == '.' || infix[i] >= 65 && infix[i] <= 90 || infix[i] >= 97 && infix[i] <= 122 || infix[i] >= 48 && infix[i] <= 57) {
			if (infix[i] == '(') {
				if (infix[i + 1] == ')' || infix[i + 1] == '+' || infix[i + 1] == '-' || infix[i + 1] == '*' || infix[i + 1] == '/' || infix[i + 1] == '.') {
					throw std::exception("operator after opening bracket");
					break;
				}
				opening_brackets++;
			}
			if (infix[i] == ')') {
				if (infix[i - 1] == '(' || infix[i - 1] == '+' || infix[i - 1] == '-' || infix[i - 1] == '*' || infix[i - 1] == '/' || infix[i - 1] == '.') {
					throw std::exception("operator before closing bracket");
					break;
				}
				closing_brackets++;
			}
			if (infix[i] == '/' && infix[i + 1] == '0') {
				throw std::exception("division by zero");
			}
			if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '.') {
				if (infix[i + 1] == '+' || infix[i + 1] == '-' || infix[i + 1] == '*' || infix[i + 1] == '/' || infix[i + 1] == '.') {
					throw std::exception("repeat operator");
					break;
				}
			}
			while (!IsOperator(infix[i])) {
				if (infix[i] >= 48 && infix[i] <= 57 || infix[i] == '.') {
					if (infix[i] == '.') {
						points++;
					}
					if (points > 1) {
						std::cout << "constant contains more than one point";
					}
				}
				i++;
				if (i == infix.size()) {
				}
			}
		}
		else {
			throw std::exception("expression contains invalid characters");
			break;
		}
	}
	if (infix[infix.size() - 2] == '/' && infix[infix.size() - 1] == '0') {
		throw std::exception("division by zero");
	}
	if (infix[infix.size() - 1] == ')') {
		if (infix[infix.size() - 2] == '(' || infix[infix.size() - 2] == '+' || infix[infix.size() - 2] == '-' || infix[infix.size() - 2] == '*' || infix[infix.size() - 2] == '/' || infix[infix.size() - 2] == '.') {
			throw std::exception("operator before closing bracket");
		}
		closing_brackets++;
	}

	if (infix[infix.size()] == '+' || infix[infix.size()] == '-' || infix[infix.size()] == '*' || infix[infix.size()] == '/' || infix[infix.size()] == '.' || infix[infix.size()] == '(') {
		throw std::exception("arithmetic expression end with operator");
	}
}

void TArithmeticExpression::Parse() {
	Check();
	std::string str;
	for (int i = 0; i < infix.size(); i++) {
		if (IsOperator(infix[i])) {
			if (infix[i] == '-' && i == 0) {
				lexems.push_back("0");
				lexems.push_back("-");
				str.clear();
				continue;
			}
			else {
				str = infix[i];
				lexems.push_back(str);
				str.clear();
			}
			continue;
		}
		else {
			while (!IsOperator(infix[i])) {
				str += infix[i];
				i++;
				if (i == infix.size()) {
					break;
				}
			}
			lexems.push_back(str);
			str.clear();
		}
		if (i != infix.size()) {
			str = infix[i];
			lexems.push_back(str);
			str.clear();
		}
	}
}

void TArithmeticExpression::ToPostfix() {
	Parse();
	TStack<std::string> st;
	std::string item;
	std::string stackItem;
	for (int i = 0; i <= lexems.size() - 1; i++) {
		item = lexems[i];
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
			operands.insert({ item, 0.0 });
			postfix.push_back(item);
		}
	}
	while (!st.IsEmpty()) {
		stackItem = st.Top();
		st.Pop();
		postfix.push_back(stackItem);
	}
}

std::string TArithmeticExpression::GetPostfix() const {
	std::string pf;
	for (const std::string& item : postfix)
		pf += item + " ";
	if (!pf.empty())
		pf.pop_back();
	return pf;
}

std::vector<std::string> TArithmeticExpression::GetOperands() const {
	std::vector<std::string> op;
	for (const auto& item : operands)
		if (!IsConst(item.first))
			op.push_back(item.first);
	return op;
}

std::map<std::string, double> TArithmeticExpression::SetValues() {
	double val;
	for (auto& op : operands) {
		if (IsConst(op.first)) {
			operands[op.first] = std::stof(op.first);
		}
		else {
			std::cout << "Enter value of " << op.first << ": ";
			std::cin >> val;
			operands[op.first] = val;
		}
	}
	return operands;
}

double TArithmeticExpression::Calculate(const std::map<std::string, double>& values) {
	for (auto& val : values) {
		try {
			operands.at(val.first) = val.second;
		}
		catch (std::out_of_range& e) {}
	}
	TStack<double> st;
	double leftOperand, rightOperand;
	for (std::string lexem : postfix) {
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
			if (rightOperand == 0)
				throw std::exception("division by zero");
			st.Pop();
			leftOperand = st.Top();
			st.Pop();
			st.Push(leftOperand / rightOperand);
		}
		else {
			st.Push(operands[lexem]);
		}
	}
	return st.Top();
}