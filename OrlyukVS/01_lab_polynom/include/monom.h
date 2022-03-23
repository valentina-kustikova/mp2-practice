#pragma once

class TMonom
{
public:
	double coef;
	unsigned int deg;
	TMonom(double coef1 = 0.0, unsigned int deg1 = 0);
	TMonom& operator=(const TMonom& m);
	bool operator==(const TMonom& m) const;
	bool operator!=(const TMonom& m) const;
	bool operator< (const TMonom& m) const;
	bool operator> (const TMonom& m) const;
};