#pragma once
#include "ArrayTable.h"

template <class TKey, class TData>
class ScanTable : public ArrayTable<TKey, TData>
{
public:
    ScanTable(int size = 25) : ArrayTable<TKey, TData>(size) {}
	virtual TData* Find(TKey k) 
	{
		for (int i = 0; i < this->DataCount; i++)
		{
			if (this->Recs[i].GetKey() == k)
				return this->Recs[i].GetValuePtr();
		}
		return nullptr;
	}
	virtual void Insert(TKey k, TData* ptr)
	{
        if (this->DataCount < this->TabSize)
		{
			this->Recs[this->DataCount] = TabRecord<TKey, TData>(k, ptr);
			this->DataCount++;
		}
	}
	virtual void Delete(TKey k)
	{
		for (int i = 0; i < this->DataCount; i++)
		{
			if (this->Recs[i].GetKey() == k)
			{
				this->Recs[i] = this->Recs[--this->DataCount];
				return;
			}
		}
	}
};
