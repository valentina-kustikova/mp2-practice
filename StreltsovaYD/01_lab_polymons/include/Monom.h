#pragma once
#ifndef _MONOM_H_
#define _MONOM_H_
#include <iostream>
#include "TNode.h"

using namespace std;

#define Monom TNode<unsigned int, double>

template<>
struct Monom
{
	unsigned int conv;
	double coef;
	Monom* pNext;

	TNode() : conv(0), coef(0), pNext(nullptr){}
	TNode(int _conv, double _coef, Monom* _pNext = nullptr) : conv(_conv), coef(_coef), pNext(_pNext) {}
	TNode(const Monom& a) : conv(a.conv), coef(a.coef), pNext(a.pNext) {}
	~TNode();

	Monom operator+(const Monom& a);
	Monom operator-() const;
	Monom operator*(const Monom& a);
	bool operator==(const Monom& a) const;
	bool operator!=(const Monom& a) const;
	bool operator<(const Monom& a) const;
	friend ostream& operator<<(ostream& out, Monom& a)
	{
		unsigned int x = a.conv / 100;
		unsigned int y = (a.conv / 10) % 10;
		unsigned int z = a.conv % 10;
		if (a.coef > 0)
			out << "+";
		out << a.coef;
		if (x != 0)
			if (x == 1)
				out << "*x";
			else
				out << "*(x^" << a.conv / 100 << ")";
		if (y != 0)
			if (y == 1)
				out << "*y";
			else
				out << "*(y^" << (a.conv / 10) % 10 << ")";
		if (z != 0)
			if (z == 1)
				out << "*z";
			else
				out << "*(z^" << a.conv % 10 << ")";
		return out;
	}
};

Monom::~TNode()
{
	conv = 0;
	coef = 0;
	pNext = nullptr;
}
Monom Monom::operator+(const Monom& a)
{
	if (conv != a.conv)
		throw "Error: different conv";
	Monom result(conv, coef + a.coef);
	return result;
};
Monom Monom::operator-() const
{
	Monom result(conv, -coef);
	return result;
};
Monom Monom::operator*(const Monom& a)
{
	int deg_x = conv / 100;
	int deg_y = (conv / 10) % 10;
	int deg_z = conv % 10;
	int deg_ax = a.conv / 100;
	int deg_ay = (a.conv / 10) % 10;
	int deg_az = a.conv % 10;
	if ((deg_x + deg_ax > 9) || (deg_y + deg_ay > 9) || (deg_z + deg_az > 9))
		throw "Error: the sum of degrees must be less than 9";
	Monom tmp(conv + a.conv, coef * a.coef);
	return tmp;
};
bool Monom::operator==(const Monom& a) const
{
	return ((conv == a.conv) && (coef == a.coef) && (pNext == a.pNext));
};
bool Monom::operator!=(const Monom& a) const
{
	return (!(*this == a));
};
bool Monom::operator<(const Monom& a) const
{
	return (conv < a.conv);
};
#endif