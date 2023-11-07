#include "matrix.h"
#include <iostream>
using namespace std;

int main()
{
    int dim;
    cout << "Enter matrix dimension:";
    cin >> dim;
    TMatrix <double> matrix_1(dim), matrix_2(dim);
    cin >> matrix_1;
    cin >> matrix_2;
    cout << "Matrix 1:" << endl << matrix_1 << endl;
    cout << "Matrix 2:" << endl << matrix_2 << endl;
    cout << "Matrix 1 + Matrix 2:" << endl << matrix_1 + matrix_2 << endl;
    cout << "Matrix 1 * Matrix 2:" << endl << matrix_1 * matrix_2 << endl;
    return 0;
}