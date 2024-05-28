#pragma once

#include <type_traits>
#include "table.h"

template <typename TKey, typename TData>
class HashTable : public Table<TKey, TData>
{
protected:
  virtual int hashFunc(const TKey key) {
    return std::hash<TKey>{}(key) % maxSize;
  }

public:
  HashTable(int n) : Table<TKey, TData>(n) {}
};

template <typename TKey, typename TData>
class ArrayHashTable : public HashTable<TKey, TData>
{
protected:
  TabRecord<TKey, TData>** recs;
  TabRecord<TKey, TData>* pMark;
  int freePos;
  int hashStep;

  int GetNextPos(int h_val) { return (h_val + hashStep) % maxSize; }
public:
  ArrayHashTable(int n, int step);
  ArrayHashTable(const ArrayHashTable<TKey, TData> &ahtable);
  ~ArrayHashTable();
  TabRecord<TKey, TData>* Find(const TKey key);
  void Insert(TKey key, TData *data);
  void Remove(TKey key);
  bool Reset();
  void Next();
  TabRecord<TKey, TData>* GetCurrent() const
  {
    if (IsEmpty())
      throw std::exception("Table_is_empty\n");
    return recs[currPos];
  }

  friend std::ostream& operator<<(std::ostream& out, const ArrayHashTable<TKey, TData>& aht)
  {
    if (aht.IsEmpty())
    {
      out << "the table is empty\n";
      return out;
    }

    ArrayHashTable<TKey, TData> tmp(aht);
    tmp.Reset();
    while (!tmp.IsEnded())
    {
      out << *tmp.GetCurrent();
      tmp.Next();
    }
    return out;
  }
};

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(int n, int step) : HashTable(n) {
  hashStep = step;
  recs = new TabRecord<TKey, TData>*[n];
  for (int i = 0; i < maxSize; i++)
  {
    recs[i] = nullptr;
  }
  pMark = new TabRecord<TKey, TData>();
  freePos = -1;
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::~ArrayHashTable()
{
  for (int i = 0; i < maxSize; i++)
  {
    if (recs[i] != nullptr && recs[i] != pMark) delete recs[i];
  }
  delete pMark;
  delete[] recs;
}

template <typename TKey, typename TData>
ArrayHashTable<TKey, TData>::ArrayHashTable(const ArrayHashTable<TKey, TData>& ahtable) : 
    ArrayHashTable<TKey, TData>(ahtable.maxSize, ahtable.hashStep) {
  if (ahtable.IsEmpty())
  {
    return;
  }

  count = ahtable.count;
  freePos = ahtable.freePos;
  for(int i = 0; i < maxSize; i++)
  {
    if (ahtable.recs[i] == nullptr) { recs[i] = nullptr; }
    else if (ahtable.recs[i] == ahtable.pMark) { recs[i] = pMark; }
    else { recs[i] = new TabRecord<TKey, TData>(ahtable.recs[i]->key, ahtable.recs[i]->data); }
  }
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>* ArrayHashTable<TKey, TData>::Find(const TKey key)
{
  TabRecord<TKey, TData> *res = nullptr;
  int hash_ind = hashFunc(key);
  freePos = -1;
  for (int i = 0; i < maxSize; i++)
  {
    if (recs[hash_ind] == nullptr)
    {
      if (freePos == -1)
        freePos = hash_ind;
      break;
    }
    else if (recs[hash_ind] == pMark)
    {
      if (freePos == -1)
        freePos = hash_ind;
    }
    else if (recs[hash_ind]->key == key)
    {
      res = recs[hash_ind];
      currPos = hash_ind;
      break;
    }

    hash_ind = GetNextPos(hash_ind);
  }

  return res;
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Insert(TKey key, TData *data) 
{
  if (IsFull()) throw std::exception("table_is_full\n");

  TabRecord<TKey, TData>* res = Find(key);
  if (freePos == -1)
    throw std::exception("there are no places\n");
  if (res != nullptr)
    throw std::exception("there is already such key. Key must have unique value \n");

  currPos = freePos;
  recs[currPos] = new TabRecord<TKey, TData>(key, data);
  count++;
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Remove(TKey key)
{
  if (IsEmpty()) throw std::exception("table is empty\n");

  TabRecord<TKey, TData>* res = Find(key);
  if (res == nullptr) throw std::exception("no such element\n");

  delete recs[currPos];
  recs[currPos] = pMark;
  count--;
}

template <typename TKey, typename TData>
bool ArrayHashTable<TKey, TData>::Reset()
{
  currPos = 0;
  while (!IsEnded())
  {
    if (recs[currPos] != nullptr && recs[currPos] != pMark)
      break;
    currPos++;
  }
  return IsEnded();
}

template <typename TKey, typename TData>
void ArrayHashTable<TKey, TData>::Next()
{   
  if (IsEnded())
    throw std::exception("table is ended\n");

  while (!IsEnded())
  {
    currPos++;
    if (recs[currPos] != nullptr && recs[currPos] != pMark)
      break;
  }
}

template <typename TData>
class StringHashTable : public ArrayHashTable<std::string, TData> {
  // DJB2 Algorithm
  int hashFunc(const std::string& key) const {
    int hash = 5381;
    for (char ch : str) {
      hash = ((hash << 5) + hash) + ch; // hash * 33 + ch
    }
    return hash % maxSize;
  }

public:
  StringHashTable(int n, int step) : ArrayHashTable<std::string, TData>(n, step) {}
};