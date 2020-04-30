#ifndef TLIST_H
#define TLIST_H
#include "TMonom.h"
#include <iostream>

using namespace std;

template<typename TData, typename TKey>
class TList
{
private:
    TNode<typename TData, typename TKey>* pFirst;
    TNode<typename TData, typename TKey>* pPrev;
    TNode<typename TData, typename TKey>* pCur;
    TNode<typename TData, typename TKey>* pNext;
public:
    TList();
    TList(const TNode<TData, TKey>*);
    TList(const TList&);
    ~TList();

    bool IsEnded() const;
    void Next();
    void Reset();

    TNode<TData, TKey>* Search(TKey);
    void InsertEnd(TKey, TData*);
    void InsertFirst(TKey, TData*);
    void InsertAfter(TKey, TData*, TKey);
    void InsertBefore(TKey, TData*, TKey);
    void Remove(TKey);
    friend std::ostream& operator << (std::ostream& out, TList<TData, TKey>& list)
    {
        list.Reset();
        while (!(list.IsEnded()))
        {
            out << (*list.pCur);
            list.Next();
        }
        return out;
    }
};

///////////////////////////////////////////////

template<typename TData, typename TKey>
TList<TData, TKey>::TList() :pFirst(0), pPrev(0), pCur(0), pNext(0) {}

template<typename TData, typename TKey>
TList<TData, TKey>::TList(const TNode<TData, TKey>* _node)
{
    TNode<TData, TKey>* node = _node;
    pFirst = new TNode<TData, TKey>(node->key, node->pData);
    pCur = pFirst;
    node = node->pNext;
    while (node != nullptr)
    {
        pCur->pNext = new TNode<TData, TKey>(node->key, node->pData);
        pCur = pCur->pNext;
        node = node->pNext;
    }
    Reset();
}

template<typename TData, typename TKey>
TList<TData, TKey>::TList(const TList<TData, TKey>& list)
{
    TNode<TKey, TData>* node = list.pFirst;
    pFirst = new TNode<TData, TKey>(node->key, node->pData);
    pCur = pFirst;
    node = node->pNext;
    while (node != nullptr)
    {
        pCur->pNext = new TNode<TData, TKey>(node->key, node->pData);
        pCur = pCur->pNext;
        node = node->pNext;
    }
    Reset();
}

template<typename TData, typename TKey>
TList<TData, TKey>::~TList()
{
    Reset();
    while (pFirst != nullptr)
    {
        pNext = pFirst->pNext;
        delete pFirst;
        pFirst = pNext;
    }
}

template<typename TData, typename TKey>
bool TList<TData, TKey>::IsEnded() const
{
    return(pCur == nullptr);
}

template<typename TData, typename TKey>
void TList<TData, TKey>::Reset()
{
    pPrev = nullptr;
    pCur = pFirst;
    if (pFirst != nullptr)
        pNext = pCur->pNext;
    else
        pNext = nullptr;
}

template<typename TData, typename TKey>
void TList<TData, TKey>::Next()
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

template<class TData, class TKey>
TNode<TData, TKey>* TList<TData, TKey>::Search(TKey fkey)
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


template<typename TData, typename TKey>
void TList<TData, TKey>::InsertEnd(TKey _key, TData* _pData) //v konec
{
    if (pFirst == nullptr)
    {
        pFirst = new TNode<TData, TKey>(_key, _pData);
        pCur = pFirst;
        return;
    }
    TNode<TData, TKey>* fpPrev = pPrev;
    TNode<TData, TKey>* fpCur = pCur;
    TNode<TData, TKey>* fpNext = pNext;
    Reset();
    while (!IsEnded())
        Next();
    TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData);
    pPrev->pNext = node;

    pPrev = fpPrev;
    pCur = fpCur;
    if (pCur->pNext == nullptr)
        pNext = node;
    else pNext = fpNext;
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertFirst(TKey _key, TData* _pData)// v nachalo
{
    TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, pFirst);
    if (pCur == pFirst)
    {
        pPrev = node;
    }
    pFirst = node;
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertAfter(TKey fkey, TData* _pData, TKey _key)
{
    if (pFirst == 0)
        throw "The list is empty";

    TNode<TData, TKey>* fpPrev = pPrev;
    TNode<TData, TKey>* fpCur = pCur;
    TNode<TData, TKey>* fpNext = pNext;

    Reset();
    while (!IsEnded())
    {
        if (pCur->key == fkey)
        {
            TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, pNext);
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

template<class TData, class TKey>
void TList<TData, TKey>::InsertBefore(TKey fkey, TData* _pData, TKey _key)
{
    if (pFirst == 0)
        throw "The list is empty";
    TNode<TData, TKey>* fpFirst = pFirst;
    TNode<TData, TKey>* fpPrev = pPrev;
    TNode<TData, TKey>* fpCur = pCur;
    TNode<TData, TKey>* fpNext = pNext;

    Reset();
    if (pCur->key == fkey)
    {
        TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, pCur);
        pFirst = node;

        if (fpCur == fpFirst)
            pPrev = node;
        else
            pPrev = fpPrev;////
        pCur = fpCur;
        pNext = fpNext;
        return;
    }
    while (pCur->pNext != nullptr)
    {
        if (pNext->key == fkey)
        {
            TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, pNext);
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

template<class TData, class TKey>
void TList<TData, TKey>::Remove(TKey fkey)
{
    if (pFirst == nullptr)
        throw "The list is empty";

    TNode<TData, TKey>* fpFirst = pFirst;
    TNode<TData, TKey>* fpPrev = pPrev;
    TNode<TData, TKey>* fpCur = pCur;
    TNode<TData, TKey>* fpNext = pNext;

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
			fpFirst = pCur;
        }
   		else if (fpCur == pFirst->pNext)
   		{
   			fpPrev = nullptr;
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

	if (fpPrev == pCur)
	{
		delete pCur;
		pCur = fpCur;
		pPrev->pNext = pCur;
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

	if (fpNext == pCur)
	{
		delete pCur;
		pCur = fpCur;
		pCur->pNext = pNext;
		pPrev = fpPrev;
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

#endif
