#include "TMonom.h"

TMonom::TMonom(double c_val, int wd_val) {
	coeff = c_val;
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

bool TMonom::operator!=(const TMonom& monom)const {//для подобных мономов
	if (wrap_degree != monom.GetWD()) {
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
	if ((wrap_degree + monom.GetWD()) <= 999 && (wrap_degree + monom.GetWD()) >= 0) {
		return TMonom(coeff * monom.GetCoeff(), wrap_degree + monom.GetWD());
	}
	else {
		throw "Degree limit!";
	}
}