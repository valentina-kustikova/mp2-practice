#include "monom.h"

TMonom::TMonom()
{
	coef = 0.0;
	deg = 0;
}

TMonom::TMonom(double coef1, unsigned int deg1)
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
	return deg == m.deg;
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