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
	}
	virtual ~ArrayTable()
	{
		for (int i = 0; i < DataCount; i++)
			delete Recs[i];

		delete[] Recs;
	}
	ArrayTable(const ArrayTable& at)
	{
		DataCount = at.DataCount;
		TabSize = at.TabSize;
		CurrPos = at.CurrPos;
		Recs = new TabRecord<TKey, TData>*[TabSize];
		for (int i = 0; i < DataCount; i++)
		{
			Recs[i] = new TabRecord<TKey, TData>(*(at.Recs[i]));
		}
	}
	ArrayTable& operator=(const ArrayTable& at)
	{
		for (int i = 0; i < DataCount; i++)
		{
			delete Recs[i];
		}
		if (TabSize != at.TabSize)
		{
			delete[] Recs;
			TabSize = at.TabSize;
			Recs = new TabRecord<TKey, TData>*[TabSize];
		}
		DataCount = at.DataCount;
		CurrPos = at.CurrPos;
		for (int i = 0; i < DataCount; i++)
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
		for (int i = 0; i < DataCount; i++)
		{
			delete Recs[i];
		}
		DataCount = 0;
		CurrPos = -1;
	}

	virtual void Reset()
	{
		CurrPos = DataCount > 0 ? 0 : -1;
	}
	virtual bool isEnd() const
	{
		return CurrPos >= DataCount || CurrPos == -1;
	}
	virtual void goNext()
	{
		if(!isEnd())
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
    virtual void Insert(const TKey& k, const TData& d) = 0;
    virtual void Delete(const TKey& k) = 0;

	/*class Iterator
	{
		TabRecord<TKey, TData>** CurrPos;
	public:
		Iterator(TabRecord<TKey, TData>** pos = nullptr)
		{
			CurrPos = pos;
		}
		TabRecord<TKey, TData>* operator*() const
		{
			return *CurrPos;
		}
		Iterator& operator++()
		{
			CurrPos++;
			return *this;
		}
        Iterator operator+(int k)
        {
            Iterator it(*this);
            it.CurrPos += k;
            return it;
        }
		bool operator!=(const Iterator& it)
		{
			return CurrPos != it.CurrPos;
		}

	};
    Iterator begin() const
	{
		ArrayTable::Iterator it(Recs);
		return it;
	}
    Iterator end() const
	{
		ArrayTable::Iterator it(Recs + this->DataCount);
		return it;
	}

	friend std::ostream& operator<<(std::ostream& os, const ArrayTable& at)
	{
		for (int i = 0; i < at.DataCount; i++)
		{
			os << *(at.Recs[i]) << std::endl;
		}
		return os;
	}*/
};
