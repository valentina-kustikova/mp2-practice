#ifndef __SCAN_TABLE_H__
#define __SCAN_TABLE_H__

#include "tab_record.h"
#include "table.h"

using namespace std;

template <typename TKey, typename TData>
class ScanTable : public Table<TKey, TData> {
protected:
	TabRecord<TKey, TData>** recs;
public:
	ScanTable(int max_size);
	ScanTable(const ScanTable<TKey, TData>& t);
	~ScanTable();
	TabRecord<TKey, TData>* Search(TKey _key);
	void Insert(TKey _key, TData* _data);
	void Remove(TKey _key);
	friend ostream& operator<<(ostream& out, const ScanTable<TKey, TData>& t) {
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
ScanTable<TKey, TData>::ScanTable(int max_size) : Table<TKey, TData>(max_size) {
	recs = new TabRecord<TKey, TData>*[maxSize];
}

template <typename TKey, typename TData>
ScanTable<TKey, TData>::ScanTable(const ScanTable<TKey, TData>& t) {
	count = t.count;
	maxSize = t.maxSize;
	currPos = t.currPos;
	recs = new TabRecord<TData, TKey>*[maxSize];
	for (int i = 0; i < maxSize; i++) {
		recs[i] = new TabRecord<TData, TKey>(*t.recs[i]);
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
TabRecord<TKey, TData>* ScanTable<TKey, TData>::Search(TKey _key) {
	if (IsEmpty())
		return nullptr;
	for (int i = 0; i < maxSize; i++)
		if (recs[i]->key == _key) {
			currPos = i;
			return recs[i];
		}
	return nullptr;
}

template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Insert(TKey _key, TData* _data) {
	if (IsFull())
		throw exception("table if full");
	if (Search(_key) != nullptr)
		throw exception("record with this key already existed");
	recs[count++] = new TabRecord<TKey, TData>(_key, _data);
}

template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Remove(TKey _key) {
	if (IsEmpty())
		return;
	if (Search(_key) == nullptr)
		throw exception("no such records");
	delete recs[currPos];
	recs[currPos] = recs[--count];
}

#endif 