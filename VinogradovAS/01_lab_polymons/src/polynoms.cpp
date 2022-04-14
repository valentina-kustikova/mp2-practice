#include "polinom.h"
#include <string>
using namespace std;


TPolynom::TPolynom()
{
	TMonom m;
	m.coeff = 0;
	m.x = m.y = 0, m.z = -1;

	pHead->value = m;
}

TPolynom::TPolynom(const TPolynom& other)
{

	TNode<TMonom>* i = other.pFirst;
	for (; i != other.pStop; i = i->pNext)
		InsLast(i->value);
}


TPolynom::TPolynom(const std::string& polyStr)
{
	if (polyStr.length() == 0) return;
	Parser(polyStr);


}

TPolynom& TPolynom::operator=(TPolynom& other)
{
	//Удаляем все звенья (кроме pHead)
	while (pFirst != pStop)
	{
		TNode<TMonom>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	//Ставим все значения указателей обратно на pHead
	pFirst = pLast = pPrev = pCurr = pStop = pHead;
	length = 0;

	other.Reset();
	while (!other.IsEnd())
	{
		InsLast(other.GetCurr());
		other.GoNext();
	}
	return *this;
}



void  TPolynom::AddMonom(TMonom m)
{
	if (m.coeff == 0) return;

	Reset();
	while (m < pCurr->value)
	{
		GoNext();
	}
	if (m.IsConst()) {
		if (pCurr->value.coeff != 0) {
			pCurr->value.coeff += m.coeff;
		}else
		InsCurr(m);
		return;
	}
	//Мономы равны с точностью до коэф-та
	if (pCurr->value == m)
	{
		pCurr->value.coeff += m.coeff;
		if (pCurr->value.coeff == 0)
		{
			DelCurr();
		}
	}
	else {
		InsCurr(m);
	}
}


inline void TPolynom::Parser(const std::string& polyStr)
{
	{
		char lastsgn = '+';

		TMonom tm(1, 0, 0, 0);

		int i = 0;
		for (; i < polyStr.size(); i++)
		{
			if (isdigit(polyStr[i]))
			{
				size_t idx;
				double digit = stod(&polyStr[i], &idx);


				tm.coeff = digit;
				i += idx - 1;
			}
			else if (polyStr[i] == 'x' || polyStr[i] == 'X')
			{
				if (i + 1 == polyStr.size())
				{
					tm.x += 1;
				}
				//Моном имеет явную степень (не 1)
				else if (isdigit(polyStr[i + 1]))
				{
					size_t idx;
					double digit = stod(&polyStr[i + 1], &idx);

					tm.x += digit;
					i += idx;
				}
				else
				{
					tm.x += 1;
				}
			}
			else if (polyStr[i] == 'y' || polyStr[i] == 'Y')
			{
				if (i + 1 == polyStr.size())
				{
					tm.y += 1;
				}
				else if (isdigit(polyStr[i + 1]))
				{
					size_t idx;
					double digit = stod(&polyStr[i + 1], &idx);

					tm.y += digit;
					i += idx;
				}
				else
				{
					tm.y += 1;
				}
			}
			else if (polyStr[i] == 'z' || polyStr[i] == 'Z')
			{
				if (i + 1 == polyStr.size())
				{
					tm.z += 1;
				}
				else if (isdigit(polyStr[i + 1]))
				{
					size_t idx;
					double digit = stod(&polyStr[i + 1], &idx);
					tm.z += digit;
					i += idx;
				}
				else
				{
					tm.z += 1;
				}
			}
			//Переход к считыванию следующего монома
			else if (polyStr[i] == '+' || polyStr[i] == '-')
			{
				if (lastsgn == '-') tm.coeff *= (-1);
				AddMonom(tm);
				tm.coeff = 1;
				tm.x = tm.y = tm.z = 0;
				lastsgn = polyStr[i];
			}
		}
		if (lastsgn == '-') tm.coeff *= (-1);
		AddMonom(tm);

	}
}

void TPolynom::AddMonom(double coeff, int x, int y, int z)
{
	AddMonom(TMonom(coeff, x, y, z));
}

bool TPolynom::operator==(const TPolynom& other) const
{
	return ToStr() == other.ToStr();
}

bool TPolynom::operator!=(const TPolynom& other) const
{
	return ToStr() != other.ToStr();
}





TPolynom TPolynom::operator+(const TPolynom& other)
{
	TPolynom result(other);
	Reset();
	result.Reset();

	while (!IsEnd())
	{
		if (result.pCurr->value > pCurr->value)
		{
			result.GoNext();
		}
		else if (result.pCurr->value < pCurr->value)
		{
			result.InsCurr(pCurr->value);
			GoNext();
		}
		else
		{
			result.pCurr->value.coeff += pCurr->value.coeff;
			if (result.pCurr->value.coeff == 0)
			{
				result.DelCurr();
				GoNext();
			}
			else
			{
				result.GoNext();
				GoNext();
			}
		}
	}
	return result;
}

TPolynom TPolynom::operator-(const TPolynom& other)
{
	TPolynom result(other);
	return operator+(result.operator*(-1));
}

TPolynom TPolynom::operator*(const TPolynom& ot)
{
	TPolynom other(ot);
	TPolynom result;

	for (Reset(); !IsEnd(); GoNext())
	{
		TMonom m = GetCurr();
		TPolynom temp = m * other;
		result = result + temp;
	}

	return result;
}

TPolynom TPolynom::operator*(const TMonom& monom)
{
	TPolynom result;

	if (monom.coeff == 0)
		return result;

	Reset();
	while (!IsEnd())
	{
		TMonom m = GetCurr();
		result.InsLast(m * monom);
		GoNext();
	}

	return result;
}

TPolynom TPolynom::operator*(const double a)
{
	TPolynom result;

	if (a == 0)
		return result;

	Reset();
	while (!IsEnd()) {
		TMonom m = GetCurr();
		m.coeff *= a;

		result.InsLast(m);
		GoNext();
	}

	return result;
}

inline double TPolynom::operator()(double x, double y, double z)
{

	{
		double res = 0.0;
		this->Reset();
		while (!this->IsEnd())
		{
			res += this->GetCurr().coeff * pow(x, this->GetCurr().x) * pow(y, this->GetCurr().y) * pow(z, this->GetCurr().z);
			this->GoNext();
		}
		return res;
	}
}