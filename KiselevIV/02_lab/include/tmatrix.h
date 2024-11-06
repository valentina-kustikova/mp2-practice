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
    if (sz <= 0 )
      throw out_of_range("Vector size should be greater than zero");
    else if (sz >= MAX_VECTOR_SIZE) {
        throw out_of_range("Vector size should be less than maxsize");
    }

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
      pMem = new T[sz];
      for (int i = 0; i < sz; i++)
      {
          pMem[i] = v.pMem[i];
      }
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
  }
  ~TDynamicVector()
  {
      delete[] this->pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      delete [] pMem;
      sz = v.sz;
      pMem = new T[sz];
      for (int i = 0; i < sz; i++) {
          pMem[i] = v.pMem[i];
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
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
      if (ind < 0) {
          throw out_of_range("set_element_with_negative_index");
      }
      if (ind >= sz) {
          throw out_of_range("set_element_with_too_large_index");
      }
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind < 0) {
          throw out_of_range("set_element_with_negative_index");
      }
      if (ind >= sz) {
          throw out_of_range("set_element_with_too_large_index");
      }
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) return false;
      for (int i = 0; i < sz; i++) {
          if (pMem[i] != v.pMem[i])return false;
      }
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(v== *this);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      for (int i = 0; i < sz; i++) {
          pMem[i] = pMem[i] + val;
      }
      return *this;
  }
  TDynamicVector operator-(T val)
  {
      for (int i = 0; i < sz; i++) {
          pMem[i] = pMem[i]- val;
      }
      return *this;
  }
  TDynamicVector operator*(T val)
  {
      for (int i = 0; i < sz; i++) {
          pMem[i] =pMem[i]* val;
      }
      return *this;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz) throw "UNREAL";
      for (int i = 0; i < sz; i++) {
          pMem[i] = pMem[i] + v[i];
      }
      return *this;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz) throw "UNREAL";
      for (int i = 0; i < sz; i++) {
          pMem[i] = pMem[i] - v[i];
      }
      return *this;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      if (size() != v.size()) throw "UNREAL"; 
      T tmp = 0;
      for (int i = 0; i < size(); i++) {
          tmp += pMem[i] * v[i];
      }
      return tmp;
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
      if (s >= MAX_MATRIX_SIZE || s<0) {
          throw "Invalid size of matrix";
      }

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
