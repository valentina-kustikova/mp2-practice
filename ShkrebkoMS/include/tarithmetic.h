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
	string spostfix;
	vector<string> postfix;
	vector<string> lexems;
	static map<string, int> priority;
	map<string, double> operands;
	void Parse();
	void ToPostfix();
	bool IsOperator(const string& lexem) const;
	bool IsConst(const string& lexem) const;

	void InToPostfix();

public:
	TArithmeticExpression(const string& infix);
	string GetInfix() const { return infix; }
	string GetPostfix_str() const { return spostfix; }
	vector<string> GetPostfix() const { return postfix; }
	bool isCorrectInfixExpression();
	void SetValues();
	double Calculate();
	double Calculate(const map<string, double>& values);
	void ShowPostfix();
};



#endif