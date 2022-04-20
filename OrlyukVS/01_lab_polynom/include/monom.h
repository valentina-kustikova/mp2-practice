#pragma once

class TMonom
{
public:
	double coef;
	int deg;
	TMonom();
	TMonom(double coef1, unsigned int deg1);
	TMonom& operator=(const TMonom& m);
	bool operator==(const TMonom& m) const;
	bool operator!=(const TMonom& m) const;
	bool operator< (const TMonom& m) const;
	bool operator> (const TMonom& m) const;
};