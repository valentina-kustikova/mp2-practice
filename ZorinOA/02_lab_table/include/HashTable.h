#pragma once
#include <string>
#include <functional>
#include "Table.h"
#include "TabRecord.h"
#include "list.h"

template <class TKey, class TData>
class ListHashTable : public Table<TKey, TData>
{
protected:
	List<TabRecord<TKey, TData>>* ListsRecs;
	int TabSize;
	virtual unsigned long HashFunc(const TKey& k) = 0;
public:
	ListHashTable(int size = MAX_SIZE)
	{
		if (size <= 0 || size > MAX_SIZE)
			throw "Wrong size!!";
		TabSize = size;
		ListsRecs = new List<TabRecord<TKey, TData>>[TabSize];
	}
	virtual ~ListHashTable()
	{
		delete[] ListsRecs;
	}
	ListHashTable(const ListHashTable& ht)
	{
		TabSize = ht.TabSize;
		ListsRecs = new List<TabRecord<TKey, TData>>[TabSize];
		for (int i = 0; i < TabSize; i++)
		{
			ListsRecs[i] = ht.ListsRecs[i];
		}
	}
	ListHashTable& operator=(const ListHashTable& ht)
	{
		if (this != &ht)
		{
			if (TabSize != ht.TabSize)
			{
				delete[] ListsRecs;
				TabSize = ht.TabSize;
				ListsRecs = new List<TabRecord<TKey, TData>>[TabSize];
			}
			for (int i = 0; i < TabSize; i++)
			{
				ListsRecs[i] = ht.ListsRecs[i];
			}
		}
		return *this;
	}
	virtual bool isFull() const
	{
		return DataCount >= TabSize;
	}
	virtual void Insert(const TKey& k, const TData& d)
	{
		int idx = HashFunc(k) % TabSize;
		ListsRecs[idx].InsertToHead(TabRecord<TKey, TData>(k, d));
		DataCount++;
	}
	virtual TData* Find(const TKey& k)
	{
		if (!isEmpty())
		{
			int idx = HashFunc(k) % TabSize;
			Node<TabRecord<TKey, TData>>* tmp = ListsRecs[idx].Search(TabRecord<TKey, TData>(k));
			if (tmp == nullptr)
				return nullptr;
			else
				return &(tmp->data.GetData());
		}

	}
	virtual void Delete(const TKey& k)
	{
		if (!isEmpty())
		{
			int idx = HashFunc(k) % TabSize;
			ListsRecs[idx].Delete(TabRecord<TKey, TData>(k));
			DataCount--;
		}
	}
	
	friend std::ostream& operator<<(std::ostream& os, const ListHashTable& ht)
	{
		for (int i = 0; i < ht.TabSize; i++)
		{
			if (!(ht.ListsRecs[i].isEmpty()))
				os << ht.ListsRecs[i] << std::endl;
		}
		return os;
	}
};

template <class TKey, class TData>
class HashTable : public ListHashTable<TKey, TData>
{
protected:
	virtual unsigned long HashFunc(const TKey& k) override
	{
		return std::hash<TKey>{}(k);
	}
public:
	HashTable(int size = MAX_SIZE)
		: ListHashTable(size) {}
};

template<class TData>
class HashTable<std::string, TData> : public ListHashTable<std::string, TData>
{
protected:
	virtual unsigned long HashFunc(const std::string& k) override
	{
		unsigned long Res = k[0];
		unsigned long p = 17;
		for (int i = 1; i < k.length(); i++)
		{
			Res += k[i] * p;
			p *= p;
		}
		return Res;
	}
public:
	HashTable(int size = MAX_SIZE)
		: ListHashTable(size) {}
};