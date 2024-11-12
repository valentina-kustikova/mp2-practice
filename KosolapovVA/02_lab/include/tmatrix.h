// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include <cassert>
#include <iomanip>

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
    if (sz <= 0)
      throw out_of_range("Vector size should be greater than zero");
    if (sz > MAX_VECTOR_SIZE)
        throw out_of_range("The size of the vector cannot exceed the max vector size");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v):sz(v.sz)
  {
      pMem = new T[sz];
      for (int i = 0; i < sz; i++)
      {
          pMem[i] = v.pMem[i];
      }
  }
  TDynamicVector(TDynamicVector&& v) noexcept : sz(v.sz)
  {
      v.sz = 0;
      this->pMem = v.pMem;
      v.pMem = nullptr;
  }
  ~TDynamicVector()
  {
      delete[] pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v)
          return *this;
      if (sz != v.sz)
      {
          this->sz = v.sz;
          delete[]this->pMem;
          this->pMem = new T[sz];
      }
      for (int i = 0; i < sz; i++)
          this->pMem[i] = v.pMem[i];                                             
      return *this;
  }

  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      if (this == &v) 
          return *this;
      this->sz = v.sz;
      v.sz = 0;
      this->pMem = v.pMem;
      v.pMem = nullptr;
      return *this;
  }
  

  size_t size() const noexcept { return sz; }

  //индексация
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
      if (ind<0 || ind>sz - 1)
          throw std::exception("Incorrect index");
      return(this->pMem[ind]);
  }
  const T& at(size_t ind) const
  {
      if (ind<0 || ind>sz - 1)
          throw std::exception("Incorrect index");
      return(this->pMem[ind]);
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
          return 0;
      int temp = 0;
      for (int i = 0; i < v.sz; i++)
          if (this->pMem[i] == v.pMem[i])
              temp += 1;
      return(temp == sz);
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(*this==v);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector<T> temp(this->sz);
      for (int i = 0; i < this->sz; i++)
          temp.pMem[i] = this->pMem[i] + val;
      return temp;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector<T> temp(this->sz);
      for (int i = 0; i < this->sz; i++)
          temp.pMem[i] = this->pMem[i] - val;
      return temp;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector<T> temp(this->sz);
      for (int i = 0; i < this->sz; i++)
          temp.pMem[i] = this->pMem[i] * val;
      return temp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (this->sz != v.sz)
          throw std::exception("Dif vector size");
      TDynamicVector<T> temp(this->sz);
      for (int i = 0; i < this->sz; i++)
          temp.pMem[i] = this->pMem[i] + v.pMem[i];
      return temp;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (this->sz != v.sz)
          throw std::exception("Dif vector size");
      TDynamicVector<T> temp(this->sz);
      for (int i = 0; i < this->sz; i++)
          temp.pMem[i] = this->pMem[i] - v.pMem[i];
      return temp;
  }
  T operator*(const TDynamicVector& v) //noexcept(noexcept(T()))
  {
      if (this->sz != v.sz)
          throw std::exception("Dif vector size");
      T temp = this->pMem[0] * v.pMem[0];
      for (int i = 1; i < this->sz; i++)
          temp = temp + (this->pMem[i] * v.pMem[i]);
      return temp;
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
      ostr  <<'|' << setw(6) << v.pMem[i] << ' '; // требуется оператор<< для типа T
    ostr << '|';
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
//Переделать в верхне-треугольную
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if (sz <= 0)
          throw out_of_range("Matrix size should be greater than zero");
      if (sz > MAX_MATRIX_SIZE)
          throw out_of_range("The size of the matrix cannot exceed the max matrix size");
      for (size_t i = 0; i < sz; i++)
          pMem[i] = TDynamicVector<T>(sz-i);
  }
  TDynamicMatrix(TDynamicVector<TDynamicVector<T>> v) : TDynamicVector<TDynamicVector<T>>(v)
  {
      if (sz <= 0)
          throw out_of_range("Matrix size should be greater than zero");
      if (sz > MAX_MATRIX_SIZE)
          throw out_of_range("The size of the matrix cannot exceed the max matrix size");
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::size;

  T& at(size_t i1, size_t i2)
  {
      if (i1 < 0 || i1 >= sz || i2 < 0 || i2 >= sz) 
          throw "incorrect index";
      return this->pMem[i1][i2];
  }
  const T& at(size_t i1, size_t i2) const
  {
      if (i1 < 0 || i1 >= sz || i2 < 0 || i2 >= sz)
          throw "incorrect index";
      return this->pMem[i1][i2];
  }

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      if (this->sz != m.sz)
          return 0;
      int temp=0;
      for (int i = 0; i < this->sz; i++)
              if (this->pMem[i] != m.pMem[i])
                  return 0;                
      return 1;
  }
  bool operator!=(const TDynamicMatrix& m) const noexcept
  {
      return (!(*this == m));
  }
  
  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix<T> res(this->sz);
      for (int i = 0; i < this->sz; i++)
      {
          res.pMem[i] = this->pMem[i] * val;
      }
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (this->sz != v.sz)
          throw std::exception("Dif matrix size");
      TDynamicVector<T> res(v.sz);
      res.pMem[0] = this->pMem[0] * v;
      for (int i = 1; i < this->sz; i++)
      {
          T temp = 0;
          for (int j = 0; j < this->sz - i; j++)
          {
              temp = this->pMem[i][j] * v.pMem[i+j] + temp;
          }
          res.pMem[i] = 0;
      }
      return res;
  }

  // матрично-матричные операции
  ///*
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (this->sz != m.sz)
          throw std::exception("Dif matrix size");
      TDynamicMatrix<T> res(m.sz);
      for (int i = 0; i < this->sz; i++)
          res.pMem[i] = this->pMem[i] + m.pMem[i];
      return res;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (this->sz != m.sz)
          throw std::exception("Dif matrix size");
      TDynamicMatrix<T> res(m.sz);
      for (int i = 0; i < this->sz; i++)
          res.pMem[i] = this->pMem[i] - m.pMem[i];
      return res;
  }
  //*/
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (this->sz != m.sz)
          throw std::exception("Dif matrix size");
      TDynamicMatrix<T> res(m.sz);
      for (int i = 0; i < this->sz; i++)
      {
          for (int j = 0; j < this->sz - i; j++)
          {
              T temp = 0;
              for (int k = 0; k < j + 1; k++)
                  temp = (this->pMem[i][k] * m.pMem[k+i][j-k]) + temp;
              res.pMem[i][j] = temp;
          }
      }
      return res;
  }
  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      size_t msz;
      std::cout << "Enter matrix size: ";
      istr >> msz;
      TDynamicMatrix temp(msz);
      for (int i = 0; i < msz; i++)
      {
          std::cout << "Enter " << i << " line: ";
          istr >> temp.pMem[i];
          std::cout << "\n";
      }
      v = msz;
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++)
      {
          for (int j = v.sz - i; j < v.sz; j++)
              ostr << '|' << setw(7) << "0 ";
          ostr << v.pMem[i] << "\n";
      }          
      return ostr;
  }
};
#endif