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

#endif // MATRIX_H_
