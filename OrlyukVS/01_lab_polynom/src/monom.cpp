#include "monom.h"
#include <iostream>

TMonom::TMonom(double coef1 = 0.0, unsigned int deg1 = 0)
{
	coef = coef1;
	deg = deg1;
}

TMonom& TMonom::operator=(const TMonom& m)
{
	coef = m.coef;
	deg = m.deg;
	return *this;
}

bool TMonom::operator==(const TMonom& m) const
{
	return((coef == m.coef) && (deg == m.deg));
}

bool TMonom::operator!=(const TMonom& m) const
{
	return!(*this == m);
}

bool TMonom::operator<(const TMonom& m) const
{
	return(deg < m.deg);
}

bool TMonom::operator>(const TMonom& m) const
{
	return(deg > m.deg);
}