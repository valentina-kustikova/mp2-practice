#ifndef _ARRAYTABLE_H_
#define _ARRAYTABLE_H_

#include "table.h"

template<typename TKey, class TData>
class TArrayTable : public TTable<TKey, TData>
{
protected:
	TTabRecord<TKey, TData>** pRecs;

public:
	TArrayTable(int _size);
	~TArrayTable();

	TTabRecord<TKey, TData>* GetRecord() const;
	virtual TKey GetKey() const;
	virtual TData* GetData() const;
};
//----------------------------------------

template<typename TKey, class TData>
TArrayTable<TKey, TData>::TArrayTable(int _size) : TTable<TKey, TData>(_size)
{
	pRecs = new TTabRecord<TKey, TData>*[this->tabSize];
	for (int i = 0; i < this->tabSize; pRecs[i++] = nullptr);
};

template<typename TKey, class TData>
TArrayTable<TKey, TData>::~TArrayTable()
{
	for (int i = 0; i < this->tabSize; delete pRecs[i++]);
	delete[] pRecs;

	this->tabSize = this->dataCount = this->currPos = 0;
};
//-----------------------------------------

template<typename TKey, class TData>
TTabRecord<TKey, TData>* TArrayTable<TKey, TData>::GetRecord() const
{
	return pRecs[this->GetCurrentPos()];
};

template<typename TKey, class TData>
TKey TArrayTable<TKey, TData>::GetKey() const
{
	return pRecs[this->GetCurrentPos()]->GetKey();
};

template<typename TKey, class TData>
TData* TArrayTable<TKey, TData>::GetData() const
{
	return pRecs[this->GetCurrentPos()]->GetData();
};

#endif
