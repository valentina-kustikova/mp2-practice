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

template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
    if (sz <= 0 || sz > MAX_VECTOR_SIZE)
      throw "Vector size should be greater than zero and less than max size";
    pMem = new T[sz]();
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    if(arr == nullptr)
        throw "index = nullptr";
    pMem = new T[sz];
    copy(arr, arr + sz, pMem);
  }

  TDynamicVector(const TDynamicVector& v) : sz(v.sz)
  {
      pMem = new T[sz];
      for (int i = 0; i < sz; i++)
          pMem[i] = v.pMem[i];
  }
 
  /*TDynamicVector(TDynamicVector&& v)noexcept : sz(v.sz), pMem(v.pMem)
  {
      this->pMem = v.pMem;
      v.pMem = nullptr;
      this->sz = v.sz;
      v.sz = 0;
  }*/
  ~TDynamicVector()
  {
      delete[] pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v)
          return *this;
      if (sz != v.sz) {
          delete[] pMem;
          sz = v.sz;
          pMem = new T[sz];
      }     
      for(int i = 0; i< sz;i++)
          pMem[i] = v.pMem[i];
      return *this;
  }
  //TDynamicVector& operator=(TDynamicVector&& v) noexcept // todo: swap - done
  //{
  //    swap(*this, v);
  //    return *this;
  //}

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
      if (ind <0 || ind >= sz)
          throw "Index does not exist";
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind < 0 || ind >= sz)
          throw "Index does not exist";
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) 
          return false;
          //throw "indexes do not match";
      for (size_t i = 0; i < sz; i++)
      {
          if (pMem[i] != v.pMem[i])
              return false;
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
      for (size_t i = 0; i < sz; i++)
      {
          result.pMem[i] = this->pMem[i] + val;
      }
      return result;
  }
  
  TDynamicVector operator-(T val)
  {
      TDynamicVector result(sz);
      for (size_t i = 0; i < sz; i++)
      {
          result.pMem[i] = this->pMem[i] - val;
      }
      return result;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector result(sz);
      for (size_t i = 0; i < sz; i++)
      {
          result.pMem[i] = this->pMem[i] * val;
      }
      return result;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v) const
  {
      TDynamicVector<T> result(sz);
      if (sz != v.sz)
          throw "different sizes";
      for (size_t i = 0; i < sz; i++)
      {
          result.pMem[i] = this->pMem[i] + v.pMem[i];
      }
      return result;
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
  }

  T operator*(const TDynamicVector& v)
  {
      if (this->sz != v.sz) {
          throw "different sizes";
      }
 
      T result(0);
      for (size_t i = 0; i < sz; i++)
      {
          result += this->pMem[i] * v.pMem[i]; 
      }
      return result;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    swap(lhs.sz, rhs.sz);
    swap(lhs.pMem, rhs.pMem);
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
    if (sz == 0 || sz > MAX_MATRIX_SIZE)
          throw "invalid size";
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz-i); // sz-i
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::size;
  using TDynamicVector<TDynamicVector<T>>::at;

  TDynamicMatrix(const TDynamicMatrix<T>& m): TDynamicVector<TDynamicVector<T>>(m){}
  TDynamicMatrix(const TDynamicVector<TDynamicVector<T>>& v) : TDynamicVector<TDynamicVector<T>>(v) {}

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
      for (size_t i = 0; i < sz; i++) {
          for (size_t j = 0; j < sz - i; j++) {
              result[i][j] = this->pMem[i][j] * val;
          }
      }
      return result;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v) 
  {
      if (sz != v.size()) {
          throw "different sizes";
      }
      TDynamicVector<T> result(sz);
      for (size_t i = 0; i < sz; i++) {
          result[i] = 0; 
          for (size_t j = 0; j < sz-i; j++) {
              result[i] += pMem[i][j] * v[i+j];
          }
      }
      return result;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {    
      /*
      if (sz != m.sz) {
          throw "different sizes";
      }
      TDynamicMatrix result(sz);
      for (size_t i = 0; i < sz; i++) {
          for (size_t j = i ; j < sz; j++) {
              result[i][j] = this->pMem[i][j] + m.pMem[i][j];
          }
      }

      return result;
      */

      return TDynamicVector<TDynamicVector<T>>::operator+(m);
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m) 
  {
      /*
      if (sz != m.sz) {
          throw "different sizes";
      }
      TDynamicMatrix result(sz);
      for (size_t i = 0; i < sz; i++) {
          for (size_t j = i; j < sz; j++) {
              result[i][j] = this->pMem[i][j] - m.pMem[i][j];
          }
      }
      return result;
      */
      return TDynamicVector<TDynamicVector<T>>::operator-(m);
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m) {
      if (this->sz != m.sz) {
          throw "different sizes";
      }
      TDynamicMatrix result(sz); 
      for (size_t i = 0; i < sz; i++) {
          for (size_t j = 0; j < sz-i; j++) { 
              result[i][j] = 0; 
              for (size_t k = 0; k < j+1; k++) { 
                  result[i][j] += this->pMem[i][k] * m[k+i][j-k];
              }
          }
      }
      return result;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++) {
          for (size_t j = 0; j < v.sz; j++) {
              istr >> v.pMem[i][j];
          }
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++) {
          for (size_t j = 0; j < v.sz; j++) {
              ostr << v.pMem[i][j] << ' ';
          }
          ostr << endl;
      }
      return ostr;
  }

};


#endif