#ifndef  _TABLE_H_
#define _TABLE_H_
#include "TabRecord.h"

using namespace std;

template<typename TKey, typename TData>
class Table
{

protected:

	int count;
	int maxSize;
	int currPos;

public:

	Table(int max_size = 101);

	virtual void Insert(const TKey& _key, TData* _data) = 0;
	virtual void Remove(const TKey& _key) = 0;
	virtual TTabRecord<TKey, TData>* Find(const TKey& _key) = 0;

	bool IsFull() const noexcept;
	bool IsEmpty() const noexcept;
	bool IsTabEnded() const noexcept;

	virtual bool Reset() noexcept;
	virtual bool Next() noexcept;

	int GetCurrPos() const noexcept;
	int GetMaxSize() const noexcept;
	int GetCount() const noexcept;

};

template<typename TKey, typename TData>
Table<TKey, TData>::Table(int max_size)
{
	maxSize = max_size;
	count = 0;
	currPos = -1;
}

template<typename TKey, typename TData>
bool Table<TKey, TData>::IsFull() const noexcept
{
	return (count == maxSize);
}

template<typename TKey, typename TData>
bool Table<TKey, TData>::IsEmpty() const noexcept
{
	return (count == 0);
}

template<typename TKey, typename TData>
bool Table<TKey, TData>::IsTabEnded() const noexcept
{
	return (currPos >= maxSize);
}

template<typename TKey, typename TData>
bool Table<TKey, TData>::Reset() noexcept
{
	if (!IsEmpty())
		currPos = 0;
	else
		currPos = -1;
	return IsTabEnded();
}

template<typename TKey, typename TData>
bool Table<TKey, TData>::Next() noexcept
{
	if (!IsTabEnded())
		currPos++;
	return IsTabEnded();
}

template<typename TKey, typename TData>
inline int Table<TKey, TData>::GetCurrPos() const noexcept
{
	return currPos;
}

template<typename TKey, typename TData>
int Table<TKey, TData>::GetMaxSize() const noexcept
{
	return maxSize;
}

template<typename TKey, typename TData>
int Table<TKey, TData>::GetCount() const noexcept
{
	return count;
}




















#endif // _TABLE_H_