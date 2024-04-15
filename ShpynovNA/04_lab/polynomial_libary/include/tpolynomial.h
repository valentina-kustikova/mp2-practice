#ifndef _TP
#define _TP
#include "tlist.h"
#include <iostream>
#include <string>

using namespace std;

class TMonomial {
public:
	double coef;
	short int degr;
	TMonomial() {
		coef = 0;
		degr = -1;
	};
	TMonomial(double d, short int i){
		coef = d;
		degr = i;
	};

	bool operator<(const TMonomial& m) const {
		return degr < m.degr;
	};
	bool operator>(const TMonomial& m) const {
		return degr > m.degr;
	}
	bool operator<=(const TMonomial& m) const {
		return degr <= m.degr;
	}
	bool operator>=(const TMonomial& m) const {
		return degr >= m.degr;
	}
	bool operator==(const TMonomial& m) const {
		return degr == m.degr;
	}
	bool operator!=(const TMonomial& m) const {
		return degr != m.degr;
	}
	
	friend ostream& operator<<(ostream& out, const TMonomial& m) {
		int x = m.degr / 100;
		int y = (m.degr % 100) / 10;
		int z = m.degr % 10;
		out << m.coef;
		if (x != 0) out << "*x^" << x;
		if (y != 0) out << "*y^" << y;
		if (z != 0) out << "*z^" << z;
		return out;
	}
};

class TPolynomial {
protected:
	string name;
	THeadRingList<TMonomial> monomials;
public:
	TPolynomial() : monomials()
	{}
	TPolynomial(const string& n) : monomials() {
		name = n;
		DividePolynomialName(n);
	};
	TPolynomial(const THeadRingList<TMonomial>& l){
		monomials = l;
	}
	TPolynomial(const TPolynomial& p){
		name = p.name;
		monomials = p.monomials;
}

	~TPolynomial() {};

	bool operator==(const TPolynomial& p) const {
		TPolynomial tmpThis(*this);
		tmpThis.monomials.reset();
		TPolynomial tmpP(p);
		tmpP.monomials.reset();
		while (!tmpP.monomials.IsEnded() || !tmpThis.monomials.IsEnded()) {
			if ((!tmpP.monomials.IsEnded() && tmpThis.monomials.IsEnded()) || (tmpP.monomials.IsEnded() && !tmpThis.monomials.IsEnded()))
				return false;
			if (tmpP.monomials.GetCurrent()->data != tmpThis.monomials.GetCurrent()->data)
				return false;
			tmpP.monomials.next();
			tmpThis.monomials.next();
		}
		return true;
	}
	TPolynomial operator+(const TPolynomial&);
	TPolynomial operator-(const TPolynomial&);
	TPolynomial operator*(const TPolynomial&);
	const TPolynomial& operator=(const TPolynomial& p);
	double operator()(const double x, const double y, const double z) const;

	TPolynomial DerivativeX() const;
	TPolynomial DerivativeY() const;
	TPolynomial DerivativeZ() const;

	void PutNewMonomialInPlace(TMonomial& m); // TODO: private
	void DividePolynomialName(const string& name); // TODO: private

	friend ostream& operator<<(ostream& out, TPolynomial& p) {
		p.monomials.reset();
		if (p.monomials.GetCurrent()->data.coef < 0)
			out << " - ";
		out << p.monomials.GetCurrent()->data;
		try { p.monomials.next(); }
		catch  (...) { return out; }
		while (!p.monomials.IsEnded()) {
			if (p.monomials.GetCurrent()->data.coef < 0)
				out << " ";
			else if (p.monomials.GetCurrent()->data.coef > 0)
				out << " + ";
			out << p.monomials.GetCurrent()->data;
			p.monomials.next();
		}
		return out;
	}
};



void TPolynomial::PutNewMonomialInPlace(TMonomial& m) {
	monomials.reset();
	if (monomials.IsEmpty()) {
		monomials.InsertFirst(m);
		return;
	}
	if (monomials.GetCurrent()->data < m) {
		monomials.InsertFirst(m);
		return;
	}
	while ((monomials.GetCurrent()->data > m) && (!monomials.IsEnded()))
		monomials.next();
	if (monomials.GetCurrent()->data.degr == m.degr) {
		monomials.GetCurrent()->data.coef += m.coef;
		return;
	}
	if (!monomials.IsEnded())
		monomials.InsertBefore(monomials.GetCurrent()->data, m);
	else
		monomials.InsertLast(m);
}

TPolynomial TPolynomial::operator+(const TPolynomial& p) {
	TPolynomial result(*this);
	TPolynomial tmp(p);
	tmp.monomials.reset();
	while (!tmp.monomials.IsEnded() && (tmp.monomials.GetCurrent() != nullptr))
	{
			result.PutNewMonomialInPlace(tmp.monomials.GetCurrent()->data);
			tmp.monomials.next();
	}
	return result;
}
TPolynomial TPolynomial::operator-(const TPolynomial& p) {
	TPolynomial tmpNeg(p);
	tmpNeg.monomials.reset();
	while (!tmpNeg.monomials.IsEnded())
	{
		try {
			tmpNeg.monomials.GetCurrent()->data.coef *= -1; // TODO: TPolynomial operator*(const double)
			tmpNeg.monomials.next();
		}
		catch (...) {
			continue;
		}
	}
	return this->operator+(tmpNeg);
}
TPolynomial TPolynomial::operator*(const TPolynomial& p) {
	TPolynomial result;
	TPolynomial tmpThis(*this);
	TPolynomial tmpP(p);
	tmpThis.monomials.reset();
	while (!tmpThis.monomials.IsEnded()) {
		tmpP.monomials.reset();
		while (!tmpP.monomials.IsEnded()) {
			TMonomial tmpMonomial = tmpThis.monomials.GetCurrent()->data;
			TMonomial tmpMonomial1 = tmpP.monomials.GetCurrent()->data;
			double Coef = tmpMonomial.coef * tmpMonomial1.coef;
			short int Degr = tmpMonomial.degr + tmpMonomial1.degr;

			if (Degr > 999)
				throw;

			result.PutNewMonomialInPlace(TMonomial(Coef, Degr));

			tmpP.monomials.next();
		}

		tmpThis.monomials.next();
	}
	return result;
}

