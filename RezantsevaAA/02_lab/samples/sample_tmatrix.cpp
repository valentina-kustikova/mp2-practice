#include <iostream>

#include "tmatrix.h"

int main()
{
    TMatrix <double> A(3), B(3), C(3);
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3 - i; j++)
        {
            A[i][j] = 1 + i;
            B[i][j] = 2 + 2 * i;
            C[i][j] = A[i][j];
        }
    

   std::cout << "A:" << std::endl << A << std::endl;
   std::cout << "B:" << std::endl << B << std::endl;
   std::cout << "C:" << std::endl << C << std::endl;

   std::cout << "A + B:" << std::endl << A + B << std::endl;
   std::cout << "A - B:" << std::endl << A - B << std::endl;
   std::cout << "A * B:" << std::endl << A * B << std::endl;

   std::cout << "A == B ? " << (A == B) << std::endl;
   std::cout << "A != B ? " << (A != B) << std::endl;
   std::cout << "A == C ? " << (A == C) << std::endl;
   std::cout << std::endl;
    return 0;
}
