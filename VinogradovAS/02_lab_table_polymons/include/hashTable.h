#pragma once
#include "table.h"

template<typename TData, typename TKey>
class HashTable : public Table<TData,TKey>
{
protected:
	TabRecord<TData, TKey> pMark; // маркер для обозначения удаленных записей
	int hashStep;
	int hashFunc(const TKey& Key);
	int hashFunc2(int pos);
public:
	HashTable(int maxSize = 10, int step = 1) : Table<TData, TKey>(maxSize)
	{
		hashStep = step;
		pMark = new TabRecord<TData, TKey>(string"delete", NULL);

	};
	~HashTable();
	//HashTable(const HashTable<TData, TKey>& other);
	virtual void Insert(const TData Data, const TKey Key);
	virtual void Remove(const TKey Key);
	virtual TData* Search(const TKey Key);
	void SetNext();
	void Reset();
};

template<typename TData, typename TKey>
inline int HashTable<TData, TKey>::hashFunc(const TKey& Key)
{
	int result = Key[0];
	int p = 35;
	for (int i = 1; i < Key.length(); i++)
	{
		result = result + Key[i] * p;
		p = p * p;
	}
	return result;
}

template<typename TData, typename TKey>
inline int HashTable<TData, TKey>::hashFunc2(int pos)
{
	return (pos + hashStep) % this->maxSize;
}

template<typename TData, typename TKey>
inline void HashTable<TData, TKey>::Insert(const TData Data, const TKey Key)
{
}
