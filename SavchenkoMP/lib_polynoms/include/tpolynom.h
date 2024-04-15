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
	TPolynom(TRingList<TMonom>& ringlist);
	TPolynom(TPolynom& polynom);
	~TPolynom();

	const TPolynom& operator=(const TPolynom& polynom);

	TPolynom operator+(TPolynom& polynom);
	TPolynom operator-();
	TPolynom operator-(TPolynom& polynom);
	TPolynom operator*(TPolynom& polynom);
	double operator()(double x, double y, double z);

	TPolynom dif_x();
	TPolynom dif_y();
	TPolynom dif_z();

	string get_string();
	friend ostream& operator<<(ostream& out, TPolynom& polynom);

private:
	bool IsOperator(const string& isopr) const;
	bool IsConst(const string& isopd) const;
	bool IsVariable(const string& str) const;

	int FindOperator(const string& name, int pos = 0) const;

	void ConvertInfix(string& name);
	void CorrectnessCheck(const string& name) const;


	void Reset();
	void Next();
	bool IsEnded();
	TNode<TMonom>* GetCurrent();
	TMonom GetCurrentMonom();
};

#endif // !TPOLYNOM_H