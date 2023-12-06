#ifndef  __MATRIX_H__
#define __MATRIX_H__
#include <iostream>
#include "vector.h"
using namespace std;

template <typename ValueType>
class TMatrix : public TVector<TVector<ValueType>>
{
public:
	TMatrix(int size);
	TMatrix(const TMatrix& matrix);
	TMatrix(const TVector<TVector<ValueType> >& matrix);

	int operator==(const TMatrix& matrix) const;
	int operator!=(const TMatrix& matrix) const;
	const TMatrix& operator= (const TMatrix& matrix);

	TMatrix  operator+(const TMatrix& matrix);
	TMatrix  operator-(const TMatrix& matrix);
	TMatrix operator*(const TMatrix& matrix);
	friend istream& operator>>(istream& in, TMatrix& matrix)
	{
		cout << "Input of elements of matrix vectors"<<endl;
		for (int i = 0; i < matrix.size; i++)
			in >> matrix.pVector[i];
		return in;
	}
	friend ostream& operator<<(std::ostream& ostr, const TMatrix<ValueType>& m)
	{
		for (int i = 0; i < m.size; i++)
		{
			for (int j = 0; j < m.pVector[i].getStartIndex(); j++) {
				ostr << "0" << " ";
			}
			ostr << m.pVector[i];
		}
		return ostr;
	}
};

template <typename ValueType>
TMatrix<ValueType>::TMatrix(int size) : TVector<TVector<ValueType>>(size) 
{
	for (int i = 0; i < size; ++i) 
	{
		pVector[i] = TVector<ValueType>(size - i, i);
	}
}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TMatrix& matrix) :
	TVector<TVector<ValueType>>(matrix) { }

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType>>& matrix) : 
	TVector<TVector<ValueType> >(matrix) {}

template <typename ValueType>
int TMatrix<ValueType>::operator==(const TMatrix<ValueType>& matrix) const
{
	return TVector<TVector<ValueType> >::operator==(matrix);
}

template <typename ValueType>
int TMatrix<ValueType>::operator!=(const TMatrix<ValueType>& matrix) const
{
	return TVector<TVector<ValueType> >::operator!=(matrix);
}

template <typename ValueType>
const TMatrix<ValueType>& TMatrix<ValueType>::operator=(
	const TMatrix<ValueType>& matrix)
{
	return TVector<TVector<ValueType> >::operator=(matrix);
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(
	const TMatrix<ValueType>& matrix)
{
	return TVector<TVector<ValueType> >::operator+(matrix);
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(
	const TMatrix<ValueType>& matrix)
{
	return TVector<TVector<ValueType> >::operator-(matrix);
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const TMatrix& m) 
{
	if (size != m.size)
		throw "Error: you cannot multiply sets with different dimensions";
	int size = this->getSize();
	TMatrix<ValueType> result(size);

	for (int k = 0; k < size; k++)
	{
		for (int j = k; j < size; j++)
		{
			ValueType summa = 0;
			for (int r = k; r <= j; r++)
			{
				summa += (this->pVector[k][r - k] * m.pVector[r][j - r]);
			}
			result.pVector[k][j - k] = summa;
		}
	}
	return result;
}

#endif