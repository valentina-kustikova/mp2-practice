#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include "table.h"

template <typename TKey, typename TData>
class HashTable : public Table<TKey, TData> {
protected:
	int hashFunc(const TKey _key);
public:
	HashTable(int max_size);
};

template <typename TKey, typename TData>
int HashTable<TKey, TData>::hashFunc(const TKey _key) {
	return  _key.length() % maxSize;
}

template <typename TKey, typename TData>
HashTable<TKey, TData>::HashTable(int max_size) : Table<TKey, TData>(max_size) {}

#endif