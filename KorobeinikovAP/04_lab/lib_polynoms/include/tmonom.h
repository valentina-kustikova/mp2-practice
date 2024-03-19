#ifndef __TMONOM_H__
#define __TMONOM_H__



struct TMonom {
	int st;
	double koef;
	TMonom();
	TMonom(int st_, double koef_);
	TMonom(const TMonom& obj);
	TMonom operator + (const TMonom& obj);

};


#endif 