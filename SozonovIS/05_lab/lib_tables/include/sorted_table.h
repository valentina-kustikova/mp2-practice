#ifndef __SORTED_TABLE_H__
#define __SORTED_TABLE_H__

#include "tab_record.h"
#include "table.h"
#include "scan_table.h"

using namespace std;

template <typename TKey, typename TData>
class SortedTable : public ScanTable<TKey, TData> {
private:
	void QuickSort(TabRecord<TKey, TData>** a, int n);
public:
	SortedTable(int max_size);
	SortedTable(const ScanTable<TKey, TData>& table);
	TabRecord<TKey, TData>* GetCurrent() const override;
	TabRecord<TKey, TData>* Search(TKey _key) override;
	void Insert(TKey _key, TData* _data) override;
	void Remove(TKey _key) override;
};

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::QuickSort(TabRecord<TKey, TData>** a, int n) {
	int i = 0;
	int j = n - 1;
	TabRecord<TKey, TData>* mid = a[(i + j) / 2];
	do {
		while (a[i]->key < mid->key)
			i++;
		while (a[j]->key > mid->key)
			j--;
		if (i <= j) {
			TabRecord<TKey, TData>* tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		QuickSort(a, j + 1);
	if (i < n)
		QuickSort(a, n - 1);
}


template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(int max_size) : ScanTable<TKey, TData>(max_size) {}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(const ScanTable<TKey, TData>& table) : ScanTable<TKey, TData>(table) {
	if (IsEmpty())
		return;
	this->QuickSort(this->recs, this->count);
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::GetCurrent()const {
	if (IsEmpty())
		throw exception("table is empty");
	return recs[currPos];
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::Search(TKey _key) {
	int left = 0, right = count - 1;
	TabRecord<TKey, TData>* record = nullptr;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (recs[mid]->key == _key) {
			left = mid + 1;
			right = mid;
			record = recs[mid];
		}
		else if (recs[mid]->key > _key)
			right = mid - 1;
		else
			left = mid + 1;
	}
	currPos = right;
	return record;
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Insert(TKey _key, TData* _data) {
	if (IsFull())
		throw exception("table is full");
	if (Search(_key) != nullptr)
		return;
	for (int i = count - 1; i > currPos; i--) {
		recs[i + 1] = recs[i];
	}
	recs[++currPos] = new TabRecord<TKey, TData>(_key, _data);
	count++;
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Remove(TKey _key) {
	if (IsEmpty())
		throw exception("table is empty");
	if (Search(_key) == nullptr)
		throw exception("no such records");
	delete recs[currPos];
	for (int i = currPos; i < count - 1; i++)
		recs[i] = recs[i + 1];
	count--;
}

#endif