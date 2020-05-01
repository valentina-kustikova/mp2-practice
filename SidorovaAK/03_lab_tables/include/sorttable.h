#ifndef _SORTTABLE_H_
#define _SORTTABLE_H_

#include "scantable.h"

template<typename TKey, class TData>
class TSortTable : public TScanTable<TKey, TData>
{
protected:
	void SortData();

public:
	TSortTable(int _size) : TScanTable<TKey, TData>(_size) {};
	TSortTable(const TScanTable<TKey, TData>& _tab);

	virtual TTabRecord<TKey, TData>* FindRecord(TKey _key) override;
	virtual void InsertRecord(TKey _key, TData* _data = nullptr) override;
	virtual void RemoveRecord(TKey _key) override;
};
//------------------------------------------------

template<typename TKey, class TData>
TSortTable<TKey, TData>::TSortTable(const TScanTable<TKey, TData>& _tab)
{
	this->tabSize = _tab.GetTabSize();
	this->dataCount = _tab.GetCountData();
	this->currPos = 0;

	pRecs = new TTabRecord<TKey, TData>*[this->tabSize];
	for (int i = 0; i < this->tabSize; i++)
		pRecs[i] = new TTabRecord<TKey, TData>(_tab.pRecs[i]->GetKey(), _tab.pRecs[i]->GetData());
	SortData();
};
//------------------------------------------------

template<typename TKey, class TData>
TTabRecord<TKey, TData>* TSortTable<TKey, TData>::FindRecord(TKey _key)
{
	int i, i1 = 0, i2 = this->dataCount - 1;
	TTabRecord<TKey, TData>* record = nullptr;

	while (i1 <= i2)
	{
		i = (i1 + i2) / 2;

		if (_key == this->pRecs[i]->GetKey())
		{
			i1 = i + 1;
			i2 = i;
			record = this->pRecs[i];
		}
		else if (_key > this->pRecs[i]->GetKey())
			i1 = i + 1;
		else
			i2 = i - 1;
	}

	this->currPos = i2;
	return record;
};

template<typename TKey, class TData>
void TSortTable<TKey, TData>::InsertRecord(TKey _key, TData* _data)
{
	if (!this->IsFull())
	{
		TTabRecord<TKey, TData>* record = FindRecord(_key);
		for (int i = this->dataCount; i > this->currPos; i--)
			this->pRecs[i] = this->pRecs[i - 1];
		this->pRecs[this->currPos] = new TTabRecord<TKey, TData>(_key, _data);
		this->dataCount++;
	}
	else
		throw Exception("Table is full!");
};

template<typename TKey, class TData>
void TSortTable<TKey, TData>::RemoveRecord(TKey _key)
{
	if (!this->IsEmpty())
	{
		TTabRecord<TKey, TData>* record = FindRecord(_key);

		if (!record)
		{
			delete pRecs[this->currPos];

			for (int i = this->currPos; i < this->dataCount - 1; i++)
				this->pRecs[i] = this->pRecs[i + 1];

			this->dataCount--;
		}
		else
			throw Exception("The record with this key wasn't found in table!");
	}
};

#endif