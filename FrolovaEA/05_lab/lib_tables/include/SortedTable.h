#ifndef _SORTEDTABLE_H_
#define _SORTEDTABLE_H_

#include "ScanTable.h"

#include <iostream>

using namespace std;

template<typename TKey, typename TData>
class TSortedTable : public TScanTable<TKey, TData>
{
private:


	void sort();
	void quicksort(int left, int right);
	int partition(int left, int right);
	void swap(TTabRecord<TKey, TData>*& a, TTabRecord<TKey, TData>*& b);


public:
	TSortedTable(int _maxSize = 100);
	TSortedTable(const TScanTable<TKey, TData>& ScanTable);
	TSortedTable(const TSortedTable<TKey, TData>& SortTable);

	void Insert(const TKey& _key, TData* _data);
	void Remove(const TKey& _key);
	TTabRecord<TKey, TData>* Find(const TKey& _key);

};

template<typename TKey, typename TData>
void TSortedTable<TKey, TData>::sort()
{
	quicksort(0, (this->count) - 1);
}

template<typename TKey, typename TData>
void TSortedTable<TKey, TData>::quicksort(int left, int right)
{
	if (left < right)
	{
		int pivot = partition(left, right);
		quicksort(left, pivot - 1);
		quicksort(pivot + 1, right);
	}
}

template<typename TKey, typename TData>
int TSortedTable<TKey, TData>::partition(int left, int right)
{
	TKey pivot = this->recs[right]->GetKey();
	int i = left - 1;

	for (int j = left; j < right; j++)
	{
		if (this->recs[j]->GetKey() < pivot)
		{
			i++;
			swap(this->recs[i], this->recs[j]);
		}
	}

	swap(this->recs[i + 1], this->recs[right]);
	return i + 1;
}

template<typename TKey, typename TData>
void TSortedTable<TKey, TData>::swap(TTabRecord<TKey, TData>*& a, TTabRecord<TKey, TData>*& b)
{
	TTabRecord<TKey, TData>* temp = a;
	a = b;
	b = temp;
}

template<typename TKey, typename TData>
TSortedTable<TKey, TData>::TSortedTable(int _maxSize) : TScanTable<TKey, TData>(_maxSize) {}

template<typename TKey, typename TData>
TSortedTable<TKey, TData>::TSortedTable(const TScanTable<TKey, TData>& ScanTable) : TScanTable<TKey, TData>(ScanTable)
{
	sort();
}

template<typename TKey, typename TData>
TSortedTable<TKey, TData>::TSortedTable(const TSortedTable<TKey, TData>& SortTable)
{
	this->maxSize = SortTable.maxSize;
	this->count = SortTable.count;
	this->currPos = SortTable.currPos;

	this->recs = new TTabRecord<TKey, TData>*[this->maxSize];
	for (int i = 0; i < this->count; i++)
	{
		TKey _key = SortTable.recs[i]->key;
		TData* _data = SortTable.recs[i]->data;
		this->recs[i] = new TTabRecord<TKey, TData>(_key, _data);
	}
}

template<typename TKey, typename TData>
void TSortedTable<TKey, TData>::Insert(const TKey& _key, TData* _data)
{

	if (IsFull())
		throw "ERROR: Table is full.";

	if (Find(_key) != nullptr) {
		throw "Key repeat, it's not good";
	}
	for (int i = this->count - 1; i >= this->currPos; i--) {
		recs[i + 1] = recs[i];
	}
	recs[this->currPos] = new TTabRecord<TKey, TData>(_key, _data);

	count++;

}

template<typename TKey, typename TData>
void TSortedTable<TKey, TData>::Remove(const TKey& _key)
{
	if (this->IsEmpty())
	{
		throw"Error";
	}

	TTabRecord<TKey, TData>* rec = Find(_key);
	if (rec == nullptr)
	{
		throw"Error";
	}
	else
	{
		delete rec;
		for (int i = this->currPos; i < this->count - 1; i++)
		{
			this->recs[i] = this->recs[i + 1];
		}
		this->count--;
	}
}

template <typename TKey, typename TData>
TTabRecord<TKey, TData>* TSortedTable<TKey, TData>:: Find(const TKey& _key) {
	int left = 0, right = count - 1;
	TTabRecord<TKey, TData>* search = nullptr;

	while (left <= right) {
		int mid = (right + left) / 2;

		if (recs[mid]->key == _key) {
			search = recs[mid];
			right = mid;
			left = mid + 1;
		}
		else if (recs[mid]->key < _key) left = mid + 1;
		else right = mid - 1;
	}
	if (right != -1)
		if (search == nullptr)
			this->currPos = right + 1;
		else
			this->currPos = right;
	else
		this->currPos = 0;
	return search;
}























#endif // !_SORTEDTABLE_H_


