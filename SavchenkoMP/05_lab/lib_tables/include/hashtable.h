#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "table.h"
#include "xxh3.h"

template <class TKey, class TData>
class HashTable : public Table<TKey, TData> {
protected:
	virtual size_t hash_func(const TKey& key);

public:
	HashTable(size_t size) : Table(size) {};
};

template <class TKey, class TData>
size_t HashTable<TKey, TData>::hash_func(const TKey& key) {
	return XXH3_64bits(key.c_str(), key.size());
}

#endif // !HASHTABLE_H
