#ifndef __TABLE_H__
#define __TABLE_H__

#include "tab_record.h"

using namespace std;

template <typename TKey, typename TData>
class Table {
protected:
	int count;
	int maxSize;
	int currPos;
public:
	Table(int max_size);
	virtual TabRecord<TKey, TData>* Search(TKey _key) = 0;
	virtual void Insert(TKey _key, TData* _data) = 0;
	virtual void Remove(TKey _key) = 0;
	virtual TabRecord<TKey, TData>* GetCurrent()const;
	virtual bool IsFull()const;
	virtual bool IsEmpty()const;
	virtual bool IsEnded()const;
	virtual void Reset();
	virtual void Next();
};

template <typename TKey, typename TData>
Table<TKey, TData>::Table(int max_size) {
	if (max_size <= 0)
		throw exception("negative or zero max size");
	count = 0;
	maxSize = max_size;
	currPos = -1;
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* Table<TKey, TData>::GetCurrent()const {
	if (IsEmpty())
		throw std::exception("table is empty");
	return recs[currPos];
}

template <typename TKey, typename TData>
bool Table<TKey, TData>::IsFull()const {
	return count == maxSize;
}

template <typename TKey, typename TData>
bool Table<TKey, TData>::IsEmpty()const {
	return count == 0;
}

template <typename TKey, typename TData>
bool Table<TKey, TData>::IsEnded()const {
	return currPos == maxSize;
}

template <typename TKey, typename TData>
void Table<TKey, TData>::Reset() {
	currPos = 0;
}

template <typename TKey, typename TData>
void Table<TKey, TData>::Next() {
	if (IsEnded())
		throw exception("end of the table");
	currPos++;
}

#endif