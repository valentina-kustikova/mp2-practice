#ifndef _TPOLYNOM_
#define _TPOLYNOM_
#include <iostream>
#include "tringlist.h"
#include "tmonom.h"

using namespace std;

class TPolynom
{
private:
	TRingList<TMonom> monoms; 
	string name;
	void update();
	void updatename();
	void updatenull();
public:
	TPolynom();
	TPolynom(const string& name);
	TPolynom(const TRingList<TMonom> monoms);
	TPolynom(const TPolynom& p);
	TPolynom operator+(const TPolynom& polynom);
	TPolynom operator-(const TPolynom& polynom);
	TPolynom operator*(const TPolynom& polynom);
	TPolynom operator*(const double c);
	const TPolynom& operator=(const TPolynom& polynom);
	TPolynom dif()const;
	TPolynom dif_x()const;
	TPolynom dif_y()const;
	TPolynom dif_z()const;
	string get_name()const { return name; }
	void InsertSort(const TMonom& m);
	double operator()(double x, double y, double z)const;
	friend ostream& operator<< (ostream& out, const TPolynom& polynom)
	{
		out << polynom.name << endl;
		return out;
	}
	friend istream& operator>> (istream& in, TPolynom& polynom)
	{
		string s;
		in >> s;
		polynom = TPolynom(s);
		return in;
	}
};

#endif