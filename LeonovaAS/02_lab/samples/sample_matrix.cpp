﻿// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  TDynamicMatrix<int> a(5), b(5), c(5), d(5);
  //TDynamicVector<int> v(5), v1(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование класса работы с матрицами"
    << endl;
  for (i = 0; i < 5; i++)
  {
      //v[i] = i;
      for (j = 0; j < 5 - i; j++)
      {
          a[i][j] = i * 10 + j;
          b[i][j] = (i * 10 + j) * 100;
      }
  }
  c = a * b;
  d = a * 5;
  //v1 = a * v;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a * b" << endl << c << endl;
  cout << "Matrix d = " << endl << d << endl;
  //cout << "Matrix a = " << endl << a << endl;
  //cout << "Vector v = " << endl << v << endl;
  //cout << "Vector a * v = " << endl << v1 << endl;
}
//---------------------------------------------------------------------------
