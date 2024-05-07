#ifndef ARRAYHASHTABLE_H
#define ARRAYHASHTABLE_H

#include "hashtable.h"
#include "xxh3.h"

#include <algorithm>

template <class TKey, class TData>
class ArrayHashTable : public HashTable<TKey, TData> {
protected:
	size_t hash_step;
	TabRecord<TKey, TData>** recs;
	TabRecord<TKey, TData>* pMark;
	int free_pos_ind;

	size_t hash_func(const TKey& key);
	size_t get_next_pos(size_t ind);

	void coprime_check(size_t _max_size, size_t _hash_step);
public:
	ArrayHashTable(size_t _max_size, size_t _hash_step);
	ArrayHashTable(const ArrayHashTable<TKey, TData>& aht);
	virtual ~ArrayHashTable();

	TabRecord<TKey, TData>* Find(const TKey& key);
	TabRecord<TKey, TData>* operator[](const TKey& _key);
	void Insert(const TKey& _key, const TData* _data);
	void Remove(const TKey& _key);

	bool Reset();
	bool Next();

	TKey GetKey() const;
	TData* GetData() const;
};


template <class TKey, class TData>
size_t ArrayHashTable<TKey, TData>::hash_func(const TKey& key) {
	return (XXH3_64bits(key.c_str(), key.size())) % max_size;
}

template <class TKey, class TData>
size_t ArrayHashTable<TKey, TData>::get_next_pos(size_t ind) {
	return (ind + hash_step) % max_size;
}

template <class TKey, class TData>
void ArrayHashTable<TKey, TData>::coprime_check(size_t _max_size, size_t _hash_step) {
	if (_max_size <= 0) {
		std::string exp = "ERROR: Table max_size cant be less or equal than 0.";
		throw exp;
	}

	if (_hash_step <= 0) {
		std::string exp = "ERROR: Table hash_step cant be less or equal than 0.";
		throw exp;
	}

	if (__gcd(_hash_step, _max_size) != 1) {
		std::string exp = "ERROR: max_size and hash_step must be coprime numbers.";
		throw exp;
	}
}


template <class TKey, class TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(size_t _max_size, size_t _hash_step) : HashTable(_max_size) {
	coprime_check(_max_size, _hash_step);

	recs = new TabRecord<TKey, TData>*[max_size];
	hash_step = _hash_step;
	pMark = new TabRecord<TKey, TData>();
	free_pos_ind = -1;

	for (int i = 0; i < max_size; i++) recs[i] = nullptr;
}

template <class TKey, class TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(const ArrayHashTable<TKey, TData>& aht) {
	max_size = aht.max_size;
	hash_step = aht.hash_step;
	curr_pos = aht.curr_pos;
	free_pos_ind = aht.free_pos_ind;

	recs = new TabRecord<TKey, TData>*[max_size];
	pMark = new TabRecord<TKey, TData>*();

	for (int i = 0; i < max_size; i++) {
		TabRecord<TKey, TData>* tmp = aht.recs[i];
		
		if		(tmp == nullptr)	recs[i] = tmp;
		else if (tmp == aht.pMark)	recs[i] = pMark;
		else recs[i] = new TabRecord<TKey, TData>(tmp);
	}
}

template <class TKey, class TData>
ArrayHashTable<TKey, TData>::~ArrayHashTable() {
	for (int i = 0; i < max_size; i++) {
		if (recs[i] != nullptr && recs[i] != pMark) delete recs[i];
	}
	if (recs) delete recs;
	if (pMark) delete pMark;
}


template <class TKey, class TData>
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::Find(const TKey& key) {
	size_t idx = hash_func(key);
	for (int i = 0; i < max_size; i++) {
		if (recs[idx] == nullptr)
			return nullptr;

		else if (recs[idx] == pMark && free_pos_ind == -1)
			free_pos_ind = idx;

		else if (recs[idx]->GetKey() == key)
			return recs[idx];

		idx = get_next_pos(idx);
	}

	return nullptr;
}

template <class TKey, class TData>
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::operator[](const TKey& _key) {
	return Find(_key);
}

template <class TKey, class TData>
void ArrayHashTable<TKey, TData>::Insert(const TKey& _key, const TData* _data) {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
void ArrayHashTable<TKey, TData>::Remove(const TKey& _key) {

	throw "NOT IMPLEMENTED";
}


template <class TKey, class TData>
bool ArrayHashTable<TKey, TData>::Reset() {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
bool ArrayHashTable<TKey, TData>::Next() {

	throw "NOT IMPLEMENTED";
}


template <class TKey, class TData>
TKey ArrayHashTable<TKey, TData>::GetKey() const {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
TData* ArrayHashTable<TKey, TData>::GetData() const {

	throw "NOT IMPLEMENTED";
}

#endif // !ARRAYHASHTABLE_H
