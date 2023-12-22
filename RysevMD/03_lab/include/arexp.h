#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "tstack.h"
#include <string>
#include <tstack.h>

using namespace std;
class ArithmeticExpression {
private:
	string arexp;
	vector<string> mas;
	vector<string> post_form;
	map<string, double> values;
	bool IsOperation(const string& symbol) const noexcept;
	bool IsOperation(const char& symbol) const noexcept;
	bool IsInvalidSign(const char& symbol) const noexcept;
	void GetTokens();
	void GetValues();
	bool IsParam(const string& tok) const noexcept;
	bool IsConst(const string& tok) const noexcept;
public:
	ArithmeticExpression();
	ArithmeticExpression(const string& str);

	void ToPostfixForm();
	float Calculate();

	string InfixForm();
	string PostfixForm();
};