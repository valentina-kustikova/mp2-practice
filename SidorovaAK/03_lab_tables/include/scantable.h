#ifndef _SCANTABLE_H_
#define _SCANTABLE_H_

#include "arraytable.h"

template<typename TKey, class TData>
class TScanTable : public TArrayTable<TKey, TData>
{
public:
    TScanTable() : TArrayTable<TKey, TData>() {};
    TScanTable(int _size) : TArrayTable<TKey, TData>(_size) {};

    virtual TTabRecord<TKey, TData>* FindRecord(const TKey _key) override;
    virtual void InsertRecord(const TKey _key, TData* _data = nullptr) override;
    virtual void RemoveRecord(const TKey _key) override;
};
//-----------------------------------------------

template<typename TKey, class TData>
TTabRecord<TKey, TData>* TScanTable<TKey, TData>::FindRecord(const TKey _key)
{
    for (int i = 0; i < this->dataCount; i++)
    {
        if (this->pRecs[i]->GetKey() == _key)
        {
            this->currPos = i;
            return this->pRecs[i];
        }
    }

    return nullptr;
};

template<typename TKey, class TData>
void TScanTable<TKey, TData>::InsertRecord(const TKey _key, TData* _data)
{
    if (this->IsFull())
        throw Exception("Table is full!");
    
    this->pRecs[this->dataCount++] = new TTabRecord<TKey, TData>(_key, _data);
};

template<typename TKey, class TData>
void TScanTable<TKey, TData>::RemoveRecord(const TKey _key)
{
    if (this->IsEmpty())
        throw Exception("Table is empty!");

    if (!(this->FindRecord(_key)))
        throw Exception("A record with this key is not in the table.");

    delete this->pRecs[this->currPos];
    this->pRecs[this->currPos] = this->pRecs[--(this->dataCount)];
    this->pRecs[this->dataCount] = nullptr;
};

#endif