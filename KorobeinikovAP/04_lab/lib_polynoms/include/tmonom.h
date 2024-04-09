#ifndef __TMONOM_H__
#define __TMONOM_H__



struct TMonom {
	int st;
	double koef;
	TMonom();
	TMonom(int st_, double koef_);
	TMonom(const TMonom& obj);
	bool operator != (const TMonom& obj) {
		if (obj.st != st || obj.koef != koef) {
			return true;
		}
		return false;
	}
};


#endif 