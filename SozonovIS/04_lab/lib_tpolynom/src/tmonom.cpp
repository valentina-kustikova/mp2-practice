#include "tmonom.h"
#include "tdata.h"

#include <iostream>

using namespace std;

TMonom::TMonom(const TMonom& monom) {
	coeff = monom.coeff;
	degree = monom.degree;
}

TMonom::TMonom(double coef, int deg) {
	if (deg > 999)
		throw exception("degree out of range");
	coeff = coef;
	degree = deg;
}

bool TMonom::operator<(const TMonom& monom)const {
	return degree < monom.degree || degree == monom.degree && coeff < monom.coeff;
}

bool TMonom::operator<=(const TMonom& monom)const {
	return degree < monom.degree || degree == monom.degree && coeff < monom.coeff || *this == monom;
}

bool TMonom::operator>(const TMonom& monom)const {
	return degree > monom.degree || degree == monom.degree && coeff > monom.coeff;
}

bool TMonom::operator>=(const TMonom& monom)const {
	return degree > monom.degree || degree == monom.degree && coeff > monom.coeff || *this == monom;
}

bool TMonom::operator==(const TMonom& monom)const {
	return degree == monom.degree && coeff == monom.coeff;
}

bool TMonom::operator!=(const TMonom& monom)const {
	return !(*this == monom);
}