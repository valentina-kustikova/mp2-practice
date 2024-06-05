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
	virtual TabRecord<TKey, TData>* GetCurrent()const = 0;
	virtual TabRecord<TKey, TData>* Search(TKey _key) = 0;
	virtual void Insert(TKey _key, TData* _data) = 0;
	virtual void Remove(TKey _key) = 0;
	virtual bool IsFull()const noexcept;
	virtual bool IsEmpty()const noexcept;
	virtual bool IsEnded()const noexcept;
	virtual void Reset() noexcept;
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
bool Table<TKey, TData>::IsFull()const noexcept {
	return count == maxSize;
}

template <typename TKey, typename TData>
bool Table<TKey, TData>::IsEmpty()const noexcept {
	return count == 0;
}

template <typename TKey, typename TData>
bool Table<TKey, TData>::IsEnded()const noexcept {
	return currPos == maxSize;
}

template <typename TKey, typename TData>
void Table<TKey, TData>::Reset() noexcept {
	currPos = 0;
}

template <typename TKey, typename TData>
void Table<TKey, TData>::Next() {
	if (IsEnded())
		throw exception("end of the table");
	currPos++;
}

#endif