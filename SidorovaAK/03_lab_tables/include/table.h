#ifndef _TABLE_H_
#define _TABLE_H_

#include "tabrecord.h"
#include "exceptions.h"

#include <iostream>

using namespace std;

template<typename TKey, class TData>
class TTable
{
protected:
	int tabSize;
	int dataCount;
	int currPos;

public:
	TTable(int _tabSize);

	bool IsEmpty() const { return dataCount == 0; }
	bool IsFull() const { return dataCount >= tabSize; }
	int GetDataCount() const { return dataCount; }
	int GetCurrentPos() const { return currPos; }
	
	virtual TTabRecord<TKey, TData>* FindRecord(TKey _key) = 0;
	virtual void InsertRecord(TKey _key, TData* _data = nullptr) = 0;
	virtual void RemoveRecord(TKey _key) = 0;
	
	virtual bool Reset();
	virtual bool GetNext();

	virtual bool IsTabEnded() const { return currPos >= tabSize; }
	
	virtual TTabRecord<TKey, TData>* GetRecord() const = 0;
	virtual TKey GetKey() const = 0;
	virtual TData* GetData() const = 0;

	template<typename TKey, class TData> friend ostream& operator<<(ostream& _out, TTable& _table);
};
//-------------------------------------------------

template<typename TKey, class TData>
TTable<TKey, TData>::TTable(int _tabSize) : dataCount(0), currPos(0)
{
	if (_tabSize <= 0)
		throw Exception("Max size of table must be positive!");

	tabSize = _tabSize;
};


template<typename TKey, class TData>
bool TTable<TKey, TData>::Reset()
{
	currPos = 0;
	return IsTabEnded();
};

template<typename TKey, class TData>
bool TTable<TKey, TData>::GetNext()
{
	if (!IsTabEnded()) currPos++;
	return IsTabEnded();
};

template<typename TKey, class TData>
ostream& operator<<(ostream& _out, TTable<TKey, TData>& _table)
{
	if (_table.IsEmpty())
		_out << "Table is empty!" << endl;
	else
		for (_table.Reset(); !_table.IsTabEnded(); _table.GetNext())
		{
			if (_table.GetRecord() != nullptr)
				_out << *_table.GetRecord() << endl;
		}

	return _out;
};

#endif
