#ifndef TPOLYNOM_H
#define TPOLYNOP_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "tringlist.h"
#include "tmonom.h"

using namespace std;

class TPolynom {
private:
	TRingList<TMonom>* monoms;
	
	static map<string, int> priority; 

	void parse(string& name);
	void to_monoms(vector<string>& lexems);
	void add_monom(const TMonom& m);
public:
	TPolynom();
	TPolynom(const string& _name);
	TPolynom(TRingList<TMonom>& ringlist);
	TPolynom(TPolynom& polynom);
	~TPolynom();

	bool operator<(TPolynom& polynom);
	bool operator>(TPolynom& polynom);
	bool operator<=(TPolynom& polynom);
	bool operator>=(TPolynom& polynom);
	bool operator==(TPolynom& polynom);
	bool operator!=(TPolynom& polynom);

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
	bool is_operator(const string& isopr) const;
	bool is_const(const string& isopd) const;
	bool is_variable(const string& str) const;

	int find_operator(const string& name, int pos = 0) const;

	void convert_infix(string& name);
	void correctness_check(const string& name) const;


	void reset();
	void next();
	bool ended();
	TNode<TMonom>* get_curr();
	TMonom get_current_monom();
};

#endif // !TPOLYNOM_H
