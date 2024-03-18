#pragma once


class Monom
{
private:

	double coef;
	int degX;
	int degY;
	int degZ;

public:
	Monom(const Monom& monom);
	Monom(const double coef = 0.0, const int _degX = 0, const int _degY = 0, const int _degZ = 0);

	bool operator==(const Monom& monom) const;
	bool operator!=(const Monom& monom) const;
	bool operator>(const Monom& monom) const;
	bool operator<(const Monom& monom) const;
	Monom operator*(const Monom& monom) const;

	double getCoef() const;
	int getDegX() const;
	int getDegY() const;
	int getDegZ() const;

	double Calculate(double x, double y, double z);
	Monom difX() const;
	Monom difY() const;
	Monom difZ() const;
};