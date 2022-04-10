#pragma once
#include "Table.h" 

//Класс Просматриваемых таблиц
template <typename TData, typename TKey>
class ScanTable : public Table<TData,TKey>
{ public: 
    
  // Конструкторы, деструктор	
  ScanTable(unsigned int n = 10) : Table<TData,TKey>(n) {};
  ScanTable(const ScanTable<TData,TKey>& T1);
  ~ScanTable() {};
  // Методы 
  virtual void Insert(const TData Data, const TKey Key);
  virtual TData* Search(const TKey Key);
  virtual void Delete(const TKey Key);
}; 

// Pелизация функциий для класса росматриваемых таблиц
// Конструктор
template <typename TData, typename TKey>
ScanTable<TData, TKey>::ScanTable(const ScanTable<TData, TKey>& T1)
{
    this->Size = T1.Size;
    this->dataCount = T1.dataCount;
    this->ind = T1.ind;
    this->rec = new TabRecord<TData, TKey>*[this->Size];
    for (int i = 0; i < this->dataCount; i++)
    {
        this->rec[i] = new TabRecord<TData, TKey>(*(T1.rec[i]));
    }
}
// Методы 
template <typename TData, typename TKey>
void ScanTable<TData, TKey>::Insert(const TData Data, const TKey Key)
{
    if (this->IsFull())
    {
        throw 1;
    } //Таблица переполнена
    TabRecord<TData, TKey> R(Key, Data);
    this->Reset();
    if ((this->IsEmpty()) || (Search(Key) == nullptr))
    {
        this->rec[this->dataCount] = new TabRecord<TData, TKey>(R);
        this->dataCount++;
    }
    else
    {
        throw 1;
    } // Повторная вставка элемента
    this->Reset();
}
template <typename TData, typename TKey>
TData* ScanTable<TData, TKey>::Search(const TKey Key)
{
    if (this->IsEmpty())
    {
        throw 1;
    } //таблица пуста 
    this->Reset();
    while (!(this->IsEnd()) && Key != this->rec[this->ind]->GetKey())
    {
        this->ind++;
    }
    if (!(this->IsEnd()))
    {
        return this->rec[this->ind]->GetData();
    }
    else
    {
        return nullptr;
    }
}
template <typename TData, typename TKey>
void ScanTable<TData, TKey>::Delete(TKey Key)
{
    if (Search(Key) == nullptr)
    {
        throw 1;
    } // элемента для удаления нет в таблице
    else
    {
        this->rec[this->ind] = new TabRecord<TData, TKey>(*this->rec[this->dataCount - 1]);
        this->rec[this->dataCount - 1] = NULL;
        this->dataCount = this->dataCount - 1;
        this->ind = this->dataCount - 1;
    }
}

