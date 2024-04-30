#ifndef _TP
#define _TP
#include "tmonomial.h"


using namespace std;

class TPolynomial {
private:
	void PutNewMonomialInPlace(TMonomial& m);
	void DividePolynomialName(const string& name);
protected:
	string name;
	THeadRingList<TMonomial> monomials;
public:
	TPolynomial() : monomials(){}
	TPolynomial(const string& n) : monomials() {
		name = n;
		DividePolynomialName(n);
	};
	TPolynomial(const THeadRingList<TMonomial>& l){	monomials = l;}
	TPolynomial(const TPolynomial& p){
		name = p.name;
		monomials = p.monomials;
}

	~TPolynomial() {};

	bool operator==(const TPolynomial& p) const;
	TPolynomial operator+(const TPolynomial&);
	TPolynomial operator-(const TPolynomial&);
	TPolynomial operator*(const TPolynomial&);
	TPolynomial operator*(const double&);
	const TPolynomial& operator=(const TPolynomial& p);
	double operator()(const double x, const double y, const double z) const;

	TPolynomial DerivativeX() const;
	TPolynomial DerivativeY() const;
	TPolynomial DerivativeZ() const;

	friend ostream& operator<<(ostream& out, TPolynomial& p) {
		p.monomials.reset();
		if ((p.monomials.GetCurrent()->data.coef == 0) && (p.monomials.GetCurrent()->data.degr == 0))
			out << "0";
		else if ((p.monomials.GetCurrent()->data.coef == 0) && (p.monomials.GetCurrent()->data.degr != 0)){}
		else if (p.monomials.GetCurrent()->data.coef < 0)
			out<< "-" << p.monomials.GetCurrent()->data;
		else 
			out << p.monomials.GetCurrent()->data;
		try { p.monomials.next(); }
		catch  (...) { return out; }
		int k = -1;
		while (!p.monomials.IsEnded()) {
			k++;
			if (p.monomials.GetCurrent()->data.coef < 0)
				out << " - ";
			else if (p.monomials.GetCurrent()->data.coef > 0)
				out << " + ";
			else if ((p.monomials.GetCurrent()->data.coef == 0) && (k == 0))
				return out;
			else if ((p.monomials.GetCurrent()->data.coef == 0) && (k != 0)) {
				p.monomials.next();
				continue;
			}
			out << p.monomials.GetCurrent()->data;
			p.monomials.next();
		}
		return out;
	}
};


#endif