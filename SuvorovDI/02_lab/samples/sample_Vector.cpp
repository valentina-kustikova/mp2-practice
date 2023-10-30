#include "Vector.h"
#include <iostream>

int main() {
  int size_1, size_2, sInd_1, sInd_2;

  try {
    std::cout << "Initializing the first vector - a:\n";
    std::cout << " -- enter the size of the first vector:\n    ";
    std::cin >> size_1;
    std::cout << " -- enter the start index of the first vector:\n    ";
    std::cin >> sInd_1;
    std::cout << " -- enter the coordinates of your vector:\n";

    TVector<int> a(size_1, sInd_1);
    std::cin >> a;
    std::cout << "\nYour vector:\n   ";
	  std::cout << a;

    std::cout << "Initializing the second vector - b:\n";
    std::cout << " -- enter the size of the second vector:\n    ";
    std::cin >> size_2;
    std::cout << " -- enter the start index of the second vector:\n    ";
    std::cin >> sInd_2;
    std::cout << " -- enter the coordinates of your vector:\n";

    TVector<int> b(size_2, sInd_2);
    std::cin >> b;
    std::cout << "\nYour vector:\n   ";
	  std::cout << b;


    // сhecking vector operations
    std::cout << "a + b :\n" << a + b << std::endl;
    std::cout << "a - b :\n" << a - b << std::endl;
    std::cout << "a * b :\n" << a * b << std::endl;

    // сhecking vector scalar operations
    int value;
    std::cout << "\nEnter some integer value - V:\n   ";
    std::cin >> value;
    std::cout << "a + V :\n" << a + value << std::endl;
    std::cout << "a - V :\n" << a - value << std::endl;
    std::cout << "a * V :\n" << a * value << std::endl;

    // checking the assignment and comparison operation
    std::cout << "a == b ?  " << (a == b) << std::endl;
    std::cout << "a != b ?  " << (a != b) << std::endl;

    std::cout << "a = b\n";
    a = b;

    std::cout << "a:\n" << a << std::endl;
    std::cout << "b:\n" << b << std::endl;

    std::cout << "a == b ?  " << (a == b) << std::endl;
    std::cout << "a != b ?  " << (a != b) << std::endl;
  }
  catch (const std::exception& exp) {
    std::cerr << exp.what() << std::endl;
  }
  
	return 0;
}