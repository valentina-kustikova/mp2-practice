#pragma once
#include "Polynom.h"
#include <iostream>
Polynom::Polynom() {
}

Polynom::Polynom(const std::string& polynomStr)
{
	Monom fictitious(999, -1, -1, -1);
	parser(polynomStr);
}

Lexema Polynom::lexem(const std::string& polynomStr)
{

	char* LEX_DELIMS[] = { "+","-","^","=" };
	pos;
	Lexema lexem;
	char currentChar;
	State currentState = START;
	while (true)
	{
		currentChar = polynomStr[pos];
		switch (currentState)
		{
		case START:
			if (currentChar == ' ')//���� ������;
			{
				pos++;
				currentState = START;
			}
			else if (isdigit(currentChar))//���� �����;
			{
				lexem.buf += currentChar;//�������� �� � ����� ���������� ������;
				pos++;
				currentState = NUMBER;
			}
			else if (currentChar == 'x' || currentChar == 'y' || currentChar == 'z')//���� ����������;
			{
				pos++;
				Lexema lexem11;
				if (currentChar == 'x')
				{
					Lexema lexem1(LEX_VAR, LEX_NULL, "x");
					lexem11 = lexem1;
				}
				if (currentChar == 'y')
				{
					Lexema lexem1(LEX_VAR, LEX_NULL, "y");
					lexem11 = lexem1;
				}
				if (currentChar == 'z')
				{
					Lexema lexem1(LEX_VAR, LEX_NULL, "z");
					lexem11 = lexem1;
				}
				return lexem11;
			}
			else//���� ;
			{
				lexem.buf += currentChar;
				pos++;
				const char* tmp = lexem.buf.c_str();
				int index = -1;
				for (int i = 0; i < 4; i++)//���� � �������;
				{
					if (strcmp(tmp, LEX_DELIMS[i]) == 0)
					{

						index = i;
						i = 5;
					}
				}
				if (index != -1)
				{
					if (index == 0)
					{
						Lexema lexem2(LEX_DELIM, LEX_DEL_ADD);
						return lexem2;
					}
					if (index == 1)
					{
						Lexema lexem2(LEX_DELIM, LEX_DEL_SUB);
						return lexem2;
					}
					if (index == 2)
					{
						Lexema lexem2(LEX_DELIM, LEX_DEL_POW);
						return lexem2;
					}
					if (index == 3)
					{
						Lexema lexem2(LEX_DELIM, LEX_DEL_EQUALS);
						return lexem2;
					}
				}
				else
				{
					if (pos == polynomStr.length() + 1)//����� ������;
					{
						Lexema Lexem0(LEX_DELIM, LEX_DEL_EQUALS);
						return Lexem0;
					}
					else
					{
						//cout << "�������������� ����. ��� ������ ������� ������� 102, polinom.cpp";
						throw "error";
						Lexema Lexem00(LEX_NULL, LEX_NULL);
						return Lexem00;
					}
				}
			}
			break;

		case NUMBER://������������� �������� ��������;
			if (currentChar == ' ')//���� ������;
			{
				pos++;
				currentChar = polynomStr[pos];
				currentState = NUMBER;
			}
			if (isdigit(currentChar) || currentChar == '.' || currentChar == ',')//���� �����;
			{
				if (currentChar == ',')
					currentChar = '.';
				lexem.buf += currentChar;
				pos++;
				currentState = NUMBER;
			}
			else
			{
				Lexema Lexem3(LEX_NUMBER, LEX_NULL, lexem.buf, atof(lexem.buf.c_str()));
				return Lexem3;
			}
			break;
		}
	}
};


