#ifndef _TABRECORDLIST_H_
#define _TABRECORDLIST_H_

#include "tabrecordlink.h"

template<typename TKey, class TData>
class TTabRecordList
{
protected:
    TTabRecordLink<TKey, TData>* pFirst;
    TTabRecordLink<TKey, TData>* pCurrent;
    TTabRecordLink<TKey, TData>* pNext;
    TTabRecordLink<TKey, TData>* pPrev;

public:
    TTabRecordList();
    TTabRecordList(const TTabRecordList&);
    TTabRecordList(const TTabRecordLink<TKey, TData>*);
    ~TTabRecordList();

    void Reset();
    void Next();
    bool IsEnded() const;
    
    bool IsEmpty() const { return pFirst? false : true; }

    TTabRecordLink<TKey, TData>* GetFirst() const { return pFirst; }
    TTabRecordLink<TKey, TData>* GetCurrent() const { return pCurrent; }

    TTabRecordLink<TKey, TData>* Search(TKey);
    void PushBegin(TKey, TData*);
    void PushEnd(TKey, TData*);
    void PushBefore(TKey, TKey, TData*);
    void PushAfter(TKey, TKey, TData*);
    void Delete(TKey);
};
//-----------------------------------------------------------------

template<typename TKey, class TData>
TTabRecordList<TKey, TData>::TTabRecordList()
{
    pFirst = pNext = pPrev = pCurrent = nullptr;
};

template<typename TKey, class TData>
TTabRecordList<TKey, TData>::TTabRecordList(const TTabRecordList& _copy)
{
    pNext = pPrev = pCurrent = nullptr;

    if (!_copy.pFirst)
        pFirst = nullptr;
    else
    {
        pFirst = new TTabRecordLink<TKey, TData>(*_copy.pFirst);
        pFirst->pNext = nullptr;
        pCurrent = pFirst;

        TTabRecordLink<TKey, TData>* iter = new TTabRecordLink<TKey, TData>;
        iter = _copy.pFirst;

        while (iter->pNext)
        {
            iter = iter->pNext;
            pCurrent->pNext = new TTabRecordLink<TKey, TData>(*iter);

            pPrev = pCurrent;
            pCurrent = pCurrent->pNext;
            pNext = pCurrent->pNext = nullptr;
        }

        pPrev = nullptr;
        pCurrent = pFirst;
        pNext = pFirst->pNext;
    }
};

template<typename TKey, class TData>
TTabRecordList<TKey, TData>::TTabRecordList(const TTabRecordLink<TKey, TData>* _node)
{
    pNext = pPrev = pCurrent = nullptr;

    if (!_node)
        pFirst = nullptr;
    else
    {
        TTabRecordLink<TKey, TData>* node = new TTabRecordLink<TKey, TData>(*_node);
        pFirst = node;

        TTabRecordLink<TKey, TData>* iter = _node->pNext;
        TTabRecordLink<TKey, TData>* prev = pFirst;

        while (iter)
        {
            TTabRecordLink<TKey, TData>* tmp = new TTabRecordLink<TKey, TData>(*iter);
            prev->pNext = tmp;
            prev = tmp;
            iter = iter->pNext;
        }

        pCurrent = pFirst;
        pNext = pCurrent->pNext;
    }
};

template<typename TKey, class TData>
TTabRecordList<TKey, TData>::~TTabRecordList()
{
    this->Reset();
    while (!this->IsEnded())
    {
        this->Next();
        delete pPrev;
    }

    delete pCurrent;

    pFirst = pNext = pPrev = pCurrent = nullptr;
};
//-----------------------------------------------------------------

template<typename TKey, class TData>
void TTabRecordList<TKey, TData>::Reset()
{
    pPrev = nullptr;
    pCurrent = pFirst;
    if (pFirst)
        pNext = pCurrent->pNext;
    else
        pNext = nullptr;
};

template<typename TKey, class TData>
void TTabRecordList<TKey, TData>::Next()
{
    pPrev = pCurrent;
    pCurrent = pNext;

    if (pCurrent)
        pNext = pCurrent->pNext;
    else
        pNext = nullptr;
};

template<typename TKey, class TData>
bool TTabRecordList<TKey, TData>::IsEnded() const
{
    return (pCurrent == nullptr);
};
//-----------------------------------------------------------------

template<typename TKey, class TData>
TTabRecordLink<TKey, TData>* TTabRecordList<TKey, TData>::Search(TKey _key)
{
    TTabRecordLink<TKey, TData>* tmppCurrent = pCurrent;
    TTabRecordLink<TKey, TData>* tmppNext = pNext;
    TTabRecordLink<TKey, TData>* tmppPrev = pPrev;

    this->Reset();

    while (!this->IsEnded())
    {
        if (_key == pCurrent->key)
        {
            TTabRecordLink<TKey, TData>* findNode = pCurrent;
            pCurrent = tmppCurrent;
            pNext = tmppNext;
            pPrev = tmppPrev;

            return findNode;
        }

        this->Next();
    }

    pCurrent = tmppCurrent;
    pNext = tmppNext;
    pPrev = tmppPrev;

    return nullptr;
};

