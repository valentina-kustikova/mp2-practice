#ifndef TABLE_H
#define TABLE_H

#include "TabRecord.h"

template <class TKey, class TData>
class Table
{
protected:
	int count;
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
	//virtual void Print() = 0;
};

template <class TKey, class TData>
Table<TKey, TData>::Table(int _maxsize)
{
	count = 0;
	maxsize = _maxsize;
	currPos = -1;
}
template <class TKey, class TData>
bool Table<TKey, TData>::IsFull() const
{
	return count == maxsize;
}
template <class TKey, class TData>
bool Table<TKey, TData>::IsEmpty() const
{
	return count == 0;
}
template <class TKey, class TData>
bool Table<TKey, TData>::IsTabEnded() const
{
	return currPos >= maxsize;
}
template <class TKey, class TData>
bool Table<TKey, TData>::Reset()
{
	if (!IsTabEnded())
		currPos = 0;
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
	return count;
}

# endif //! TABLE_H
