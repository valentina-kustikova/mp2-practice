#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "stack.h"

class ArithmeticExp {
private:
	std::string original_exp;
	std::vector<std::string> vector_postfix_exp;
	std::string string_postfix_exp;

	std::vector<std::string> lexemes;
	std::map<std::string, int> priorities;
	std::map<std::string, double> operands_values;
	std::vector<std::string> valid_symbols;

	void Parse();
	void ToPostfix();
	bool Check();
public:
	ArithmeticExp(const std::string &exp);

	std::string GetOriginal() const {return original_exp;}
	std::string GetPostfix() const { return string_postfix_exp; }

	std::vector<std::string> GetOperands() const;
	double Calculate(const std::map<std::string, double>& values);
};