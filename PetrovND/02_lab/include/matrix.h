#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include "vector.h"

using namespace std;

template <typename ValueType>
class Matrix : public Vector<Vector<ValueType>> {
public:
	Matrix(int size);
	Matrix(const Matrix& m);
	Matrix(const Vector<Vector<ValueType>>& m);
	int operator==(const Matrix& m) const;
	int operator!=(const Matrix& m) const;
	const Matrix& operator=(const Matrix& m);
	Matrix<ValueType> operator+(const Matrix& m);
	Matrix<ValueType> operator-(const Matrix& m);
	Matrix<ValueType> operator*(const Matrix& m);

	friend istream& operator>>(istream& in, Matrix<ValueType>& m) {
		int size = m.getSize();
		for (int i = 0; i < size; ++i) {
			int rowSize = size - i;
			for (int j = 0; j < rowSize; ++j) {
				in >> m[i][j];
			}
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, Matrix<ValueType>& m) {
		int size = m.getSize();
		for (int i = 0; i < size; ++i) {
			int rowSize = size - i;
			for (int j = 0; j < i; ++j) {
				out << "0 ";
			}
			for (int j = 0; j < rowSize; ++j) {
				out << m[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}
};

template <typename ValueType>
Matrix<ValueType>::Matrix(int size) : Vector<Vector<ValueType>>(size) {
	for (int i = 0; i < size; ++i) {
		Vector<ValueType> row(size - i, i);
		this->pVector[i] = row;
	}
}

template <typename ValueType>
Matrix<ValueType>::Matrix(const Matrix& m) : Vector<Vector<ValueType>>(m) { }

template <typename ValueType>
Matrix<ValueType>::Matrix(const Vector<Vector<ValueType>>& m) : Vector<Vector<ValueType>>(m) { }

template <typename ValueType>
int Matrix<ValueType>::operator==(const Matrix& m) const {
	return Vector<Vector<ValueType>>::operator==(m);
}

template <typename ValueType>
int Matrix<ValueType>::operator!=(const Matrix& m) const {
	return Vector<Vector<ValueType>>::operator!=(m);
}

template <typename ValueType>
const Matrix<ValueType>& Matrix<ValueType>::operator=(const Matrix& m) {
	Vector<Vector<ValueType>>::operator=(m);
	return *this;
}

template <typename ValueType>
Matrix <ValueType> Matrix<ValueType>::operator+(const Matrix& m) {
	return Vector<Vector<ValueType> >::operator+(m);
}

template <typename ValueType>
Matrix <ValueType> Matrix<ValueType>::operator-(const Matrix& m) {
	return Vector<Vector<ValueType> >::operator-(m);
}

template <typename ValueType>
Matrix<ValueType> Matrix<ValueType>::operator*(const Matrix& m) {
	if (this->size != m.size) throw invalid_argument("Matrices must have the same size for matrix multiplication.");

	int size = this->getSize();
	Matrix<ValueType> result(size);

	for (int k = 0; k < size; k++) {
		for (int j = k; j < size; j++) {
			ValueType sum = 0;
			for (int r = k; r <= j; r++) {
				sum += this->pVector[k][r - k] * m.pVector[r][j - r];
			}
			result.pVector[k][j - k] = sum;
		}
	}
	return result;
}

#endif // !__MATRIX_H__