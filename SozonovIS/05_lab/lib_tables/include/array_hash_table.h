#ifndef __ARRAY_HASH_TABLE_H__
#define __ARRAY_HASH_TABLE_H__

class ArrayHashTable : public HashTable {
private:
	TabRecord** records;
	TabRecord* pMark;
	int freePos;
	int hashStep;
	int GetNextPos(int h_val);
public:
	ArrayHashTable(int n, int step);
	ArrayHashTable(const ArrayHashTable& ahtable);
	~ArrayHashTable();
	ArrayHashTable* Search(const TKey key);
	void Insert(TKey key, TData* data);
	void Remove(TKey key);
	void Reset();
	void Next();
	bool IsEnded()const;
};


#endif