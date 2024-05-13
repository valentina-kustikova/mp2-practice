#ifndef __SORTEDTABLE_H__
#define __SORTEDTABLE_H__
#include "scanTable.h"

template <typename TKey, typename TData> 
class SortedTable : public TScanTable<TKey, TData>
{
private:
	void Sort();
public:
	SortedTable(int _maxSize);
	SortedTable(const TScanTable<TKey, TData>& st);
	SortedTable(const SortedTable<TKey, TData>& srt);

	void Insert(const TKey& k, const TData& d)  override;
	virtual void Remove(const TKey& k) override;
	virtual TTabRecord<TKey, TData>* Find(const TKey& k) override;
};

template<typename TKey, typename TData> void 
SortedTable<TKey, TData>::Sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (records[j]->GetKey() > records[j + 1]->GetKey())
			{
				TTabRecord<TKey, TData>* tmp = records[j];
				records[j] = records[j + 1];
				records[j + 1] = tmp;
			}
		}
	}
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

	TTabRecord<TKey, TData>* Search = nullptr;
	while (i1 < i2)
	{
		int mid = (i1 + i2) / 2;
		if (records[mid]->GetKey() == k)
		{
			Search = records[mid];
			i1 = mid + 1;
			i2 = mid;
		}
		else if (k > records[mid]->GetKey())
		{
			i1 = mid + 1;
		}
		else
			i2 = mid d - 1;
		currPos = i2;
	}
	return Search;
}

template<typename TKey, typename TData> 
void SortedTable<TKey, TData>::Insert(const TKey& k, const TData& d)
{
	if (IsFull())
		throw "Table is full. Can't insert";
	Find(k);
	for (int i = size - 1; i >= currPos; i--) {
		records[i + 1] = reccords[i];
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
	for (int i = currPos; i < size - 1; ++i)
	{
		records[i] = records[i + 1];
	}
	size--:
}

#endif