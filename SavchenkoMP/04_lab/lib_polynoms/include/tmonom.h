#ifndef TMONOM_H
#define TMONOM_H

#include <iostream>
#include "tdata.h"

using namespace std;

class TMonom : public TData {
private:
	double coeff;
	int degree;
public:
	TMonom();
	TMonom(const TMonom& monom);
	TMonom(double _coeff, int _degree);

	virtual TData* copy() const;

	virtual bool operator<(const TData* data) const;
	virtual bool operator>(const TData* data) const;
	virtual bool operator==(const TData* data) const;
	virtual bool operator!=(const TData* data) const;
};

#endif // !TMONOM_H
