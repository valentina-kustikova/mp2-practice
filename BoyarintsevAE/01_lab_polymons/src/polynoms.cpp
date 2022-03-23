#include "polinom.h"



TList<TMonom> TPolinom::parser(const string s)
{
	TList<TMonom> pars;
	string smonom;
	string spolinom = s;

	int count = 0;

	int deg[3] = { 100, 10, 1 };

	while (spolinom.length())
	{
		
		count = 1;
		TMonom temp;

		while (spolinom[count] != '-' && spolinom[count] != '+' && count < spolinom.length())
		{
			count++;
		}
		
		smonom = spolinom.substr(0, count);
		spolinom.erase(0, count);

		if (spolinom[0] == '-')
		{
			temp.coeff = -1;
			spolinom.erase(0, 1);
		}
		else
		{
			temp.coeff = 1;
			if (spolinom[count] == '+')
			{
				spolinom.erase(0, 1);
			}
		}

		if (isdigit(smonom[0]))
		{
			count = 0;
			while (smonom[count] == '.' || isdigit(smonom[count]))
			{
				count++;
			}
			
			temp.coeff = stod(smonom.substr(0, count)) * temp.coeff;
			smonom.erase(0, count);

		}

		for (int i = 0; i < 3; i++)
		{
			double position = smonom.find("xyz"[i]);

			if (position != -1)
			{
				if (smonom[position + 1] == '^')
				{
					temp.degree = stoi(smonom.substr(position + 2, 1)) * deg[i] + temp.degree;
				}
				else
				{
					temp.degree = deg[i] + temp.degree;
				}
			}

		}

		pars.InsertToTail(temp);

	}
	return pars;


}

TList<TMonom> TPolinom::transform(TList<TMonom> polinom)
{
	TList<TMonom> result;

	result.Reset();
	polinom.Reset();

	TMonom temp;

	TNode<TMonom>* p = polinom.getpCurr();
	polinom.Next();

	if (!(polinom.isEnd()))
	{
		polinom.Reset();

		while (!(polinom.isEnd()))
		{
			temp.degree = polinom.getpCurr()->data.degree;
			temp.coeff = polinom.getpCurr()->data.coeff;

			while (!(polinom.isEnd()) && (polinom.getpCurr()->data.degree == polinom.getpCurr()->pNext->data.degree))
			{
				temp.coeff = polinom.getpCurr()->pNext->data.coeff + temp.coeff;
				polinom.Next();
			}

			if (temp.coeff)
			{

				result.InsertToTail(temp);
				result.Next();
			}

			if (!(polinom.isEnd()))
			{
				polinom.Next();
			}
		}
		result.Reset();

		if (result.getpCurr()->data.coeff == 0 && result.getpCurr()->data.degree == 0)
		{
			result.InsertAfter(NULL, result.getpCurr());
		}
	}
	else
	{
		result = polinom;
	}

	return result;

}

TPolinom::TPolinom()
{
	TMonom temp;
	temp.coeff = 0.0;
	temp.degree = -1;
	monom.InsertToTail(temp);
}

TPolinom::TPolinom(const string str)
{
	monom = parser(str);
		monom = transform(monom);

}

TPolinom::TPolinom(const TList<TMonom>& pol) : monom(pol)
{

}

TPolinom::TPolinom(const TMonom m)
{
	monom.InsertAfter(m, monom.getpCurr());
}

TPolinom::TPolinom(const TPolinom& polinom) : monom(polinom.monom)
{

}


TPolinom::~TPolinom()
{
	
}

TPolinom TPolinom::operator+(const TPolinom& polinom) const
{
	TPolinom polinom1, polinom2;
	TPolinom result;

	polinom1 = monom;
	polinom2 = polinom;

	
	int max, i;
	max = (polinom1.monom.getpCurr()->data.degree > polinom2.monom.getpCurr()->data.degree) ? polinom1.monom.getpCurr()->data.degree : polinom2.monom.getpCurr()->data.degree;
	
	if (polinom1.monom.getpCurr()->data.degree == polinom2.monom.getpCurr()->data.degree)
	{
		for (i = polinom1.monom.getpCurr()->data.degree; i >= 0; i--)
		{
			result = polinom1 + polinom2;
		}
	}

	if (polinom1.monom.getpCurr()->data.degree > polinom2.monom.getpCurr()->data.degree)
	{
		for (i = polinom1.monom.getpCurr()->data.degree; i > polinom2.monom.getpCurr()->data.degree; i--)
		{
			result = polinom1;
		}

		for (i = polinom2.monom.getpCurr()->data.degree; i >= 0 ; i--)
		{
			result = polinom1 + polinom2;
		}
	}

	if (polinom1.monom.getpCurr()->data.degree < polinom2.monom.getpCurr()->data.degree)
	{
		for (i = polinom2.monom.getpCurr()->data.degree; i > polinom1.monom.getpCurr()->data.degree; i--)
		{
			result = polinom2;
		}

		for (i = polinom1.monom.getpCurr()->data.degree; i >= 0; i--)
		{
			result = polinom1 + polinom2;
		}
	}
	return result;
}

