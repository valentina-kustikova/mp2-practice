#include "TSplitSet.h"

TSplitSet::TSplitSet(int size)
{
	universe = size;
	set = new int[universe];
	for (int i = 0; i < universe; i++)
	{
		set[i] = -1;
	}
}

TSplitSet::~TSplitSet()
{
	delete[] set;
}

void TSplitSet::createSingleton(int i)
{
	if (i < 0 || i >= universe)
	{
		throw "index out of set";
	}
	set[i] = i;
}

void TSplitSet::createUnitedSet(int i, int j)
{
	if (i < 0 || i >= universe || j < 0 || j >= universe)
	{
		throw "index out of set";
	}
	for (int k = 0; k < universe; k++)
	{
		if (set[k] == j)
			set[k] = i;
	}
}

int TSplitSet::findSet(int i)
{
	return set[i];
}

bool TSplitSet::operator!=(const TSplitSet& temp) const
{
	if (universe != temp.universe)
		return true;
	for (int i = 0; i < universe; i++)
		if (set[i] != temp.set[i])
			return true;
	return false;
}