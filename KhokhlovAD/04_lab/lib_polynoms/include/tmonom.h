#ifndef _TMONOM_
#define _TMONOM_

class TMonom {
private:
	double coeff;
	int degree;
public:
	TMonom();
	TMonom(const TMonom& monom);
	TMonom(double coeff, int degree);
	bool operator<(const TMonom& data) const;
	bool operator>(const TMonom& data) const;
	bool operator==(const TMonom& data) const;
	bool operator!=(const TMonom& data) const;
};

#endif