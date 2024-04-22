#ifndef _TMONOM_
#define _TMONOM_

class TMonom {
private:
	double coeff;
	int degree;
public:
	TMonom(const TMonom& monom);
	TMonom(double coeff = 1, int degree = 0);


	bool operator<(const TMonom& data) const;
	bool operator>(const TMonom& data) const;
	bool operator==(const TMonom& data) const;
	bool operator!=(const TMonom& data) const;
};

#endif