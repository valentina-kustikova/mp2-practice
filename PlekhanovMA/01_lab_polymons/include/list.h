#pragma once
#include "node.h"

class TList
{
protected:
    TNode* pFirst;// первый элемент списка
    TNode* pStop;// nullptr для лин. односвязного списка и pHead для цикл. с головой
    TNode* pCurr;// текущий элемент списка
    TNode* pNext;// следующий элемент списка от текущего
    int Size; // длина списка

public:
    // Конструкторы
    TList();
    TList(TNode* pFirst);
    TList(const TList& list);
    ~TList();
    
    // Операции над списком
     TNode* Search(TData* const data);// поиск элемента списка
     void InsertToHead(TData* const data);// вставить элемент в начало
     void InsertToTail(TData* const data);// вставить элемент в конец
     void InsertAfter(TData* const data, TData* const after_data);// вставить элемент после данного
     void RemoveFirst();// удалить первый элемент
     void RemoveLast();// удалить последний элемент
     void Remove(TData* curr_data);// удалить данный элемент
     int GetLenght() const;// получить длину списка
     void Clear(); // очистить список

    // Навигация
     void Next(); // переход к следующему звену
     void Reset(); // переход в начало списка
     bool IsEnded() const; // проверка на конец списка
     bool IsEmpty() const; // проверка на пустоту списка

    // Служебные методы
     TList& operator =(const TList& list);
     int operator==(const TList list) const;
     TNode* GetLast();
     TNode* GetCurr();
     TNode* GetNext();
     TNode* GetFirst();
};
