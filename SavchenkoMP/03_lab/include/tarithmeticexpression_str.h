#ifndef _TARITHMETIC_EXPRESSION_H
#define _TARITHMETIC_EXPRESSION_H

#include <iostream>
#include <map>
#include <vector>
#include "tstack.h"

using namespace std;

class TArithmeticExpression {
private:
	string infix;
	string postfix;
	vector<char> lexems;
	static map<char, int> priority;
	map<char, double> operands;
	
	void Parse();
	void ToPostfix();

public:
	TArithmeticExpression(string _infix);

	string GetInfix() const { return infix; }
	string GetPostfix() const { return postfix; }

	vector<char> GetOperands() const;
	void SetValues();
	void SetValues(map<char, double>& values);

	double Calculate();
	double Calculate(const map<char, double>& values);
};

#endif // !_TARITHMETIC_EXPRESSION_H
