#pragma once
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Monom
{
public:

	double coef;
	int degX;
	int degY;
	int degZ;

	Monom(const Monom& monom);
	Monom(const double coef = 1.0, const int _degX = 0, const int _degY = 0, const int _degZ = 0);

	const Monom& operator=(const Monom& monom);
	bool operator==(const Monom& monom) const;
	bool operator!=(const Monom& monom) const;
	bool operator>(const Monom& monom) const;
	bool operator<(const Monom& monom) const;
	Monom operator*(const Monom& monom) const;
	friend std::ostream& operator << (std::ostream& out, Monom& monom) {
		out << monom.coef;
		if (monom.degX != 0 && monom.degX == 1) out << "*X";
		else if (monom.degX > 1) out << "*X^" << monom.degX;
		if (monom.degY != 0 && monom.degY == 1) out << "*Y";
		else if (monom.degY > 1) out << "*Y^" << monom.degY;
		if (monom.degZ != 0 && monom.degZ == 1) out << "*Z";
		else if (monom.degZ > 1) out << "*Z^" << monom.degZ;
		return out;
	}

	double getCoef() const;
	int getDegX() const;
	int getDegY() const;
	int getDegZ() const;

	double Calculate(double x, double y, double z);
	Monom difX() const;
	Monom difY() const;
	Monom difZ() const;

	string toString() const;
};