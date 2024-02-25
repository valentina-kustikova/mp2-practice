#include "tarithmeticexpression.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {

	std::string exprStr;
	std::cout << "Enter expression: ";
	std::cin >> exprStr;

	TArithmeticExpression expr(exprStr);
	std::cout << "Postfix: " << expr.GetPostfix() << std::endl;
	std::cout << std::endl;

	std::vector<std::string> operands = expr.GetOperands();
	std::map<std::string, double> values;
	values = expr.SetValues();
	std::cout << std::endl;

	std::cout << "Result: " << expr.Calculate(values) << std::endl;
	return 0;
}