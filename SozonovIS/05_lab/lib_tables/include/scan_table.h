#ifndef __SCAN_TABLE_H__
#define __SCAN_TABLE_H__

template <typename TKey, typename TData>
class ScanTable : public Table {
protected:
	TabRecord** recs;
public:
	ScanTable(int maxSize);
	ScanTable(const ScanTable& t);
	~ScanTable();
	TabRecord<TKey, TData>* Find(Tkey key);
	void Insert(TKey key, TData* data);
	void Remove(TKey key);
}

#endif