#pragma once

#include "table.h"
#include "scan_table.h"

template <typename TKey, typename TData>
class SortedTable : public ScanTable<TKey, TData>
{
private:
  void QuickSort(TabRecord<TKey, TData> **rec_arr, int size);

public:
  SortedTable(int maxSize) : ScanTable(maxSize) {};
  SortedTable(const ScanTable<TKey, TData>*);
  TabRecord<TKey, TData> *Find(TKey key) override;
  void Insert(TKey key, TData *data) override;
  void Remove(TKey key) override;
  TabRecord<TKey, TData>* GetCurrent() const override
  {
    if (IsEmpty())
      throw std::exception("Table_is_empty\n");
    return recs[currPos];
  }
  bool IsEnded() const noexcept override
  {
    return currPos == count;
  }
  friend std::ostream& operator<<(std::ostream& out, const SortedTable<TKey, TData>& t)
  {
    if (t.IsEmpty())
    {
      out << "EMPTY_TABLE\n";
      return out;
    }

    ScanTable<TKey, TData> tmp(t);
    while (!tmp.IsEnded())
    {
      out << *tmp.GetCurrent();
      tmp.Next();
    }
    return out;
  }
};

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::QuickSort(TabRecord<TKey, TData> **rec_arr, int size)
{
  int i = 0;
  int j = size - 1;

  TabRecord<TKey, TData> *mid = rec_arr[size / 2];

  do
  {
    while (recs[i]->key < mid->key)
    {
      i++;
    }
    while (recs[j]->key > mid->key)
    {
      j--;
    }

    if (i <= j)
    {
      TabRecord<TKey, TData> *tmp = rec_arr[i];
      rec_arr[i] = rec_arr[j];
      rec_arr[j] = tmp;

      i++;
      j--;
    }
  } while (i <= j);

  if (j > 0)
  {
    QuickSort(rec_arr, j + 1);
  }
  if (i < size)
  {
    QuickSort(&rec_arr[i], size - i);
  }
}

template <typename TKey, typename TData>
SortedTable<TKey, TData>::SortedTable(const ScanTable<TKey, TData>* t) : ScanTable<TKey, TData>(*t)
{
  if (IsEmpty())
    return;

  this->QuickSort(this->recs, this->count);
}

template <typename TKey, typename TData>
TabRecord<TKey, TData> *SortedTable<TKey, TData>::Find(TKey key)
{
  int left = 0, right = count - 1;
  TabRecord<TKey, TData>* record = nullptr;
  while (left <= right)
  {
    int middle = (left + right) / 2;
    if (recs[middle]->key == key)
    {
      left = middle + 1;
      right = middle;
      record = recs[middle];
    }
    else if (recs[middle]->key > key)
      right = middle - 1;
    else
      left = middle + 1;
  }
  currPos = right;
  return record;
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Insert(TKey key, TData *data)
{
  if (IsFull())
    throw std::exception("table_is_full\n");
  if (Find(key) != nullptr)
    throw std::exception("record with this key already existed\n");

  for (int i = count - 1; i > currPos; i--)
  {
    recs[i + 1] = recs[i];
  }

  recs[++currPos] = new TabRecord<TKey, TData>(key, data);
  count++;
}

template <typename TKey, typename TData>
void SortedTable<TKey, TData>::Remove(TKey key)
{
  if (IsEmpty())
    throw std::exception("table_is_empty\n");

  TabRecord<TKey, TData>* res = Find(key);
  if (res == nullptr)
    throw std::exception("no_such_element\n");
  delete res;
  for (int i = currPos; i < count - 1; i++)
    recs[i] = recs[i + 1];
  count--;
}