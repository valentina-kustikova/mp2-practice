#include "tmonom.h"

TMonom::TMonom() {
	coeff = 0;
	degree = -1;
}
TMonom::TMonom(const TMonom& monom) {
	coeff = monom.coeff;
	degree = monom.degree;
}
TMonom::TMonom(double _coeff, int _degree) {
	coeff = _coeff;
	degree = _degree;
}

TData* TMonom::copy() const {
	TData* monom = new TMonom(coeff, degree);
	return monom;
}

//  ¿  —–¿¬Õ»¬¿“‹?
bool TMonom::operator<(const TData& data) const {
	//if (degree < data.degree) return true;
	//else return false;
	throw "NOT IMPLEMENTED";
}
bool TMonom::operator>(const TData& data) const {
	//if (degree > data.degree) return true;
	//else return false;
	throw "NOT IMPLEMENTED";
}
bool TMonom::operator==(const TData& data) const {
	//if (degree == data.degree) return true;
	//else return false;
	throw "NOT IMPLEMENTED";
}
bool TMonom::operator!=(const TData& data) const {
	//return !(degree == data.degree);
	throw "NOT IMPLEMENTED";
}