#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include"Table.h"
#include<iostream>

template<typename TKey, typename TData>
class THashTable : public Table<TKey, TData>
{
protected:

	virtual size_t hash_func(const TKey& key) = 0;

public:

	THashTable(size_t size = 100) : Table<TKey, TData>(size) {};
};

#endif // !_HASHTABLE_H_