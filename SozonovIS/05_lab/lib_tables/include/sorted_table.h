#ifndef __SORTED_TABLE_H__
#define __SORTED_TABLE_H__

#include "tab_record.h"
#include "table.h"
#include "scan_table.h"

using namespace std;

template <typename TKey, typename TData>
class SortedTable : public ScanTable<TKey, TData> {
private:
	void Sort();
	void QuickSort(TabRecord<TKey, TData>* _mid, int& n);
	void MergeSort(int& left, int& right);
	void Merge(int& left, int& mid, int& right);
public:
	SortedTable(int max_size);
	SortedTable(const ScanTable<TKey, TData>& t);
	TabRecord<TKey, TData>* Search(TKey _key);
	void Insert(TKey _key, TData* _data);
	void Remove(TKey _key);
};

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Sort() {
	int c;
	do {
		cout << "Select the sorting method: " << endl;
		cout << "1) QuickSort " << endl;
		cout << "2) MergeSort " << endl;
		cin >> c;
		if (c == 1) {
			QuickSort(recs, count);
		}
		else if (c == 2) {
			MergeSort(0, count);
		}
		else {
			cout << "Wrong value. Try again" << endl;
		}
	} while (c == 1 || c == 2);
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::QuickSort(TabRecord<TKey, TData>* a, int& n) {
	int i = 0;
	int j = n - 1;
	TabRecord<TKey, TData> mid = a[(i + j) / 2];
	do {
		while (a[i] < mid)
			i++;
		while (a[j] > mid)
			j--;
		if (i <= j) {
			TabRecord<TKey, TData> tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		QuickSort();
	if (i < n)
		QuickSort();
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::MergeSort(int& left, int& right) {
	if (left == right)
		return;
	int mid = (left + right) / 2;
	MergeSort(left, mid);
	MergeSort(mid + 1, right);
	Merge(left, mid, right);
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Merge(int& left, int& mid, int& right) {
	int i = left, j = mid + 1;
	for (int k = left; k < right; k++) {
		if ((i < mid) && (j < right))
			if (recs[i] <= recs[j])
				TabRecord<TKey, TData> ma[k] = recs[i++];
			else
				TabRecord<TKey, TData> ma[k] = recs[j++];
		else
			if (i == mid)
				ma[k] = recs[j++];
			else
				ma[k] = recs[i++];
	}
}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(int max_size) : ScanTable<TKey, TData>(max_size) {}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(const ScanTable<TKey, TData>& t) : ScanTable<TKey, TData>(t) {
	if (IsEmpty())
		return;
	this->Sort();
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
		throw exception("record with this key already existed");
	for (int i = count - 1; i >= currpos; i--) {
		resc[i++] = recs[i];
	}
	recs[++currPos] = new TabRecord<TKey, TData>(_key, _data);
	count++;
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Remove(TKey _key) {
	if (IsEmpty())
		return;
	TabRecord<TKey, TData>* record = Search(_key);
	if (record == nullptr)
		throw exception("no such records");
	delete record;
	for (int i = currpos; i < count - 1; i++)
		recs[i] = recs[i++];
	count--;
}

#endif