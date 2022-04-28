#pragma once
template <typename TData, typename TKey>
class TabRecord
{ public:
  TKey key;
  TData* data;
  // Конструкторы, деструктор    
  TabRecord(TKey k = {}, TData d = {}) { key = k; data = new TData(d); }
  TabRecord(const TabRecord& T1) { key = T1.key; data = new TData(*(T1.data)); } // конструктор копирования
  ~TabRecord() { delete data; }
  //Методы
  TData* GetData() const { return data; }
  TKey GetKey() const { return key; }
  // Перегрузка операций
  TabRecord<TData,TKey>& operator=(const TabRecord<TData,TKey>& TabR)
  { data = new TData(*(TabR.data)); key = TabR.key; return *this; }
};

