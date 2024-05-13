#include <iostream>
#include "tmonom.h" 

int main() {
	double coeff1, coeff2;
	int degree1, degree2;
	std::cout << "Let's create first monom: coeff = ";
	std::cin >> coeff1;
	std::cout << std::endl <<"degree = " ;
	std::cin >> degree1;

	std::cout << std::endl <<"Let's create second monom: coeff = ";
	std::cin >> coeff2;
	std::cout << std::endl << "degree = ";
	std::cin >> degree2;

	TMonom m1(coeff1, degree1);
	TMonom m2(coeff2, degree2);

	std::cout << "m1 < m2: " << (m1 < m2) << std::endl;
	std::cout << "m1 <= m2: " << (m1 <= m2) << std::endl;
	std::cout << "m1 > m2: " << (m1 > m2) << std::endl;
	std::cout << "m1 >= m2: " << (m1 >= m2) << std::endl;
	std::cout << "m1 == m2: " << (m1 == m2) << std::endl;
	std::cout << "m1 != m2: " << (m1 != m2) << std::endl;

	return 0;
}