#ifndef __TPOLYNOM_H__
#define __TPOLYNOM_H__

#include "tringlist.h"
#include "tmonom.h"
#include <string>
class TPolinom {

private: 
	TRingList<TMonom> monoms;
	std::string formula;
	std::map<char, double> uniques;
	void sumEqual();
	void deleteZero();
	void Sort();


	bool isMonomOperator(char op);
	bool isSeparator(char op);
	bool isOperator(char op);
	bool isVariable(char var);
	
	void getListOfMonoms(const std::string& input);
	double getCoeff(const std::string& input, int& pos);
	void updateDegree(int& degree, char variable, int degreeOfVar);

	void fillVariables(); // заполнить значениями все переменные
	double getValue(const char& variable);  // задать значения для всех переменных
public: 
	TPolinom();
	TPolinom(const string& stringPolynom);
	TPolinom(const TRingList<TMonom>& m); 
	TPolinom(const TPolinom& p);
	~TPolinom();
	std::string getStringMonoms() const;
	std::string getFormula() const;

	TPolinom operator+(const TPolinom& p);
	TPolinom operator-(const TPolinom& p);
	TPolinom operator*(const TPolinom& p); 
	void GetNormalView();
	TPolinom defX() const; //производная по x
	TPolinom defY() const; //производная по y
	TPolinom defZ() const; //производная по z
	double calculate();
	
};
#endif
