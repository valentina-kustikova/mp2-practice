#include "tlist.h"
#include "tpolynom.h"
#include <iostream>
#include <string>

int main() {
  std::string P = "5*x^3*y^1-2.5*y^2";
  TPolynom polynomian = TPolynom(P);
  polynomian.monoms.Reset();
  while (!polynomian.monoms.IsEnded()) {
    polynomian.monoms.pCurr->data->output_data();
    polynomian.monoms.Next();
  }

  return 0;
}