#ifndef _TARITHMETIC_EXPRESSION_STR_H
#define _TARITHMETIC_EXPRESSION_STR_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "tstack.h"

using namespace std;

class TArithmeticExpression_str {
private:
	string infix;
	vector<string> postfix;
	vector<string> lexems;
	static map<string, int> priority;
	map<string, double> operands;
	
	void Parse();
	void ToPostfix();

public:
	TArithmeticExpression_str(const string& _infix);

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

	//double StringToValue(const string& str) const;

	void ConvertInfix();
};

#endif // !_TARITHMETIC_EXPRESSION_H
