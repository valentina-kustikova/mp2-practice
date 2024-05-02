#ifndef __POLYNOM_H__
#define __POLYNOM_H__

#include "theadringlist.h"
#include "tmonom.h"

#include <map>
#include <iostream>

using namespace std;

class TPolynom {
private:
	THeadRingList<TMonom> monoms;
	string expr;
	void Check(const string& expr);
	void Parse(const string& expr);
	void Cancellation();
public:
	TPolynom();
	TPolynom(const string& expr);
	TPolynom(const THeadRingList<TMonom>& monomlist);
	TPolynom(const TPolynom& p);
	const TPolynom& operator=(const TPolynom& p);
	bool operator==(const TPolynom& p)const;
	TPolynom operator+(const TPolynom& p);
	TPolynom operator-()const;
	TPolynom operator-(const TPolynom& p);
	TPolynom operator*(const TPolynom& p);
	double operator()(double x, double y, double z)const;
	TPolynom dx()const;
	TPolynom dy()const;
	TPolynom dz()const;
	friend ostream& operator<<(ostream& out, TPolynom& p) {
		p.monoms.Reset();
		int i = 0;
		while (!p.monoms.IsEnded()) {
			if (p.monoms.GetCurrent()->data.coeff > 0 && i > 0)
				out << "+";
			out << p.monoms.GetCurrent()->data;
			p.monoms.Next();
			i++;
		}
		return out;
	}
};

#endif