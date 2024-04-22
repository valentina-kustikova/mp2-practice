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




string TMonom::get_string() const {
	int degZ = st % 10;
	int degY = (st % 100) / 10;
	int degX = st / 100;
	string res = "";


	res += to_string(koef);

	if (degX == 1) res += "*x";
	else if (degX > 1)	res += "*x^" + to_string(degX);

	if (degY == 1) res += "*y";
	else if (degY > 1)	res += "*y^" + to_string(degY);

	if (degZ == 1) res += "*z";
	else if (degZ > 1)	res += "*z^" + to_string(degZ);

	return res;
}


double TMonom::get_koef() const {
	return koef;
}