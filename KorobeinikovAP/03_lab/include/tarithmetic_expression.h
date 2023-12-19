#ifndef __TARITHMETIC_EXPRESSION_H__
#define __TARITHMETIC_EXPRESSION_H__

#include <iostream>
#include <vector>
#include <map>
#include "tstack.h"

class TArithmeticExpression {
private:
	string infix;
	string postfix;
	vector<char> lexems;
	map <char, int> priority;
	map <char, double> operands;

	void Parse();
	void ToPostfix();
public:




};
#endif
