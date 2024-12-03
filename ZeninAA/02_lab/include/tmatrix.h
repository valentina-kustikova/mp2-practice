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
      if (sz <= 0)
          throw out_of_range("Vector size should be greater than zero");
      if (sz > MAX_VECTOR_SIZE)
          throw out_of_range("The size of the vector should be less than max vector size");
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
      for (int i = 0; i < sz; i++) {
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
      delete[] this->pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v)
      {
          return *this;
      }
      if (this->sz != v.sz)
      {
          delete[] this->pMem; 
          this->sz = v.sz;
          this->pMem = new T[this->sz];
      }

      for (int i = 0; i < this->sz; i++) {
          this->pMem[i] = v.pMem[i];
      }
      return *this;
  
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      if (this == &v)
      {
          return *this;
      }
      sz = v.sz;
      pMem = v.pMem;
      v.pMem = nullptr;
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
      if (ind >= sz || ind < 0)
      {
          throw "OUT OF RANGE INDEX";
      }
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind >= sz || ind < 0)
      {
          throw "OUT OF RANGE INDEX";
      }
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) {
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
  TDynamicVector operator+(T val) const
  {
      TDynamicVector tmp(sz);
      for (int i = 0; i < sz; i++)
      {
          tmp.pMem[i] = val + pMem[i];
      }
      return tmp;
  }
  TDynamicVector operator-(T val) const
  {
      TDynamicVector tmp(sz);
      for (int i = 0; i < sz; i++)
      {
          tmp.pMem[i] = pMem[i] - val;
      }
      return tmp;
  }
  TDynamicVector operator*(T val) const
  {
      TDynamicVector tmp(sz);
      for (int i = 0; i < sz; i++)
      {
          tmp.pMem[i] = val * pMem[i];
      }
      return tmp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v) const  
  {
      if (sz != v.sz) { 
          throw "VECTORS WITH DIF SIZE";
      }
      TDynamicVector tmp(sz);  
      for (int i = 0; i < sz; i++) {  
          tmp.pMem[i] = pMem[i] + v.pMem[i];  
      } 
      return tmp;   


      
  }
  TDynamicVector operator-(const TDynamicVector& v) const 
  {

      if (sz != v.sz) {
          throw "VECTORS WITH DIF SIZE";
      }
      TDynamicVector tmp(sz);
      for (int i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] - v.pMem[i];
      }
      return tmp;
         
      
  }
  T operator*(const TDynamicVector& v) const
  {
      if (sz != v.sz) {
          throw "VECTORS WITH DIF SIZE";
      } 
      T tmp = T(0);
      for (int i = 0; i < sz; i++) {
          tmp += pMem[i] * v.pMem[i];
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
  TDynamicMatrix(const TDynamicVector<TDynamicVector<T>>& m) : TDynamicVector<TDynamicVector<T>>(m) {}
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if (sz >= MAX_MATRIX_SIZE || sz <= 0) {
          throw out_of_range("The size of matrix should be greater than zero and less than 10000");
      }
      for (size_t i = 0; i < sz; i++) {
      pMem[i] = TDynamicVector<T>(sz-i);
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
      TDynamicMatrix tmp(sz);
      for (int i = 0; i < sz; i++) { 
          tmp.pMem[i] = pMem[i] * val;  
      } 
      return tmp;
      
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
              tmp[i] += pMem[i][j] * v[i+j];    
          }
      }
      return tmp;
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
      cout << "Write the size of matrix: "; 
      istr >> v.sz; 
      for (int i = 0; i < v.sz; i++)
      {
          for (int j = 0; j < v.sz - i; j++)
          {
              cout << "Write the number of element: " << i + 1 << "," << j + 1 << " : ";
              istr >> v.pMem[i][j];
          }
      }
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++) {
          for (int j = v.sz - 1; j >= 0; j--) {
              if (j >= v.sz - i) {
              ostr << " ";
              continue;
              }
              ostr << v[i][j] << " ";
          }
          ostr << '\n';
      }
      return ostr;
      
      
      /*for (int i = 0; i < v.sz; i++) {
          for (int j = 0; j < v.sz; j++) {
              
              if (i + j >= v.sz - 1) {
                  ostr << v.pMem[i * v.sz + j] << " "; 
              }
              else {
                  ostr << "0 "; 
              }
          }
          ostr << endl; 
      }
      return ostr;*/ 
      /*for (int i = 0; i < v.sz; i++)
      {
          for (int j = 1; j < v.sz; j++)  
          {
              for (int k = 0; k < sz - j; k++)  
              {
                  if (v[i][k] > v[i][k + 1]) 
                  {
                      int temp = v[i][k];  
                      v[i][k] = v[i][k + 1];
                      v[i][k + 1] = temp; 
                  }
              }
          }
      }*/
      
  }
};

#endif
