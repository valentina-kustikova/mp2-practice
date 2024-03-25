#include <iostream>
#include "tmonom.h"

int main()
{
	
	TMonom monom1(5,2);
	std::cout << "Created monom with degree = " << monom1.GetDegree() << " and  Coeff = " << monom1.GetCoeff() << std::endl;
	std::cout << "Our monom: " << monom1 << std::endl;
	std::cout << "Lets set new coeff and new degree" << std::endl;
	monom1.SetCoeff(8);
	monom1.SetDegree(20);
	std::cout << "Changed monom: " << monom1 << std::endl;
	
	TMonom monom2(5, 21);
	std::cout << "Monom2: " << monom2 << std::endl;
	std::cout << "Lets multiply monom1 and monom2: " << monom1 * monom2 << std::endl;

	TMonom m1(5, 4);
	TMonom m2(2, 4);
	TMonom m3(2, 2);
	TMonom m4(3, 20);
	TMonom m5(5, 4);

	std::cout << "m1: " << m1 << std::endl;
	std::cout << "m2: " << m2 << std::endl;
	std::cout << "m3: " << m3 << std::endl;
	std::cout << "m4: " << m4 << std::endl;
	std::cout << "m4: " << m5 << std::endl;
	std::cout << "Lets compare: m1 > m2? " << (m1 > m2) << std::endl;
	std::cout << "Lets compare: m1 == m2? " << (m1 == m2) << std::endl;
	std::cout << "Lets compare: m1 == m5? " << (m1 == m5) << std::endl;
	std::cout << "Lets compare: m1 != m2? " << (m1 != m2) << std::endl;
	std::cout << "Lets compare: m1 < m2? " << (m1 < m2) << std::endl;
	std::cout << "Lets compare: m1 > m3? " << (m1 > m3) << std::endl;
	std::cout << "Lets compare: m2 > m3? " << (m2 > m3) << std::endl;
	std::cout << "Lets compare: m4 > m3? " << (m4 > m3) << std::endl;

	TMonom m6(7, 221);
	std::cout << m6.getStringMonom();

	return 0;
}
