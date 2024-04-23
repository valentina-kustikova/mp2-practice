#include "tmonom.h"

TMonom::TMonom(double coeff, int degree)
{
	this->coeff = coeff;
	this->degree = degree;
}

TMonom::TMonom(const TMonom& monom)
{
	coeff = monom.coeff;
	degree = monom.degree;
}


bool TMonom::operator==(const TMonom& data)const
{
	if (degree == data.degree && coeff == data.coeff)
		return true;
	return false;
}

bool TMonom::operator!=(const TMonom& data)const
{
	return !(*this == data);
}


bool TMonom::operator<(const TMonom& data) const
{
	if (degree < data.degree)
		return true;
	if (degree == data.degree)
		if (coeff < data.coeff)
			return true;
	return false;
}

bool TMonom::operator>(const TMonom& data) const
{
	if (degree > data.degree)
		return true;
	if (degree == data.degree)
		if (coeff > data.coeff)
			return true;
	return false;
}

TMonom TMonom::operator+(const TMonom& data)
{
	if (degree != data.degree)
		throw std::exception("Invalid monoms(op+)");
	return TMonom(coeff + data.coeff, degree);
}

TMonom TMonom::operator-(const TMonom& data)
{
	if (degree != data.degree)
		throw std::exception("Invalid monoms(op-)");
	return TMonom(coeff - data.coeff, degree);
}

TMonom TMonom::operator*(const TMonom& data)
{
	if (degree != data.degree)
		throw std::exception("Invalid monoms(op*)");
	return TMonom(coeff * data.coeff, degree);
}


TMonom TMonom::def_X()
{
	if ((int)(degree/100) == 0)
		return TMonom(0, 0);
	return TMonom(coeff * (degree / 100), degree - 100);
}

TMonom TMonom::def_Y()
{
	if ((int)(degree % 100) / 10 == 0)
		return TMonom(0,0);
	return TMonom(coeff * ((degree % 100) / 10), degree - 10);
}

TMonom TMonom::def_Z()
{
	if((int)(degree%10) == 0)
		return TMonom(0, 0);
	return TMonom(coeff * (degree % 10), degree - 1);
}