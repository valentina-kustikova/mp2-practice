#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "tstack.h"
#include <string>
#include <tstack.h>

using namespace std;
class ArithmeticExpression {
protected:
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
	virtual ~ArithmeticExpression() { 
		arexp = "";
		mas.clear();
		post_form.clear();
		if (!values.empty()) values.clear();
	};

	void ToPostfixForm();
	float Calculate();

	string InfixForm() const;
	string PostfixForm() const;
	string getArexp() const { return arexp; }
};