#include "tmonom.h"


TMonom::TMonom() {
	st = 0;
	koef = 0.0;
}


TMonom::TMonom(int st_, double koef_) {
	if ((st_ < 0) || (st_ >999)) {
		throw "Incorrect st";
	}

	this->st = st_;
	this->koef = koef_;
}


TMonom::TMonom(const TMonom& obj) {
	st = obj.st;
	koef = obj.koef;
}		

