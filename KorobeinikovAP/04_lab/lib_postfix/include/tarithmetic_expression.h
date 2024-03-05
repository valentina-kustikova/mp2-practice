#ifndef __TARITHMETIC_EXPRESSION_H__
#define __TARITHMETIC_EXPRESSION_H__

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "tstack.h"

class TArithmeticExpression {
private:
	string infix;
	vector<string> postfix;
	vector<string> lexems;
	map <string, int> priority;
	map <string, double> operands;

	//вспомогательные функции
	bool IsOperator(const string& op) const;
	bool IsConst(const string& op) const;
	bool IsBinaryOperator(const char& op) const;
	int FindFirstOperator(int pos) const;

	void SetOperand(const string& operand);

	void GetFinishedLine();
	void CheckCorrect() const;


	void Parse();
	void ToPostfix();
public:
	//TArithmeticExpression(const string& infx);
	TArithmeticExpression(const string& infx, const map<string, double> operands_ = map<string, double>());

	string GetInfix() const {
		return infix;
	}
	string GetPostfix()  const {
		string postfix_str = postfix[0];
		for (int i = 1; i < postfix.size(); i++) postfix_str  += postfix[i];
		return postfix_str;
	}

	double  Calculate();
};
#endif
