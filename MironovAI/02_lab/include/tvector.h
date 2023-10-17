#ifndef __TVECTOR_H__
#define __TVECTOR_H__

#include <iostream>
using namespace std;

const int MAX_VECTOR_SIZE = 100000000;


// Шаблон вектора
template <class ValType>
class TVector
{
private:
    int StartIndex;
protected:
  ValType *pVector;
  int Size;       
  //int StartIndex; 
public:
    TVector(int s = 10, int si = 0);
    TVector(const TVector& v);
    ~TVector();
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
    for (int i = 0; i < v.StartIndex + v.Size; i++)
      out << v[i] << ' ';
    return out;
  }
};

template <class ValType>
TVector<ValType>::TVector(int s, int si):Size(s), StartIndex(si)
{
    if (s <= 0 || s>MAX_VECTOR_SIZE)
        throw "Incorrect size";
    if (si < 0)
        throw "You cannot start at negative index!";
    pVector = new ValType[s]();
}

template <class ValType> 
TVector<ValType>::TVector(const TVector<ValType> &v) 
{
  Size = v.Size;
  StartIndex = v.StartIndex;
  pVector = new ValType[Size];
  std::copy(v.pVector, v.pVector + v.Size, pVector);  
} 
template <class ValType>
TVector<ValType>::~TVector()
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
bool TVector<ValType>::operator==(const TVector<ValType>&v) const
{
    //Нет перегрузки индексации для константного TVector
    TVector tmp1(v), tmp2(*this);
    //Реализация рассчитана на то, что в значимых элементах тоже могут быть нули
    if (StartIndex + Size != v.StartIndex + v.Size)
        return 0;


    for (int i = min(StartIndex, v.StartIndex); i < StartIndex + Size; ++i)
    {
        if (tmp2[i] != tmp1[i])
            return 0;
    }
    return 1;
}
/*
template <class ValType>
bool TVector<ValType>::operator==(const TVector &v) const
{
    
    TVector tmp1(v), tmp2(*this);
    //Реализация  НЕ рассчитана на то, что в значимых элементах тоже могут быть нули
    if ((StartIndex != v.StartIndex) || (Size != v.Size)) return false;


    for (int i = StartIndex; i < StartIndex + Size; ++i)
    {
        if (tmp1[i] != tmp2[i])
            return 0;
    }
    return 1;
}

*/


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
        ValType* Tmp = new ValType[v.Size];
        delete[] pVector;
        pVector = Tmp;
    }

    Size = v.Size;
    StartIndex = v.StartIndex;
    std::copy(v.pVector, v.pVector + v.Size, pVector);
} 


//После добавления числа к вектору, первые "нули" перестают быть нулями. Это учитывается. Другая реализация закомментирована 
template <class ValType> 
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
    TVector<ValType> A(Size+StartIndex);
    for (int i = 0; i < A.Size; ++i)
    {
        A[i] = (*this)[i] + val;
    }
    return A;
}
/*
template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
    TVector<ValType> A(Size, index);
    for (int i = StartIndex; i < Size+StartIndex; ++i)
    {
        A[i] = (*this)[i] + val;
    }
    return A;
}
*/


template <class ValType> 
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
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
    TVector <ValType> B(max(v.Size, Size), min(v.StartIndex, StartIndex)), tmp(v);
    for (int i = min(v.StartIndex, StartIndex); i < min(v.StartIndex, StartIndex) + max(v.Size, Size); ++i)
    {   
        B[i] = (*this)[i] + tmp[i];
    }
    return B;
} 

/*
template <class ValType>
TVector<ValType> TVector<ValType>::operator+(TVector<ValType> &v)
{
    if ((Size != v.Size) || (StartIndex != v.StartIndex))
        throw "Size and startIndex should be equal"

    TVector <ValType> B(Size, StartIndex);
    for (int i = StartIndex; i < StartIndex + Size; ++i)
    {

        B[i] =  (*this)[i] + v[i];
    }
    return B;
}
*/
template <class ValType> 
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
    TVector <ValType> B(max(v.Size, Size), min(v.StartIndex, StartIndex)), tmp(v);
  
    for (int i = min(v.StartIndex, StartIndex); i < min(v.StartIndex, StartIndex) + max(v.Size, Size); ++i)
    {
        B[i] = (*this)[i] - tmp[i];       
    }
    return B;
} 

template <class ValType> 
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
    ValType ans=ValType();
    TVector <ValType> tmp(v);
    for (int i = std::min(v.StartIndex, StartIndex); i < std::max(v.Size, Size); ++i)
    {
        ans = ans + (*this)[i] * tmp[i];
    }
    return ans;
}


#endif