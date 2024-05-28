#ifndef  ARRAYSORTTABLE_H
#define ARRAYSORTTABLE_H

#include "ArrayScanTable.h"

enum SortMethod { SIMPLE, SELECT, INSERT, BUBBLE,QUICK,MERGE };

template<typename TKey, typename TData> class TArraySortTable : public TArrayScanTable<TKey, TData> {
protected:
	void SortData();
public:
	TArraySortTable(int max_size_ = 25);
	TArraySortTable(const TArrayScanTable& ScanTable);
	void Insert(TKey Key, const Data<TData>* data_)override;
	TTabRecord<TKey, TData>* Find(TKey Key)override;
	void Remove(TKey key)override;

	void SetSortMethod(SortMethod n = MERGE) { number = n; }
	SortMethod GetSortMethod()const { return number; }
protected:
	SortMethod number; 
	void SimpleSort();
	void SelectSort();
	void InsertSort();
	void BubbleSort();
	void MergeSort(int _first, int _last);
	void Merge(int _first, int _mid, int _last);
	void QuickSort(int _first, int _last);
	void QuickSplit(int& i, int& j, TTabRecord<TKey, TData>* _mid);
};

template<typename TKey,typename TData>
TArraySortTable<TKey,TData>::TArraySortTable(int max_size_):TArrayScanTable<TKey,TData>(max_size_){}

template<typename TKey,typename TData>
TArraySortTable<TKey, TData>::TArraySortTable(const TArrayScanTable<TKey,TData>& ScanTable): TArrayScanTable<TKey, TData>(ScanTable) {
	SortData();
}

template<typename TKey, typename TData>
void TArraySortTable<TKey,TData>::Insert(TKey Key, const Data<TData>* data_) {
	if(IsFull()){
		throw "table is full!";
	}
	TTabRecord<TKey,TData>* search = Find(Key);
	if (search != nullptr)throw "Key already exist!";

	for (int i = count; i > curr_pos; i--) {
		records[i] = records[i-1];
	}
	records[curr_pos] = new TTabRecord<TKey, TData>(Key, data_);
	count++;
	reset();
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
			search = records[i2];
		}
		else if (Key > records[mid]->key) {
			i1 = mid + 1;
		}
		else {
			i2 = mid - 1;
		}
	}
	curr_pos = i1;
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
		reset();
	}
}

template<typename TKey, typename TData>
void TArraySortTable<TKey, TData>::SortData() {
	SetSortMethod();
	switch (number) {
		case SIMPLE:
		{
			SimpleSort();
			break;
		}

		case SELECT:
		{
			SelectSort();
			break;
		}

		case INSERT:
		{
			InsertSort();
			break;
		}

		case BUBBLE:
		{
			BubbleSort();
			break;
		}
		case QUICK:
		{
			QuickSort(0, count - 1);
			break;
		}
		case MERGE:
		{
			MergeSort(0, count-1);
			break;
		}
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

template<typename TKey, typename TData>
void TArraySortTable<TKey, TData>::QuickSort(int _first, int _last) {
	int i = _first;
	int j = _last;
	int mid = (_last + _first) / 2;

	QuickSplit(i, j, records[mid]);

	if (j > _first)
		QuickSort(_first, j);
	if (i < _last)
		QuickSort(i, _last);
}

template<typename TKey, class TData>
void TArraySortTable<TKey, TData>::QuickSplit(int& i, int& j, TTabRecord<TKey, TData>* _mid)
{
	do
	{
		while (*records[i] < *_mid && records[i] != nullptr)i++;
		while (*records[j] > *_mid && records[j] != nullptr)j--;

		if (i <= j)
		{
			std::swap<TTabRecord<TKey, TData>*>(records[i], records[j]);
			i++;
			j--;
		}
	} while (i <= j);
};

template<typename TKey, class TData>
void TArraySortTable<TKey, TData>::MergeSort(int _first, int _last)
{
	if (_first >= _last)
		return;

	int mid = (_last + _first) / 2;
	MergeSort(_first, mid);
	MergeSort(mid + 1, _last);
	Merge(_first, mid, _last);
};

template<typename TKey, class TData>
void TArraySortTable<TKey, TData>::Merge(int _first, int _mid, int _last)
{
	int i = _first;
	int j = _mid + 1;
	TTabRecord<TKey, TData>** pBuff = new TTabRecord<TKey, TData>* [_last - _first + 1];

	for (int ind = 0; ind < _last - _first + 1; ind++) {
		if ((j > _last) || ((i <= _mid) && (*records[i] < *records[j])
			&& (records[i] != nullptr && records[j] != nullptr))) {
			pBuff[ind] = records[i++];
		}
		else {
			pBuff[ind] = records[j++];
		}
	}

	for (int ind = _first; ind < _last + 1; ind++) {
		{
			records[ind] = pBuff[ind - _first];
			pBuff[ind - _first] = nullptr;
		}
	}

	delete[] pBuff;
};
#endif