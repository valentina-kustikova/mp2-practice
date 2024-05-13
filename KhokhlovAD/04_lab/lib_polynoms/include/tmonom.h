#ifndef _TMONOM_
#define _TMONOM_

#include <iostream>
#include <map>
#include <string>

using namespace std;

class TMonom {
private:
	double coeff;
	int degree;
public:
	TMonom();
	TMonom(const TMonom& monom);
	TMonom(double coeff, int degree);
	TMonom(const string& monom);

	void SetCoeff(const double cf);
	void SetDegree(const int dgr);
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

	double calculate(double x, double y, double z);

	friend std::ostream& operator<<(std::ostream out, TMonom& monom);
	friend std::istream& operator>>(std::istream in, TMonom& monom);
};

#endif