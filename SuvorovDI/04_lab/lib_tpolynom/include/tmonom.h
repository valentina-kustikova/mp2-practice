#pragma once

#include <iostream>
#include "tlist.h" //????
#include <stdint.h>

class TMonom {
public:
  double coeff_;
  int16_t degree_;

  TMonom();
  TMonom(double coeff, int16_t degree);
  bool operator<(const TMonom&) const;
  bool operator<=(const TMonom&) const;
  bool operator>(const TMonom&) const;
  bool operator>=(const TMonom&) const;
  bool operator==(const TMonom&) const;
  bool operator!=(const TMonom&) const;

  friend std::ostream& operator<< (std::ostream& out, const TMonom& m) {
    out << m.coeff_ << "  " << m.degree_ << std::endl;
	  return out;
  }
};