const TPolynomial& TPolynomial::operator=(const TPolynomial& p) {
	if (this == &p)
	{
		return *this;
	}
	name = p.name;
	monomials = p.monomials;
	return (*this);
}
double TPolynomial::operator()(const double x, const double y, const double z) const{
	TPolynomial tmp(*this);
	double result = 0;
	tmp.monomials.reset();
	while (!tmp.monomials.IsEnded()) {
		double i = tmp.monomials.GetCurrent()->data.coef;
		i *= pow(x, tmp.monomials.GetCurrent()->data.degr / 100);
		i *= pow(y, tmp.monomials.GetCurrent()->data.degr / 10 % 10);
		i *= pow(z, tmp.monomials.GetCurrent()->data.degr % 10);
		result += i;
		tmp.monomials.next();
	}
	return result;
}

TPolynomial TPolynomial::DerivativeX() const {
	TPolynomial tmp(*this);
	tmp.monomials.reset();
	TPolynomial tmpdx = TPolynomial();
	while (!tmp.monomials.IsEnded()) {
		if (tmp.monomials.GetCurrent()->data.degr / 100 != 0) {
			double Coef = tmp.monomials.GetCurrent()->data.coef * (tmp.monomials.GetCurrent()->data.degr / 100);
			int16_t Degr = tmp.monomials.GetCurrent()->data.degr - 100;
			tmpdx.PutNewMonomialInPlace(TMonomial(Coef, Degr));
		}
		tmp.monomials.next();
	}
	return tmpdx;
}
TPolynomial TPolynomial::DerivativeY() const {
	TPolynomial tmp(*this);
	tmp.monomials.reset();
	TPolynomial tmpdx = TPolynomial();
	while (!tmp.monomials.IsEnded()) {
		if (tmp.monomials.GetCurrent()->data.degr / 10 % 10 != 0) {
			double Coef = tmp.monomials.GetCurrent()->data.coef * (tmp.monomials.GetCurrent()->data.degr / 10 % 10);
			int16_t Degr = tmp.monomials.GetCurrent()->data.degr - 10;
			tmpdx.PutNewMonomialInPlace(TMonomial(Coef, Degr));
		}
		tmp.monomials.next();
	}
	return tmpdx;
}
TPolynomial TPolynomial::DerivativeZ() const {
	TPolynomial tmp(*this);
	tmp.monomials.reset();
	TPolynomial tmpdx = TPolynomial();
	while (!tmp.monomials.IsEnded()) {
		if (tmp.monomials.GetCurrent()->data.degr % 10 != 0) {
			double Coef = tmp.monomials.GetCurrent()->data.coef * (tmp.monomials.GetCurrent()->data.degr % 10);
			int16_t Degr = tmp.monomials.GetCurrent()->data.degr - 1;
			tmpdx.PutNewMonomialInPlace(TMonomial(Coef, Degr));
		}
		tmp.monomials.next();
	}
	return tmpdx;
}

void TPolynomial::DividePolynomialName(const string& str) {
	string subdiv[30];
	int k = 0;
	int kostyl[30] = {0};
	int kostyl2 = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-') {
			if (k == 0)
				kostyl[k] = -1;
			else
				kostyl[k + 1] = -1;
		}
		if ((str[i] != '+') && (str[i] != '-'))
			subdiv[k] += str[i];
		else k++;
		}
	k++;
	for (int i = 0; i < k; i++) {
		short degr = 0;
		double coef = 1.0;
		int n = 0;
		string tmpstr = "";
		while ((subdiv[i][n] != 'x') && (subdiv[i][n] != 'y') && (subdiv[i][n] != 'z')&&(n != subdiv[i].size())) {
			tmpstr += subdiv[i][n];
			if (kostyl[i] == -1)
				kostyl2 = -1;
			else
				kostyl2 = 0;
			n++;
		}
		if (tmpstr != "") {
			coef = stod(tmpstr);
			if (kostyl2 == -1)
				coef *= -1;
		}
		for (n = 0; n < subdiv[i].size(); n++) {
			if ((subdiv[i][n] == 'x')&&(subdiv[i][n+1] == '^'))
				degr += (int(subdiv[i][n + 2]) - 48) * 100;
			if ((subdiv[i][n] == 'x') && (subdiv[i][n + 1] != '^'))
				degr += 100;
			if ((subdiv[i][n] == 'y') && (subdiv[i][n + 1] == '^'))
				degr += (int(subdiv[i][n + 2]) - 48) * 10;
			if ((subdiv[i][n] == 'y') && (subdiv[i][n + 1] != '^'))
				degr += 10;
			if ((subdiv[i][n] == 'z') && (subdiv[i][n + 1] == '^'))
				degr += (int(subdiv[i][n + 2]) - 48);
			if ((subdiv[i][n] == 'z') && (subdiv[i][n + 1] != '^'))
				degr += 1;
		}
		if(coef!= 0.0)
			this->PutNewMonomialInPlace(TMonomial(coef, degr));
	}
}
#endif