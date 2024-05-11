#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Tables.h"

template<class TKey,class TData>
class THashTable : public Table<TKey, TData>
{
protected:
    virtual size_t hash_func(const TKey& key) = 0;
public:
	THashTable(int size) : Table<TKey, TData>(size) {};
};


#endif
