#ifndef __TMONOM_H__
#define __TMONOM_H__

#include<iostream>
#include<string>
using namespace std;

class TMonom {
private:
	int st;
	double koef;
public:
	TMonom();
	TMonom(int st_, double koef_);
	TMonom(int degX, int degY, int degZ, double koef_);
	TMonom(const TMonom& obj);

	double get_koef() const;
	int get_degree() const {
		return st;
	}

	int get_degX() const;
	int get_degY() const;
	int get_degZ() const;


	void set_koef(double _koef) {
		koef = _koef;
	}
	void set_degree(int _degree) {
		st = _degree;
	}
	void set_degree(int degX, int degY, int degZ) {
		st = degX * 100 + degY * 10 + degZ;
	}



	TMonom operator*(const TMonom& monom) const;

	bool operator == (const TMonom& obj);
	bool operator != (const TMonom& obj);
	bool operator < (const TMonom& obj);
	bool operator > (const TMonom& obj);

	string get_string() const;


	TMonom dif_x() const;
	TMonom dif_y() const;
	TMonom dif_z() const;

};


#endif 