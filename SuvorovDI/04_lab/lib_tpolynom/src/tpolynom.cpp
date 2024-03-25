#pragma once
#include "tpolynom.h"
#include "tlist.h"
#include <typeinfo>
#include <iostream>
#include <cmath>
#include <string>

TMonom::TMonom() {
  coeff_ = 0;
  degree_ = -1;
}

TMonom::TMonom(double coeff, int16_t degree) {
  coeff_ = coeff;
  degree_ = degree;
}

bool TMonom::operator<(const TMonom& data) const {
  return degree_ < data.degree_;
}

bool TMonom::operator<=(const TMonom& data) const {
  return degree_ <= data.degree_;
}

bool TMonom::operator>(const TMonom& data) const {
  return degree_ > data.degree_;
}

bool TMonom::operator>=(const TMonom& data) const {
  return degree_ >= data.degree_;
}

// Для приведения подобных
bool TMonom::operator==(const TMonom& data) const {
  return degree_ == data.degree_;
}

bool TMonom::operator!=(const TMonom& data) const {
  return degree_ != data.degree_;
}
