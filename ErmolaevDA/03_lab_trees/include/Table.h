#pragma once
#include "TabRecord.h"
#include <iostream>
using namespace std;


//Класс Таблица
template <typename TData, typename TKey> class Table
{
//protected
  public:
  TabRecord<TData,TKey>** records;
  int tabSize;
  int dataCount ;
  int currPos;
  // Конструкторы, деструктор    
  Table(unsigned int n = 100);

  virtual ~Table() { delete[] records; }
  //public:
  //информационные методы
  bool IsFull() const { return dataCount  == tabSize; }
  bool IsEmpty() const { return dataCount  == 0; }
  int GetCount() const { return dataCount; }
  int GetSize() const { return tabSize; }

  // операции над таблицами
  virtual void InsertRecord(const TData Data, const TKey Key) = 0;
  virtual void RemoveRecord(const TKey Key) = 0;
  virtual TData* FindRecord(const TKey Key) = 0;
  virtual void Clear() =0;
  //навигация по таблицу
  void Reset();
  void SetNext();
  bool IsTabEnded() const { return currPos == dataCount  || currPos == -1; }

  //доступ к текущей записи таблицы
  TData* GetData() const; // для текущего элемента
  TKey GetKey() const;  // для текущего элемента

  friend std::ostream& operator<< (std::ostream& os, const Table<TData,TKey>& Tab)
  { unsigned int i = 0;
    while (i < Tab.dataCount)
    { os <<"Key:"<< left << Tab.records[i]->GetKey() << " | Data: " << *(Tab.records[i]->GetData()) << '\n';
      i++;
    }
    if (Tab.dataCount == 0)
    os << "\n\tTable is Empty\n";
    return os;
  }
  friend TabRecord<TData, TKey>;
};


template <typename TData, typename TKey>
Table<TData, TKey>::Table(unsigned int n)
{
    tabSize = n;
    dataCount = 0;
    currPos = -1;
    records = new TabRecord<TData, TKey>*[tabSize];
}
// Методы 
template <typename TData, typename TKey>
void Table<TData, TKey>::Reset()
{
    if (dataCount > 0)
    {
        currPos = 0;
    }
    else
    {
        currPos = -1;
    }
}
template <typename TData, typename TKey>
void Table<TData, TKey>::SetNext()
{
    try {
        if (currPos != -1) { currPos++; }
        else { throw "Table Table is Empty, cannot use SetNext"; } //Таблица пуста
        if (IsTabEnded()) { Reset(); }
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
}
template <typename TData, typename TKey>
TData* Table<TData, TKey>::GetData() const
{    
    try {
        if (!IsEmpty())
        {
            return records[currPos]->data; //GetData();
        }
        else
        {
            throw "Table Table is Empty, cannot block GetData";

        } //Таблица пуста
    }
    catch(const char* exception){
        std::cerr << "Error: " << exception << '\n';
    }
}
template <typename TData, typename TKey>
TKey Table<TData, TKey>::GetKey() const
{
    try {
        if (!IsEmpty())
        {
            return records[currPos]->GetKey();
        }
        else
        {
            throw "Table Table Is Empty, Cannot GetKey";
        } //Таблица пуста
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
}

