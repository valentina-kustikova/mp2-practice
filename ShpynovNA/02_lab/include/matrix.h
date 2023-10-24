#ifndef MATRIX_H_
#define MATRIX_H_

#include "vector.h"

template<typename T> class TMatrix : public TVector<TVector<T>> {
public:
	TMatrix(int n);
	TMatrix(const TMatrix& m);
	TMatrix(const TVector<TVector<T>>& v);

	const TMatrix& operator=(const TMatrix& m);

	bool operator ==(const TMatrix& m) const;
	bool operator !=(const TMatrix& m) const;

	TMatrix operator+(const TMatrix& m);
	TMatrix operator-(const TMatrix& m);
	TMatrix operator*(const TMatrix& m);

	template<typename T> friend ostream& operator<<(ostream& out, const TMatrix<T>& m);
	template<typename T> friend istream& operator>>(istream& in, TMatrix<T>& m);
};

template<typename T> ostream& operator<<(ostream& out, const TMatrix<T>& m)
{
	for (int i = 0; i < m.size; i++) {
		for (int j = 0; j < m.elements[i].getindex(); j++) {
			out << "0 ";
		}
		out << m.elements[i] << endl;
	}
	return out;
}
template<typename T> istream& operator>>(istream& in, TMatrix<T>& m)
{
	cout << "size:";
	in >> m.size;
	for (int i = 0; i < size; i++) {
		cout << i << " line: \n";
		in >> m.elements[i];
	}
	return in;
}

template  <typename T> TMatrix<T>::TMatrix(int n) :TVector<TVector<T>>(n) {
	for (i = 0; i < n; i++) {
		elements[i] = TVector<T>(n - i, i);
	}
}
template  <typename T> TMatrix<T>::TMatrix(const TMatrix<T>& m) : TVector<TVactor<T>>(m.elements) {}
template  <typename T> TMatrix<T>::TMatrix(const TVector<TVector<T>>& v) : TVector<TVactor<T>>(m.elements) {}

template  <typename T> TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& m) {
	if (size != m.size)
		throw "got different sizes";
	return TVector<TVector<T>>::operator+(m);
}
template  <typename T> TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& m) {
	if (size != m.size)
		throw "got different sizes";
	return TVector<TVector<T>>::operator-(m);
}
template  <typename T> TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& m) {
	if (size != m.size)
		throw "got different sizes";
	TMatrix<T> res(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
		{
			for (int g = i; g <= j; g++)
				res.elements[i][j - i] = res.elements[i][j - i] + elements[i][g - i] * m.elements[g][j - g];
		}
	return res;
}

template  <typename T> bool TMatrix<T>::operator==(const TMatrix& m) const {
	if (m.size != size)
		return false;
	return TVector<TVector<T>>::operator==(m);
}
template  <typename T> bool TMatrix<T>::operator==(const TMatrix& m) const {
	return (!(*this == m));
}

template  <typename T> const TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& m)
{
	return  TVector<TVector<T>>::operator=(m);
}
#endif // MATRIX_H_
