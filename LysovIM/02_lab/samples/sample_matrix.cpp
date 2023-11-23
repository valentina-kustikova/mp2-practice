#include "matrix.h"
#include <iostream>
using namespace std;

int main()
{
    int Dimension;
    cout << "Enter the dimensionality of the original matrix:"<<"\t";
    cin >> Dimension;
    TMatrix <double> matrix1(Dimension), matrix2(Dimension);
    cin >> matrix1;
    cin >> matrix2;
    cout << "Matrix 1:" << endl << matrix1;
    cout << "Matrix 2:" << endl << matrix2;
    cout << "Matrix 1 + matrix 2:" << endl << matrix1 + matrix2;
    cout << "Matrix 1 * matrix 2:" << endl << matrix1 * matrix2;
    cout << "Matrix 1 == Matrix 2?" << "\t" << (matrix1 == matrix2);
    return 0;
}