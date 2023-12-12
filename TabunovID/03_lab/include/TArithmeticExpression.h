#ifndef _TARITHMETICEXPRESSION_H
#define _TARITHMETICEXPRESSION_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "STack.h"

using namespace std;

class TArithmeticExpression
{
private:
	string infix;
	vector<string> postfix;
	vector<string> lexems;
	map<string, int> priority;
	map<string, double> operands;

	void Parse();
	void ToPostfix();
	bool IsOperator(const string& lecsem) const;
	bool IsConst(const string& lecsem) const;
	

public:

	TArithmeticExpression(string infix);

	string GetInfix() const { return infix; }
	vector<string> GetPostFix() const { return postfix; }

	bool isCorrectInfixExpression();
	vector<string> GetOperands() const;
	void SetValues();
	double Calculate(const map<string, double>& values);
	double Calculate();
	void ShowPostfix();

};

#endif