#ifndef _ARRAYHASHTABLE_H_
#define _ARRAYHASHTABLE_H_

#include "hashtable.h"
#include "tabrecord.h"

template<typename TKey, class TData>
class TArrayHashTable : public THashTable<TKey, TData>
{
protected:
	TTabRecord<TKey, TData>** pRecs;
	int hashStep;
	int freePos;
	TTabRecord<TKey, TData>* pMark;

	int GetNextPos(int _pos) const { return (_pos + hashStep) % this->tabSize; }

public:
	TArrayHashTable(int _tabSize, int _hashStep);
	~TArrayHashTable();

	TTabRecord<TKey, TData>* FindRecord(const TKey _key) override;
	void InsertRecord(const TKey _key, TData* _data = nullptr) override;
	void RemoveRecord(const TKey _key) override;

	bool Reset() override;
	bool GetNext() override;

	TTabRecord<TKey, TData>* GetRecord() const override;
	TKey GetKey() const override;
	TData* GetData() const override;
};
//----------------------------------------------

template<typename TKey, class TData>
TArrayHashTable<TKey, TData>::TArrayHashTable(int _tabSize, int _hashStep)
	: THashTable<TKey, TData>(_tabSize)
{
	hashStep = _hashStep;
	freePos = 0;
	pRecs = new TTabRecord<TKey, TData>*[this->tabSize];
	for (int i = 0; i < this->tabSize; i++) pRecs[i] = nullptr;
	pMark = new TTabRecord<TKey, TData>();
};

template<typename TKey, class TData>
TArrayHashTable<TKey, TData>::~TArrayHashTable()
{
	hashStep = 0;
	freePos = 0;
	for (int i = 0; i < this->tabSize; i++)
		if (pRecs[i] && (pRecs[i] != pMark))
			delete pRecs[i];
	
	delete pRecs;
	delete pMark;
};
//----------------------------------------------

template<typename TKey, class TData>
TTabRecord<TKey, TData>* TArrayHashTable<TKey, TData>::FindRecord(const TKey _key)
{
	TTabRecord<TKey, TData>* record = nullptr;
	this->currPos = this->HashFunction(_key) % this->tabSize;
	freePos = -1;

	for (int i = 0; i < this->tabSize; i++)
	{
		if (!pRecs[this->currPos])
		{
			if (freePos == -1)
				freePos = this->currPos;
			break;
		}
		else if (pRecs[this->currPos] == pMark)
		{
			if (freePos == -1)
				freePos = this->currPos;
		}
		else if (pRecs[this->currPos]->GetKey() == _key)
		{
			record = pRecs[this->currPos];
			break;
		}

		this->currPos = GetNextPos(this->currPos);
	}

	return record;
};

template<typename TKey, class TData>
void TArrayHashTable<TKey, TData>::InsertRecord(const TKey _key, TData* _data)
{
	if (this->IsFull())
		throw Exception("Table is full!");

	if (FindRecord(_key))
		throw Exception("Tab record with this key is already in the table!");

	if (freePos != -1)
	{
		this->currPos = freePos;
		pRecs[this->currPos] = new TTabRecord<TKey, TData>(_key, _data);
		this->dataCount++;
		freePos = -1;
	}
};

template<typename TKey, class TData>
void TArrayHashTable<TKey, TData>::RemoveRecord(const TKey _key)
{
	if (this->IsEmpty())
		throw Exception("Table is empty!");

	TTabRecord<TKey, TData>* record = FindRecord(_key);

	if (record)
	{
		delete pRecs[this->currPos];
		pRecs[this->currPos] = pMark;
		this->dataCount--;
	}
};

template<typename TKey, class TData>
bool TArrayHashTable<TKey, TData>::Reset()
{
	this->currPos = 0;

	while (!(this->IsTabEnded()))
	{
		if (pRecs[this->currPos] && (pRecs[this->currPos] != pMark))
			break;
		else
			this->currPos++;
	}

	return this->IsTabEnded();
};

template<typename TKey, class TData>
bool TArrayHashTable<TKey, TData>::GetNext()
{
	if (!(this->IsTabEnded()))
	{
		while (++(this->currPos) < this->tabSize)
		{
			if (pRecs[this->currPos] && (pRecs[this->currPos] != pMark))
				break;
		}
	}

	return this->IsTabEnded();
};

template<typename TKey, class TData>
TTabRecord<TKey, TData>* TArrayHashTable<TKey, TData>::GetRecord() const
{
	return ((this->currPos < 0) || (this->currPos >= this->tabSize)) ? nullptr : pRecs[this->currPos];
};

template<typename TKey, class TData>
TKey TArrayHashTable<TKey, TData>::GetKey() const
{
	return ((this->currPos < 0) || (this->currPos >= this->tabSize)) ? 0 : 
		pRecs[this->currPos]->GetKey();
};

template<typename TKey, class TData>
TData* TArrayHashTable<TKey, TData>::GetData() const
{
	return ((this->currPos < 0) || (this->currPos >= this->tabSize)) ? nullptr :
		pRecs[this->currPos]->GetData();
};

#endif