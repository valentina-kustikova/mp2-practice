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
void ArithmeticExpression<T>::Parse() {
	char c;
	string str;
	for (int i = 0; i <= (infix.size() - 1); i++) {
		c = infix[i];
		if ((c == '-' && i == 0) || (c == '-' && infix[i - 1] == '(')) {
			str.append("0");
			str.append("-");
			lexemes.push_back(str);
			str = "";
			continue;
		}
		while (c >= 48 && c <= 57 || c == '.') {
			str += c;
			i++;
			c = infix[i];
		}
		if (str[0] >= 48 && str[0] <= 57) {
			lexemes.push_back(str);
			str = "";
		}//можно объединить в одно условие
		if (c == '\0') {
			continue;
		}
		str = c;
		lexemes.push_back(str);
		str = "";
	}
}

template<typename T>
void ArithmeticExpression<T>::ToPostfix() {
	Parse();
	Stack<char> stack_ops;
	signed char c;
	string lexeme;
	char stack_op;
	for (int i = 0; i <= (lexemes.size() - 1); i++) {
		lexeme = lexemes[i];
		if (lexeme == "0-") {
			c = 151;
		}
		else {
			c = lexeme[0];
		}
		switch (c) {
		case '(':
		{
			stack_ops.Push(c);
			break;
		}
		case '+': case '-': case '*': case '/': case 'Ч'
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
			if (c == 'Ч') {
				//...
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
			if (c >= 47 && c <= 57) {
				operands.insert({ lexeme,stod(lexeme) });
				postfix.push_back(lexeme);
				break;
			}
			operands.insert({ lexeme, 0.0 });
			postfix.push_back(lexeme);
			break;
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
	auto it_begin{operands.begin() }; 
	auto it_end{ operands.end() };
	while (it_begin != it_end) {
		if (this->operands.at(*it_begin) != 0) {
			tmp.insert({ *it_begin, this->operands.at(*it_begin) });
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
	string lexeme;
	char c;
	double left_op,right_op;
	auto it_begin = postfix.begin();
	auto it_end = postfix.end();
	while (it_begin != it_end) {
		lexeme = *it_begin;
		if (lexeme.size() == 1) {
			c = lexeme[0];
			switch (c) {
			case '0-': {
				right_op = expr_operands.Pop();
				expr_operands.Push(-right_op);
				break;
			}
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
		}
		else {
			expr_operands.Push(values.at(lexeme));
		}
		it_begin++;
	}
	return expr_operands.Top();
}
#endif
