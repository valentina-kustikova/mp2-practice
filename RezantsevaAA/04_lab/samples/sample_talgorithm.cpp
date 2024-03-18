#include <iostream>
#include "talgorithm.h"
#include <math.h>
int main()
{
	
	std::string s;
	std::cin >> s;
	try
	{
		Postfix postfix = postfix.ConvertToPol(s);
		std::cout << "Formula : " << s << std::endl;
		std::cout << "Postfix : " << postfix << std::endl;


		postfix.setValues();
		double result = postfix.calculate();
		std::cout << "Result for formula = " << result << std::endl;
	}
	catch (const char* ex)
	{
		std::cout << ex;
	}

	return 0;

}
