
#include <iostream>
#include "tmatrix.h"

int main()
{
    std::cout << "Input a size of matrix\n";
    int size;
    std::cin >> size;
    TMatrix<int> A(size), B(size);
    std::cout << "Input matrix A and B" << std::endl;
    std::cin >> A >> B;
    std::cout << A << "\n" << B;
    std::cout << "------------\n";

    TMatrix<int> C(size);
    C = A + B;
    std::cout << "C = A + B: "<< '\n' << C << std::endl;
    std::cout << "------------\n";

    TMatrix<int> D(size);
    D = A - B;
    std::cout << "D = A - B: " << '\n' << D << std::endl;
    std::cout << "------------\n";

    TMatrix<int> E(size);
    E = A * B;
    std::cout << "E = A * B: " << '\n' << E << std::endl;

    return 0;
}
