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
	vector<string> postfix;
	vector<string> lexemes;
	map<char, int> priority;
	map<string, double> operands;
public:
	ArithmeticExpression(string infix_);

	string GetInfix()const { return infix; }
	string GetPostfix()const { return postfix; }
	vector<string> GetOperands()const;
	map<string, double> SetOperands(const vector<string> operands);

	void Parse();
	void ToPostfix();
	double Calculate(const map<string, double>& values);
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
	char c;
	string lexeme;
	char stack_op;
	for (int i = 0; i <= (lexemes.size() - 1); i++) {
		lexeme = lexemes[i];
		if(lexeme.size() == 1){
			c = lexeme[0];
			switch (c) {
			case '(':
			{
				stack_ops.Push(c);
				break;
			}
			case '+': case '-': case '*': case '/':
			{
				while (!stack_ops.IsEmpty()) {
					stack_op = stack_ops.Pop();
					if (priority[c] <= priority[stack_op]) {
						string tmp_str;
						tmp_str = stack_op;
						postfix.push_back(tmp_str);
					}
					else {
						stack_ops.Push(stack_op);
						break;
					}
				}
				stack_ops.Push(c);
				break;
			}
			case ')':
			{
				stack_op = stack_ops.Pop();
				string tmp_str;
				while (stack_op != '(') {
					tmp_str = stack_op;
					postfix.push_back(tmp_str);
					stack_op = stack_ops.Pop();
				}
				break;
			}
			default:
				string new_str;
				new_str = c;
				if (c >= 48 && c <= 57) {
					operands.insert({ new_str,stod(new_str) });
					postfix.push_back(new_str);
					break;
				}
				operands.insert({ new_str, 0.0 });
				postfix.push_back(new_str);
				break;
			}
		}
		else {
			operands.insert({ lexeme,stod(lexeme) });
			postfix.push_back(lexeme);
		}
	}
		
	while (!stack_ops.IsEmpty()) {
		stack_op = stack_ops.Pop();
		string tmp_str;
		tmp_str = stack_op;
		postfix.push_back(tmp_str);
	}
}

template<typename T>
void ArithmeticExpression<T>::Parse() {
	char c;
	string str;
	for (int i = 0; i <= (infix.size() - 1); i++) {
		c = infix[i];
		while (c >= 48 && c <= 57 || c == '.') {
			str += c;
			i++;
			c = infix[i];
		}
		if (str[0] >= 48 && str[0] <= 57) {
			lexemes.push_back(str);
			str = "";
		}
		if (c == '\0') {
			continue;
		}
		str = c;
		lexemes.push_back(str);
		str = "";
	}
}

template<typename T>
vector<string> ArithmeticExpression<T>::GetOperands()const {
	vector<string> tmp;
	auto it_begin{ operands.begin() };
	auto it_end{ operands.end() };
	while (it_begin != it_end) {
		tmp.push_back(it_begin->first);
		it_begin++;
	}
	return tmp;
}

template<typename T>
map<string, double> ArithmeticExpression<T>::SetOperands(const vector<string> operands) {
	map<string, double> tmp;
	double value;
	auto it_begin_map{ this->operands.begin() };
	auto it_begin{operands.begin() }; 
	auto it_end{ operands.end() };
	while (it_begin != it_end) {
		if (it_begin_map->second != 0) {//???
			it_begin++;
			continue;
		}
		cout << "Enter value of operand " << *it_begin << ": ";
		cin >> value;
		tmp.insert({ *it_begin, value });
		it_begin++;
	}
	return tmp;
}

template<typename T>
double ArithmeticExpression<T>::Calculate(const map<string, double>& values) {
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
