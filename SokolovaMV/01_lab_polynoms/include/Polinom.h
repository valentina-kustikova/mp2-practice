#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "HeadList.h"
#include "Monom.h"


class TPolinom : public THeadList<TMonom>
{
private:
	void addMonom(const TMonom& m);

public:

	TPolinom();
	TPolinom(const int& m);
	TPolinom(const TMonom& m);
	TPolinom(const TPolinom& p);
	TPolinom operator*(const double& c) const;
	TPolinom operator*(const TMonom& m) const;
	TPolinom operator*(const TPolinom& p) const;
	TPolinom& operator=(const TPolinom& p);
	bool operator==(const TPolinom& p) const;
	bool operator==(const string& s) const;
	TPolinom operator-(const TMonom& p) const;
	TPolinom operator-(const TPolinom& p) const;
	TPolinom operator+(const TPolinom& p) const;
	/*TPolinom operator+(const TMonom& m) const;/**/
	friend ostream& operator<<(ostream& os, TPolinom& p)
	{
		//if (p.pFirst->data.coeff == 0)
		//	os << "0";
		//else {
		for (p.reset(); !p.isEnd(); p.goNext()) {
			os << p.getCurrdata();
			if (p.pCurr->pNext != p.pStop)
			{
				os << " + ";
			}
		}
		//}
		if (p.isEmpty())
			os << 0;
		os << "\n";
		return os;
	}
	friend istream& operator>>(istream& in, TPolinom& P)
	{
		string str;
		in >> str;
		//        getline(in, str);
		P = TPolinom(str);
		return in;
	}
	double operator() (double x, double y, double z);
	TPolinom(const string& str);

};