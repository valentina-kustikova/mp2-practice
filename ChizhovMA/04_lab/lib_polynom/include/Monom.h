#ifndef _MONOM_H
#define _MONOM_H

#include <iostream>


using namespace std;

struct TMonom
{
	double coef;
	int degree;

	TMonom();
	TMonom(const TMonom& m);
	TMonom(double c, int d);

	virtual bool operator > (const TMonom& d) const;
	virtual bool operator < (const TMonom& d) const;
	virtual bool operator == (const TMonom& d) const;
	virtual bool operator != (const TMonom& d) const;

	friend ostream& operator<<(ostream& os, const TMonom& m)
	{
		os << m.coef << " " << m.degree;
		return os;
	}
};

#endif 
