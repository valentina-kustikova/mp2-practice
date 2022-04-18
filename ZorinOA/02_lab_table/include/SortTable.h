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
                if (*(Recs[j]) < *(Recs[min]))
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
        int right = DataCount - 1;
        int mid = 0;

        while (left <= right)
        {
            mid = (left + right) >> 1;

            if (Recs[mid]->GetKey() == k)
            {
                left = mid + 1;
                right = mid;
            }
            else if (Recs[mid]->GetKey() > k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (right < 0 || Recs[right]->GetKey() < k)
            right++;
        CurrPos = right;

        if (right < DataCount && Recs[mid]->GetKey() == k)
            return Recs[mid]->GetData();
        else
            return nullptr;
    }
    virtual void Insert(const TKey& k, const TData& d)
    {
        if (!isFull())
        {
           if (Find(k) == nullptr)
           {
               for (int i = DataCount; i > CurrPos; i--)
                   Recs[i] = Recs[i - 1];
               Recs[CurrPos] = new TabRecord<TKey, TData>(k, d);
               DataCount++;
           }
        }
    }
    virtual void Delete(const TKey& k)
    {
        if (Find(k) != nullptr)
        {
            delete Recs[CurrPos];
            for (int i = CurrPos; i < DataCount-1; i++)
                Recs[i] = Recs[i + 1];

            Recs[--DataCount] = nullptr;
        }
    }
};