void Polynom::parser(const std::string& polynomStr)
{
	monoms.Clean();
	int length = polynomStr.length();
	Lexema currentLex = lexem(polynomStr);
	for (int i = 0; i < polynomStr.length(); i++)
	{
		double coef = 1, degX = 0, degY = 0, degZ = 0, X = 0, Y = 0, Z = 0;
		if (currentLex.type == LEX_DELIM && currentLex.index == LEX_DEL_SUB)
		{
			coef = -1;
			currentLex = lexem(polynomStr);
		}
		if (currentLex.type == LEX_NUMBER)
		{
			coef *= currentLex.value;
			currentLex = lexem(polynomStr);
		}


		while (currentLex.type != LEX_DELIM)
		{
			if (currentLex.type == LEX_VAR)
			{
				if (currentLex.buf == "x")
				{
					if (degX >= 1)//��� ������ ���� 2xxx;
						degX++;
					else degX = 1;
					X = 1;
				}
				if (currentLex.buf == "y")
				{
					if (degY >= 1)//��� ������ ���� 2yyy;
						degY++;
					else degY = 1;
					Y = 1;
				}
				if (currentLex.buf == "z")
				{
					if (degZ >= 1)//��� ������ ���� 2zzz;
						degZ++;
					else degZ = 1;
					Z = 1;
				}
				currentLex = lexem(polynomStr);
			}
			if (currentLex.type == LEX_DELIM && currentLex.index == LEX_DEL_POW)
			{
				currentLex = lexem(polynomStr);
				if (currentLex.type == LEX_NUMBER)
				{
					if (X == 1)
					{
						int degXx = degX;
						degX = currentLex.value;
						degX = degX + (degXx - 1);
						X = 0;
					}
					if (Y == 1)
					{
						int degYy = degY;
						degY = currentLex.value;
						degY = degY + (degYy - 1);
						Y = 0;
					}
					if (Z == 1)
					{
						int degZz = degZ;
						degZ = currentLex.value;
						degZ = degZ + (degZz - 1);
						Z = 0;
					}
					currentLex = lexem(polynomStr);
				}
				else {
					throw logic_error("Error in expression");
				}
			}
			else X = 0, Y = 0, Z = 0;

			if (currentLex.type == LEX_NUMBER)//���� ����� ������ ��� ���: 2xy3z;
			{
				coef = coef * currentLex.value;
				currentLex = lexem(polynomStr);
			}
		}


		if (currentLex.type == LEX_DELIM && (currentLex.index == LEX_DEL_ADD || currentLex.index == LEX_DEL_SUB || currentLex.index == LEX_DEL_EQUALS))
		{
			if (currentLex.index == LEX_DEL_ADD && pos == 1)//���� � ����� ������ ��������� +: +2x^2+5...;
			{
				currentLex = lexem(polynomStr);
			}
			else
			{
				Monom cur_monom(coef, degX, degY, degZ);
				monoms.InsertToTail(cur_monom);
				if (currentLex.index == LEX_DEL_EQUALS)
					i = polynomStr.length();
			}
		}
		int P = 0;
		if (currentLex.index == LEX_DEL_ADD)
		{
			currentLex = lexem(polynomStr);
			if (currentLex.index == LEX_DEL_ADD)
				currentLex = lexem(polynomStr);//���� ���� x++y=x+y;
			P = 1;
		}
		if (currentLex.index == LEX_DEL_SUB && P != 1)
		{
			Lexema currentLexCopy = currentLex;
			int posCopy = pos;
			currentLexCopy = lexem(polynomStr);
			pos = posCopy;
			if (currentLexCopy.index == LEX_DEL_SUB)
			{
				pos++;
				currentLex = lexem(polynomStr);//���� ���� x--y=x+y;
			}
			if (currentLexCopy.index == LEX_DEL_ADD)
			{
				pos++;
				currentLex.index = LEX_DEL_SUB;//���� ���� x-+y=x-y;
			}
			P = 0;
		}
	}
};





Polynom Polynom::operator+(const Polynom& _polynom) const
{
	Polynom Res = *this;
	Node<Monom>* tmppoltwo;
	tmppoltwo = _polynom.monoms.GetHead();

	while (tmppoltwo)
	{
		Res.monoms.InsertToTail(tmppoltwo->data);
		tmppoltwo = tmppoltwo->next;
	}
	Res.cancellation();
	return Res;
}

Polynom Polynom::operator-(const Polynom& _polynom) const
{
	return *this + _polynom * (-1);
}


Polynom Polynom::operator*(const Polynom& _polynom) const
{
	Polynom Res;
	Node<Monom>* tmpPol;
	Node<Monom>* tmppoltwo;
	tmpPol = this->monoms.GetHead();
	tmppoltwo = _polynom.monoms.GetHead();


	while (tmpPol)
	{
		while (tmppoltwo)
		{
			Res.monoms.InsertToTail(tmpPol->data * tmppoltwo->data);
			tmppoltwo = tmppoltwo->next;
		}
		tmppoltwo = _polynom.monoms.GetHead();
		tmpPol = tmpPol->next;
	}
	Res.cancellation();
	return Res;
}





