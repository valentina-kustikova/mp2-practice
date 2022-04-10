#pragma once
#include "Table.h"

template <typename TData>
class THashTable : public  Table<TData>
{
protected:
	virtual int HashFunc(const TableKey key_); //Хэш-функция;
public:
	THashTable() :Table<TData>() {}
};

template <typename TData>
int THashTable<TData>::HashFunc(const TableKey key_)
{

}