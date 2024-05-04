#ifndef __TLIST_H__
#define __TLIST_H__

//изменить сэмплы, чтобы работа происходила с пользовательскими данными, +++
//  изменить в отчете рисунки списка звеньями с указателями, 
// стрелочками и тд, операции +-* и тд  написать описание самого алгоритм: полино представилен списком с головой мономов и ....
#include <iostream>
#include "tnode.h"

using namespace std;
template<class TData>
class TList {
protected:
    TNode<TData>* pFirst = nullptr;
    TNode<TData>* pLast = nullptr;
    TNode<TData>* pStop = nullptr; //значение указателя конца списка =null
    TNode<TData>* pCurr = nullptr;  //pCurrent текущий
    TNode<TData>* pPrev = nullptr;
public:
    TList();
    TList(const TNode<TData>* pFirst_); //конструктор  с параметром
    TList(const TList& pList);   //конструктор копирования
    
    virtual void Clear();
     ~TList();
    
     bool is_Full() const;
    void Next();

    void Sort();
    virtual  bool is_Empty() const;
 

    TNode<TData>* Search(const TData& data_);
    //INSERT 
    virtual void InsertFirst(const TData& data_);
    void InsertLast(const TData& data_);
    void InsertBefore(const TData& data_, const TData& NextData);
    void InsertAfter(const TData& data_, const TData& PrevData);

    void Reset(); //установить на начало списка

    TNode<TData>* GetCurrent() const; //возвращает текущее звено
    TData getCurrData() const;
    void setCurrData(const TData& _data);

    const TList<TData>& operator=(const TList<TData>& pList) ; // TODO: const

    //insert(2)
    void InsertBeforeCurrent(const TData& data_); //вставить перед текущим
    void InsertAfterCurrent(const TData& data_); //вставить после текущего

    //functions
    void Remove(const TData& data_); //удаление по данным 
    virtual void RemoveFirst();
    void RemoveCurrent();
    bool is_End() const; //список завершен?

    friend std::ostream& operator<<(std::ostream& out, const TList<TData>& list) {
        TNode<TData>* tmp = list.pFirst;
        int num = 1;
        while (tmp != nullptr) {
            out << num << " node " << tmp->data << std::endl;
            tmp = tmp->pNext;
            num++;
        }
        return out;
    }
};

//constructors
template <class TData> TList<TData> ::TList() {
    pFirst = pLast = pCurr = pStop = pPrev = nullptr;
    Reset();
}

template <class TData> TList<TData> ::TList(const TNode<TData>* pFirst_) {
    pFirst = (TNode<TData>*)pFirst_;
    pCurr = pFirst;
    while (pCurr->pNext != nullptr)
    {
        Next();
    }
    pLast = pCurr;
    pCurr = pFirst;
    pLast->pNext = pStop;
    pStop = pPrev = nullptr;
}
template <class TData> TList<TData> ::TList(const TList& pList) {
    if (pList.pFirst == nullptr)
    {
        return;
    }
    TNode<TData>* oldCurrent = pList.pFirst;
    pFirst = new TNode<TData>(*pList.pFirst);
    TNode<TData>* newCurrent = pFirst;
    oldCurrent = oldCurrent->pNext;
    while (oldCurrent != pList.pStop)
    {
        newCurrent->pNext = new TNode<TData>(oldCurrent->data);
        newCurrent = newCurrent->pNext;
        oldCurrent = oldCurrent->pNext;
    }
    pLast = newCurrent;
    pLast->pNext = pStop;
    pCurr = pFirst;
    pStop = nullptr;
}

