#pragma once

#include <iostream>

using namespace std;

class TMonom
{
public:
	double coeff;
	int degree;

	TMonom(double _coeff = 0, int _degree = 0);
	TMonom& operator=(const TMonom& m);
	bool operator==(const TMonom& m) const;
	bool operator!=(const TMonom& m) const;
	bool operator<(const TMonom& m) const;
	bool operator>(const TMonom& m) const;
	TMonom operator*(const int& c);
	friend ostream& operator<<(ostream& os, const TMonom& m)
	{
		int x, y, z;
		x = m.degree / 100;
		y = (m.degree - x * 100) / 10;
		z = m.degree - x * 100 - y * 10;
		if (m.coeff != 1 || m.degree == 0)
			os << m.coeff;
		if (x > 0)
			os << "x^" << x;
		if (y > 0)
			os << "y^" << y;
		if (z > 0)
			os << "z^" << z;
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