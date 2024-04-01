#ifndef TPOLYNOM_H
#define TPOLYNOP_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "tringlist.h"
#include "tmonom.h"

using namespace std;

#define infix name

class TPolynom {
private:
	TRingList<TMonom>* monoms;
	
	static map<string, int> priority; 

	void Parse(string& name);
	void ToMonoms(vector<string>& lexems);
	void AddMonom(const TMonom& m);
public:
	TPolynom();
	TPolynom(const string& _name);
	TPolynom(const TRingList<TMonom>& ringlist);
	TPolynom(const TPolynom& polynom);
	~TPolynom();

	const TPolynom& operator=(const TPolynom& polynom);

	const TPolynom operator+(const TPolynom& polynom) const;
	const TPolynom operator-() const;
	const TPolynom operator-(const TPolynom& polynom) const;
	const TPolynom operator*(const TPolynom& polynom) const;
	double operator()(double x, double y, double z) const;

	TPolynom dif_x() const;
	TPolynom dif_y() const;
	TPolynom dif_z() const;

	string get_string() const;
	friend ostream& operator<<(ostream& out, const TPolynom& polynom);

private:
	bool IsOperator(const string& isopr) const;
	bool IsConst(const string& isopd) const;
	bool IsVariable(const string& str) const;

	int FindOperator(const string& name, int pos = 0) const;

	void ConvertInfix(string& name);
	void CorrectnessCheck(const string& name) const;
};

#endif // !TPOLYNOM_H
