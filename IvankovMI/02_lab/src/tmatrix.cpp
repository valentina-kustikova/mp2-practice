#include "tmatrix.h"

#include <stdexcept>
#include <algorithm>
#include <cassert>

// ---------- TDynamicVector ----------

template<typename T>
TDynamicVector<T>::TDynamicVector(size_t size) : sz(size)
{
    if (sz == 0 || sz > MAX_VECTOR_SIZE)
        throw std::out_of_range("Vector size should be in (0, MAX_VECTOR_SIZE]");
    pMem = new T[sz]();
}

template<typename T>
TDynamicVector<T>::TDynamicVector(T* arr, size_t s) : sz(s)
{
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    if (sz == 0 || sz > MAX_VECTOR_SIZE)
        throw std::out_of_range("Vector size should be in (0, MAX_VECTOR_SIZE]");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
}

template<typename T>
TDynamicVector<T>::TDynamicVector(const TDynamicVector& v) : sz(v.sz)
{
    pMem = new T[sz];
    std::copy(v.pMem, v.pMem + sz, pMem);
}

template<typename T>
TDynamicVector<T>::TDynamicVector(TDynamicVector&& v) noexcept
    : sz(v.sz), pMem(v.pMem)
{
    v.sz = 0;
    v.pMem = nullptr;
}

template<typename T>
TDynamicVector<T>::~TDynamicVector()
{
    delete[] pMem;
}

template<typename T>
TDynamicVector<T>& TDynamicVector<T>::operator=(const TDynamicVector& v)
{
    if (this != &v)
    {
        TDynamicVector tmp(v);
        swap(*this, tmp);
    }
    return *this;
}

template<typename T>
TDynamicVector<T>& TDynamicVector<T>::operator=(TDynamicVector&& v) noexcept
{
    if (this != &v)
    {
        delete[] pMem;
        sz = v.sz;
        pMem = v.pMem;
        v.sz = 0;
        v.pMem = nullptr;
    }
    return *this;
}

template<typename T>
T& TDynamicVector<T>::operator[](size_t ind)
{
    return pMem[ind];
}

template<typename T>
const T& TDynamicVector<T>::operator[](size_t ind) const
{
    return pMem[ind];
}

template<typename T>
T& TDynamicVector<T>::at(size_t ind)
{
    if (ind >= sz)
        throw std::out_of_range("Index out of range");
    return pMem[ind];
}

template<typename T>
const T& TDynamicVector<T>::at(size_t ind) const
{
    if (ind >= sz)
        throw std::out_of_range("Index out of range");
    return pMem[ind];
}

template<typename T>
bool TDynamicVector<T>::operator==(const TDynamicVector& v) const noexcept
{
    if (sz != v.sz)
        return false;
    for (size_t i = 0; i < sz; ++i)
        if (pMem[i] != v.pMem[i])
            return false;
    return true;
}

template<typename T>
bool TDynamicVector<T>::operator!=(const TDynamicVector& v) const noexcept
{
    return !(*this == v);
}

template<typename T>
TDynamicVector<T> TDynamicVector<T>::operator+(T val)
{
    TDynamicVector result(sz);
    for (size_t i = 0; i < sz; ++i)
        result.pMem[i] = pMem[i] + val;
    return result;
}

template<typename T>
TDynamicVector<T> TDynamicVector<T>::operator-(T val)
{
    TDynamicVector result(sz);
    for (size_t i = 0; i < sz; ++i)
        result.pMem[i] = pMem[i] - val;
    return result;
}

template<typename T>
TDynamicVector<T> TDynamicVector<T>::operator*(T val)
{
    TDynamicVector result(sz);
    for (size_t i = 0; i < sz; ++i)
        result.pMem[i] = pMem[i] * val;
    return result;
}

template<typename T>
TDynamicVector<T> TDynamicVector<T>::operator+(const TDynamicVector& v)
{
    if (sz != v.sz)
        throw std::out_of_range("Vector sizes must match");
    TDynamicVector result(sz);
    for (size_t i = 0; i < sz; ++i)
        result.pMem[i] = pMem[i] + v.pMem[i];
    return result;
}

template<typename T>
TDynamicVector<T> TDynamicVector<T>::operator-(const TDynamicVector& v)
{
    if (sz != v.sz)
        throw std::out_of_range("Vector sizes must match");
    TDynamicVector result(sz);
    for (size_t i = 0; i < sz; ++i)
        result.pMem[i] = pMem[i] - v.pMem[i];
    return result;
}

template<typename T>
T TDynamicVector<T>::operator*(const TDynamicVector& v)
{
    if (sz != v.sz)
        throw std::out_of_range("Vector sizes must match");
    T result = T();
    for (size_t i = 0; i < sz; ++i)
        result = result + pMem[i] * v.pMem[i];
    return result;
}

// Явные инстанцирования для типов, используемых в тестах и матрице
template class TDynamicVector<int>;
template class TDynamicVector<double>;
template class TDynamicVector<float>;
template class TDynamicVector<long long>;

template class TDynamicVector<TDynamicVector<int>>;
template class TDynamicVector<TDynamicVector<double>>;
template class TDynamicVector<TDynamicVector<float>>;
template class TDynamicVector<TDynamicVector<long long>>;