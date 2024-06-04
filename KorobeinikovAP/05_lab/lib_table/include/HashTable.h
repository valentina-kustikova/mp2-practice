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
	int free_pos;

	virtual size_t hash(const TKey& key) const;
	void next(int pos);
public:
	HashTable<TKey, TData>(int _max_size = 100, size_t _step = 13);
	HashTable<TKey, TData>(const HashTable& table);
	virtual ~HashTable<TKey, TData>();

	TabRecord<TKey, TData>* find(const TKey& key);
	virtual void insert(const TKey& _key, TData* _data);
	virtual void remove(const TKey& key);

	TabRecord<TKey, TData>* operator[](const TKey& _key);

	
	friend ostream& operator<<(ostream& os, const HashTable& table)
	{	
		os << "HashTable count: " << table.count << endl;
		string str1 = string(32, '-'), str2 = string(62, '-');
		os << '+' << str1 << '+' << str2 << '+' << endl;
		for (int i = 0; i < table.max_size; ++i)
		{
			if (table.recs[i] && table.recs[i] != table.pMark) {
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
HashTable<TKey, TData>::HashTable(int _max_size, size_t _step)
{
	if (_max_size <= 0)
	{
		throw "Size can't is negative";
	}
	max_size = _max_size;
	count = 0;
	curr_pos = 0;
	free_pos = 0;
	
	int flag = 0;
	for (int i = 2; i <= _max_size; i++) 
	{
		if ((_max_size % i == 0) && (step % i == 0)) {
			flag = 0;
			break;
		}
		else if (i == _max_size) flag = 1;
	}
	if (flag == 1) {
		throw "step is bad";
	}
	else step = _step;
	
	recs = new TabRecord<TKey, TData>* [max_size];
	for (int i = 0; i < _max_size; ++i) recs[i] = nullptr;
}

template <class TKey, class TData>
HashTable<TKey, TData>::HashTable(const HashTable& table)
{
	this->max_size = table.max_size;
	this->step = table.step;
	this->count = table.count;
	free_pos = table.free_pos;
	curr_pos = table.curr_pos;
	pMark = new TabRecord<TKey, TData>();

	recs = new TabRecord<TKey, TData>* [max_size];
	for (int i = 0; i < max_size; ++i)
	{
		if (table.recs[i])
		{
			recs[i] = new TabRecord<TKey, TData>(*table.recs[i]);
		}
		else {
			recs[i] = nullptr;
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
	free_pos = hs;

	if (recs[hs] == nullptr)
	{
		free_pos = hs;
		return nullptr;
	}
	if (recs[hs]->key == key && recs[hs] != pMark)
	{
		curr_pos = hs;
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
			free_pos = t;
			return nullptr;
		}
		t = (t + step) % max_size;
		++c;
	}
	if (recs[free_pos] != pMark && recs[free_pos] != nullptr) {
		next(free_pos);
	}
	return nullptr;
}

template <class TKey, class TData>
void HashTable<TKey, TData>::insert(const TKey& key,TData* _data)
{
	if (ended())
	{
		throw "Table is full\n";
	}
	TabRecord<TKey, TData>* tmp = find(key);

	if (!tmp)
	{
		recs[free_pos] = new TabRecord<TKey, TData>(key, _data);
		count++;
	}
	else
	{		
		throw "Kiy not unique: not good";
		//tmp->data = _data; // throw
	}
}

template <class TKey, class TData>
void HashTable<TKey, TData>::remove(const TKey& key)
{
	if (empty())
	{
		throw string("Table is empty\n");
	}
	TabRecord<TKey, TData>* exist = find(key);

	if (!exist)
	{
		throw string("Wrong key\n");
	}
	count--;
	delete recs[curr_pos]; recs[curr_pos] = pMark;
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* HashTable<TKey, TData>::operator[](const TKey& _key) {
	return find(_key);
}



template <class TKey, class TData>
void HashTable<TKey, TData>::next(int pos)
{
	if (count == max_size) free_pos = 0;
	int new_pos = (pos + step % max_size);
	while (new_pos != pos && (recs[new_pos] != pMark && recs[new_pos] != nullptr))
	{
		new_pos = (new_pos + step) % max_size;
	}
	free_pos = new_pos;
}

#endif
