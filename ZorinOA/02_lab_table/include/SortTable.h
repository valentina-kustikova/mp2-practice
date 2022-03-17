#pragma once
#include "ArrayTable.h"
#include "ScanTable.h"

template <class TKey, class TData>
class SortTable : public ArrayTable<TKey, TData>
{
public:
    SortTable(int size = MAX_SIZE) : ArrayTable<TKey, TData>(size) {}
    virtual TData* Find(const TKey& k)
    {
        int left = 0;
        int right = this->DataCount - 1;

        while (left <= right)
        {
            int mid = (left + right) >> 1;

            if (this->Recs[mid].GetKey() == k)
                return &(this->Recs[mid].GetData());
            if (this->Recs[mid].GetKey() > k)
                right = mid - 1;
            else
                left = mid + 1;

        }

        return nullptr;
    }
    virtual void Insert(const TKey& k, const TData& d)
    {
        if (!this->isFull())
        {
            int l = 0, r = this->DataCount - 1;

            while (l <= r)
            {
                int m = (l + r) >> 1;
                if (this->Recs[m].GetKey() == k)
                {
                    l = m + 1;
                    r = m;
                }
                else if (this->Recs[m].GetKey() > k)
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            if (r < 0 || this->Recs[r].GetKey() < k)
                r++;

            for (int i = this->DataCount; i > r; i--)
            {
                this->Recs[i] = this->Recs[i-1];
            }
            this->Recs[r] = TabRecord<TKey, TData>(k, d);
            DataCount++;
        }
    }
    virtual void Delete(const TKey& k)
    {

        int l = 0, r = this->DataCount - 1, m = 0;
        bool find = false;
        while (l < r || !find)
        {
            m = (l + r) >> 1;
            if (this->Recs[m].GetKey() == k)
            {
                find = true;
            }
            else if (this->Recs[m].GetKey() > k)
                r = m - 1;
            else
                l = m + 1;
        }

        if (find)
        {
            this->DataCount--;
            for (int i = m; i < this->DataCount; i++)
            {
                this->Recs[i] = this->Recs[i+1];
            }

        }
    }
};
