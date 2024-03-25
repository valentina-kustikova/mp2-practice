#include "tlist.h"
#include "tpolynom.h"
#include <iostream>
#include <string>

int main() {
  std::string P = "-5*z*x^3*y^1-2.5*y^2+52.4*x^3*z^7";
  TPolynom<TMonom> polynomian = TPolynom<TMonom>(P);
  polynomian.output_polynom();

  return 0;
}