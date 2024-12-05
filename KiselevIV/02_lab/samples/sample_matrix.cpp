// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------


void main()
{
    TDynamicMatrix<int> a(3), b(3), c(3);
    int i, j;

    setlocale(LC_ALL, "Russian");
    cout << "Тестирование класса работы с матрицами"
        << endl;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3 - i; j++)
        {
            a[i][j] = i*3 + j;
            b[i][j] = a[i][j] * 2;
        }
    c = a + b;
    cout << "Matrix a = " << endl << a << endl;
    cout << "Matrix b = " << endl << b << endl;
    cout << "Matrix c = a + b" << endl << c << endl;

}
//---------------------------------------------------------------------------
