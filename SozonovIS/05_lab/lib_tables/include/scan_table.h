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
	virtual TabRecord<TKey, TData>* Search(Tkey _key);
	virtual void Insert(TKey _key, TData* _data);
	virtual void Remove(TKey _key);
};

template <typename TKey, typename TData>
ScanTable<TKey, TData>::ScanTable(int max_size) {
	if (max_size <= 0)
		throw exception("negative or zero max size");
	count = 0;
	maxSize = max_size;
	currPos = -1;
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
	for (int i = 0; i < maxSize; i++) {
		delete recs[i];
	}
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::Search(Tkey _key) {
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