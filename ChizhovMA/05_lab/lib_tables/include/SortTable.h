#ifndef SORT_TABLE_H
#define SORT_TABLE_H

#include "ScanTable.h"
#include <iostream>
using namespace std;

template <class TKey, class TData>
class TSortTable : public TScanTable<TKey, TData>
{
private: 
	void Sort();
public:
	TSortTable(int _maxsize);
	TSortTable(const TScanTable* st); // c параметром
	TSortTable(const TSortTable& rst); //копирование

	void Insert(TKey k, TData* data);
	void Remove(TKey k);
	TabRecord<TKey, TData>* Find(TKey k);

	friend ostream& operator<<(ostream& out, const TSortTable<TKey, TData>& st)
	{
		TSortTable<TKey, TData> t(st);
		if (!t.Reset());
		for (int i = 0; i < t.GetCount(); i++)
		{
			out << *(t.GetData());
			t.Next();
		}
		return out;
	}
};

template <class TKey, class TData>
TSortTable<TKey, TData>::TSortTable(int _maxsize) : TScanTable<TKey, TData>(_maxsize) {}

template <class TKey, class TData>
TSortTable<TKey, TData>::TSortTable(const TScanTable<TKey, TData>* st) : TScanTable<TKey, TData>(*st)
{
	Sort();
}
template <class TKey, class TData>
TSortTable<TKey, TData>::TSortTable(const TSortTable& rst) : TScanTable<TKey, TData>(rst) {}

template <class TKey, class TData>
TabRecord<TKey, TData>* TSortTable<TKey, TData>::Find(TKey k)
{
	int i1 = 0;
	int i2 = count - 1;
	TabRecord<TKey, TData>* Search = nullptr;
	while (i1 <= i2)
	{
		int mid = (i1 + i2) / 2;
		if (recs[mid]->GetKey() == k)
		{
			Search = recs[mid];
			i1 = mid + 1;
			i2 = mid;
		}
		else if (k > recs[mid]->GetKey())
			i1 = mid+1;
		else
			i2 = mid-1;
	}
	currPos = i2;
	return Search;
}
template <class TKey, class TData>
void TSortTable<TKey, TData>::Insert(TKey k, TData* data)
{
	if (IsFull())
	{
		string msg = "Error: sorted table is full";
		throw msg;
	}
	Find(k);
	for (int i = count - 1; i > currPos; i--)
		recs[i + 1] = recs[i];
	recs[currPos+1] = new TabRecord<TKey, TData>(k, data);
	count++;
	//this->Sort();
}
template <class TKey, class TData>
void TSortTable<TKey, TData>::Remove(TKey k)
{
	if (IsEmpty())
	{
		string msg = "Error: sorted table is empty";
		throw msg;
	}
	TabRecord<TKey, TData>* s = Find(k);
	if (s == nullptr)
	{
		string msg = "Error: the element to be deleted was not found";
		throw msg;
	}
	delete s;
	for (int i = currPos; i < count; i++)
	{
		recs[i] = recs[i + 1];
	}
	count--;
}
template <class TKey, class TData>
void TSortTable<TKey, TData>::Sort()
{
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (recs[j]->GetKey() > recs[j + 1]->GetKey())
			{
				TabRecord<TKey, TData>* temp = recs[j];
				recs[j] = recs[j + 1];
				recs[j + 1] = temp;
			}
		}
	}
}
#endif //! SORT_TABLE_H