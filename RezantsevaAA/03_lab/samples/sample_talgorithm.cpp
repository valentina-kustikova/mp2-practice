#include <iostream>
#include "talgorithm.h"

int main()
{
	std::string s1 = "A+B+X1+XY+2.5+3";

	std::string s2 = "A+(B-A)/(D-A)*K-(A+B)/B";
	Postfix postfix1 = postfix1.ConvertToPol(s1);
	std::cout << "Formula 1 : " << s1 << std::endl;
	std::cout << "Postfix 1 : " << postfix1 << std::endl;
	

	postfix1.setValues();
	double result1 = postfix1.calculate();
	std::cout << "Result for formula 1 = " << result1 << std::endl;

	Postfix postfix2 = postfix2.ConvertToPol(s2);
	std::cout << "Formula 2 : " << s2 << std::endl;
	std::cout << "Postfix 2 : "<< postfix2 << std::endl;;

	postfix2.setValues();
	double result2 = postfix2.calculate();
	std::cout << "Result for formula 2 = " << result2 << std::endl;

	return 0;

}
