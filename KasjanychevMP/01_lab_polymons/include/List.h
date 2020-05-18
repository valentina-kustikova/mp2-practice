#pragma once
#include <iostream>
using namespace std;

template<class Tkey, class TData>
class TNode {
public:
    Tkey key;
    TData* pData;
    TNode* pNext;

    TNode();
    TNode(const TNode&);
    TNode(Tkey, TData*, TNode* _pNext = 0);
    ~TNode();

    friend ostream& operator<<(ostream& out, TNode<Tkey, TData>& node) {
        out << node.key << " - " << node.pData[0];
        return out;
    }
};

template<class Tkey, class TData>
TNode<Tkey, TData>::TNode() {
    pData = new TData;
    pNext = NULL;
}

template<class Tkey, class TData>
TNode<Tkey, TData>::TNode(const TNode& node) {
    key = node.key;
    pData = new TData;
    pData = node.pData;
    pNext = NULL;
}

template<class Tkey, class TData>
TNode<Tkey, TData>::TNode(Tkey _key, TData* _pData, TNode* _pNext) {
    key = _key;
    pData = new TData(*_pData);
    pNext = _pNext;
}

template<class Tkey, class TData>
TNode<Tkey, TData>::~TNode() {
    delete pData;
}


template<class Tkey, class TData>
class TList {
private:
    TNode<Tkey, TData>* pFirst;
    TNode<Tkey, TData>* pPrev;
    TNode<Tkey, TData>* pCurr;
    TNode<Tkey, TData>* pNext;
public:
    TList();
    TList(const TList&);
    TList(TNode<Tkey, TData>* list);
    ~TList();

    void Next();
    void Reset();
    bool IsEnded() const;
    void Back(Tkey _key, TData* pData);
    TNode<Tkey, TData>* Search(Tkey _key);
    void Push(Tkey _key, TData* pData);
    void InsertAfter(Tkey, TData*, Tkey);
    void InsertBefore(Tkey, TData*, Tkey);
    void Remove(Tkey);

    friend ostream& operator<<(ostream& out, TList<Tkey, TData>& list) {
        list.Reset();
        while (!(list.IsEnded())) {
            //out << list.pCurr->key << " - " << list.pCurr->pData << endl;
            out << (*list.pCurr) << endl;
            list.Next();
        }
        return out;
    }
};

template <class Tkey, class TData>
TList<Tkey, TData>::TList() {
    pFirst = NULL;
    pPrev = NULL;
    pCurr = NULL;
    pNext = NULL;
}

template <class Tkey, class TData>
TList<Tkey, TData>::TList(TNode<Tkey, TData>* list) {
    pFirst = list;
    pCurr = pFirst;
    pPrev = NULL;
    pNext = pFirst->pNext;
}

template <class Tkey, class TData>
TList<Tkey, TData>::TList(const TList<Tkey, TData>& list) {
    pFirst = new TNode<Tkey, TData>(*(list.pFirst));
    pCurr = pFirst;
    TNode<Tkey, TData>* node = list.pFirst;
    node = node->pNext;
    while (node != NULL) {
        pCurr->pNext = new TNode<Tkey, TData>(*node);
        pCurr = pCurr->pNext;
        node = node->pNext;
    }
    Reset();
}

template <class Tkey, class TData>
TList<Tkey, TData>::~TList() {
    Reset();
    while (!IsEnded()) {
        delete pCurr->pData;
        Next();
    }
    pFirst = NULL;
}

template <class Tkey, class TData>
bool TList<Tkey, TData>::IsEnded() const {
    return pCurr == NULL;
}

template <class Tkey, class TData>
void TList<Tkey, TData>::Next() {
    if (IsEnded()) return;
    pPrev = pCurr;
    pCurr = pCurr->pNext;
    if (pNext != NULL) pNext = pNext->pNext;
}

template <class Tkey, class TData>
void TList<Tkey, TData>::Reset() {
    pPrev = NULL;
    pCurr = pFirst;
    if (pFirst != NULL) pNext = pCurr->pNext;
    else pNext = NULL;
}

