#pragma once
#include "Table.h" 

//Класс Просматриваемых таблиц
template <typename TData, typename TKey>
class ScanTable : public Table<TData,TKey>
{ public: 
    
  // Конструкторы, деструктор	
  ScanTable(unsigned int n = 100) : Table<TData,TKey>(n) {};
  ScanTable(const ScanTable<TData,TKey>& T1);
  ~ScanTable() {};
  // Методы 
  virtual void InsertRecord(const TData Data, const TKey Key);
  virtual TData* FindRecord(const TKey Key);
  virtual void RemoveRecord(const TKey Key);
}; 

// Pелизация функциий для класса росматриваемых таблиц
// Конструктор
template <typename TData, typename TKey>
ScanTable<TData, TKey>::ScanTable(const ScanTable<TData, TKey>& T1)
{
    this->tabSize = T1.tabSize;
    this->dataCount = T1.dataCount;
    this->currPos = T1.currPos;
    this->records = new TabRecord<TData, TKey>*[this->tabSize];
    for (int i = 0; i < this->dataCount; i++)
    {
        this->records[i] = new TabRecord<TData, TKey>(*(T1.records[i]));
    }
}
// Методы 
template <typename TData, typename TKey>
void ScanTable<TData, TKey>::InsertRecord(const TData Data, const TKey Key)
{
    if (this->IsFull())
    {
        throw 1;
    } //Таблица переполнена
    TabRecord<TData, TKey> R(Key, Data);
    this->Reset();
    if ((this->IsEmpty()) || (FindRecord(Key) == nullptr))
    {
        this->records[this->dataCount] = new TabRecord<TData, TKey>(R);
        this->dataCount++;
    }
    else
    {
        throw 1;
    } // Повторная вставка элемента
    this->Reset();
}
template <typename TData, typename TKey>
TData* ScanTable<TData, TKey>::FindRecord(const TKey Key)
{
    if (this->IsEmpty())
    {
        throw 1;
    } //таблица пуста 
    this->Reset();
    while (!(this->IsTabEnded()) && Key != this->records[this->currPos]->GetKey())
    {
        this->currPos++;
    }
    if (!(this->IsTabEnded()))
    {
        return this->records[this->currPos]->GetData();
    }
    else
    {
        return nullptr;
    }
}
template <typename TData, typename TKey>
void ScanTable<TData, TKey>::RemoveRecord(TKey Key)
{
    if (FindRecord(Key) == nullptr)
    {
        throw 1;
    } // элемента для удаления нет в таблице
    else
    {
        this->records[this->currPos] = new TabRecord<TData, TKey>(*this->records[this->dataCount - 1]);
        this->records[this->dataCount - 1] = NULL;
        this->dataCount = this->dataCount - 1;
        this->currPos = this->dataCount - 1;
    }
}

