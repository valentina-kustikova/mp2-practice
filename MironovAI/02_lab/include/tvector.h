#ifndef __TVECTOR_H__
#define __TVECTOR_H__

#include <iostream>
using namespace std;

const int MAX_VECTOR_SIZE = 100000000;


// Шаблон вектора
template <class ValType>
class TVector
{
protected:
    int StartIndex;
    ValType *pVector;
    int Size;        
public:
    TVector<ValType>(int s = 10, int si = 0);
    TVector<ValType>(const TVector& v);
    virtual ~TVector<ValType>();
    int GetSize()       { return Size;       } 
    int GetStartIndex() { return StartIndex; } 
    ValType& operator[](int pos);             
    bool operator==(const TVector<ValType> &v) const;  
    bool operator!=(const TVector<ValType> &v) const;  
    const TVector<ValType>& operator=(const TVector<ValType> &v);

    // скалярные операции
    TVector<ValType>  operator+(const ValType &val);
    TVector<ValType>  operator-(const ValType &val);
    TVector<ValType>  operator*(const ValType &val);

    // векторные операции
    TVector<ValType>  operator+(const TVector<ValType> &v);
    TVector<ValType>  operator-(const TVector<ValType>&v);
    ValType  operator*(const TVector<ValType> &v);

    // ввод-вывод
    friend istream& operator>>(istream &in, TVector<ValType> &v)
    {
        for (int i = v.StartIndex; i < v.StartIndex+v.Size; i++)
        in >> v[i];
        return in;
    }
    friend ostream& operator<<(ostream &out,TVector<ValType> &v)
    {

        for (int i = 0; i < v.StartIndex + v.Size; i++) {

            out << v[i] << " ";
        }
        return out;
    }
};

template <class ValType>
TVector<ValType>::TVector<ValType>(int s, int si):Size(s), StartIndex(si)
{
    if (s <= 0 || s>MAX_VECTOR_SIZE)
        throw "Incorrect size";
    if (si < 0)
        throw "You cannot start at negative index!";
    pVector = new ValType[s]();
}

template <class ValType> 
TVector<ValType>::TVector<ValType>(const TVector<ValType> &v)
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
    ValType x = ValType();
    if (pos < 0 || pos>=MAX_VECTOR_SIZE)
        throw "Wrong position";
    if (pos < StartIndex)
        return x;

    if (pos - StartIndex < Size)
        return pVector[pos - StartIndex];
    else
        throw "Acces Error";
} 

template <class ValType>
bool TVector<ValType>::operator==(const TVector &v) const
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
bool TVector<ValType>::operator!=(const TVector<ValType>&v) const
{
    return !(*this == v);
}


template <class ValType>
const TVector<ValType>& TVector<ValType>::operator=(const TVector<ValType>&v)
{
    if (*this == v)
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
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
    if (val == ValType())
    {
        return *this;
    }
    TVector<ValType> A(Size+StartIndex);
    for (int i = 0; i < A.Size; ++i)
    {
        A[i] = (*this)[i] + val;
    }
    return A;
}
template <class ValType> 
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
    if (val == ValType())
    {
        return *this;
    }
    TVector<ValType> A(Size + StartIndex);
    for (int i = 0; i < A.Size; ++i)
    {
        A[i] = (*this)[i] - val;
    }
    return A;
} 


template <class ValType> 
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
    TVector<ValType> A(Size , StartIndex);
    for (int i = 0; i < A.Size; ++i)
    {
        A[i] = (*this)[i] * val;
    }
    return A;
}


template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
    if ((Size != v.Size) || (StartIndex != v.StartIndex))
        throw "Size and startIndex should be equal";

    TVector<ValType> B(Size, StartIndex), tmp(v);
    for (int i = StartIndex; i < Size+StartIndex; ++i)
    {

        B[i] = (*this)[i] + tmp[i];
    }
    return B;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
    if ((Size != v.Size) || (StartIndex != v.StartIndex))
        throw "Size and startIndex should be equal";

    TVector<ValType> B(Size, StartIndex), tmp(v);
    for (int i = StartIndex; i < Size + StartIndex; ++i)
    {

        B[i] = (*this)[i] - tmp[i];
    }
    return B;
}

template <class ValType> 
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
    if ((v.Size != Size) || (v.StartIndex != StartIndex))
        throw "dimentions of vectors should be equal for dot product";

    ValType ans=ValType();
    TVector <ValType> tmp(v);
    for (int i = std::max(v.StartIndex, StartIndex); i < std::min(v.Size, Size); ++i)
    {
        ans = ans + (*this)[i] * tmp[i];
    }
    return ans;
}


#endif