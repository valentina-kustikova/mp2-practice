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

	TMonom def_X()const; 
	TMonom def_Y()const; 
	TMonom def_Z()const; 

	double operator()(double x, double y, double z)const; 

	friend std::ostream& operator<<(std::ostream& out, TMonom& monom)
	{
		int x, y, z;
		x = monom.degree / 100;
		y = (monom.degree % 100) / 10;
		z = monom.degree % 10;
		if (monom.coeff == 0)
			return out << "0";
		if (monom.coeff > 0)
			out << "+";
		out << monom.coeff;
		if (x == 1)
			out << "*x";
		else  if (x > 0)
			out << "*x^" << x;
		if (y == 1)
			out << "*y";
		else  if (y > 0)
			out << "*y^" << y;
		if (z == 1)
			out << "*z";
		else  if (z > 0)
			out << "*z^" << z;
		return out;

	}

	friend std::istream& operator>>(std::istream in, TMonom& monom);
};

#endif