#ifndef __MONOM_H__
#define __MONOM_H__

#include <iostream>

using namespace std;

class TMonom {
public:
	double coeff;
	int degree; 
	TMonom(const TMonom& monom);
	TMonom(double coef = 0, int deg = -1);
	bool operator<(const TMonom& monom)const;
	bool operator<=(const TMonom& monom)const;
	bool operator>(const TMonom& monom)const;
	bool operator>=(const TMonom& monom)const;
	bool operator==(const TMonom& monom)const;
	bool operator!=(const TMonom& monom)const;
	friend ostream& operator<<(ostream& out, const TMonom& m) {
		int x, y, z;
		x = m.degree / 100;
		y = m.degree / 10 % 10;
		z = m.degree % 10;
		if (m.degree == 0) {
			out << m.coeff;
		}
		else if (m.coeff != 1) {
			if (m.coeff == -1)
				out << "-";
			else {
				out << m.coeff;
				if (m.degree != 0)
					out << "*";
			}
		}
		if (x != 0) {
			out << "x";
			if (x > 1)
				out << "^" << x;
			if (y != 0 || z != 0)
				out << "*";
		}
		if (y != 0) {
			out << "y";
			if (y > 1)
				out << "^" << y;
			if (z != 0)
				out << "*";
		}
		if (z != 0) {
			out << "z";
			if (z > 1)
				out << "^" << z;
		}
		return out;
	}
};

#endif