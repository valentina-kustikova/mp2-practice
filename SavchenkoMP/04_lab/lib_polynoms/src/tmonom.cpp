#include "tmonom.h"

TMonom::TMonom() {
	coeff = 0;
	degree = 0;
}
TMonom::TMonom(const TMonom& monom) {
	coeff = monom.coeff;
	degree = monom.degree;
}
TMonom::TMonom(double _coeff, int _degree) {
	if (_degree > 999 || _degree < 0) {
		string exp = "Error: degree must be in [0, 999]";
		throw exp;
	}
	
	coeff = _coeff;
	degree = _degree;
}
TMonom::TMonom(double _coeff, int degX, int degY, int degZ) {
	if (degX < 0 || degY < 0 || degZ < 0 || degX > 9 || degY > 9 || degZ > 9) {
		string exp = "Error: x,y,z must be in [0, 9]";
		throw exp;
	}

	coeff = _coeff;
	degree = 100 * degX + 10 * degY + degZ;
}



double TMonom::get_coeff() const {
	return coeff;
}
int TMonom::get_degree() const {
	return degree;
}
void TMonom::set_coeff(double _coeff) {
	coeff = _coeff;
}
void TMonom::set_degree(int _degree) {
	if (_degree > 999 || _degree < 0) {
		string exp = "Error: degree must be in [0, 999]";
		throw exp;
	}
	
	degree = _degree;
}
void TMonom::set_degree(int degX, int degY, int degZ) {
	if (degX < 0 || degY < 0 || degZ < 0 || degX > 9 || degY > 9 || degZ > 9) {
		string exp = "Error: degX,degY,degZ must be in [0, 9]";
		throw exp;
	}
	
	degree = 100 * degX + 10 * degY + degZ;
}


double TMonom::value(int x, int y, int z) {
	int resX = 1, resY = 1, resZ = 1;
	
	int degZ = degree % 10;
	int degY = (degree / 10) % 10;
	int degX = degree / 100;
	
	for (int i = 0; i < degZ; i++) {
		resZ *= z;
	}
	for (int i = 0; i < degY; i++) {
		resY *= y;
	}
	for (int i = 0; i < degX; i++) {
		resX *= x;
	}

	return coeff * resX * resY * resZ;
}


bool TMonom::operator<(const TMonom& monom) const {
	if (degree < monom.degree) return true;
	return false;
}
bool TMonom::operator>(const TMonom& monom) const {
	if (degree > monom.degree) return true;
	return false;
}
bool TMonom::operator<=(const TMonom& monom) const {
	if (degree <= monom.degree) return true;
	return false;
}
bool TMonom::operator>=(const TMonom& monom) const {
	if (degree >= monom.degree) return true;
	return false;
}
bool TMonom::operator==(const TMonom& monom) const {
	if (degree == monom.degree) return true;
	return false;
}
bool TMonom::operator!=(const TMonom& monom) const {
	return !(degree == monom.degree);
}


const TMonom& TMonom::operator=(const TMonom& monom) const {
	TMonom res(monom);
	return res;
}

TMonom TMonom::operator*(const TMonom& monom) const {
	int res_degree = degree + monom.degree;
	double res_coeff = coeff * monom.coeff;
	
	if (res_degree < 0 || res_degree > 999) {
		string exp = "Error: res_degree must be in [0, 999]";
		throw exp;
	}
	
	TMonom res(res_coeff, res_degree);
	return res;
}