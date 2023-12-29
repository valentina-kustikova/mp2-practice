#ifndef _TMATRIX_H
#define _TMATRIX_H

#include "tvector.h"

template <typename T>
class TMatrix : public TVector<TVector<T>> {
public:
	TMatrix(int mn = 10);
	TMatrix(const TMatrix<T>& m);
	TMatrix(const TVector<TVector<T>>& m);

	TVector<T>& operator[](const int index);

	const TMatrix<T>& operator=(const TMatrix<T>& m);

	int operator==(const TMatrix<T>& m) const;
	int operator!=(const TMatrix<T>& m) const;

	TMatrix<T> operator+(const TMatrix<T>& m);
	TMatrix<T> operator-(const TMatrix<T>& m);

	TMatrix<T> operator*(const TMatrix<T>& m);

	friend ostream& operator<<(ostream& out, const TMatrix<T>& m) {
		for (int i = 0; i < m.GetSize(); i++) {
			out << m.pMem[i] << endl;
		}
		return out;
	}
	friend istream& operator>>(istream& in, TMatrix<T>& m) {
		for (int i = 0; i < m.GetSize(); i++) {
			in >> m.pMem[i];
		}
		return in;
	}
};

///////////////////////////////////////////////////////////////////////////

template <typename T>
TMatrix<T>::TMatrix(int mn) : TVector<TVector<T>>(mn) {
	if (mn <= 0) throw "ERROR: matrix size less than 1";
	for (int i = 0; i < mn; i++) {
		pMem[i] = TVector<T>(mn - i, i);
	}
}
template <typename T>
TMatrix<T>::TMatrix(const TMatrix<T>& m) : TVector<TVector<T>>((TVector<TVector<T>>)m) {}
template <typename T>
TMatrix<T>::TMatrix(const TVector<TVector<T>>& m) : TVector<TVector<T>>(m) {}

template <typename T>
TVector<T>& TMatrix<T>::operator[](const int index) {
	return TVector<TVector<T>>::operator[](index);
}

template <typename T>
const TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& m) {
	return TVector<TVector<T>>::operator=(m);
}

template <typename T>
int TMatrix<T>::operator==(const TMatrix<T>& m) const {
	return TVector<TVector<T>>::operator==(m);
}
template <typename T>
int TMatrix<T>::operator!=(const TMatrix<T>& m) const {
	return !(*this == m);
}

template <typename T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& m) {
	return TVector<TVector<T>>::operator+(m);
}
template <typename T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& m) {
	return TVector<TVector<T>>::operator-(m);
}

template <typename T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& m) {
	if (size != m.size) throw "ERROR: Matrix diffirent size";
	if (startIndex != m.startIndex) throw "ERROR: Matrix diffirent startIndex";
	
	TMatrix<T> res(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			res[i][j] = (*this)[i][j] - (*this)[i][j];

	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			for (int k = i; k <= j; k++)
				res[i][j] += (*this)[i][k] * m.pMem[k][j];
	return res;
}

#endif // !_TMATRIX_H

