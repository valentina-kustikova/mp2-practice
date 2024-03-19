#include "tmonom.h"


TMonom::TMonom() {
	st = 0;
	koef = 0.0;
}


TMonom::TMonom(int st_, double koef_) {
	if (st < 0 || st >999) {
		throw "Incorrect st";
	}
	st = st_;
	koef = koef_;
}


TMonom::TMonom(const TMonom& obj) {
	st = obj.st;
	koef = obj.koef;
}		

TMonom TMonom:: operator+ (const TMonom& obj) {
	
}