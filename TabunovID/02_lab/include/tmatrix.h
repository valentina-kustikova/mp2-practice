#ifndef TMATRIX_H
#define TMATRIX_H

#include "TVector.h"

using namespace std;

template <typename T>
class TMatrix : public TVector<TVector<T>>
{
public:
	TMatrix(int mn = 10);
	TMatrix(const TMatrix<T>& m);
	TMatrix(const TVector<TVector<T>>& m);

	TVector<T>& operator[](const int index);

	const TMatrix<T> operator=(const TMatrix<T>& m);
	int operator==(const TMatrix<T>& m) const;
	int operator!=(const TMatrix<T>& m) const;

	TMatrix operator +(const TMatrix<T>& m);
	TMatrix operator -(const TMatrix<T>& m);
	TMatrix operator *(const TMatrix<T>& m);

	friend istream& operator >>(istream& in, TMatrix<T>& m)
	{
		for (int i = 0; i < m.GetSize(); i++)
			in >> m.vec[i];

		return in;
	};
	friend ostream& operator <<(ostream& out, TMatrix<T>& m)
	{
		for (int i = 0; i < m.GetSize(); i++)
			out << m.vec[i] << endl;

		return out;
	};
};

template <typename T>
TMatrix<T> :: TMatrix(int mn) : TVector<TVector<T>> (mn)
{
	if (mn <= 0)
		throw "ERROR: matrix size less than 1";
	for (int i = 0; i < mn; i++) 
		(*this)[i] = TVector<T>(mn - i, i);
}

template <typename T>
TMatrix<T>::TMatrix(const TMatrix<T>& m) : TVector<TVector<T>>(m) {};

template <typename T>
TMatrix<T>::TMatrix(const TVector<TVector<T>>& m) : TVector<TVector<T>>(m) {};

template <typename T>
TVector<T>& TMatrix<T>::operator[](const int index) {
	return TVector<TVector<T>>::operator[](index);
}

template <typename T>
const TMatrix<T> TMatrix<T>::operator=(const TMatrix<T>& m)
{
	return TVector<TVector<T>>::operator=(m);
};

template <typename T>
int TMatrix<T>::operator==(const TMatrix<T>& m) const
{
	return TVector<TVector<T>>::operator==(m);
};

template <typename T>
int TMatrix<T>::operator!=(const TMatrix<T>& m) const
{
	return !(*this == m);
};

template <typename T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& m)
{
	return TVector<TVector<T>>::operator+(m);
};

template <typename T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& m)
{
	return TVector<TVector<T>>::operator-(m);
};

template <typename T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& m)
{
	if (GetSize() != m.GetSize() || GetStart() != m.GetStart())
		throw "ERROR: matrix sizes do not match";

	TMatrix<T> result(GetSize());
	for (int i = 0; i < GetSize(); i++)
		for (int j = result[i].GetStart(); j < GetSize(); j++)
			result[i][j] = T(NULL);

	for (int i = 0; i < GetSize(); i++)
	{
		for (int j = result[i].GetStart(); j < GetSize(); j++)
		{
			T sum = 0;
			for (int k = result[i].GetStart(); k <= j; k++) {
				sum += (*this)[i][k] * m.vec[k][j];
 			}
			result.vec[i][j] = sum;
		}
	}
	return result;
};
#endif // !TMATRIX_H

