#pragma once

using namespace std;

class Monom
{
public:
	double cf;
	int pw;
	Monom(const double c = 0.0, const int p = 0);
	Monom(const Monom& m);
	bool operator==(const Monom& m)const;
	bool operator!=(const Monom& m)const;
	bool operator< (const Monom& m)const;
	bool operator> (const Monom& m)const;
	const Monom& operator= (const Monom& m);
};