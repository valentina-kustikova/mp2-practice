#pragma once

#include <iostream>
#include "TVector.h"

using namespace std;

template <typename T>
class TMatrix : public TVector<TVector<T>> {
public:
	TMatrix(int N = 5);
	TMatrix(const TMatrix<T>& matr);
	TMatrix(const TVector<TVector<T>>& vecs);

	const TMatrix<T>& operator = (const TMatrix<T>& matr);

	int operator == (const TMatrix<T>& matr) const;
	int operator != (const TMatrix<T>& matr) const;

	TMatrix<T> operator + (const TMatrix<T>& matr);
	TMatrix<T> operator - (const TMatrix<T>& matr);
	TMatrix<T> operator * (const TMatrix<T>& matr);


	friend istream& operator >> (istream& in, TMatrix<T>& matr) {
		for (int i = 0; i < matr.GetSize(); i++) in >> matr.elems[i];
		return in;
	}
	friend ostream& operator << (ostream& out, const TMatrix<T>& matr) {
		for (int i = 0; i < matr.GetSize(); i++) out << "|" << matr.elems[i] << "|\n";
		return out;
	}
};

template <typename T>
TMatrix<T>::TMatrix(int N) : TVector<TVector<T>>(N) {
	for (int i = 0; i < size; i++) elems[i] = TVector<T>(size - i, i);
}

template <typename T>
TMatrix<T>::TMatrix(const TMatrix<T>& matr) : TVector<TVector<T>>(matr) {}

template <typename T>
TMatrix<T>::TMatrix(const TVector<TVector<T>>& vecs) : TVector<TVector<T>>(vecs) {}

template <typename T>
const TMatrix<T>& TMatrix<T>::operator = (const TMatrix<T>& matr) {
	return TVector<TVector<T>>::operator = (matr);
}

template <typename T>
int TMatrix<T>::operator == (const TMatrix<T>& matr) const {
	return TVector<TVector<T>>::operator == (matr);
}

template <typename T>
int TMatrix<T>::operator != (const TMatrix<T>& matr) const {
	return TVector<TVector<T>>::operator != (matr);
}

template <typename T>
TMatrix<T> TMatrix<T>::operator + (const TMatrix<T>& matr) {
	return TVector<TVector<T>>::operator + (matr);
}

template <typename T>
TMatrix<T> TMatrix<T>::operator - (const TMatrix<T>& matr) {
	return TVector<TVector<T>>::operator - (matr);
}

template <typename T>
TMatrix<T> TMatrix<T>::operator * (const TMatrix<T>& matr) {
	if (matr.size != size) throw "different_sizes";

	TMatrix<T> res(size), tmp(matr);
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) res[i][j] = 0;
	}
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			for (int k = i; k <= j; k++) res[i][j] += (*this)[i][k] * tmp[k][j];
		}
	}
	return res;
}