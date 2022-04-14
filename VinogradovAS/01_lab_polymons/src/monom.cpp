#include "monom.h"


TMonom::TMonom()
{
	coeff = 0;
	x = y = z = 0;
}

TMonom::TMonom(
	double _coeff, int _x, int _y, int _z)
{
	coeff = _coeff;
	x = _x;
	y = _y;
	z = _z;
}

TMonom::TMonom(int _x, int _y, int _z)
{
	coeff = 0;
	x = _x;
	y = _y;
	z = _z;
}

bool TMonom::operator==(const TMonom& other) const
{
	return (x == other.x && y == other.y && z == other.z);
}

bool TMonom::operator!=(const TMonom& other) const
{
	return (x != other.x || y != other.y || z != other.z);
}

bool TMonom::operator<(const TMonom& other) const
{
	if (x < other.x) return true;
	else if (x == other.x)
	{
		if (y < other.y) return true;
		else if (y == other.y)
		{
			return z < other.z;
		}
		else return false;
	}
	else return false;
}

bool TMonom::operator>(const TMonom& other) const
{
	return !operator<(other) && !operator==(other);
}

bool TMonom::IsConst() const
{
	return x == 0 && y == 0 && z == 0;
}

TMonom TMonom::operator*(const TMonom& other)
{
	TMonom result;
	result.coeff = coeff * other.coeff;
	result.x = x + other.x;
	result.y = y + other.y;
	result.z = z + other.z;
	return result;
}