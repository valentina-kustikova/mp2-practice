
#ifndef SORTED_TABLE_H_
#define SORTED_TABLE_H_

#include "scan_table.h"

template <class Key, class Value>
class SortedTable : public ScanTable<Key, Value> {
private:
	void sort();

public:
	SortedTable(size_t _max_size=DefaultSize);
	SortedTable(const ScanTable<Key, Value>& table);
	SortedTable(const SortedTable<Key, Value>& table);

	Record<Key, Value>* find(const Key& key);
	void insert(const Key& _key, const Value& _data);
	// we dont need it because we have "find"
	//void remove(const Key& _key);
};

TabTemplate
SortedTable<Key, Value>::SortedTable(size_t _max_size) : ScanTable(_max_size) {}

TabTemplate
SortedTable<Key, Value>::SortedTable(const ScanTable<Key, Value>& table) : ScanTable(st)
{
	this->sort();
}

TabTemplate
SortedTable<Key, Value>::SortedTable(const SortedTable<Key, Value>& table): 
	size(table.size), max_size(table.max_size), curr(table.curr)
{
	recs = new Record<Key, Value>*[max_size];
	for (int i = 0; i < count; i++) {
		recs[i] = Record<Key, Value>(*recs[i]);
	}
}

TabTemplate
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

TabTemplate
void SortedTable<Key, Value>::insert(const Key& _key, const Value& _data) {
	
	if (this->full()) {
		throw string("Table is full\n");
	}

	Record<Key, Value>* exist = find(_key);
	if (exist)
	{
		exist->data = _data;
	}
	else
	{
		for (int i = size - 1; i >= curr; i--)
		{
			recs[i + 1] = recs[i];
		}
		
		recs[curr] = new Record<Key, Value>(_key, _data);
		size++;
	}
}

TabTemplate
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
