#ifndef _TMONOM_H
#define _TMONOM_H
#include <iostream>
#include <string>

using namespace std;
class TMonom {
public:
	double coeff;
	int wrap_degree;

	TMonom(double c_val = 0, int wd_val = -1);
	TMonom(const TMonom& mon);

	bool operator<(const TMonom& monom)const;
	bool operator<=(const TMonom& monom)const;
	bool operator!=(const TMonom& monom)const;
	bool operator==(const TMonom& monom)const;
	TMonom operator*(const TMonom& monom);
	TMonom operator+(const TMonom& monom);
	TMonom& operator+=(const TMonom& monom);
	TMonom operator-();

	friend ostream& operator<<(ostream& ostr, const TMonom& monom);
	friend istream& operator>>(istream& istr, TMonom& monom);
};


#endif