#include "tpolynom.h"

TPolynom::TPolynom() {
	monoms = nullptr;
}
TPolynom::TPolynom(const string _name) {
	name = _name;
	monoms = nullptr;
}
TPolynom::TPolynom(const TRingList<TMonom>& ringlist) {
	monoms = new TRingList<TMonom>(ringlist);
	name = "";
}
TPolynom::TPolynom(const TPolynom& polynom) {
	name = polynom.name;
	monoms = new TRingList<TMonom>(*polynom.monoms);
}
TPolynom::~TPolynom() {
	if (monoms) delete monoms;
}

const TPolynom& TPolynom::operator=(const TPolynom& polynom) {

	throw "NOT IMPLEMENTED";
}

TPolynom TPolynom::operator+(const TPolynom& polynom) {

	throw "NOT IMPLEMENTED";
}
TPolynom TPolynom::operator-(const TPolynom& polynom) {

	throw "NOT IMPLEMENTED";
}
TPolynom TPolynom::operator*(const TPolynom& polynom) {

	throw "NOT IMPLEMENTED";
}
double TPolynom::operator()(double x, double y, double z) {

	throw "NOT IMPLEMENTED";
}

TPolynom TPolynom::dif_x() const {

	throw "NOT IMPLEMENTED";
}
TPolynom TPolynom::dif_y() const {

	throw "NOT IMPLEMENTED";
}
TPolynom TPolynom::dif_z() const {

	throw "NOT IMPLEMENTED";
}
