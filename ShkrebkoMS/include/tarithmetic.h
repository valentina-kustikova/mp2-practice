#ifndef _TARITHMETIC_H
#define _TARITHMETIC_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "tstack.h"

using namespace std;

class TArithmeticExpression {
private:
	string infix;
	vector<string> postfix;
	vector<string> lexems;
	static map<string, int> priority;
	map<string, double> operands;
	void Parse();
	void ToPostfix();
	bool IsOperator(const string& lecsem) const;
	bool IsConst(const string& lecsem) const;
	double Calculate(const map<string, double>& values);

public:
	TArithmeticExpression(const string& infix);
	string GetInfix() const { return infix; }
	vector<string> GetPostFix() const { return postfix; }
	bool isCorrectInfixExpression();
	void SetValues();
	double Calculate();
};

#endif