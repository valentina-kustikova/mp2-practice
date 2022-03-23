#pragma once
#include "monom.h"
#include <string>

class TPolinom
{
private:
	
	string name;
	TList<TMonom> monom;
	TList<TMonom> parser (const string s);
	TList<TMonom> transform(TList<TMonom> polinom);


public:
	TPolinom();
	TPolinom(const string str);
	TPolinom(const TList<TMonom>& pol);
	TPolinom(const TMonom m);
	TPolinom(const TPolinom& polinom);
	~TPolinom();

	// операции
	TPolinom operator+(const TPolinom& polinom) const;
	TPolinom operator-(const TPolinom& polinom) const;
	TPolinom operator*(const TPolinom& polinom) const;
	
	//TPolinom operator-(); //unarka ???   

	TPolinom& operator=(const TPolinom& polinom);


	//Comparisons
	bool operator!=(const TPolinom& polinom) const;
	bool operator==(const TPolinom& polinom) const;

	// ввод/вывод
	friend std::ostream& operator<<(std::ostream &out, 
		const TPolinom& polinom);
};
