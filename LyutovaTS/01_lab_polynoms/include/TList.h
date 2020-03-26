#ifndef _TLIST_H_
#define _TLIST_H_
#include <iostream>
#include "TNode.h"
#include "Exception.h"

template<class TKey, class TData>
class TList
{

    public:

        TNode<TKey, TData>* pFirst;
        TNode<TKey, TData>* pCurr; //текущий
        TNode<TKey, TData>* pNext;
        TNode<TKey, TData>* ptmp;


        TList();
        TList(const TList&);
        TList(TNode<TKey, TData>*);
        ~TList();

        bool IsFull()const;
        void Reset();
        void Next();

        TNode<TKey, TData>* Search(TKey);
        TNode<TKey, TData>* Curr() const;
        void InsertB(TData*&, TKey);
        void InsertE(TData, TKey);
        void InsertAfter(TData*&, TKey, TKey);
        void InsertBefore(TData*&, TKey, TKey);
        void Delete(/*TData*&,*/TKey);

        friend ostream& operator<<(ostream& out, TList<TKey, TData>& l)
        {
            if (!l.pFirst) {
                out << "Error" << endl;
                return out;;
            }

            l.Reset();
            while (!(l.IsFull()))
            {
                out << l->pCurr->key << endl;
                l.Next();
            }
            return out;
        }
};

template <class TKey, class TData>
TList<TKey, TData>::TList()
{
    pFirst = 0;
    pCurr = 0;
    pNext = 0;
    ptmp = 0;
}

template <class TKey, class TData>
TList<TKey, TData>::TList(TNode<TKey, TData>* first)
{
    pFirst = new TNode<TKey, TData>(*first);
    TNode<TKey, TData>* node = first;
    TNode<TKey, TData>* tmp = pFirst;
    while (tmp->pNext != 0)
    {
        node->pNext = new TNode<TKey, TData>(*(tmp->pNext));
        node = node->pNext;
        tmp = tmp->pNext;
    }
    ptmp = 0;
    pCurr = pFirst;
    pNext = pFirst->pNext;
}


template <class TKey, class TData>
TList<TKey, TData>::TList(const TList& tmp2)
{
    if (tmp2.pFirst == 0)
    {
        pFirst = 0;
        pCurr = 0;
        pNext = 0;
        ptmp = 0;
        return;
    }

    pFirst = new TNode<TKey, TData>(*(tmp2.pFirst));
    pCurr = pFirst;
    TNode<TKey, TData>* tmp = tmp2.pFirst;
    while (tmp->pNext != 0)
    {
        pCurr->pNext = new TNode<TKey, TData>(*(tmp->pNext));
        ptmp = pCurr;
        pCurr = pCurr->pNext;
        tmp = tmp->pNext;
    }
    ptmp = 0;
    pCurr = pFirst;
    pNext = pFirst->pNext;
  
}

template <class TKey, class TData>
TList<TKey, TData>::~TList()
{
    TNode<TKey, TData> *del = pFirst;
    TNode<TKey, TData> *tmp;
    while (del != nullptr)
    {
        tmp = del->pNext;
        delete del;
        del = tmp;
    }
}

template <class TKey, class TData>
bool TList<TKey, TData>::IsFull() const
{
    return (pCurr == 0);
}

template <class TKey, class TData>
void TList<TKey, TData>::Reset()
{
    ptmp = 0;
    pCurr = pFirst;
    if (pFirst != 0)
    {
        pNext = pCurr->pNext;
    }
    else
    {
        pNext = NULL;
    }
}

template <class TKey, class TData>
void TList<TKey, TData>::Next()
{
    if (IsFull())
        throw exception("The end of the list");
    ptmp = pCurr;
    pCurr = pCurr->pNext;
    if (pNext != NULL)
        pNext = pNext->pNext;
}

template <class TKey, class TData>
TNode<TKey, TData>* TList<TKey, TData>::Search(TKey key1)
{
    TNode<TKey, TData>* tmp3Curr = pCurr;
    TNode<TKey, TData>* tmp3Next = pNext; //переобозначим
    TNode<TKey, TData>* tmp3tmp = ptmp;
    this->Reset();

    while (!IsFull() && (key1 != pCurr->key))
    {
        this->Next();
    }
    pCurr = tmp3Curr;
    pNext = tmp3Next;
    ptmp = tmp3tmp;
    return pCurr;
}

