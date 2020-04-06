#include "TSList.h"
#include <iostream>

using namespace std;

TList<double, unsigned int>::TList() :pFirst(0), pPrev(0), pCur(0), pNext(0) {}

TList<double, unsigned int>::TList(const TNode<double, unsigned int>* _node)
{
    TNode<double, unsigned int>* node = new TNode<double, unsigned int>(*_node);
    pFirst = new TNode<double, unsigned  int>(node->key, node->pData);
    pCur = pFirst;
    node = node->pNext;
    while (node != nullptr)
    {
        pCur->pNext = new TNode<double, unsigned int>(node->key, node->pData);
        pCur = pCur->pNext;
        node = node->pNext;
    }
    Reset();
}


TList<double, unsigned int>::TList(const TList<double, unsigned int>& list)
{
    if (list.pFirst == nullptr)
    {
        TList();
        return;
    }
    TNode<double, unsigned int>* node = list.pFirst;
    pFirst = new TNode<double, unsigned int>(node->key, node->pData);
    pCur = pFirst;
    node = node->pNext;
    while (node != nullptr)
    {
        pCur->pNext = new TNode<double, unsigned int>(node->key, node->pData);
        pCur = pCur->pNext;
        node = node->pNext;
    }
    Reset();
}

TList<double, unsigned int>::~TList()
{
    Reset();
    while (pFirst != nullptr)
    {
        pNext = pFirst->pNext;
        delete pFirst;
        pFirst = pNext;
    }
}

bool TList<double, unsigned int>::operator==(const TList& tmp) const
{
    TNode<double, unsigned int>* node1 = pFirst;
    TNode<double, unsigned int>* node2 = tmp.pFirst;

    while (node1 && node2 && (*node1 == *node2))
    {
        node1 = node1->pNext;
        node2 = node2->pNext;
    }
    return (!(node1 || node2));
}

bool TList<double, unsigned int>::IsEnded() const
{
    return(pCur == nullptr);
}

void TList<double, unsigned int>::Reset()
{
    pPrev = nullptr;
    pCur = pFirst;
    if (pFirst != nullptr)
        pNext = pCur->pNext;
    else
        pNext = nullptr;
}

void TList<double, unsigned int>::Next()
{
    if (IsEnded())
        throw "You reached the end";
    pPrev = pCur;
    pCur = pNext;
    if (pCur != nullptr)
        pNext = pCur->pNext;
    else
        pNext = nullptr;
}

TNode<double, unsigned int>* TList<double, unsigned int>::Search(unsigned int fkey)
{
    Reset();
    while ((!IsEnded()) && (pCur->key != fkey))
        Next();
    if (IsEnded())
    {
        Reset();
        return nullptr;
    }
    return pCur;
}

void TList<double, unsigned int>::InsertEnd(unsigned int _key, double _pData) //v konec
{
    if (pFirst == nullptr)
    {
        pFirst = new TNode<double, unsigned int>(_key, _pData);
        pCur = pFirst;
        return;
    }
    TNode<double, unsigned int>* fpPrev = pPrev;
    TNode<double, unsigned int>* fpCur = pCur;
    TNode<double, unsigned int>* fpNext = pNext;
    Reset();
    while (!IsEnded())
        Next();
    TNode<double, unsigned int>* node = new TNode<double, unsigned int>(_key, _pData);
    pPrev->pNext = node;

    pPrev = fpPrev;
    pCur = fpCur;
    if (pCur->pNext == nullptr)
        pNext = node;
    else pNext = fpNext;
}

void TList<double, unsigned int>::InsertFirst(unsigned int _key, double _pData)// v nachalo
{
    TNode<double, unsigned int>* node = new TNode<double, unsigned int>(_key, _pData, pFirst);
    if (pCur == pFirst)
    {
        pPrev = node;
    }
    pFirst = node;
}

void TList<double, unsigned int>::InsertAfter(unsigned int fkey, double _pData, unsigned int _key)
{
    if (pFirst == 0)
        throw "The list is empty";

    TNode<double, unsigned int>* fpPrev = pPrev;
    TNode<double, unsigned int>* fpCur = pCur;
    TNode<double, unsigned int>* fpNext = pNext;

    Reset();
    while (!IsEnded())
    {
        if (pCur->key == fkey)
        {
            TNode<double, unsigned int>* node = new TNode<double, unsigned int>(_key, _pData, pNext);
            pCur->pNext = node;

            pPrev = fpPrev;
            pCur = fpCur;
            if (pCur != fpCur)
            {
                pNext = fpNext;
            }
            else
            {
                pNext = node;
            }
            return;
        }
        Next();
    }
    pPrev = fpPrev;
    pCur = fpCur;
    pNext = fpNext;

    throw "The list doesn't contain an elem with this key";
}

void TList<double, unsigned int>::InsertBefore(unsigned int fkey, double _pData, unsigned int _key)
{
    if (pFirst == 0)
        throw "The list is empty";
    TNode<double, unsigned int>* fpFirst = pFirst;
    TNode<double, unsigned int>* fpPrev = pPrev;
    TNode<double, unsigned int>* fpCur = pCur;
    TNode<double, unsigned int>* fpNext = pNext;

    Reset();
    if (pCur->key == fkey)
    {
        InsertFirst(_key, _pData);
        return;
    }
    while (pCur->pNext != nullptr)
    {
        if (pNext->key == fkey)
        {
            TNode<double, unsigned int>* node = new TNode<double, unsigned int>(_key, _pData, pNext);
            pCur->pNext = node;

            pPrev = fpPrev;
            pCur = fpCur;
            if (pCur != fpCur)
            {
                pNext = fpNext;
            }
            else
            {
                pNext = node;
            }
            return;
        }
        Next();
    }
    pPrev = fpPrev;
    pCur = fpCur;
    pNext = fpNext;
    throw "The list doesn't contain an elem with this key";
}

void TList<double, unsigned int>::Remove(unsigned int fkey)
{
    if (pFirst == nullptr)
        throw "The list is empty";

    TNode<double, unsigned int>* fpFirst = pFirst;
    TNode<double, unsigned int>* fpPrev = pPrev;
    TNode<double, unsigned int>* fpCur = pCur;
    TNode<double, unsigned int>* fpNext = pNext;

    if (Search(fkey) == nullptr)
    {
        pPrev = fpPrev;
        pCur = fpCur;
        pNext = fpNext;
        throw "The list doesn't contain an elem with this key";
    }

    if (pFirst == pCur)
    {
        if (fpCur == pFirst)
        {
            Next();
            fpCur = pCur;
            fpNext = pNext;
            fpPrev->pNext = pCur;
            fpFirst = pCur;
        }
        else if (fpCur == pFirst->pNext)
        {
            fpPrev = nullptr;
            fpPrev->pNext = fpCur;
            fpFirst = fpCur;
        }
        else
        {
            fpFirst = fpFirst->pNext;
        }
        delete pFirst;
        pFirst = fpFirst;

        pPrev = fpPrev;
        pCur = fpCur;
        pNext = fpNext;
        return;
    }

    if (fpCur == pCur)
    {
        delete pCur;
        pCur = fpNext;
        pPrev->pNext = pCur;
        if (pNext != nullptr)
        {
            pNext = pNext->pNext;
        }
        return;
    }
    pPrev->pNext = pCur->pNext;
    delete pCur;
    pCur = pNext;
    if (pNext != nullptr)
    {
        pNext = pNext->pNext;
    }

    pPrev = fpPrev;
    pCur = fpCur;
    pNext = fpNext;
}