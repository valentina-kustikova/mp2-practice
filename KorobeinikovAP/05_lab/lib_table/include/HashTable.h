#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include "table.h"
#include <iostream>
#include <iomanip>

template <class TKey, class TData>
class HashTable : public Table<TKey, TData>
{
protected:
	TabRecord<TKey, TData>** recs;
	TabRecord<TKey, TData>* pMark = new TabRecord<TKey, TData>();
	size_t step;

	virtual size_t hash(const TKey& key) const;
public:
	HashTable<TKey, TData>(int _max_size = 100);
	HashTable<TKey, TData>(const HashTable& table) noexcept;
	virtual ~HashTable<TKey, TData>();

	TabRecord<TKey, TData>* find(const TKey& key);
	virtual void insert(const TKey& _key, TData* _data);
	virtual void remove(const TKey& key);

	TabRecord<TKey, TData>* operator[](const TKey& _key);

	void next(int pos);
	friend ostream& operator<<(ostream& os, const HashTable& table)
	{	
		os << "HashTable count: " << table.count << endl;
		string str1 = string(32, '-'), str2 = string(62, '-');
		os << '+' << str1 << '+' << str2 << '+' << endl;
		for (int i = 0; i < table.max_size; ++i)
		{
			if (table.recs[i] && (table.recs[i] != table.pMark)) {
				os << "| " << setw(30) << table.recs[i]->key << " | " << setw(60) << *table.recs[i]->data << " | \n";
				os << '+' << str1 << '+' << str2 << '+' << endl;
			}
		}
		os <<endl;
		return os;
	}
};

template <class TKey, class TData>
size_t HashTable<TKey, TData>::hash(const TKey& key) const
{
	std::hash<TKey> hasher;
	return hasher(key) % max_size;

}

template <class TKey, class TData>
HashTable<TKey, TData>::HashTable(int _max_size)
{
	if (_max_size <= 0)
	{
		throw "Size can't is negative";
	}
	max_size = _max_size;
	count = 0;
	curr_pos = 0;
	recs = new TabRecord<TKey, TData>* [max_size];
	for (int i = 0; i < _max_size; ++i) recs[i] = pMark;

	step = (max_size == 13) ? 11 : 13;
}

template <class TKey, class TData>
HashTable<TKey, TData>::HashTable(const HashTable& table) noexcept
{
	this->max_size = table.max_size;
	this->step = table.step;
	this->count = table.count;
	curr_pos = table.curr_pos;

	recs = new TabRecord<TKey, TData>* [max_size];
	for (int i = 0; i < max_size; ++i)
	{
		if (table.recs[i] != table.pMark)
		{
			recs[i] = new TabRecord<TKey, TData>(*table.recs[i]);
		}
		else {
			recs[i] = this->pMark;
		}
	}
}

template <class TKey, class TData>
HashTable<TKey, TData>::~HashTable()
{
	for (int i = 0; i < max_size; ++i)
	{
		if (recs[i] == pMark) recs[i] = nullptr;
		else if (recs[i] != nullptr) delete recs[i];
	}
	delete pMark;
}

template <class TKey, class TData>
TabRecord<TKey, TData>* HashTable<TKey, TData>::find(const TKey& key)
{
	int hs = hash(key), t = (hs + step) % max_size, c = 1;
	curr_pos = hs;

	if (recs[hs] == nullptr)
	{
		return nullptr;
	}
	if (recs[hs]->key == key && recs[hs] != pMark)
	{
		return recs[hs];
	}
	while (recs[t] != nullptr && t != hs && c < max_size)
	{
		if (recs[t]->key == key)
		{
			curr_pos = t;
			return recs[t];
		}
		if (recs[t] == nullptr)
		{
			return nullptr;
		}
		t = (t + step) % max_size;
		++c;
	}
	if (recs[curr_pos] != pMark && recs[curr_pos] != nullptr) next(curr_pos);
	return nullptr;
}

template <class TKey, class TData>
void HashTable<TKey, TData>::insert(const TKey& key,TData* _data)
{
	//сделать исендед
	if (count == max_size)
	{
		throw string("Table is full\n");
	}
	TabRecord<TKey, TData>* exist = find(key);

	if (!exist)
	{
		recs[curr_pos] = new TabRecord<TKey, TData>(key, _data);
		count++;
	}
	else
	{
		exist->data = _data;
	}
}

template <class TKey, class TData>
void HashTable<TKey, TData>::remove(const TKey& key)
{
	//СДЕЛАТЬ  исемпти
	if (count == 0)
	{
		throw string("Table is empty\n");
	}
	TabRecord<TKey, TData>* exist = find(key);

	if (!exist)
	{
		throw string("Wrong key\n");
	}
	else
	{
		count--;
		delete recs[curr_pos]; recs[curr_pos] = pMark;
	}
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* HashTable<TKey, TData>::operator[](const TKey& _key) {
	return find(_key);
}



template <class TKey, class TData>
void HashTable<TKey, TData>::next(int pos)
{
	if (count == max_size) curr_pos = 0;
	int new_pos = (pos + step % max_size);
	while (new_pos != pos && (recs[new_pos] != pMark && recs[new_pos] != nullptr))
	{
		new_pos = (new_pos + step) % max_size;
	}
	curr_pos = new_pos;
}
#endif
