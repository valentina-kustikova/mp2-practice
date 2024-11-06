#include <iostream>
#include "tmatrix.h"

void main()
{
    TDynamicMatrix<int> a(5), b(5), c(5);
    int i, j;

    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ ������ � ���������"
        << endl;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5-i; j++)
        {
            a[i][j] = i;
            b[i][j] = j;
        }
    c = a * b;
    cout << "Matrix a = " << endl << a << endl;
    cout << "Matrix b = " << endl << b << endl;
    cout << "Matrix c = a * b" << endl << c << endl;
}