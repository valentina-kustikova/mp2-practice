#ifndef __TARITHMETIC_EXPRESSION_H__
#define __TARITHMETIC_EXPRESSION_H__

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "tstack.h"


//вспомогательные функции
bool IsVariable(const string& op);
bool IsOperator(const string& op);
bool IsConst(const string& op);
bool IsBinaryOperator(const char& op);

class TArithmeticExpression {
private:
	string infix;
	vector<string> postfix;
	vector<string> lexems;
	map <string, int> priority;
	map <string, double> operands;

	
	int FindFirstOperator(int pos) const;

	void SetOperand(const string& operand);

	void GetFinishedLine();
	void CheckCorrect() const;

	void Parse();
	void ToPostfix();
public:
	//TArithmeticExpression(const string& infx);
	TArithmeticExpression(const string& infx, const map<string, double> operands_ = map<string, double>());
	TArithmeticExpression();
	string GetInfix() const;
	string GetPostfix()  const {
		string postfix_str = postfix[0];
		for (int i = 1; i < postfix.size(); i++) postfix_str  += postfix[i];
		return postfix_str;
	}

	vector<string> GetLexems() {
		return lexems;
	}

	double  Calculate();
};
#endif
