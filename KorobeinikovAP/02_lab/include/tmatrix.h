// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных", С++, ООП
//
// tmatrix.cpp - бесполезный файл поскольку класс шаблонный 
// Разработано для Microsoft Visual Studio 2022 Коробейниковым А.П. (15.10.2023)
//
// Матрица - реализация через публичное наследование вектора векторов

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "tvector.h"


template <typename T>
class TMatrix: public Vector<Vector<T>>
{
public:
  TMatrix<T>(int mn = 10);                        //конструктор по умолчанию
  TMatrix<T>(const TMatrix<T> &m);                // конструктор копирования
  TMatrix<T>(const Vector<Vector<T>> &vec);       // конструктор преобразования типа
  
  const TMatrix<T>& operator = (const TMatrix<T>& m);    //оператор присваивания

  bool operator == (const TMatrix<T>& m) const;      //оператор проверки на равенство
  bool operator != (const TMatrix<T>& m) const;      //оператор проверки на неравенство

  TMatrix<T> operator + (const TMatrix<T>& m);       //сложение матриц
  TMatrix<T> operator - (const TMatrix<T>& m);       //вычитание матриц
  TMatrix<T> operator * (const TMatrix<T>& m);       //умножение матриц

  friend istream& operator>>(istream& istr, TMatrix<T>& m) {
	  for (int i = 0; i < m.n; ++i) {
		  int x = m.GetSize() - m.coor[i].GetStart_index();
		  cout << "Enter line number  " << m.coor[i].GetStart_index() + 1
			   << ", there are " << x << " elements in it" << endl;
		  istr >> m.coor[i];
	  }
	  return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TMatrix<T>& m) {
	  for (int i = 0; i < m.n; ++i) {
		  ostr << m.coor[i];
	  }
	  return ostr;
  }
};

// конструкторы 

template <typename T>
TMatrix<T>::TMatrix(int mn): Vector<Vector<T>>(mn) {
	for (int i = 0; i < mn; ++i) {
		coor[i] = Vector<T>(mn - i, i);
	}
}

template <typename T>
TMatrix<T>::TMatrix(const TMatrix<T>& m) : Vector<Vector<T>>((Vector<Vector<T>>) m) {}

template <typename T>
TMatrix<T>::TMatrix<T>(const Vector<Vector<T>>& v) : Vector<Vector<T>> (v) {}

//операторы 

template <typename T>
bool TMatrix<T>:: operator == (const TMatrix<T>& m) const //проверка на равенство
{
	return Vector<Vector<T>> :: operator == (m);
}


template <typename T>
bool TMatrix<T>:: operator != (const TMatrix<T>& m) const //проверка на неравенство
{
	return Vector<Vector<T>> :: operator != (m);
}

template <class T>
const TMatrix<T>& TMatrix<T>::operator = (const TMatrix<T>& m) //оператор присваивания
{
	return Vector<Vector<T>>::operator=(m);
}

template <typename T>
TMatrix<T> TMatrix<T>:: operator + (const TMatrix<T>& m) //сложение матриц
{
	return Vector<Vector<T>> :: operator + (m);
}

template <typename T>
TMatrix<T> TMatrix<T>:: operator - (const TMatrix<T>& m) //вычитание матриц
{
	return Vector<Vector<T>> :: operator - (m);
}

template <typename T>
TMatrix<T> TMatrix<T>:: operator * (const TMatrix<T>& m) {
	if (n != m.n) {
		throw "No multi (different size)";
	}
	TMatrix res(n);
	
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
				res[i][j - i] = 0;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			for (int k = i; k <= j; ++k) {
				res[i][j - i] += (*this)[i][k-i] * m[k][j - k];
			}
		}
	}
	

	return res;
}




#endif 
