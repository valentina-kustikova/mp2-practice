#ifndef _TPOLINOM_H
#define _TPOLINOM_H

#include "TRingList.h"
#include "TMonom.h"
#include "ArExpression.h"
#include "SupFunctions.h"

class TPolynom {
private:
	TRingList<TMonom>* monoms;
	string polynom;
public:
	TPolynom();
	TPolynom(const string& str);
	TPolynom(const TRingList<TMonom>* monoms_list);
	TPolynom(const TRingList<TMonom>& monoms_list);
	TPolynom(const TPolynom& obj);
	~TPolynom();

	const TPolynom& operator=(const TPolynom& Q);
	bool operator==(const TPolynom& Q)const;
	TPolynom operator+(const TPolynom& Q);
	TPolynom operator-()const;
	TPolynom operator*(const TPolynom& Q);
	double operator()(double x,double y, double z)const;

	string GetPolynomString()const;
	TRingList<TMonom>* GetMonoms()const { return monoms; }

	TPolynom differentiate_by_x()const;
	TPolynom differentiate_by_y()const;
	TPolynom differentiate_by_z()const;

	friend istream& operator>>(istream& istr, TPolynom& Q);
	friend ostream& operator<<(ostream& ostr, const TPolynom& Q);
private:
	int Find_const(const string& str,const int& pos);
	double Read_const(const string& str, int& pos);
	int Read_degrees(const string& str, int& pos);
	void Add_monom(const TMonom& m);
	string CreatePolynomString();
	string CreateMonomString(double coeff,int degree_x,int degree_y, int degree_z);
	TPolynom cite_similars(TRingList<TMonom>* list_monoms);
};
#endif