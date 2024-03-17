#include "TMonom.h"

TMonom::TMonom(double c_val, int wd_val) {
	coeff = c_val;
	if (wd_val < 0 || wd_val > 999) {
		throw "degree limit!";
	}
	wrap_degree = wd_val;
}

TMonom::TMonom(const TMonom& mon) {
	coeff = mon.GetCoeff();
	wrap_degree = mon.GetWD();
}

bool TMonom::operator<(const TMonom& monom)const {//для подобных мономов
	if (wrap_degree < monom.GetWD()) {
		return true;
	}
	else {
		return false;
	}
}

//сравнивать только степень

bool TMonom::operator<=(const TMonom& monom)const {//для подобных мономов
	if (wrap_degree <= monom.GetWD()) {
		return true;
	}
	else {
		return false;
	}
}

bool TMonom::operator>(const TMonom& monom)const {
	if (wrap_degree > monom.GetWD()) {
		return true;
	}
	else {
		return false;
	}
}

bool TMonom::operator>=(const TMonom& monom)const {
	if (wrap_degree >= monom.GetWD()) {
		return true;
	}
	else {
		return false;
	}
}

bool TMonom::operator!=(const TMonom& monom)const {//для подобных мономов
	if (wrap_degree != monom.GetWD()) {
		return true;
	}
	else {
		return false;
	}
}

bool TMonom::operator==(const TMonom& monom)const {//для равных мономов
	if (coeff == monom.GetCoeff() && wrap_degree == monom.GetWD()) {
		return true;
	}
	else {
		return false;
	}
}

TMonom& TMonom::operator=(const TMonom& monom) {
	coeff = monom.GetCoeff();
	wrap_degree = monom.GetWD();
	return *this;
}

TMonom TMonom::operator*(const TMonom& monom)const {
	int d_x_t = wrap_degree / 100;
	int d_y_t = (wrap_degree % 100) / 10;
	int d_z_t = (wrap_degree % 10);

	int d_x_m = monom.GetWD() / 100;
	int d_y_m = (monom.GetWD() % 100) / 10;
	int d_z_m = (monom.GetWD() % 10);
	if (d_x_t + d_x_m < 0 || d_x_t + d_x_m > 9) {
		throw "Degree limit!";
	}
	else if (d_y_t + d_y_m < 0 || d_y_t + d_y_m > 9) {
		throw "Degree limit";
	}
	else if (d_z_t + d_z_m < 0 || d_z_t + d_z_m > 9) {
		throw "Degree limit";
	}
	return TMonom(coeff * monom.GetCoeff(), wrap_degree + monom.GetWD());
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
	cout << "Coeff: " << monom.GetCoeff() << endl;
	cout << "Wrap_degree: " << monom.GetWD() << endl;
	cout << endl;
	return ostr;
}

