#ifndef _POLYNOM_H
#define _POLYNOM_H

#include "RingList.h"
#include "Monom.h"
#include <iostream>
#include <map>

using namespace std;

class TPolynom
{
protected:
	TRingList<TMonom>* monoms;
	string name;

	static map<string, double> symbolDict;
	void Parse_Polynom(const string& s);
public:
	TPolynom();
	TPolynom(const string& s);
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
	string ToString();
	friend ostream& operator<<(ostream& os, const TPolynom& p)
	{
		os << p.name << endl;
		os << *p.monoms << endl;
		return os;
	}
	//void Print_Polynom();
	//void Parse_Polynom(const string& s); 

protected:
	string FilteredExpression(const string& s);
	bool isOperand(char c);
	bool isValidExpression(const string& expression);
	int Is_Symbol(string sm);
	bool Is_Number(const string& str);
};
#endif 
