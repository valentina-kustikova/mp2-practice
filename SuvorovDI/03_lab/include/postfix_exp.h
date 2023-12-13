#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "stack.h"

class ArithmeticExp {
private:
	std::string original_exp;
	std::string postfix_exp;

	std::vector<char> lexemes;
	std::map<char, int> priorities;
	std::map<char, double> operands_values; // !!!!! cahr -> string

	void Parse();
	void ToPostfix();
public:
	ArithmeticExp(const std::string exp);

	std::string GetOriginal() {return original_exp;}
	std::string GetPostfix() { return postfix_exp; }

	std::vector<char> GetOperands() const; // !!!!
	double Calculate(const std::map<char, double>& values); // !!!!
};

ArithmeticExp::ArithmeticExp(const std::string exp) : original_exp(exp) {
	priorities = {
		{'*', 3},
		{'/', 3},
		{'+', 2},
		{'-', 2},
	};
	ToPostfix();
}

void ArithmeticExp::Parse() {
	for (char c : original_exp) {
		lexemes.push_back(c); // !!!!
	}
}

void ArithmeticExp::ToPostfix() {
	Parse();
	Stack<char> operations;
	Stack<char> operands; // !!!

	for (char elem : lexemes) { // !!!
		switch (elem) {
		case '(':
			operations.Push(elem);
			break;
		case ')':
			while (operations.Top() != '(') {
				operands.Push(operations.Top());
				operations.Pop();
			}
			break;
		case '+': case '-': case '*': case '/':
			while (!operations.isEmpty()) {
				if (priorities[elem] <= priorities[operations.Top()]) {
					operands.Push(operations.Top());
					operations.Pop();
				}
				else {
					break;
				}
			}
			operations.Push(elem);
			break;
		default:
			operands.Push(elem);
			operands_values.insert({elem, 0.0});
		}
	}
	while (!operations.isEmpty()) {
		operands.Push(operations.Top());
		operations.Pop();
	}

	while (!operands.isEmpty()) {
		postfix_exp = operands.Top() + postfix_exp;
		operands.Pop();
	}
}

std::vector<char> ArithmeticExp::GetOperands() const {
	std::vector<char> op;
	for (const std::pair<char, double> elem : operands_values) {
		op.push_back(elem.first);
	}
	return op;
}

double ArithmeticExp::Calculate(const std::map<char, double>& values) {
	for (std::pair<char, double> val : values) {
		operands_values.at(val.first) = val.second; // зачем try catch в лекциях
	}

	Stack<double> st;
	double leftOp, rightOp;
	for (char lexem : postfix_exp) {
		switch (lexem) {
		case '+':
			rightOp = st.Top();
			st.Pop();
			leftOp = st.Top();
			st.Pop();
			st.Push(leftOp + rightOp);
			break;
		case '-':
			rightOp = st.Top();
			st.Pop();
			leftOp = st.Top();
			st.Pop();
			st.Push(leftOp - rightOp);
			break;
		case '*':
			rightOp = st.Top();
			st.Pop();
			leftOp = st.Top();
			st.Pop();
			st.Push(leftOp * rightOp);
			break;
		case '/':
			rightOp = st.Top();
			st.Pop();
			leftOp = st.Top();
			st.Pop();
			st.Push(leftOp / rightOp);
			break;
		default:
			st.Push(operands_values[lexem]);
		}
	}
	return st.Top();
}