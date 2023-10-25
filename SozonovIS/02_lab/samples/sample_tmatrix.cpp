#include "tmatrix.h"

#include <iostream>

using namespace std;

int main()
{
    int size;
    cout << "Enter matrix size:";
    cin >> size;

    TMatrix<double> A(size), B(size), C(size);
    cin >> A;
    cin >> B;

    cout << "A:" << endl << A << endl;
    cout << "B:" << endl << B << endl;

    cout << "A + B:" << endl << A + B << endl;
    cout << "A - B:" << endl << A - B << endl;
    cout << "A * B:" << endl << A * B << endl;

    C = A;
    cout << "C:" << endl << C << endl;

    std::cout << "A == B ? " << (A == B) << std::endl;
    std::cout << "A != B ? " << (A != B) << std::endl;
    std::cout << "A == C ? " << (A == C) << std::endl;

    return 0;
}
