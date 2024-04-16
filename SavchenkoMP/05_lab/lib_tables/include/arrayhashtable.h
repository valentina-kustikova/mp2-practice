#ifndef ARRAYHASHTABLE_H
#define ARRAYHASHTABLE_H

#include "hashtable.h"
#include "xxh3.h"

template <class TKey, class TData>
class ArrayHashTable : public HashTable<TKey, TData> {
protected:
	size_t hash_step;
	TabRecord<TKey, TData>** recs;
	TabRecord<TKey, TData>* pMark;
	int free_pos_ind;

	size_t get_next_pos(size_t ind);

public:
	ArrayHashTable(size_t _max_size, size_t _hash_step);
	ArrayHashTable(const ArrayHashTable<TKey, TData>& aht);
	virtual ~ArrayHashTable();

	void Insert(const TKey& _key, const TData* _data);
	void Remove(const TKey& _key);
	TabRecord<TKey, TData>* Find(const TKey& key);

	bool Reset();
	bool Next();

	TKey GetKey() const;
	TData* GetData() const;
};


template <class TKey, class TData>
size_t ArrayHashTable<TKey, TData>::get_next_pos(size_t ind) {

	throw "NOT IMPLEMENTED";
}


template <class TKey, class TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(size_t _max_size, size_t _hash_step) {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(const ArrayHashTable<TKey, TData>& aht) {

	throw "NOT IMPLEMENTED";
}

template <class TKey, class TData>
ArrayHashTable<TKey, TData>::~ArrayHashTable() {

	throw "NOT IMPLEMENTED";
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
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::Find(const TKey& key) {

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
