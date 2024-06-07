#include "tmonom.h"
#include <algorithm>
#include <string>

TMonom::TMonom(const TMonom& monom) 
{
	coef = double(monom.coef);
	degree_x = double(monom.degree_x);
	degree_y = double(monom.degree_y);
	degree_z = double(monom.degree_z);
}


TMonom::TMonom(const double coef_, const int degreex_, const int degreey_, const int degreez_)
{
	coef = coef_;
	degree_x = degreex_;		   
	degree_y = degreey_;   
	degree_z = degreez_;   
}

string TMonom::to_str()
{
	return to_string(abs(coef)) + "x^" + to_string(degree_x) + "y^"
		+ to_string(degree_y) + "z^" + to_string(degree_z);
}

bool TMonom::operator<(const TMonom& monom) const {
	return ((degree_x < monom.degree_x) || (degree_x == monom.degree_x && degree_y < monom.degree_y) ||
		(degree_x == monom.degree_x && degree_y == monom.degree_y && degree_z < monom.degree_z));
}


bool TMonom::operator>(const TMonom& monom) const {
	return ((degree_x > monom.degree_x) || (degree_x == monom.degree_x && degree_y > monom.degree_y) ||
		(degree_x == monom.degree_x && degree_y == monom.degree_y && degree_z > monom.degree_z));
}


bool TMonom::operator==(const TMonom& monom) const {
	return degree_x == monom.degree_x && degree_y == monom.degree_y && degree_z == monom.degree_z;
}


bool TMonom::operator!=(const TMonom& monom) const {
	return !(*this == monom);
}


TMonom TMonom::operator*(const TMonom& monom) const
{
	return TMonom(monom.coef * this->coef, monom.degree_x + this->degree_x,
		this->degree_y + monom.degree_y, this->degree_z + monom.degree_z);
}


double TMonom::eval(double x, double y, double z)
{
	return coef * std::pow(x, degree_x) * std::pow(y, degree_y) * std::pow(z, degree_z);
}


double TMonom::get_coef() const
{
	return coef;
}


void TMonom::set_coef(double digit)
{
	coef = digit;
}


void TMonom::inc_coef(double digit)
{
	coef += digit;
}

bool TMonom::greater(const TMonom& monom) const
{
	if (degree_x != monom.degree_x)
	{
		return degree_x < monom.degree_x;
	}
	if (degree_y != monom.degree_y)
	{
		return degree_y < monom.degree_y;
	}
	if (degree_z != monom.degree_z)
	{
		return degree_z < monom.degree_z;
	}
	return coef < monom.coef;
}

bool TMonom::equal(const TMonom& monom) const
{
	return coef == monom.coef && degree_x == monom.degree_x
		&& degree_y == monom.degree_y
		&& degree_z == monom.degree_z;
}


TMonom TMonom::dif_x() const
{
	if (*this == TMonom())
	{
		return TMonom();
	}
	if (degree_x == 0)
	{
		return TMonom(0, 0, 0, 0);
	}
	return TMonom(coef * degree_x, degree_x - 1, degree_y, degree_z);
}


TMonom TMonom::dif_y() const
{
	if (*this == TMonom())
	{
		return TMonom();
	}
	if (degree_y == 0)
	{
		return TMonom(0, 0, 0, 0);
	}
	return TMonom(coef * degree_y, degree_x, degree_y - 1, degree_z);
}


TMonom TMonom::dif_z() const
{
	if (*this == TMonom())
	{
		return TMonom();
	}
	if (degree_z == 0)
	{
		return TMonom(0, 0, 0, 0);
	}
	return TMonom(coef * degree_z, degree_x, degree_y, degree_z - 1);
}

