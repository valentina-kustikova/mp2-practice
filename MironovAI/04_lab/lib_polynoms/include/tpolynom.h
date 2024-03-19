#ifndef TPOLYNOM_H
#define TPOLYNOP_H

#include <iostream>
#include <string>
#include "tringlist.h"
#include "tmonom.h"

using namespace std;


class TPolynom {
private:
	TRingList<TMonom> monoms;

	void del_zeros();
	void parse(string polynom);
	void x(string token, char& stage, int& i, double& coef, int& degreex, int& degreey, int& degreez);
	void y(string token, char& stage, int& i, double& coef, int& degreex, int& degreey, int& degreez);
	void z(string token, char& stage, int& i, double& coef, int& degreex, int& degreey, int& degreez);
	void c(string token, char& stage, int& i, double& coef, int& degreex, int& degreey, int& degreez);
	string preparation(string polynom);

public:
	TPolynom();
	TPolynom(const string& polynom_string);
	TPolynom(const TRingList<TMonom>& list);
	TPolynom(const TPolynom& polynom);

	const TPolynom& operator=(const TPolynom& polynom);
	bool operator==(const TPolynom& polynom) const;
	TPolynom operator+(const TPolynom& polynom);
	TPolynom operator-(const TPolynom& polynom);
	TPolynom operator*(const TPolynom& polynom);
	double operator()(double x, double y, double z);

	TPolynom dif_x() const;
	TPolynom dif_y() const;
	TPolynom dif_z() const;

	friend ostream& operator<<(ostream& buf, TPolynom& polynom) {
		if (polynom.monoms.empty())
		{
			buf << "Polynom is empty" << endl;
			return buf;
		}
		TNode<TMonom>* t = polynom.monoms.get_curr();
		while (t->value != TMonom())
		{
			if (t->next->value == TMonom())
			{
				buf << t->value << endl;
				break;
			}
			buf << t->value << " + ";
			t = t->next;
		}
		return buf;
	}
};

#endif // !TPOLYNOM_H