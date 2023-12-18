#ifndef __TVECTOR_H__
#define __TVECTOR_H__

#include <iostream>
using namespace std;

template <class ValType>
class TVector
{
protected:
    int StartIndex;
    ValType* pVector;
    int Size;
public:
    TVector<ValType>(int s = 10, int si = 0);
    TVector<ValType>(const TVector& v);
    virtual ~TVector<ValType>();
    int GetSize() const { return Size; }
    int GetStartIndex() const { return StartIndex; }
    ValType& operator[](int pos);
    bool operator==(const TVector<ValType>& v) const;
    bool operator!=(const TVector<ValType>& v) const;
    const TVector<ValType>& operator=(const TVector<ValType>& v);

    // скалярные операции
    TVector<ValType>  operator+(const ValType& val);
    TVector<ValType>  operator-(const ValType& val);
    TVector<ValType>  operator*(const ValType& val);

    // векторные операции
    TVector<ValType>  operator+(const TVector<ValType>& v);
    TVector<ValType>  operator-(const TVector<ValType>& v);
    ValType  operator*(const TVector<ValType>& v);

    // ввод-вывод
    friend istream& operator>>(istream& in, TVector<ValType>& v)
    {
        for (int i = v.StartIndex; i < v.StartIndex + v.Size; i++)
            in >> v[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, TVector<ValType>& v)
    {
        for (int i = 0; i < v.StartIndex; i++)
        {
            out << ValType() << " ";
        }
        for (int i = v.StartIndex; i < v.Size + v.StartIndex; i++) {

            out << v[i] << " ";
        }
        return out;
    }
};

template <class ValType>
TVector<ValType>::TVector<ValType>(int s, int si) :Size(s), StartIndex(si)
{
    if (s <= 0 || s > Size)
        throw "Incorrect size";
    if (si < 0)
        throw "You cannot start at negative index!";
    pVector = new ValType[s]();
}

template <class ValType>
TVector<ValType>::TVector<ValType>(const TVector<ValType>& v)
{
    Size = v.Size;
    StartIndex = v.StartIndex;
    pVector = new ValType[Size];
    std::copy(v.pVector, v.pVector + v.Size, pVector);
}
template <class ValType>
TVector<ValType>::~TVector<ValType>()
{
    delete[] pVector;
}

template <class ValType>
ValType& TVector<ValType>::operator[](int pos)
{
    if (pos < 0 || pos >= 1000)
        throw "Wrong position";
    if (pos < StartIndex)
        throw "Wrong position (less than start index)";

    if (pos - StartIndex < Size)
        return pVector[pos - StartIndex];
    throw "Access Error";
}

template <class ValType>
bool TVector<ValType>::operator==(const TVector& v) const
{
    if ((StartIndex != v.StartIndex) || (Size != v.Size)) return false;

    for (int i = 0; i < Size; ++i)
    {
        if (pVector[i] != v.pVector[i]) {
            return false;
        }
    }
    return true;
}



template <class ValType>
bool TVector<ValType>::operator!=(const TVector<ValType>& v) const
{
    return !(*this == v);
}


template <class ValType>
const TVector<ValType>& TVector<ValType>::operator=(const TVector<ValType>& v)
{
    if (this == &v)
        return *this;

    if (Size != v.Size)
    {
        delete[] pVector;
        pVector = new ValType[v.Size];
    }

    Size = v.Size;
    StartIndex = v.StartIndex;
    for (int i = 0; i < Size; i++)
    {
        pVector[i] = v.pVector[i];
    }
    return *this;
}



template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
    TVector<ValType> A(Size, StartIndex);
    for (int i = 0; i < A.Size; ++i)
    {
        A[i] = pVector[i] + val;
    }
    return A;
}
template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
    TVector<ValType> A(Size, StartIndex);
    for (int i = 0; i < A.Size; ++i)
    {
        A[i] = pVector[i] - val;
    }
    return A;
}


template <class ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
    TVector<ValType> A(Size, StartIndex);
    for (int i = 0; i < A.Size; ++i)
    {
        A[i] = pVector[i] * val;
    }
    return A;
}


template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
    if ((Size != v.Size) || (StartIndex != v.StartIndex))
        throw "Size and StartIndex should be equal";

    TVector<ValType> B(Size, StartIndex), tmp(v);
    for (int i = 0; i < Size; ++i)
    {
        B.pVector[i] = pVector[i] + v.pVector[i];
    }
    return B;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
    if ((Size != v.Size) || (StartIndex != v.StartIndex))
        throw "Size and StartIndex should be equal";

    TVector<ValType> B(Size, StartIndex), tmp(v);
    for (int i = 0; i < Size; ++i)
    {

        B.pVector[i] = pVector[i] - v.pVector[i];
    }
    return B;
}

template <class ValType>
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
    if ((v.Size != Size) || (v.StartIndex != StartIndex))
        throw "dimentions of vectors should be equal for dot product";

    ValType ans = ValType();
    TVector<ValType> tmp(v);
    for (int i = 0; i < Size; ++i)
    {
        ans = ans + pVector[i] * tmp[i];
    }
    return ans;
}


#endif