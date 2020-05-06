#ifndef _SORTTABLE_H_
#define _SORTTABLE_H_

#include "scantable.h"

enum class TSortType {INSERT_SORT, MERGE_SORT, QUICK_SORT};

template<typename TKey, class TData>
class TSortTable : public TScanTable<TKey, TData>
{
protected:
	TSortType sortType;

	void SortData();
	void InsertSort();
	void MergeSort(int _first, int _last);
	void Merge(int _first, int _mid, int _last);
	void QuickSort(int _first, int _last);
	void QuickSplit(int &i, int &j, TTabRecord<TKey, TData>* _mid);

public:
	TSortTable(int _size) : TScanTable<TKey, TData>(_size), sortType(TSortType::INSERT_SORT) {};
	TSortTable(const TScanTable<TKey, TData>& _tab, const TSortType _type = TSortType::INSERT_SORT);

	void SetSortType(TSortType _type);

	TTabRecord<TKey, TData>* FindRecord(const TKey _key) override;
	void InsertRecord(const TKey _key, TData* _data = nullptr) override;
	void RemoveRecord(const TKey _key) override;
};
//------------------------------------------------

template<typename TKey, class TData>
TSortTable<TKey, TData>::TSortTable(const TScanTable<TKey, TData>& _tab, const TSortType _type)
{
	this->tabSize = _tab.GetTabSize();
	this->dataCount = _tab.GetDataCount();
	this->currPos = 0;

	this->pRecs = new TTabRecord<TKey, TData>*[this->tabSize];
	for (int i = 0; i < this->tabSize; i++)
		if (_tab.pRecs[i])
			this->pRecs[i] = new TTabRecord<TKey, TData>(_tab.pRecs[i]->GetKey(), _tab.pRecs[i]->GetData());
		else
			this->pRecs[i] = nullptr;

	sortType = _type;
	SortData();
};
//------------------------------------------------

template<typename TKey, class TData>
void TSortTable<TKey, TData>::SortData()
{
	switch (sortType)
	{
	case TSortType::INSERT_SORT:
		InsertSort();
		break;
	case TSortType::MERGE_SORT:
		MergeSort(0, (this->dataCount -1));
		break;
	case TSortType::QUICK_SORT:
		QuickSort(0, (this->dataCount - 1));
		break;
	}
};

template<typename TKey, class TData>
void TSortTable<TKey, TData>::InsertSort()
{
	for (int i = 1, j; i < this->dataCount; i++)
	{
		TTabRecord<TKey, TData>* temp = this->pRecs[i];

		for (j = i - 1; j >= 0; j--)
			if (*(this->pRecs[j]) > * temp)
				this->pRecs[j + 1] = this->pRecs[j];
			else break;

		this->pRecs[j + 1] = temp;
	}
};

template<typename TKey, class TData>
void TSortTable<TKey, TData>::MergeSort(int _first, int _last)
{
	if (_first >= _last)
		return;

	int mid = (_last + _first) / 2;
	MergeSort(_first, mid);
	MergeSort(mid + 1, _last);
	Merge(_first, mid, _last);
};

template<typename TKey, class TData>
void TSortTable<TKey, TData>::Merge(int _first, int _mid, int _last)
{
	int i = _first, j = _mid + 1, step = 0;
	TTabRecord<TKey, TData>** pBuff = new TTabRecord<TKey, TData>*[_last - _first + 1];

	for (step; step < _last - _first + 1; step++)
		if ((j > _last) || ((i <= _mid) && (*(this->pRecs[i]) < *(this->pRecs[j]))))
			pBuff[step] = this->pRecs[i++];
		else 
			pBuff[step] = this->pRecs[j++];

	for (step = _first; step < _last + 1; step++)
	{
		this->pRecs[step] = pBuff[step - _first];
		pBuff[step - _first] = nullptr;
	}

	delete[] pBuff;
};

template<typename TKey, class TData>
void TSortTable<TKey, TData>::QuickSort(int _first, int _last)
{
	int i = _first, j = _last, mid = (_last + _first) / 2;

	QuickSplit(i, j, this->pRecs[mid]);

	if (j > _first)
		QuickSort(_first, j);
	if (i < _last)
		QuickSort(i, _last);
};

template<typename TKey, class TData>
void TSortTable<TKey, TData>::QuickSplit(int& i, int& j, TTabRecord<TKey, TData>* _mid)
{
	do
	{
		while (*(this->pRecs[i]) < *_mid)
			i++;
		while (*(this->pRecs[j]) > *_mid)
			j--;

		if (i <= j)
		{
			std::swap<TTabRecord<TKey, TData>* >(this->pRecs[i], this->pRecs[j]);
			i++;
			j--;
		}
	} while (i <= j);
};
//------------------------------------------------

template<typename TKey, class TData>
void TSortTable<TKey, TData>::SetSortType(TSortType _type)
{
	sortType = _type;
};

template<typename TKey, class TData>
TTabRecord<TKey, TData>* TSortTable<TKey, TData>::FindRecord(const TKey _key)
{
	int i, i1 = 0, i2 = this->dataCount - 1;
	TTabRecord<TKey, TData>* record = nullptr;

	if (!this->IsEmpty())
	{
		while (i1 <= i2)
		{
			i = (i1 + i2) / 2;

			if (_key == this->pRecs[i]->GetKey())
			{
				i1 = i;
				i2 = i - 1;
				record = this->pRecs[i];
			}
			else if (_key > this->pRecs[i]->GetKey())
				i1 = i + 1;
			else
				i2 = i - 1;
		}

		this->currPos = i1;
	}

	return record;
};

template<typename TKey, class TData>
void TSortTable<TKey, TData>::InsertRecord(const TKey _key, TData* _data)
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
void TSortTable<TKey, TData>::RemoveRecord(const TKey _key)
{
	if (!this->IsEmpty())
	{
		TTabRecord<TKey, TData>* record = FindRecord(_key);

		if (record)
		{
			delete this->pRecs[this->currPos];

			for (int i = this->currPos; i < this->dataCount - 1; i++)
				this->pRecs[i] = this->pRecs[i + 1];

			this->pRecs[--(this->dataCount)] = nullptr;
		}
		else
			throw Exception("The record with this key wasn't found in table!");
	}
};

#endif