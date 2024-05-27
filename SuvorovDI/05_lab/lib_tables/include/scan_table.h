#pragma once

#include <iostream>
#include "table.h"

template <typename TKey, typename TData>
class ScanTable : public Table<TKey, TData>
{
protected:
  TabRecord<TKey, TData> **recs;

public:
  ScanTable(int maxSize);
  ScanTable(const ScanTable<TKey, TData> &t);
  ~ScanTable() override {
    if (!IsEmpty())
      for (int i = 0; i < count; i++)
      {
        delete recs[i];
      }
    delete[] recs;
  }

  TabRecord<TKey, TData>* Find(TKey key) override; // const??
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
    return currPos == count - 1;
  }

  friend std::ostream& operator<<(std::ostream& out, const ScanTable<TKey, TData>& t)
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
ScanTable<TKey, TData>::ScanTable(int size) : Table<TKey, TData>(size)
{
  recs = new TabRecord<TKey, TData>* [size];
}

template <typename TKey, typename TData>
ScanTable<TKey, TData>::ScanTable(const ScanTable<TKey, TData>& t) : Table<TKey, TData>(t.maxSize)
{
  if (t.IsEmpty())
  {
    recs = new TabRecord<TKey, TData>* [maxSize];
    return;
  }

  count = t.count;
  currPos = 0;
  recs = new TabRecord<TKey, TData>* [maxSize];

  for (int i = 0; i < count; i++)
  {
    recs[i] = new TabRecord<TKey, TData>(t.recs[i]->key, t.recs[i]->data);
  }
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ScanTable<TKey, TData>::Find(TKey key)
{
  if (IsEmpty())
    return nullptr;

  for (int i = 0; i < count; i++)
  {
    if (recs[i]->key == key)
    {
      currPos = i;
      return recs[i];
    }
  }
  return nullptr;
}

template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Insert(TKey key, TData* data)
{
  if (IsFull())
    throw std::exception("table is full\n");
  if (Find(key) != nullptr)
    throw std::exception("record with this key already existed\n");
  TabRecord<TKey, TData>* res = new TabRecord<TKey, TData>(key, data);
  currPos = count;
  recs[count++] = res;
}

template <typename TKey, typename TData>
void ScanTable<TKey, TData>::Remove(TKey key)
{
  if (IsEmpty())
    throw std::exception("table is empty\n");
  if (Find(key) == nullptr)
    throw std::exception("no such element\n");

  delete recs[currPos];
  recs[currPos] = recs[--count];
}