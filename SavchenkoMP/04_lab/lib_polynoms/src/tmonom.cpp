#include "tmonom.h"
#include <string>

TMonom::TMonom() {
	coeff = 0;
	degree = -1;
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

int TMonom::get_degX() const {
	int degX = degree / 100;
	return degX;
}
int TMonom::get_degY() const {
	int degY = (degree / 10) % 10;
	return degY;
}
int TMonom::get_degZ() const {
	int degZ = degree % 10;
	return degZ;
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


double TMonom::value(double x, double y, double z) {
	double resX = 1, resY = 1, resZ = 1;

	int degZ = get_degZ();
	int degY = get_degY();
	int degX = get_degX();
	
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


const TMonom& TMonom::operator=(const TMonom& monom) {
	degree = monom.degree;
	coeff = monom.coeff;

	return (*this);
}

TMonom TMonom::operator*(const TMonom& monom) const {
	int degZ1 = get_degZ();
	int degY1 = get_degY();
	int degX1 = get_degX();

	int degZ2 = monom.get_degZ();
	int degY2 = monom.get_degY();
	int degX2 = monom.get_degX();

	if (degZ1 + degZ2 > 9 || degY1 + degY2 > 9 || degX1 + degX2 > 9 ||
		degZ1 + degZ2 < 0 || degY1 + degY2 < 0 || degX1 + degX2 < 0) {
		string exp = "Error: res_degrees must be in [0, 9]";
		throw exp;
	}
	
	int res_degree = degree + monom.degree;
	double res_coeff = coeff * monom.coeff;
		
	TMonom res(res_coeff, res_degree);
	return res;
}


TMonom TMonom::dif_x() const {
	int degX = get_degX();
	
	if (degX == 0) {
		TMonom res(0, 0);
		return res;
	}
	else {
		double _coeff = coeff * degX;
		int _degree = degree - 100;

		TMonom res(_coeff, _degree);
		return res;
	}	
}
TMonom TMonom::dif_y() const {
	int degY = get_degY();
	
	if (degY == 0) {
		TMonom res(0, 0);
		return res;
	}
	else {
		double _coeff = coeff * degY;
		int _degree = degree - 10;

		TMonom res(_coeff, _degree);
		return res;
	}
}
TMonom TMonom::dif_z() const {
	int degZ = get_degZ();
	
	if (degZ == 0) {
		TMonom res(0, 0);
		return res;
	}
	else {
		double _coeff = coeff * degZ;
		int _degree = degree - 1;

		TMonom res(_coeff, _degree);
		return res;
	}
}


string TMonom::get_string() const {
	int degZ = get_degZ();
	int degY = get_degY();
	int degX = get_degX();
	string res = "";


	res += to_string(coeff);
	
	if		(degX == 1) res += "*x";
	else if (degX > 1)	res += "*x^" + to_string(degX);

	if (degY == 1) res += "*y";
	else if (degY > 1)	res += "*y^" + to_string(degY);

	if (degZ == 1) res += "*z";
	else if (degZ > 1)	res += "*z^" + to_string(degZ);

	return res;
}
ostream& operator<<(ostream& out, const TMonom& monom) {
	return out << monom.get_string();
}