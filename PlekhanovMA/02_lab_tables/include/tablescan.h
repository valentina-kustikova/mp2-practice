#pragma once
#include "table.h"

template <typename TData, typename TKey>
class TTableScan : public TTable<TData, TKey>
{
protected:
	TTabRecord<TData, TKey>** records;
public:
	TTableScan(int _tabSize) : TTable<TData, TKey>(_tabSize) { records = new TTabRecord<TData, TKey>*[_tabSize]; };
	TTableScan<TData, TKey>() {};
	TTableScan(TTableScan<TData, TKey> &table)
	{
		this->tabSize = table.tabSize;
		this->dataCount = table.dataCount;
		this->currPos = table.currPos;
		this->records = new TTabRecord<TData, TKey>*[this->tabSize];
		for (int i = 0; i < table.tabSize; i++)
		{
			records[i] = table.records[i];
		}
	}
	// операции над таблицами
	virtual TTabRecord<TData, TKey>* FindRecord(TKey key);
	virtual void InsertRecord(TKey key, TData data);
	virtual void RemoveRecord(TKey key);
	void Clear();
	// доступ к текущей записи таблицы
	TKey GetKey() const
	{
		if (this->IsEmpty() == 0)
		{
			return this->records[this->currPos]->key;
		}
	}

	TData* GetData() const
	{
		if (this->IsEmpty() == 0)
		{
			return this->records[this->currPos]->data;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const TTableScan& records)
	{
		int i = 0;
		while (i < records.dataCount)
		{
			out << "Key:" << records.records[i]->key << " Polinom: " << *(records.records[i]->data) << '\n';
			i++;
		}
		if (records.dataCount == 0)
			out << "Table is Empty\n";
		return out;
	}
};

template <typename TData, typename TKey>
TTabRecord<TData, TKey>* TTableScan<TData, TKey>::FindRecord(TKey key)
{
	this->currPos = 0;
	for (int i = 0; i < this->dataCount; i++)
	{
		if (this->records[this->currPos]->GetKey() == key)
		{
			return this->records[this->currPos];
		}
		this->currPos++;
	}
	return NULL;
}

template <typename TData, typename TKey>
void TTableScan<TData, TKey>::InsertRecord(TKey key, TData data)
{
	TTabRecord<TData, TKey> R(data, key);
	try
	{
		if (this->IsFull() == 0 && this->FindRecord(key) == NULL)
		{
			this->records[this->dataCount] = new TTabRecord<TData, TKey>(R);
			this->dataCount++;
			this->currPos++;
		}
		else
			throw "таблица полная или данная запись уже есть в таблице";
	}
	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << '\n';
	}
}

template <typename TData, typename TKey>
void TTableScan<TData, TKey>::RemoveRecord(TKey key)
{
	try
	{
		if (this->IsEmpty() == 0 && this->FindRecord(key) != NULL)
		{
			delete this->records[this->currPos];
			this->records[this->currPos] = this->records[--this->dataCount];
		}
		else
			throw "таблица пуста или такой записи нет";
	}
	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << '\n';
	}
}

template <typename TData, typename TKey>
void TTableScan<TData, TKey>::Clear()
{
	try
	{
		if (this->IsEmpty() == 0)
		{
			this->Reset();
			while (this->IsTabEnded() == 0)
			{
				this->records[this->currPos] = nullptr;
				this->currPos++;
			}
			this->dataCount = 0;
		}
		else
			throw "таблица уже пустая";
	}
	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << '\n';
	}
}