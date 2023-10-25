#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "tvector.h"

#include <iostream>

using namespace std;

template <typename ValueType>
class TMatrix : public TVector<TVector<ValueType>> {
public:
	TMatrix(int size);
	TMatrix(const TMatrix& m);
	TMatrix(const TVector<TVector<ValueType>>& v);
	int operator==(const TMatrix& m) const;
	int operator!=(const TMatrix& m) const;
	const TMatrix& operator=(const TMatrix& m);
	TMatrix operator+(const TMatrix& m);
	TMatrix operator-(const TMatrix& m);
	TMatrix operator*(const TMatrix& m);
	friend istream& operator>>(istream& in, TMatrix& m){
		cout << "Enter elements of matrix vectors" << endl;
		for (int i = 0; i < m.size; i++)
			in >> m.pVector[i];
		return in;
	}
	friend ostream& operator<<(std::ostream& out, const TMatrix& m){
		for (int i = 0; i < m.size; i++)
		{
			for (int j = 0; j < m.pVector[i].GetStartIndex(); j++) {
				out << "0" << " ";
			}
			out << m.pVector[i];
		}
		return out;
	}
};

template <typename ValueType>
TMatrix<ValueType>::TMatrix<ValueType>(int size): TVector<TVector<ValueType>>(size){
	for (int i = 0; i < size; ++i) {
		pVector[i] = TVector<ValueType>(size - i, i);
	}
}

template <typename ValueType>
TMatrix<ValueType>::TMatrix<ValueType>(const TMatrix& m): TVector<TVector<ValueType>>(m.pVector){}

template <typename ValueType>
TMatrix<ValueType>::TMatrix<ValueType>(const TVector<TVector<ValueType>>& v): TVector<TVector<ValueType>>(v.pVector) {}

template <typename ValueType>
int TMatrix<ValueType>::operator==(const TMatrix<ValueType>& m) const{
	return TVector<TVector<ValueType> >::operator==(m);
}

template <typename ValueType>
int TMatrix<ValueType>::operator!=(const TMatrix<ValueType>& m) const{
	return TVector<TVector<ValueType> >::operator!=(m);
}

template <typename ValueType>
const TMatrix<ValueType>& TMatrix<ValueType>::operator=(const TMatrix<ValueType>& m){
	return TVector<TVector<ValueType> >::operator=(m);
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const TMatrix<ValueType>& m)
{
	if (size != m.size) {
		throw exception("Different sizes");
	}
	TMatrix tmp(*this);
	for (int i = 0; i < size; i++) {
		tmp.pVector[i] = tmp.pVector[i] + m.pVector[i];
	}
	return tmp;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const TMatrix<ValueType>& m)
{
	if (size != m.size) {
		throw exception("Different sizes");
	}
	TMatrix tmp(*this);
	for (int i = 0; i < size; i++) {
		tmp.pVector[i] = tmp.pVector[i] - m.pVector[i];
	}
	return tmp;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const TMatrix& m) {
	if (size != m.size)
		throw exception("Different sizes");
	int size = GetSize();
	TMatrix<ValueType> tmp(size);
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			ValueType sum = 0;
			for (int k = i; k <= j; k++) {
				sum += this->pVector[i][k - i] * m.pVector[k][j - k];
			}
			tmp.pVector[i][j - i] = sum;
		}
	}
	return tmp;
}

#endif
