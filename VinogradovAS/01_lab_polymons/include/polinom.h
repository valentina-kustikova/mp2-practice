
#pragma once
#include<cmath>
#include<sstream>
#include "headlist.h"
#include "monom.h"
using namespace std;

class TPolynom : public THeadList<TMonom>
{
protected:
	void Parser(const std::string& polyStr);
	void Print(std::ostream& os) const;
	TPolynom(const TPolynom& other);
public:
	
	TPolynom();
	void AddMonom(TMonom m);
	
	TPolynom(const std::string& polyStr);
	void AddMonom(double coeff, int x, int y, int z);
	TPolynom& operator=(TPolynom& other);
	
	bool operator==(const TPolynom& other) const;
	bool operator!=(const TPolynom& other) const;
	TPolynom operator+(const TPolynom& other); 
	TPolynom operator-(const TPolynom& other) ;
	TPolynom operator*(const TPolynom& other) ;
	TPolynom operator*(const TMonom& monom) ;
	TPolynom operator*(const double a) ;
	string PolStr( TPolynom& p) {
		TNode<TMonom>* _pCurr = p.pFirst;
		string res;
		stringstream os;
		//Нулевой полином
		if (_pCurr == p.pStop)
		{
			os << "0";
			return os.str();
		}

		//Вывод для первого монома полинома
		TMonom m = _pCurr->value;
		double absCoeff = fabs(m.coeff);

		if (m.coeff < 0) os << "- ";

		//Моном был константный
		if (m.IsConst())
		{
			os << absCoeff;
		}
		//Не константный
		else
		{
			if (absCoeff != 1) os << absCoeff << "*";
			os << m;
		}

		_pCurr = _pCurr->pNext;

		for (; _pCurr != p.pStop; _pCurr = _pCurr->pNext)
		{
			TMonom m = _pCurr->value;
			double absCoeff = fabs(m.coeff);

			if (m.coeff < 0) os << " - ";
			else os << " + ";

			if (m.IsConst())
			{
				os << absCoeff;
			}
			else
			{
				if (absCoeff != 1)
					os << absCoeff << "*";
				os << m;
			}
		}
		return os.str();
	}
	double operator() (double x, double y, double z);

	friend std::ostream& operator<<(std::ostream& os, TPolynom& p)
		
	{ 
		TNode<TMonom>* _pCurr = p.pFirst;

		
		//Нулевой полином
		if (_pCurr == p.pStop)
		{
			os << "0";
			return os;
		}

		//Вывод для первого монома полинома
		TMonom m = _pCurr->value;
		double absCoeff = fabs(m.coeff);

		if (m.coeff < 0) os << "- ";

		//Моном был константный
		if (m.IsConst())
		{
			os << absCoeff;
		}
		//Не константный
		else
		{
			if (absCoeff != 1) os << absCoeff << "*";
			os << m;
		}

		_pCurr = _pCurr->pNext;

		for (; _pCurr != p.pStop; _pCurr = _pCurr->pNext)
		{
			TMonom m = _pCurr->value;
			double absCoeff = fabs(m.coeff);

			if (m.coeff < 0) os << " - ";
			else os << " + ";

			if (m.IsConst())
			{
				os << absCoeff;
			}
			else
			{
				if (absCoeff != 1)
					os << absCoeff << "*";
				os << m;
			}
		}
		return os;
	}

	friend std::istream& operator>>(std::istream& is, TPolynom& p)
	{
		string polyStr;
		is >> polyStr;
		p.Parser(polyStr);
		return is;
	}

	friend TPolynom operator*(TMonom& m,TPolynom& p) 
	{
		return p * m;
	}

	friend TPolynom operator*(
		double a,
		TPolynom& p)
	{
		return p * a;
	}

	
};
 

