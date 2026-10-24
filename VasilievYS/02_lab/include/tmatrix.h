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
    if (sz == 0)
      throw out_of_range("Vector size should be greater than zero");
    if (sz > MAX_VECTOR_SIZE)
        throw out_of_range("Too large vector");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
      if (sz == 0)
          throw out_of_range("Vector size should be greater than zero");
      if (sz > MAX_VECTOR_SIZE)
          throw out_of_range("Too large vector");
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v) : sz(v.sz)
  {
      pMem = new T[sz];
      std::copy(v.pMem, v.pMem + sz, pMem);
  }
  TDynamicVector(TDynamicVector&& v) noexcept
      : sz(v.sz), pMem(v.pMem)
  {
      v.sz = 0; v.pMem = nullptr;
  }
  ~TDynamicVector()
  {
      delete[]pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this != &v)
      {
          if (sz != v.sz)
          {
              T* temp_mem = new T[v.sz];
              delete[]pMem;
              pMem = temp_mem;
              sz = v.sz;
          }
      std::copy(v.pMem, v.pMem + sz, pMem);
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      if (this != &v)
      {
          delete[]pMem;
          pMem = v.pMem;
          sz = v.sz;
          v.sz = 0;
          v.pMem = nullptr;
      }
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      if (ind >= sz) throw out_of_range("Index out of range");
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      if (ind >= sz) throw out_of_range("Index out of range");
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind >= sz) throw out_of_range("Index out of range");
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind >= sz) throw out_of_range("Index out of range");
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (this == &v)return true;
      if (sz != v.sz)return false;
      for (size_t i = 0; i < sz; i++)
      {
          if (pMem[i] != v.pMem[i]) return false;
      }
      return true;

  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(*this == v);
  }

  // скалярные операции
  TDynamicVector operator+(T val) const
  {
      TDynamicVector res(sz);
      for (size_t i=0; i < sz; i++)
      {
          res[i] =pMem[i] + val;
      }
      return res;
  }
  TDynamicVector operator-(T val) const
  {
      TDynamicVector res(sz);
      for (size_t i=0; i < sz; i++)
      {
          res[i] = pMem[i] - val;
      }
      return res;
  }
  TDynamicVector operator*(T val) const
  {
      TDynamicVector res(sz);
      for (size_t i=0; i < sz; i++)
      {
          res[i] = pMem[i] * val;
      }
      return res;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v) const
  {
      if (v.sz != sz) throw out_of_range("Can't add vectors with different sizes");
      TDynamicVector res(sz);
      for (size_t i=0; i < sz; i++)
      {
          res[i] = pMem[i] + v.pMem[i];
      }
      return res;
  }
  TDynamicVector operator-(const TDynamicVector& v) const
  {
      if (v.sz != sz) throw out_of_range("Can't subtract vectors with different sizes");
      TDynamicVector res(sz);
      for (size_t i=0; i < sz; i++)
      {
          res[i] = pMem[i] - v.pMem[i];
      }
      return res;
  }
  T operator*(const TDynamicVector& v) const //noexcept(noexcept(T()))
  {
      if (v.sz != sz) throw out_of_range("Can't multiply vectors with different sizes");
      T res=0;
      for (size_t i=0; i < sz; i++)
      {
          res = res + (pMem[i] * v.pMem[i]);
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
  TDynamicMatrix(size_t s = 1) : 
      TDynamicVector<TDynamicVector<T>>((s>MAX_MATRIX_SIZE) ? MAX_VECTOR_SIZE+1 : s)
  {
      for (size_t i = 0; i < sz; i++)
      {
          pMem[i] = TDynamicVector<T>(sz);
      }
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  using TDynamicVector<TDynamicVector<T>>::size;
  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      return TDynamicVector<TDynamicVector<T>>::operator== (m);
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val) const
  {
      TDynamicMatrix res(sz);
      for (size_t row = 0; row < sz; row++)
      {
          res.pMem[row] = pMem[row] * val;
      }
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v) const
  {
      if (v.size() != sz) 
          throw out_of_range("Cant multiply matrix and vector of different sizes");
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; i++)
      {
          res[i] = pMem[i] * v;
      }
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m) const
  {
      if (m.sz != sz)
          throw out_of_range("Cant add matrices of different sizes");
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; i++)
      {
          res.pMem[i] = pMem[i] + m.pMem[i];
      }
      return res;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m) const
  {
      if (m.sz != sz)
          throw out_of_range("Cant subtract matrices of different sizes");
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; i++)
      {
          res.pMem[i] = pMem[i] - m.pMem[i];
      }
      return res;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m) const
  {
      if (m.sz != sz)
          throw out_of_range("Cant multiply matrices of different sizes");
      TDynamicMatrix<T> res(sz);
      for (size_t i = 0; i < sz; i++)
      {
          for (size_t j = 0; j < sz; j++)
          {
              for (size_t k = 0; k < sz; k++)
              {
                  res.pMem[i][j] = res.pMem[i][j] + pMem[i][k] * m.pMem[k][j];
              }
          }
      }
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
      {
          istr >> v.pMem[i];
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          ostr << v.pMem[i] << '\n';
      return ostr;
  }
};

#endif