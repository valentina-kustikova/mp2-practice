#ifndef __ARRAY_HASH_TABLE_H__
#define __ARRAY_HASH_TABLE_H__

#include "tab_record.h"
#include "table.h"
#include "hash_table.h"

template <typename TKey, typename TData>
class ArrayHashTable : public HashTable<TKey, TData> {
private:
	TabRecord<TKey, TData>** recs;
	TabRecord<TKey, TData>* pMark;
	int freePos;
	int hashStep;
	int GetNextPos(int h_val);
public:
	ArrayHashTable(int max_size, int step);
	ArrayHashTable(const ArrayHashTable<TKey, TData>& t);
	~ArrayHashTable();
	ArrayHashTable<TKey, TData>* Search(const TKey _key);
	void Insert(TKey _key, TData* _data);
	void Remove(TKey _key);
	void Reset();
	void Next();
	bool IsEnded()const;
};

template <typename TKey, typename TData>
int ArrayHashTable<TKey, TData>::GetNextPos(int h_val) {
	return (h_val + hashStep) % maxSize;
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(int max_size, int step) {
	count = 0;
	maxSize = max_size;
	currPos = -1;
	hashStep = step;
	recs = new TabRecord<TKey, TData>*[max_size];
	pMark = new TabRecord<TKey, TData>();
	freePos = -1;
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(const ArrayHashTable<TKey, TData>& t) {
	freePos = t.freePos;
	hashStep = t.hashStep;
	count = t.count;
	maxSize = t.maxSize;
	currPos = t.currPos;
	records = new TabRecord<TKey, TData>*[maxSize];
	pMark = new TabRecord<TKey, TData>();
	for (int i = 0; i < maxSize; ++i) {
		recs[i] = new TabRecord<TKey, TData>(t.recs[i]);
	}
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::~ArrayHashTable() {
	if (!recs)
		return;
	for (int i = 0; i < maxSize; ++i) {
		if (recs[i] == pMark) {
			delete recs[i];
		}
	}
	delete recs;
	delete pMark;
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>* ArrayHashTable<TKey, TData>::Search(const TKey _key) {
	TabRecord<TKey, TData>* res = nullptr;
	currPos = hashFunc(_key);
	freePos = -1;
	for (int i = 0; i < maxSIze; i++) {
		if (recs[hash_value] == nullptr) {
			freePos = hash_value;
			break;
		}
		else if (recs[hash_value] == pMark) {
			if (freePos == -1)
				freePos = hash_value;
		}
		else if (recs[hash_value]->key == _key) {
			res = recs[hash_value];
			break;
		}
	}
	hash_value = GetNextPos(hash_value);
	currPos = hash_value;
	return res;
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Insert(TKey _key, TData* _data) {
	if (IsFull())
		throw exception("table if full");
	Search(_key);
	if (freePos == -1)
		throw exception("no places to insert");
	currPos = freePos;
	recs[currPos] = new TabRecord<TKey, TData>(_key, _data);
	count++;
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Remove(TKey _key) {
	if (IsEmpty())
		return;
	if (Search(_key) == nullptr)
		throw exception("no such records");
	delete recs[currPos];
	recs[currPos] = pMark;
	count--;
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Reset() {
	currPos = -1;
	while (!IsEnded()) {
		if (recs[currPos] != nullptr && recs[currPos] != pMark)
			break;
		currPos++;
	}
	return IsEnded();
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Next() {
	if (IsEnded())
		throw exception("end of the table");
	while (!IsEnded()) {
		if (recs[currPos] != nullptr && recs[currPos] != pMark)
			break;
		currPos++;
	}
}

template <typename TKey, typename TData>
bool ArrayHashTable<TKey, TData>::IsEnded() const {
	return hashStep = maxSize - 1;
}

#endif