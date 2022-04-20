#include <polinom.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
TPolinom::TPolinom(const std::string& str)
{//25x2y4z5+4.5x4y3z7
	TPolinom::TPolinom();
	string S = "";
	double coefficient;
	int deg;
	int flag = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i] >= '0') && (str[i] <= '9')||(str[i] == '.'))
		{
			S = S + str[i];
		}
		else
		{
			if (flag == 0)
			{
				coefficient = atof(S.c_str());
			}
			if (flag == 1)
			{
				deg = atoi(S.c_str())*100;
			}
			if (flag == 2)
			{
				deg += atoi(S.c_str()) * 10;
			}
			if (flag == 3)
			{
				deg += atoi(S.c_str());
			}
			flag++;
			S = "";
		}
		if ((str[i] == '+') || (str[i] == '-'))
		{
			TMonom* monom = new TMonom(coefficient, deg);
			InsertToHead(monom);
			S = "";
			deg = 0;
			coefficient = 0;
			flag = 0;
		}
	}
	TMonom* monom = new TMonom(coefficient, deg);
	InsertToHead(monom);
	Sort();
}

TPolinom TPolinom::operator+(const TPolinom& a)
{//2x2y2z5+3x5y7z8
 //4x2y2z5+6x5y7z9
	TPolinom pol;
	TNode* elem = pFirst;
	while (elem != pStop)
	{
		TNode* node = a.Search(elem->data);
		TMonom* monom1;
		if (node == nullptr)
		{
			pol.InsertToHead(elem->data);
		}
		else
		{
			pol.InsertToHead(monom1 + elem->data);
		}
		elem = elem->pNext;
	}
	return nullptr;
}