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
	TMatrix(const TMatrix& mx);
	TMatrix(const TVector<TVector<ValueType> >& mx);

	int operator==(const TMatrix& mx) const;
	int operator!=(const TMatrix& mx) const;
	const TMatrix& operator= (const TMatrix& mx);
	TMatrix  operator+(const TMatrix& mx);
	TMatrix  operator-(const TMatrix& mx);
	TMatrix operator*(const TMatrix& mx);
	friend istream& operator>>(istream& in, TMatrix& mx)
	{
		cout << "Enter elements of vectors" << endl;
		
		for (int i = 0; i < mx.size; i++)
			in >> mx.pVector[i];
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

template <typename ValueType>TMatrix<ValueType>::
TMatrix(int size) : TVector<TVector<ValueType>>(size) {
	for (int i = 0; i < size; ++i) {
		pVector[i] = TVector<ValueType>(size - i, i);
	}
}

template <typename ValueType>TMatrix<ValueType>::
TMatrix(const TMatrix& mt) : TVector<TVector<ValueType>>(mt)
{ 

}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType>>& mx) : TVector<TVector<ValueType> >(mx) 
{

}

template <typename ValueType>
int TMatrix<ValueType>::operator==(const TMatrix<ValueType>& mx) const
{
	return TVector<TVector<ValueType> >::operator==(mx);
}

template <typename ValueType>
int TMatrix<ValueType>::operator!=(const TMatrix<ValueType>& mx) const
{
	return TVector<TVector<ValueType> >::operator!=(mx);
}

template <typename ValueType>
const TMatrix<ValueType>& TMatrix<ValueType>::operator=(const TMatrix<ValueType>& mx)
{
	return TVector<TVector<ValueType> >::operator=(mx);
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const TMatrix<ValueType>& mx)
{
	if (size != mx.size) {
		throw ("Error: Matrices have different rank ");
	}
	TMatrix obj(*this);
	for (int i = 0; i < size; ++i) {
		obj.pVector[i] = obj.pVector[i] + mt.pVector[i];
	}
	return obj;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const TMatrix<ValueType>& mx)
{
	if (size != mx.size) {
		throw ("Error: Matrices have different rank ");
	}
	TMatrix obj(*this);
	for (int i = 0; i < size; ++i) {
		obj.pVector[i] = obj.pVector[i] - mt.pVector[i];
	}
	return obj;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const TMatrix& m) {
	if (size != m.size)
		throw "Error: For multiplication, the matrices must have the same size";
	int size = this->getSize();
	TMatrix<ValueType> matrix_result(size);

	for (int k = 0; k < size; k++) {
		for (int j = k; j < size; j++) {
			ValueType sum = 0;
			for (int r = k; r <= j; r++) {
				sum += this->pVector[k][r - k] * m.pVector[r][j - r];
			}
			matrix_result.pVector[k][j - k] = sum;
		}
	}
	return matrix_result;
}

#endif //__MATRIX_H__