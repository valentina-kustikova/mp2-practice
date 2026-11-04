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
  TDynamicMatrix<int> a(5), b(5), c(5);
  TDynamicVector<int> v(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование класса работы с матрицами"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = 0; j < 5 - i; j++ )
    {
      a[i][j] =  1;
      b[i][j] = 2;
    }

  for (int i = 0; i < 5; i++)
      v[i] = i + 1;

  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;

  TDynamicMatrix<int> d = b - a;
  cout << "Matrix d = b - a" << endl << d << endl;

  TDynamicMatrix<int> f = a * 2;
  cout << "Matrix f = a * 2" << endl << f << endl;

  TDynamicVector<int> g = a * v;
  cout << "Vector a * v (где v = [1, 2, 3, 4, 5]) = " << g << endl;

  TDynamicMatrix<int> h = a * b;
  cout << "Matrix mul_mat = a * b" << endl << h << endl;
}
//---------------------------------------------------------------------------
