#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include "table.h"

template <class Key, class Value>
class HashTable : public Table<Key, Value> 
{
protected:
	Record<Key, Value>** recs;
	Record<Key, Value>* const pMark = new Record<Key, Value>(Key(), Value());
	size_t step;

	virtual int hash(const Key& key) const;
public:
	HashTable<Key, Value>(size_t max_size=DefaultSize, size_t step=2);
	HashTable<Key, Value>(const HashTable& table);
	~HashTable<Key, Value>();

	Record<Key, Value>* find(const Key& key, const Value& value);
	void insert(const Key& key, const Value& value);
	void remove(const Key& key);
	
	int next;
};

template <class Key, class Value>
int HashTable<Key, Value>::hash(const Key& key) const
{
	return std::hash<Key>(key) % max_size;
}

TabTemplate
HashTable<Key, Value>::HashTable(size_t max_size, size_t step)
{
	if (max_size == 0 || step == 0)
	{
		throw string("max_size and step should be > 0\n");
	}
	this->max_size = max_size;
	this->step = step;
	curr = 0;
	recs = new Record<Key, Value>*[max_size];
}

TabTemplate
HashTable<Key, Value>::HashTable(const HashTable& table)
{
	this->max_size = table.max_size;
	this->step = table.step;
	curr = table.curr;
	recs = new Record<Key, Value>*[max_size];
	for (int i = 0; i < max_size; ++i)
	{
		if (table.recs[i])
		{
			recs[i] = new Record<Key, Value>(table.recs[i]);
		}
	}
}

TabTemplate
HashTable<Key, Value>::~HashTable()
{
	if (!recs) return;
	for (int i = 0; i < max_size; ++i)
	{
		if (recs[i])
		{
			delete recs[i];
		}
	}
	delete recs;
}

TabTemplate
Record<Key, Value>* HashTable<Key, Value>::find(const Key& key, const Value& value)
{
	int hs = hash(key), t = (hs + step) % mod, c = 1;
	curr = hs;
	if (recs[hs] == Record(key, value);
	{
		return recs[hs];
	}
	if (recs[hs] == nullptr)
	{
		curr = hs;
		return nullptr;
	}
	while (recs[t] != nullptr && t != hs && c < max_size)
	{
		if (recs[t] == key)
		{
			return recs[t];
		}
		if (recs[t] == nullptr)
		{
			curr = t;
			return nullptr;
		}
		t += step;
		++c;
	}
	
	return nullptr;
}

TabTemplate
void HashTable<Key, Value>::insert(const Key& key, const Value& value)
{
	Record<Key, Value>* exist = find({ key, value });

	if (!exist)
	{
		exist = new Record<Key, Value>(key, value);
	}
	else
	{
		if (size == max_size)
		{
			throw string("Table is full\n");
		}
		recs[curr] = value;
	}
}

TabTemplate
void HashTable<Key, Value>::remove(const Key& key)
{
	if (size == 0)
	{
		throw string("Table is empty\n");
	}
	Record<Key, Value>* exist = find({ key, value });
	
	if (!exist)
	{
		throw string("Wrong key\n");
	}
	else
	{
		recs[curr] = pMark;
	}
}
#endif // !HASH_TABLE_H_