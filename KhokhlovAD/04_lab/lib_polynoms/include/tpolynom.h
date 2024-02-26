#ifndef _TPOLYNOM_
#define _TPOLYNOM_
#include "tringlist.h"
using namespace std;

class TPolynom
{
private:
	TRingList* monoms;
	string name;
public:
	TPolynom();
	TPolynom(const string& name);
	TPolynom(const TRingList* monoms);
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