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
	TMatrix(int n = 5);
	TMatrix(const TMatrix<ValueType>& m);
	TMatrix(const TVector<TVector<ValueType>>& v);

	int operator== (const TMatrix<ValueType>& m) const;
	int operator!= (const TMatrix<ValueType>& m) const;

	const TMatrix& operator= (const TMatrix<ValueType>& m);

	TMatrix operator+ (const TMatrix<ValueType>& m);
	TMatrix operator- (const TMatrix<ValueType>& m);
	TMatrix operator* (const TMatrix<ValueType>& m);

	friend std::istream& operator>> (std::istream& in, TMatrix<ValueType>& m) {
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

	friend std::ostream& operator<< (std::ostream& out, const TMatrix<ValueType>& m) {
		for (int i = 0; i < m.size; i++) {
			for (int z = 0; z < i; z++) {
				std::cout.width(5);
				out << "0 ";
			}

			for (int j = 0; j < m.pVector[i].GetSize(); j++) {
				std::cout.width(5);
				out << m.pVector[i][j] << " ";
			}
			out << "\n";
		}

		return out;
	}
};

template <typename ValueType>
TMatrix<ValueType>::TMatrix(int n) : TVector<TVector<ValueType>>(n) {
	for (int i = 0; i < n; i++)
		pVector[i] = TVector<ValueType>(n - i, i);
}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TMatrix<ValueType>& m) : TVector<TVector<ValueType>>(m) {}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType>>& v) : TVector<TVector<ValueType>>(v) {}

template <typename ValueType>
int TMatrix<ValueType>::operator== (const TMatrix<ValueType>& m) const {
	return TVector<TVector<ValueType>>::operator==(m);
}

template <typename ValueType>
int TMatrix<ValueType>::operator!= (const TMatrix<ValueType>& m) const {
	return !(*this == m);
}

template <typename ValueType>
const TMatrix<ValueType>& TMatrix<ValueType>::operator= (const TMatrix<ValueType>& m) {
	return TVector<TVector<ValueType>>::operator=(m);
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+ (const TMatrix<ValueType>& m) {
	return TVector<TVector<ValueType>>::operator+(m);
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator- (const TMatrix<ValueType>& m) {
	return TVector<TVector<ValueType>>::operator-(m);
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator* (const TMatrix<ValueType>& m) {
	if (size != m.size)
		throw std::exception("diff. sizes");

	TMatrix<ValueType> res(size);

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			res[i][j - res.pVector[i].GetStartIndex()] = 0;
			for (int k = i; k <= j; k++) {
				res.pVector[i][j - res.pVector[i].GetStartIndex()] += this->pVector[i][k - this->pVector[i].GetStartIndex()] * m.pVector[k][j - m.pVector[k].GetStartIndex()];
			}
		}
	}

	return res;
}

#endif