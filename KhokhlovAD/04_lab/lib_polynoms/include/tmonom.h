#ifndef _TMONOM_
#define _TMONOM_

#include <iostream>

class TMonom {
private:
	double coeff;
	int degree;
public:
	TMonom(const TMonom& monom);
	TMonom(double coeff = 1, int degree = 0);

	double GetCoeff()const { return coeff; }
	int GetDegree()const { return degree; }

	bool operator<(const TMonom& data) const;
	bool operator>(const TMonom& data) const;
	bool operator==(const TMonom& data) const;
	bool operator!=(const TMonom& data) const;

	TMonom operator+(const TMonom& data);
	TMonom operator-(const TMonom& data);
	TMonom operator*(const TMonom& data);

	TMonom def_X();
	TMonom def_Y();
	TMonom def_Z();
};

#endif