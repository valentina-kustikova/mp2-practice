#ifndef _LISTHASHTABLE_H_
#define _LISTHASHTABLE_H_

#include "hashtable.h"
#include "tabrecordlist.h"

template<typename TKey, class TData>
class TListHashTable : public THashTable<TKey, TData>
{
protected:
	TTabRecordList<TKey, TData>** pRecs;

public:
	TListHashTable(int _size);
	~TListHashTable();

	bool IsFull() const override;

	TTabRecord<TKey, TData>* FindRecord(const TKey _key) override;
	void InsertRecord(const TKey _key, TData* _data = nullptr) override;
	void RemoveRecord(const TKey _key) override;

	bool Reset() override;
	bool GetNext() override;

	TTabRecord<TKey, TData>* GetRecord() const override;
	TKey GetKey() const override;
	TData* GetData() const override;
};
//-------------------------------------------------------

template<typename TKey, class TData>
TListHashTable<TKey, TData>::TListHashTable(int _size) : THashTable<TKey, TData>(_size)
{
	this->currPos = 0;
	pRecs = new TTabRecordList<TKey, TData>* [_size];
	for (int i = 0; i < this->tabSize; i++)
		pRecs[i] = new TTabRecordList<TKey, TData>;
};

template<typename TKey, class TData>
TListHashTable<TKey, TData>::~TListHashTable()
{
	for (int i = 0; i < this->tabSize; i++)
		delete pRecs[i];

	delete[] pRecs;
};
//---------------------------------------------------------

template<typename TKey, class TData>
bool TListHashTable<TKey, TData>::IsFull() const
{
	TTabRecordList<TKey, TData>* tmp = new TTabRecordList<TKey, TData>;

	if (tmp)
	{
		delete tmp;
		return false;
	}
	else return true;
};

template<typename TKey, class TData>
TTabRecord<TKey, TData>* TListHashTable<TKey, TData>::FindRecord(const TKey _key)
{
	if (this->IsEmpty())
		throw Exception("Table is empty!");

	TTabRecord<TKey, TData>* record = nullptr;
	
	int k = this->HashFunction(_key) % this->tabSize;

	for (pRecs[k]->Reset(); !pRecs[k]->IsEnded(); pRecs[k]->Next())
	{
		if (pRecs[k]->GetCurrent()->GetKey() == _key)
		{
			record = (TTabRecord<TKey, TData>*)(pRecs[k]->GetCurrent());
			break;
		}
	}

	return record;
};

template<typename TKey, class TData>
void TListHashTable<TKey, TData>::InsertRecord(const TKey _key, TData* _data)
{
	if (IsFull())
		throw Exception("Table is full!");

	int k = this->HashFunction(_key) % this->tabSize;

	for (pRecs[k]->Reset(); !pRecs[k]->IsEnded(); pRecs[k]->Next())
	{
		if (pRecs[k]->GetCurrent()->GetKey() == _key)
		{
			pRecs[k]->GetCurrent()->SetData(_data);
			return;
		}
	}

	pRecs[k]->PushEnd(_key, _data);
	this->dataCount++;
};

template<typename TKey, class TData>
void TListHashTable<TKey, TData>::RemoveRecord(const TKey _key)
{
	if (this->IsEmpty())
		throw Exception("Table is empty!");

	int k = this->HashFunction(_key) % this->tabSize;
	
	if (pRecs[k]->IsEmpty())
		throw Exception("Record with this key was not found!");

	
	pRecs[k]->Delete(_key);
	this->dataCount--;
};

template<typename TKey, class TData>
bool TListHashTable<TKey, TData>::Reset()
{
	for (this->currPos = 0; this->currPos < this->tabSize; this->currPos++)
	{
		if (!(pRecs[this->currPos]->IsEmpty()))
		{
			pRecs[this->currPos]->Reset();
			break;
		}
	}

	return this->IsTabEnded();
};

template<typename TKey, class TData>
bool TListHashTable<TKey, TData>::GetNext()
{
	if (!(this->IsTabEnded()))
	{
		pRecs[this->currPos]->Next();

		if (!(pRecs[this->currPos]->IsEnded()))
			return this->IsTabEnded();

		for (++(this->currPos); this->currPos < this->tabSize; this->currPos++)
		{
			if (!(pRecs[this->currPos]->IsEmpty()))
			{
				pRecs[this->currPos]->Reset();
				break;
			}
		}
	}

	return this->IsTabEnded();
};

template<typename TKey, class TData>
TTabRecord<TKey, TData>* TListHashTable<TKey, TData>::GetRecord() const
{
	if ((this->currPos < 0) || (this->currPos >= this->tabSize))
		return nullptr;

	return (TTabRecord<TKey, TData>*)(pRecs[this->currPos]->GetCurrent());
};

template<typename TKey, class TData>
TKey TListHashTable<TKey, TData>::GetKey() const
{
	if ((this->currPos < 0) || (this->currPos >= this->tabSize))
		return 0;

	return (pRecs[this->currPos]->GetCurrent()->GetKey());
};

template<typename TKey, class TData>
TData* TListHashTable<TKey, TData>::GetData() const
{
	if ((this->currPos < 0) || (this->currPos >= this->tabSize))
		return 0;

	return (pRecs[this->currPos]->GetCurrent()->GetData());
};

#endif
