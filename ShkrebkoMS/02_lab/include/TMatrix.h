#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include "TVector.h"

template <typename ValueType> 
class TMatrix : public TVector<TVector<ValueType>>
{

public:
	TMatrix(int n = 10);
	TMatrix(const TMatrix& m);
	TMatrix(const TVector <TVector<ValueType>>& m);


	const TMatrix& operator=(const TMatrix& m);
	int operator==(const TMatrix& m) const;
	int operator!=(const TMatrix& m) const;

	TMatrix operator+(const TMatrix& m); 
	TMatrix operator-(const TMatrix& m); 
	TMatrix operator*(const TMatrix& m); 


	friend istream& operator>>(istream& istr, TMatrix<ValueType>& m)
	{

		istr >> m.Size;
		std::cout << "\nEnter the " << m.Size << " elements: ";
		for (int i = 0; i < m.Size; i++)
			istr >> m.pVector[i];
		return istr;
	}
	friend ostream& operator<<(ostream& ostr, TMatrix<ValueType>& m)
	{
		for (int i = 0; i < m.Size; i++)
		{
			for (int j = 0; j < m.pVector[i].GetStartIndex(); j++)
				ostr << "0" << " ";
			ostr << m.pVector[i] << std::endl;

		}
		return ostr;
	}

};

template <typename ValueType>
TMatrix<ValueType>::TMatrix(int n) : TVector<TVector<ValueType>>(n)
{
	for (int i = 0; i < n; i++)
	{
		TVector<TVector<ValueType>>::pVector[i] = TVector<ValueType>(n - i, i);
	}
}

template<typename ValueType>
TMatrix<ValueType>::TMatrix(const TMatrix& m) : TVector<TVector<ValueType>>(m) { };

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType>>& m) :TVector<TVector<ValueType>>(m) { };


template<typename ValueType>
const TMatrix<ValueType>& TMatrix<ValueType>::operator=(const TMatrix<ValueType>& m)
{
	return  TVector<TVector<ValueType>>::operator=(m);
}

template <typename ValueType>
int TMatrix<ValueType>::operator==(const TMatrix& m) const
{
	return TVector<TVector<ValueType> >::operator==(m);
}

template <typename ValueType>
int TMatrix<ValueType>::operator!=(const TMatrix& m) const
{
	return TVector<TVector<ValueType> >::operator!=(m);
}


template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const TMatrix& m)
{
	return TVector<TVector<ValueType>>::operator+(m);
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const TMatrix& m)
{
	return TVector<TVector<ValueType> > :: operator-(m);
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const TMatrix& m)
{
	if (this->Size != m.Size)
		throw "diff size\n";

	TMatrix<ValueType> tmp(this->Size);
	for (int i = 0; i < this->Size; i++)
	{
		for (int j = i; j < this->Size; j++)
		{
			for (int k = i; k <= j; k++)
			{
				tmp[i][j - i] += this->pVector[i][k - i] * m.pVector[k][j - k];
			}
		}

	}
	return tmp;
}

#endif