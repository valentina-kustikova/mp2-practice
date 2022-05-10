#pragma once
#include "Table.h"

// Класса Хеш-таблица
template <typename TData, typename TKey>
class HashTable : public Table<TData, TKey>
{
protected:
	char* mark;								// 0 пусто, 1 заполнена, -1 удалена
	int HashFunc(const TKey& key) const;
	int HashFunc2(int in) const;
	unsigned int step;
public:
	// Конструкторы, деструктор	
	HashTable(unsigned int n = 10, unsigned int step1 = 1);
	HashTable(const HashTable<TData, TKey>& T1);
	~HashTable();
	// Методы
	virtual void Insert(const TData Data, const TKey Key);
	virtual void Delete(const TKey Key);
	virtual TData* Search(const TKey Key);
	void SetNext();
	void Reset();
	template <class TData> friend ostream& operator<<(ostream& os, const HashTable<TData, TKey>& T1)
	{
		if (T1.dataCount)
		{
			for (int i = 0; i < T1.Size; i++)
			{
				if (T1.mark[i])
				{
					os << "\t" << left << setw(15) << T1.rec[i]->GetKey() << " | " << *(T1.rec[i]->GetData()) << '\n';
				}
			}
		}
		else
		{
			os << "\n\tTable is Empty\n" << endl;
		}
		return os;
	}
	HashTable<TData, TKey>& operator=(HashTable<TData, TKey> T1)
	{
		Size = T1.Size;
		step = T1.step;
		dataCount = T1.dataCount;
		ind = T1.ind;
		rec = new TabRecord<TData, TKey>*[Size];
		mark = new char[Size];
		for (int i = 0; i < Size; i++)
		{
			mark[i] = T1.mark[i];
			if (mark[i] == 1)
			{
				rec[i] = new TabRecord<TData, TKey>(*(T1.rec[i]));
			}
		}
		return *this;
	}
};

// Pелизация функциий для класса Хеш-таблиц
// Конструкторы, деструктор	
template <typename TData, typename TKey>
HashTable<TData, TKey>::HashTable(unsigned int n, unsigned int step1) : Table(n)
{
	step = step1;
	mark = new char[n];
	for (int i = 0; i < Size; i++)
	{
		mark[i] = 0;
	}
}
template <typename TData, typename TKey>
HashTable<TData, TKey>::HashTable(const HashTable<TData, TKey>& T1)
{
	Size = T1.Size;
	step = T1.step;
	dataCount = T1.dataCount;
	ind = T1.ind;
	rec = new TabRecord<TData, TKey>*[Size];
	mark = new char[Size];
	for (int i = 0; i < Size; i++)
	{
		mark[i] = T1.mark[i];
		if (mark[i] == 1)
		{
			rec[i] = new TabRecord<TData, TKey>(*(T1.rec[i]));
		}
	}
}
template <typename TData, typename TKey>
HashTable<TData, TKey>::~HashTable()
{
	delete[] mark;
}
// Методы 
template <typename TData, typename TKey>
int HashTable<TData, TKey>::HashFunc(const TKey& key) const
{
	int h = 0;
	for (int i = 0; i < key.length(); i++)
	{
		h = h + int(key[i]);
	}
	return h % Size;
}
template <typename TData, typename TKey>
int HashTable<TData, TKey>::HashFunc2(int in) const
{
	return (in + step) % Size;;
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::SetNext()
{
	if (!IsEmpty())
	{
		do
		{
			ind = (ind + 1) % Size;
		} while (mark[ind] != 1);
	}
	else
	{
		throw 1;
	}
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::Reset()
{
	if (dataCount)
	{
		ind = 0;
		while (mark[ind] != 1)
		{
			ind++;
		}
	}
	else
	{
		ind = -1;
	}
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::Insert(const TData data1, const TKey key1)
{
	if (IsFull())
	{
		throw 1;
	} //Таблица переполнена
	ind = HashFunc(key1);
	if (mark[ind] != 1)
	{
		rec[ind] = new TabRecord<TData, TKey>(key1, data1);
		dataCount++;
		mark[ind] = 1;
	}
	else
	{
		if (rec[ind]->GetKey() != key1)
		{
			int i = ind;
			while (mark[ind])
			{
				ind = HashFunc2(ind);
			}
			rec[ind] = new TabRecord<TData, TKey>(key1, data1);
			dataCount++;
			mark[ind] = 1;
		}
		else
		{
			throw 1;
		}
	}
}
template <typename TData, typename TKey>
TData* HashTable<TData, TKey>::Search(const TKey key1)
{
	Reset();
	if (dataCount)
	{
		ind = HashFunc(key1);
		int i = ind;
		if (rec[ind]->GetKey() == key1)
		{
			return rec[ind]->GetData();
		}
		else
		{
			while (mark[ind] && ((ind + step) != i) && (rec[ind]->GetKey() != key1))
			{
				ind = HashFunc2(ind);
			}
			if (rec[ind]->GetKey() == key1)
			{
				return rec[ind]->GetData();
			}
			else
			{
				return nullptr;
			}
		}
	}
	else
	{
		throw 1;
	}
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::Delete(const TKey key1)
{
	Reset();
	if (Search(key1) != nullptr)
	{
		rec[ind] = new TabRecord<TData, TKey>;
		mark[ind] = -1;
		dataCount--;
	}
	else
	{
		throw 1;
	}
}