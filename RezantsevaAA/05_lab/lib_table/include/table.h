#ifndef __TABLE_H__
#define __TABLE_H__

#include "tabRecord.h"
#include <iostream>

template <typename TKey, typename TData> 
class TTable
{
protected:
	int size; //количество записей
	int maxSize;
	int currPos; 

public:
	TTable() { size = 0; currPos = -1; };
	TTable(int _maxSize);
	~TTable() { };
	virtual void Insert(const TKey& k, const TData& d) = 0;
	virtual void Remove(const TKey& k) = 0;
	virtual TTabRecord <TKey, TData>* Find(const TKey& k) = 0;
	//Get
	virtual TKey GetKey() const = 0;
	virtual TData* GetData() const = 0;
	int GetSize() const;
	//навигация
	virtual bool IsTabEnded() const; //таблица завершена? 
	virtual bool Reset();   
	virtual bool Next();	
	bool IsFull() const;
	bool IsEmpty() const;

};

template <typename TKey, typename TData> TTable<TKey, TData>::TTable(int _maxSize)
{
	maxSize = _maxSize;
	size = 0;
	currPos = -1;
}

template <typename TKey, typename TData> int TTable<TKey, TData>::GetSize() const
{
	return size;
}

template <typename TKey, typename TData> bool TTable<TKey, TData>::IsFull() const
{
	return (size == maxSize);
}


template <typename TKey, typename TData> bool TTable<TKey, TData>::IsEmpty() const
{
	return (size == 0);
}

template <typename TKey, typename TData> bool TTable<TKey, TData>::IsTabEnded() const
{
	return (currPos >= maxSize); 
}
template <typename TKey, typename TData> bool TTable<TKey, TData>::Reset()
{
	if (!IsEmpty())
	{
		currPos = 0;
		return true;
	}
	else
	{
		currPos = -1;
		return false;
	}
}

template <typename TKey, typename TData> bool TTable<TKey, TData>::Next()
{
	if ( currPos < maxSize && !IsEmpty())
	{
		currPos++;
		return true;
	}
	else
	{
		return false;
	}
}
#endif