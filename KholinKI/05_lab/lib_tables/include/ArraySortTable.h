#ifndef  ARRAYSORTTABLE_H
#define ARRAYSORTTABLE_H

#include "ArrayScanTable.h"


template<typename TKey, typename TData> class TArraySortTable : public TArrayScanTable<TKey, TData> {

public:
	TArraySortTable(int max_size_);
	void Insert(TKey Key, const Data<TData>* data_)override;
	TTabRecord<TKey, TData>* Find(TKey Key)override;
	void Remove(TKey key)override;

	void SimpleSort();
	void SelectSort();
	void InsertSort();
	void BubbleSort();
	//void MergeSort();
	//void QuickSort();
};

template<typename TKey,typename TData>
TArraySortTable<TKey,TData>::TArraySortTable(int max_size_):TArrayScanTable<TKey,TData>(max_size_){}

template<typename TKey, typename TData>
void TArraySortTable<TKey,TData>::Insert(TKey Key, const Data<TData>* data_) {
	if(IsFull()){
		throw "table is full!";
	}
	Find(Key);

	for (int i = count - 1; i >= curr_pos; i--) {
		records[i + 1] = records[i];
	}
	records[curr_pos] = new TTabRecord<TKey, TData>(Key, data_);
	count++;
}

template<typename TKey, typename TData>
TTabRecord<TKey, TData>* TArraySortTable<TKey, TData>::Find(TKey Key) {
	TTabRecord<TKey, TData>* search = nullptr;

	if (IsEmpty()) {
		return search;
	}

	int i1 = 0;
	int i2 = count-1;

	while (i1 <= i2) {
		int mid = (i1 + i2) / 2;
		if (records[mid]->key == Key) {
			i1 = mid + 1;
			i2 = mid;
		}
		else if (Key > records[mid]->key) {
			i1 = mid + 1;
		}
		else {
			i2 = mid - 1;
		}
	}
	curr_pos = i2;
	if (curr_pos == -1) {
		curr_pos++;
	}
	return search;
}

template<typename TKey, typename TData>
void TArraySortTable<TKey, TData>::Remove(TKey key) {
	if (IsEmpty()) {
		return;
	}

	TTabRecord<TKey, TData>* search = Find(key);
	if (search == nullptr) {
		throw "Record not found!";
	}
	else {
		delete records[curr_pos];
		for (int i = curr_pos; i < count; i++) {
			records[i] = records[i+1];
		}
		count--;
	}
}

template<typename TKey, typename TData>
void TArraySortTable<TKey, TData>::SimpleSort() {
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (records[j]->key > records[i]->key) {
				TTabRecord<TKey, TData> tmp = *records[i];
				*records[i] = *records[j];
				*records[j] = tmp;
			}
		}
	}
}

template<typename TKey, typename TData>
void TArraySortTable<TKey, TData>::SelectSort() {
	for (int i = 0; i < count; i++) {
		int min = i;
		for (int j = i + 1; j < count; j++) {
			if (records[j]->key < records[i]->key) {
				min = j;
			}
		}
		TTabRecord<TKey, TData> tmp = *records[i];
		*records[i] = *records[min];
		*records[min] = tmp;
	}
}

template<typename TKey, typename TData>
void TArraySortTable<TKey, TData>::InsertSort() {
	for (int i = 1; i < count; i++) {
		TTabRecord<TKey, TData> tmp = *records[i];
		for (int j = i - 1; j >= 0 && records[j]->key > records[j+1]->key;j--) {
			*records[j+1] = *records[j];
			*records[j] = tmp;
		}
	}
}

template<typename TKey, typename TData>
void TArraySortTable<TKey, TData>::BubbleSort() {
	for (int i = 1; i < count; i++) {
		for (int j = 0; j < count - i; j++) {
			if (records[j]->key > records[j + 1]->key) {
				TTabRecord<TKey, TData> tmp = *records[j+1];
				*records[j+1] = *records[j];
				*records[j] = tmp;
			}
		}
	}
}
#endif