void Polynom::cancellation()//�������� ���������;
{
	if (this->monoms.GetSize() == 0)
	{
		return;
	}
	int index = 0;
	Polynom Res;
	Res.monoms.Clean();
	Node<Monom>* tmpPol;
	tmpPol = this->monoms.GetHead();
	Node<Monom>* tmpPoltwo = tmpPol;
	tmpPoltwo = tmpPoltwo->next;
	while (tmpPol)
	{
		while (tmpPoltwo)
		{
			if (tmpPol->data.degreeEq(tmpPoltwo->data))//���� �������, ���������� � ��������� � �����. ��� ������ �������. ������� �������(tmpPol) �� ������.-> ����� ��� �������;
			{
				index = 1;
				this->monoms.InsertToTail(tmpPol->data + tmpPoltwo->data);
				this->monoms.Delete(tmpPol->data);
				this->monoms.Delete(tmpPoltwo->data);
				tmpPol = this->monoms.GetHead();
				tmpPoltwo = tmpPol;
				tmpPoltwo = tmpPoltwo->next;
			}
			else//������� � ����������, ���� �� ����;
			{
				if (this->monoms.GetSize() > 1)
					tmpPoltwo = tmpPoltwo->next;
				else tmpPoltwo = nullptr;
				index = 0;
			}
		}
		if (index == 0)// ���� ������ ������� �� ����� ����, �������� ��� � �����;
		{
			if (tmpPol->data.coeff() != 0)//������� ����
				Res.monoms.InsertToTail(tmpPol->data);
			this->monoms.Delete(tmpPol->data);
			tmpPol = this->monoms.GetHead();
			tmpPoltwo = tmpPol;

			if (this->monoms.GetSize() > 0)//������ ������� �� �����, ���� �������� 0 ���������;
				tmpPoltwo = tmpPoltwo->next;
		}
		else index = 0;
	}
	tmpPol = this->monoms.GetHead();
	if (this->monoms.GetSize() > 0)
		if (tmpPol->data.coeff() != 0)
			Res.monoms.InsertToTail(tmpPol->data);
	*this=Res;
}




Polynom Polynom::operator+(const double& _Num) const
{
	Polynom pol = *this;
	Node<Monom>* tmpPol = this->monoms.GetHead();
	while (tmpPol)
	{
		if (tmpPol->data.degree() == 0)
		{
			tmpPol->data = (tmpPol->data + _Num);
			return *this;
		}
		tmpPol = tmpPol->next;
	}
	Monom monom(_Num, 0, 0, 0);
	pol.monoms.InsertToTail(monom);
	return pol;
}

Polynom Polynom::operator-(const double& _Num) const
{
	return *this + (-1) * _Num;
}

Polynom Polynom::operator*(const double& _Num) const
{
	Polynom pol = *this;

	Node<Monom>* tmpPol = this->monoms.GetHead();
	if (this->monoms.GetSize() != 0)
	{
		while (tmpPol)
		{
			tmpPol->data = (tmpPol->data * _Num);
			tmpPol = tmpPol->next;
		}
		pol = *this;
		pol.cancellation();
		return pol;
	}
	else return pol;
}


bool Polynom::operator==(const Polynom& _Polynom) const
{
	Polynom PolCooyOne = *this;
	Polynom PolCooyOTwo = _Polynom;

	PolCooyOne.cancellation();
	PolCooyOTwo.cancellation();

	if (PolCooyOne.monoms.GetSize() == PolCooyOTwo.monoms.GetSize())
	{
		int index = 0;
		Node<Monom>* tmpPol = PolCooyOne.monoms.GetHead();
		Node<Monom>* tmpPolTwo;
		while (tmpPol)
		{
			tmpPolTwo = PolCooyOTwo.monoms.GetHead();
			while (tmpPolTwo)
			{
				if (tmpPol->data == tmpPolTwo->data)
				{
					index++;
				}
				tmpPolTwo = tmpPolTwo->next;
			}
			tmpPol = tmpPol->next;
		}
		if (index == PolCooyOTwo.monoms.GetSize())
			return 1;
		else return 0;
	}
	else return 0;
}

bool Polynom::operator!=(const Polynom& _Polynom) const
{
	if (*this == _Polynom)
		return 0;
	else return 1;
}













