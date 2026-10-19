// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include <utility>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
    size_t sz;
    T* pMem;
public:
    TDynamicVector(size_t size = 1);
    TDynamicVector(T* arr, size_t s);
    TDynamicVector(const TDynamicVector& v);
    TDynamicVector(TDynamicVector&& v) noexcept;
    ~TDynamicVector();

    TDynamicVector& operator=(const TDynamicVector& v);
    TDynamicVector& operator=(TDynamicVector&& v) noexcept;

    size_t size() const noexcept { return sz; }

    // индексация
    T& operator[](size_t ind);
    const T& operator[](size_t ind) const;

    // индексация с контролем
    T& at(size_t ind);
    const T& at(size_t ind) const;

    // сравнение
    bool operator==(const TDynamicVector& v) const noexcept;
    bool operator!=(const TDynamicVector& v) const noexcept;

    // скалярные операции
    TDynamicVector operator+(T val);
    TDynamicVector operator-(T val);
    TDynamicVector operator*(T val);

    // векторные операции
    TDynamicVector operator+(const TDynamicVector& v);
    TDynamicVector operator-(const TDynamicVector& v);
    T operator*(const TDynamicVector& v);

    friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
    {
        std::swap(lhs.sz, rhs.sz);
        std::swap(lhs.pMem, rhs.pMem);
    }

    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicVector& v)
    {
        for (size_t i = 0; i < v.sz; i++)
            istr >> v.pMem[i]; // требуется оператор>> для типа T
        return istr;
    }
    friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
    {
        for (size_t i = 0; i < v.sz; i++)
            ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
        return ostr;
    }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
    using TDynamicVector<TDynamicVector<T>>::pMem;
    using TDynamicVector<TDynamicVector<T>>::sz;
public:
    TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
    {
        for (size_t i = 0; i < sz; i++)
            pMem[i] = TDynamicVector<T>(sz);
    }

    using TDynamicVector<TDynamicVector<T>>::operator[];

    // сравнение
    bool operator==(const TDynamicMatrix& m) const noexcept
    {
        throw "Method is not implemented";
    }

    // матрично-скалярные операции
    TDynamicMatrix operator*(const T& val)
    {
        throw "Method is not implemented";
    }

    // матрично-векторные операции
    TDynamicVector<T> operator*(const TDynamicVector<T>& v)
    {
        throw "Method is not implemented";
    }

    // матрично-матричные операции
    TDynamicMatrix operator+(const TDynamicMatrix& m)
    {
        throw "Method is not implemented";
    }
    TDynamicMatrix operator-(const TDynamicMatrix& m)
    {
        throw "Method is not implemented";
    }
    TDynamicMatrix operator*(const TDynamicMatrix& m)
    {
        throw "Method is not implemented";
    }

    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicMatrix& v)
    {
        throw "Method is not implemented";
    }
    friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
    {
        throw "Method is not implemented";
    }
};

#endif
