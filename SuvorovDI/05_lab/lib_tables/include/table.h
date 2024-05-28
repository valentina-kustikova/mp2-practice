#pragma once

#include <iostream>

template <typename TKey, typename TData>
struct TabRecord
{
  TKey key;
  TData *data;

  TabRecord()
  {
    this->key = TKey();
    this->data = nullptr;
  }

  TabRecord(TKey key, TData *data)
  {
    this->key = key;
    this->data = new TData(*data);
  }

  TabRecord<TKey, TData>& operator=(const TabRecord<TKey, TData> &r)
  {
    if (this == &r) 
      return *this;
    
    key = r.key;
    data = new TData(r.data);
    return *this;
  }

  bool operator==(const TabRecord<TKey, TData> &r) const
  {
    return (key == r.key) && (*data == *r.data);
  }

  TData* GetData() const {
    return data;
  }

  friend std::ostream& operator<<(std::ostream& out, const TabRecord<TKey, TData>& r)
  {
    out << "KEY: " << r.key << " -> VALUE:\n" << *r.data << "\n";
    return out;
  }
};

template <typename TKey, typename TData>
class Table
{
protected:
  int count;
  int maxSize;
  int currPos;

public:
  Table(int maxSize)
  {
    if (maxSize < 0)
      throw std::exception("negative_table_max_size\n");

    this->maxSize = maxSize;
    count = 0;
    currPos = -1;
  }
  virtual ~Table() = 0;
  virtual TabRecord<TKey, TData> *Find(TKey key) = 0;
  virtual void Insert(TKey key, TData *data) = 0;
  virtual void Remove(TKey key) = 0;
  bool IsFull() const noexcept
  {
    return count == maxSize;
  }
  bool IsEmpty() const noexcept
  {
    return count == 0;
  }
  void Reset() noexcept
  {
    currPos = 0;
  }
  virtual bool IsEnded() const noexcept
  {
    return currPos == maxSize; // general case
  }
  virtual void Next()
  {
    if (IsEnded())
      throw std::exception("table is ended");
    currPos += 1;
  }
  virtual TabRecord<TKey, TData>* GetCurrent() const = 0;
};

template <typename TKey, typename TData>
Table<TKey, TData>::~Table() {}