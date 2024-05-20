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
	string ToString() const;

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
		out << p.ToString();
		return out;
	}
};


#endif