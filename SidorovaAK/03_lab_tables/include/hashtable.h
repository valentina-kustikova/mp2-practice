#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "table.h"

template<typename TKey, class TData>
class THashTable : public TTable<TKey, TData>
{
protected:
	virtual unsigned long HashFunction(const TKey _key);

public:
	THashTable(int _tabSize) : TTable(_tabSize) {}
};
//--------------------------------

template<typename TKey, class TData>
unsigned long THashTable<TKey, TData>::HashFunction(const TKey _key)
{

};

#endif