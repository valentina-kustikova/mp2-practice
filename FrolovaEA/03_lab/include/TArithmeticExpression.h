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

protected:

	void Parse();
	void ToPostfix();
	void InToPostfix();
	vector<string> GetPostFix() const { return postfix; }

	bool IsOperator(const string& lecsem) const;
	bool IsConst(const string& lecsem) const;
	bool isOperatorChar(char c) const;
	bool isCorrectInfixExpression();
	vector<string> GetOperands() const;
	
	

public:

	TArithmeticExpression(const string& infix);
	void SetValues();
	string GetInfix() const { return infix; }
	string GetPostFix_str() const { return str_postfix; }
	double Calculate(const map<string, double>& values);
	double Calculate();
	void ShowPostfix();
	

};

#endif