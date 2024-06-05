#pragma once
#include <iostream>
#include "TRingList.h"
#include "TMonom.h"
#include "arexp.h"
#include <string>

using namespace std;

class TPolynom : public ArithmeticExpression {
protected:
	TRingList<Monom>* monoms;
	void toPolynome();
	bool findLess(Monom& m, TNode<Monom>*& g);
	void setDegree(Monom&, string& param, int deg);
	void giveSimTer();
	bool isSimilar(Monom& a, Monom& b) const;
	void SortInsert(Monom& m);
public:
	TPolynom();
	TPolynom(const string& _polynome);
	TPolynom(const TRingList<Monom>& ringlist);
	TPolynom(const TPolynom& polynom);
	~TPolynom();

	const TPolynom& operator=(const TPolynom& polynom);

	TPolynom operator+(TPolynom& polynom);
	TPolynom operator-(TPolynom& polynom);
	TPolynom operator*(TPolynom& polynom);
	TPolynom operator*=(int num);
	TPolynom operator*=(float num);
	double operator()(double x, double y, double z);
	friend std::ostream& operator << (std::ostream& out, TPolynom& polynom) {
		polynom.monoms->Reset();
		while (polynom.monoms->getCurrent() != polynom.monoms->getStop()) {
			Monom monom = polynom.monoms->getCurrent()->key;
			if (monom.coef > 0 && polynom.monoms->getCurrent() != polynom.monoms->getFirst()) out << "+";
			if (monom.coef != 0) out << monom;
			polynom.monoms->Next();
		}
		return out;
	}
	friend std::istream& operator >> (std::istream& in, TPolynom& polynom) {
		string pol;
		getline(in, pol);
		polynom = TPolynom(pol);
		return in;
	}

	bool operator == (const TPolynom& polynom) const;

	TPolynom dif_x() const;
	TPolynom dif_y() const;
	TPolynom dif_z() const;

	void ToString();
};