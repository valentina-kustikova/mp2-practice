#include "tmonom.h"

#include <iostream>
#include <string>

using namespace std;

TMonom::TMonom()
{
	coef = 0;
	degree = 0;
}

TMonom::TMonom(const TMonom& m)
{
	coef = m.coef;
	degree = m.degree;
}

TMonom::TMonom(double _coef, int _degree)
{
	if (_degree > 999 || _degree < 0)
	{
		throw "intervai for degree [0,999]";
	}
	coef = _coef;
	degree = _degree;
}

TMonom::TMonom(double _coef, int DegreeX, int DegreeY, int DegreeZ)
{
	if (DegreeX < 0 || DegreeX>9 || DegreeY < 0 || DegreeY>9 || DegreeZ < 0 || DegreeZ>9)
	{
		throw"Interval for degrees [0,9]";
	}
	coef = _coef;
	degree = DegreeX * 100 + DegreeY * 10 + DegreeZ;

}

bool TMonom::operator>(const TMonom& m) const
{
	if (degree > m.degree)
		return true;
	return false;
}

bool TMonom::operator<(const TMonom& m) const
{
	if (degree < m.degree)
		return true;
	return false;
}

bool TMonom::operator==(const TMonom& m) const
{
	if (degree == m.degree)
		return true;
	return false;
}

bool TMonom::operator!=(const TMonom& m) const
{
	if (degree != m.degree)
		return true;
	return false;
}

TMonom& TMonom::operator=(const TMonom& m) 
{
	coef = m.coef;
	degree = m.degree;
	return *this;
}

TMonom TMonom::operator+(const TMonom& m) const
{
	if (degree != m.degree)
		throw"Cant add different degrees";
	TMonom res;
	res.degree = degree;
	res.coef = coef + m.coef;
	return res;
}

TMonom TMonom::operator-(const TMonom& m) const
{
	if (degree != m.degree)
		throw"Cant add different degrees";
	TMonom res;
	res.degree = degree;
	res.coef = coef - m.coef;
	return res;
}

TMonom TMonom::operator*(const TMonom& m) const
{
	int ResultDegree = degree + m.degree;
	if (ResultDegree < 0 || ResultDegree>999)
	{
		throw"Interwal for degree [0,999]";
	}
	double ResultCoef = coef * m.coef;
	TMonom res(ResultCoef, ResultDegree);
	return res;

}

double TMonom::GetValue(double x, double y, double z)
{
	double ResX = 1;
	for (int i = 0; i < GetDegreeX(); i++)
	{
		ResX *= x;
	}
	double ResY = 1;
	for (int i = 0; i < GetDegreeY(); i++)
	{
		ResY *= y;
	}
	double ResZ = 1;
	for (int i = 0; i < GetDegreeZ(); i++)
	{
		ResZ *= z;
	}
	return (coef * ResX * ResY * ResZ);

}

int TMonom::GetDegreeX() const
{
	if (degree < 100)
		return 0;
	return(degree / 100);
}

int TMonom::GetDegreeY() const
{
	if (degree < 10)
		return 0;
	if (degree < 100)
		return (degree / 10);
	return((degree - GetDegreeX() * 100) / 10);
}

int TMonom::GetDegreeZ() const
{
	if (degree < 10)
		return degree;
	return(degree - GetDegreeX() * 100 - GetDegreeY() * 10);
}

TMonom TMonom::dif_x()
{
	if (GetDegreeX() == 0)
	{
		TMonom res(0, 0);
		return res;
	}
	if (GetDegreeX() == 1)
	{
		int ResDegree = GetDegreeY() * 10 + GetDegreeZ();
		TMonom res(coef, ResDegree);
		return res;
	}
	double ResCoef = coef * GetDegreeX();
	int ResDegree = (GetDegreeX() - 1) * 100 + GetDegreeY() * 10 + GetDegreeZ();
	TMonom res(ResCoef, ResDegree);
	return res;

}

TMonom TMonom::dif_y()
{
	if (GetDegreeY() == 0)
	{
		TMonom res(0, 0);
		return res;
	}
	if (GetDegreeY() == 1)
	{
		int ResDegree = GetDegreeX() * 100 + GetDegreeZ();
		TMonom res(coef, ResDegree);
		return res;
	}
	double ResCoef = coef * GetDegreeY();
	int ResDegree = GetDegreeX() * 100 + (GetDegreeY() - 1) * 10 + GetDegreeZ();
	TMonom res(ResCoef, ResDegree);
	return res;
}

TMonom TMonom::dif_z()
{
	if (GetDegreeZ() == 0)
	{
		TMonom res(0, 0);
		return res;
	}
	if (GetDegreeZ() == 1)
	{
		int ResDegree = GetDegreeX() * 100 + GetDegreeY() * 10;
		TMonom res(coef, ResDegree);
		return res;
	}
	double ResCoef = coef * GetDegreeZ();
	int ResDegree = GetDegreeX() * 100 + GetDegreeY() * 10 + (GetDegreeZ() - 1);
	TMonom res(ResCoef, ResDegree);
	return res;
}

void TMonom::SetDegree(int _degree)
{
	if (_degree < 0 || _degree>999)
		throw"digree must be in interval [0,999]";
	degree = _degree;
}

void TMonom::SetDegreeXYZ(int DegreeX, int DegreeY, int DegreeZ)
{
	if (DegreeX < 0 || DegreeX>9 || DegreeY < 0 || DegreeY>9 || DegreeZ < 0 || DegreeZ>9)
		throw"Interval for degrees [0,9]";
	degree = DegreeX * 100 + DegreeY * 10 + DegreeZ;
}

string TMonom::GetStr() const
{
	string res = " ";

	res += to_string(coef);

	if (GetDegreeX() == 1)
		res += "x";
	if (GetDegreeX() > 1)
	{
		res += "x^" + to_string(GetDegreeX());
	}

	if (GetDegreeY() == 1)
		res += "y";
	if (GetDegreeY() > 1)
	{
		res += "y^" + to_string(GetDegreeY());
	}

	if (GetDegreeZ() == 1)
		res += "z";
	if (GetDegreeZ() > 1)
	{
		res += "z^" + to_string(GetDegreeZ());
	}

	return res;
}

bool TMonom::TheSameCoefANDDegree(const TMonom& m)
{
	if (coef == m.coef && degree == m.degree)
		return true;
	else
		return false;
}

