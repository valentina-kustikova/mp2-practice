#ifndef _AREXPRESSION_H
#define _AREXPRESSION_H

#include <iostream>
#include <Stack.h>
#include <vector>
#include <map>

using namespace std;



template <typename T> class ArithmeticExpression {
private:
	string infix;
	string postfix;
	vector<char> lexemes;
	map<char, int> priority;
	map<char, double> operands;
public:
	ArithmeticExpression(string infix_);

	string GetInfix()const { return infix; }
	string GetPostfix()const { return postfix; }
	vector<char> GetOperands()const;
	map<char, double> SetOperands(const vector<char> operands);

	void Parse();
	void ToPostfix();
	double Calculate(const map<char, double>& values);
};

template<typename T>
ArithmeticExpression<T>::ArithmeticExpression(string infix_) :infix(infix_) {
	priority =
	{
		{'(',1},{'+',2},{'-',2},{'*',3}, {'/',3}
	};
	ToPostfix();
}

template<typename T>
void ArithmeticExpression<T>::ToPostfix() {
	Parse();
	Stack<char> stack_ops;
	char lexeme;
	char stack_op;
	for (int i = 0; i <= (lexemes.size() - 1); i++) {
		lexeme = lexemes[i];
		switch (lexeme) {
			case '(': 
			{
				stack_ops.Push(lexeme);
				break;
			}
			case '+': case '-': case '*': case '/':
			{
				while (!stack_ops.IsEmpty()) {
					stack_op = stack_ops.Pop(); 
					if (priority[lexeme] <= priority[stack_op]) {
						postfix += stack_op;
					}
					else {
						stack_ops.Push(stack_op);
						break;
					}
				}
				stack_ops.Push(lexeme);
				break;
			}
			case ')':
			{
				stack_op = stack_ops.Pop();
				while (stack_op != '(') {
					postfix += stack_op;
					stack_op = stack_ops.Pop();
				}
				break;
			}
			default: 
				operands.insert({ lexeme, 0.0 });
				postfix += lexeme;
				break;
		}
	}
	while (!stack_ops.IsEmpty()) {
		stack_op = stack_ops.Pop();
		postfix += stack_op;
	}
}

template<typename T>
void ArithmeticExpression<T>::Parse() {
	char c;
	for (int i = 0; i <= (infix.size() - 1); i++) {
		c = infix[i];
		lexemes.push_back(c);
	}
}

template<typename T>
vector<char> ArithmeticExpression<T>::GetOperands()const {
	vector<char> tmp;
	auto it_begin{ operands.begin() };
	auto it_end{ operands.end() };
	while (it_begin != it_end) {
		tmp.push_back(it_begin->first);
		it_begin++;
	}
	return tmp;
}

template<typename T>
map<char, double> ArithmeticExpression<T>::SetOperands(const vector<char> operands) {
	map<char, double> tmp;
	double value;
	auto it_begin{operands.begin() }; 
	auto it_end{ operands.end() };
	while (it_begin != it_end) {
		cout << "Enter value of operand " << *it_begin << ": ";
		cin >> value;
		tmp.insert({ *it_begin, value });
		it_begin++;
	}
	return tmp;
}

template<typename T>
double ArithmeticExpression<T>::Calculate(const map<char, double>& values) {
	Stack<double> expr_operands;
	char lexeme;
	double left_op,right_op;
	int i = 0;
	while (i != postfix.size()) {
		lexeme = postfix[i];
		switch (lexeme) {
		case '+':
		{
			right_op = expr_operands.Pop();
			left_op = expr_operands.Pop();
			expr_operands.Push(left_op + right_op);
			break;
		}
		case '-':
		{
			right_op = expr_operands.Pop();
			left_op = expr_operands.Pop();
			expr_operands.Push(left_op - right_op);
			break;
		}
		case '*': 
		{
			right_op = expr_operands.Pop();
			left_op = expr_operands.Pop();
			expr_operands.Push(left_op * right_op);
			break;
		}
		case '/':
		{
			right_op = expr_operands.Pop();
			left_op = expr_operands.Pop();
			expr_operands.Push(left_op / right_op);
			break;
		}
		default:
			expr_operands.Push(values.at(lexeme));
			break;
		}
		i++;
	}
	return expr_operands.Top();
}
#endif
