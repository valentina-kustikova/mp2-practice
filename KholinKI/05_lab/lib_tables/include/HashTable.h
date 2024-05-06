#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "TABLE.h"

template<typename TKey, typename TData> class THashTable:public Table<TKey,TData> {
protected:
	virtual size_t HashFunction(const TKey& Key);
public:
	THashTable(int max_size_);
};

template<typename TKey, typename TData>
THashTable<TKey,TData>::THashTable(int max_size_):Table<TKey,TData>(max_size_){}

template<typename TKey, typename TData>
size_t THashTable<TKey, TData>::HashFunction(const TKey& Key) {
	return  Key % max_size;
}

#endif