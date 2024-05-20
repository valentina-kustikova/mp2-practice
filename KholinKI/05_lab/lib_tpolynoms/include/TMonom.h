#ifndef _TMONOM_H
#define _TMONOM_H
#include <iostream>
#include <string>

using namespace std;
class TMonom {
protected:
	double coeff;
	int wrap_degree;
public:
	TMonom(double c_val = 0, int wd_val = -1);
	TMonom(const TMonom& mon);

	bool operator<(const TMonom& monom)const;
	bool operator<=(const TMonom& monom)const;
	bool operator!=(const TMonom& monom)const;
	bool operator==(const TMonom& monom)const;
	TMonom operator*(const TMonom& monom);
	TMonom operator+(const TMonom& monom);
	TMonom& operator+=(const TMonom& monom);
	TMonom operator-(); // const

	int GetWP()const { return wrap_degree; }
	int GetCoeff()const { return coeff; }

	void SetCoeff(double c_val) { coeff = c_val; }
	void SetWP(int wp_val) { wrap_degree = wp_val; }

	friend ostream& operator<<(ostream& ostr, const TMonom& monom);
	friend istream& operator>>(istream& istr, TMonom& monom);
};


#endif