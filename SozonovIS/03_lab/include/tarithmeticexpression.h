#ifndef __ARITHMETICEXPRESSION_H__
#define __ARITHMETICEXPRESSION_H__

#include "tstack.h"

#include <iostream>
#include <map>
#include <vector>
#include <string>

class TArithmeticExpression {
private:
	std::string infix;
	std::vector<std::string> postfix;
	std::vector<std::string> lexems;
	std::map<std::string, int> priority;
	std::map<std::string, double> operands; 
	bool IsOperator(char c)const;
	bool IsConst(const std::string& str)const;
	void Check();
	void Parse();
	void ToPostfix();
public:
	TArithmeticExpression(const std::string& infx);
	std::string GetInfix() const;
	std::string GetPostfix() const;
	std::vector<std::string> GetOperands() const;
	std::map<std::string, double> SetValues();
	double Calculate(const std::map<std::string, double>& values); //?const
};

#endif