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
    if (sz>MAX_VECTOR_SIZE) {
        throw out_of_range("Vector size should be greater than zero or lesser than max. size.");
    }
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
      this->pMem = new T[sz];
      for (int i = 0; i < sz; i++) {
          this->pMem[i] = v.pMem[i];
      }
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
      this->pMem = nullptr;
      swap(*this, v);
  }
  ~TDynamicVector()
  {
      delete[] this->pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v) {
          return *this;
      }
      if (this->sz != v.sz) {
          delete [] pMem;
          this->sz = v.sz;
          this->pMem = new T [sz];
      }
      for (int i = 0; i < sz; i++) {
          this->pMem[i] = v.pMem[i];
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      swap(*this, v);
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      if (ind < 0 || ind >= this->sz || ind > MAX_VECTOR_SIZE) {
          throw ind;
      }
      return (this->pMem[ind]);
  }
  const T& operator[](size_t ind) const
  {
      if (ind < 0 || ind >= this->sz || ind > MAX_VECTOR_SIZE) {
          throw ind;
      }
      return (this->pMem[ind]);
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind < 0 || ind >= this->sz || ind > MAX_VECTOR_SIZE) {
          throw ind;
      }
      return (this->pMem[ind]);
  }
  const T& at(size_t ind) const
  {
      if (ind < 0 || ind >= this->sz || ind > MAX_VECTOR_SIZE) {
          throw ind;
      }
      return (this->pMem[ind]);
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (this->sz != v.sz) {
          return 0;
      }
      for (int i = 0; i < this->sz; i++) {
          if (this->pMem[i] != v.pMem[i]) {
              return 0;
          }
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
      TDynamicVector<T> res(this->sz);
      for (int i = 0; i < this->sz; i++) {
          res.pMem[i] = this->pMem[i] + val;
      }
      return res;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector<T> res(this->sz);
      for (int i = 0; i < this->sz; i++) {
          res.pMem[i] = this->pMem[i] - val;
      }
      return res;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector<T> res(this->sz);
      for (int i = 0; i < this->sz; i++) {
          res[i] = val * this->pMem[i];
      }
      return res;
  }
  TDynamicVector operator*(T val) const
  {
      TDynamicVector<T> res(this->sz);
      for (int i = 0; i < this->sz; i++) {
          res[i] = this->pMem[i] * val;
      }
      return res;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)  const
  {
      if (this->sz != v.sz) {
          throw("Wrong size of vectors.");
      }
      TDynamicVector<T> res(this->sz);
      for (int i = 0; i < this->sz; i++) {
          res[i] = this->pMem[i] + v.pMem[i];
      }
      return res;
  }
  TDynamicVector operator-(const TDynamicVector& v) 
  {
      if (sz != v.sz)
      {
          throw "Vectors have different dim";
      }
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
      {
          res.pMem[i] = pMem[i] - v.pMem[i];
      }
      return res;
      // return *this + v * (-1);
  }
  T operator*(const TDynamicVector& v)
  {
      if (this->sz != v.size()) {
          throw("Wrong size of vectors.");
      }
      T res =  T();
      // T res = 0;
      for (int i = 0; i < this->sz; i++) {
          res += this->pMem[i] * v.pMem[i];
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
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if (s < 0 || s > MAX_MATRIX_SIZE) {
          throw "Incorrect Matrix size.";
      }
      for (size_t i = 0; i < sz; i++) {
          pMem[i] = TDynamicVector<T>(sz - i);
      }
  }

  TDynamicMatrix(const TDynamicMatrix<T>& m) : TDynamicVector <TDynamicVector<T>>(m) {

  }
  TDynamicMatrix(const TDynamicVector<TDynamicVector<T>>& v) : TDynamicVector <TDynamicVector<T>>(v) {

  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      return TDynamicVector <TDynamicVector<T>>::operator== (m);
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      return TDynamicVector <TDynamicVector<T>>::operator* (val);
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (this->sz != v.size())
      {
          throw "Different sizes.";
      }
      TDynamicVector<T> res(v.size());
      for (int i = 0; i < v.size(); i++)
      {
          res[i] = 0;
          for (int j = 0; j < res.size() - i; j++)
          {
              res[i] += pMem[i][j] * v[j + i];
          }
      }
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      return TDynamicVector <TDynamicVector<T>>::operator+ (m);
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      return TDynamicVector <TDynamicVector <T>>::operator- (m);
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (this->sz != m.sz) {
          throw "Matrices have different sizes.";
      }
      TDynamicMatrix res(this->size());
      for (int i = 0; i < this->size(); i++) {
          for (int j = 0; j < this->size() - i; j++) {
              res.pMem[i][j] = 0;
              for (int k = 0; k < j + 1; k++)
              {
                  res.pMem[i][j] += this->pMem[i][k] * m.pMem[k+i][j-k];
              }
          }
      }
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          istr >> v.pMem[i];
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++) {
          for (int j = 0; j < i; j++) {
             ostr << "0 ";
          }
          ostr << v.pMem[i] << "\n";
      }
      return ostr;
  }
};

#endif