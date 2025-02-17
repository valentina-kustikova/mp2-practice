#pragma once

using namespace std;

#include "string"
#include <iostream>


template <typename TElem>
class perems
{
	TElem* value;
	std::string* Name;
	int count_p;
public:
	perems()
	{
		value = nullptr;
		Name = nullptr;
		count_p = 0;
	}
	perems(const int count)
	{
		value = new TElem[count];
		Name = new std::string[count];
		count_p = count;
	}
	string Get_Name(int idx)
	{
		return Name[idx];
	}
	TElem Get_value(int idx)
	{
		return value[idx];
	}
	void Set_value(TElem v, int idx)
	{
		value[idx] = v;
	}
	void Set_Name(string n, int idx)
	{
		Name[idx] = n;
	}
	friend istream& operator>>(istream& istr, perems& p)
	{
		std::string str;
		for (int i = 0; i < p.count_p; i++)
		{
			std::cin >> p.Name[i] >> p.value[i];
		}
		return istr;
	}
	friend ostream& operator<<(ostream& ostr, const perems& p)
	{
		for (int i = 0; i < p.count_p; i++)
		{
			std::cout << p.Name[i] << "=" << p.value[i] << std::endl;
		}
		return ostr;
	}

};