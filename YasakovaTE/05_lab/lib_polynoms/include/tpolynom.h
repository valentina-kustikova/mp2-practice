#pragma once

#include <iostream>
#include <string>
#include <cstdio>
#include "tmonom.h"
#include "list.h"
#include "headlist.h"
using namespace std;

class TPolynom {
protected:
  string name;
  headlist<TMonom> monoms;

  void smash_pol(const string& name);//разбитие полинома на мономы
  bool check(const string& name);//содержит ли строка только допустимые символы
  void InsertToSort(const TMonom& monom);//сортировка мономов в порядке убывания степени
public:
  TPolynom() : monoms() {}
  TPolynom(const string& name);
  TPolynom(const headlist<TMonom>& l);
  TPolynom(const TPolynom& p);
  ~TPolynom() = default;
  
  TPolynom operator-() const;
  TPolynom operator+(const TPolynom& p);
  TPolynom operator-(const TPolynom& p);
  TPolynom operator*(const TPolynom& p);
  bool operator==(const TPolynom& p) const;
  
  string TPolynom::ToString() const;

  double operator()(double x, double y, double z) const;
  TPolynom dx() const;
  TPolynom dy() const;
  TPolynom dz() const;

  const TPolynom& operator=(const TPolynom& p);

  friend ostream& operator<<(ostream& out, const TPolynom& p) {
	  out << p.ToString() << endl;
	  return out;
  }

};

