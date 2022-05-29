#pragma once
#include <iostream>
#include "TabRecord.h"
using namespace std;

template <class TData, class TKey>
class Table
{
protected:
	int Top;
public:
	Table() { Top = 0; }
	virtual ~Table() {};
	virtual void Insert(const TData& _data, const TKey& _Key) = 0;
	virtual void Delete(const TKey& _Key) = 0;
	virtual TData* Search(const TKey& _Key) = 0;
	virtual void Reset() = 0;
	virtual void SetNext() = 0;
	virtual bool IsEnd() const = 0;
	virtual bool IsFull() const = 0;
	virtual bool IsEmpty() const { return Top == 0; }
	virtual TData* GetData() const = 0;
	virtual TKey GetKey() const = 0;
	friend ostream& operator<<(ostream& os, Table<TData, TKey>& Table)
	{
		for (Table.Reset(); !Table.IsEnd(); Table.SetNext())
		{
			os << Table.GetKey() << " -- " << *Table.GetData() << endl;
		}
		os << "=======================================";
		return os;
	}
};