#include "monom.h"

Monom::Monom(const double c, const int d)
{
	coeff = c;
	degree = d;
}

Monom::Monom(const Monom& m)
{
	coeff = m.coeff;
	degree = m.degree;
}

Monom& Monom::operator+(const Monom& m)
{
	coeff = coeff + m.coeff;
	return *this;
}
Monom& Monom::operator*(const double& d)
{
	coeff = coeff * d;
	return *this;
}
Monom& Monom::operator*(const Monom& m)
{
	coeff = coeff * m.coeff;
	degree = degree + m.degree;
	return *this;
}

bool Monom::operator<(const Monom& m) const
{
	return (degree < m.degree);
}

bool Monom::operator>(const Monom& m) const
{
	return (degree > m.degree);
}

const Monom& Monom::operator=(const Monom& m)
{
	coeff = m.coeff;
	degree = m.degree;
	return *this;
}

bool Monom::operator==(const Monom& m) const
{
	return ((degree == m.degree) && (coeff == m.coeff));
}

bool Monom::operator!=(const Monom& m) const
{
	return !(*this == m);
}