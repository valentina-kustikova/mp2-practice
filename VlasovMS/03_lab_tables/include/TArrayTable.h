#ifndef _TARRAYTABLE_H_
#define _TARRAYTABLE_H_
#define _TArrayTableIter typename TArrayTable<TKey, TData>::Iterator
#define _TArrayTableEntry typename TArrayTable<TKey, TData>::Entry

#include "EXCEPT.h"
#include "TBaseTable.h"

template <typename TKey, typename TData>
class TArrayTable : public TBaseTable<TKey, TData>
{
public:
    using BaseType = TBaseTable<TKey, TData>;
    using Key = TKey;
    using Data = TData;
    using Iterator = BaseType::Iterator;
    using Entry = TTableEntry<TKey, TData>;
    using Pair = BaseType::Pair;

protected:
    using BaseType::entriesCount;
    size_t capacity;
    Entry** entries;

public:
    TArrayTable();
    explicit TArrayTable(size_t capacity_);
    ~TArrayTable();

    using BaseType::empty;
    bool full() const;
    virtual Iterator find(const TKey& needle) const;

    virtual void insert(const TKey& key, TData* data = nullptr);
    virtual void remove(const TKey& key);
    virtual void remove(Iterator& iter);

    virtual Iterator begin();
    virtual Iterator end();
    virtual Iterator notFound();
    virtual const Iterator begin() const;
    virtual const Iterator end() const;
    virtual const Iterator notFound() const;

    EXCEPT(FullError, "Table is full.");
    EXCEPT(DuplicateError, "There is an entry with given key in the table already.");
    EXCEPT(NotFoundError, "Given key not found.");
};

template<typename TKey, typename TData>
TArrayTable<TKey, TData>::TArrayTable()
    : BaseType(), capacity(0), entries(nullptr)
{
}

template<typename TKey, typename TData>
TArrayTable<TKey, TData>::TArrayTable(size_t capacity_)
    : capacity(capacity_)
{
    if (capacity > 0)
        entries = new Entry*[capacity];
}

template<typename TKey, typename TData>
TArrayTable<TKey, TData>::~TArrayTable()
{
    if (entries != nullptr)
    {
        for (size_t i = 0; i < entriesCount; i++)
            delete entries[i];
        delete[] entries;
    }
}

template<typename TKey, typename TData>
bool TArrayTable<TKey, TData>::full() const
{
    return entriesCount == capacity;
}

template<typename TKey, typename TData>
_TArrayTableIter TArrayTable<TKey, TData>::find(const TKey& needle) const
{
    for (auto i = begin(); i != end(); i++)
        if (i.key() == needle)
            return i;
    return end();
}

template<typename TKey, typename TData>
void TArrayTable<TKey, TData>::insert(const TKey& key, TData* data)
{
    if (full())
        throw FullError();
    if (find(key) != notFound())
        throw DuplicateError();
    entries[entriesCount++] = new Entry(key, data);
}

template<typename TKey, typename TData>
void TArrayTable<TKey, TData>::remove(const TKey& key)
{
    auto iter = find(key);
    remove(iter);
}

template<typename TKey, typename TData>
void TArrayTable<TKey, TData>::remove(Iterator& iter)
{
    if (empty() || (iter == notFound()) || !iter.isAccessible())
        throw NotFoundError();
    int index = iter.entry - entries;
    delete entries[index];
    entries[index] = entries[entriesCount - 1];
    entriesCount--;
}

template<typename TKey, typename TData>
_TArrayTableIter TArrayTable<TKey, TData>::begin()
{
    return Iterator(entries);
}

template<typename TKey, typename TData>
_TArrayTableIter TArrayTable<TKey, TData>::end()
{
    return Iterator(entries + entriesCount);
}

template<typename TKey, typename TData>
_TArrayTableIter TArrayTable<TKey, TData>::notFound()
{
    return end();
}

template<typename TKey, typename TData>
const _TArrayTableIter TArrayTable<TKey, TData>::begin() const
{
    return Iterator(entries);
}

template<typename TKey, typename TData>
const _TArrayTableIter TArrayTable<TKey, TData>::end() const
{
    return Iterator(entries + entriesCount);
}

template<typename TKey, typename TData>
const _TArrayTableIter TArrayTable<TKey, TData>::notFound() const
{
    return end();
}

#endif