template<typename TKey, class TData>
void TTabRecordList<TKey, TData>::PushBegin(TKey _key, TData* _data)
{
    TTabRecordLink<TKey, TData>* newNode = new TTabRecordLink<TKey, TData>(_key, _data, pFirst);

    if (pCurrent == pFirst)
        pPrev = newNode;

    pFirst = newNode;
};

template<typename TKey, class TData>
void TTabRecordList<TKey, TData>::PushEnd(TKey _key, TData* _data)
{
    TTabRecordLink<TKey, TData>* tmppCurrent = pCurrent;
    TTabRecordLink<TKey, TData>* tmppNext = pNext;
    TTabRecordLink<TKey, TData>* tmppPrev = pPrev;

    this->Reset();

    while (pNext)
        this->Next();

    TTabRecordLink<TKey, TData>* newNode = new TTabRecordLink<TKey, TData>(_key, _data);

    if (!pFirst)
        pFirst = newNode;
    else
        pCurrent->pNext = newNode;

    if (tmppCurrent == pCurrent)
        pNext = newNode;
    else
        pNext = tmppNext;

    pCurrent = tmppCurrent;
    pPrev = tmppPrev;
};

template<typename TKey, class TData>
void TTabRecordList<TKey, TData>::PushBefore(TKey _superKey, TKey _key, TData* _data)
{
    TTabRecordLink<TKey, TData>* tmppCurrent = pCurrent;
    TTabRecordLink<TKey, TData>* tmppNext = pNext;
    TTabRecordLink<TKey, TData>* tmppPrev = pPrev;

    this->Reset();

    if ((this->IsEnded()) || (pFirst->key == _superKey))
    {
        this->PushBegin(_key, _data);
        pCurrent = pFirst;
        return;
    }

    TTabRecordLink<TKey, TData>* nodeFind = Search(_superKey);

    if (!nodeFind)
    {
        throw Exception("Key didn't find!");
        return;
    }

    while (pCurrent != nodeFind)
        this->Next();

    TTabRecordLink<TKey, TData>* newNode = new TTabRecordLink<TKey, TData>(_key, _data, pCurrent);
    pPrev->pNext = newNode;

    if (tmppCurrent == pPrev)
        pNext = newNode;
    else
        pNext = tmppNext;

    if (tmppCurrent == pCurrent)
        pPrev = newNode;
    else
        pPrev = tmppPrev;

    pCurrent = tmppCurrent;
};

template<typename TKey, class TData>
void TTabRecordList<TKey, TData>::PushAfter(TKey _superKey, TKey _key, TData* _data)
{
    TTabRecordLink<TKey, TData>* tmppCurrent = pCurrent;
    TTabRecordLink<TKey, TData>* tmppNext = pNext;
    TTabRecordLink<TKey, TData>* tmppPrev = pPrev;

    this->Reset();

    TTabRecordLink<TKey, TData>* nodeFind = Search(_superKey);

    if (!nodeFind)
    {
        throw Exception("Key didn't find!");
        return;
    }

    while (pCurrent != nodeFind)
        this->Next();

    TTabRecordLink<TKey, TData>* newNode = new TTabRecordLink<TKey, TData>(_key, _data, pNext);
    pCurrent->pNext = newNode;

    if (tmppCurrent == pCurrent)
        pNext = newNode;
    else
        pNext = tmppNext;

    if (tmppCurrent == pNext)
        pPrev = newNode;
    else
        pPrev = tmppPrev;

    pCurrent = tmppCurrent;
};

template<typename TKey, class TData>
void TTabRecordList<TKey, TData>::Delete(TKey _key)
{
    if (!pFirst)
        throw Exception("List is empty!");

    if (pFirst->key == _key)
    {
        if (pCurrent == pFirst)
        {
            pCurrent = pNext;
            if (pNext)
                pNext = pNext->pNext;
            else
                pNext = nullptr;

            delete pFirst;
            pFirst = pCurrent;

            return;
        }

        if (pCurrent == pFirst->pNext)
        {
            pPrev = nullptr;

            delete pFirst;
            pFirst = pCurrent;

            return;
        }

        delete pFirst;

        return;
    }

    TTabRecordLink<TKey, TData>* tmppCurrent = pCurrent;
    TTabRecordLink<TKey, TData>* tmppPrev = pPrev;
    TTabRecordLink<TKey, TData>* tmppNext = pNext;

    this->Reset();

    TTabRecordLink<TKey, TData>* nodeFind = Search(_key);

    if (!nodeFind)
    {
        throw Exception("Key didn't find!");
        return;
    }

    while (pCurrent != nodeFind)
        this->Next();

    pPrev->pNext = pNext;

    if (tmppCurrent == pCurrent)
    {
        pCurrent = tmppNext;
        pNext = pCurrent->pNext;
        delete nodeFind;

        return;
    }

    if (tmppCurrent == pPrev)
    {
        pCurrent = pPrev;
        pPrev = tmppPrev;
        pNext = pCurrent->pNext;
        delete nodeFind;

        return;
    }

    if (tmppCurrent == pNext)
    {
        pCurrent = pNext;
        pNext = pCurrent->pNext;
        delete nodeFind;

        return;
    }

    if (tmppCurrent)
        pNext = tmppCurrent->pNext;
    else
        pNext = nullptr;

    pCurrent = tmppCurrent;
    delete nodeFind;

    return;
};

#endif
