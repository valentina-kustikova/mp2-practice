#pragma once
#ifndef __MONOM_H__
#define __MONOM_H__
// класс или структура Монома 

#include <iostream>
#include <string>

//Обозначения для повышения читабельности кода;
enum State
{
	START,
	NUMBER,
	END
};
//Лексемы, числа, операции, переменные;
enum LexType
{
	LEX_NULL, //для нераспознанных лексем;

	LEX_NUMBER,//числа;
	LEX_DELIM, //разделители, состоящие из неалфавитных символов;
	LEX_VAR //переменная
};
//разделители
enum LexDelims
{
	LEX_DEL_NULL,//для ошибки;

	LEX_DEL_ADD,//операция +;
	LEX_DEL_SUB,//операция -, бинарный или унарный;
	LEX_DEL_POW,//возведение в степень;
	LEX_DEL_EQUALS//знак равенства;
};




class Monom
{
private:
	double coefficient;
	int degreeX;
	int degreeY;
	int degreeZ;
public:
	Monom() {
		coefficient = 0;
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

	std::string Mstring();


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
				if (l.coefficient != -1)
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
		{
			if ((l.coefficient != 1 && l.coefficient != -1) || (l.degreeX == 0 && l.degreeY == 0 && l.degreeZ == 0))
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
	int type;//тип лексемы (константа, разделитель, ошибка);
	int index;//конкретный индекс лексемы;
	double value;//значение лексемы (для числовых констант);

	std::string buf;//хранение самой лексемы;

	Lexema(int type = LEX_NULL, int index = LEX_NULL, const std::string& buf = "", double value = 0) : type(type), index(index), buf(buf), value(value) {};

};
#endif