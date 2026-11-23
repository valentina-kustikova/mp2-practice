// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include <cassert>

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
    if (sz == 0)
      throw out_of_range("Vector size should be greater than zero");
    if (sz > MAX_VECTOR_SIZE)
        throw out_of_range("Vector size should be less than MAX_VECTOR_SIZE");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
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
      for (size_t i = 0; i < sz; ++i) {
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
      delete[] pMem;
  }

  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v) return *this;
      delete[] pMem;
      sz = v.sz;
      pMem = new T[sz];
      for (size_t i = 0; i < sz; ++i) {
          pMem[i] = v.pMem[i];
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept 
  {
      if (this == &v) return *this;
      delete[] pMem;
      sz = v.sz;
      pMem = v.pMem;
      v.pMem = nullptr;
      v.sz = 0;
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      if (ind >= sz) throw out_of_range("Vector ind should be less than size of the vector");
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      if (ind >= sz) throw out_of_range("Vector ind should be less than size of the vector");
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind >= sz) throw out_of_range("Vector ind should be less than size of the vector");
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind >= sz) throw out_of_range("Vector ind should be less than size of the vector");
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (this == &v) return true;
      if (sz != v.sz) return false;
      for (size_t i = 0; i < sz; ++i) {
          if (pMem[i] != v.pMem[i]) return false;
      }
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(*this == v);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector result(*this);
      for (size_t i = 0; i < sz; ++i) {
          result[i] += val;
      }
      return result;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector result(*this);
      for (size_t i = 0; i < sz; ++i) {
          result.pMem[i] -= val;
      }
      return result;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector result(*this);
      for (size_t i = 0; i < sz; ++i) {
          result.pMem[i] *= val;
      }
      return result;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      TDynamicVector result(*this);
      if (sz != v.sz)
          throw length_error("Vectors must have the same size");
      for (size_t i = 0; i < sz; ++i) {
          result.pMem[i] = pMem[i] + v.pMem[i];
      }
      return result;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      TDynamicVector result(*this);
      if (sz != v.sz) 
          throw length_error("Vectors must have the same size");
      for (size_t i = 0; i < sz; ++i) {
          result.pMem[i] = pMem[i] - v.pMem[i];
      }
      return result;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      if (sz != v.sz)
          throw length_error("Vectors must have the equel size");

      T result{};
      for (size_t i = 0; i < sz; ++i) {
          result += pMem[i] * v.pMem[i];
      }
      return result;
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
    TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
    {

        if (s > MAX_MATRIX_SIZE)
            throw out_of_range("Matrix size is too large");

        for (size_t i = 0; i < sz; i++)
            pMem[i] = TDynamicVector<T>(sz - i);
    }

    using TDynamicVector<TDynamicVector<T>>::operator[];
    using TDynamicVector<TDynamicVector<T>>::size; //для теста

    // сравнение
    bool operator==(const TDynamicMatrix& m) const noexcept
    {
        if (sz != m.sz) return false;
        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz - i; j++) {
                if (pMem[i][j] != m.pMem[i][j]) return false;
            }
        }
        return true;
    }

    // матрично-скалярные операции
    TDynamicMatrix operator*(const T& val)
    {
        TDynamicMatrix result(*this);

        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz - i; j++) {
                result.pMem[i][j] *= val;
            }
        }
        return result;
    }

    // матрично-векторные операции
    TDynamicVector<T> operator*(const TDynamicVector<T>& v)
    {
        if (sz != v.size())
            throw length_error("Matrix and vector sizes must be equal");


        TDynamicVector<T> result(sz);
        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz - i; j++) {
                result[i] += pMem[i][j] * v[i + j];
            }
        }
        return result;
    }

    // матрично-матричные операции
    TDynamicMatrix operator+(const TDynamicMatrix& m)
    {
        if (sz != m.sz)
            throw length_error("Matrices must have the same size");

        TDynamicMatrix result(sz);

        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz - i; j++) {
                result[i][j] = pMem[i][j] + m.pMem[i][j];
            }
        }
        return result;
    }
    TDynamicMatrix operator-(const TDynamicMatrix& m)
    {

        if (sz != m.sz)
            throw length_error("Matrices must have the same size");

        TDynamicMatrix result(*this);

        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz - i; j++) {
                result[i][j] = pMem[i][j] - m.pMem[i][j];
            }
        }
        return result;
    }
    TDynamicMatrix operator*(const TDynamicMatrix& m)
    {
        if (sz != m.sz)
            throw length_error("Matrices must have the same size");

        TDynamicMatrix result(sz);

        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz - i; j++) {
                for (size_t k = i; k <= i + j; ++k) {
                    result[i][j] += pMem[i][k - i] * m.pMem[k][i + j - k];
                }
            }
        }
        return result;
    }

    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicMatrix& v)
    {
        for (size_t i = 0; i < v.sz; ++i) {
            for (size_t j = 0; j < v.sz - i; ++j) {
                istr >> v.pMem[i][j];
            }
        }
        return istr;
    }
    friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
    {
        for (size_t i = 0; i < v.sz; i++) {
            for (size_t j = 0; j < v.sz - i; ++j) {
                ostr << v.pMem[i][j] << ' ';
            }
            ostr << endl;
        }
        return ostr;
    }
};

#endif
