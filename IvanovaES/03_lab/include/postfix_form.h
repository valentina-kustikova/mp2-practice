#pragma once
#include <iostream>
#include <string>

class PostfixForm {
private:
	std::string infix;
	std::string postfix;
	
	int GetPriority(char op) const;
public:
	PostfixForm(const std::string& expr);

	double Calculate() const;
};