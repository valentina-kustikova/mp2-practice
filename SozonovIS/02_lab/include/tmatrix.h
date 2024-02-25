#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "tvector.h"

#include <iostream>

using namespace std;

template <typename ValueType>
class TMatrix : public TVector<TVector<ValueType>> {
public:
	TMatrix(int size = 5);
	TMatrix(const TMatrix<ValueType>& m);
	TMatrix(const TVector<TVector<ValueType>>& v);
	int operator==(const TMatrix<ValueType>& m) const;
	int operator!=(const TMatrix<ValueType>& m) const;
	const TMatrix& operator=(const TMatrix<ValueType>& m);
	TMatrix operator+(const TMatrix<ValueType>& m);
	TMatrix operator-(const TMatrix<ValueType>& m);
	TMatrix operator*(const TMatrix<ValueType>& m);
	friend istream& operator>>(istream& in, TMatrix<ValueType>& m) {
		for (int i = 0; i < m.size; i++)
			in >> m.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TMatrix<ValueType>& m) {
		for (int i = 0; i < m.size; i++)
		{
			for (int j = 0; j < m.pVector[i].GetStartIndex(); j++) {
				out << "0" << " ";
			}
			out << m.pVector[i] << endl;
		}
		return out;
	}
};

template <typename ValueType>
TMatrix<ValueType>::TMatrix(int size) : TVector<TVector<ValueType>>(size) {
	for (int i = 0; i < size; ++i) {
		pVector[i] = TVector<ValueType>(size - i, i);
	}
}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TMatrix<ValueType>& m) : TVector<TVector<ValueType>>(m) {}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType>>& v) : TVector<TVector<ValueType>>(v) {}

template <typename ValueType>
int TMatrix<ValueType>::operator==(const TMatrix<ValueType>& m) const {
	return TVector<TVector<ValueType> >::operator==(m);
}

template <typename ValueType>
int TMatrix<ValueType>::operator!=(const TMatrix<ValueType>& m) const {
	return TVector<TVector<ValueType> >::operator!=(m);
}

template <typename ValueType>
const TMatrix<ValueType>& TMatrix<ValueType>::operator=(const TMatrix<ValueType>& m) {
	return TVector<TVector<ValueType> >::operator=(m);
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const TMatrix<ValueType>& m)
{
	if (size != m.size) {
		throw exception("different sizes");
	}
	TMatrix tmp(*this);
	for (int i = 0; i < size; i++)
		tmp.pVector[i] = tmp.pVector[i] + m.pVector[i];
	return tmp;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const TMatrix<ValueType>& m)
{
	if (size != m.size) {
		throw exception("different sizes");
	}
	TMatrix tmp(*this);
	for (int i = 0; i < size; i++)
		tmp.pVector[i] = tmp.pVector[i] - m.pVector[i];
	return tmp;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const TMatrix<ValueType>& m) {
	if (size != m.size)
		throw exception("different sizes");
	TMatrix<ValueType> tmp(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			tmp[i][j - tmp.pVector[i].GetStartIndex()] = 0;
			for (int k = i; k <= j; k++)
				tmp.pVector[i][j - tmp.pVector[i].GetStartIndex()] += this->pVector[i][k - this->pVector[i].GetStartIndex()] * m.pVector[k][j - m.pVector[k].GetStartIndex()];
		}
	return tmp;
}

#endif
