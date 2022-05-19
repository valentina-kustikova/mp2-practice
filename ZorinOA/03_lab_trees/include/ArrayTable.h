#pragma once
#include "Table.h"
#include "TabRecord.h"

template<class TKey, class TData>
class ArrayTable : public Table<TKey, TData>
{
protected:
	TabRecord<TKey, TData>** Recs;
	int TabSize;
	int CurrPos;
public:
	ArrayTable(int size = 25)
	{
		Recs = new TabRecord<TKey, TData>*[size];
		TabSize = size;
		CurrPos = -1;
		for (int i = 0; i < TabSize; i++)
			Recs[i] = nullptr;
	}
	virtual ~ArrayTable()
	{
		for (int i = 0; i < this->DataCount; i++)
			delete Recs[i];

		delete[] Recs;
	}
	ArrayTable(const ArrayTable& at)
	{
		this->DataCount = at.DataCount;
		TabSize = at.TabSize;
		CurrPos = at.CurrPos;
		Recs = new TabRecord<TKey, TData>*[TabSize];
		for (int i = 0; i < this->DataCount; i++)
		{
			Recs[i] = new TabRecord<TKey, TData>(*(at.Recs[i]));
		}
	}
	ArrayTable& operator=(const ArrayTable& at)
	{
		for (int i = 0; i < this->DataCount; i++)
		{
			delete Recs[i];
		}
		if (TabSize != at.TabSize)
		{
			delete[] Recs;
			TabSize = at.TabSize;
			Recs = new TabRecord<TKey, TData>*[TabSize];
		}
		this->DataCount = at.DataCount;
		CurrPos = at.CurrPos;
		for (int i = 0; i < this->DataCount; i++)
		{
			Recs[i] = new TabRecord<TKey, TData>(*(at.Recs[i]));
		}
		return *this;
	}
	virtual bool isFull() const
	{
		return this->DataCount >= TabSize;
	}
	int GetTabSize() const
	{
		return TabSize;
	}
	virtual void Clear()
	{
		for (int i = 0; i < this->DataCount; i++)
		{
			delete Recs[i];
		}
		this->DataCount = 0;
		CurrPos = -1;
	}

	virtual void Reset()
	{
		CurrPos = (this->DataCount > 0) ? 0 : -1;
	}
	virtual bool isEnd() const
	{
		return CurrPos >= this->DataCount || CurrPos == -1;
	}
	virtual void goNext()
	{
		if (!isEnd())
			CurrPos++;
	}
	virtual TKey getKey() const
	{
		return (CurrPos == -1) ? TKey() : Recs[CurrPos]->GetKey();
	}
	virtual TData* getData() const
	{
		return (CurrPos == -1) ? nullptr : Recs[CurrPos]->GetData();
	}

	virtual TData* Find(const TKey& k) = 0;
	virtual bool Insert(const TKey& k, const TData& d) = 0;
	virtual bool Delete(const TKey& k) = 0;
};
