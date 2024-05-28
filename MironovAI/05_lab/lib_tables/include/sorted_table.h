
#ifndef SORTED_TABLE_H_
#define SORTED_TABLE_H_

#include "scan_table.h"

template <class Key, class Value>
class SortedTable : public ScanTable<Key, Value> {
private:
	void sort();

public:
	SortedTable(int _max_size=DefaultSize) noexcept;
	SortedTable(const ScanTable<Key, Value>& table) noexcept;
	SortedTable(const SortedTable<Key, Value>& table) noexcept;

	Record<Key, Value>* find(const Key& key);
	void remove(const Key& _key);
	void insert(const Key& _key, const Value& _data);
};

template <class Key, class Value>
SortedTable<Key, Value>::SortedTable(int _max_size) noexcept : ScanTable(_max_size) {}

template <class Key, class Value>
SortedTable<Key, Value>::SortedTable(const ScanTable<Key, Value>& table) noexcept : ScanTable(st)
{
	this->sort();
}

template <class Key, class Value>
SortedTable<Key, Value>::SortedTable(const SortedTable<Key, Value>& table) noexcept :
	size(table.size), max_size(table.max_size), curr(table.curr)
{
	recs = new Record<Key, Value>*[max_size];
	for (int i = 0; i < count; i++) {
		recs[i] = Record<Key, Value>(*recs[i]);
	}
}

template <class Key, class Value>
Record<Key, Value>* SortedTable<Key, Value>::find(const Key& key) 
{
	int l = 0, r = size - 1;
	while (l <= r) {
		
		int mid = (l + r) / 2;
		
		if (recs[mid]->key == key) 
		{
			curr = mid;
			return recs[mid];
		}
		if (recs[mid]->key < key) 
		{
			curr = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return nullptr;
}

template <class Key, class Value>
void SortedTable<Key, Value>::insert(const Key& _key, const Value& _data) {
	
	if (this->full()) {
		throw string("Table is full\n");
	}

	Record<Key, Value>* exist = find(_key);
	if (exist)
	{
		throw string("Element is not exist\n");
	}
	else
	{
		if (recs[curr] != nullptr) if (recs[curr]->key < _key) curr++;
		for (int i = size - 1; i >= curr; i--)
		{
			recs[i + 1] = recs[i];
		}
		recs[curr] = new Record<Key, Value>(_key, _data);
		size++;
	}
}

template <class Key, class Value>
void SortedTable<Key, Value>::remove(const Key& _key)
{
	if (this->empty()) {
		throw string("Table is empty\n");
	}

	Record<Key, Value>* exist = find(_key);
	if (!exist)
	{
		throw string("Element is not exist\n");
	}
	else
	{
		if (recs[curr] != nullptr) if (recs[curr]->key < _key) curr++;
		for (int i = curr; i < size; ++i)
		{
			recs[i] = recs[i + 1];
		}
		if (recs[--size]) delete recs[size];

	}
}

template <class Key, class Value>
void SortedTable<Key, Value>::sort()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (recs[i] > recs[j])
			{
				Record<Key, Value>* t = recs[i];
				recs[i] = recs[j];
				recs[j] = t;
			}
		}
	}
}

#endif // !SORTED_TABLE_H_
