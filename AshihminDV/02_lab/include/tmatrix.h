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
      if (sz > MAX_VECTOR_SIZE)
      {
          throw out_of_range("Too large size");
      }
    if (sz <= 0)
      throw out_of_range("Vector size should be greater than zero");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v): sz(v.sz)
  {
      pMem = new T[sz]();
      for (int i = 0; i < sz; i++)
      {
          pMem[i] = v.pMem[i];
      }
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
      /*try
      * {
      * }
      * catch(...)
      * {
      * }*/
  }
  ~TDynamicVector()
  {
      if (pMem != nullptr)
      {
          delete[]pMem;
      }
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this->pMem == v.pMem)
      {
          return *this;
      }
      if (this->sz != v.sz)
      {
          this->sz = v.sz;
          delete[]pMem;
          pMem = new T[this->sz]();
      }
      for (int i = 0; i < this->sz; i++)
      {
          this->pMem[i] = v.pMem[i];
      }

  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      return this->pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      return this->pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind <0 || ind > sz - 1)
      {
          throw "Incorrect index";
      }
      return this->pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind <0 || ind > sz - 1)
      {
          throw "Incorrect index";
      }
      return this->pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (this->sz != v.sz) {
          return false;
      }
      for (int i = 0; i < sz; i++) {
          if (this->pMem[i] != v[i]) {
              return false;
          }
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
      TDynamicVector<T> SUM(this->sz);
      for (int i = 0; i < this->sz; i++) {
          SUM[i] = pMem[i] + val;
      }
      return SUM;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector<T> RAZ(this->sz);
      for (int i = 0; i < this->sz; i++) {
          RAZ[i] = pMem[i] - val;
      }
      return RAZ;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector<T> PR(this->sz);
      for (int i = 0; i < this->sz; i++) {
          PR[i] = pMem[i] * val;
      }
      return PR;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (this->sz != v.size()) {
          throw " NOT EQUAL SIZE "
      }
      TDynamicVector<T> SUM(this->sz);
      for (int i = 0; i < this->sz; i++) {
          SUM[i] = v[i] + this->pMem[i];
      }
      return SUM;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (this->sz != v.size()) {
          throw " NOT EQUAL SIZE "
      }
      TDynamicVector<T> RAZ(this->sz);
      for (int i = 0; i < this->sz; i++) {
          RAZ[i] = v[i] - this->pMem[i];
      }
      return RAZ;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      if (this->sz != v.size()) {
          throw " NOT EQUAL SIZE "
      }
      T PR = T();
      for (int i = 0; i < this->sz; i++) {
          PR += v[i] * this->pMem[i];
      }
      return PR;
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
