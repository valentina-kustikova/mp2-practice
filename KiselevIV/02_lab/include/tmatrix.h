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
      pMem = nullptr;
      swap(*this, v);
  }
  ~TDynamicVector()
  {
      delete[] this->pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v) //todo  (+)
  {
      if (this->pMem == v.pMem) {
          return* this;
      }
      if (sz != v.sz) {
          delete []pMem;
          this->sz = v.sz;
          pMem = new T[sz];
      }
      for (int i = 0; i < sz; i++) {
          pMem[i] = v.pMem[i];
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      swap(*this, v);
      return v;
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
  TDynamicVector operator+(T val) const
  {
      TDynamicVector v1(sz);
      for (int i = 0; i < sz; i++) {
          v1.pMem[i] = pMem[i] + val;
      }
      return v1;
  }
  TDynamicVector operator-(T val) const
  {
      TDynamicVector v1(sz);
      for (int i = 0; i < sz; i++) {
          v1.pMem[i] = pMem[i] - val;
      }
      return v1;
  }
  TDynamicVector operator*(T val) const
  {
      TDynamicVector v1(sz);
      for (int i = 0; i < sz; i++) {
          v1.pMem[i] = pMem[i] * val;
      }
      return v1;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v) const
  {
      if (sz != v.sz) throw "UNREAL";
      TDynamicVector v1(sz);
      for (int i = 0; i < sz; i++) {
          v1.pMem[i] = pMem[i] + v[i];
      }
      return v1;
  }
  TDynamicVector operator-(const TDynamicVector& v)const
  {
      TDynamicVector v1(sz);
      v1 = v * T(-1);
      return (*this+ v1);
  }
  T operator*(const TDynamicVector& v) const
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
      if (s >= MAX_MATRIX_SIZE || s<=0) {
          throw "Invalid size of matrix";
      }
      for (size_t i = 0; i < s; i++) {
          pMem[i] = TDynamicVector<T>(s-i); // todo
      }
  }
  TDynamicMatrix (TDynamicVector<TDynamicVector<T>>& m) : TDynamicVector<TDynamicVector<T>>(m) {}

  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::size;
  using TDynamicVector<TDynamicVector<T>>::at;
  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      if (sz != m.sz) {
          return 0;
      }
      for (int i = 0; i < sz; i++) {
          if (pMem[i] != m.pMem[i]) {
              return 0;
          }
      }
      return 1;
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix<T> res(sz);
      for (int i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] * val;
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.size()) {
          throw "VECTOR AND MATRIX WITH DIFF SIZE";
      }
      TDynamicVector<T> tmp(sz);
      for (int i = 0; i < sz; i++) {
          tmp[i] = T(0);
          for (int j = 0; j < sz - i; j++) {
              tmp[i] += pMem[i][j] * v[i + j];
          }
      }
      return tmp;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      return TDynamicVector < TDynamicVector<T>>:: operator+(m);
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      return TDynamicVector<TDynamicVector<T>>:: operator-(m);
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz) {
          throw "DIF SIZE";

      }
      TDynamicMatrix<T> tmp(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz - i; j++) {
              for (int n = 0; n < j + 1; n++) {
                  tmp[i][j] += pMem[i][n] * m[n + i][j - n];
              }

          }

      }
      return tmp;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (int i = 0; i < m.sz; i++) {
          for (int j = 0; j < m.sz - i; j++) {
              istr >> m[i][j];
          }
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++) {
          for (int j = v.sz - 1; j >= 0; j--) {
              if (j >= v.sz - i) {
                  ostr << "  ";
                  continue;
              }
              ostr << v[i][j] << " ";
          }
          ostr << '\n';
      }
      return ostr;
  }
};

#endif
