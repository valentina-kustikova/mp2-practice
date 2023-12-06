#ifndef __TMATRIX_H__
#define __TMATRIX_H__
#include <iostream>
#include "tvector.h"

//const int MAX_MATRIX_SIZE = 100000;

template <class ValType>
class TMatrix : public TVector<TVector<ValType>>
{
public:
    TMatrix<ValType>(int s = 10);
    TMatrix<ValType>(const TMatrix<ValType>& mt);
    TMatrix<ValType>(const TVector<TVector<ValType> >& mt);
    bool operator==(const TMatrix<ValType>& mt) const;
    bool operator!=(const TMatrix<ValType>& mt) const;
    const TMatrix<ValType>& operator=(const TMatrix<ValType>& mt);
    TMatrix<ValType> operator+(const TMatrix<ValType>& mt);
    TMatrix<ValType> operator-(const TMatrix<ValType>& mt);
    TMatrix<ValType> operator*(const TMatrix<ValType>& mt);

    friend istream& operator>>(istream& in, TMatrix<ValType>& mt)
    {
        for (int i = 0; i < mt.Size; i++)
            in >> mt.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TMatrix<ValType>& mt)
    {

        for (int i = 0; i < mt.Size; i++)
            out << mt.pVector[i] << endl;
        return out;
    }

};

template <class ValType>
TMatrix<ValType>::TMatrix<ValType>(int s) : TVector<TVector<ValType>>(s)
{
    for (int i = 0; i < Size; ++i)
    {
        TVector<ValType> x(Size - i, i);
        pVector[i] = x;
        pVector[i] = TVector<ValType>(Size - i, i);
    }
}

template <class ValType>
TMatrix<ValType>::TMatrix<ValType>(const TMatrix<ValType>& mt) :TVector<TVector<ValType>>(mt)
{

}

template <class ValType>
TMatrix<ValType>::TMatrix<ValType>(const TVector<TVector<ValType>>& mt) :TVector<TVector<ValType>>(mt)
{

}


template <class ValType>
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
    return TVector<TVector<ValType>>::operator==(mt);
}

template <class ValType>
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
    return !(*this == mt);
}

template <class ValType>
const TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
    return TVector<TVector<ValType>>::operator=(mt);
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
    return TVector<TVector<ValType>>::operator+(mt);
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
    return TVector<TVector<ValType>>::operator-(mt);
}
template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix<ValType>& mt)
{
    if (Size != mt.Size)
        throw "Sizes should be equal!\n";

    TMatrix<ValType> tmp(mt), res(Size);
    for (int i = 0; i < Size; i++)
    {
        for (int j = i; j < Size; j++)
        {
            for (int k = i; k <= j; k++)
            {
                res[i][j] += (*this)[i][k] * tmp[k][j];
            }
        }

    }
    return res;
}

#endif