#include"Polinom.h"
Polinom::Polinom()
{
	poli = new TList<unsigned int, double, Monom>();
}
Polinom::Polinom(const Polinom& polinom)
{
	poli = new TList<unsigned int, double, Monom>(*polinom.poli);
}
Polinom::Polinom(const string& polinom)
{
	poli = new TList<unsigned int, double, Monom>();
	string str;
	int i = 0;
	while (i < polinom.length())
	{
		if (polinom[i] == '-')
		{
			str += polinom[i];
			i++;
		}
		if (polinom[i] == '+')
			i++;
		while (polinom[i] != '+' && polinom[i] != '-' && i < polinom.length())
		{
			str += polinom[i];
			i++;
		}
		Monom monom(str);
		if (monom.pData != 0)
			*this = *this + monom;
		str = "";
	}
}
Polinom::~Polinom()
{
	delete poli;
}
Polinom Polinom::operator+(const Monom& monom)
{
	Polinom result(*this);
	result.poli->Reset();
	while (!result.poli->IsEnded() && *result.poli->GetpCur() < monom && *result.poli->GetpCur() != monom)
		result.poli->Next();
	if (result.poli->IsEnded())
		result.poli->InsertEnd(monom.key, monom.pData);
	else
		if (*result.poli->GetpCur() > monom)
		{
			int k = result.poli->GetpCur()->key;
			result.poli->InsertBefore(monom.key, k, monom.pData);
		}
		else
			if (*result.poli->GetpCur() == monom)
			*result.poli->GetpCur() = *result.poli->GetpCur() + monom;
	result.poli->Reset();
	return result;
}
Polinom Polinom::operator-(const Monom& monom)
{
	return *this + (-monom);
}
Polinom Polinom::operator*(const Monom& monom)
{
	Polinom result(*this);
	result.poli->Reset();
	while(!result.poli->IsEnded())
	{
		*result.poli->GetpCur() = *result.poli->GetpCur() * monom;
		result.poli->Next();
	}
	//result.poli->Reset();
	return result;
}
Polinom& Polinom::operator+=(const Monom& monom)
{
	Polinom result(*this);
	*this = result + monom;
	return (*this);
}
//Polinom& Polinom::operator-=(const Monom& monom)
//{
//	Polinom result(*this);
//	*this = result - monom;
//	return (*this);
//}
//Polinom& Polinom::operator*=(const Monom& monom)
//{
//	Polinom result(*this);
//	*this = result * monom;
//	return (*this);
//}
Polinom Polinom::operator+(const Polinom& polinom)
{
	Polinom result(*this);
	result.poli->Reset();
	if (result.poli->GetpCur() == nullptr)
		return polinom;
	polinom.poli->Reset();
	if (polinom.poli->GetpCur() == nullptr)
		return result;
	//while (!poli->IsEnded() && !polinom.poli->IsEnded())
	while (!polinom.poli->IsEnded())
	{
		if (*result.poli->GetpCur() < *polinom.poli->GetpCur())
		{
			//result.poli->Next();
			while (*result.poli->GetpCur() < *polinom.poli->GetpCur() && !result.poli->IsEnded() && result.poli->GetpCur()->key != polinom.poli->GetpCur()->key)
			{
				result.poli->Next();
			}
			if (result.poli->IsEnded())
			{
				result.poli->Reset();
				result.poli->InsertEnd(polinom.poli->GetpCur()->key, polinom.poli->GetpCur()->pData);
				result.poli->Reset();
			}
			else
			if (result.poli->GetpCur()->key == polinom.poli->GetpCur()->key)
			{
				result.poli->GetpCur()->pData = result.poli->GetpCur()->pData + polinom.poli->GetpCur()->pData;
				result.poli->Reset();
			}
			else
			{
				result.poli->InsertBefore(result.poli->GetpCur()->key, polinom.poli->GetpCur()->key, polinom.poli->GetpCur()->pData);
				result.poli->Reset();
			}
		}
		else if (*result.poli->GetpCur() > *polinom.poli->GetpCur())
		{
			result.poli->InsertStart(polinom.poli->GetpCur()->key, polinom.poli->GetpCur()->pData);
			result.poli->Reset();
		}
		else if (*poli->GetpCur() == *polinom.poli->GetpCur())
		{
			result.poli->InsertEnd(poli->GetpCur()->key, poli->GetpCur()->pData + polinom.poli->GetpCur()->pData);
			//result.poli->Reset();
			poli->Next();
			polinom.poli->Next();
		}
		polinom.poli->Next();
	}
	//while (!poli->IsEnded())
	//{
	//	result.poli->InsertEnd(poli->GetpCur()->key, poli->GetpCur()->pData);
	//	//result.poli->Reset();
	//	poli->Next();
	//}
	//while (!polinom.poli->IsEnded())
	//{
	//	result.poli->InsertEnd(polinom.poli->GetpCur()->key, polinom.poli->GetpCur()->pData);
	//	//result.poli->Reset();
	//	polinom.poli->Next();
	//}
	result.poli->Reset();
	return result;
}
Polinom Polinom::operator-(const Polinom& polinom)
{
	return *this + (-polinom);
}
Polinom Polinom::operator*(const Polinom& polinom)
{
	Polinom result;
	polinom.poli->Reset();
	while (!polinom.poli->IsEnded())
	{
		result = result + *this * *polinom.poli->GetpCur();
		polinom.poli->Next();
	}
	//result.poli->Reset();
	return result;
}
Polinom Polinom::operator-() const
{
	Polinom result(*this);
	result.poli->Reset();
	while (!result.poli->IsEnded())
	{
		result.poli->GetpCur()->pData = result.poli->GetpCur()->pData * -1;
		result.poli->Next();
	}
	//result.poli->Reset();
	return result;
}
Polinom& Polinom::operator=(const Polinom& polinom)
{
	if (*this == polinom)
		return *this;
	delete poli;
	poli = new TList<unsigned int, double, Monom>(*polinom.poli);
	//poli->Reset();
	return *this;
}
bool Polinom::operator==(const Polinom& polinom) const
{
	poli->Reset();
	polinom.poli->Reset();
	while (!poli->IsEnded() && !polinom.poli->IsEnded())
	{
		if (poli->GetpCur() != polinom.poli->GetpCur())
			return false;
		poli->Next();
		polinom.poli->Next();
	}
	if (!poli->IsEnded() || !polinom.poli->IsEnded())
		return false;
	return true;
}
istream& operator>>(istream& in, Polinom& polinom)
{
	string str;
	getline(in, str);
	polinom = Polinom(str);
	return in;
}
ostream& operator<<(ostream& out, const Polinom& polinom)
{
	polinom.poli->Reset();
	cout << polinom.poli->GetpCur()->pData;
	if (polinom.poli->GetpCur()->key / 100 == 1)
		cout << "*x";
	if (polinom.poli->GetpCur()->key / 100 != 0 && polinom.poli->GetpCur()->key / 100 != 1)
		cout << "*x^" << polinom.poli->GetpCur()->key / 100;
	if (polinom.poli->GetpCur()->key % 100 / 10 == 1)
		cout << "*y";
	if (polinom.poli->GetpCur()->key % 100 / 10 != 0 && polinom.poli->GetpCur()->key % 100 / 10 != 1)
		cout << "*y^" << polinom.poli->GetpCur()->key % 100 / 10;
	if (polinom.poli->GetpCur()->key % 100 % 10 == 1)
		cout << "*z";
	if (polinom.poli->GetpCur()->key % 100 % 10 != 0 && polinom.poli->GetpCur()->key % 100 % 10 != 1)
		cout << "*z^" << polinom.poli->GetpCur()->key % 100 % 10;
	polinom.poli->Next();
	while (!polinom.poli->IsEnded())
	{
		if (polinom.poli->GetpCur()->pData > 0)
		{
			cout << "+";
			cout << polinom.poli->GetpCur()->pData;
		}
		else
			cout << polinom.poli->GetpCur()->pData;
		if (polinom.poli->GetpCur()->key / 100 == 1)
			cout << "*x";
		if (polinom.poli->GetpCur()->key / 100 != 0 && polinom.poli->GetpCur()->key / 100 != 1)
			cout << "*x^" << polinom.poli->GetpCur()->key / 100;
		if (polinom.poli->GetpCur()->key % 100 / 10 == 1)
			cout << "*y";
		if (polinom.poli->GetpCur()->key % 100 / 10 != 0 && polinom.poli->GetpCur()->key % 100 / 10 != 1)
			cout << "*y^" << polinom.poli->GetpCur()->key % 100 / 10;
		if (polinom.poli->GetpCur()->key % 100 % 10 == 1)
			cout << "*z";
		if (polinom.poli->GetpCur()->key % 100 % 10 != 0 && polinom.poli->GetpCur()->key % 100 % 10 != 1)
			cout << "*z^" << polinom.poli->GetpCur()->key % 100 % 10;
		polinom.poli->Next();
	}
	return out;
}
