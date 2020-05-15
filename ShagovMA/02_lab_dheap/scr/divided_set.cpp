#include "divided_set.h"

DividedSet::DividedSet(int size)
{
	if (size <= 0)
	{
		throw "Incorrect size of set";
	}
	universe = size;
	set = new int[universe];
	for (int i = 0; i < universe; i++)
	{
		set[i] = -1;
	}
}

DividedSet::~DividedSet()
{
	delete[] set;
}

void DividedSet::createSingleton(int i)
{
	if (i < 0 || i >= universe)
	{
		throw "index out of set";
	}
	set[i] = i;
}

void DividedSet::createUnitedSet(int i, int j)
{
	if (i < 0 || i >= universe || j < 0 || j >= universe)
	{
		throw "index out of set";
	}
	for (int k = 0; k < universe; k++)
	{
		if (set[k] == j)
		{
			set[k] = i;
		}
	}
}

int DividedSet::findSet(int i)
{
	if (i < 0 || i >= universe)
	{
		throw "Out of range set";
	}
	return set[i];
}

bool DividedSet::operator!=(const DividedSet & _set) const
{
	if (universe != _set.universe)
	{
		return false;
	}
	for (int i = 0; i < universe; i++)
	{
		if (set[i] != _set.set[i])
		{
			return true;
		}
	};
	return false;
}

bool DividedSet::operator==(const DividedSet & _set) const
{
	return !(*this == _set);
}
