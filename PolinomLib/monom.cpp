#include <typeinfo>	
#include "monom.h"

Monom::Monom(double _coef, int _degx, int _degy, int _degz, Monom* _next)
{
	
		degx = _degx;
		degy = _degy;
		degz = _degz;

		coef = _coef;
		next = _next;
}

Monom::Monom(const Monom& monom2)
{
	degx = monom2.degx;
	degy = monom2.degy;
	degz = monom2.degz;
	coef = monom2.coef;
	next = monom2.next;
}



bool Monom::operator==(const Monom& m) const
{
	return ((coef) - (m.coef) < 1e-10) && (degx == m.degx) && (degy == m.degy) && (degz == m.degz);
}

bool Monom::operator!=(const Monom& m) const
{
	return ((coef) - (m.coef) > 1e-10) || (degx != m.degx) || (degy != m.degy) || (degz != m.degz);
}

std::ostream& operator<<(std::ostream& os, const Monom& m)
{
	os << m.coef << "x^" << m.degx << "y^" << m.degy << "z^" << m.degz << std::endl;
	return os;
}


