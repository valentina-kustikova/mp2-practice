#ifndef _SORT_TABLE_H
#define _SORT_TABLE_H

#include "ScanTable.h"

template <typename TKey, typename TData>
class SortedTable : public ScanTable<TKey, TData> {
private:
    void QuickSort(TabRecord<TKey, TData>** arr, int left, int right);
public:
    SortedTable(int maxSize);
    SortedTable(const ScanTable<TKey, TData>& table);

    TabRecord<TKey, TData>* Find(TKey key) override;
    void Insert(TKey key, TData* data) override;
    void Remove(TKey key);
};


template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(int maxSize) : ScanTable<TKey, TData>(maxSize) {}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(const ScanTable<TKey, TData>& table) : ScanTable<TKey, TData>(table) {
    if (!IsEmpty()) {
        QuickSort(recs, 0, count - 1);
    }
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* SortedTable<TKey, TData>::Find(TKey key) {
    int left = 0, right = count - 1;
    TabRecord<TKey, TData>* search = nullptr;

    while (left <= right) {
        int mid = (right + left) / 2;

        if (recs[mid]->key == key) {
            search = recs[mid];
            right = mid;
            left = mid + 1;
        }
        else if (recs[mid]->key < key) left = mid + 1;
        else right = mid - 1;
    }
    if (right != -1)
        if (search == nullptr)
            currPos = right + 1;
        else
            currPos = right;
    else
        currPos = 0;
    return search;
}


template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Insert(TKey key, TData* data) {
    if (IsFull()) 
        throw "ERROR: Table is full.";

    if (Find(key) != nullptr) {
        throw "Key repeat, it's not good";
    }
    for (int i = count - 1; i >= currPos; i--) {
        recs[i + 1] = recs[i];
    }
    recs[currPos] = new TabRecord<TKey, TData>(key, data);

    count++;
}


template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Remove(TKey key) {
    if (IsEmpty()) {
        throw "ERROR: Table is empty.";
    }

    TabRecord<TKey, TData>* rec = Find(key);
    if (rec == nullptr) {
        throw "ERROR: Key not found.";
    }
    delete rec;
    for (int i = currPos; i < count - 1; i++) {
        recs[i] = recs[i + 1];
    }
    count--;
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::QuickSort(TabRecord<TKey, TData>** arr, int left, int right) {
    if (left >= right)  return;

    int i = left;
    int j = right;

    TabRecord<TKey, TData>* middle = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i]->GetKey() < middle->GetKey())
            i++;
        while (arr[j]->GetKey() > middle->GetKey())
            j--;
        if (i <= j) {
            TabRecord<TKey, TData>* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    QuickSort(arr, left, j);
    QuickSort(arr, i, right);
}


#endif 