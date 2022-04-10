// ����� ������� - ������������� ����������� ������ �������
// ������������ �������� ������, ������� ������, �������� ������,  
// ����� ������, �������� ���������(������� ������������� �������), 
// ��������� ���������
#pragma once
#include "Monom.h"
#include "List.h"
#include <ctype.h>

class Polynom
{

private:
	int pos = 0;
	List<Monom> monoms;

public:
	Polynom();
	Polynom(const std::string& polynomStr);
	Lexema lexem(const std::string& polynomStr);

	void parser(const std::string& polynomStr);
	void cancellation();

	bool operator==(const Polynom& _Polynom) const;
	bool operator!=(const Polynom& _Polynom) const;

	Polynom operator+(const Polynom& _Polynom) const;
	Polynom operator-(const Polynom& _polynom) const;
	Polynom operator*(const Polynom& _Polynom) const;

	Polynom operator+(const double& _Num) const;
	Polynom operator-(const double& _Num) const;
	Polynom operator*(const double& _Num) const;


	friend std::ostream& operator<< (std::ostream& out, const Polynom& _Pol)
	{
		if (_Pol.monoms.GetSize() != 0)
		{
			Node<Monom>* tmpPol = _Pol.monoms.GetHead();;
			double coeff = 0;
			int i = 0;
			while (tmpPol)
			{
				if (i != 0)
				{
					if (tmpPol->data.coeff() >= 0)
						std::cout << "+";
				}
				std::cout << tmpPol->data;
				tmpPol = tmpPol->next;
				i++;
			}
			return out;
		}
		else
		{
			cout << 0;
			return out;
		}
	}
};

