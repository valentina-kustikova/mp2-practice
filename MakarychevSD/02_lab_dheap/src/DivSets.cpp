#include "DivSets.h"

DivSets::DivSets(int size, int* keys)
{
	if (size < 0 || keys == nullptr)
		throw "invalid par";
	this->size = size;
	this->keys = new int[size];
	for (int i = 0; i < size; i++)
		this->keys[i] = keys[i];
}

DivSets::DivSets(int size)
{
	if (size < 0)
		throw "invalid par";
	this->size = size;
	this->keys = new int[size];
	for (int i = 0; i < size; i++)
		this->keys[i] = -1;
}

DivSets::~DivSets()
{
	delete[] keys;
}

void DivSets::MakeSingletone(int i)
{
	keys[i] = i;
}

void DivSets::UnSets(int i, int j)
{
	if (i < 0 || j < 0)
		throw "invalid par";
	for (int k = 0; k < size; k++)
	{
		if (keys[k] == j)
			keys[k] = i;
	}
}

int DivSets::Def(int i)const
{
	return keys[i];
}
