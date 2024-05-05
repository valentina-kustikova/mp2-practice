#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include "table.h"

template <class Key, class Value>
class HashTable : public Table<Key, Value> 
{
protected:
	Record<Key, Value>** recs;
	Record<Key, Value>* pMark = new Record<Key, Value>();
	size_t step;

	virtual size_t hash(const Key& key) const noexcept;
public:
	HashTable<Key, Value>(size_t max_size=DefaultSize);
	HashTable<Key, Value>(const HashTable& table);
	virtual ~HashTable<Key, Value>();

	Record<Key, Value>* find(const Key& key);
	void insert(const Key& key, const Value& value);
	void remove(const Key& key);
	void next(int pos);
};

template <class Key, class Value>
size_t HashTable<Key, Value>::hash(const Key& key) const noexcept
{
	std::hash<Key> hasher;
	return hasher(key) % max_size;
	
}

TabTemplate
HashTable<Key, Value>::HashTable(size_t max_size)
{
	if (max_size == 0)
	{
		throw string("max_size and step should be > 0\n");
	}
	step = (max_size == 13) ? 11 : 13;
	this->max_size = max_size;
	curr = 0;
	recs = new Record<Key, Value>*[max_size]();
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
		if (recs[i]==pMark)
		{
			delete recs[i];
		}
	}
	delete recs;
	delete pMark;
}

TabTemplate
Record<Key, Value>* HashTable<Key, Value>::find(const Key& key)
{
	int hs = hash(key), t = (hs + step) % max_size, c = 1;
	curr = hs;
	
	if (recs[hs] == nullptr)
	{
		return nullptr;
	}
	if (recs[hs]->key == key)
	{
		return recs[hs];
	}
	while (recs[t] != nullptr && t != hs && c < max_size)
	{
		if (recs[t]->key == key)
		{
			curr = t;
			return recs[t];
		}
		if (recs[t] == nullptr)
		{
			return nullptr;
		}
		t += step;
		++c;
	}
	if (recs[curr] != pMark && recs[curr] != nullptr) next(curr);
	return nullptr;
}

TabTemplate
void HashTable<Key, Value>::insert(const Key& key, const Value& value)
{
	if (size == max_size)
	{
		throw string("Table is full\n");
	}
	Record<Key, Value>* exist = find(key);

	if (!exist)
	{
		recs[curr] = new Record<Key, Value>(key, value);
		size++;
	}
	else
	{
		exist->data = value;
	}
}

TabTemplate
void HashTable<Key, Value>::remove(const Key& key)
{
	if (size == 0)
	{
		throw string("Table is empty\n");
	}
	Record<Key, Value>* exist = find(key);
	
	if (!exist)
	{
		throw string("Wrong key\n");
	}
	else
	{
		size--;
		delete exist;
		recs[curr] = pMark;
	}
}

TabTemplate
void HashTable<Key, Value>::next(int pos)
{
	if (size == max_size) curr = 0;
	int new_pos = (pos + step % max_size);
	while (new_pos != pos && (recs[new_pos] != pMark && recs[new_pos] != nullptr))
	{
		new_pos = (new_pos + step) % max_size;
	}
	curr = new_pos;
}
#endif // !HASH_TABLE_H_