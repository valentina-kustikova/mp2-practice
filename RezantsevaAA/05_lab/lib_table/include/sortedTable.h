#ifndef __SORTEDTABLE_H__
#define __SORTEDTABLE_H__
#include "scanTable.h"

template <typename TKey, typename TData> 
class SortedTable : public TScanTable<TKey, TData>
{
private:
	void Sort();
	void QuickSort(TTabRecord<TKey, TData>* a, int n);
public:
	SortedTable(int _maxSize);
	SortedTable(const TScanTable<TKey, TData>& st);
	SortedTable(const SortedTable<TKey, TData>& srt);

	virtual void Insert(const TKey& k, const TData& d)  override;
	virtual void Remove(const TKey& k) override;
	virtual TTabRecord<TKey, TData>* Find(const TKey& k) override;
};

template<typename TKey, typename TData>
void SortedTable<TKey, TData>::QuickSort(TTabRecord<TKey, TData>* a, int n)
{
	int i = 0;
	int j = n - 1;
	TTabRecord<TKey, TData> pivot = a[n / 2]; 

	do {
		while (a[i].GetKey() < pivot.GetKey()) 
			i++;
		while (a[j].GetKey() > pivot.GetKey()) 
			j--;

		if (i <= j) {
			TTabRecord<TKey, TData> tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0)
		QuickSort(a, j + 1); 
	if (i < n)
		QuickSort(a + i, n - i); 
}

template<typename TKey, typename TData> void 
SortedTable<TKey, TData>::Sort()
{
	QuickSort(records, size);
}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(int max_size) : TScanTable<TKey, TData>(max_size) {}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(const TScanTable<TKey, TData>& st) : TScanTable<TKey, TData>(st)
{
	Sort();
}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(const SortedTable<TKey, TData>& srt) : TScanTable<TKey, TData>(srt) { this->Sort(); }

template<typename TKey, typename TData> TTabRecord<TKey, TData>* SortedTable<TKey, TData>::Find(const TKey& k)
{
	int i1 = 0;
	int i2 = size - 1; 

	while (i1 <= i2)
	{
		int mid = (i1 + i2) / 2;
		if (records[mid]->GetKey() == k)
		{
			currPos = mid;
			return records[mid];
		}
		else if (k > records[mid]->GetKey())
		{
			currPos = mid;
			i1 = mid + 1;
		}
		else
			i2 = mid  - 1;
	}
	currPos = i1;
	return nullptr;
}
template<typename TKey, typename TData>
void SortedTable<TKey, TData>::Insert(const TKey& k, const TData& d) {
	
	if (IsFull())
		throw "Table is full. Can't insert";

	if (records[currPos] != nullptr && records[currPos]->GetKey() < k)
		currPos++;
	for (int i = size - 1; i >= currPos; i--)
	{
		records[i + 1] = records[i];
	}
	records[currPos] = new TTabRecord<TKey, TData>(k, d);
	size++;
}

template<typename TKey, typename TData> 
void SortedTable<TKey, TData>::Remove(const TKey& k)
{
	if (IsEmpty())
		throw "Nothing to remove. Table is empty";
	TTabRecord<TKey, TData>* rec = Find(k);
	if (rec == nullptr)
		throw "Record not found";
	delete rec;
	for (int i = currPos; i < size; ++i)
	{
		records[i] = records[i + 1];
		
	}
	size--;
}

#endif