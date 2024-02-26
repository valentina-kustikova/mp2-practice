#ifndef _TMONOM_
#define _TMONOM_
#include "tdata.h"

class TMonom : public TData {
private:
	double coeff;
	int degree;
public:
	TMonom();
	TMonom(const TMonom& monom);
	TMonom(double coeff, int degree);
	virtual TData* copy()const;
	virtual bool operator<(const TData& data) const;
	virtual bool operator>(const TData& data) const;
	virtual bool operator==(const TData& data) const;
	virtual bool operator!=(const TData& data) const;
};

#endif