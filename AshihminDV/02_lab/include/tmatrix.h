// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

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
      pMem = nullptr;
      swap(*this, v);
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
      if (this == &v)
      {
          return *this;
      }
      if (this->sz != v.sz)
      {
          this->sz = v.sz;
          delete[]pMem;
          pMem = new T[this->sz];
      }
      for (int i = 0; i < this->sz; i++)
      {
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
  TDynamicVector operator*(T val) const
  {
      TDynamicVector<T> PR(this->sz);
      for (int i = 0; i < this->sz; i++) {
          PR[i] = pMem[i] * val;
      }
      return PR;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v) const// Добавил
  {

      if (this->sz != v.size()) {

          throw std::exception("NOT EQUAL SIZE");
      }

      TDynamicVector<T> SUMM(this->sz);

      for (int i = 0; i < this->sz; i++) {
          SUMM[i] = v[i] + this->pMem[i];
      }
      return SUMM;
  }
  TDynamicVector operator-(const TDynamicVector& v) // todo через +
  {
      return *this + v * (-1);
  }
  T operator*(const TDynamicVector& v) //noexcept(noexcept(T()))
  {
      if (this->sz != v.size()) {
          throw std::exception("NOT EQUAL SIZE");
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
        if (this->sz <= 0)
        {
            throw out_of_range("Matrix size should be greater than zero");
        }
        if (this->sz > MAX_MATRIX_SIZE)
        {
            throw out_of_range("TOO LARGE SIZE");
        }
        for (size_t i = 0; i < sz; i++)
            pMem[i] = TDynamicVector<T>(sz - i);
    }

    TDynamicMatrix(const TDynamicMatrix<T>& m) : TDynamicVector<TDynamicVector<T>>(m){}

    TDynamicMatrix(const TDynamicVector<TDynamicVector<T>>& v): TDynamicVector<TDynamicVector<T>>(v) {}
  
  using TDynamicVector<TDynamicVector<T>>::size;
  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::operator!=;

  T& at(size_t ind_str, size_t ind_sto)
  {
      if (ind_str <0 || ind_str > sz - 1 || ind_sto < 0 || ind_sto >sz - ind_str)
      {
          throw "Incorrect index";
      }
      return this->pMem[ind_str][ind_sto];
  }

  const T& at(size_t ind_str, size_t ind_sto) const
  {
      if (ind_str <0 || ind_str > sz - 1 || ind_sto < 0 || ind_sto >sz - ind_str)
      {
          throw "Incorrect index";
      }
      return this->pMem[ind_str][ind_sto];
  }

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      return TDynamicVector <TDynamicVector <T>>::operator== (m);
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val) // todo вызов базового
  {
      return TDynamicVector<TDynamicVector <T>>::operator* (val);
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (this->sz != v.size())
      {
          throw "Not equal matrixs sizes *";
      }
      TDynamicVector<T> ress(v.size());
      for (int i = 0; i < v.size(); i++)
      {
          ress[i] = 0;
          for (int j = 0; j < ress.size(); j++)
          {
              ress[i] += pMem[i][j] * v[j + i];
              //ress[i] += 12;
          }
      }
      return ress;
  }

  // матрично-матричные операции
  TDynamicMatrix<T> operator+ (const TDynamicMatrix<T>& m) {
      return TDynamicVector<TDynamicVector <T>>::operator+ (m);
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      return TDynamicVector<TDynamicVector <T>>::operator- (m);
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (this->sz != m.sz)
      {
          throw "DIFF LEN";
      }
      TDynamicMatrix<int> ress(m.sz);
      for (int i = 0; i < this->sz; i++)
      {
          for (int j = 0; j < this->sz - i; j++)
          {
              ress[i][j] = 0;
              for (int k = 0; k < j + 1; k++)
              {
                  ress[i][j] += (*this)[i][k] * m[k + i][j - k];
              }
          }
      }
      return ress;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      std::cout << "Enter the matrix";
      for (int i = 0; i < m.sz; i++)
      {
          istr >> m[i];
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++) {
          for (int j = 0; j < i; j++)
          {
              ostr << setw(6) <<" ";
          }
          for (int j = 0; j < v[i].size(); j++)
          {
              ostr << setw(6) << v[i][j];
          }
          ostr << std::endl;
      }
      return ostr;
  }
};

#endif
