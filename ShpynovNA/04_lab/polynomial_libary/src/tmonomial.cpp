#include "tmonomial.h"
#include <cmath>
#include <sstream>
#include <iomanip>

string TMonomial::ToString() const {
	stringstream S;
	double tmp = coef;
	if (tmp == 0) {
		S << fixed << setprecision(2) << tmp;
		return S.str();
	}
	if (tmp < 0)
	{
		tmp *= -1;
	}
	int x = degr / 100;
	int y = (degr % 100) / 10;
	int z = degr % 10;
	if ((tmp != 1) && (degr != 0)) {
		S << fixed << setprecision(2) << tmp;
		if ((x != 0) && (x != 1)) {
			S<<"*x^";
			S<<(to_string(x));
		}
		else if (x == 1) S << "*x";
		if ((y != 0) && (y != 1)) {
			S << ("*y^");
			S << (to_string(y));
		}
		else if (y == 1) S << "*y";
		if ((z != 0) && (z != 1)) {
			S << ("*z^");
			S << (to_string(z));
		}
		else if (z == 1) S << "*z";
		return S.str();
	}
	else if (degr != 0) {
		bool tmp1 = false;

		if (tmp1)
			S << "*";
		if ((x != 0) && (x != 1)) {
			S<<"x^";
			S<<(to_string(x));
			tmp1 = true;
		}
		else if (x == 1) {
			S << "x";
			tmp1 = true;
		}

		if ((y != 0) && (y != 1)) {
			S << "y^";
			S<<(to_string(y));
			tmp1 = true;
		}
		else if (y == 1) {
			S << "y";
			tmp1 = true;
		}

		if ((z != 0) && (z != 1)) {
			S << "z^";
			S << to_string(z);
			tmp1 = true;
		}
		else if (z == 1) {
			S << "z";
			tmp1 = true;
		}
	}
	else if (degr == 0) {
		S << fixed << setprecision(2) << coef;
	}
	return S.str();
}
