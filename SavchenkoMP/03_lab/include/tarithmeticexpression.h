#ifndef _TARITHMETIC_EXPRESSION_H
#define _TARITHMETIC_EXPRESSION_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "tstack.h"

using namespace std;

class TArithmeticExpression {
private:
	string infix;
	vector<string> postfix;
	vector<string> lexems;
	static map<string, int> priority;
	map<string, double> operands;

	void Parse();
	void ToPostfix();

public:
	TArithmeticExpression(const string& _infix);
	TArithmeticExpression(const TArithmeticExpression& ae);

	string GetInfix() const { return infix; }
	vector<string> GetPostfix() const { return postfix; }
	string GetStringPostfix() const;

	vector<string> GetOperands() const;
	void SetValues();
	void SetValues(map<string, double>& values);
	void ClearValues();

	double Calculate();
	double Calculate(const map<string, double>& values);

private:
	bool IsOperator(const string& isopr) const;
	bool IsConst(const string& isopd) const;

	int FindOperator(int pos = 0) const;

	void ConvertInfix();
	void CorrectnessCheck();
};

#endif // !_TARITHMETIC_EXPRESSION_H
