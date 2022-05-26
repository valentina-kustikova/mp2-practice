#pragma once
#include "table.h"

template <typename TData, typename TKey>
class TTableHash : public TTable<TData, TKey>
{
protected:
	unsigned long HashFunc(const TKey key);
	TTabRecord<TData, TKey>** records;
	int hashStep;
	int freePos;
	TTabRecord<TData, TKey>* pMark;
	// функция вторичного перемешивания
	int GetNextPos(int pos)
	{
		return (pos + hashStep) % tabSize;
	}
public:
	TTableHash(int _tabSize, int _hashStep);
	~TTableHash() {};
	virtual TTabRecord<TData, TKey>* FindRecord(TKey key);
	virtual void InsertRecord(TKey key, TData data);
	virtual void RemoveRecord(TKey key);
	void Clear();
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
	friend std::ostream& operator<<(std::ostream& out, const TTableHash& records)
	{
		int i = 0;
		while (i < records.tabSize)
		{
			if((records.records[i] != nullptr) && (records.records[i]->key != "zero"))
			out << "Key:" << records.records[i]->key << " Polinom: " << *(records.records[i]->data) << '\n';
			i++;
		}
		if (records.dataCount == 0)
			out << "Table is Empty\n";
		return out;
	}
};

template<typename TData, typename TKey>
unsigned long TTableHash<TData, TKey>::HashFunc(const TKey key)
{
    unsigned long h = 0;
    for (int i = 0; i < key.length(); i++)
    {
        h = (h << 3) + int(key[i]);
    }
    return h % this->tabSize;
}

template <typename TData, typename TKey>
TTableHash<TData, TKey>::TTableHash(int _tabSize, int _hashStep) : TTable<TData, TKey>(_tabSize)
{
	this->records = new TTabRecord<TData, TKey>*[this->tabSize];
	this->tabSize = _tabSize;
	hashStep = _hashStep;
	for (int i = 0; i < tabSize; i++)
	{
		this->records[i] = nullptr;
	}
	this->currPos = this->dataCount;
	pMark = new TTabRecord<TData, TKey>("zero");
}

template <typename TData, typename TKey>
TTabRecord<TData, TKey>* TTableHash<TData, TKey>::FindRecord(TKey key)
{
	TTabRecord<TData, TKey>* rec = NULL; 
	this->freePos = -1;
	this->currPos = HashFunc(key) % this->tabSize;
	for (int i = 0; i < this->tabSize; i++) {
		if (this->records[this->currPos] == NULL) 
			break;
		else if (this->records[this->currPos] == this->pMark)
		{
			if (this->freePos == -1) this->freePos = this->currPos;
		}
		else if (this->records[this->currPos] != nullptr && this->records[this->currPos]->key == key)
		{
			rec = this->records[this->currPos]; break;
		}
		this->currPos = GetNextPos(this->currPos);
	}
	return rec;
}

template <typename TData, typename TKey>
void TTableHash<TData, TKey>::InsertRecord(TKey key, TData data)
{
	if (this->IsFull() == 0 && FindRecord(key) == NULL && this->freePos < 0)
	{
		this->records[this->currPos] = new TTabRecord<TData, TKey>(data, key);
		this->dataCount++;
	}
	else if (this->IsFull() == 0 && FindRecord(key) == NULL && this->freePos > -1)
	{
		this->records[this->freePos] = new TTabRecord<TData, TKey>(data, key);
		this->dataCount++;
	}
}

template <typename TData, typename TKey>
void TTableHash<TData, TKey>::RemoveRecord(TKey key)
{
	TTabRecord<TData, TKey>* rec = FindRecord(key);
	if (rec != NULL)
	{
		delete this->records[this->currPos];
		this->records[this->currPos] = this->pMark;
		this->dataCount--;
	}
}

template <typename TData, typename TKey>
void TTableHash<TData, TKey>::Clear()
{
	this->Reset();
	while (this->currPos < this->tabSize)
	{
		if(this->records[this->currPos] != nullptr)
		this->records[this->currPos] = pMark;
		this->currPos++;
	}
	this->dataCount = 0;
}