#include "Vector.h"
#include "Matrix.h"
#include <iostream>


int main() {
	TMatrix<int> m(5);
	TMatrix<int> d(5);

	try {
		std::cin >> m;
		std::cin >> d;

		std::cout << m * d;
	}
	catch (std::exception exp) {
		std::cout << exp.what();
	}
	/*int size = 3;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			for (int k = 0; k < j + 1 && k < size - i; k++) {
				std::cout << "res[" << i << ", " << j << "] = " << "a[" << i << ", " << k << "] + b[" << k << ", " << j - i << "]\n";
			}
		}
	}*/


	return 0;
}