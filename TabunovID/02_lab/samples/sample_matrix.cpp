#include "TMatrix.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Input a size of matrix\n";
    int size;
    cin >> size;
    TMatrix<int> A(size), B(size);
    cout << "Input matrix A and B" << endl;
    cin >> A >> B;
    cout << A << "\n" << B;
    cout << "------------\n";

    TMatrix<int> C(size);
    C = A + B;
    cout << "C = A + B: " << '\n' << C << endl;
    cout << "------------\n";

    TMatrix<int> D(size);
    D = A - B;
    cout << "D = A - B: " << '\n' << D << endl;
    cout << "------------\n";

    TMatrix<int> E(size);
    E = A * B;
    cout << "E = A * B: " << '\n' << E << endl;

    return 0;
 }