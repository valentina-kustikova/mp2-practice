#ifndef _TM
#define _TM
#include "theadringlist.h"

class TMonomial {
public:
	double coef;
	short int degr;
	TMonomial() {
		coef = 0;
		degr = -1;
	};
	TMonomial(double d, short int i) {
		coef = d;
		degr = i;
	};

	bool operator<(const TMonomial& m) const {return degr < m.degr;};
	bool operator>(const TMonomial& m) const {return degr > m.degr;}
	bool operator<=(const TMonomial& m) const {return degr <= m.degr;}
	bool operator>=(const TMonomial& m) const {return degr >= m.degr;}
	bool operator==(const TMonomial& m) const {	return degr == m.degr;}
	bool operator!=(const TMonomial& m) const {	return degr != m.degr;}

	friend ostream& operator<<(ostream& out, const TMonomial& m) {
		double tmp = m.coef;
		if (tmp == 0 && tmp == 0) {
		out << tmp;
		return out;
		}
		if (tmp < 0)
		{
			tmp *= -1;
		}
		int x = m.degr / 100;
		int y = (m.degr % 100) / 10;
		int z = m.degr % 10;
		if ((tmp != 1) && (m.degr!=0)) {
			out << tmp;
			if ((x != 0) && (x != 1)) out << "*x^" << x;
			else if (x == 1) out << "*x";
			if ((y != 0) && (y != 1)) out << "*y^" << y;
			else if (y == 1) out << "*y";
			if ((z != 0) && (z != 1)) out << "*z^" << z;
			else if (z == 1) out << "*z";
			return out;
		}
		else if (m.degr != 0) {
			bool tmp1 = false;

			if (tmp1)
				out << "*";
			if ((x != 0) && (x != 1)) {
				out << "x^" << x;
				tmp1 = true;
			}
			else if (x == 1) {
				out << "x";
				tmp1 = true;
			}

			if ((y != 0) && (y != 1)){
				out << "y^" << y;
				tmp1 = true;
			}
			else if (y == 1){
				out << "y";
			tmp1 = true;
			}

			if ((z != 0) && (z != 1)){
				out << "z^" << x;
				tmp1 = true;
			}
			else if (z == 1) {
				out << "z";
				tmp1 = true;
			}
		}
		else if (m.degr == 0) {
			out << m.coef;
		}
	}
};

#endif