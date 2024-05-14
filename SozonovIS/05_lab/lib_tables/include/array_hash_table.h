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
	int GetNextPos(int hashValue);
public:
	ArrayHashTable(int max_size, int step);
	ArrayHashTable(const ArrayHashTable<TKey, TData>& t);
	~ArrayHashTable();
	TabRecord<TKey, TData>* Search(TKey _key);
	void Insert(TKey _key, TData* _data);
	void Remove(TKey _key);
	void Reset();
	void Next();
	friend ostream& operator<<(ostream& out, const ArrayHashTable<TKey, TData>& t) {
		if (t.IsEmpty()) {
			out << "table is empty";
			return out;
		}
		for (int i = 0; i < t.count; i++) {
			if (t.recs[i] != nullptr)
				out << "| " << table.recs[i]->key << " | " << table.recs[i]->data << " |" << endl;
		}
		return out;
	};
};

template <typename TKey, typename TData>
int ArrayHashTable<TKey, TData>::GetNextPos(int hashValue) {
	return (hashValue + hashStep) % maxSize;
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(int max_size, int step) : HashTable<TKey, TData>(max_size) {
	count = 0;
	maxSize = max_size;
	currPos = -1;
	recs = new TabRecord<TKey, TData>*[max_size];
	for (int i = 0; i < maxSize; i++)
		recs[i] = nullptr;
	pMark = new TabRecord<TKey, TData>();
	freePos = -1;
	hashStep = step;
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
	for (int i = 0; i < maxSize; ++i) {
		if (recs[i] != nullptr) {
			delete recs[i];
		}
	}
	delete[] recs;
	delete pMark;
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::Search(TKey _key) {
	TabRecord<TKey, TData>* res = nullptr;
	int hashValue = hashFunc(_key);
	currPos = hashValue;
	freePos = -1;
	for (int i = 0; i < maxSIze; i++) {
		if (recs[hashValue] == nullptr) {
			freePos = hashValue;
			break;
		}
		else if (recs[hashValue] == pMark) {
			if (freePos == -1)
				freePos = hashValue;
		}
		else if (recs[hashValue]->key == _key) {
			res = recs[hashValue];
			break;
		}
		hashValue = GetNextPos(hashValue);
		currPos = hashValue;
	}
	return res;
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Insert(TKey _key, TData* _data) {
	if (IsFull())
		throw exception("table if full");
	if (freePos == -1)
		throw exception("no places to insert");
	if (Search(_key) != nullptr)
		throw exception("record with this key already existed");
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
	currPos = 0;
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

#endif