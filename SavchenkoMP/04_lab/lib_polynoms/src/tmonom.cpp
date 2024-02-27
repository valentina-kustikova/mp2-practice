#include "tmonom.h"

TMonom::TMonom() {
	coeff = 0;
	degree = -1;
}
TMonom::TMonom(const TMonom& monom) {
	coeff = monom.coeff;
	degree = monom.degree;
}
TMonom::TMonom(double _coeff = 0, int _degree = -1) {
	coeff = _coeff;
	degree = _degree;
}



bool TMonom::operator<(const TMonom& monom) const {
	if (degree < monom.degree) return true;
	return false;
}
bool TMonom::operator>(const TMonom& monom) const {
	if (degree > monom.degree) return true;
	return false;
}
bool TMonom::operator==(const TMonom& monom) const {
	if (degree == monom.degree) return true;
	return false;
}
bool TMonom::operator!=(const TMonom& monom) const {
	return !(degree == monom.degree);
}