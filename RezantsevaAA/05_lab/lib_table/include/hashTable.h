#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__
#include "table.h"
template <typename TKey, typename TData> 
class THashTable : public TTable<TKey, TData>
{
protected:
	virtual size_t hash_func(const TKey& k) { return (k % maxSize)}
public:
	THashTable(size_t _size): TTable<TKey,TData>(_size) {};
};

#endif