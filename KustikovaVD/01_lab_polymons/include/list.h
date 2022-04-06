#pragma once

#include "data.h"
#include "node.h"

class TList
{
private:
    TNode* pFirst; //голова 
    TNode* pCurr; //указатель на текущее звено
    TNode* pLast;//указатель на хвост 

public:
    // Конструкторы
    TList();
    TList(TNode* pFirst) : pFirst(pFirst) {};
    TList(const TList& list);
    // Деструктор
    ~TList();

    // Операции над списком
    bool is_empty() //проверяем, является ли первый узел пустым 
    {
        return pFirst == nullptr;
    }
    TNode* Search(TData* const data) //поиск узла в списке по заданному значению 
    {
        if (is_empty()) return;
        TNode* p = pFirst; 
        while (p && p->data != *(data)) //обходим список, пока указатель p не пустой и пока значение узла p не равно заданному значению
            p = p->pNext;
        return (p && p->data == *(data)) ? p : nullptr;
    };

    void InsertToHead(TData* const data); //вставить в начало списка 
    void InsertToTail(TData* const data); //вставить в конец
    void InsertBefore(TData* const data, TData* const before_data); //вставить узел data перед before_data
    void InsertAfter(TData* const data, TData* const after_data);  //вставить узел data после after_data 
    void RemoveFirst(); //Удалить первый узел 
    void RemoveLast(); //Удалить последний узел
    void Remove(TData* const data); //Удалить узел со значением data
    virtual void Clear();
    virtual void Sort();
    virtual int GetLenght() const; //Получить длину списка, подсчет количества узлов  

    // Навигация
    virtual void Next(); // переход к следующему звену
    virtual void Reset(); // переход в начало списка
    virtual bool IsEnded() const; // проверка на конец списка
    virtual bool IsEmpty() const; // проверка на пустоту списка

    // Служебные методы
    // ...
};
TList::TList(const TList& list) //конструктор копирования 
{
    TNode* tmp = list.pFirst;
    pFirst = new TNode(tmp->data);
    pFirst->pNext = pFirst; 
    pCurr = pFirst;
    while (tmp->pNext != list.pFirst)
    {
        tmp = tmp->pNext;
        pCurr->pNext = new TNode(tmp->data);
        pCurr = pCurr->pNext; 
    }
    pCurr->pNext = pFirst;
    
    
}

void TList::InsertToHead(TData* const data)
{
    TNode* p = new TNode(*data);
    if (is_empty()) 
    {
        pFirst = p;
        pLast = p;
        return; 
    }
    p->pNext = pFirst; //голова стоит после нового узла (??)
    pFirst = p;
};
void TList::InsertToTail(TData* const data)
{
    TNode* p = new TNode(*data);
    if (is_empty())
    {
        pFirst = p;
        pLast = p;
        return;
    }
    pLast->pNext = p; //новый узел стоит после последнего узла 
    pLast = p; 
};
void TList::InsertBefore(TData* const data, TData* const before_data)
{
    TNode* bf = new TNode(*before_data);
    TNode* p = new TNode(*data);
    p->pNext = bf;
};
void TList::InsertAfter(TData* const data, TData* const after_data)
{
    TNode* af = new TNode(*after_data);
    TNode* p = new TNode(*data);
    af->pNext = p;
};

void TList::RemoveFirst()
{
    if (is_empty()) return;
    TNode* p = pFirst; 
    pFirst = p->pNext; //Меняем значение первого узла на следующий
    delete p; 
};

void TList::RemoveLast()
{
    if (is_empty()) return;
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
};

void TList::Remove(TData* const data) //не дописала !
{
    TNode* p = new TNode(*data);
    if (p == pFirst)
    {
        RemoveFirst();
        return;
    }
    else if (p == pLast)
    {
        RemoveFirst();
        return;
    }
    TNode* slow = pFirst;
    TNode* fast = pFirst->pNext;


};














