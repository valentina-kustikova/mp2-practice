#pragma once
#include "Table.h"
#include <string>
#include <algorithm>
using namespace std;

template <class TData, class TKey>
class HashTable : public Table<TData, TKey>
{
protected:
	virtual unsigned int HashFunc(const TKey& key) const;
public:
	HashTable():Table() {}
};

template<class TData, class TKey>
inline unsigned int HashTable<TData, TKey>::HashFunc(const TKey& key) const
{
	unsigned long hash = key[0];
	unsigned long p = 38;
	for (int i = 1; i < key.length(); i++)
	{
		hash += key[i] * p;
		p *= p;
	}
	return hash;
}
