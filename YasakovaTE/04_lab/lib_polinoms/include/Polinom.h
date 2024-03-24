#include <iostream>
#include <cstdio>
#include <string>

#include "list.h"
#include "headlist.h"
#include "monom.h"

using namespace std;

class TPolinom {
private:
	THeadList<Monom> curmon;
public:
	TPolinom() {  }
	TPolinom(const string &s);
	TPolinom(const TPolinom &);
	~TPolinom();
	TPolinom operator+ (const TPolinom & _polinom);
	TPolinom operator- (const TPolinom & _polinom)
	{
		TPolinom res = (*this) + (-1.0) * _polinom;
		return res;
	}
	TPolinom operator* (const TPolinom & _polinom);
	TPolinom operator* (double d);
	friend TPolinom operator* (double d, TPolinom& _polinom) { return _polinom * d; };
	TPolinom& operator= (const TPolinom& _polinom);
	bool operator== (const TPolinom& curpol) const { return (*this).curmon == curpol.curmon; };
	bool operator!= (const TPolinom& curpol) const { return !((*this) == curpol); };
	friend ostream& operator<< (ostream& out, const TPolinom& _polinom);
	friend istream& operator>> (istream& in, TPolinom& _polinom)
	{
		string s;
		in >> s;
		_polinom = TPolinom(s);
		return in;
	}
	friend TPolinom operator* (double d, const TPolinom& p);
	double operator()(double x, double y, double z);
};

