#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "table.h"

template <class TKey, class TData>
class HashTable : public Table<TKey, TData> {
protected:
	virtual size_t hash_func(const TKey& key) = 0;

public:
	HashTable(size_t size) : Table(size) {};
};

#endif // !HASHTABLE_H
