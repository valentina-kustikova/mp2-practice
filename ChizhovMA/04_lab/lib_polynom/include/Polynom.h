#ifndef _POLYNOM_H
#define _POLYNOM_H

#include "RingList.h"
#include "Monom.h"
#include <iostream>
#include <map>

using namespace std;

class TPolynom
{
private:
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
	TPolynom operator-() const;
	const TPolynom& operator=(const TPolynom& p);

	TPolynom difx() const;
	TPolynom dify() const;
	TPolynom difz() const;

	void HandleX(const string& str, int& i, string& deg);
	void HandleY(const string& str, int& i, string& deg);
	void HandleZ(const string& str, int& i, string& deg);
	void ProcessMonom(const string& numStr, const string& str, int& i, const string& deg, int& flag, TRingList<TMonom>* monomList);
	void CreateAndInsertMonom(double koef, int degree, TRingList<TMonom>* monomList);

	string ProcessDegreeZero(const string& str, const string& coef_str, double& k);
	string ProcessDegreeNonZero(const string& str, const string& coef_str, double& k,int& f);
	string ProcessDegreeX(const string& str, const string& coef_str, double& k, int& d, int& flag);
	string ProcessDegreeY(const string& str, const string& coef_str, double& k, int& d, int& flag);
	string ProcessDegreeZ(const string& str, const string& coef_str, double& k, int& d, int& flag);

	double operator() (double _x, double _y, double _z);
	string ToString();
	friend ostream& operator<<(ostream& os, const TPolynom& p)
	{
		os << p.name << endl;
		os << *p.monoms << endl;
		return os;
	}

protected:
	string FilteredExpression(const string& s);
	bool isOperand(char c);
	bool isValidExpression(const string& expression);
	int Is_Symbol(string sm);
	bool Is_Number(const string& str);
};
#endif 
