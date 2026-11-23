#ifndef __POSTFIX_FORM_H__
#define __POSTFIX_FORM_H__
#include<vector>
#include<utility>
#include<string>
#include"stack.h"
 
const size_t STACK_SIZE = 10000;

class ArithmeticExpression
{
	std::string expression;
	const std::string all_operations = "+-*/()";
	bool isOperation(char) const;
	bool isOperand(char) const;
	int getPriority(char) const;
	void validate() const;
	std::vector<char> GetUnique() const;
public:
	ArithmeticExpression(const std::string& exp) :
		expression(exp) {
		validate();
	};
	std::string GetPostfix() const;
	double Compute(const std::vector<std::pair<char, double>>&) const;
	std::vector<std::pair<char, double>> MakeVectorPair() const;
};

#endif 