template <class Tkey, class TData>
void TList<Tkey, TData>::Back(Tkey _key, TData * _pData) {
    if (pFirst == NULL) {
        pFirst = new TNode<Tkey, TData>(_key, _pData);
        pCurr = pFirst;
        return;
    }
    TNode<Tkey, TData>* _pPrev = pPrev;
    TNode<Tkey, TData>* _pCurr = pCurr;
    TNode<Tkey, TData>* _pNext = pNext;
    while (!IsEnded()) Next();
    pCurr = new TNode<Tkey, TData>(_key, _pData);
    pPrev->pNext = pCurr;
    pPrev = _pPrev;
    pCurr = _pCurr;
    pNext = _pNext;
}

template <class Tkey, class TData>
TNode<Tkey, TData>* TList<Tkey, TData>::Search(Tkey _key) {
    Reset();
    while (!IsEnded()) {
        if (pCurr->key == _key) return pCurr;
        Next();
    }
    Reset();
    return NULL;
}

template <class Tkey, class TData>
void TList<Tkey, TData>::Push(Tkey _key, TData * _pData) {
    TNode<Tkey, TData>* tmp = new TNode<Tkey, TData>(_key, _pData, pFirst);
    if (pCurr == pFirst) pPrev = tmp;
    pFirst = tmp;
}

template <class Tkey, class TData>
void TList<Tkey, TData>::InsertAfter(Tkey _key, TData * _pData, Tkey key1) {
    if (pFirst == NULL) throw "osh";
    TNode<Tkey, TData> * _pPrev = pPrev;
    TNode<Tkey, TData> * _pCurr = pCurr;
    TNode<Tkey, TData> * _pNext = pNext;
    if (Search(key1) == 0) {
        pPrev = _pPrev;
        pCurr = _pCurr;
        pNext = _pNext;
        return;
    }
    TNode<Tkey, TData>* tmp = new TNode<Tkey, TData>(_key, _pData, pNext);
    pCurr->pNext = tmp;
    pPrev = _pPrev;
    pCurr = _pCurr;
    pNext = _pNext;
}

template <class Tkey, class TData>
void TList<Tkey, TData>::InsertBefore(Tkey _key, TData * _pData, Tkey key1) {
    if (pFirst == NULL) throw "osh";
    TNode<Tkey, TData> * _pPrev = pPrev;
    TNode<Tkey, TData> * _pCurr = pCurr;
    TNode<Tkey, TData> * _pNext = pNext;
    if (Search(key1) == 0) {
        pPrev = _pPrev;
        pCurr = _pCurr;
        pNext = _pNext;
        return;
    }
    if (pFirst == pCurr) {
        TNode<Tkey, TData>* tmp = new TNode<Tkey, TData>(_key, _pData, pFirst);
        if (_pCurr == pFirst) pPrev = tmp;
        else {
            pPrev = _pPrev;
            pCurr = _pCurr;
            pNext = _pNext;
        }
        pFirst = tmp;
        return;
    }
    TNode<Tkey, TData>* tmp = new TNode<Tkey, TData>(_key, _pData, pCurr);
    pPrev->pNext = tmp;
    pPrev = _pPrev;
    pCurr = _pCurr;
    pNext = _pNext;
}

template <class Tkey, class TData>
void TList<Tkey, TData>::Remove(Tkey _key) {
    if (pFirst == NULL) {
        throw "osh";
        return;
    }
    TNode<Tkey, TData>* _pPrev = pPrev;
    TNode<Tkey, TData>* _pCurr = pCurr;
    TNode<Tkey, TData>* _pNext = pNext;
    if (Search(_key) == 0) {
        pPrev = _pPrev;
        pCurr = _pCurr;
        pNext = _pNext;
        return;
    }
    if (pFirst == pCurr) {
        if (pNext != NULL) pNext = pNext->pNext;
        pCurr = pNext;
        delete pFirst;
        pFirst = pCurr;
        return;
    }
    if (_pCurr == pCurr) {
        delete pCurr;
        pCurr = _pNext;
        if (pNext != NULL) pNext = pNext->pNext;
        pPrev->pNext = pCurr;
        return;
    }
    pPrev->pNext = pCurr->pNext;
    delete pCurr;
    pCurr = pNext;
    if (pNext != NULL) pNext = pNext->pNext;
    pPrev = _pPrev;
    pCurr = _pCurr;
    pNext = _pNext;
}#pragma once
