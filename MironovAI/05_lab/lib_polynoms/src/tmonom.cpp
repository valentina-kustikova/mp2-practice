#include "tmonom.h"
#include <algorithm>


TMonom::TMonom(const TMonom& monom) 
{
	coef = monom.coef;
	degree_x = monom.degree_x;
	degree_y = monom.degree_y;
	degree_z = monom.degree_z;
}


TMonom::TMonom(const double coef_, const int degreex_, const int degreey_, const int degreez_)
{
	coef = coef_;
	degree_x = degreex_;		   
	degree_y = degreey_;   
	degree_z = degreez_;   
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

