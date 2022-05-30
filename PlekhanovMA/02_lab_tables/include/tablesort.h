#pragma once
#include "tablescan.h"

template <typename TData, typename TKey>
class TTableSort : public TTableScan<TData, TKey>
{
protected:
	void SortData(); // метод сортировки записей по ключам
public:
	TTableSort(int _tabSize) : TTableScan<TData, TKey>(_tabSize) { };
	TTableSort(TTableScan<TData, TKey>& table) : TTableScan<TData, TKey>(table) { SortData(); };
	// операции над таблицами
	virtual TTabRecord<TData, TKey>* FindRecord(TKey key);
	virtual void InsertRecord(TKey key, TData data);
	virtual void RemoveRecord(TKey key);
};

template <typename TData, typename TKey>
void TTableSort<TData, TKey>::SortData()
{
	int rght, rend;
	int i, j, m;
	TTabRecord<TData, TKey> **b = new TTabRecord<TData, TKey>*[this->tabSize];
	for (int k = 1; k < this->dataCount; k *= 2)
	{
		for (int left = 0; left + k < this->dataCount; left += k * 2)
		{
			rght = left + k;
			rend = rght + k;
			if (rend > this->dataCount)
			{
				rend = this->dataCount;
			}
			m = left; i = left; j = rght;
			while (i < rght && j < rend)
			{
				if (this->records[i]->GetKey() <= this->records[j]->GetKey())
				{
					b[m] = this->records[i]; i++;
				}
				else
				{
					b[m] = this->records[j]; j++;
				}
				m++;
			}
			while (i < rght)
			{
				b[m] = this->records[i];
				i++; m++;
			}
			while (j < rend)
			{
				b[m] = this->records[j];
				j++; m++;
			}
			for (m = left; m < rend; m++)
			{
				this->records[m] = b[m];
			}
		}
	}
}

template <typename TData, typename TKey>
TTabRecord<TData, TKey>* TTableSort<TData, TKey>::FindRecord(TKey key)
{
	if (this->IsEmpty() == 0)
	{
		int i = -1, j = this->dataCount;
		int mid;
		while (i < j - 1)
		{
			mid = (j + i) / 2;
			if (key >= this->records[mid]->GetKey())
			{
				i = mid;
			}
			else
			{
				j = mid;
			}
		}
		if (key == this->records[i]->GetKey())
		{
			this->currPos = i;
			return this->records[this->currPos];
		}
		else
		{
			return nullptr;
		}
	}
}

template <typename TData, typename TKey>
void TTableSort<TData, TKey>::InsertRecord(TKey key, TData data)
{
	int check = 1;
	this->Reset();
	while ((this->IsTabEnded() == 0) && key >= this->records[this->currPos]->GetKey())
	{
		if (this->records[this->currPos]->GetKey() == key)
		{
			check = 0;
			break;
		} 
		this->currPos++;
	}
	if (this->IsEmpty())
	{
		this->currPos++;
	}
	try
	{
		if (this->IsFull() == 0 && check != 0)
		{
			for (int i = this->dataCount; i > this->currPos; i--)
			{
				this->records[i] = this->records[i - 1];
			}
			this->records[this->currPos] = new TTabRecord<TData, TKey>(data, key);
			this->dataCount++;
		}
		else
			throw "таблица полная или данная запись уже есть";
	}
	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << '\n';
	}
}

template <typename TData, typename TKey>
void TTableSort<TData, TKey>::RemoveRecord(TKey key)
{
	TTabRecord<TData, TKey>* rec = FindRecord(key);
		if (rec != NULL)
		{
			delete this->records[this->currPos];
			for (int i = this->currPos; i < this->dataCount - 1; i++)
			{
				this->records[i] = this->records[i + 1];
			}
			this->dataCount--;
		}
		else
			throw "такой записи нет";
}