#include "tset.h"
#include <iostream>

int main() {
	int size_U;
	std::cout << "Enter size of set U for set a:" << std::endl;
	std::cin >> size_U;
	TSet a(size_U);

	std::cout << "Enter size of set U for set b:" << std::endl;
	std::cin >> size_U;
	TSet b(size_U);

	std::cout << "Enter size of set U for set c:" << std::endl;
	std::cin >> size_U;
	TSet c(size_U);

	try {
		std::cout << "a ( |U| = " << a.GetMaxPower() << " ): " << a << std::endl;
		std::cout << "b ( |U| = " << b.GetMaxPower() << " ): " << b << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cout << "a ( |U| = " << a.GetMaxPower() << " ): ";
		std::cin >> a;
		std::cout << "b ( |U| = " << b.GetMaxPower() << " ): ";
		std::cin >> b;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cout << "a ( |U| = " << a.GetMaxPower() << " ): " << a << std::endl;
		std::cout << "b ( |U| = " << b.GetMaxPower() << " ): " << b << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cout << "a + b = " << (a + b) << std::endl;
		std::cout << "a + 3 = " << (a + 3) << std::endl;
		std::cout << "a * b = " << (a * b) << std::endl;
		std::cout << "b - 2 = " << (b - 2) << std::endl;
		std::cout << "~a = " << (~a) << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cout << "c ( |U| = " << c.GetMaxPower() << " ): ";
		std::cin >> c;
		std::cout << "c ( |U| = " << c.GetMaxPower() << " ): " << c << std::endl;
		
		std::cout << "c == a ?  " << (c == a) << std::endl;
		std::cout << "c != b ?  " << (c != b) << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cout << "c = a" << std::endl;
		c = a;
		
		std::cout << "c == a ?  " << (c == a) << std::endl;
		std::cout << "c != b ?  " << (c != b) << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	return 0;
}