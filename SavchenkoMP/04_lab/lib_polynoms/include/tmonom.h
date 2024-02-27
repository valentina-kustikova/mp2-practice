#ifndef TMONOM_H
#define TMONOM_H

#include <iostream>

using namespace std;

class TMonom{
private:
	double coeff;
	int degree;
public:
	TMonom();
	TMonom(const TMonom& monom);
	TMonom(double _coeff, int _degree);

	virtual bool operator<(const TMonom& data) const;
	virtual bool operator>(const TMonom& data) const;
	virtual bool operator==(const TMonom& data) const;
	virtual bool operator!=(const TMonom& data) const;
};

#endif // !TMONOM_H