template <class TData> const TList<TData>& TList<TData>::operator=(const TList<TData>& pList) {
    if (this == &pList)
    {
        return *this;
    }
    if (pList.pFirst == nullptr)
    {
        pFirst = pStop = pCurr = pPrev = pLast = nullptr;
        return;
    }
    TNode<TData>* oldCurrent = pList.pFirst;
    pFirst = new TNode<TData>(*pList.pFirst);
    TNode<TData>* newCurrent = pFirst;
    oldCurrent = oldCurrent->pNext;
    while (oldCurrent != pList.pStop)
    {
        newCurrent->pNext = new TNode<TData>(oldCurrent->data);
        newCurrent = newCurrent->pNext;
        oldCurrent = oldCurrent->pNext;
    }
    pLast = newCurrent;
    pCurr = pFirst;
    pStop = nullptr;

    return *this;
}
template <class TData> void TList<TData>::Clear() {
    if (pFirst == nullptr)
    {
        return;
    }
    pCurr = pFirst;
    while (pCurr != pStop) {
        TNode<TData>* tmp = pCurr;
        pCurr = pCurr->pNext;
        delete tmp;
    }
    pCurr = pStop;
    pLast = pStop;
    pFirst = pStop;
    pPrev = pStop;
}

template <class TData> TList<TData> ::~TList() {
    Clear();
}

//functions

//sort по убыванию
template <class TData> void TList<TData>::Sort() {
    TNode<TData>* elem1 = pFirst;
    if (is_Empty())
    {
        return; //
    }
    while (elem1->pNext != pStop)
    {
        TNode<TData>* elem2 = elem1->pNext;
        while (elem2 != pStop)
        {
            if (elem1->data < elem2->data)
            {
                TData tmp = elem1->data;
                elem1->data = elem2->data;
                elem2->data = tmp;
            }
            elem2 = elem2->pNext;
        }
        elem1 = elem1->pNext;
    }
    pPrev = pLast;
    pCurr = pFirst;
}
template <class TData> void TList<TData> ::Next() {
    if (pCurr == pStop)
    {
        return;
    }
    pPrev = pCurr;
    pCurr = pCurr->pNext;
}

template <class TData> void TList<TData> ::Reset() {
    if (is_Empty()) {
        pCurr = pStop;
    }
    else {
        pCurr = pFirst;
        pPrev = pStop;
    }
    return;
}

template <class TData> bool TList<TData> ::is_Full() const {
    try
    {
        TNode<TData>* tmp = new TNode<TData>();
        if (tmp == nullptr)
            return true;
        else
        {
            delete tmp;
            return false;
        }
    }
    catch (...)
    {
        return true;
    }
    return true;
}

template <class TData> bool TList<TData> ::is_Empty() const {
    return pFirst == pStop;
}

template <class TData> bool TList<TData> ::is_End() const {
    if (pCurr == pStop)
        return true;
    else
        return false;
}

template <class TData> TNode<TData>* TList<TData> ::Search(const TData& data_) {
    TNode<TData>* tmp = pFirst;

    while ((tmp != pStop) && (tmp->data != data_)) {
        tmp = tmp->pNext; 
    }
    if (tmp == pStop) {
        return nullptr;
    }
    return tmp;
}

template <class TData> void TList<TData>::Remove(const TData& data_) {
    // Поиск звена с данными для удаления
    pCurr = Search(data_);
    if (pCurr == nullptr) {
        throw "Error. List does't have node with this data"; // Звено не найдено, выходим из функции
    }
    // Обновление ссылок на звено после удаления
    if (pCurr == pFirst) {
        pFirst = pFirst->pNext;
    }
    else {
        pPrev->pNext = pCurr->pNext;
    }
    if (pCurr == pLast) {
        pLast = pPrev;
    }
    // Освобождение памяти, выделенной для звена
    delete pCurr;

}

template <class TData> void TList<TData>::RemoveFirst()
{
    if (pFirst != pStop) {
        TNode<TData>* tmp = pFirst;
        pFirst = pFirst->pNext;
        pCurr = pFirst;
        delete tmp;
    }
}

template <class TData> void TList<TData>::RemoveCurrent() {
    if(pCurr != pStop)
        if (pCurr == pFirst) {
            RemoveFirst();
        }
        else {
            TNode<TData>* tmp = pCurr;
           
            pPrev->pNext = pCurr->pNext;
            pCurr = pCurr->pNext;
            if (pPrev->pNext == pStop)
                pLast = pPrev;
            pPrev->pNext = pCurr;
            delete tmp;
        }
} 

