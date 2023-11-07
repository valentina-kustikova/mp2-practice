#include "Vector.h"
#include "Matrix.h"
#include <iostream>

int main() {
	TMatrix<int> m(5);
	TMatrix<int> d(5);

  // сhecking matrix operations
	try {
		std::cin >> m;
		std::cin >> d;

    std::cout << "Your matrixes:\n";
    std::cout << "m:\n" << m << std::endl;
    std::cout << "d:\n" << d << std::endl;

    std::cout << "\nCompare the results of all operations with your matrices:\n";

		std::cout << "m * d :\n" << m * d << std::endl;
    std::cout << "m + d :\n" << m + d << std::endl;
    std::cout << "m - d :\n" << m - d << std::endl;
	}
	catch (const std::exception& exp) {
		std::cerr << exp.what() << std::endl << std::endl;
	}

  // checking the assignment and comparison operation
  try {
    std::cout << "m == d ?  " << (m == d) << std::endl;
    std::cout << "m != d ?  " << (m != d) << std::endl;

    std::cout << "m = d\n";
    m = d;

    std::cout << "m:\n" << m << std::endl;
    std::cout << "d:\n" << d << std::endl;

    std::cout << "m == d ?  " << (m == d) << std::endl;
    std::cout << "m != d ?  " << (m != d) << std::endl;
	}
	catch (const std::exception& exp) {
		std::cerr << exp.what() << std::endl;
	}
	
	return 0;
}