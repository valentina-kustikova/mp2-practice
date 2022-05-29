#pragma once
#include "Table.h"
#include "TabRecord.h"

template<class TData, class TKey>
class ArrayTable : public Table<TData, TKey>
{
protected:
	TabRecord<TData, TKey>** DataTab;
	int MaxSize;
	int current;
public:
	ArrayTable(int MaxSize = 10);
	virtual ~ArrayTable();
	ArrayTable(const ArrayTable& Table);
	ArrayTable& operator=(const ArrayTable& Table);
	virtual bool IsFull() const
	{
		if (Top == 0)
			return true;
		if (current == Top - 1)
			return 1;
		else return 0;
	}
	virtual void Clear()
	{
		for (int i = 0; i < this->Top; i++)
		{
			delete DataTab[i];
		}
		this->Top = 0;
		current = -1;
	}
	virtual void Reset() { current = 0; };
	virtual bool IsEnd() const { return current == Top || current == -1; }
	virtual void SetNext() { if (!IsEnd()) current++; }
	virtual TKey GetKey() const { return (DataTab[current]->GetKey()); }
	TData* GetData() const { return (DataTab[current]->GetData()); }
	virtual TData* Search(const TKey& _Key) = 0;
	virtual void Insert(const TData& _data, const TKey& _key) = 0;
	virtual void Delete(const TKey& _key) = 0;
};

template<class TData, class TKey>
ArrayTable<TData, TKey>::ArrayTable(int SizeTable)
{
	MaxSize = SizeTable;
	DataTab = new TabRecord<TData, TKey> *[SizeTable];
	for (int i = 0; i < SizeTable; i++)
		DataTab[i] = NULL;
	Top = 0;
	current = 0;
}

template<class TData, class TKey>
ArrayTable<TData, TKey>::~ArrayTable()
{
	for (int i = 0; i < Top; i++)
		delete DataTab[i];
	delete[] DataTab;
}
template<class TData, class TKey>
ArrayTable<TData, TKey>::ArrayTable(const ArrayTable& Table)
{
	this->Top = Table.Top;
	MaxSize = Table.MaxSize;
	current = Table.current;
	DataTab = new TabRecord<TData, TKey>*[MaxSize];
	for (int i = 0; i < this->Top; i++)
	{
		DataTab[i] = new TabRecord<TData, TKey>(*(Table.DataTab[i]));
	}
}
template<class TData, class TKey>
ArrayTable<TData, TKey>& ArrayTable<TData, TKey>::operator=(const ArrayTable& Table)
{
	for (int i = 0; i < this->Top; i++)
	{
		delete DataTab[i];
	}
	if (MaxSize != Table.MaxSize)
	{
		delete[] DataTab;
		MaxSize = Table.MaxSize;
		DataTab = new TabRecord<TData, TKey>*[MaxSize];
	}
	this->Top = Table.Top;
	current = Table.current;
	for (int i = 0; i < this->Top; i++)
	{
		DataTab[i] = new TabRecord<TData, TKey>(*(Table.DataTab[i]));
	}
	return *this;
}