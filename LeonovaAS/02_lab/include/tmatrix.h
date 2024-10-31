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
      throw out_of_range("Vector size should be greater than zero and less than 100000000");
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
  {
      sz = v.sz;
      pMem = v.pMem;
      v.sz = 0;
      v.pMem = nullptr;
  }
  ~TDynamicVector()
  {
      delete[]this->pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v)
      {
          return* this;
      }
      if (sz != v.sz)
      {
          delete[]this->pMem;
          sz = v.sz;
          pMem = new T[sz];
      }
      for (int i = 0; i < sz; i++)
      {
          pMem[i] = v.pMem[i];
      }
      return* this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      if (this == &v)
      {
          return *this;
      }
      sz = v.sz;
      pMem = v.pMem;
      v.sz = 0;
      v.pMem = nullptr;
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
      if (ind < 0 || ind >= sz)
      {
          throw "idx is out of range!";
      }
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind < 0 || ind >= sz)
      {
          throw "idx is out of range!";
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
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
      {
          res.pMem[i] = val + pMem[i];
      }
      return res;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
      {
          res.pMem[i] = pMem[i] - val;
      }
      return res;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
      {
          res.pMem[i] = val * pMem[i];
      }
      return res;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz)
      {
          throw "Vectors have different dim";
      }
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++)
      {
          res.pMem[i] = pMem[i] + v.pMem[i];
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
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      if (sz != v.sz)
      {
          throw "Vectors have different dim";
      }
      T res = T(0);
      for (int i = 0; i < sz; i++)
      {
          res += pMem[i] * v.pMem[i];
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
      if (sz <= 0 || sz >= MAX_MATRIX_SIZE)
      {
          throw out_of_range("Matrix size should be greater than zero and less than 10000");
      }
      for (size_t i = 0; i < sz; i++)
        pMem[i] = TDynamicVector<T>(sz); // sz - i
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::size;
  using TDynamicVector<TDynamicVector<T>>::at;

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      //return TDynamicVector<TDynamicVector<T>>::operator==(m);
      if (sz == m.sz)
      {
          for (int i = 0; i < sz; i++)
          {
              if (pMem[i] != m.pMem[i])
              {
                  return 0;
              }
          }
          return 1;
          
      }
      return 0;
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++)
      {
          res.pMem[i] = pMem[i] * val;
      }
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.sz)
      {
          throw "Matrix and vector have different dim!"
      }
      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++)
      {
          res.pMem[i] = pMem[i] * v[i];
      }
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
      {
          throw "Matrices have different dim!";
      }
      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++)
      {
          res.pMem[i] = pMem[i] + m.pMem[i];
      }
      return res;
      
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
      {
          throw "Matrices have different dim!";
      }
      TDynamicMatrix res(sz);
      for (int i = 0; i < sz; i++)
      {
          res.pMem[i] = pMem[i] - m.pMem[i];
      }
      return res;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      TDynamicMatrix res(sz);
      if (sz != m.sz)
      {
          throw "Matrices have different dim!";
      }
      for (int i = 0; i < sz; i++)
      {
          for (int j = 0; j < sz; j++)
          {
              res.pMem[i] = res.pMem[i] + pMem[j] * m.pMem[i][j];
          }
      }
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      cout << "Enter dim of the matrix: ";
      istr >> v.sz;
      for (int i = 0; i < v.sz; i++)
      {
          for (int j = 0; j < v.sz; j++)
          {
              cout << "Enter element num " << i+1 << "," << j+1 << " : ";
              istr >> v.pMem[i][j];
          }
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (int i = 0; i < v.size(); i++)
      {
              ostr << v.pMem[i] << " "<< endl;
      }
      return ostr;
  }
};

#endif
