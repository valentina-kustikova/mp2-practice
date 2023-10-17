#include "tset.h"
#include <iostream>

int main() {

	TSet a(6);
	TSet b(4);
	TSet c(4);

	try {
		std::cout << "a ( |U| = 6 ): " << a << std::endl;
		std::cout << "b ( |U| = 4 ): " << b << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cout << "a ( |U| = 6 ): ";
		std::cin >> a;
		std::cout << "b ( |U| = 4 ): ";
		std::cin >> b;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cout << "a ( |U| = 6 ): " << a << std::endl;
		std::cout << "b ( |U| = 4 ): " << b << std::endl;
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
		std::cout << "c ( |U| = 4 ): ";
		std::cin >> c;
		std::cout << "c ( |U| = 4 ): " << c << std::endl;
		
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