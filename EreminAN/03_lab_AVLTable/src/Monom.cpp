#pragma once


#include "Monom.h"

Monom::Monom(double coeff, int degX, int degY, int degZ)
{
	if (degX < -1 || degY < -1 || degZ < -1)
		throw std::exception("incorrect!");
	else
	{
		coefficient = coeff;
		degreeX = degX;
		degreeY = degY;
		degreeZ = degZ;
	}
}

Monom::Monom(const Monom& m)
{
	degreeX = m.degreeX;
	degreeY = m.degreeY;
	degreeZ = m.degreeZ;
	coefficient = m.coefficient;
}

const Monom& Monom::operator = (const Monom& _monom)
{
	coefficient = _monom.coefficient;
	degreeX = _monom.degreeX;
	degreeY = _monom.degreeY;
	degreeZ = _monom.degreeZ;
	return *this;
}

bool Monom::operator != (const Monom& _monom) const
{
	return (coefficient != _monom.coefficient || degreeX != _monom.degreeX || degreeY != _monom.degreeY || degreeZ != _monom.degreeZ);
}

bool Monom::operator == (const Monom& _monom) const
{
	return (coefficient == _monom.coefficient && degreeX == _monom.degreeX && degreeY == _monom.degreeY && degreeZ == _monom.degreeZ);
}

bool Monom::degreeEq(const Monom& _monom)
{
	return (degreeX == _monom.degreeX && degreeY == _monom.degreeY && degreeZ == _monom.degreeZ);
}


Monom Monom::operator+(const Monom& _monom) const
{
	if (this->degreeX == _monom.degreeX && this->degreeY == _monom.degreeY && this->degreeZ == _monom.degreeZ)
	{
		Monom tmp(1, _monom.degreeX, _monom.degreeY, _monom.degreeZ);
		tmp.coefficient = this->coefficient + _monom.coefficient;
		return tmp;
	}
	else {
		throw "Error";
	}
}

Monom Monom::operator-(const Monom& _monom) const
{
	if (this->degreeX == _monom.degreeX && this->degreeY == _monom.degreeY && this->degreeZ == _monom.degreeZ)
	{
		Monom tmp(1, _monom.degreeX, _monom.degreeY, _monom.degreeZ);
		tmp.coefficient = this->coefficient - _monom.coefficient;
		return tmp;
	}
	else {
		throw "Error";
	}
}

Monom Monom::operator*(const Monom& _monom) const
{
	Monom tmp(0, 0, 0, 0);
	tmp.coefficient = this->coefficient * _monom.coefficient;
	tmp.degreeX = this->degreeX + _monom.degreeX;
	tmp.degreeY = this->degreeY + _monom.degreeY;
	tmp.degreeZ = this->degreeZ + _monom.degreeZ;
	return tmp;
}

Monom Monom::operator+(const double& _Num) const
{
	Monom monom = *this;
	if (monom.degree() == 0)
	{
		monom.coefficient = monom.coefficient + _Num;
		return monom;
	}
	else
	{
		throw "error";
	}
}

Monom Monom::operator*(const double& _Num) const
{
	Monom tmp(*this);
	tmp.coefficient = this->coefficient * _Num;

	return tmp;
}

Monom Monom::operator-(const double& _Num) const
{
	Monom monom = *this;
	if (monom.degree() == 0)
	{
		monom.coefficient = monom.coefficient - _Num;
		return monom;
	}
	else
	{
		throw "error";
	}
}

std::string Monom::Mstring()
{
	Monom l = *this;
	std::string Res;
	if (l.degreeX != 0)
	{
		if (l.coefficient != 1 && l.coefficient != -1)
			if (l.degreeX != 1)
				Res = Res + (std::to_string((int)l.coefficient) + "x" + "^" + std::to_string(l.degreeX));
			else Res = std::to_string((int)l.coefficient) + "x";
		else
		{
			if (l.coefficient != -1)
			{
				if (l.degreeX != 1)
					Res = Res + "x" + "^" + std::to_string(l.degreeX);
				else Res = Res + "x";
			}
			else
			{
				if (l.degreeX != 1)
					Res = Res + "-x" + "^" + std::to_string(l.degreeX);
				else Res = Res + "-x";
			}
		}
	}
	else
	{
		if ((l.coefficient != 1 && l.coefficient != -1) || (l.degreeX == 0 && l.degreeY == 0 && l.degreeZ == 0))
			Res = Res + std::to_string((int)l.coefficient);
		else
		{
			if (l.coefficient == -1)
			{
				Res = Res + "-";
			}
		}
	}
	if (l.degreeY != 0)
	{
		if (l.degreeY != 1)
			Res = Res + "y" + "^" + std::to_string(l.degreeY);
		else Res = Res + "y";
	}
	if (l.degreeZ != 0)
	{
		if (l.degreeZ != 1)
			Res = Res+ "z" +"^" + std::to_string(l.degreeZ);
		else Res = Res + "z";
	}
	return Res;
}