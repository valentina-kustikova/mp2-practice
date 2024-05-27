#ifndef ARRAYHASHTABLE_H
#define ARRAYHASHTABLE_H

#include "HashTable.h"
#include <iostream>
using namespace std;


template<class TKey, class TData>
class TArrayHashTable : public THashTable<TKey, TData>
{
protected:
	size_t hash_step;
	TabRecord<TKey, TData>** recs;
	TabRecord<TKey, TData>* pMark;
	int freePos;

	size_t GetNextPos(size_t ind) { return (ind + hash_step) % maxsize; }

public:
	TArrayHashTable(size_t _maxsize, size_t _step);
	TArrayHashTable(const TArrayHashTable& ht);
	virtual ~TArrayHashTable();

	void Insert(TKey k, TData* d);
	void Remove(TKey k);
	TabRecord<TKey, TData>* Find(TKey k);

	bool Reset();
	bool Next();

	TKey GetKey() const ;
	TData* GetData() const;

	friend ostream& operator<<(ostream& out, const TArrayHashTable<TKey, TData>& h)
	{
		TArrayHashTable<TKey, TData> ht(h);
		if (!ht.Reset())
		{ 
			while (!ht.IsTabEnded())
			{
				if (ht.recs[ht.currPos] != nullptr && ht.recs[ht.currPos] != ht.pMark) 
					out << *(ht.GetData()); 
				ht.Next();
			}
		}
		return out;
	};

};

template<class TKey, class TData>
TArrayHashTable<TKey, TData>::TArrayHashTable(size_t _maxsize, size_t _step) : THashTable<TKey, TData>(_maxsize)
{
	recs = new TabRecord<TKey, TData>* [_maxsize];
	hash_step = _step;
	pMark = new TabRecord<TKey, TData> ();
	freePos = -1;
	for (int i = 0; i < _maxsize; i++)
		recs[i] = nullptr;
}
template<class TKey, class TData>
TArrayHashTable<TKey, TData>::TArrayHashTable(const TArrayHashTable& ht) : THashTable<TKey, TData>(ht.maxsize) 
{
	if (this == &ht)
		return;
	maxsize = ht.maxsize;
	currPos = ht.currPos;
	hash_step = ht.hash_step;
	freePos = ht.freePos;
	recs = new TabRecord<TKey, TData>* [maxsize];
	pMark = new TabRecord<TKey, TData> ();
	for (int i = 0; i < maxsize; i++)
	{
		TabRecord<TKey, TData>* tmp = ht.recs[i];
		if (ht.recs[i] == ht.pMark) {
			recs[i] = pMark;
		}
		else if (ht.recs[i] == nullptr) {
			recs[i] = nullptr;
		}
		else 
			recs[i] = new TabRecord<TKey, TData>(*tmp);
	}
}
template<class TKey, class TData>
TArrayHashTable<TKey, TData>::~TArrayHashTable()
{
	for (int i = 0; i < maxsize; i++)
	{
		if (recs[i] != nullptr && recs[i] != pMark)
			delete recs[i];
	}
	if (recs)
		delete[] recs;
	if (pMark)
		delete pMark;
}
template<class TKey, class TData>
TabRecord<TKey, TData>* TArrayHashTable<TKey, TData>::Find(TKey k)
{
	currPos = hash_func(k);
	for (int i = 0; i < maxsize; i++)
	{
		if (recs[currPos] == nullptr)
			return nullptr;
		else if (recs[currPos] == pMark && freePos == -1)
			freePos = currPos;
		else if (recs[currPos]->GetKey() == k)
			return recs[currPos];
		currPos = GetNextPos(currPos);
	}
	return nullptr;
}
template<class TKey, class TData>
void TArrayHashTable<TKey, TData>::Insert(TKey k, TData* d)
{
	if (IsFull())
	{
		string msg = "Error: hash table is full";
		throw msg;
	}
	if (Find(k) != nullptr && freePos != -1)
		currPos = freePos;
	recs[currPos] = new TabRecord<TKey, TData>(k, d);
	Count++;
}
template<class TKey, class TData>
void TArrayHashTable<TKey, TData>::Remove(TKey k)
{
	TabRecord<TKey, TData>* tmp = Find(k);
	if (IsEmpty())
	{
		string msg = "Error: hash table is empty";
		throw msg;
	}
	if (tmp == nullptr)
	{
		string msg = "Error: elem not found";
		throw msg;
	}
	delete tmp;
	recs[currPos] = pMark;
	freePos = -1;
	Count--;
}
template<class TKey, class TData>
bool TArrayHashTable<TKey, TData>::Reset()
{
	currPos = 0;
	while (!IsTabEnded())
	{
		if (recs[currPos] != nullptr && recs[currPos] != pMark)
			break;
		currPos++;
	}
	return IsTabEnded();
}
template<class TKey, class TData>
bool TArrayHashTable<TKey, TData>::Next()
{
	currPos++;
	while (!IsTabEnded())
	{
		if (recs[currPos] != nullptr && recs[currPos] != pMark)
			break;
		currPos++;
	}
	return IsTabEnded();
}
template<class TKey, class TData>
TKey TArrayHashTable<TKey,TData>::GetKey() const
{
	if (currPos < maxsize)
		return recs[currPos]->GetKey();
	else
	{
		string msg = "Error: Current position is out of range";
		throw msg;
	}
}
template<class TKey, class TData>
TData* TArrayHashTable<TKey,TData>::GetData() const
{
	if (currPos < maxsize)
		return recs[currPos]->GetData();
	else
	{
		string msg = "Error: Current position is out of range";
		throw msg;
	}
}

#endif