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
	/*Vector<char> GetOperands()const;*/

	void Parse();
	void ToPostfix();
	//double Calculate(const map<char, double>& values);
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
#endif
