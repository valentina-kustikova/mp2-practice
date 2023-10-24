#ifndef __TVECTOR_H__
#define __TVECTOR_H__

#include <iostream>
using namespace std;

const int MAX_VECTOR_SIZE = 100000000;


template <class T>
class TVector
{
protected:
    int index;
    T *pVector;
    int size;        
public:
    TVector<T>(int s = 10, int si = 0);
    TVector<T>(const TVector& v);
    virtual ~TVector<T>();
    int Getsize()       { return size;       } 
    int Getindex() { return index; } 
    T& operator[](int pos);             
    bool operator==(const TVector<T> &v) const;  
    bool operator!=(const TVector<T> &v) const;  
    const TVector<T>& operator=(const TVector<T> &v);

    // скалярные операции
    TVector<T>  operator+(const T &val);
    TVector<T>  operator-(const T &val);
    TVector<T>  operator*(const T &val);

    // векторные операции
    TVector<T>  operator+(const TVector<T> &v);
    TVector<T>  operator-(const TVector<T>&v);
    T  operator*(const TVector<T> &v);

    // ввод-вывод
    friend istream& operator>>(istream &in, TVector<T> &v)
    {
        for (int i = v.index; i < v.index+v.size; i++)
        in >> v[i];
        return in;
    }
    friend ostream& operator<<(ostream &out,TVector<T> &v)
    {

        for (int i = 0; i < v.index + v.size; i++) {

            out << v[i] << " ";
        }
        return out;
    }
};

template <class T>
TVector<T>::TVector<T>(int s, int si):size(s), index(si)
{
    if (s <= 0 || s>MAX_VECTOR_SIZE)
        throw "Incorrect size";
    if (si < 0)
        throw "You cannot start at negative index!";
    pVector = new T[s]();
}

template <class T> 
TVector<T>::TVector<T>(const TVector<T> &v)
{

    size = v.size;
    index = v.index;
    pVector = new T[size];
    std::copy(v.pVector, v.pVector + v.size, pVector);  
} 
template <class T>
TVector<T>::~TVector<T>()
{
    delete[] pVector;
} 

template <class T> 
T& TVector<T>::operator[](int pos) 
{
    T x = T();
    if (pos < 0 || pos>=MAX_VECTOR_SIZE)
        throw "Wrong position";
    if (pos < index)
        return x;

    if (pos - index < size)
        return pVector[pos - index];
    else
        throw "Acces Error";
} 

template <class T>
bool TVector<T>::operator==(const TVector &v) const
{
   
    if ((index != v.index) || (size != v.size)) return false;

    for (int i = 0; i < size; ++i)
    {
        if (pVector[i] != v.pVector[i]) {
            return false;
        }
    }
    return true;
}



template <class T> 
bool TVector<T>::operator!=(const TVector<T>&v) const
{
    return !(*this == v);
}


template <class T>
const TVector<T>& TVector<T>::operator=(const TVector<T>&v)
{
    if (*this == v)
        return *this;

    if (size != v.size)
    {
        delete[] pVector;
        pVector = new T[v.size];
    }

    size = v.size;
    index = v.index;
    for (int i = 0; i < size; i++)
    {
        pVector[i] = v.pVector[i];
    }
    return *this;
} 



template <class T> 
TVector<T> TVector<T>::operator+(const T &val)
{
    if (val == T())
    {
        return *this;
    }
    TVector<T> A(size+index);
    for (int i = 0; i < A.size; ++i)
    {
        A[i] = (*this)[i] + val;
    }
    return A;
}
template <class T> 
TVector<T> TVector<T>::operator-(const T &val)
{
    if (val == T())
    {
        return *this;
    }
    TVector<T> A(size + index);
    for (int i = 0; i < A.size; ++i)
    {
        A[i] = (*this)[i] - val;
    }
    return A;
} 


template <class T> 
TVector<T> TVector<T>::operator*(const T &val)
{
    TVector<T> A(size , index);
    for (int i = 0; i < A.size; ++i)
    {
        A[i] = (*this)[i] * val;
    }
    return A;
}


template <class T>
TVector<T> TVector<T>::operator+(const TVector<T> &v)
{
    if ((size != v.size) || (index != v.index))
        throw "size and startIndex should be equal";

    TVector<T> B(size, index), tmp(v);
    for (int i = index; i < size+index; ++i)
    {

        B[i] = (*this)[i] + tmp[i];
    }
    return B;
}

template <class T>
TVector<T> TVector<T>::operator-(const TVector<T>& v)
{
    if ((size != v.size) || (index != v.index))
        throw "size and startIndex should be equal";

    TVector<T> B(size, index), tmp(v);
    for (int i = index; i < size + index; ++i)
    {

        B[i] = (*this)[i] - tmp[i];
    }
    return B;
}

template <class T> 
T TVector<T>::operator*(const TVector<T> &v)
{
    if ((v.size != size) || (v.index != index))
        throw "dimentions of vectors should be equal for dot product";

    T ans=T();
    TVector <T> tmp(v);
    for (int i = std::max(v.index, index); i < std::min(v.size, size); ++i)
    {
        ans = ans + (*this)[i] * tmp[i];
    }
    return ans;
}


#endif