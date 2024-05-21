#ifndef SORTEDTABLE_H
#define SORTEDTABLE_H

#include "scantable.h"
#include "sortings.h"

template <class TKey, class TData>
class SortedTable : public ScanTable<TKey, TData> {
private:
	void sort();
	int partition(int start, int pivot);
	void quick_sort(int start, int end);

	void swap(TabRecord<TKey, TData>& a, TabRecord<TKey, TData>& b);
	bool is_sorted();

public:
	SortedTable(int _max_size);
	SortedTable(const ScanTable<TKey, TData>* st);
	SortedTable(const SortedTable<TKey, TData>& srt);

	TabRecord<TKey, TData>* find(const TKey& key);
	TabRecord<TKey, TData>* operator[](const TKey& _key);
	void insert(const TKey& _key, const TData* _data);
	void remove(const TKey& _key);
};


template <class TKey, class TData>
void SortedTable<TKey, TData>::sort() {
	quick_sort(0, count);
}

template <class TKey, class TData>
int SortedTable<TKey, TData>::partition(int start, int pivot) {
	int i = start;
	while (i < pivot) {
		if (recs[i]->key > recs[pivot]->key && i == pivot - 1) {
			swap(recs[i], recs[pivot]);
			pivot--;
		}

		else if (recs[i]->key > recs[pivot]->key) {
			swap(recs[pivot - 1], recs[pivot]);
			swap(recs[i], recs[pivot]);
			i--;
		}

		else i++
	}
	return pivot
}

template <class TKey, class TData>
void SortedTable<TKey, TData>::quick_sort(int start, int end) {
	if (start < end)
	{
		int pivot = partition(start, end);

		quick_sort(start, pivot - 1);
		quick_sort(pivot + 1, end);
	}
}


template <class TKey, class TData>
void SortedTable<TKey, TData>::swap(TabRecord<TKey, TData>& a, TabRecord<TKey, TData>& b) {
	srt::swap(a, b);
	//TabRecord<TKey, TData> tmp = a;
	//a = b;
	//b = tmp;
}

template <class TKey, class TData>
bool SortedTable<TKey, TData>::is_sorted() {
	bool flag = true;
	for (int i = 0; i < max_size - 1; i++) {
		if (recs[i]->key > recs[i + 1]->key) {
			flag = false;
			break;
		}
	}
	return flag;
}


template <class TKey, class TData>
SortedTable<TKey, TData>::SortedTable(int _max_size) : ScanTable(_max_size) {}

template <class TKey, class TData>
SortedTable<TKey, TData>::SortedTable(const ScanTable<TKey, TData>* st) : ScanTable(*st) {
	if (!is_sorted()) sort();
}

template <class TKey, class TData>
SortedTable<TKey, TData>::SortedTable(const SortedTable<TKey, TData>& srt) {
	count = srt.count;
	max_size = srt.max_size;
	curr_pos = srt.max_size;

	recs = new TabRecord<TKey, TData>* [max_size];
	for (int i = 0; i < count; i++) {
		recs[i] = new TabRecord<TKey, TData>(*recs[i]);
	}
}


template <class TKey, class TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::find(const TKey& key) {
	int left = 0, right = count - 1;
	TabRecord<TKey, TData>* search = nullptr;

	while (left <= right) {
		int mid = (right + left) / 2;

		if (recs[mid]->key == key) {
			search = recs[mid];
			right = mid;
			left = mid + 1;
		}
		else if (recs[mid]->key < key) left = mid + 1;
		else right = mid - 1;
	}
	curr_pos = right;
	return search;
}

template <class TKey, class TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::operator[](const TKey& _key) {
	return find(_key);
}

template <class TKey, class TData>
void SortedTable<TKey, TData>::insert(const TKey& _key, const TData* _data) {
	if (IsFull()) {
		std::string exp = "ERROR: Table is full.";
		throw exp;
	}

	find(_key);
	for (int i = count - 1; i >= currpos; i--) {
		recs[i + 1] = recs[i];
	}
	recs[curr_pos] = new TabRecord<TKey, TData>(_key, _data);
}

template <class TKey, class TData>
void SortedTable<TKey, TData>::remove(const TKey& _key) {
	if (IsEmpty()) {
		std::string exp = "ERROR: Table is empty.";
		throw exp;
	}

	TabRecord<TKey, TData>* rec = find(_key);
	if (rec == nullptr) {
		std::string exp = "ERROR: Key nod found.";
		throw exp;
	}
	else {
		delete rec;
		for (int i = curr_pos; i < count - 1; i++) {
			recs[i] = recs[i + 1];
		}
		count--;
	}
}

#endif // !SORTEDTABLE_H
