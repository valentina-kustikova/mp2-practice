#pragma once
#include <iostream>
#include <cmath>

struct TMonom
{
	double coeff;

	int x;
	int y;
	int z;
	TMonom();
	TMonom(double _coeff, int _x, int _y, int _z);
	TMonom(int _x, int _y, int _z);

	
	bool operator==(const TMonom& other) const;
	bool operator!=(const TMonom& other) const;
	bool operator<(const TMonom& other) const;
	bool operator>(const TMonom& other) const;

	
	bool IsConst() const;

	TMonom operator*(const TMonom& other);

	//Выводит текущий моном без коэффициента и знака
	friend std::ostream& operator<<(std::ostream& os, TMonom& monom)
	{
		if (monom.x != 0)
		{
			os << "x";
			if (monom.x != 1)
				os << monom.x;
		}
		if (monom.y != 0)
		{
			os << "y";
			if (monom.y != 1)
				os << monom.y;
		}
		if (monom.z != 0)
		{
			os << "z";
			if (monom.z != 1)
				os << monom.z;
		}
		return os;
	}
};

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
















//#pragma once
//
//#include "data.h"
//
//class TMonom: public TData
//{
//public:
//    double coeff;
//    int degree;
//public:
//    TMonom(double coeff, int degree);
//    
//    TMonom& operator=(const TMonom& monom);
//    
//    int operator==(const TMonom& monom) const;
//    int operator!=(const TMonom& monom) const;
//    int operator<(const TMonom& monom) const;
//    int operator>(const TMonom& monom) const;
//    
//    virtual TData* Copy(); // создание копии
//};
