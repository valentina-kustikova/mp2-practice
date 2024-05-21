#ifndef ARRAYHASHTABLE_H
#define ARRAYHASHTABLE_H

#include <iostream>
#include <numeric>
#include "hashtable.h"
#include "xxh3.h"

#define DEFAULT_HASHSTEP 10

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
	ArrayHashTable(size_t _max_size = DEFAULT_SIZE, size_t _hash_step = DEFAULT_HASHSTEP);
	ArrayHashTable(const ArrayHashTable<TKey, TData>& aht);
	virtual ~ArrayHashTable();

	TabRecord<TKey, TData>* find(const TKey& key);
	TabRecord<TKey, TData>* operator[](const TKey& _key);
	void insert(const TKey& _key, TData* _data);
	void remove(const TKey& _key);

	bool reset() noexcept;
	bool next() noexcept;
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

	//if (std::gcd(_hash_step, _max_size) != 1) { // gcd NOT WORKING !?!?!??!?!
	//	std::string exp = "ERROR: max_size and hash_step must be coprime numbers.";
	//	throw exp;
	//}
}


template <class TKey, class TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(size_t _max_size, size_t _hash_step) : HashTable(_max_size) {
	coprime_check(_max_size, _hash_step);

	recs = new TabRecord<TKey, TData>* [max_size];
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

	recs = new TabRecord<TKey, TData>* [max_size];
	pMark = new TabRecord<TKey, TData>* ();

	for (int i = 0; i < max_size; i++) {
		TabRecord<TKey, TData>* tmp = aht.recs[i];

		if (tmp == nullptr)	recs[i] = tmp;
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
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::find(const TKey& key) {
	size_t idx = hash_func(key);
	for (int i = 0; i < max_size; i++) {
		if (recs[idx] == nullptr)
			return nullptr;

		else if (recs[idx] == pMark && free_pos_ind == -1)
			free_pos_ind = idx;

		else if (recs[idx]->key == key)
			return recs[idx];

		idx = get_next_pos(idx);
	}

	return nullptr;
}

template <class TKey, class TData>
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::operator[](const TKey& _key) {
	return find(_key);
}

template <class TKey, class TData>
void ArrayHashTable<TKey, TData>::insert(const TKey& _key, TData* _data) {
	if (full()) {
		std::string exp = "Error: table is full.";
		throw exp;
	}

	if (find(_key) != nullptr && free_pos_ind != -1) {
		curr_pos = free_pos_ind;
	}
	recs[curr_pos] = new TabRecord<TKey, TData>(_key, _data);
	count++;
}

template <class TKey, class TData>
void ArrayHashTable<TKey, TData>::remove(const TKey& _key) {
	TabRecord<TKey, TData>* tmp = find(_key);

	if (tmp == nullptr) {
		std::string exp = "Error: key not found";
		throw exp;
	}

	delete tmp;
	recs[curr_pos] = pMark;
	free_pos_ind = -1;
	count--;
}


template <class TKey, class TData>
bool ArrayHashTable<TKey, TData>::reset() noexcept {
	if (!empty()) {
		curr_pos = 0;
		return true;
	}
	else {
		curr_pos = -1;
		return false;
	}
}

template <class TKey, class TData>
bool ArrayHashTable<TKey, TData>::next() noexcept {
	if (curr_pos < max_size && !empty()) {
		curr_pos++;
		return true;
	}
	else return false;
}

#endif // !ARRAYHASHTABLE_H
