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
  TDynamicMatrix<int> a(5), b(5), matrix_res(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование класса работы с матрицами"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  matrix_res = a * 5;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix matrix_res = a * 5" << endl << matrix_res << endl;
  TDynamicVector<int> vec(5), vector_res(5);
  for (i = 0; i < 5; i++) 
  {
      vec[i] = i;
  }
  vector_res = a * vec;
  cout << "Vector vec = " << endl << vec << endl;
  cout << "Vector vector_res = a * vec" << endl << vector_res << endl;
  matrix_res = a + b;
  cout << "Matrix matrix_res = a + b" << endl << matrix_res << endl;
  matrix_res = b - a;
  cout << "Matrix matrix_res = b - a" << endl << matrix_res << endl;
  matrix_res = a * b;
  cout << "Matrix matrix_res = a * b" << endl << matrix_res << endl;
}
//---------------------------------------------------------------------------