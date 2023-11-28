#ifndef _ARITHMETIC_H
#define _ARITHMETIC_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "stack.h"
using namespace std;


class TArithmeticExpession {
private:
	string infix;
	vector<string> postfix;
	vector<string> lexems;
	map<char, int> priority ={
		   {'*', 3},
		   { '/', 3},
		   { '+', 2},
		   { '-', 2},
		   { '( ', 1}
	};
	map<string, double> operands;
public:
	TArithmeticExpession(const string& _infix);
	string GetInfix() const { return infix; }
	vector<string> GetPostfix() const { return postfix; }
	string GetStringPostfix() const;
	vector<string> GetOperands()const;
	void Parse();
	void ToPostfix();
	bool IsOperator(const char& c) const;
	bool IsConst(const string& s) const;
	double Calculate(const map<string, double>& values);
};

#endif 