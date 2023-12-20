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
	string str_postfix;
	vector<string> postfix;
	vector<string> lexems;
	map<string, int> priority;
	map<string, double> operands;

	void Parse();
	void ToPostfix();
	bool IsOperator(const string& lecsem) const;
	bool IsConst(const string& lecsem) const;
	

public:

	TArithmeticExpression(const string& infix);

	string GetInfix() const { return infix; }
	vector<string> GetPostFix() const { return postfix; }
	string GetPostFix_str() const { return str_postfix; }


	bool isCorrectInfixExpression();
	vector<string> GetOperands() const;
	void SetValues();
	double Calculate(const map<string, double>& values);
	double Calculate();
	void ShowPostfix();
	void InToPostfix();

};

#endif