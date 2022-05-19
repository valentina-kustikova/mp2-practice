#pragma once
#include "ArrayTable.h"

template <class TKey, class TData>
class ScanTable : public ArrayTable<TKey, TData>
{
public:
	ScanTable(int size = 25) : ArrayTable<TKey, TData>(size) {}
	virtual TData* Find(const TKey& k)
	{
		for (int i = 0; i < this->DataCount; i++)
		{
			if (this->Recs[i]->GetKey() == k)
			{
				this->CurrPos = i;
				return this->Recs[i]->GetData();
			}
		}
		return nullptr;
	}
	virtual bool Insert(const TKey& k, const TData& d)
	{
		if (!this->isFull())
		{
			TData* tmp = Find(k);
			if (tmp == nullptr)
			{
				this->Recs[this->DataCount] = new TabRecord<TKey, TData>(k, d);
				this->DataCount++;
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	virtual bool Delete(const TKey& k)
	{
		if (Find(k) != nullptr)
		{
			delete this->Recs[this->CurrPos];
			this->Recs[this->CurrPos] = this->Recs[--this->DataCount];
			return true;
		}
		else
			return false;
	}
};