template<class TKey, class TData>
void TList<TKey, TData>::InsertB(TData*& data, TKey key)
{
    if (pFirst == 0)
    {
        pFirst = new TNode<TKey, TData>(data, key);
        pCurr = pFirst;
    }
    TNode<TKey, TData>* node = new TNode<TKey, TData>(data, key, pFirst);
    node->pNext = pFirst;
    if (pCurr == pFirst)
        ptmp = node;
    pFirst = node;
}

template<class TKey, class TData>
void TList<TKey, TData>::InsertE(TData data, TKey key)
{
    if (pFirst == 0)
    {
        pFirst = new TNode<TKey, TData>(key, data);
        pCurr = pFirst;
        return;
    }
    TNode<TKey, TData>* node = new TNode<TKey, TData>(data, key);
    TNode<TKey, TData>* tmp = pFirst;
    while (tmp->pNext != 0)
    {
        tmp = tmp->pNext;
    }
    tmp->pNext = node;
    if (pCurr == tmp) 
        pNext = node;
    tmp->pNext->pNext = 0; //в тетради так
}

template <class TKey, class TData>
void TList<TKey, TData>::InsertAfter(TData*& data, TKey key, TKey nextkey)
{
    if (pFirst == 0)
    {
        throw exception("Empty");
        return;
    }
    TNode<TKey, TData>* tmp = pFirst;
    while ((tmp != 0) && (tmp->key != nextkey))
    {
        tmp = tmp->pNext;
    }
    if (tmp == 0)
        throw exception("Key not found");
    TNode<TKey, TData>* tmp1 = tmp->pNext;
    TNode<TKey, TData>* node = new TNode<TKey, TData>(data, key);
    tmp->pNext = node;
    node->pNext = tmp1;
    if (pCurr == tmp)
        pNext = tmp1;
    if (pCurr == node)
        ptmp = tmp1;
}

template <class TKey, class TData>
void TList<TKey, TData>::InsertBefore(TData*& data, TKey key, TKey nextkey)
{
    if (pFirst == 0) 
    {
        throw exception("Empty");
        return;
    }
    if (pFirst->key == nextkey)
    {
        InsertB(data, key);
        return;
    }
    TNode<TKey, TData>* tmp = pFirst;
    while ((tmp->pNext != 0) && (tmp->pNext->key != nextkey))
    {
        tmp = tmp->pNext;
    }
    if (tmp->pNext == 0)
        throw exception("Key not found");
    TNode<TKey, TData>* tmp1 = tmp->pNext;
    TNode<TKey, TData>* node = new TNode<TKey, TData>(data, key);
    tmp->pNext = tmp1;
    tmp1->pNext = node;
    if (pCurr == tmp) 
        pNext = tmp1;
    if (pCurr == node)
        ptmp = tmp1;
}

template <class TKey, class TData>
void TList<TKey, TData>::Delete(TKey key1)
{
    if (pFirst == 0)
    {
        throw exception("Empty");
        return;
    }
    if (pFirst->key == key1)
    {
        TNode<TKey, TData>* tmp = pFirst->pNext;
        if (pCurr == pFirst) 
            pCurr = 0;
        if (ptmp == pFirst)
            ptmp = 0;
        if (pNext == pFirst)
            pNext = pNext->pNext;
        delete pFirst;
        pFirst = tmp;
        return;
    }
    TNode<TKey, TData>* tmp1 = pFirst;
    while ((tmp1->pNext != 0) && (tmp1->pNext->key != key1))
        tmp1 = tmp1->pNext;
    if (tmp1->pNext == 0)
        throw exception("Key not found");
    TNode<TKey, TData>* del = tmp1->pNext->pNext;
    if (pCurr == tmp1->pNext) 
        pCurr = 0;
    if (pNext == tmp1->pNext)
        pNext = tmp1->pNext->pNext;
    tmp1->pNext = del;
    delete tmp1->pNext;
}

template <class TKey, class TData>
TNode<TKey, TData>* TList<TKey, TData>::Curr() const
{
    return pCurr;
}

#endif