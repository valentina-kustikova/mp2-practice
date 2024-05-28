#ifndef SCAN_TABLE_H_
#define SCAN_TABLE_H_

#include <iostream>
#include <vector>
#include "table.h"
using namespace std;

template <class Key, class Value>
class ScanTable : public Table<Key, Value> {
protected:
	Record<Key, Value>** recs;

public:
	ScanTable(int _max_size=DefaultSize) noexcept;
	ScanTable(const ScanTable<Key, Value>& table) noexcept;
	virtual ~ScanTable();
	
	virtual Record<Key, Value>* find(const Key& key);
	virtual void insert(const Key& key, const Value& value);
	virtual void remove(const Key& key);
	friend ostream& operator<<(ostream& buf, const ScanTable& table)
	{
		cout << "Table size: " << table.size << endl;
		for (int i = 0; i < table.max_size; ++i)
		{
			if (table.recs[i])
				cout << "(" << table.recs[i]->key << ", " << table.recs[i]->data << "), ";
		}
		cout << endl;
		return buf;
	}	
};


template <class Key, class Value>
ScanTable<Key, Value>::ScanTable(int _max_size) noexcept
{
	if (_max_size <= 0)
	{
		max_size = -1;
		return;
	}
	max_size = _max_size;
	size = 0;
	curr = 0;
	recs = new Record<Key, Value>*[max_size];
	for (int i = 0; i < _max_size; ++i) recs[i] = nullptr;

}

template <class Key, class Value>
ScanTable<Key, Value>::ScanTable(const ScanTable<Key, Value>& table) noexcept :
	max_size(table.max_size), size(table.size), curr(table.curr) 
{ 
	recs = new Record<Key, Value>*[max_size];
	for (int i = 0; i < max_size; ++i)
	{
		if (table.recs[i])
		{
			recs[i] = new Record<Key, Value>(*table.recs[i]);
		}
	}
}

template <class Key, class Value>
ScanTable<Key, Value>::~ScanTable() 
{
	if (max_size == -1) return;
	for (int i = 0; i < max_size; ++i)
	{
		if (recs[i]) delete recs[i];
	}
	if (recs != nullptr) delete recs;
}


template <class Key, class Value>
void ScanTable<Key, Value>::insert(const Key& _key, const Value& _data)
{
	if (this->full())
	{
		throw string("Table is full\n");
	}

	Record<Key,Value>* exist = find(_key);
	if (exist) 
	{
		throw string("Insert!");
	}
	recs[size++] = new Record<Key, Value>(_key, _data);
}

template <class Key, class Value>
void ScanTable<Key, Value>::remove(const Key& _key)
{
	if (this->empty())
	{
		throw string("Table is empty\n");
	}
	Record<Key, Value>* exist = find(_key);
	if (!exist) throw string("Key doesn`t exist\n");

	delete recs[curr];
	recs[curr] = nullptr;
	if (--size >= 0 && curr != size)
	{
		recs[curr] = recs[size];
		recs[size] = nullptr;
	}
}

template <class Key, class Value>
Record<Key, Value>* ScanTable<Key, Value>::find(const Key& key) 
{
	for (int i = 0; i < size; ++i)
	{
		if (recs[i]->key == key)
		{
			curr = i;
			return recs[i];
		}
	}
	return nullptr;
}

#endif // !SCAN_TABLE_H_