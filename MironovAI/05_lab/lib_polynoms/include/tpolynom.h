#ifndef TPOLYNOM_H
#define TPOLYNOP_H

#include <iostream>
#include <string>
#include "tringlist.h"
#include "tmonom.h"

using namespace std;


class TPolynom {
private:
	TRingList<TMonom> monoms;
	string name;

	void del_zeros();
	void parse(string polynom);
	void x(string token, char& stage, int& i, double& coef, int& degreex, int& degreey, int& degreez);
	void y(string token, char& stage, int& i, double& coef, int& degreex, int& degreey, int& degreez);
	void z(string token, char& stage, int& i, double& coef, int& degreex, int& degreey, int& degreez);
	void c(string token, char& stage, int& i, double& coef, int& degreex, int& degreey, int& degreez);
	string preparation(string polynom);
	void set_string();

public:
	TPolynom();
	TPolynom(const string& polynom_string);
	TPolynom(const TRingList<TMonom>& list);
	TPolynom(const TPolynom& polynom);

	const TPolynom& operator=(const TPolynom& polynom);
	bool operator==(const TPolynom& polynom) const;
	TPolynom operator+(const TPolynom& polynom);
	TPolynom operator-(const TPolynom& polynom);
	TPolynom operator*(const TPolynom& polynom);
	double operator()(double x, double y, double z);
	bool operator<(const TPolynom& polynom) const;
	string get_name() const { return name; }
	TPolynom dif_x() const;
	TPolynom dif_y() const;
	TPolynom dif_z() const;

	friend ostream& operator<<(ostream& buf, TPolynom& polynom) {
		if (polynom.monoms.empty())
		{
			buf << "Polynom is empty" << endl;
			return buf;
		}
		TNode<TMonom>* t = polynom.monoms.get_curr();
		while (t->value != TMonom())
		{
			if (t->next->value == TMonom())
			{
				buf << t->value;
				break;
			}
			buf << t->value << " + ";
			t = t->next;
		}
		return buf;
	}
	friend istream& operator >> (istream& buf, TPolynom& polynom)
	{
		string poly; 
		cout << "input a polynom\n";
		buf >> poly;
		try
		{
			TPolynom t(poly);
			TRingList<TMonom> k(t.monoms);
			polynom.monoms = k;
			polynom.name = t.name;
			return buf;
		}
		catch (string ex)
		{
			throw ex;
		}
	}

};

namespace std
{
	template <>
	struct hash<TPolynom>
	{
		size_t operator()(const TPolynom& obj) const
		{
			return std::hash<std::string>()(obj.get_name());
		}
	};
}
#endif // !TPOLYNOM_H