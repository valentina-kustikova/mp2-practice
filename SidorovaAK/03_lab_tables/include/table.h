#ifndef _TABLE_H_
#define _TABLE_H_

#include "tabrecord.h"

template<typename TKey, class TData>
class Table
{
protected:
	int tabSize;
	int dataCount;
	int currPos;

public:
	Table(int _tabSize) : tabSize(_tabSize), dataCount(0), currPos(0) {}

	bool IsEmpty() const { return dataCount == 0; }
	bool IsFull() const { return dataCount == tabSize; }
	int GetDataCount() const { return dataCount; }
	
	virtual TabRecord<TKey, TData>* FindRecord(TKey key) = 0;
	virtual void InsertRecord(TKey key, TData* data) = 0;
	virtual void RemoveRecord(TKey key) = 0;
	
	virtual int Reset()
	{
		currPos = 0;
		return IsTabEnded();
	}
	virtual int GetNext()
	{
		if (!IsTabEnded()) currPos++;
		return IsTabEnded();
	}

	virtual int IsTabEnded() const { return currPos >= tabSize; }
	
	virtual TKey GetKey() const = 0;
	virtual TData* GetData() const = 0;
};

#endif
