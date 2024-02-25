#include "tmatrix.h"

#include <iostream>

using namespace std;

int main()
{
    try {
        int size;
        cout << "Enter matrix size: ";
        cin >> size;
        cout << endl;

        TMatrix<double> A(size);
        cout << "Enter matrix vectors: " << endl;
        cin >> A;
        cout << endl;

        cout << "Enter matrix size: ";
        cin >> size;
        cout << endl;

        TMatrix<double> B(size);
        cout << "Enter matrix vectors: " << endl;
        cin >> B;
        cout << endl;

        cout << "Matrix A:" << endl << A << endl;
        cout << "Matrix B:" << endl << B << endl;

        cout << "A == B ? " << (A == B) << endl;
        cout << "A != B ? " << (A != B) << endl;
        cout << endl;

        cout << "A + B:" << endl << A + B << endl;
        cout << "A - B:" << endl << A - B << endl;
        cout << "A * B:" << endl << A * B << endl;
    }
    catch (exception exp) {
        cout << exp.what();
    }
    return 0;
}
