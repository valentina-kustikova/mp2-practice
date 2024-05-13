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

	string ToString() const;

	friend ostream& operator<<(ostream& out, const TMonomial& m) {
		out << m.ToString();
		return out;
	}
};

#endif