#pragma once

#include <iostream>

using namespace std;

class TMonom
{
public:
	double coeff;
	int degree;

	TMonom(double _coeff = 0, int _degree = 0)
	{
		if (_degree > 999) { throw 1; }
		coeff = _coeff;
		degree = _degree;
	}

	bool operator==(const TMonom& m) const
	{
		return degree == m.degree;
	}

	bool operator>(const TMonom& m) 
	{
		if (degree > m.degree)
			return true;
		if (degree = m.degree)
		{
			if (coeff > m.coeff) return true;
			else false;
		}
		else return false;
	}

	bool operator<(const TMonom& m) 
	{
		if (degree < m.degree)
			return true;
		if (degree = m.degree)
		{
			if (coeff < m.coeff) return true;
			else false;
		}
		else return false;
	}

	TMonom operator*(const int& c)
	{
		coeff *= c;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const TMonom& m)
	{
		int x, y, z;
		x = m.degree / 100;
		y = (m.degree - x * 100) / 10;
		z = m.degree - x * 100 - y * 10;
		os << m.coeff << "*x^" << x << "*y^" << y << "*z^" << z << " ";
		return os;
	}

	friend istream& operator>>(istream& is, TMonom& m)
	{
		int x, y, z;
		cout << "Введите коэффициент\n";
		is >> m.coeff;
		cout << "Введите степени x, y, z \n";
		is >> x >> y >> z;
		m.degree = x * 100 + y * 10 + z;
		return is;
	}
};