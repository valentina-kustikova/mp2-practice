#pragma once

#include <iostream>
#include <string>
#include "tmonom.h"
#include "tlist.h"
#include "theadringlist.h"

// move TMonom and TPolynom to different files
// I should make these files into VS Code

// Add operator unaryminus!
class TPolynom {
protected:
  std::string name;

  void tokinize_polynom(const std::string& name);
  void InsertToSort(const TMonom& monom);

public:
  THeadRingList<TMonom> monoms;

  TPolynom() : monoms() {}
  TPolynom(const std::string& name);
  TPolynom(const THeadRingList<TMonom>& l);
  TPolynom(const std::string& name, const TPolynom& p);
  TPolynom(const TPolynom& p);
  ~TPolynom() = default;
  
  friend TPolynom operator-(const TPolynom& i);
  TPolynom operator+(const TPolynom& p);
  TPolynom operator-(const TPolynom& p);
  TPolynom operator*(const TPolynom& p);

  const std::string& GetName() const {return name;}

  double operator()(double x, double y, double z) const;
  TPolynom dx() const;
  TPolynom dy() const;
  TPolynom dz() const;

  const TPolynom& operator=(const TPolynom& p);

  friend std::ostream& operator<< (std::ostream& out, TPolynom& pol) {
	  pol.monoms.Reset();
    while (!pol.monoms.IsEnded()) {
		  out << pol.monoms.GetCurr()->data;
		  pol.monoms.Next();
    }
	  return out;
  }
};

