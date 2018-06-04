#include "stack.h"
#include "funñ.h"
#include "link.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;


int funcs::priority(const char& a) {
	if (a == '+' || a == '-') return 0;
	return 1;
}

bool funcs::is_variable(const char& ch) {
	return ch >= 'a' && ch <= 'z';
}

bool funcs::is_operation(const char& ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int funcs::correct(const string& s) {
	int count = 0;
	char prev = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			continue;
		}

		if (s[i] == '(') {
			count++;
		}
		else if (s[i] == ')') {
			count--;
		}
		else {
			if (!(is_variable(s[i]) || is_operation(s[i]))) {
				return i;
			}
			if ((is_variable(prev) && is_variable(s[i])) ||
				(is_operation(prev) && is_operation(s[i]))) {
				return i;
			}

			prev = s[i];
		}
		if (count < 0) {
			return i;
		}
	}
	if (count == 0)
		return -1;
	return s.length();
}


string funcs::postfix_form(string input) {
	int error_index = correct(input);
	if (error_index != -1) {
		string error = "Syntax error at index " + to_string(error_index);
		throw _strdup(error.c_str());
	}

	string result;
	stack<char> ops;

	for (const char& c : input) {
		if (is_variable(c)) {
			result += c;
		}
		else if (is_operation(c)) {
			if (ops.IsEmpty() || ops.Top() == ')') {
				ops.Push(c);
			}
			else if (priority(c) > priority(ops.Top())) {
				ops.Push(c);
			}
			else {
				while (!(ops.IsEmpty() || ops.Top() == '(' || priority(ops.Top()) < priority(c))) {
					result += ops.Top();
					ops.Pop();
				}
				ops.Push(c);
			}
		}
		else if (c == '(') {
			ops.Push('(');
		}
		else if (c == ')') {
			while (ops.Top() != '(') {
				result += ops.Top();
				ops.Pop();
			}
			ops.Pop();
		}
	}
	while (!ops.IsEmpty()) {
		result += ops.Top();
		ops.Pop();
	}

	return result;
}


double funcs::compute(string s) {
	map<char, double> values = readvalue(s);
	stack<double> stack;
	for (const char& ch : s) {
		if (is_variable(ch)) {
			stack.Push(values[ch]);
			continue;
		}
		double x = stack.Top();
		stack.Pop();
		double y = stack.Top();
		stack.Pop();
		switch (ch) {
		case '+': stack.Push(y + x);
			break;
		case '-': stack.Push(y - x);
			break;
		case '*': stack.Push(y * x);
			break;
		case '/':
			if (abs(x) <= std::numeric_limits<double>::epsilon())
				throw "Division by zero";
			stack.Push(y / x);
			break;
		}
	}
	const double result = stack.Top();
	stack.Pop();
	if (!stack.IsEmpty())
		throw "Expression is not correct";
	return result;
}

map<char, double> funcs::readvalue(const string& s) {
	map<char, double> OpValue;
	double value;
	for (const char& c : s) {
		if (is_variable(c)) {
			if (OpValue.count(c) == 0) {
				cout << "Input:" << c << endl;
				cin >> value;
				OpValue[c] = value;
			}
		}
	}
	return OpValue;
}
