#include "tpolynom.h"
#include "theadringlist.h"
#include "tmonom.h"

#include "string"
#include <iostream>

using namespace std;

TPolynom::TPolynom() : monoms() {
}

TPolynom::TPolynom(const string& expr) : monoms() {
	this->expr = expr;
	Check(expr);
	Parse(expr);
}

TPolynom::TPolynom(const THeadRingList<TMonom>& monomlist) : monoms(monomlist) {
}

TPolynom::TPolynom(const TPolynom& p) : monoms(p.monoms), expr(p.expr) {}


void TPolynom::Check(const string& expr) {
	string items = "0123456789xyz.*^+-";
	for (int i = 0; i < expr.size(); i++) {
		if (items.find(expr[i]) == string::npos)
			throw exception("an expression contains invalid characters");
		if (i != expr.size() && !isdigit(expr[i]) && expr[i] == expr[i + 1])
			throw exception("an expression contains repetitive operators");
	}
}

void TPolynom::Parse(const string& expr) {
	string str = expr;
	while (!str.empty()) {
		double curr_coeff = -1;
		int curr_degree = 0;
		string curr_monom = str.substr(0, str.find_first_of("+-", 1));
		str.erase(0, str.find_first_of("+-", 1));
		string coef = "";
		int i = 0;
		while (i < curr_monom.size() && !isalpha(curr_monom[i])) {
			coef += curr_monom[i];
			i++;
		}
		if (coef == "+" || coef == "")
			curr_coeff = 1;
		else if (coef == "-")
			curr_coeff = -1;
		else
			curr_coeff = stod(coef);
		for (i; i < curr_monom.size(); i++) {
			if (i != curr_monom.size() && isalpha(curr_monom[i])) {
				int deg = 1;
				if (curr_monom[i + 1] == '^')
					deg = curr_monom[i + 2] - '0';
				switch (curr_monom[i]) {
				case 'x':
					curr_degree += deg * 100;
					break;
				case 'y':
					curr_degree += deg * 10;
					break;
				case 'z':
					curr_degree += deg * 1;
					break;
				}
			}
		}
		TMonom monom(curr_coeff, curr_degree);
		monoms.InsertLast(monom);
	}
	this->Cancellation();
}

void TPolynom::Cancellation() {
	TPolynom tmp(*this);
	this->monoms.Clear();
	tmp.monoms.Sort();
	tmp.monoms.Reset();
	while (!tmp.monoms.IsEnded()) {
		TMonom mn = tmp.monoms.GetCurrent()->data;
		double coef = mn.coeff;
		tmp.monoms.Next();
		while (!tmp.monoms.IsEnded() && tmp.monoms.GetCurrent()->data.degree == mn.degree) {
			coef += tmp.monoms.GetCurrent()->data.coeff;
			tmp.monoms.Next();
		}
		if (coef != 0) {
			TMonom monom(coef, mn.degree);
			this->monoms.InsertLast(monom);
		}
	}
	if (this->monoms.IsEmpty()) {
		TMonom mon(0, 0);
		this->monoms.InsertLast(mon);
	}
}

const TPolynom& TPolynom::operator=(const TPolynom& p) {
	if (this == &p)
		return *this;
	monoms = p.monoms;
	expr = p.expr;
	return *this;
}

bool TPolynom::operator==(const TPolynom& p)const {
	TPolynom polynom(*this);
	TPolynom tmp(p);
	while (!polynom.monoms.IsEnded() && !tmp.monoms.IsEnded()) {
		if (polynom.monoms.GetCurrent()->data != tmp.monoms.GetCurrent()->data)
			return false;
		polynom.monoms.Next();
		tmp.monoms.Next();
	}
	return true;
}

bool TPolynom::operator!=(const TPolynom& p) const {
	return !(*this == p);
}

bool TPolynom::operator<(const TPolynom& p) const {
	TPolynom polynom(*this);
	TPolynom tmp(p);
	while (!polynom.monoms.IsEnded() && !tmp.monoms.IsEnded()) {
		if (polynom.monoms.GetCurrent()->data >= tmp.monoms.GetCurrent()->data)
			return false;
		polynom.monoms.Next();
		tmp.monoms.Next();
	}
	return true;
}

bool TPolynom::operator>(const TPolynom& p)const {
	TPolynom polynom(*this);
	TPolynom tmp(p);
	while (!polynom.monoms.IsEnded() && !tmp.monoms.IsEnded()) {
		if (polynom.monoms.GetCurrent()->data <= tmp.monoms.GetCurrent()->data)
			return false;
		polynom.monoms.Next();
		tmp.monoms.Next();
	}
	return true;
}

