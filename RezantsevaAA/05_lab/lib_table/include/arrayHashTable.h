#ifndef __ARRAYHASHTABLE_H__
#define __ARRAYHASHTABLE_H__
#include "hashTable.h"
#include <iostream>
#include <iomanip>

template <typename TKey, typename TData> 
class TArrayHashTable : public THashTable<TKey, TData>
{
protected: 
	size_t hash_step;
	TTabRecord<TKey, TData>** records; //массив указателей на записи
	
	size_t GetNextPos(size_t index) { return (index + hash_step) % maxSize; }
	size_t hash_func(const TKey& k);

	TTabRecord<TKey, TData>* pMark; //пометка о том, что был удален
	int freePosIndex; //index свободной позиции


public:
	TArrayHashTable(size_t maxSize, size_t step);
	TArrayHashTable(const TArrayHashTable& obj);
	virtual ~TArrayHashTable();

	virtual void Insert(const TKey& k, const TData& d)  override;
	virtual void Remove(const TKey& k) override;
	virtual TTabRecord<TKey, TData>* Find(const TKey& k) override;

	virtual bool Reset() override;
	virtual bool Next() override;

	virtual TKey GetKey() const override;
	virtual TData* GetData() const override;

	friend std::ostream& operator<<(std::ostream& out, const TArrayHashTable<TKey, TData>& ht)
	{
		std::cout << "-------------------------------------" << std::endl;
		for (int i = 0; i < ht.maxSize; i++) {

			if (ht.records[i] != ht.pMark && ht.records[i] != nullptr)
			{
				out << "| " << std::setw(20) << ht.records[i]->GetKey() <<  " | " << std::setw(20) << *(ht.records[i]->GetData()) << std::endl;

			}
		}
		return out;
	}
};

template <typename TKey, typename TData> 
TArrayHashTable<TKey, TData>::TArrayHashTable(size_t _maxSize, size_t _step) : THashTable<TKey, TData>(_maxSize)
{
	records = new TTabRecord<TKey, TData>* [_maxSize];
	hash_step = _step;
	pMark = new TTabRecord<TKey, TData>();
	freePosIndex = -1;
	for (int i = 0; i < _maxSize; i++) {
		records[i] = nullptr;
	}
}
		
template <typename TKey, typename TData> 
TArrayHashTable<TKey, TData>::TArrayHashTable(const TArrayHashTable& obj):THashTable<TKey, TData>(obj.maxSize)
{
	maxSize = obj.maxSize;
	currPos = obj.currPos;
	hash_step = obj.hash_step;
	freePosIndex = obj.freePosIndex;
	records = new TTabRecord<TKey, TData>* [maxSize];
	pMark = new TTabRecord<TKey, TData>();
	for (int i = 0; i < maxSize; i++)
	{
		TTabRecord<TKey, TData>* tmp = obj.records[i];
		if (obj.records[i] == obj.pMark) {
			records[i] = pMark;
		}
		else if (obj.records[i] == nullptr) {
			records[i] = nullptr;
		}
		else
			records[i] = new TTabRecord<TKey, TData>(*tmp);
	}
}

template <typename TKey, typename TData> 
TArrayHashTable<TKey, TData>::~TArrayHashTable()
{
	for (int i = 0; i < maxSize; i++) {
		if (records[i] != nullptr && records[i] != pMark)
		{
			delete records[i];
		}
	}
	if (records)
		delete[] records;
	if (pMark)
		delete pMark;
}

//Hash func
template<typename TKey, typename TData>
size_t TArrayHashTable<TKey, TData>::hash_func(const TKey& k)
{
	std::hash<TKey> hasher;
	return hasher(k) % maxSize;
}


//navigation
template<typename TKey, typename TData>
bool TArrayHashTable<TKey, TData>::Reset()
{
	currPos = 0;
	while (!IsTabEnded())
	{
		if (records[currPos] != nullptr && records[currPos] != pMark)
			break;
		currPos++;
	}
	return IsTabEnded();
}


template<typename TKey, typename TData>
bool TArrayHashTable<TKey, TData>::Next()
{
	currPos++;
	while (!IsTabEnded())
	{
		if (records[currPos] != nullptr && records[currPos] != pMark)
			break;
		currPos++;
	}
	return IsTabEnded();
}

//Get
template<typename TKey, typename TData>
TKey TArrayHashTable<TKey, TData>::GetKey() const
{
	if (currPos < maxSize)
	{
		return records[currPos]->GetKey();
	}
	else
		throw "Error. Can't get key. Current position out of range";
}

template<typename TKey, typename TData>
TData* TArrayHashTable<TKey, TData>::GetData() const
{
	if (currPos < maxSize)
	{
		return records[currPos]->GetData();
	}
	else
		throw "Error. Can't get data. Current position out of range";
}



//functions

template<typename TKey, typename TData>
TTabRecord<TKey, TData>* TArrayHashTable<TKey, TData>::Find(const TKey& k)
{
	currPos = hash_func(k);
	for (int i = 0; i < maxSize; i++)
	{
		if (records[currPos] == nullptr)
		{
			return nullptr;
		}
		else 
			if (records[currPos] == pMark && freePosIndex == -1)
			{
				freePosIndex = currPos;
			}
		else 
				if (records[currPos]->GetKey() == k)
				{
					return records[currPos];
				}	
		currPos = GetNextPos(currPos);
	}
	return nullptr;
}


template<typename TKey, typename TData>
void TArrayHashTable<TKey, TData>::Remove(const TKey& k)
{
	TTabRecord<TKey, TData>* tmp = Find(k);
	if (tmp == nullptr)
	{
		throw " Error. Record is empty";
	}
	delete tmp;

	records[currPos] = pMark;
	freePosIndex = -1;
	size--;
}

template<typename TKey, typename TData>
void TArrayHashTable<TKey, TData>::Insert(const TKey& k, const TData& d)

{
	if (IsFull())
	{
		throw "Error. Can't insert, table is full";
	}
	

	if (freePosIndex != -1)
	{
		currPos = freePosIndex;
	}
	else
	{
		currPos = hash_func(k);
		while (records[currPos] != nullptr && records[currPos] != pMark)
		{
			currPos = GetNextPos(currPos);
		}
	}

	records[currPos] = new TTabRecord<TKey, TData>(k, d);
	size++;
}
/*
{
	if (IsFull())
	{
		throw "Error. Can't insert, table is full";
	}
	
	if (Find(k) != nullptr && freePosIndex != -1)
	{
		currPos = freePosIndex;
	}
	records[currPos] = new TTabRecord<TKey, TData>(k, d);
	size++;

}*/
#endif