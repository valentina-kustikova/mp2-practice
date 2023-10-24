#ifndef __TMATRIX_H__
#define __TMATRIX_H__
#include <iostream>
#include "tvector.h"

const int MAX_MATRIX_SIZE = 10000;

//Наследуем матрицу от конкретного экземпляра TVector<T1>, где T1 = TVector<T>, причём поля в родительском классе.
template <class T>
class TMatrix : public TVector<TVector<T>>
{
public:
  TMatrix<T>(int s = 10);                           
  TMatrix<T>(const TMatrix<T> &mt);                    
  TMatrix<T>(const TVector<TVector<T> > &mt);
  bool operator==(const TMatrix<T>&mt) const;
  bool operator!=(const TMatrix<T>&mt) const;
  const TMatrix<T>& operator=(const TMatrix<T> &mt);
  TMatrix<T> operator+(const TMatrix<T> &mt);
  TMatrix<T> operator-(const TMatrix<T> &mt);
  TMatrix<T> operator*(const TMatrix<T> &mt);
  
  //Эти операции изменят вид матрицы, что не логично для задачи.
  //TMatrix& operator=(const T& v);
  //TMatrix  operator+(const T& v);
  //TMatrix  operator-(const T &v);
  
  
  // ввод / вывод
  friend istream& operator>>(istream &in, TMatrix<T>&mt)
  {
    for (int i = 0; i < mt.size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix<T>&mt)
  {
    for (int i = 0; i < mt.size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }

};

template <class T>
TMatrix<T>::TMatrix<T>(int s): TVector<TVector<T>>(s)
{
    if(s > MAX_MATRIX_SIZE)
        throw "Too Large Matrix";
    if (s <= 0)
        throw "Too Small Matrix";
    for (int i = 0; i < size; ++i)
    {
        TVector<T> x(size - i, i);
        pVector[i] = x;
    }
} 

template <class T> 
TMatrix<T>::TMatrix<T>(const TMatrix<T> &mt):TVector<TVector<T>>(mt) 
{
  
}

template <class T> 
TMatrix<T>::TMatrix<T>(const TVector<TVector<T>> &mt):TVector<TVector<T>>(mt) 
{
    if (size > MAX_MATRIX_SIZE)
    {
        throw "Allocation Error";
    }
    if (size < 0)
    {
        throw "size should be positive";
    }
}


template <class T> 
bool TMatrix<T>::operator==(const TMatrix<T> &mt) const
{
    return TVector<TVector<T>>::operator==(mt);
}

template <class T> 
bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
{
    return !(*this == mt);
} 

template <class T> 
const TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
{

    return TVector<TVector<T>>::operator=(mt);
} 

template <class T> 
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
    
    return TVector<TVector<T>>::operator+(mt);
} 

template <class T> 
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
    return TVector<TVector<T>>::operator-(mt);
} 
template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& mt)
{
    if (size != mt.size)
        throw "sizes should be equal!\n";

    TMatrix<T> tmp(mt), res(size);
	for (int i = 0; i < size; i++)
	{
        for (int j = i; j < size; j++)
        {
            for (int k = i; k <= j; k++)
            {
                res[i][j] += (*this)[i][k] * tmp[k][j];
            }
        }
		
	}
    return res;
}

#endif
