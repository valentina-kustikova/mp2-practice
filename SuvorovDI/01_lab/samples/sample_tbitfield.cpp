#include "tbitfield.h"
#include <iostream>

int main() {

	TBitField a(10);
	TBitField b(4);
	TBitField c(4);

	try {
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cin >> a;
		std::cin >> b;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cout << (a | b) << std::endl;
		std::cout << (a & b) << std::endl;
		std::cout << (~a) << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cout << c << std::endl;
		std::cin >> c;
		std::cout << c << std::endl;
	
		std::cout << (c == a) << std::endl;
		std::cout << (c != b) << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		c = a;
		
		std::cout << (c == a) << std::endl;
		std::cout << (c != b) << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	return 0;
}