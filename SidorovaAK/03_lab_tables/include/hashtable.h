#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "table.h"

template<typename TKey, class TData>
class THashTable : public TTable<TKey, TData>
{
protected:
    virtual unsigned long HashFunction(const TKey _key);

public:
    THashTable(int _tabSize) : TTable<TKey, TData>(_tabSize) {}
};
//--------------------------------

template<typename TKey, class TData>
unsigned long THashTable<TKey, TData>::HashFunction(const TKey _key)
{
    unsigned long value = 0;
    int len = _key.length();
    
    for (int i = 0; i < len; i++)
        value = (value << 3) + _key[i];

    return value;
};

#endif