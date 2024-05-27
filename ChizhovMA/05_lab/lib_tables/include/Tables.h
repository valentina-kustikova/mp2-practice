#ifndef TABLE_H
#define TABLE_H

#include "TabRecord.h"

template <class TKey, class TData>
class Table
{
protected:
	int Count;
	int maxsize;
	int currPos;
public:
	Table(int _maxsize);
	virtual void Insert(TKey k, TData* d) = 0;
	virtual void Remove(TKey k) = 0;
	virtual TabRecord<TKey, TData>* Find(TKey k) = 0;
	bool IsFull() const;
	bool IsEmpty() const;
	virtual bool IsTabEnded() const;
	virtual bool Next();
	virtual bool Reset();
	int GetCount() const;
	virtual TKey GetKey() const = 0;
	virtual TData* GetData() const = 0;
};

template <class TKey, class TData>
Table<TKey, TData>::Table(int _maxsize)
{
	Count = 0;
	maxsize = _maxsize;
	currPos = -1;
}
template <class TKey, class TData>
bool Table<TKey, TData>::IsFull() const
{
	return Count == maxsize;
}
template <class TKey, class TData>
bool Table<TKey, TData>::IsEmpty() const
{
	return Count == 0;
}
template <class TKey, class TData>
bool Table<TKey, TData>::IsTabEnded() const
{
	return currPos >= maxsize;
}
template <class TKey, class TData>
bool Table<TKey, TData>::Reset()
{
	if (!IsEmpty())
		currPos = 0;
	else 
		currPos = -1;
	return IsTabEnded();
	
}
template <class TKey, class TData>
bool Table<TKey, TData>::Next()
{
	if (!IsTabEnded())
		currPos++;
	return IsTabEnded();
}
template <class TKey, class TData>
int Table<TKey, TData>::GetCount() const
{
	return Count;
}

# endif //! TABLE_H
