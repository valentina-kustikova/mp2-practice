#ifndef _AREXPRESSION_H
#define _AREXPRESSION_H

#include <iostream>
#include <Stack.h>
#include <vector>
#include <map>
#include <string>
using namespace std;



template <typename T> class ArithmeticExpression {
private:
	string infix;
	vector<string> postfix;
	vector<string> lexemes;
	map<char, int> priority;
	map<string, double> operands;

	bool Is_Operator(char c)const;
	bool Is_Operand_String(char c)const;
	bool Is_Operand_const(char c)const;
public:
	ArithmeticExpression(string infix_);

	string GetInfix()const { return infix; }
	vector<string> GetPostfix()const { return postfix; }
	vector<string> GetOperands()const;
	map<string, double> SetOperands(const vector<string> operands);

	void Check();
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
bool ArithmeticExpression<T>::Is_Operator(char c)const {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

template<typename T>
bool ArithmeticExpression<T>::Is_Operand_String(char c)const {
	return c >= 65 && c <= 90 || c >= 97 && c <= 122;
}

template<typename T>
bool ArithmeticExpression<T>::Is_Operand_const(char c)const {
	return c >= 48 && c <= 57;
}


template<typename T>
void ArithmeticExpression<T>::Check() {
	int i = 0;
	char c;
	while (i < infix.size()) {//проверяет на чужеродные символы
		c = infix[i];
		if (Is_Operand_String(c) || Is_Operand_const(c) ||
			Is_Operator(c) || c == '.') {
			i++;
			continue;
		}
		else {
			throw "Mistake in arithmetic expression!";
		}
	}
	i = 0;

	int count_left_open_bracket = 0;
	int count_right_close_bracket = 0;
	char next_c;
	while (i < infix.size()) {//проверяет на соответствие числа открывающих и закрывающих скобок
		c = infix[i];
		next_c = infix[i + 1];
		if (c == '(') {
			if (next_c == '+' || next_c == '*' || next_c == '/' || next_c == ')') {
				throw "Mistake in arithmetic expression!";
			}
			count_left_open_bracket++;
		}
		if (c == ')') {
			count_right_close_bracket++;
		}
		i++;
	}
	if (count_left_open_bracket != count_right_close_bracket) {
		throw "Mistake in arithmetic expression!";
	}
	i = 0;

	char cc;
	while (i < infix.size()) {//проверяет на отсутствие двух идущих подряд операций и точек
		c = infix[i];
		switch (c) {
		case '+': case '-': case '*': case '/':
		{
			cc = infix[i + 1];
			if (cc == ')') {
				throw "Mistake in arithmetic expression!";
			}
			auto tmp = priority.find(cc);
			if (tmp != priority.end() && tmp->first != ')' && tmp->first != '(') {//повторы операций
				throw "Mistake in arithmetic expression!";
			}
		}
		default:

			cc = infix[i + 1];
			if (c == '.' && cc == '.') {//повторы точки
				throw "Mistake in arithmetic expression!";
			}
			break;
		}
		i++;
	}
}

template<typename T>
void ArithmeticExpression<T>::Parse() {//использованы правила идентификаторов переменных
	char c;
	char cc;
	int count_points = 0;
	string str;
	int i = 0;
	char first_c;
	Check();
	for (i = 0; i < (infix.size()); i++) {
		c = infix[i];
		first_c = c;
		switch (c) {
		case '+': case '-': case '*': case '/': case '(': case ')':
			{
				if (i == 0 && c != '-' && c != '(') {
				throw "Mistake in arithmetic expression!";
				}
				if (i == infix.size() - 1 && c != ')') {
					throw "Mistake in arithmetic expression!";
				}
				if ((c == '-' && i == 0) || (c == '-' && infix[i - 1] == '(')) {
					lexemes.push_back("0");
					lexemes.push_back("-");
					str = "";
					continue;
				}
				str = c;
				lexemes.push_back(str);
				str = "";
				continue;
			}
			default:
				while (!Is_Operator(c)) {
					if (c == '.' && str == "") {
						throw "Mistake in arithmetic expression!";
					}
					if (Is_Operand_const(c) && Is_Operand_const(first_c) || c == '.') {//константа-операнд
						if (c == '.') {
							count_points++;
							if (count_points > 1) {
								throw "Mistake in arithmetic expression!";
							}
						}
						str += c;
						i++;
						if (i == infix.size()) {
							break;
						}
						c = infix[i];
						if (Is_Operand_String(c)) {
							throw "Mistake in arithmetic expression!";//встретился символ внутри константы-операнда
						}
						if (c == '.' && Is_Operator(infix[i+1]) && i + 1 != infix.size()) {
							throw "Mistake in arithmetic expression!";
						}
					}
					else {
						str += c;
						i++;
						if (i == infix.size()) {
							break;
						}

						c = infix[i];
						if (!(c != '.')) {
							throw "Mistake in arithmetic expression!";
						}
					}

				}
				if (i == infix.size() - 1 && c != ')') {
					throw "Mistake in arithmetic expression!";
				}
				count_points = 0;
				lexemes.push_back(str);
				str = "";
				break;
		}

		if (c == '\0') {
			continue;
		}
		if (i != infix.size()) {
			str = c;
			lexemes.push_back(str);
			str = "";
		}
	}
}

template<typename T>
void ArithmeticExpression<T>::ToPostfix() {
	Parse();
	Stack<char> stack_ops;
	unsigned char c;
	string lexeme;
	char stack_op;
	for (int i = 0; i <= (lexemes.size() - 1); i++) {
		lexeme = lexemes[i];
		c = lexeme[0];
		switch (c) {
		case '(':
		{
			stack_ops.Push(c);
			break;
		}
		case '+': case '-': case '*': case '/': case '—':
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
			if (c >= 47 && c <= 57) {//operand-number
				operands.insert({ lexeme,stod(lexeme) });
				postfix.push_back(lexeme);
				break;
			}
			operands.insert({ lexeme, 0.0 });//operand-symbol(string)
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
		if (this->operands.at(*it_begin) != 0 || *it_begin == "0") {
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
			c = lexeme[0];
			switch (c) {
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
				if (right_op == 0) {
					throw "division by zero!";
				}
				expr_operands.Push(left_op / right_op);
				break;
			}
			default:
				expr_operands.Push(values.at(lexeme));
				break;
		}
		it_begin++;
	}
	return expr_operands.Top();
}
#endif
