#ifndef SCANTABLE_H
#define SCANTABLE_H

#include "Tables.h"
//#include "SortTable.h"
#include <iostream>
using namespace std;

template <class TKey, class TData>
class TScanTable : public Table<TKey,TData>
{
protected:
	TabRecord<TKey, TData>** recs;
public:
	TScanTable(int _maxsize);
	TScanTable(const TScanTable& st);
	~TScanTable();
	void Insert(TKey k, TData* data);
	void Remove(TKey k);
	TabRecord<TKey, TData>* Find(TKey k);
	TKey GetKey() const;
	TData* GetData() const;
    //TScanTable operator=(const TSortTable<Tkey, TData>& st);
    friend ostream& operator<<(ostream& out, const TScanTable<TKey, TData>& st)
    {
        TScanTable<TKey, TData> t(st);
        if(!t.Reset());
        for (int i = 0; i < t.GetCount(); i++)
        {
            out << *(t.GetData());
            t.Next();
        }
        return out;
    }
};

template <class TKey, class TData>
TScanTable<TKey, TData>::TScanTable(int _maxsize) : Table<TKey, TData>(_maxsize)
{
    recs = new TabRecord<TKey, TData>* [maxsize];
    for (int i = 0; i < maxsize; i++)
        recs[i] = nullptr;
}
template <class TKey, class TData>
TScanTable<TKey, TData>::TScanTable(const TScanTable& st) : Table<TKey, TData>(st.maxsize)
{
    count = st.count;
    currPos = st.currPos;

    recs = new TabRecord<TKey, TData>* [maxsize];
    for (int i = 0; i < maxsize; i++)
    {
        if (st.recs[i] != nullptr)
            recs[i] = new TabRecord<TKey, TData>(*st.recs[i]);
        else
            recs[i] = nullptr;
    }
}
template <class TKey, class TData>
TScanTable<TKey, TData>::~TScanTable()
{
    for (int i = 0; i < count; i++)
    {
        if (recs[i] != nullptr)
            delete recs[i];
    }
    delete[] recs;
}
template <class TKey, class TData>
void TScanTable<TKey, TData>::Insert(TKey k, TData* data)
{
    if (IsFull())
    {
        string msg = "Error: scan table is full";
        throw msg;
    }
    recs[count++] = new TabRecord<TKey,TData>(k, data);
}
template <class TKey, class TData>
void TScanTable<TKey, TData>::Remove(TKey k)
{
    if (IsEmpty())
    {
        string msg = "Error: scan table is empty";
        throw msg;
    }
    if (Find(k) != nullptr)
    {
        delete recs[currPos];
        for (int i = currPos; i < this->count; i++)
            recs[i] = recs[i + 1];
        count--;
    }
    else
    {
        string msg = "Error: the element to be deleted was not found";
        throw msg;
    }
}
template <class TKey, class TData>
TabRecord<TKey, TData>* TScanTable<TKey, TData>::Find(TKey k)
{
    for(int i = 0; i < count; i++)
    {
        if (recs[i]->GetKey() == k)
        {
            currPos = i;
            return recs[i];
        }
    }
    return nullptr;
}
template <class TKey, class TData>
TKey TScanTable<TKey, TData>::GetKey() const
{
    if (currPos < count)
        return recs[currPos]->GetKey();
    else
    {
        string msg = "Error: Current position is out of range";
        throw msg;
    }
}
template <class TKey, class TData>
TData* TScanTable<TKey, TData>::GetData() const
{
    if (currPos < count)
        return recs[currPos]->GetData();
    else
    {
        string msg = "Error: Current position is out of range";
        throw msg;
    }
}

#endif //! SCANTABLE_H
