#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Tables.h"

template<class TKey,class TData>
class THashTable : public Table<TKey, TData>
{
protected:
    virtual size_t hash_func(const TKey& key);
public:
	THashTable(int size) : Table<TKey, TData>(size) {};
};
template<class TKey, class TData>
size_t THashTable<TKey, TData>::hash_func(const TKey& key)
{
	size_t hash = 0;
	for (char c : key)
		hash += c;

	return hash % maxsize;
}

#endif
