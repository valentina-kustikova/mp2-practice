#ifndef SORTEDTABLE_H
#define SORTEDTABLE_H

#include "scantable.h"

template <class TKey, class TData>
class SortedTable : public ScanTable<TKey, TData> {
private:
	void sort();
	int partition(int low, int high);
	void quick_sort(int low, int high);

public:
	SortedTable(int _max_size = DEFAULT_SIZE);
	SortedTable(const ScanTable<TKey, TData>& st);
	SortedTable(const SortedTable<TKey, TData>& srt);

	TabRecord<TKey, TData>* find(const TKey& key);
	TabRecord<TKey, TData>* operator[](const TKey& _key);
	void insert(const TKey& _key, TData* _data);
	void remove(const TKey& _key);

	friend std::ostream& operator<<(std::ostream& out, const SortedTable& table) {
		out << "Table size: " << table.count << endl;
		for (int i = 0; i < table.count; i++) {
			if (table.recs[i]) {
				out << "(" << table.recs[i]->key << ", " << *table.recs[i]->data << "); " << endl;
			}
		}
		return out;
	}
};


template <class TKey, class TData>
void SortedTable<TKey, TData>::sort() {
	quick_sort(0, count - 1);
}

template <class TKey, class TData>
int SortedTable<TKey, TData>::partition(int low, int high) {
	TKey pivot = recs[high]->key;
	int i = low - 1;

	for (int j = low; j <= high - 1; ++j) {
		if (recs[j]->key < pivot) {
			++i;
			std::swap(recs[i], recs[j]);
		}
	}
	std::swap(recs[i + 1], recs[high]);
	return (i + 1);
}

template <class TKey, class TData>
void SortedTable<TKey, TData>::quick_sort(int low, int high) {
	if (low < high) {
		int pi = partition(low, high);

		quick_sort(low, pi - 1);
		quick_sort(pi + 1, high);
	}
}


template <class TKey, class TData>
SortedTable<TKey, TData>::SortedTable(int _max_size) : ScanTable(_max_size) {}

template <class TKey, class TData>
SortedTable<TKey, TData>::SortedTable(const ScanTable<TKey, TData>& st) : ScanTable(st) {
	sort();
}

template <class TKey, class TData>
SortedTable<TKey, TData>::SortedTable(const SortedTable<TKey, TData>& srt) {
	count = srt.count;
	max_size = srt.max_size;
	curr_pos = srt.max_size;

	recs = new TabRecord<TKey, TData>* [max_size];
	for (int i = 0; i < count; i++) {
		recs[i] = new TabRecord<TKey, TData>(*srt.recs[i]);
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
void SortedTable<TKey, TData>::insert(const TKey& _key, TData* _data) {
	if (full()) {
		std::string exp = "ERROR: Table is full.";
		throw exp;
	}

	if (find(_key) == nullptr) {
		for (int i = count - 1; i >= curr_pos; i--) {
			recs[i + 1] = recs[i];
		}
		recs[curr_pos + 1] = new TabRecord<TKey, TData>(_key, _data);
		count++;
	}
}

template <class TKey, class TData>
void SortedTable<TKey, TData>::remove(const TKey& _key) {
	if (empty()) {
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
