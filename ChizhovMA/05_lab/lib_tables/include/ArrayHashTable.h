#ifndef ARRAYHASHTABLE_H
#define ARRAYHASHTABLE_H

#include "HashTable.h"
#include <iostream>


template<class TKey, class TData>
class TArrayHashTable : public THashTable<TKey, TData>
{
protected:
	size_t hash_step;
	TabRecord<TKey, TData>** recs;
	size_t GetNextPos(size_t ind) { return (ind + hash_step) % maxsize; }
	TabRecord<TKey, TData>* pMark;
	int freePos;
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
	/*friend ostream& operator<<(ostream& out, const TArrayHashTable<TKey, TData>& ht)
	{
		ht.Reset();
		while (!ht.IsTabEnded())
		{
			out << *(ht.recs[currPos]->GetData());
			ht.Next();
		}
		return out;
	};*/
	void Print();
};

template<class TKey, class TData>
TArrayHashTable<TKey, TData>::TArrayHashTable(size_t _maxsize, size_t _step) : THashTable(_maxsize)
{
	recs = new TabRecord<TKey, TData>* [_maxsize];
	hash_step = _step;
	pMark = nullptr;
	freePos = -1;
	for (int i = 0; i < _maxsize; i++)
		recs[i] = nullptr;
}
template<class TKey, class TData>
TArrayHashTable<TKey, TData>::TArrayHashTable(const TArrayHashTable& ht)
{
	maxsize = ht.maxsize;
	currPos = ht.currPos;
	hash_step = ht.hash_step;
	freePos = ht.freePos;
	recs = new TabRecord<TKey, TData>* [maxsize];
	for (int i = 0; i < maxsize; i++)
	{
		TabRecord<TKey,TData>* tmp = ht.recs[i];
		if (tmp == pMark)
			recs[i] = pMark;
		else if (tmp == nullptr)
			recs[i] = nullptr;
		else
			recs[i] = new TabRecord<TKey, TData>(tmp);
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
		delete recs;
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
	count++;
}
template<class TKey, class TData>
void TArrayHashTable<TKey, TData>::Remove(TKey k)
{
	TabRecord<TKey, TData>* tmp = Find(k);
	if (tmp == nullptr)
	{
		string msg = "Error: hash table is empty";
		throw msg;
	}
	delete tmp;
	recs[currPos] = pMark;
	freePos = -1;
	count--;
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
template<class TKey, class TData>
void TArrayHashTable<TKey, TData>::Print()
{
	Reset();
	while (!IsTabEnded())
	{
		cout << *(recs[currPos]->GetData());
		Next();
	}
}

#endif