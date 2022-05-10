#pragma once
#include "Table.h" 
#include"AVLTree.h"
#define PTBalanceNode TbNode<TData,TKey>*

//Класс таблиц на АВЛ деревьях
template <typename TData, typename TKey>
class AVLTable : public Table<TData, TKey>
{ private:
  AVLTree<TData, TKey>* A1;
  PTBalanceNode Cur;
  public:
  // Конструкторы, деструктор	
  AVLTable() { A1 = new AVLTree<TData, TKey>; dataCount = 0; Cur=nullptr;}
  AVLTable(const AVLTable<TData, TKey>& T1);
  ~AVLTable(){ delete A1; }
  // Методы 
  virtual void Insert(const TData Data, const TKey Key);
  virtual TData* Search(const TKey Key);
  virtual void Delete(const TKey Key);
  void Reset();
  void SetNext();
  bool IsEnd() const { return Cur->GetKey() == (A1->FindMax())->GetKey(); }
  TData* GetData() const; // для текущего элемента
  TKey GetKey() const;  // для текущего элемента
  template<class TData> friend std::ostream& operator<< (std::ostream& os, const AVLTable<TData, TKey>& Tab)
  {
      if (Tab.dataCount == 0)
      { os << "\n\tTable is Empty\n";}
      else 
      { os << *(Tab.A1); }
      return os;
  }
  AVLTable<TData, TKey>& operator=(const AVLTable<TData, TKey>& T1)
  {
      A1 = new AVLTree<TData, TKey>(*(T1.A1));
      dataCount = T1.dataCount;
      return *this;
  }

};

// Pелизация функциий для класса таблиц на АВЛ деревьях
// Конструкторы
template <typename TData, typename TKey>
AVLTable<TData, TKey>::AVLTable(const AVLTable<TData, TKey>& T1)
{
    PTBalanceNode p1;
    A1 = new AVLTree<TData, TKey>;
    dataCount = 0;
    if(T1.dataCount>0)
    { p1 =(PTBalanceNode)T1.A1->FindMin();
      A1->Insert(p1->GetKey(), *(p1->GetData())); 
      dataCount++;
    }
      
    for (int i = 1; i < T1.dataCount; i++)
    {
        p1 = (PTBalanceNode)T1.A1->FindNext(p1);
        A1->Insert(p1->GetKey(),*( p1->GetData()));
        dataCount++;
    }
    Cur = nullptr;
}
// Методы 
template <typename TData, typename TKey>
void AVLTable<TData, TKey>::Insert(const TData Data, const TKey Key)
{
    A1->Insert(Key,Data);
    dataCount++;
}
template <typename TData, typename TKey>
TData* AVLTable<TData, TKey>::Search(const TKey Key)
{
    if (!IsEmpty())
    {
        return (A1->Find(Key))->GetData();
    }
    else
    {
        throw - 1;
    } //Таблица пуста
}
template <typename TData, typename TKey>
void AVLTable<TData, TKey>::Delete(TKey Key)
{
    if (!IsEmpty())
    {
        A1->Delete(Key);
        dataCount--;
    }
    else
    {
        throw - 1;
    } //Таблица пуста
}
template <typename TData, typename TKey>
void AVLTable<TData, TKey>::Reset()
{

    if (!IsEmpty())
    {
        Cur = (PTBalanceNode)A1->FindMin();
    }
    else
    {
        throw - 1;
    } //Таблица пуста
}
template <typename TData, typename TKey>
void AVLTable<TData, TKey>::SetNext()
{
    if (!IsEmpty())
    {
        Cur = (PTBalanceNode)A1->FindNext(Cur);
    }
    else
    {
        throw - 1;
    } //Таблица пуста
}
template <typename TData, typename TKey>
TData* AVLTable<TData, TKey>::GetData() const
{
    if (!IsEmpty())
    {
        return Cur->GetData();
    }
    else
    {
        throw - 1;
    } //Таблица пуста
}
template <typename TData, typename TKey>
TKey  AVLTable<TData, TKey>::GetKey() const
{
    if (!IsEmpty())
    {
        return Cur->GetKey();
    }
    else
    {
        throw - 1;
    } //Таблица пуста
}
