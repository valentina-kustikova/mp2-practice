#ifndef __POSTFIX_FORM_H__
#define __POSTFIX_FORM_H__

#include "stack.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

class ArExpression {

  string expr;

  bool isoperation(char) const;
  void Vector_Filling(vector<pair<char, double>>&) const;
  bool Mathematically_Correct(const string&) const;

public:
  explicit ArExpression(const string&);
  string GetPostfix() const;
  double Compute(const vector<pair<char, double>>&) const;
  friend istream& operator>>(istream& in, ArExpression& ae) {
    string s;
    if (getline(in, s)) {
      try {
        ae = ArExpression(s);
      }
      catch (const invalid_argument& e) {
        in.setstate(ios::failbit);
      }
    }
    return in;
  }
  friend ostream& operator<<(ostream& out, const ArExpression& ae) {
    out << ae.expr;
    return out;
  };
};

#endif __POSTFIX_FORM_H__