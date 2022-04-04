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
        return this->DataCount >= TabSize;
	}
	virtual void Clear()
	{
		if (!(this->isEmpty()))
		{
			this->DataCount = 0;
			for (int i = 0; i < TabSize; i++)
			{
				ListsRecs[i].Clear();
			}
		}
	}
	virtual void Insert(const TKey& k, const TData& d)
	{
		int idx = HashFunc(k) % TabSize;
        Node<TabRecord<TKey, TData>>* tmp = ListsRecs[idx].Search(TabRecord<TKey, TData>(k));
        if (tmp == nullptr)
        {
            ListsRecs[idx].InsertToHead(TabRecord<TKey, TData>(k, d));
            this->DataCount++;
        }
	}
	virtual TData* Find(const TKey& k)
	{
        if (!(this->isEmpty()))
		{
			int idx = HashFunc(k) % TabSize;
			Node<TabRecord<TKey, TData>>* tmp = ListsRecs[idx].Search(TabRecord<TKey, TData>(k));
            if (tmp != nullptr)
				return &(tmp->data.GetData());
		}
        return nullptr;
	}
	virtual void Delete(const TKey& k)
	{
        if (!(this->isEmpty()))
		{
			int idx = HashFunc(k) % TabSize;
			ListsRecs[idx].Delete(TabRecord<TKey, TData>(k));
            this->DataCount--;
		}
	}

	class Iterator
	{
		List< TabRecord<TKey, TData> >* CurrList;
		List< TabRecord<TKey, TData> >* LastList;
		typename List<TabRecord<TKey, TData>>::Iterator CurrPos;
	public:
		Iterator(List<TabRecord<TKey, TData>>* pos, int n)
		{
			CurrList = pos;
			LastList = pos + n - 1;
			CurrPos = pos->begin();
			while (CurrList != LastList && CurrPos == CurrList->end())
			{
				CurrList++;
				CurrPos = CurrList->begin();
			}
		}
		Iterator()
		{
			CurrList = nullptr;
			LastList = nullptr;
            typename List< TabRecord<TKey, TData> >::Iterator it(nullptr);
			CurrPos = it;
		}
		TabRecord<TKey, TData>& operator*()
		{
			return *CurrPos;
		}
		Iterator& operator++()
		{
			++CurrPos;
			while (CurrList != LastList && CurrPos == CurrList->end())
			{
				CurrList++;
				CurrPos = CurrList->begin();
			}
			return *this;
		}
		bool operator==(const Iterator& it)
		{
			return CurrPos == it.CurrPos;
		}
		bool operator!=(const Iterator& it)
		{
			return CurrPos != it.CurrPos;
		}
	};
	Iterator begin() const
	{
		ListHashTable::Iterator it(ListsRecs, TabSize);
		return it;

	}
	Iterator end() const
	{
		ListHashTable::Iterator it;
		return it;
	}

	friend std::ostream& operator<<(std::ostream& os, const ListHashTable& ht)
	{
		for (auto it = ht.begin(); it != ht.end(); ++it)
		{
			os << *it << std::endl;
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
        :ListHashTable<TKey, TData>(size) {}
};

template<class TData>
class HashTable<std::string, TData> : public ListHashTable<std::string, TData>
{
protected:
	virtual unsigned long HashFunc(const std::string& k) override
	{
		unsigned long Res = k[0];
		unsigned long p = 17;
        for (size_t i = 1; i < k.length(); i++)
		{
			Res += k[i] * p;
			p *= p;
		}
		return Res;
	}
public:
	HashTable(int size = MAX_SIZE)
        : ListHashTable<std::string, TData>(size) {}
};
