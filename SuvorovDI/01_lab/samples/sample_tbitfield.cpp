#include "tbitfield.h"
#include <iostream>

int main() {

	TBitField a(18);
	TBitField b(10);
	TBitField c(18);
	
	try {
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	std::cout << "\n-----------------------------------\n";

	try {
		std::cout << "a: ";
		std::cin >> a;
		std::cout << "b: ";
		std::cin >> b;
		std::cout << "c: ";
		std::cin >> c;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	std::cout << "\n-----------------------------------\n";

	try {
		std::cout << "a | c :: " << (a | c) << std::endl;
		std::cout << "c & a :: " << (c & a) << std::endl;
		std::cout << "~b :: " << (~b) << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		std::cout << "a == c ? Answer: " << (a == c) << std::endl;
		std::cout << "c != b ? Answer: " << (c != b) << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	try {
		b = a;
		std::cout << "Variable b was assigned variable a\n";
		std::cout << "b == a ? Answer: " << (b == a) << std::endl;
		std::cout << "a == c ? Answer: " << (c != b) << std::endl;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}

	return 0;
}