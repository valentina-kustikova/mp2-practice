#pragma once

#include "data.h"
#include "node.h"

class TList
{
protected:
    TNode* pFirst;
    //TNode* pStop; // nullptr дл€ лин. односв€зного списка и pHead дл€ цикл. с головой
    TNode* pCurr;
    TNode* pNext;
    TNode* pPrev;

public:
    //  онструкторы
    TList();
    TList(TNode* temp); // pFirst
    TList(const TList& temp);
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
    virtual bool NextIsEnded() const; // проверка на конец списка
    virtual bool IsEmpty() const; // проверка на пустоту списка

    virtual bool IsEnded() const;
    // —лужебные методы
    // ...
    virtual TNode* GetFirst() const { return pFirst; }
    virtual TNode* GetCur() const { return pCurr; }
};
