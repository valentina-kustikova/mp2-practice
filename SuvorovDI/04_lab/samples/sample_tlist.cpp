#include "tlist.h"
#include "tpolynom.h"
#include <iostream>
#include <string>

int main() {
  //std::string P = "-5*z*x^3*y^1+5*y^2+52.4*x^3*y";
  std::string P = "1+2*x^2-x^2*y";
  TPolynom polynomian = TPolynom(P);
  std::cout << polynomian;
  std::cout << polynomian.ToString() << "\n";
  std::cout << polynomian.dy();

  return 0;
}