#pragma once
#include "monom.h"
#include "headlist.h"
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class TPolinom
{
private:
	THeadList<TMonom> listmonoms;
	THeadList<TMonom> unions(THeadList<TMonom>& m);
public:
	TPolinom();
	TPolinom(int n, int m[][1]);
	TPolinom(const TPolinom& pol);
	TPolinom(string str);
	double calculation();
	double operator()(double x, double y, double z);
	TPolinom& operator=(const TPolinom& pol);
	bool operator==(const TPolinom& pol) const;
	TPolinom operator-(const TPolinom& pol) const;//Ѕинарный минус
	TPolinom operator-() const; //”нарный минус
	TPolinom operator+(const TMonom& mon) const;
	TPolinom operator+(const TPolinom& pol) const;
	TPolinom operator*(const TPolinom& pol) const;
	TPolinom operator*(const double con) const;
	friend ostream& operator<<(ostream& ostr, const TPolinom& pm);
	friend istream& operator>>(istream& istr, TPolinom& pm);
};

