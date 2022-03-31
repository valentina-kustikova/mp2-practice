#pragma once

#include "data.h"
#include "node.h"

class TList 
{
private:
    TNode* pFirst; //голова 
    TNode* pCurr; //указатель на текущее звено

public:
    //  онструкторы
    TList();
    TList(TNode* pFirst) : pFirst(pFirst) {};
    TList(const TList& list);
    // ƒеструктор
    ~TList();

    // ќперации над списком
    virtual TNode* Search(TData* const data);
    virtual void InsertToHead(TData* const data);
    virtual void InsertToTail(TData* const data);
    virtual void InsertBefore(TData* const data, TData* const before_data);
    virtual void InsertAfter(TData* const data, TData* const after_data);
    virtual void RemoveFirst();
    virtual void RemoveLast();
    virtual void Remove(TData* const data);
    virtual void Clear();
    virtual void Sort();
    virtual int GetLenght() const;

    // Ќавигаци€
    virtual void Next(); // переход к следующему звену
    virtual void Reset(); // переход в начало списка
    virtual bool IsEnded() const; // проверка на конец списка
    virtual bool IsEmpty() const; // проверка на пустоту списка

    // —лужебные методы
    // ...
};
TList::TList(const TList& list) //конструктор копировани€ 
{

}
