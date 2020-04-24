#ifndef _TTABLEITERATOR_H_
#define _TTABLEITERATOR_H_

template <typename Table>
class TTableIterator
{
protected:
    template<typename, typename> friend class TBaseTable;    // hmm
    template<typename, typename> friend class TArrayTable;   // hmm
    template<typename, typename> friend class TOrderedTable; // hmm
    // i think there must be a way to make here "universal" 
    // declarator for each TTableIterator class being compiled
    typename Table::Entry** entry;
    explicit TTableIterator(typename Table::Entry** entry_);

public:
    TTableIterator(const TTableIterator<Table>& other);
    bool operator!=(const TTableIterator<Table>& other) const;
    bool operator==(const TTableIterator<Table>& other) const;
    typename Table::Pair operator*() const;
    TTableIterator operator++(int);
    TTableIterator& operator++();
    TTableIterator operator--(int);
    TTableIterator& operator--();
    typename Table::Key key() const;
    typename Table::Data*& data();
    typename Table::Data* data() const;
    bool isAccessible() const;
};

template<typename Table>
TTableIterator<Table>::TTableIterator(typename Table::Entry** entry_)
    : entry(entry_)
{
}

template<typename Table>
TTableIterator<Table>::TTableIterator(const TTableIterator<Table>& other)
    : entry(other.entry)
{
}

template<typename Table>
bool TTableIterator<Table>::operator!=(const TTableIterator<Table>& other) const
{
    return entry != other.entry;
}

template<typename Table>
bool TTableIterator<Table>::operator==(const TTableIterator<Table>& other) const
{
    return entry == other.entry;
}

template<typename Table>
typename Table::Pair TTableIterator<Table>::operator*() const
{
    return typename Table::template Pair<typename Table::Key, 
        typename Table::Data>((*entry)->key, (*entry)->data);
    // this syntax makes me sad
}

template<typename Table>
TTableIterator<Table> TTableIterator<Table>::operator++(int)
{
    entry++;
    return TTableIterator(entry - 1);
}

template<typename Table>
TTableIterator<Table>& TTableIterator<Table>::operator++()
{
    ++entry;
    return *this;
}

template<typename Table>
TTableIterator<Table> TTableIterator<Table>::operator--(int)
{
    entry--;
    return TTableIterator(entry + 1);
}

template<typename Table>
TTableIterator<Table>& TTableIterator<Table>::operator--()
{
    --entry;
    return *this;
}

template<typename Table>
typename Table::Key TTableIterator<Table>::key() const
{
    return (*entry)->getKey();
}

template<typename Table>
typename Table::Data*& TTableIterator<Table>::data()
{
    return (*entry)->data;
}

template<typename Table>
typename Table::Data* TTableIterator<Table>::data() const
{
    return (*entry)->data;
}

template<typename Table>
bool TTableIterator<Table>::isAccessible() const
{
    return entry != nullptr && *entry != nullptr;
}

#endif // !_TTABLEITERATOR_H_
