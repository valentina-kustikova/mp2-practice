#ifndef __TMATRIX_H__
#define __TMATRIX_H__
#include <iostream>
#include "tvector.h"

const int MAX_MATRIX_SIZE = 10000;

//Наследуем матрицу от конкретного экземпляра TVector<ValType1>, где ValType1 = TVector<ValType>, причём поля в родительском классе.
template <class ValType>
class TMatrix : public TVector<TVector<ValType>>
{
public:
  TMatrix(int s = 10);                           
  TMatrix(const TMatrix &mt);                    
  TMatrix(const TVector<TVector<ValType> > &mt);
  bool operator==(const TMatrix<ValType>&mt) const;
  bool operator!=(const TMatrix<ValType>&mt) const;
  const TMatrix& operator=(const TMatrix<ValType> &mt);
  TMatrix  operator+(const TMatrix<ValType> &mt);
  TMatrix  operator-(const TMatrix<ValType> &mt);
  TMatrix  operator*(const TMatrix<ValType> &mt);
  
  //Эти операции изменят вид матрицы, что не логично для задачи.
  //TMatrix& operator=(const ValType& v);
  //TMatrix  operator+(const ValType& v);
  //TMatrix  operator-(const ValType &v);
  
  
  // ввод / вывод
  friend istream& operator>>(istream &in, TMatrix<ValType>&mt)
  {
    for (int i = 0; i < mt.Size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix<ValType>&mt)
  {
    for (int i = 0; i < mt.Size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }

};

template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType>>(s)
{
    if(s> MAX_MATRIX_SIZE)
        throw "Too Large Matrix";
    for (int i = 0; i < Size; ++i)
    {
        TVector<ValType> x(Size - i, i);
        pVector[i] = x;
    }
} 

template <class ValType> 
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):TVector<TVector<ValType>>(mt) 
{
    for (int i = 0; i < Size; ++i)
    {
        pVector[i] = mt.pVector[i];
    }
}

template <class ValType> 
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType>> &mt):TVector<TVector<ValType>>(mt) 
{
    if (mt.Size > MAX_MATRIX_SIZE)
    {
        throw "Allocation Error";
    }
}


template <class ValType> 
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
    for (int i = 0; i < Size; ++i)
    {
        if (pVector[i] != mt.pVector[i])
            return 0;
    }
    return 1;
}

template <class ValType> 
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
    return !(*this == mt);
} 

template <class ValType> 
const TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
    if (*this == mt)
        return *this;

    if (Size != mt.Size)
    {
        TVector<ValType>* Tmp  = new TVector<ValType>[mt.Size];
        delete[] pVector;
        pVector = Tmp;
    }

    Size = mt.Size;
    std::copy(mt.pVector, mt.pVector + mt.Size, pVector);
    return *this;
} 

template <class ValType> 
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
    
    TMatrix<ValType> A(std::max(Size, mt.Size)), not_const_mt(mt);
    for (int i = 0; i < max(Size, mt.Size); ++i)
    {
        TVector<ValType> tmp;
        if (i >= not_const_mt.Size)
            tmp = (*this)[i];
        else if (i >= Size)
            tmp = not_const_mt[i];
        else
            tmp = (*this)[i] + not_const_mt[i];
        A[i] = tmp;
    }
    return A;
} 

template <class ValType> 
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
    TMatrix<ValType> A(std::max(Size, mt.Size)), not_const_mt(mt);
    for (int i = 0; i < max(Size, mt.Size); ++i)
    {
        TVector<ValType> tmp;
        if (i >= not_const_mt.Size)
            tmp = (*this)[i];
        else if (i >= Size)
            tmp =   not_const_mt[i]*(-1);
        else
            tmp = (*this)[i] - not_const_mt[i];
        A[i] = tmp;
    }
    return A;
} 
template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix<ValType>& mt)
{
    if (Size != mt.Size)
        throw "Sizes should be equal!\n";

    TMatrix<ValType> tmp(mt), res(Size);
	for (int i = 0; i < Size; i++)
	{
        for (int j = i; j < Size; j++)
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
