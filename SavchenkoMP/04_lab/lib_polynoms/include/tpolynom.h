#ifndef TPOLYNOM_H
#define TPOLYNOP_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "tringlist.h"
#include "tmonom.h"
#include "tarithmeticexpression.h"

using namespace std;

#define infix name

class TPolynom {
private:
	TRingList<TMonom>* monoms;
	string name;
	
	vector<string> lexems;
	static map<string, int> priority;

	void Parse();
	void ToMonoms();
	void AddMonom(const TMonom& m);
public:
	TPolynom();
	TPolynom(const string _name);
	TPolynom(const TRingList<TMonom>& ringlist);
	TPolynom(const TPolynom& polynom);
	~TPolynom();

	const TPolynom& operator=(const TPolynom& polynom);

	TPolynom operator+(TPolynom& polynom);
	TPolynom operator-(TPolynom& polynom);
	TPolynom operator*(TPolynom& polynom);
	double operator()(double x, double y, double z);

	TPolynom dif_x() const;
	TPolynom dif_y() const;
	TPolynom dif_z() const;

private:
	bool IsOperator(const string& isopr) const;
	bool IsConst(const string& isopd) const;

	int FindOperator(int pos = 0) const;

	void ConvertInfix();
	void CorrectnessCheck();
};

#endif // !TPOLYNOM_H
