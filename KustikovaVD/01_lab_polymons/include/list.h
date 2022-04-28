#pragma once

#include <iostream>
#include "data.h"
#include "node.h"

class TList
{
private:
    TNode* pFirst; //голова 
    TNode* pCurr; //указатель на текущее звено
    TNode* pLast;//указатель на хвост 


    // Конструкторы
    TList();
    TList(TNode* pFirst) : pFirst(pFirst), pCurr(pFirst), pLast(pFirst) {};
    TList(const TList& list);
    // Деструктор
    ~TList();

    // Операции над списком

    TNode* Search(TData* const data) //поиск узла в списке по заданному значению 
    {
        if (IsEmpty())
        {
            TNode* p = pFirst;
            while (p && p->data != *(data)) //обходим список, пока указатель p не пустой и пока значение узла p не равно заданному значению
                p = p->pNext;
            return p && p->data == *(data) ? p : nullptr;
        }

    };
    
    virtual void InsertToHead(TData* const data); //вставить в начало списка 
    virtual void InsertToTail(TData* const data); //вставить в конец
    virtual void InsertBefore(TData* const data, TData* const before_data); //вставить узел data перед before_data
    virtual void InsertAfter(TData* const data, TData* const after_data);  //вставить узел data после after_data 
    virtual void RemoveFirst(); //Удалить первый узел 
    virtual void RemoveLast(); //Удалить последний узел
    virtual void Remove(TData* const data); //Удалить узел со значением data
    virtual void Clear(); //очистить список 
    int GetLenght() const; //Получить длину списка 

    // Навигация
    void Next(); // переход к следующему звену
    void Reset(); // переход в начало списка
    bool IsEnded() const  // проверка на конец списка
    {
        this->pCurr;
        return pCurr->pNext == nullptr;
    }
    bool IsEmpty() const // проверка на пустоту списка
    {
        return pFirst == nullptr;
    }

    // Служебные методы
    // ...
};
//конструкторы
TList::TList()
{
    pFirst = new TNode;
    pFirst->pNext = nullptr;
    pCurr = pFirst; 
    pLast = pFirst;
}

TList::TList(const TList& list) //конструктор копирования 
{
    TNode* tmp = list.pFirst;
    pFirst = new TNode(tmp->data);
    pFirst->pNext = pFirst; 
    pCurr = pFirst;
    pLast = pFirst; 
    while (tmp->pNext != list.pLast)
    {
        tmp = tmp->pNext;
        pCurr->pNext = new TNode(tmp->data);
        pCurr = pCurr->pNext; 
    }
}
//деструктор 
TList::~TList()
{
    Clear();
}
void TList::InsertToHead(TData* const data)
{
    TNode* p = new TNode(*data);
    if (IsEmpty())
    {
        pFirst = p;
        pLast = p;
        return; 
    }
    p->pNext = pFirst; //голова стоит после нового узла (??)
    pFirst = p;
}
void TList::InsertToTail(TData* const data)
{
    TNode* p = new TNode(*data);
    if (IsEmpty())
    {
        pFirst = p;
        pLast = p;
        return;
    }
    pLast->pNext = p; //новый узел стоит после последнего узла 
    pLast = p; 
}
void TList::InsertBefore(TData* const data, TData* const before_data)
{
    TNode* bf = new TNode(*before_data);
    TNode* p = new TNode(*data);
    p->pNext = bf;
}
void TList::InsertAfter(TData* const data, TData* const after_data)
{
    TNode* af = new TNode(*after_data);
    TNode* p = new TNode(*data);
    af->pNext = p;
}

void TList::RemoveFirst()
{
    if (IsEmpty()) return;
    TNode* p = pFirst; 
    pFirst = p->pNext; //Меняем значение первого узла на следующий
    delete p; 
}

void TList::RemoveLast()
{
    if (IsEmpty()) return;
    if (pFirst == pLast)
    {
        RemoveFirst();
        return;
    }
    TNode* p = pFirst;
    while (p->pNext != pLast)
        p = p->pNext;
    p->pNext = nullptr;
    delete pLast;
    pLast = p;
}

void TList::Remove(TData* const _data) 
{
    TNode* p = new TNode(*_data);
    if (p == pFirst)
    {
        RemoveFirst();
        return;
    }
    else if (p == pLast)
    {
        RemoveLast();
        return;
    }
    TNode* slow = pFirst;
    TNode* fast = pFirst->pNext;
    while (fast && fast->data != *_data)
    {
        fast = fast->pNext;
        slow = slow->pNext;
    }
    if (!fast)
    {
        setlocale(LC_ALL, "Russian");
        std::cout << "Ошибка: такого элемента нет" << std::endl;
        return;
    }
    slow->pNext = fast->pNext; 
    delete fast;
}

int TList::GetLenght() const
{
    int it = 1;
    if (pFirst == nullptr)
    {
        return 0;
    }
    else
    while (pFirst->pNext)
    {
        pFirst->pNext = pFirst;
        ++it; 
    }
    return it; 
}
void TList::Next() //???
{
    if (IsEmpty())
        pCurr = pCurr->pNext;
}

void TList::Reset()
{
    TNode* tmp = pFirst;
    pCurr->pNext = pFirst;
    return; 
}
void TList::Clear()
{
    if (IsEmpty()) return; 
    TNode* p = new TNode; 
    TNode* p = pFirst;
    int size = GetLenght();
    int i=0;
    while (i != size)
    {
        pFirst = p->pNext;
        delete p;
        ++i;
    }
}

   

















