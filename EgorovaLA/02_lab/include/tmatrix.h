// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

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
    TDynamicVector(size_t size = 1) : sz(size)
    {
        if (sz <= 0 || sz >= MAX_VECTOR_SIZE)
            throw out_of_range("Size vector should be >0 & <100000000");
        pMem = new T[sz](); // У типа T д.б. констуктор по умолчанию
    }

    TDynamicVector(T* arr, size_t s) : sz(s)
    {
        assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
        pMem = new T[sz];
        std::copy(arr, arr + sz, pMem);
    }

    TDynamicVector(const TDynamicVector& v)
    {
        sz = v.sz;
        pMem = new T[sz];
        for (int i = 0; i < sz; i++) {
            pMem[i] = v.pMem[i];
        }
    }

    TDynamicVector(TDynamicVector&& v) noexcept : sz(v.sz), pMem(v.pMem)
    {
        v.sz = 0;
        v.pMem = nullptr;
    }

    ~TDynamicVector() 
    {
        if (pMem != nullptr) {
            delete[] pMem;
        }
    }

    TDynamicVector& operator=(const TDynamicVector& v)
    {
        if (this == &v) return *this;
        if (sz != v.sz) {
            sz = v.sz;
            pMem = new T[sz];
        }
        for (int i = 0; i < sz; i++) {
            pMem[i] = v.pMem[i];
        }
        return *this;
    }
    TDynamicVector& operator=(TDynamicVector&& v) noexcept
    {
        if (this == &v) return *this;
        sz = v.sz;
        pMem = v.pMem;
        v.sz = 0;
        v.pMem = nullptr;
        return *this;
    }

    size_t size() const noexcept { return sz; }

    // индексация
    T& operator[](size_t ind)
    {
        return pMem[ind];
    }

    const T& operator[](size_t ind) const
    {
        return pMem[ind];
    }

    // индексация с контролем
    T& at(size_t ind)
    {
        if (ind < 0 || ind >= sz)
            throw "No correct index";
        return(this->pMem[ind]);
    }

    const T& at(size_t ind) const
    {
        if (ind < 0 || ind >= sz)
            throw "No correct index";
        return(this->pMem[ind]);
    }

    // сравнение
    bool operator==(const TDynamicVector& v) const noexcept
    {
        if (sz != v.sz) return 0;
        for (int i = 0; i < sz; i++) {
            if (pMem[i] != v.pMem[i]) return 0;
        }
        return 1;
    }

    bool operator!=(const TDynamicVector& v) const noexcept
    {
        return !(*this == v);
    }

    // скалярные операции
    TDynamicVector operator+(T val)
    {
        TDynamicVector res(sz);
        for (int i = 0; i < sz; i++)
        {
            res.pMem[i] = pMem[i] + val;
        }
        return res;
    }
    TDynamicVector operator-(T val)
    {
        TDynamicVector res(sz);
        for (int i = 0; i < sz; i++)
        {
            res.pMem[i] = pMem[i] - val;
        }
        return res;
    }
    TDynamicVector operator*(T val)
    {
        TDynamicVector res(sz);
        for (int i = 0; i < sz; i++)
        {
            res.pMem[i] = pMem[i] * val;
        }
        return res;
    }

    // векторные операции
    TDynamicVector operator+(const TDynamicVector& v)
    {
        if (sz != v.sz) throw "Not equal size";
        TDynamicVector res(sz);
        for (int i = 0; i < sz; i++) {
            res.pMem[i] = pMem[i] + v.pMem[i];
        }
        return res;
    }
    TDynamicVector operator-(const TDynamicVector& v) 
    {
        if (sz != v.sz) throw "Not equal size";
        TDynamicVector res(sz);
        for (int i = 0; i < sz; i++) {
            res.pMem[i] = pMem[i] - v.pMem[i];
        }
        return res;
    }
    T operator*(const TDynamicVector& v)
    {
        T res = 0;
        if (sz != v.sz) throw "Not equal size";
        for (int i = 0; i < sz; i++) {
            res += pMem[i] * v.pMem[i];
        }
        return res;
    }

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
    TDynamicMatrix(const TDynamicVector<TDynamicVector<T>>& m)
        : TDynamicVector<TDynamicVector<T>>(m) {};

    TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
    {
        if (sz <= 0 || sz >= MAX_MATRIX_SIZE)
            throw out_of_range("Matrix size should be > 0 and <10000");
        for (size_t i = 0; i < sz; i++){
            pMem[i] = TDynamicVector<T>(sz - i);
        }
    }

    using TDynamicVector<TDynamicVector<T>>::operator[];
    using TDynamicVector<TDynamicVector<T>>::size;
    using TDynamicVector<TDynamicVector<T>>::at;

    // сравнение
    bool operator==(const TDynamicMatrix& m) const noexcept
    {
        return TDynamicVector<TDynamicVector<T>>::operator==(m);
    }

    bool operator!=(const TDynamicMatrix& m) const noexcept
    {
        return (!(*this == m));
    }

    // матрично-скалярные операции
    TDynamicMatrix operator*(const T& val)
    {
        TDynamicMatrix result(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz - i; j++) {
                result[i][j] = pMem[i][j] * val;
            }
        }
        return result;
    }

    // матрично-векторные операции
    TDynamicVector<T> operator*(const TDynamicVector<T>& v)
    {
        if (size() != v.size())
            throw "Matrix and Vector have no correct size";
        TDynamicVector<T> res(sz);
        for (int i = 0; i < sz; i++) {
            res[i] = 0;
            for (int j = 0; j < sz-i; j++) {
                res[i] += pMem[i][j] * v[j];
            }
        }
        return res;
    }

    // матрично-матричные операции
    TDynamicMatrix operator+(const TDynamicMatrix& m)
    {
        return TDynamicVector<TDynamicVector<T>>::operator+(m);
    }
    TDynamicMatrix operator-(const TDynamicMatrix& m)
    {
        return TDynamicVector<TDynamicVector<T>>::operator-(m);
    }

    TDynamicMatrix operator*(const TDynamicMatrix& m)
    {
        if (size() != m.size()) 
            throw "Matrixes have diff size";
        TDynamicMatrix answ(sz);

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz - i; j++) {
                for (int k = 0; k < j + 1; k++) {
                    answ[i][j] += pMem[i][k] * m[k + i][j - k];
                }
            }
        }
        return answ;
    }

    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicMatrix& m)
    {
        for (int i = 0; i < m.sz; i++) {
            for (int j = 0; j < m.sz - i; j++) {
                istr >> m[i][j];
            }
        }
        return istr;
    }
    friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& m)
    {
        for (int i = 0; i < m.sz; i++) {
            for (int j = m.sz-1; j >=0; j--) {
                if (j >= m.sz - i) {
                    ostr << "x ";
                    continue;
                }
                ostr << m[i][j] << " ";
            }
            ostr << '\n';
        }
        return ostr;
    }
};

#endif