//INSERT 
template <class TData> void TList<TData>::InsertFirst(const TData& data_) {
    if (is_Full()) {
        throw "Error. Memory is not enough";
    }
    TNode<TData>* newNode = new TNode<TData>(data_, nullptr);

    if (pFirst != pStop)
    {
        TNode<TData>* oldPFirst = pFirst;
        pFirst = newNode;
        pFirst->pNext = oldPFirst;

    }
    else {
        pFirst = newNode;
    }
    pCurr = pFirst;
    if (pLast == pStop) {
        pLast = pFirst;
    }
}

template <class TData> void TList<TData>::InsertLast(const TData& data_) {
    if (is_Empty())
    {
        InsertFirst(data_);
        pLast = pFirst;
        return;
    }
    TNode<TData>* newNode = new TNode<TData>(data_, pStop);
    pLast->pNext = newNode;
    pLast = newNode;
    pCurr = pLast;

}
template <class TData> void TList<TData>::InsertBefore(const TData& data_, const TData& NextData) {
    if (is_Empty()) {
        throw "Error. List is empty.";
    }
    pCurr = pFirst;
    while ((pCurr != pStop) && (pCurr->data != NextData))
    {
        pPrev = pCurr;
        Next();
    }
    if ((pCurr == pStop) && (pCurr->data != NextData))
    {
        throw "Error. Key not found.";
    }
    TNode<TData>* newNode = new TNode<TData>(data_, pCurr);

    // list have only 1 node
    if (pPrev == pStop) {
        pFirst = newNode;
    }
    else {
        newNode->pNext = pPrev->pNext;
        pPrev->pNext = newNode;
    }
    pCurr = pFirst;

}

template <class TData> void TList<TData>::InsertAfter(const TData& data_, const TData& PrevData) {
    if (is_Empty())
        throw "Error. List is empty";
    TNode<TData>* prNode = Search(PrevData);
    if (prNode == pStop)
    {
        throw "Error. Can't insert after";
    }
    TNode<TData>* tmp = new TNode<TData>(data_, prNode->pNext);
    tmp->pNext = prNode->pNext;
    prNode->pNext = tmp;
   
}

// Set & Get
template <class TData> TNode<TData>* TList<TData>::GetCurrent() const //возвращает текущее звено 
{
    return pCurr;
}
template <class TData> TData TList<TData>::getCurrData() const {
    if (pCurr != pStop)
        return pCurr->data;
    else
        return NULL;
}

template <class TData> void TList<TData>::setCurrData(const TData& _data)
{
    pCurr->data = _data;
}

//insert(2)
//pCur на вставленный элемент
template <class TData> void TList<TData>::InsertBeforeCurrent(const TData& data_) //вставить перед текущим
{
    if (is_Empty()) {
        InsertFirst(data_);
    }
    else if (is_End()) {
        InsertLast(data_);
    }
    else {
        TNode<TData>* newNode = new TNode<TData>(data_, pCurr); //pCur->pNext;
        if (newNode == nullptr) {
            throw "Error. List doesn't have memory";
        }
        else {
            pCurr = newNode;
            pPrev->pNext = newNode;
         
        }
    }
    
}
//pCur на вставленный элемент
template <class TData> void TList<TData>::InsertAfterCurrent(const TData& data_) //вставить после текущего
{
    if (is_Empty()) {
        InsertFirst(data_);
    }
    else if (is_End()) {
        InsertLast(data_);
    }
    else {
        TNode<TData>* newNode = new TNode<TData>(data_); 
        if (newNode == nullptr) {
            throw "Error. List doesn't have memory";
        }
        else {
            newNode->pNext = pCurr->pNext;
            pCurr->pNext = newNode; 
            pCurr = newNode;
            pPrev = pPrev->pNext;
           
        }
    }
}
#endif