#pragma once
#include "Table.h"
#include "TabRecord.h"

template<class TKey, class TData>
class ArrayTable : public Table<TKey, TData>
{
protected:
	TabRecord<TKey, TData>* Recs;
	int TabSize;
public:
	ArrayTable(int size = MAX_SIZE)
	{
        if (size > 0 && size <= MAX_SIZE)
		{
			Recs = new TabRecord<TKey, TData>[size];
			TabSize = size;
		}
        else
            throw "Wrong size!!!";
	}
	virtual ~ArrayTable()
	{
		delete[] Recs;
	}
	ArrayTable(const ArrayTable& at)
	{
		TabSize = at.TabSize;
		this->DataCount = at.DataCount;
		Recs = new TabRecord<TKey, TData>[TabSize];
		for (int i = 0; i < this->DataCount; i++)
		{
			Recs[i] = at.Recs[i];
		}
		

	}
	ArrayTable& operator=(const ArrayTable& at)
	{
		if (this != &at)
		{
			if (TabSize != at.TabSize)
			{
				delete[] Recs;
				TabSize = at.TabSize;
				Recs = new TabRecord<TKey, TData>[TabSize];
			}
			this->DataCount = at.DataCount;
			for (int i = 0; i < this->DataCount; i++)
			{
				Recs[i] = at.Recs[i];
			}
		}
		return *this;
	}
	virtual bool isFull() const
	{
		return this->DataCount == TabSize;
	}
	int GetTabSize() const
	{
		return TabSize;
	}
	virtual void Clear()
	{
		this->DataCount = 0;
	}
    virtual TData* Find(const TKey& k) = 0;
    virtual void Insert(const TKey& k, const TData& d) = 0;
    virtual void Delete(const TKey& k) = 0;

	class Iterator
	{
		TabRecord<TKey, TData>* CurrPos;
	public:
		Iterator(TabRecord<TKey, TData>* pos = nullptr)
		{
			CurrPos = pos;
		}
		TabRecord<TKey, TData>& operator*()
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
		bool operator<(const Iterator& it)
		{
			return CurrPos < it.CurrPos;
		}
		bool operator>(const Iterator& it)
		{
			return CurrPos > it.CurrPos;
		}
		bool operator==(const Iterator& it)
		{
			return CurrPos == it.CurrPos;
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
			os << at.Recs[i] << std::endl;
		}
		return os;
	}
};
