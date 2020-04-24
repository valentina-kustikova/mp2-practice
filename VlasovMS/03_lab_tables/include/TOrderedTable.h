#ifndef _TORDEREDTABLE_H_
#define _TORDEREDTABLE_H_
#define _TOrderedTableIter typename TOrderedTable<TKey, TData>::Iterator
#define _TOrderedTableEntry typename TOrderedTable<TKey, TData>::Entry

#include "TArrayTable.h"

template <typename TKey, typename TData>
class TOrderedTable : public TArrayTable<TKey, TData>
{
public:
    using BaseType = TArrayTable<TKey, TData>;
    using Key = TKey;
    using Data = TData;
    using Iterator = BaseType::Iterator;
    using Entry = TTableEntry<TKey, TData>;
    using Pair = BaseType::Pair;

protected:
    using BaseType::entries;
    using BaseType::capacity;

    void sort();

public:
    TOrderedTable();
    explicit TOrderedTable(size_t capacity_);
    ~TOrderedTable();

    virtual Iterator find(const TKey& needle) const;

    virtual void insert(const TKey& key, TData* data = nullptr);
    virtual void remove(const TKey& key);
    virtual void remove(Iterator& iter);
};

template<typename TKey, typename TData>
void TOrderedTable<TKey, TData>::sort()
{
    // TODO
}

template<typename TKey, typename TData>
TOrderedTable<TKey, TData>::TOrderedTable()
    : BaseType()
{
}

template<typename TKey, typename TData>
TOrderedTable<TKey, TData>::TOrderedTable(size_t capacity_)
    : BaseType(capacity_)
{
}

template<typename TKey, typename TData>
TOrderedTable<TKey, TData>::~TOrderedTable()
{
}

template<typename TKey, typename TData>
_TOrderedTableIter TOrderedTable<TKey, TData>::find(const TKey& needle) const
{
    // TODO : binary search
    return Iterator(nullptr);
}

template<typename TKey, typename TData>
void TOrderedTable<TKey, TData>::insert(const TKey& key, TData* data)
{
    // TODO
}

template<typename TKey, typename TData>
void TOrderedTable<TKey, TData>::remove(const TKey& key)
{
    // TODO
}

template<typename TKey, typename TData>
void TOrderedTable<TKey, TData>::remove(Iterator& iter)
{
    // TODO
}

#endif