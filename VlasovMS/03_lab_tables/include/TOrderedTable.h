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
    using BaseType::entriesCount;
    using BaseType::capacity;

    void sort();
    size_t getIndex(Iterator iter);

public:
    TOrderedTable() = default;
    explicit TOrderedTable(size_t capacity_);
    ~TOrderedTable() = default;

    using BaseType::full;
    using BaseType::empty;
    virtual Iterator find(const TKey& needle) const;
    using BaseType::notFound;

    virtual void insert(const TKey& key, TData* data = nullptr);
    virtual void remove(const TKey& key);
    virtual void remove(Iterator& iter);

    using BaseType::begin;
    using BaseType::end;

    EXCEPT(FullError, "Table is full.");
    EXCEPT(DuplicateError, "There is an entry with given key in the table already.");
    EXCEPT(NotFoundError, "Given key not found.");
};

template<typename TKey, typename TData>
void TOrderedTable<TKey, TData>::sort()
{
    for (size_t i = 0; i < entriesCount; i++)
        for (size_t j = 1; j < entriesCount - 1; j++)
            if (entries[j - 1]->getKey() > entries[j]->getKey())
            {
                Entry* temp = entries[j];
                entries[j] = entries[j - 1];
                entries[j - 1] = temp;
            }
}

template<typename TKey, typename TData>
size_t TOrderedTable<TKey, TData>::getIndex(Iterator iter)
{
    return iter.entry - entries;
}

template<typename TKey, typename TData>
TOrderedTable<TKey, TData>::TOrderedTable(size_t capacity_)
    : BaseType(capacity_)
{
}

template<typename TKey, typename TData>
_TOrderedTableIter TOrderedTable<TKey, TData>::find(const TKey& needle) const
{
    size_t middle;
    size_t left = 0;
    size_t right = entriesCount - 1;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (needle == entries[middle]->getKey())
            return Iterator(entries + middle);
        else if (needle < entries[middle]->getKey())
            right = middle - 1;
        else
            left = middle + 1;
    }
    return notFound();
}

template<typename TKey, typename TData>
void TOrderedTable<TKey, TData>::insert(const TKey& key, TData* data)
{
    if (full())
        throw FullError();
    auto nextOrdered = begin();
    while ((nextOrdered != end()) && (nextOrdered.key() < key))
    {
        if (nextOrdered.key() == key)
            throw DuplicateError();
        nextOrdered++;
    }
    size_t index = getIndex(nextOrdered);
    if (!empty())
        for (size_t i = entriesCount; i > index; i--)
            entries[i] = entries[i - 1];
    entries[index] = new Entry(key, data);
    entriesCount++;
}

template<typename TKey, typename TData>
void TOrderedTable<TKey, TData>::remove(const TKey& key)
{
    auto iter = find(key);
    remove(iter);
}

template<typename TKey, typename TData>
void TOrderedTable<TKey, TData>::remove(Iterator& iter)
{
    if (empty() || (iter == notFound()) || !iter.isAccessible())
        throw NotFoundError();
    int index = getIndex(iter);
    delete entries[index];
    for (size_t i = index + 1; i < entriesCount; i++)
        entries[i - 1] = entries[i];
    entriesCount--;
}

#endif