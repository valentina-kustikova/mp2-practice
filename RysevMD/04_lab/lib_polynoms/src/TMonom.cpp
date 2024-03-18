#include "TMonom.h"

double dc(double num, int deg) {
	double res = 1.0;
	for (int i = 0; i < deg; i++) res *= num;
	return num;
}

Monom::Monom(const Monom& monom) {
	coef = monom.coef;
	degX = monom.degX;
	degY = monom.degY;
	degZ = monom.degZ;
}

Monom::Monom(const double _coef, const int _degX, const int _degY, const int _degZ) {
	coef = _coef;
	degX = _degX;
	degY = _degY;
	degZ = _degZ;
}

bool Monom::operator==(const Monom& monom) const
{
	return (coef == monom.coef) && (degX == monom.degX) && (degY == monom.degY) && (degZ == monom.degZ);
}

bool Monom::operator!=(const Monom& monom) const
{
	return !(*this == monom);
}

bool Monom::operator>(const Monom& monom) const
{
	return ((degX > monom.degX) || (degX == monom.degX && degY > monom.degY) ||
			(degX == monom.degX && degY == monom.degY && degZ > monom.degZ));
}

bool Monom::operator<(const Monom& monom) const
{
	return ((degX < monom.degX) || (degX == monom.degX && degY < monom.degY) ||
		(degX == monom.degX && degY == monom.degY && degZ < monom.degZ));
}

Monom Monom::operator*(const Monom& monom) const
{
	return Monom(monom.coef * coef, monom.degX + degX, degY + monom.degY, degZ + monom.degZ);
}

double Monom::getCoef() const { return coef; }

int Monom::getDegX() const { return degX; }

int Monom::getDegY() const { return degY; }

int Monom::getDegZ() const { return degZ; }

double Monom::Calculate(double x, double y, double z)
{
	return coef * dc(x, degX) * dc(y, degY) * dc(z, degZ);
}

Monom Monom::difX() const
{
	if (*this == Monom()) return Monom();
	return Monom(coef * degX, degX - 1, degY, degZ);
}

Monom Monom::difY() const
{
	if (*this == Monom()) return Monom();
	return Monom(coef * degY, degX, degY - 1, degZ);
}

Monom Monom::difZ() const
{
	if (*this == Monom()) return Monom();
	return Monom(coef * degZ, degX, degY, degZ - 1);
}
