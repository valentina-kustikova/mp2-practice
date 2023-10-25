#ifndef MATRIX_H_
#define MATRIX_H_

#include "vector.h"

template<typename T> class TMatrix : public TVector <TVector<T>> {
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
	int tmp = 0;
	for (int i = 0; i < m.size; i++) {
		for (int j = 0; j < tmp; j++) {
			out << " 0";
		}
		tmp++;
		out << m.elements[i] << endl;
	}
	return out;
}
template<typename T> istream& operator>>(istream& in, TMatrix<T>& m)
{
	cout << endl;
	for (int i = 0; i < m.size; i++) {
		cout <<i << " line: ";
		in >> m.elements[i];
	}
	return in;
}






template  <typename T> TMatrix<T>::TMatrix(int n) :TVector <TVector<T>>(n) {
	for (int i = 0; i < n; i++) {
		elements[i] = TVector<T>(n - i, i);
	}
}
template  <typename T> TMatrix<T>::TMatrix(const TMatrix& m) : TVector<TVector<T>>(m) {}
template  <typename T> TMatrix<T>::TMatrix(const TVector<TVector<T>>& v) : TVector<TVector<T>>(v) {}

template  <typename T> TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& m) {
	if (size != m.size)
		throw "got different sizes on addition";
	return TVector<TVector<T>>::operator+(m);
}
template  <typename T> TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& m) {
	if (size != m.size)
		throw "got different sizes on subtractoin";
	return TVector<TVector<T>>::operator-(m);
}
template  <typename T> TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& m) {
	if (size != m.size)
		throw "got different sizes on multiplication";
	TMatrix<T> res(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
		{
			T sum = 0;
			for (int g = i; g <= j; g++)
				sum += elements[i][g - i] * m.elements[g][j - g];
			res.elements[i][j - i] = sum;
		}
	return res;
}

template  <typename T> bool TMatrix<T>::operator==(const TMatrix& m) const {
	if (m.size != size)
		return false;
	return TVector<TVector<T>>::operator==(m);
}
template  <typename T> bool TMatrix<T>::operator!=(const TMatrix& m) const {
	return (!(*this == m));
}

template  <typename T> const TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& m)
{
	return  TVector<TVector<T>>::operator=(m);
}
#endif // MATRIX_H_
