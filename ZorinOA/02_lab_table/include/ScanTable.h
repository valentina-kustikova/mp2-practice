#pragma once
#include "ArrayTable.h"
#include "SortTable.h"

template <class TKey, class TData>
class ScanTable : public ArrayTable<TKey, TData>
{
public:
    ScanTable(int size = MAX_SIZE) : ArrayTable<TKey, TData>(size) {}
    virtual TData* Find(const TKey& k)
	{
		for (int i = 0; i < this->DataCount; i++)
		{
			if (this->Recs[i].GetKey() == k)
                return &(this->Recs[i].GetData());
		}
        return nullptr;
	}
    virtual void Insert(const TKey& k, const TData& d)
	{
        if (this->DataCount < this->TabSize)
		{
            this->Recs[this->DataCount] = TabRecord<TKey, TData>(k, d);
			this->DataCount++;
		}
	}
    virtual void Delete(const TKey& k)
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
