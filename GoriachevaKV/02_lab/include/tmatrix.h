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
        throw out_of_range("Vector size exceeds MAX_VECTOR_SIZE");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v) {
      sz = v.sz;
      pMem = nullptr;
      pMem = new T[sz];
      for (int i = 0; i < sz; i++) pMem[i] = v.pMem[i];
  }

  TDynamicVector(TDynamicVector&& v) noexcept {
      sz = v.sz;
      pMem = v.pMem;
      v.sz = 0;
      v.pMem = nullptr;
  }

  ~TDynamicVector() {
      delete[] pMem;
  }

  TDynamicVector& operator=(const TDynamicVector& v) {
      if (&v == this) return *this;

      if (sz != v.sz) {
          delete[] pMem;
          sz = v.sz;
          pMem = new T[sz]();
      }

      for (int i = 0; i < sz; i++) pMem[i] = v.pMem[i];
      return *this;
  }

  TDynamicVector& operator=(TDynamicVector&& v) noexcept {
      if (this != &v) {
          delete[] pMem;
          sz = v.sz;
          pMem = v.pMem;
          v.sz = 0;
          v.pMem = nullptr;
      }
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind) { return pMem[ind]; }

  const T& operator[](size_t ind) const { return pMem[ind]; }

  // индексация с контролем
  T& at(size_t ind) {
      if (ind >= sz) throw std::exception();
      return pMem[ind];
  }

  const T& at(size_t ind) const {
      if (ind >= sz) throw std::exception();
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept {
      if (sz != v.sz) return false;
      for (int i = 0; i < sz; i++) {
          if (pMem[i] != v.pMem[i]) return false;
      }
      return true;
  }

  bool operator!=(const TDynamicVector& v) const noexcept { return !(*this == v); }

  // скалярные операции
  TDynamicVector operator+(T val) {
      TDynamicVector<T> temp(sz);
      for (int i = 0; i < sz; i++) {
          temp.pMem[i] = (*this).pMem[i] + val;
      }
      return temp;
  }

  TDynamicVector operator-(T val) {
      TDynamicVector<T> temp(sz);
      for (int i = 0; i < sz; i++) {
          temp.pMem[i] = (*this).pMem[i] - val;
      }
      return temp;
  }

  TDynamicVector operator*(T val) {
      TDynamicVector<T> temp(sz);
      for (int i = 0; i < sz; i++) {
          temp.pMem[i] = (*this).pMem[i] * val;
      }
      return temp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v) {
      if ((*this).sz != v.sz) throw std::exception();
      TDynamicVector<T> temp(sz);
      for (int i = 0; i < sz; i++) {
          temp.pMem[i] = (*this).pMem[i] + v.pMem[i];
      }
      return temp;
  }

  TDynamicVector operator-(const TDynamicVector& v) {
      if ((*this).sz != v.sz) throw std::exception();
      TDynamicVector<T> temp(sz);
      for (int i = 0; i < sz; i++) {
          temp.pMem[i] = (*this).pMem[i] - v.pMem[i];
      }
      return temp;
  }

  T operator*(const TDynamicVector& v)
  {
      if ((*this).sz != v.sz) throw std::exception();
      T result{};
      for (int i = 0; i < sz; i++) {
          result += ((*this).pMem[i] * v.pMem[i]);
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
      if (sz > MAX_MATRIX_SIZE)
          throw out_of_range("Matrix size exceeds MAX_MATRIX_SIZE");
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::size;
  using TDynamicVector<TDynamicVector<T>>::at;

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      if (sz != m.sz) return false;
      for (int i = 0; i < sz; i++) {
          for (int j = i; j < sz; j++) {
              if (pMem[i][j] != m.pMem[i][j]) return false;
          }
      }
      return true;
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix temp(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = i; j < sz; j++) {
              temp.pMem[i][j] = pMem[i][j] * val;
          }
      }
      return temp;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.size()) throw std::exception();
      TDynamicVector<T> temp(sz);
      for (int i = 0; i < sz; i++) {
          T res{};
          for (int j = i; j < sz; j++) {
              res += (pMem[i][j] * v[j]);
          }
          temp[i] = res;
      }
      return temp;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if ((*this).sz != m.sz) throw std::exception();
      TDynamicMatrix temp(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = i; j < sz; j++) {
              temp.pMem[i][j] = (*this).pMem[i][j] + m.pMem[i][j];
          }
      }
      return temp;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if ((*this).sz != m.sz) throw std::exception();
      TDynamicMatrix temp(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = i; j < sz; j++) {
              temp.pMem[i][j] = (*this).pMem[i][j] - m.pMem[i][j];
          }
      }
      return temp;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if ((*this).sz != m.sz) throw std::exception();
      TDynamicMatrix temp(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = i; j < sz; j++) {
              T res{};
              for (int k = i; k <= j; k++) {
                res += ((*this).pMem[i][k] * m.pMem[k][j]);
              }
              temp.pMem[i][j] = res;
          }
      }
      return temp;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++)
      {
          for (int j = 0; j < v.sz; j++)
          {
              T value{};
              istr >> value;
              if (j >= i) v.pMem[i][j] = value;
          }
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
      {
          for (size_t j = 0; j < v.sz; j++) {
              ostr << v.pMem[i][j] << ' ';
          }
          ostr << '\n';
      }
      return ostr;
  }
};

#endif
