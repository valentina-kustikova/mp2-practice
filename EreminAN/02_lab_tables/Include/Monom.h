#pragma once
#ifndef __MONOM_H__
#define __MONOM_H__
// ����� ��� ��������� ������ 

#include <iostream>


//����������� ��� ��������� ������������� ����;
enum State
{
	START,
	NUMBER,
	END
};
//�������, �����, ��������, ����������;
enum LexType
{
	LEX_NULL, //��� �������������� ������;

	LEX_NUMBER,//�����;
	LEX_DELIM, //�����������, ��������� �� ������������ ��������;
	LEX_VAR //����������
};
//�����������
enum LexDelims
{
	LEX_DEL_NULL,//��� ������;

	LEX_DEL_ADD,//�������� +;
	LEX_DEL_SUB,//�������� -, �������� ��� �������;
	LEX_DEL_POW,//���������� � �������;
	LEX_DEL_EQUALS//���� ���������;
};




class Monom
{
private:
	double coefficient;
	int degreeX;
	int degreeY;
	int degreeZ;
public:
	Monom() { coefficient = 0;
	degreeX = 0;
	degreeY = 0;
	degreeZ = 0;
	};
	Monom(double coeff, int degX, int degY, int degZ);
	Monom(const Monom& m);

	double coeff() { return coefficient; }
	int degree() { return degreeX + degreeY + degreeZ; }

	const Monom& operator = (const Monom& _monom);
	bool operator != (const Monom& _monom) const;
	bool operator == (const Monom& _monom) const;

	Monom operator+(const Monom& _monom) const;
	Monom operator-(const Monom& _monom) const;
	Monom operator*(const Monom& _monom) const;

	Monom operator+(const double& _Num) const;
	Monom operator-(const double& _Num) const;
	Monom operator*(const double& _Num) const;
	bool degreeEq(const Monom& _monom);


	friend std::ostream& operator<< (std::ostream& out, const Monom& l)
	{
		if (l.degreeX != 0)
		{
			if (l.coefficient != 1 && l.coefficient != -1)
				if (l.degreeX != 1)
					out << l.coefficient << "x" << "^" << l.degreeX;
				else out << l.coefficient << "x";
			else
			{
				if(l.coefficient != -1)
				{
					if (l.degreeX != 1)
						out << "x" << "^" << l.degreeX;
					else out << "x";
				}
				else
				{
					if (l.degreeX != 1)
						out << "-x" << "^" << l.degreeX;
					else out << "-x";
				}
			}
		}
		else 
		{ if(l.coefficient != 1 && l.coefficient != -1)
			out << l.coefficient; 
		else
		{
			if (l.coefficient == -1)
			{
				out << "-";
			}
		}
		}
		if (l.degreeY != 0)
		{
			if (l.degreeY != 1)
				out << "y" << "^" << l.degreeY;
			else out << "y";
		}
		if (l.degreeZ != 0)
		{
			if (l.degreeZ != 1)
				out << "z" << "^" << l.degreeZ;
			else out << "z";
		}
		return out;
	}
};


class Lexema
{
public:
	int type;//��� ������� (���������, �����������, ������);
	int index;//���������� ������ �������;
	double value;//�������� ������� (��� �������� ��������);

	std::string buf;//�������� ����� �������;

	Lexema(int type = LEX_NULL, int index = LEX_NULL, const std::string& buf = "", double value = 0) : type(type), index(index), buf(buf), value(value) {};

};
#endif