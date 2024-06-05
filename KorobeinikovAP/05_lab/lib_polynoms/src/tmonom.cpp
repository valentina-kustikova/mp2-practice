#include "tmonom.h"



TMonom::TMonom() {
	st = int();
	koef = double();
}


TMonom::TMonom(int st_, double koef_) {
	if ((st_ < 0) || (st_ >999)) {
		throw "Incorrect st";
	}

	this->st = st_;
	this->koef = koef_;
}

TMonom::TMonom(int degX, int degY, int degZ, double koef_) {
	int tmp_st = degX * 100 + degY * 10 + degZ;
	if (tmp_st < 0 || tmp_st>999) {
		throw "Error: st incorrect";
	}
	st = tmp_st;
	koef = koef_;
}


TMonom::TMonom(const TMonom& obj) {
	st = obj.st;
	koef = obj.koef;
}		

bool TMonom:: operator == (const TMonom& obj) {
	if (obj.st == st) {
		return true;
	}
	return false;
}



bool TMonom:: operator != (const TMonom& obj) {
	if (obj.st != st || obj.koef != koef) {
		return true;
	}
	return false;
}

bool TMonom:: operator < (const TMonom& obj) {
	if (st < obj.st) {
		return true;
	}
	return false;
}

bool TMonom:: operator > (const TMonom& obj) {
	if (st > obj.st) {
		return true;
	}
	return false;
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

	int res_degree = st + monom.st;
	double res_coeff = koef * monom.koef;

	TMonom res(res_degree, res_coeff);
	return res;
}




string TMonom::get_string() const {
	int degZ = st % 10;
	int degY = (st % 100) / 10;
	int degX = st / 100;
	string res = "";


	res += to_string(koef).erase(to_string(koef).size() - 4);;
	res.replace(res.find(","), 1, ".");

	if (degX == 1) res += "*x";
	else if (degX > 1)	res += "*x^" + to_string(degX); //.erase(to_string(degX).size() - 4)

	if (degY == 1) res += "*y";
	else if (degY > 1)	res += "*y^" + to_string(degY); //.erase(to_string(degY).size() - 4)

	if (degZ == 1) res += "*z";
	else if (degZ > 1)	res += "*z^" + to_string(degZ); //.erase(to_string(degZ).size() - 4)

	return res;
}


int TMonom::get_degX() const {
	int degX = st / 100;
	return degX;
}
int TMonom::get_degY() const {
	int degY = (st / 10) % 10;
	return degY;
}
int TMonom::get_degZ() const {
	int degZ = st % 10;
	return degZ;
}


double TMonom::get_koef() const {
	return koef;
}



TMonom TMonom::dif_x() const {
	int degX = get_degX();

	if (degX == 0) {
		TMonom res(0, 0);
		return res;
	}
	else {
		double _coeff = koef * degX;
		int _degree = st - 100;

		TMonom res(_degree, _coeff);
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
		double _coeff = koef * degY;
		int _degree = st - 10;

		TMonom res(_degree, _coeff);
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
		double _coeff = koef * degZ;
		int _degree = st - 1;

		TMonom res(_degree, _coeff);
		return res;
	}
}