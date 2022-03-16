#include "monom.h"

Monom::Monom(const double c, const int p)
{
	cf = c;
	pw = p;
}

Monom::Monom(const Monom& m)
{
	cf = m.cf;
	pw = m.pw;
}

bool Monom::operator==(const Monom& m) const
{
	return ((pw == m.pw) && (cf == m.cf));
}

bool Monom::operator!=(const Monom& m) const
{
	return !(*this == m);
}

bool Monom::operator<(const Monom& m) const
{
	return (pw < m.pw);
}

bool Monom::operator>(const Monom& m) const
{
	return (pw > m.pw);
}

const Monom& Monom::operator=(const Monom& m)
{
	cf = m.cf;
	pw = m.pw;
	return *this;
}