#ifndef __SORTED_TABLE_H__
#define __SORTED_TABLE_H__

template <typename TKey, typename TData>
class SortedTable : public ScanTable {
private:
	void QuickSort();
public:
	SortedTable(int maxSize);
	SortedTbale(const ScanTbale* <TKey, TData>);
	TabRecord<TKey, TData>* Find(TKey key);
	void Insert(TKey key, TData* data);
	void Remove(TKey key);
}

#endif