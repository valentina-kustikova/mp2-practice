#ifndef __TMONOM_H__
#define __TMONOM_H__

#include<iostream>
#include<string>
using namespace std;

struct TMonom {
	int st;
	double koef;
	TMonom();
	TMonom(int st_, double koef_);
	TMonom(int degX, int degY, int degZ, double koef_);
	TMonom(const TMonom& obj);

	double TMonom::get_koef() const;

	bool operator == (const TMonom& obj);
	bool operator != (const TMonom& obj);
	bool operator < (const TMonom& obj);
	bool operator > (const TMonom& obj);

	string get_string() const;

};


#endif 