TPolynom TPolynom::operator+(const TPolynom& p) {
	TPolynom p1(*this);
	TPolynom p2(p);
	TPolynom sum;
	p1.monoms.Reset();
	p2.monoms.Reset();
	while (!p1.monoms.IsEnded() && !p2.monoms.IsEnded()) {
		if (p1.monoms.GetCurrent()->data.degree > p2.monoms.GetCurrent()->data.degree) {
			sum.monoms.InsertLast(p1.monoms.GetCurrent()->data);
			p1.monoms.Next();
		}
		else if (p1.monoms.GetCurrent()->data.degree < p2.monoms.GetCurrent()->data.degree) {
			sum.monoms.InsertLast(p2.monoms.GetCurrent()->data);
			p2.monoms.Next();
		}
		else {
			p1.monoms.GetCurrent()->data.coeff += p2.monoms.GetCurrent()->data.coeff;
			if (p1.monoms.GetCurrent()->data.coeff != 0)
				sum.monoms.InsertLast(p1.monoms.GetCurrent()->data);
			p1.monoms.Next();
			p2.monoms.Next();
		}
	}
	while (!p1.monoms.IsEnded()) {
		sum.monoms.InsertLast(p1.monoms.GetCurrent()->data);
		p1.monoms.Next();
	}
	while (!p2.monoms.IsEnded()) {
		sum.monoms.InsertLast(p2.monoms.GetCurrent()->data);
		p2.monoms.Next();
	}
	if (sum.monoms.IsEmpty()) {
		TMonom mon(0, 0);
		sum.monoms.InsertLast(mon);
	}
	return sum;
}

TPolynom TPolynom::operator-()const {
	TPolynom polynom(*this);
	polynom.monoms.Reset();
	while (!polynom.monoms.IsEnded()) {
		polynom.monoms.GetCurrent()->data.coeff = polynom.monoms.GetCurrent()->data.coeff * (-1);
		polynom.monoms.Next();
	}
	return polynom;
}

TPolynom TPolynom::operator-(const TPolynom& p) {
	TPolynom dif = (*this) + (-p);
	return dif;
}

TPolynom TPolynom::operator*(const TPolynom& p) {
	TPolynom prd;
	TPolynom tmp(p);
	monoms.Reset();
	while (!monoms.IsEnded()) {
		tmp.monoms.Reset();
		while (!tmp.monoms.IsEnded()) {
			TMonom mon1 = monoms.GetCurrent()->data;
			TMonom mon2 = tmp.monoms.GetCurrent()->data;
			double new_coeff = mon1.coeff * mon2.coeff;
			int new_degree = mon1.degree + mon2.degree;
			if (new_degree > 999)
				throw exception("degree out of range");
			TMonom monom(new_coeff, new_degree);
			prd.monoms.InsertLast(monom);
			tmp.monoms.Next();
		}
		monoms.Next();
	}
	prd.Cancellation();
	return prd;
}

double TPolynom::operator()(double x, double y, double z)const {
	double result = 0;
	TPolynom polynom(*this);
	while (!polynom.monoms.IsEnded()) {
		double mon = polynom.monoms.GetCurrent()->data.coeff;
		mon *= pow(x, polynom.monoms.GetCurrent()->data.degree / 100);
		mon *= pow(y, polynom.monoms.GetCurrent()->data.degree / 10 % 10);
		mon *= pow(z, polynom.monoms.GetCurrent()->data.degree % 10);
		result += mon;
		polynom.monoms.Next();
	}
	return result;
}

TPolynom TPolynom::dx()const {
	TPolynom polynom(*this);
	TPolynom dx_polynom;
	while (!polynom.monoms.IsEnded()) {
		double new_coeff = polynom.monoms.GetCurrent()->data.coeff * (polynom.monoms.GetCurrent()->data.degree / 100);
		int new_degree = polynom.monoms.GetCurrent()->data.degree - 100;
		if (new_coeff != 0) {
			TMonom monom(new_coeff, new_degree);
			dx_polynom.monoms.InsertLast(monom);
		}
		polynom.monoms.Next();
	}
	if (dx_polynom.monoms.IsEmpty()) {
		TMonom mon(0, 0);
		dx_polynom.monoms.InsertLast(mon);
	}
	return dx_polynom;
}

TPolynom TPolynom::dy()const {
	TPolynom polynom(*this);
	TPolynom dy_polynom;
	while (!polynom.monoms.IsEnded()) {
		double new_coeff = polynom.monoms.GetCurrent()->data.coeff * (polynom.monoms.GetCurrent()->data.degree / 10 % 10);
		int new_degree = polynom.monoms.GetCurrent()->data.degree - 10;
		if (new_coeff != 0) {
			TMonom monom(new_coeff, new_degree);
			dy_polynom.monoms.InsertLast(monom);
		}
		polynom.monoms.Next();
	}
	if (dy_polynom.monoms.IsEmpty()) {
		TMonom mon(0, 0);
		dy_polynom.monoms.InsertLast(mon);
	}
	return dy_polynom;
}

TPolynom TPolynom::dz()const {
	TPolynom polynom(*this);
	TPolynom dz_polynom;
	while (!polynom.monoms.IsEnded()) {
		double new_coeff = polynom.monoms.GetCurrent()->data.coeff * (polynom.monoms.GetCurrent()->data.degree % 10);
		int new_degree = polynom.monoms.GetCurrent()->data.degree - 1;
		if (new_coeff != 0) {
			TMonom monom(new_coeff, new_degree);
			dz_polynom.monoms.InsertLast(monom);
		}
		polynom.monoms.Next();
	}
	if (dz_polynom.monoms.IsEmpty()) {
		TMonom mon(0, 0);
		dz_polynom.monoms.InsertLast(mon);
	}
	return dz_polynom;
}