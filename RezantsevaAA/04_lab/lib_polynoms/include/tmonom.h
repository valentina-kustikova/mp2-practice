#ifndef __TMONOM_H__
#define __TMONOM_H__

#include <iostream>
#include <map>

//переделать под структуру 

class TMonom {
private:
	double Coeff;
	int Degree;

public:
	TMonom(double c = 1, int d = 0);
	TMonom(const TMonom& m);
	TMonom& operator=(const TMonom& m);
	
	std::string getStringMonom() const;

	void SetCoeff(double cm);
	void SetDegree(int d);
	void ChangeCoeff(); //меняет знак коэффициента на противоположный

	double Pow(double a, double degree);
	double GetCoeff();
	int GetDegree();
	double calculateMonom(std::map<char, double>& variables);

	bool operator<(const TMonom& m) const;
	bool operator>(const TMonom& m) const;

	bool operator==(const TMonom& m) const;
	bool operator!=(const TMonom& m) const;
	
	TMonom operator*(const TMonom& m)const;
	TMonom operator+(const TMonom& m)const;
	TMonom monom_defX();
	TMonom monom_defY();
	TMonom monom_defZ();
	friend std::ostream& operator<<(std::ostream& out, TMonom& m);
	friend std::istream& operator>>(std::istream& istr, TMonom& m);
};

#endif