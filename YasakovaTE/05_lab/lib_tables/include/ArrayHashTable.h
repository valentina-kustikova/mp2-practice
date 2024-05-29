#ifndef _ARRAY_HASH_TABLE_H
#define _ARRAY_HASH_TABLE_H
#include <HashTable.h>

template <typename TKey, typename TData>
class ArrayHashTable : public HashTable<TKey, TData> {
private:
    TabRecord<TKey, TData>** recs;
    TabRecord<TKey, TData>* pMark;

    int freePos;
    int hashStep;
    void GetNextPos(int pos);
    virtual size_t hashFunc(const TKey& key) const override;
public:
    ArrayHashTable(int n, int step);
    ArrayHashTable(const ArrayHashTable& ahtable);
    ~ArrayHashTable();

    TabRecord <TKey, TData>* Find(const TKey key);
    void Insert(TKey key, TData* data);
    void Remove(TKey key);
    void Next();
    void Reset();
    TabRecord<TKey, TData>* GetCurrent() const;
    friend ostream& operator<<(ostream& out, const ArrayHashTable<TKey, TData>& t) {
        if (t.IsEmpty()) {
            out << "Table is empty";
            return out;
        }
        for (int i = 0; i < t.maxSize; i++) {
            if (t.recs[i] && t.recs[i] != t.pMark)
                out << *(t.recs[i]);
        }
        return out;
    }

};

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(int n, int step) : HashTable<TKey, TData>(n) {
    maxSize = n;
    hashStep = step;
    recs = new TabRecord<TKey, TData>*[n];
    pMark = new TabRecord<TKey, TData>();

    for (int i = 0; i < n; ++i) {
        recs[i] = nullptr;
    }

    freePos = -1;
    count = 0;
    currPos = 0;
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(const ArrayHashTable& ahtable) : HashTable<TKey, TData>(ahtable.maxSize) {
    hashStep = ahtable.hashStep;
    currPos = ahtable.currPos;
    recs = new TabRecord<TKey, TData>*[maxSize];
    pMark = new TabRecord<TKey, TData>();

    for (int i = 0; i < maxSize; ++i) {
        if (ahtable.recs[i] == nullptr) {
            recs[i] = nullptr;
        }
        else if (ahtable.recs[i] == ahtable.pMark) {
            recs[i] = pMark;
        }
        else {
            recs[i] = new TabRecord<TKey, TData>(*ahtable.recs[i]);
        }
    }
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Insert(TKey key, TData* data) {
    if (IsEnded())
        throw "Table is full\n";
    TabRecord<TKey, TData>* tmp = Find(key);

    if (!tmp)
    {
        recs[freePos] = new TabRecord<TKey, TData>(key, data);
        count++;
    }
    else
    {
        tmp->data = data;
    }
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Remove(TKey key) {
    if (IsEmpty())
    {
        throw string("Table is empty\n");
    }
    TabRecord<TKey, TData>* exist = Find(key);

    if (!exist)
    {
        throw string("Wrong key\n");
    }
    count--;
    delete recs[currPos];
    recs[currPos] = pMark;
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::Find(const TKey key) {
    int hs = hashFunc(key), t = (hs + hashStep) % maxSize, c = 1;
    freePos = hs;

    if (recs[hs] == nullptr)
    {
        freePos = hs;
        return nullptr;
    }
    if (recs[hs]->key == key && recs[hs] != pMark)
    {
        currPos = hs;
        return recs[hs];
    }
    while (recs[t] != nullptr && t != hs && c < maxSize)
    {
        if (recs[t]->key == key)
        {
            currPos = t;
            return recs[t];
        }
        if (recs[t] == nullptr)
        {
            freePos = t;
            return nullptr;
        }
        t = (t + hashStep) % maxSize;
        ++c;
    }
    if (recs[freePos] != pMark && recs[freePos] != nullptr) {
        GetNextPos(freePos);
    }
    return nullptr;
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::~ArrayHashTable()
{
    for (int i = 0; i < maxSize; ++i) {
        if (recs[i] != nullptr) {
            delete recs[i];
        }
    }
    delete[] recs;
    delete pMark;
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::GetCurrent() const {
    if (currPos == -1 || currPos >= maxSize || recs[currPos] == nullptr) {
        return nullptr;
    }

    return recs[currPos];
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::GetNextPos(int pos) {
    if (count == maxSize) currPos = 0;
    int new_pos = (pos + hashStep % maxSize);
    while (new_pos != pos && (recs[new_pos] != pMark && recs[new_pos] != nullptr))
    {
        new_pos = (new_pos + hashStep) % maxSize;
    }
    currPos = new_pos;
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Reset() {
    currPos = 0;
    while (!IsEnded() && (recs[currPos] == nullptr || recs[currPos] == pMark))
    {
        currPos++;
    }
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Next() {
    if (IsEnded())  throw ("table is ended");
    currPos++;
    while (!IsEnded() && (recs[currPos] == nullptr || recs[currPos] == pMark))
    {
        currPos++;
    }
}

template<class TKey, class TData>
size_t ArrayHashTable<TKey, TData>::hashFunc(const TKey& key) const
{
    return std::hash<TKey>{}(key) % maxSize;
}

template <typename string, typename TPolynom>
class PolynomialHashTable : public ArrayHashTable<string, TPolynom> {
    size_t hashFunc(const string& key) const {
        uint64_t hashValue = 0;
        for (char ch : key) {
            hashValue += ch;
        }
        return (hashValue % maxSize);
    }

public:
    PolynomialHashTable(int n, int step) : ArrayHashTable<string, TPolynom>(n, step) {}
};

#endif 