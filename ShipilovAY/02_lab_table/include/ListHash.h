#pragma once
#include "HashTable.h"
#include "list.h"
#include "TabRecord.h"

template <class TData, class TKey>
class ListHash : public HashTable<TData, TKey>
{
protected:
	TList< TabRecord<TData, TKey> >* pList;
	int TabSize;
	int CurrList;
public:
	ListHash(int MaxSize = 10);
	ListHash(const ListHash& lh);
	~ListHash();
	virtual void Insert(const TData& _data, const TKey& _Key);
	virtual void Delete(const TKey& _Key);
	virtual TData* Search(const TKey& _Key);
	virtual void Reset();
	virtual void SetNext();
	virtual bool IsEnd() const;
	virtual bool IsFull() const;
	virtual TKey GetKey() const;
	virtual TData* GetData() const;
	virtual void Clear()
	{
		if (!(this->IsEmpty()))
		{
			for (int i = 0; i < Top; i++)
			{

				pList[i].Clear();
			}
			this->Top = 0;
			CurrList = 0;
		}
	}
};

template<class TData, class TKey>
inline ListHash<TData, TKey>::ListHash(int MaxSize)
{
	pList = new TList< TabRecord<TData, TKey> >[MaxSize];
	TabSize = MaxSize;
	CurrList = 0;
}

template<class TData, class TKey>
inline ListHash<TData, TKey>::ListHash(const ListHash& lh)
{
	Top = lh.Top;
	TabSize = lh.TabSize;
	CurrList = lh.CurrList;
	for (int i = 0; i < TabSize; i++)
	{
		pList[i] = lh.pList[i];
	}
}

template<class TData, class TKey>
inline ListHash<TData, TKey>::~ListHash()
{
	delete[] pList;
}

template<class TData, class TKey>
inline bool ListHash<TData, TKey>::IsFull() const
{
	try
	{
		TabRecord<TData, TKey>* rec = new TabRecord<TData, TKey>;
		bool temp = (rec == nullptr);
		delete rec;
		return temp;
	}
	catch (const exception& ex)
	{
		cerr << ex.what() << endl;
	}
}

template<class TData, class TKey>
inline TKey ListHash<TData, TKey>::GetKey() const
{
	return pList[CurrList].GetCurrent() == nullptr ? TKey() : pList[CurrList].GetCurrent()->data.GetKey();
}

template<class TData, class TKey>
inline TData* ListHash<TData, TKey>::GetData() const
{
	return pList[CurrList].GetCurrent() == nullptr ? nullptr : pList[CurrList].GetCurrent()->data.GetData();
}

template<class TData, class TKey>
inline void ListHash<TData, TKey>::Insert(const TData& _data, const TKey& _Key)
{
	if (!IsFull())
	{
		if (Search(_Key) == nullptr)
		{
			pList[CurrList].InsFirst(TabRecord<TData, TKey>(_data, _Key));
			Top++;
		}
		else
			throw "duplicated key";
	}
	else
		throw "Table is full";
}

template<class TData, class TKey>
inline void ListHash<TData, TKey>::Delete(const TKey& _Key)
{
	if (!this->IsEmpty())
	{
		if (Search(_Key) != nullptr)
		{
			pList[CurrList].Delete(TabRecord<TData, TKey>({}, _Key));
			Top--;
		}
		else
			throw "Element not find in HashTable";
	}
	else
		throw "Table is empty";
}

template<class TData, class TKey>
inline TData* ListHash<TData, TKey>::Search(const TKey& _Key)
{
	CurrList = HashFunc(_Key) % TabSize;
	for (pList[CurrList].Reset(); !pList[CurrList].IsEnded(); pList[CurrList].GetNext())
	{
		if (pList[CurrList].GetCurrent()->data.GetKey() == _Key)
			return pList[CurrList].GetCurrent()->data.GetData();
	}
	return nullptr;
}

template<class TData, class TKey>
inline void ListHash<TData, TKey>::Reset()
{
	CurrList = 0;
	pList[CurrList].Reset();
	while (CurrList < TabSize - 1 && pList[CurrList].IsEnded())
	{
		CurrList++;
		pList[CurrList].Reset();
	}
}

template<class TData, class TKey>
inline void ListHash<TData, TKey>::SetNext()
{
	if (!pList[CurrList].IsEnded())
		pList[CurrList].GetNext();

	while (CurrList < TabSize - 1 && pList[CurrList].IsEnded())
	{
		CurrList++;
		pList[CurrList].Reset();
	}
}

template<class TData, class TKey>
inline bool ListHash<TData, TKey>::IsEnd() const
{
	return CurrList == TabSize - 1 && pList[CurrList].IsEnded();
}
