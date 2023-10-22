
#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include "tvector.h"

template <typename T> class TMatrix : public TVector <TVector<T>>
{
public:
	TMatrix(int mn = 10);
	TMatrix(const TMatrix& m);
	TMatrix(const TVector <TVector<T>>& m);

	//operations 
	const TMatrix operator=(const TMatrix& m);
	int operator==(const TMatrix& m) const;
	int operator!=(const TMatrix& m) const;

	TMatrix operator+(const TMatrix& m); // A + B
	TMatrix operator-(const TMatrix& m); // A - B
	TMatrix operator*(const TMatrix& m); // A * B

	template<typename T> friend std::ostream& operator<<(std::ostream& ostr, const TMatrix<T>& v);
	template<typename T> friend std::istream& operator>>(std::istream& istr, TMatrix<T>& v);

};
//constructors
template <typename T>
TMatrix<T>::TMatrix<T>(int mn) :TVector<TVector<T>>(mn)
{
	for (int i = 0; i < mn; i++)
	{
		pVec[i] = TVector<T>(mn - i, i);
	}
}

template<typename T>
TMatrix<T>::TMatrix<T>(const TMatrix& m):TVector<TVector<T>>(m) { };

template <typename T>
TMatrix<T>::TMatrix<T>(const TVector<TVector<T>>& m) :TVector<TVector<T>>(m) { };

//oprations
// =
template<typename T>
const TMatrix<T> TMatrix<T>::operator=(const TMatrix<T>& m)
{
	return  TVector<TVector<T>>::operator=(m);
}
// ==
template <typename T> 
int TMatrix<T>::operator==(const TMatrix& m) const
{
	return TVector<TVector<T> >::operator==(m);
}
// !=
template <typename T>
int TMatrix<T>::operator!=(const TMatrix& m) const
{
	return TVector<TVector<T> >::operator!=(m);
}

// A + B
template<typename T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix& m)
{
	if (size != m.size)
		throw "Can't accumulate matrix with different dimensions!";
	else
		return TVector<TVector<T> > :: operator+(m);
}

// A - B 
template<typename T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix& m)
{
	if (size != m.size)
		throw "Can't subtract matrix with different dimensions!";
	else
		return TVector<TVector<T> > :: operator-(m);
}

// A * B
template<typename T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix& m)
{
	if (size != m.size)
		throw "Can't multiply matrix with different dimensions!";
	else
	size;
	TMatrix <T> res(size);
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
		{
			for (int k = i; k <= j; k++)
				res.pVec[i][j - i] += this->pVec[i][k - i] * m.pVec[k][j - k];
		}
	return res;
}

// in
template <typename T>  
std::istream& operator>>(std::istream& istr, TMatrix<T>& m)
{
	istr >> m.size;
	std::cout << "\nEnter the " << m.size << " elements: ";
	for (int i = 0; i < m.size; i++)
		istr >> m.pVec[i];
	return istr;
}

// out
template <typename T>
std::ostream& operator<<(std::ostream& ostr, const TMatrix<T>& m)
{
	for (int i = 0; i < m.size; i++)
	{
		for (int j = 0; j < i; j++)
			ostr << "0" << '\t';
		ostr << m.pVec[i] << std::endl;

	}
	return ostr;

}
#endif
