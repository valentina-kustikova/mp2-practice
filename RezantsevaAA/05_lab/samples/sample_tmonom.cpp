#include <iostream>
#include "tmonom.h"

int main()
{
	TMonom monom1, monom2;
	std::cout << "Let's create first monom" << std::endl;
	std::cin >> monom1;
	std::cout << "First monom: " << monom1 << std::endl;

	std::cout << "Let's create second monom" << std::endl;
	std::cin >> monom2;
	std::cout << "Second monom: " << monom2 << std::endl;

	std::cout << "Let's compare our monoms: " << std::endl;
	std::cout << "m1 > m2 ? " << (monom1 > monom2) << std::endl;
	std::cout << "m1 < m2 ? " << (monom1 < monom2) << std::endl;
	std::cout << "m1 == m2 ? " << (monom1 == monom2) << std::endl;
	std::cout << "m1 != m2 ? " << (monom1 != monom2) << std::endl;

	try {
		std::cout << "Let's multiply our monoms: m1 * m2 = " << monom1 * monom2 << std::endl;
	}
	catch (const char* error_message)
	{
		std::cout << "Error. Result degree out of range. Please, enter monoms with different degrees" << std::endl;
		std::cin >> monom1;
		std::cin >> monom2;
		std::cout << "First monom: " << monom1 << std::endl;
		std::cout << "Second monom: " << monom2 << std::endl;
		std::cout << "Let's multiply our monoms: m1 * m2 = " << monom1 * monom2 << std::endl;
	}
	try {
		std::cout << "Let's add up our monoms:  m1 + m2 = " << monom1 + monom2 << std::endl;
		std::cout << "Let's add up our monoms: m1 - m2 = " << monom1 - monom2 << std::endl;
	}
	catch (const char* error_message) {
		std::cout << "Monoms degrees aren't equal. Can't add and substract. Please, enter monoms with equal degrees " << std::endl;
		std::cin >> monom1;
		std::cin >> monom2;
		std::cout << "First monom: " << monom1 << std::endl;
		std::cout << "Second monom: " << monom2 << std::endl;
		std::cout << "Let's add up our monoms:  m1 + m2 = " << monom1 + monom2 << std::endl;
		std::cout << "Let's substract up our monoms: m1 - m2 = " << monom1 - monom2 << std::endl;
	}
	return 0;
}
