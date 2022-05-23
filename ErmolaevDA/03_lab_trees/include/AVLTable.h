#pragma once
#include "Table.h" 
#include"AVLTree.h"
#include <iostream>
using namespace std;

//Класс таблиц на АВЛ деревьях
template <typename TData, typename TKey>
class AVLTable : public Table<TData, TKey>
{ 
protected:
  AVLTree<TData, TKey>* Dat;
  BalanceNode<TData,TKey>* Cur;
  public:
  // Конструкторы, деструктор	
  AVLTable() { Dat = new AVLTree<TData, TKey>; this->dataCount = 0; Cur=nullptr;}
  ~AVLTable(){ delete Dat; }
  // Методы 
  virtual void InsertRecord(const TData Data, const TKey Key);
  virtual TData* FindRecord(const TKey Key);
  virtual void RemoveRecord(const TKey Key);

  void Reset();
  void SetNext();
  bool IsTabEnded() const { return Dat->IsTabEnded(); }

  virtual void Clear();

  TData* GetData() const; // для текущего элемента
  TKey GetKey() const;  // для текущего элемента
  AVLTree<TData, TKey>* GetDat() { return Dat; };
//template<class TData>
  friend std::ostream& operator<< (std::ostream& os, const AVLTable<TData, TKey>& Tab)
  {
      if (Tab.dataCount == 0)
      { 
          os << "\n\tTable is Empty\n";
      }
      else 
      { 
          os << *(Tab.Dat); 
      }
      return os;
  }
  AVLTable<TData, TKey>& operator=(const AVLTable<TData, TKey>& T1)
  {
      Dat = new AVLTree<TData, TKey>(*(T1.Dat));
      this->dataCount = T1.dataCount;
      return *this;
  }
};

// Pелизация функциий для класса таблиц на АВЛ деревьях
// Методы 
template <typename TData, typename TKey>
void AVLTable<TData, TKey>::InsertRecord(const TData Data, const TKey Key)
{
    this->dataCount++;
    Dat->Insert(Key,Data);
}
template <typename TData, typename TKey>
TData* AVLTable<TData, TKey>::FindRecord(const TKey Key)
{
    
    try {
        if (!this->IsEmpty())
        {
            return (Dat->Find(Key))->GetData();
        }
        else
        {
            throw "Search in an empty table is not possible";
        } //Таблица пуста
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
}
template <typename TData, typename TKey>
void AVLTable<TData, TKey>::RemoveRecord(TKey Key)
{
    try {

        if (!this->IsEmpty())
        {
            Dat->Delete(Key);
            this->dataCount--;
        }
        else
        {
            throw "Delete in an empty table is not possible";
        }
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
}
template <typename TData, typename TKey>
void AVLTable<TData, TKey>::Reset()
{
    try {
        if (!this->IsEmpty())
        {
            Dat->Reset();
            Cur = (BalanceNode<TData, TKey>*)Dat->GetCur();
        }
        else
        {
            throw "Reset in an empty table is not possible";
        } 
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
}
template <typename TData, typename TKey>
void AVLTable<TData, TKey>::SetNext()
{
    
    try {
        if (!this->IsEmpty())
        {
            Dat->SetNext();
            Cur = (BalanceNode<TData, TKey>*)Dat->GetCur();
        }
        else
        {
            throw "SetNext in an empty table is not possible";
        } 
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
    
}
template<typename TData, typename TKey>
inline void AVLTable<TData, TKey>::Clear()
{
    Dat->Clear();
    this->dataCount = 0;
}
template <typename TData, typename TKey>
TData* AVLTable<TData, TKey>::GetData() const
{
    try {
        if (!this->IsEmpty())
        {
            return Cur->GetData();
        }
        else
        {
            throw "GetData in an empty table is not possible";
        } //Таблица пуста
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }

}
template <typename TData, typename TKey>
TKey  AVLTable<TData, TKey>::GetKey() const
{
    try {
        if (!this->IsEmpty())
        {
            return Cur->GetKey();
        }
        else
        {
            throw "GetKey in an empty table is not possible";
        } 
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }

}
