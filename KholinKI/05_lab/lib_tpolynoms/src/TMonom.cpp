#include "TMonom.h"

TMonom::TMonom(double c_val, int wd_val) {

	coeff = c_val;

	wrap_degree = wd_val;
}

TMonom::TMonom(const TMonom& mon) {
	coeff = mon.coeff;
	wrap_degree = mon.wrap_degree;
}


bool TMonom::operator<(const TMonom& monom)const {
	if (wrap_degree < monom.wrap_degree) {
		return true;
	}
	else {
		return false;
	}
}



bool TMonom::operator<=(const TMonom& monom)const {
	if (wrap_degree <= monom.wrap_degree) {
		return true;
	}
	else {
		return false;
	}
}


bool TMonom::operator!=(const TMonom& monom)const {
	if (wrap_degree != monom.wrap_degree) {
		return true;
	}
	else {
		return false;
	}
}

bool TMonom::operator==(const TMonom& monom)const {
	if (wrap_degree == monom.wrap_degree) {
		return true;
	}
	else {
		return false;
	}
}


TMonom TMonom::operator*(const TMonom& monom) {
	int d_x_t = wrap_degree / 100;
	int d_y_t = (wrap_degree % 100) / 10;
	int d_z_t = (wrap_degree % 10);

	int d_x_m = monom.wrap_degree / 100;
	int d_y_m = (monom.wrap_degree % 100) / 10;
	int d_z_m = (monom.wrap_degree % 10);
	if (d_x_t + d_x_m < 0 || d_x_t + d_x_m > 9) {
		throw "Degree limit!";
	}
	else if (d_y_t + d_y_m < 0 || d_y_t + d_y_m > 9) {
		throw "Degree limit";
	}
	else if (d_z_t + d_z_m < 0 || d_z_t + d_z_m > 9) {
		throw "Degree limit";
	}
	return TMonom(coeff * monom.coeff, wrap_degree + monom.wrap_degree);
}

TMonom TMonom::operator+(const TMonom& monom) {
	if (this->wrap_degree != monom.wrap_degree) {
		throw "Monomialss have different degrees!";
	}
	TMonom res(*this);
	res.coeff = coeff + monom.coeff;
	return res;
}
TMonom& TMonom::operator+=(const TMonom& monom) {
	if (this->wrap_degree != monom.wrap_degree) {
		throw "Monomialss have different degrees!";
	}
	coeff += monom.coeff;
	return *this;
}

TMonom TMonom::operator-() {
	TMonom res(*this);
	res.coeff = -coeff;
	return res;
}

istream& operator>>(istream& istr, TMonom& monom) {
	double d_x; double d_y; double d_z;
	cout << "Enter coefficient: ";
	cin >> monom.coeff;
	cout << "Enter degrees x, y, z:" << endl;
	cout << "degree x = ";
	cin >> d_x;
	cout << "degree y = ";
	cin >> d_y;
	cout << "degree z = ";
	cin >> d_z;
	monom.wrap_degree = d_x * 100 + d_y * 10 + d_z;
	return istr;
}

ostream& operator<<(ostream& ostr, const TMonom& monom) {
	cout << "Coeff: " << monom.coeff << endl;
	cout << "Wrap_degree: " << monom.wrap_degree << endl;
	cout << endl;
	return ostr;
}