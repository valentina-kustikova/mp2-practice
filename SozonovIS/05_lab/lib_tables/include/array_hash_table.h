#ifndef __ARRAY_HASH_TABLE_H__
#define __ARRAY_HASH_TABLE_H__

#include "tab_record.h"
#include "table.h"
#include "hash_table.h"

#include <iostream>

using namespace std;

template <typename TKey, typename TData>
class ArrayHashTable : public HashTable<TKey, TData> {
private:
	TabRecord<TKey, TData>** recs;
	TabRecord<TKey, TData>* pMark;
	int freePos;
	int hashStep;
	int GetNextPos(int hashValue) const;
public:
	ArrayHashTable(int max_size, int step);
	ArrayHashTable(const ArrayHashTable<TKey, TData>& table);
	~ArrayHashTable();
	TabRecord<TKey, TData>* GetCurrent() const;
	TabRecord<TKey, TData>* Search(TKey _key);
	void Insert(TKey _key, TData* _data);
	void Remove(TKey _key);
	void Reset() noexcept;
	void Next();
	friend ostream& operator<<(ostream& out, const ArrayHashTable<TKey, TData>& table) {
		if (table.IsEmpty()) {
			out << "table is empty" << endl;
			return out;
		}
		for (int i = 0; i < table.maxSize; i++) {
			if (table.recs[i] != nullptr && table.recs[i] != table.pMark)
				cout << *table.recs[i] << endl;
		}
		return out;
	}
};

template <typename TKey, typename TData>
int ArrayHashTable<TKey, TData>::GetNextPos(int hashValue) const {
	return (hashValue + hashStep) % maxSize;
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(int max_size, int step) : HashTable<TKey, TData>(max_size) {
	count = 0;
	maxSize = max_size;
	currPos = 0;
	recs = new TabRecord<TKey, TData>*[max_size];
	for (int i = 0; i < max_size; i++)
		recs[i] = nullptr;
	pMark = new TabRecord<TKey, TData>();
	freePos = -1;
	hashStep = step;
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(const ArrayHashTable<TKey, TData>& table) :
	ArrayHashTable<TKey, TData>(table.maxSize, table.hashStep) {
	freePos = table.freePos;
	hashStep = table.hashStep;
	recs = new TabRecord<TKey, TData>*[maxSize];
	pMark = new TabRecord<TKey, TData>();
	for (int i = 0; i < maxSize; i++) {
		if (table.recs[i] == nullptr)
			recs[i] = nullptr
		else if (table.recs[i] == table.pMark)
			recs[i] = pMark;
		else
			recs[i] = new TabRecord<TKey, TData>(table.recs[i]->key, table.recs[i]->data);
	}

}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::~ArrayHashTable() {
	for (int i = 0; i < maxSize; i++) {
		if (recs[i] == pMark)
			recs[i] = nullptr;
		else if (recs[i] != nullptr)
			delete recs[i];
	}
	delete[] recs;
	delete pMark;
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::GetCurrent() const {
	if (IsEmpty())
		throw exception("table is empty");
	return recs[currPos];
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::Search(TKey _key) {
	TabRecord<TKey, TData>* res = nullptr;
	currPos = hashFunc(_key);
	freePos = -1;
	for (int i = 0; i < count; i++) {
		if (recs[currPos] == nullptr) {
			if (freePos == -1)
				freePos = currPos;
			break;
		}
		else if (recs[currPos] == pMark) {
			if (freePos == -1)
				freePos = currPos;
		}
		else if (recs[currPos]->key == _key) {
			res = recs[currPos];
			break;
		}
		currPos = GetNextPos(currPos);
	}
	return res;
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Insert(TKey _key, TData* _data) {
	if (IsFull())
		throw exception("table is full");
	if (Search(_key) != nullptr)
		throw exception("record with this key already existed");
	if (freePos != -1)
		currPos = freePos;
	recs[currPos] = new TabRecord<TKey, TData>(_key, _data);
	count++;
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Remove(TKey _key) {
	if (IsEmpty())
		throw exception("table is empty");
	if (Search(_key) == nullptr)
		throw exception("no such records");
	delete recs[currPos];
	recs[currPos] = pMark;
	count--;
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Reset() noexcept {
	currPos = 0;
	while (!IsEnded()) {
		if (recs[currPos] == nullptr && recs[currPos] == pMark)
			currPos++;
	}
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Next() {
	if (IsEnded())
		throw exception("end of the table");
	currPos++;
	while (!IsEnded()) {
		if (recs[currPos] == nullptr && recs[currPos] == pMark)
			currPos++;
	}
}

#endif