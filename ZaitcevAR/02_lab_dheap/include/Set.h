#pragma once
#include "Exception.h"

class Set
{
private:
	int size; // размер
	int* keys; // элементы множества
public:
	Set(int size_ = 10);
	Set(int size_, int* keys_);
	~Set();

	// создание одноэментного подмножества
	void CreateOneElemSubset(int id);
	// объединение 2 подмножеств в первое
	void UnitedSubsets(int id_1, int id_2);
	// определение подмножества, которому принадлежит эл-т
	int GetNameOfSubset(int id);
};