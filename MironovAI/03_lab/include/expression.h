#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "tstack.h"

using namespace std;

class Expression {
private:
	string infix;
	vector<string> postfix;
	vector<string> lexems;
	map<string, short> priority;
	map<string, double> operands;
	double res;

	void Parse();
	void Convert();
	void Preparation();
	bool IsOperator(const string& op) const;
	bool IsConst(const string& op) const;
	bool IsArOperator(const char& op) const;
	void IsCorrect() const;
	int FindFirstOperator(int pos = 0) const;
	void Calculate();
	void SetOperand(const string& operand);

public:
	Expression(const string& expression, const map<string, double> operands_ = map<string, double>());

	string GetInfix() const { return infix; }
	string GetPostfix() const;
	double Get_res() const { return res; }

};

#endif