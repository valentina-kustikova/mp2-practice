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
        if (sz == 0 || sz >= MAX_VECTOR_SIZE) {
            throw out_of_range("Vector size should be greater than zero");
        }
        pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
    }
    TDynamicVector(T* arr, size_t s) : sz(s)
    {
        assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
        pMem = new T[sz]();
        std::copy(arr, arr + sz, pMem);
    }
    TDynamicVector(const TDynamicVector& v)
    {
        sz = v.sz;
        pMem = new T[sz]();
        for (int i = 0; i < sz; ++i) {
            pMem[i] = v.pMem[i];
        }
    }
    TDynamicVector(TDynamicVector&& v) noexcept
    {
        sz = v.sz;
        pMem = v.pMem;
        v.pMem = nullptr;
        v.sz = 0;
    }
    ~TDynamicVector()
    {
        delete[] pMem;
    }
    TDynamicVector& operator=(const TDynamicVector& v)
    {
        if (this == &v) {
            return *this;
        }
        if (sz != v.sz) {
            sz = v.sz;
            delete[] pMem;
            pMem = new T[sz]();
        }
        for (int i = 0; i < sz; ++i) {
            pMem[i] = v.pMem[i];
        }
        return *this;
    }
    TDynamicVector& operator=(TDynamicVector&& v) noexcept
    {
        if (this == &v) {
            return *this;
        }
        delete[] pMem;
        sz = v.sz;
        pMem = v.pMem;
        v.pMem = nullptr;
        v.sz = 0;
        return *this;
    }

    size_t size() const noexcept {
        return sz;
    }

    // индексация
    T& operator[](size_t ind)
    {
        if (ind >= sz) {
            throw std::out_of_range("0");
        }
        return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind >= sz) {
          throw std::out_of_range("0");
      }
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind >= sz) {
          throw std::out_of_range("0");
      }
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (this == &v) {
          return 1;
      }
      if (sz != v.sz) {
          return 0;
      }
      for (int i = 0; i < sz; ++i) {
          if (pMem[i] != v.pMem[i]) {
              return 0;
          }
      }
      return 1;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(this == &v);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      if (val != 0) {
          for (int i = 0; i < sz; ++i) {
              pMem[i] += val;
          }
      }
      return *this;
  }
  TDynamicVector operator-(T val)
  {
      if (val != 0) {
          for (int i = 0; i < sz; ++i) {
              pMem[i] -= val;
          }
      }
      return *this;
  }
  TDynamicVector operator*(T val)
  {
      for (int i = 0; i < sz; ++i) {
          pMem[i] *= val;
      }
      return *this;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      TDynamicVector result(sz);
      if (sz != v.sz) {
          throw std::exception("0");
      }
      else {
          for (int i = 0; i < sz; ++i) {
              result.pMem[i] = pMem[i] + v.pMem[i];
          }
      }
      return result;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      TDynamicVector result(sz);
      if (sz != v.sz) {
          throw std::exception("0");
      }
      else {
          for (int i = 0; i < sz; ++i) {
              result.pMem[i] = pMem[i] - v.pMem[i];
          }
      }
      return result;
  }
  //T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  T operator*(const TDynamicVector& v)
  {
      T result = T();
      if (sz != v.sz) {
          throw std::exception("0");
      }
      for (int i = 0; i < sz; ++i) {
          result += pMem[i] * v.pMem[i];
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
      if (sz >= MAX_MATRIX_SIZE) {
          throw std::exception("0");
      }
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz-i);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];
  using TDynamicVector<TDynamicVector<T>>::size;
  //using TDynamicVector<TDynamicVector<T>>::at;

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      if (sz != m.sz) {
          return 0;
      }
      for (size_t i = 0; i < sz; ++i) {
          for (size_t j = 0; j < pMem[i].size(); ++j) {
              if (pMem[i][j] != m.pMem[i][j]) {
                  return 0;
              }
          }
      }
      return 1;

  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix result(sz);
      if (val != 0) {
          for (size_t i = 0; i < sz; ++i) {
              for (size_t j = 0; j < pMem[i].size(); ++j) {
                  result.pMem[i][j] = pMem[i][j] * val;
              }
          }
      }
      return result;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.sz) {
          throw std::exception("0");
      }
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; ++i) {
          T sum(0);
          for (size_t j = 0; j < pMem[i].size(); ++j) {
              sum += pMem[i][j] * v[j];
          }
          res[i] = sum;
      }
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz) {
          throw std::exception("0");
      }
      TDynamicMatrix res(sz);
      for (size_t i = 0; i < sz; ++i) {
          for (size_t j = 0; j < pMem[i].size(); ++j) {
              res[i][j] = pMem[i][j] + m.pMem[i][j];
          }
      }
      return res;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz) {
          throw std::exception("0");
      }
      TDynamicMatrix res(sz);
      for (size_t i = 0; i < sz; ++i) {
          for (size_t j = 0; j < pMem[i].size(); ++j) {
              res[i][j] = pMem[i][j] - m.pMem[i][j];
          }
      }
      return res;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      TDynamicMatrix res(sz);
      for (size_t i = 0; i < sz; ++i) {
          for (size_t j = 0; j < pMem[i].size(); ++j) {
              res[i][j] = pMem[i][j] * m.pMem[i][j];
          }
      }
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; ++i) {
          for (size_t j = 0; j < v.pMem[i].size(); ++j) {
              istr >> v.pMem[i][j];
          }
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; ++i) {
          for (size_t j = 0; j < v.pMem[i].size(); ++j) {
              ostr << v.pMem[i][j]<<"\t";
          }
          ostr << std::endl;
      }
      return ostr;
  }
};

#endif
