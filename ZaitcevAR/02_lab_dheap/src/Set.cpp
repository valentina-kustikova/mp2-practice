#include "stdafx.h"
#include "Set.h"

Set::Set(int size_)
{
	size = size_;
	keys = new int[size];
	for (int i = 0; i < size; i++)
		keys[i] = -1;
}

Set::Set(int size_, int* keys_)
{
	size = size_;
	keys = new int[size];
	for (int i = 0; i < size; i++)
		keys[i] = keys_[i];
}

Set::~Set()
{
	size = 0;
	delete[] keys;
}

void Set::CreateOneElemSubset(int id)
{
	if (keys[id] != -1)
		throw Exception(" Error, element with such id has already used\n");
	keys[id] = id;
}

void Set::UnitedSubsets(int id_1, int id_2)
{
	// объединяем в подмножество с id_1
	for (int i = 0; i < size; i++)
	{
		if (keys[i] == id_2)
			keys[i] = id_1;
	}
}

int Set::GetNameOfSubset(int id)
{
	if (id < 0 || id >= size)
		throw Exception(" Error, number of id incorrect\n");
	return keys[id];
}