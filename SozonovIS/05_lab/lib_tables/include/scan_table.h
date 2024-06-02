#ifndef __SCAN_TABLE_H__
#define __SCAN_TABLE_H__

#include "tab_record.h"
#include "table.h"

#include <iostream>

using namespace std;

template <typename TKey, typename TData>
class ScanTable : public Table<TKey, TData> {
protected:
	TabRecord<TKey, TData>** recs;
public:
	ScanTable(int max_size);
	ScanTable(const ScanTable<TKey, TData>& table);
	~ScanTable();
	TabRecord<TKey, TData>* GetCurrent() const override;
	TabRecord<TKey, TData>* Search(TKey _key) override;
	void Insert(TKey _key, TData* _data) override;
	void Remove(TKey _key) override;
	friend ostream& operator<<(ostream& out, const ScanTable<TKey, TData>& table) {
		if (table.IsEmpty()) {
			out << "table is empty" << endl;
			return out;
		}
		for (int i = 0; i < table.count; i++) {
			if (table.recs[i] != nullptr)
				cout << *table.recs[i] << endl;
		}
		return out;
	}
};

template <typename TKey, typename TData>
ScanTable<TKey, TData>::ScanTable(int max_size) : Table<TKey, TData>(max_size) {
	recs = new TabRecord<TKey, TData>*[max_size];
}

template <typename TKey, typename TData>
ScanTable<TKey, TData>::ScanTable(const ScanTable<TKey, TData>& table) : Table<TKey, TData>(table.maxSize) {
	recs = new TabRecord<TData, TKey>*[maxSize];
	for (int i = 0; i < maxSize; i++) {
		recs[i] = new TabRecord<TData, TKey>(table.recs[i]->key, table.recs[i]->data);
	}
}

template <typename TKey, typename TData>
ScanTable<TKey, TData>::~ScanTable() {
	if (!IsEmpty()) {
		for (int i = 0; i < count; i++)
			delete recs[i];
	}
	delete[] recs;
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::GetCurrent() const {
	if (IsEmpty())
		throw exception("table is empty");
	return recs[currPos];
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::Search(TKey _key) {
	if (IsEmpty())
		return nullptr;
	for (int i = 0; i < count; i++)
		if (recs[i]->key == _key) {
			currPos = i;
			return recs[i];
		}
	return nullptr;
}

template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Insert(TKey _key, TData* _data) {
	if (IsFull())
		throw exception("table is full");
	if (Search(_key) != nullptr)
		throw exception("record with this key already existed");
	recs[count++] = new TabRecord<TKey, TData>(_key, _data);
}

template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Remove(TKey _key) {
	if (IsEmpty())
		throw exception("table is empty");
	if (Search(_key) == nullptr)
		throw exception("no such records");
	delete recs[currPos];
	recs[currPos] = recs[--count];
}

#endif 