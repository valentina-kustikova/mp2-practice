
#ifndef POLYNOM_H
#define POLYNOM_H

#include <iostream>
#include <string>
#include <map>
#include <vector>


#include "tringlist.h"
#include "tmonom.h"


using namespace std;

class TPolinom
{
private:

	TRingList<TMonom> monoms;
	string name;

	void NormalView();
	void DeleteZero(); 
	void IntoList(const string& n);
	void Sort();
public:

	TPolinom();
	TPolinom(const string& n);

	TPolinom(const TRingList<TMonom>& m);
	TPolinom(const TPolinom& p);
	~TPolinom();

	TPolinom operator-() const;
	TPolinom operator+(TPolinom& p);
	TPolinom operator-(TPolinom& p);
	TPolinom operator*(TPolinom& p);
	const TPolinom& operator=(const TPolinom& p);

	double operator()(double _x, double _y, double _z) const;

	TPolinom dif_x() const;
	TPolinom dif_y() const;
	TPolinom dif_z() const;

	string get_name() const { return name; }

	string To_string() const;

	vector <string> Parse(string name);
	bool IsConst(const string& lecsem);

	bool isValidMonomial(const string& monomial);
	bool isValidVariable(const string& monomial, int& i);
	bool isValidCoefficient(const string& monomial, int& i);
	bool checkPolynomial(const string& polyStr);

	void ProcessVariable(const string& variable, int& degree, int& i, const vector<string>& elements);
	void ProcessCoefficient(const string& element, double& coef, int& nextSign);



	friend ostream& operator<<(ostream& out, TPolinom& p)
	{

		out << p.To_string() << endl;

		return out;
	}

};





#endif