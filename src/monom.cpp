#include "monom.h"

Monom::Monom()
{
	coeff = 0;
	degree = 1003;
}
Monom::Monom(double _coeff, unsigned int _degree)
{
	coeff = _coeff;
	degree = _degree;
}
const Monom& Monom::operator=(const Monom& m)
{
	coeff = m.coeff;
	degree = m.degree;
	return *this;
}
bool Monom::operator==(const Monom& m) const
{
	return  degree == m.degree;
}
bool Monom::operator!=(const Monom& m) const
{
	return !(*this == m);
}
bool Monom::operator<(const Monom& m) const
{
	return degree < m.degree;
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