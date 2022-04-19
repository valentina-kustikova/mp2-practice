#pragma once
#include "ScanTable.h"

template <class TKey, class TData>
class SortTable : public ScanTable<TKey, TData>
{
protected:
    void SortData()
    {
        for (int i = 0; i < this->DataCount - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < this->DataCount; j++)
            {
                if (*(this->Recs[j]) < *(this->Recs[min]))
                    min = j;
            }
            std::swap(this->Recs[i], this->Recs[min]);
        }
    }
public:
    SortTable(int size = 25) : ScanTable<TKey, TData>(size) {}
    SortTable(const ScanTable<TKey, TData>& st)
        : ScanTable<TKey, TData> (st)
    {
        SortData();
    }
    virtual TData* Find(const TKey& k)
    {
        int left = 0;
        int right = this->DataCount - 1;
        int mid = 0;

        while (left <= right)
        {
            mid = (left + right) >> 1;

            if (this->Recs[mid]->GetKey() == k)
            {
                left = mid + 1;
                right = mid;
            }
            else if (this->Recs[mid]->GetKey() > k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (right < 0 || this->Recs[right]->GetKey() < k)
            right++;
        this->CurrPos = right;

        if (right < this->DataCount && this->Recs[mid]->GetKey() == k)
            return this->Recs[mid]->GetData();
        else
            return nullptr;
    }
    virtual void Insert(const TKey& k, const TData& d)
    {
        if (!this->isFull())
        {
           if (Find(k) == nullptr)
           {
               for (int i = this->DataCount; i > this->CurrPos; i--)
                   this->Recs[i] = this->Recs[i - 1];
               this->Recs[this->CurrPos] = new TabRecord<TKey, TData>(k, d);
               this->DataCount++;
           }
        }
    }
    virtual void Delete(const TKey& k)
    {
        if (Find(k) != nullptr)
        {
            delete this->Recs[this->CurrPos];
            for (int i = this->CurrPos; i < this->DataCount-1; i++)
                this->Recs[i] = this->Recs[i + 1];

            this->Recs[--this->DataCount] = nullptr;
        }
    }
};
