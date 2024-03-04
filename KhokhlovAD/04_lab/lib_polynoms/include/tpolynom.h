#ifndef _TPOLYNOM_
#define _TPOLYNOM_
#include "tringlist.h"
#include "tmonom.h"

using namespace std;

class TPolynom
{
private:
	TRingList<TMonom>* monoms;
	string name;
public:
	TPolynom();
	TPolynom(const string& name);
	TPolynom(const TRingList<TMonom>* monoms);
	TPolynom(const TPolynom& p);
	~TPolynom();
	TPolynom operator+(const TPolynom& polynom);
	TPolynom operator-(const TPolynom& polynom);
	TPolynom operator*(const TPolynom& polynom);
	const TPolynom& operator=(const TPolynom& polynom);
	TPolynom dif()const;
	double operator()(double x, double y, double z)const;
};

#endif