TPolinom TPolinom::operator-(const TPolinom& polinom) const
{

	TPolinom polinom1, polinom2;
	TPolinom result;

	polinom1 = monom;
	polinom2 = polinom;
	
	int max, i;

	max = (polinom1.monom.getpCurr()->data.degree > polinom2.monom.getpCurr()->data.degree) ? polinom1.monom.getpCurr()->data.degree : polinom2.monom.getpCurr()->data.degree;

	if (polinom1.monom.getpCurr()->data.degree == polinom2.monom.getpCurr()->data.degree)
	{
		for (i = polinom1.monom.getpCurr()->data.degree; i >= 0; i--)
		{
			result = polinom1 - polinom2;
		}
	}

	if (polinom1.monom.getpCurr()->data.degree > polinom2.monom.getpCurr()->data.degree)
	{
		for ( i = polinom1.monom.getpCurr()->data.degree; i > polinom2.monom.getpCurr()->data.degree; i--)
		{
			result = polinom1;
		}

		for (i = polinom1.monom.getpCurr()->data.degree; i >= 0; i--)
		{
			result = polinom1 - polinom2;
		}
	}


	if (polinom1.monom.getpCurr()->data.degree < polinom2.monom.getpCurr()->data.degree)
	{
		for (i = polinom2.monom.getpCurr()->data.degree; i > polinom1.monom.getpCurr()->data.degree; i--)
		{
			result = polinom2;
		}

		for ( i = polinom1.monom.getpCurr()->data.degree; i >= 0; i--)
		{
			result = polinom2 - polinom1;
		}
	}

	return result;
}

TPolinom TPolinom::operator*(const TPolinom& polinom) const
{
	TPolinom polinom1, polinom2;
	TPolinom result;

	polinom1 = monom;
	polinom2 = polinom;

	int i, j, max;

	max = polinom1.monom.getpCurr()->data.degree + polinom2.monom.getpCurr()->data.degree;

	for ( i = polinom1.monom.getpCurr()->data.degree; i >= 0; i--)
	{
		for ( j = polinom2.monom.getpCurr()->data.degree; j >= 0; j--)
		{
			result = polinom1 * polinom2 + result;
		}
	}

	return result;

}

//TPolinom TPolinom::operator-()
//{
//	return TPolinom();
//}

TPolinom& TPolinom::operator=(const TPolinom& polinom)
{
	if (*this != polinom)
	{
		this->monom.getpCurr()->data.coeff = polinom.monom.getpCurr()->data.coeff;
		this->monom.getpCurr()->data.degree = polinom.monom.getpCurr()->data.degree;
	}
	return *this;
}

bool TPolinom::operator!=(const TPolinom& polinom) const
{
	return monom != polinom.monom;
}

bool TPolinom::operator==(const TPolinom& polinom) const
{
	return monom == polinom.monom;
}

ostream& operator<<(std::ostream& out, const TPolinom& polinom)
{
	TPolinom temp = polinom;
	temp.monom.Reset();

	TNode<TMonom>* First = temp.monom.getpCurr();
	TNode<TMonom> tmp;

	while (!temp.monom.isEnd())
	{
		tmp = temp.monom.getpCurr()->data;

		if (tmp.data.coeff > 0 && temp.monom.getpCurr() != First)
		{
			out << "+";
		}

		if (tmp.data.coeff != 1 && tmp.data.coeff != -1 && tmp.data.coeff != 0)
		{
			out << tmp.data.coeff;
		}
		else
		{
			if (tmp.data.coeff == -1 && tmp.data.degree != 0)
			{
				out << "-";
			}
			else
			{
				if ((tmp.data.coeff == 1 || tmp.data.coeff == -1) && tmp.data.degree == 0)
				{
					out << tmp.data.coeff;
				}
			}
		}

		int d[] = { 100, 10 , 1 };
		for (int i = 0; i < 3; i++)
		{
			if (tmp.data.degree / d[i] % 10 != 0)
			{
				out << "xyz"[i];
				if (tmp.data.degree / d[i] % 10 != 1)
				{
					out << "^" << tmp.data.degree / d[i] % 10;
				}
			}
		}

		temp.monom.Next();

	}
	temp.monom.Reset();

	if (temp.monom.getpCurr()->data.degree == 0 && temp.monom.getpCurr()->data.coeff == 0 && !(temp.monom.isEnd()))
	{
		out << "0";
	}

	return out;
}

