#pragma once
#include "ArrayTable.h"

template <class TKey, class TData>
class SortTable : public ArrayTable<TKey, TData>
{
public:
    SortTable(int size = 25) : ArrayTable<TKey, TData>(size) {}
    virtual TData* Find(const TKey& k);
};
