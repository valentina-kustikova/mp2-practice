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
      throw out_of_range("Vector size should be greater than zero");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v) : sz(v.sz)
  {
      pMem = new T[sz];
      for (int i = 0; i < sz; i++)
      {
          pMem[i] = v.pMem[i];
      }
  }
  TDynamicVector(TDynamicVector&& v) noexcept
      : pMem(v.pMem), sz(v.sz)
  {
      v.pMem = nullptr;
      v.sz = 0;
  }
  ~TDynamicVector()
  {
      if (pMem != nullptr) 
      {
          delete[] pMem;
      }
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v)
      {
          return *this;
      }
      if (sz != v.sz)
      {
          delete[] pMem;
          sz = v.sz;
          pMem = new T[sz];
      }
      for (int i = 0; i < sz; i++)
      {
          pMem[i] = v.pMem[i];
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      if (this == &v)
      {
          return *this;
      }

      pMem = v.pMem;
      v.pMem = nullptr;
      sz = v.sz;
      v.sz = 0;

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
      if ((ind >= sz) || (ind < 0))
      {
          throw "Index out of range";
      }
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if ((ind >= sz) || (ind < 0))
      {
          throw "Index out of range";
      }
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
      {
          return false;
      }
      for (int i = 0; i < sz; i++)
      {
          if (pMem[i] != v.pMem[i])
          {
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
      TDynamicVector result(sz);

      for (int i = 0; i < sz; i++)
      {
          result.pMem[i] = pMem[i] + val;
      }

      return result;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector result(sz);

      for (int i = 0; i < sz; i++)
      {
          result.pMem[i] = pMem[i] - val;
      }

      return result;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector result(sz);

      for (int i = 0; i < sz; i++)
      {
          result.pMem[i] = pMem[i] * val;
      }

      return result;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz)
      {
          throw "Sizes are not equel";
      }
      TDynamicVector result(sz);

      for (int i = 0; i < sz; i++)
      {
          result.pMem[i] = pMem[i] + v.pMem[i];
      }

      return result;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz)
      {
          throw "Sizes are not equel";
      }
      TDynamicVector result(sz);

      for (int i = 0; i < sz; i++)
      {
          result.pMem[i] = pMem[i] - v.pMem[i];
      }
      return result;
  }
  T operator*(const TDynamicVector& v) 
  {
      if (sz != v.sz)
      {
          throw "Sizes are not equel";
      }
      T result = T(0);
      for (int i = 0; i < sz; i++)
      {
          result += this->pMem[i] * v.pMem[i];
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
    TDynamicMatrix(const TDynamicVector<TDynamicVector<T>>& m) 
        : TDynamicVector<TDynamicVector<T>>(m) {};
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if (sz <= 0 || sz >= MAX_MATRIX_SIZE)
      {
          throw "Wrong vector size";
      }
      for (size_t i = 0; i < sz; i++)
      {
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
      return TDynamicVector<TDynamicVector<T>>::operator!=(m);
  }


  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix result(sz);

      for (int i = 0; i < sz; i++) 
      {
          for (int j = 0; j < sz - i; j++) 
          {
              result[i][j] = pMem[i][j] * val;
          }
      }
      return result;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.size())
      {
          throw "Not equal sizes";
      }
      TDynamicVector<T> result(sz);

      for (int i = 0; i < sz; i++)
      {
          result[i] = 0;
          for (int j = 0; j < sz - i; j++)
          {
              result[i] += pMem[i][j] * v[j];
          }
      }
      return result;
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
      if (sz != m.sz) 
      {
          throw "Not equal sizes";
      }

      TDynamicMatrix result(sz);

      for (size_t i = 0; i < sz; i++) 
      {
          for (size_t j = 0; j < sz - i; j++) 
          {
              result[i][j] = 0;

              for (size_t k = 0; k < j + 1; k++) 
              {
                  result.pMem[i][j] += pMem[i][k] * m.pMem[k + i][j - k];
              }
          }
      }
      return result;
  } 

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++) {
          istr >> v[i];
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++) {
          ostr << v[i] << '\n';
      }
      return ostr;
  }
};

#endif
