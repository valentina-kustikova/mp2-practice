#ifndef _TMONOM_
#define _TMONOM_

#include <iostream>
#include <map>

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

	const TMonom& operator=(const TMonom& monom);

	TMonom def_X();
	TMonom def_Y();
	TMonom def_Z();

	double calculate(std::map<char, double>& xyz);

	friend std::ostream& operator<<(std::ostream out, TMonom& monom);
	friend std::istream& operator>>(std::istream in, TMonom& monom);
};

#endif