#pragma once
#include "tabrecord.h"

template <typename TData, typename TKey>
class TTable
{
protected:
	int tabSize;
	int dataCount;
	int currPos;
public:
	TTable<TData, TKey>() {};
	TTable(int _tabSize);
	~TTable() {};
	// информационные методы
	int IsEmpty() const;
	int IsFull() const;
	int GetDataCount() const;
	// операции над таблицами
	virtual TTabRecord<TData, TKey>* FindRecord(TKey key) = 0;
	virtual void InsertRecord(TKey key, TData data) = 0;
	virtual void RemoveRecord(TKey key) = 0;
	// навигация по таблице
	void Reset();
	void GetNext();
	bool IsTabEnded() const;
};

template <typename TData, typename TKey>
TTable<TData, TKey>::TTable(int _tabSize)
{
	this->tabSize = _tabSize;
	this->currPos = -1;
	this->dataCount = 0;
}

template <typename TData, typename TKey>
int TTable<TData, TKey>::IsEmpty() const
{
	if (dataCount == 0)
		return 1;
	else
		return 0;
}

template <typename TData, typename TKey>
int TTable<TData, TKey>::IsFull() const
{
	if (dataCount == tabSize)
		return 1;
	else
		return 0;
}

template <typename TData, typename TKey>
int TTable<TData, TKey>::GetDataCount() const
{
	return dataCount;
}

template <typename TData, typename TKey>
void TTable<TData, TKey>::Reset()
{
	if (dataCount > 0)
	{
		currPos = 0;
	}
	else
	{
		currPos = -1;
	}
}

template <typename TData, typename TKey>
void TTable<TData, TKey>::GetNext()
{
	currPos++;
}

template <typename TData, typename TKey>
bool TTable<TData, TKey>::IsTabEnded() const
{
	return currPos == dataCount || currPos == -1;
}