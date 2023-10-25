#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include "Vector.h"

template <typename ValueType>
class TMatrix : public TVector<TVector<ValueType>> {
	using TVector<TVector<ValueType>>::pVector;
	using TVector<TVector<ValueType>>::size;
	using TVector<TVector<ValueType>>::startIndex;
public:
	TMatrix(int);
	TMatrix(const TMatrix& m);
	TMatrix(const TVector<TVector<ValueType>>& v);

	int operator== (const TMatrix& m) const;
	int operator!= (const TMatrix& m) const;

	const TMatrix& operator= (const TMatrix& m);

	TMatrix operator+ (const TMatrix& m);
	TMatrix operator- (const TMatrix& m);
	TMatrix operator* (const TMatrix& m);

	friend std::istream& operator>> (std::istream& in, TMatrix& m) {
		std::cout << "enter the size of the matrix: ";
		int size;
		in >> size;

		if (size != m.size) {
			m.size = size;
			delete[] m.pVector;
			m.pVector = new TVector<ValueType>[size];
			for (int i = 0; i < size; i++) {
				m.pVector[i] = TVector<ValueType>(size - i, i);
			}
		}

		for (int i = 0; i < m.size; i++) {
			std::cout << "enter matrix line number " << i + 1 << "\n";
			in >> m.pVector[i];
		}

		return in;
	}

	friend std::ostream& operator<< (std::ostream& out, const TMatrix& m) {
		for (int i = 0; i < m.size; i++) {
			for (int z = 0; z < i; z++) {
				std::cout.width(5);
				out << " ";
			}

			for (int j = 0; j < m.pVector[i].GetSize(); j++) {
				std::cout.width(5);
				out << m.pVector[i][j];
			}
			out << "\n";
		}

		return out;
	}
};

template <typename ValueType>
TMatrix<ValueType>::TMatrix(int n) {
	pVector = new TVector<ValueType>[n];
	for (int i = 0; i < n; i++)
		pVector[i] = TVector<ValueType>(n - i, i);
}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TMatrix& m) : TVector<TVector<ValueType>>(m) {}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType>>& v) : TVector<TVector<ValueType>>(v) {}

template <typename ValueType>
int TMatrix<ValueType>::operator== (const TMatrix& m) const {
	return TVector<TVector<ValueType>>::operator==(m);
}

template <typename ValueType>
int TMatrix<ValueType>::operator!= (const TMatrix& m) const {
	return (*this == m);
}

template <typename ValueType>
const TMatrix<ValueType>& TMatrix<ValueType>::operator= (const TMatrix& m) {
	return TVector<TVector<ValueType>>::operator=(m);
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+ (const TMatrix& m) {
	return TVector<TVector<ValueType>>::operator+(m);
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator- (const TMatrix& m) {
	return TVector<TVector<ValueType>>::operator-(m);
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator* (const TMatrix& m) {
	if (size != m.size)
		throw std::exception("diff. sizes");

	TMatrix<ValueType> res(size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			res[i][j] = 0;
			for (int k = 0; k < j + 1 && k < size - i; k++) {
				res.pVector[i][j] += (*this).pVector[i][k] * m.pVector[k][j - m.pVector[k].GetStartIndex()];
			}
		}
	}

	return res;
}

#endif