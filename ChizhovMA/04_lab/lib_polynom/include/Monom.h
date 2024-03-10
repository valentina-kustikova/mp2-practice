#ifndef _MONOM_H
#define _MONOM_H

#include "RingList.h"
#include <iostream>
#include <map>

using namespace std;

class TMonom
{
private:
	double coef;
	int degree;

public:
	TMonom();
	TMonom(const TMonom& m);
	TMonom(double c, int d);

	virtual bool operator > (const TMonom& d) const;
	virtual bool operator < (const TMonom& d) const;
	virtual bool operator == (const TMonom& d) const;
	virtual bool operator != (const TMonom& d) const;
	double GetCoef() { return coef; }
	int GetDegree() { return degree; }
	void SetCoef(double c) { coef = c; }
	friend ostream& operator<<(ostream& os, const TMonom& m) {
		os << m.coef << " " << m.degree;
		return os;
	}
};

class TPolynom
{
private:
	TRingList<TMonom>* monoms;
	string name;

	static map<string, double> symbolDict;

public:
	TPolynom();
	TPolynom(const string s);
	TPolynom(const TRingList<TMonom>& rlist);
	TPolynom(const TPolynom& p);
	~TPolynom();

	TPolynom operator+(const TPolynom& p);
	TPolynom operator-(const TPolynom& p);
	TPolynom operator*(const TPolynom& p);
	const TPolynom& operator=(const TPolynom& p);

	TPolynom difx() const;
	TPolynom dify() const;
	TPolynom difz() const;

	double operator() (double _x, double _y, double _z);

	void Parse_Polynom(const string& s);
	void Print_Polynom();
protected:
	string FilteredExpression(const string& s);
	bool isOperand(char c);
	bool isValidExpression(const string& expression);
	int Is_Symbol(string sm);
	bool Is_Number(const string& str);
};
#endif 
