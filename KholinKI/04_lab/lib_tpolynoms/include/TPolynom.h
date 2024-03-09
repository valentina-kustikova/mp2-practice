#ifndef _TPOLINOM_H
#define _TPOLINOM_H

#include "TRingList.h"
#include "TMonom.h"
#include "ArExpression.h"
#include "SupFunctions.h"

class TPolynom {
	friend istream& operator>>(istream& istr, TPolynom& Q);
	friend ostream& operator<<(ostream& ostr, const TPolynom& Q);
private:
	TRingList<TMonom>* monoms;
	string polynom;
	map<string, double> values_xyz;
public:
	TPolynom();
	TPolynom(const string& str);
	TPolynom(const TRingList<TMonom>* monoms_list);
	TPolynom(const TPolynom& obj);
	~TPolynom();

	TPolynom& operator=(const TPolynom& Q);
	TPolynom operator+(const TPolynom& Q);
	TPolynom operator-(const TPolynom& Q);
	TPolynom operator*(const TPolynom& Q);
	double operator()(double x = 1,double y = 1, double z = 1);
	map<string, double> GetXYZ()const { return values_xyz; }
	void SetXYZ(double values[], int size);

	TRingList<TMonom>* GetMonoms()const;
	string GetPolynomString()const;

	TPolynom differentiate_by_x()const;
	TPolynom differentiate_by_y()const;
	TPolynom differentiate_by_z()const;
	
	
};
#endif