#ifndef TRINGLIST_H
#define TRINGLIST_H

#include "tlist.h"

template <typename T>
class TRingList : public TList<T> {
protected:
    TNode<T>* pHead;  // Фиктивное звено

public:
    TRingList();
    TRingList(TNode<T>* _pFirst);
    TRingList(const TRingList<T>& list);
    virtual ~TRingList();

    TNode<T>* Search(const T& data) override;
    void InsertFirst(const T& data) override;
    void InsertLast(const T& data) override;
    void InsertBefore(const T& data) override;
    void InsertAfter(const T& data) override;
    void InsertBefore(const T& data, const T& before) override;
    void InsertAfter(const T& data, const T& after) override;
    void Remove(const T& data) override;
    void Clear() override;

    bool IsEmpty() const override;

    void Reset() override;
    void Next(const int count = 1) override;
    bool IsEnded() const override;

    TNode<T>* head() const { return pHead };
};

template <typename T>
TRingList<T>::TRingList() {
    pHead = new TNode<T>();
    pHead->pNext = pHead;
    pFirst = pHead;
    pLast = pHead;
    pStop = pHead;
    pCurr = pHead;
}

template <typename T>
TRingList<T>::TRingList(TNode<T>* _pFirst) {
    pHead = new TNode<T>();
    pHead->pNext = pHead;
    pFirst = pHead;
    pLast = pHead;
    pStop = pHead;
    pCurr = pHead;

    if (_pFirst != nullptr) {
        pFirst = _pFirst;
        TNode<T>* tmp = _pFirst;

        // Найдем последний узел в переданном списке
        while (tmp->pNext != nullptr) {
            tmp = tmp->pNext;
        }

        tmp->pNext = pHead; // Сделаем список кольцевым

        pLast = tmp;
    }

    Reset();
}

template <typename T>
TRingList<T>::TRingList(const TRingList<T>& obj) : TList<T>(obj) {
    pHead = new TNode<T>();
    pHead->pNext = pHead;
    pFirst = pHead;
    pLast = pHead;
    pStop = pHead;
    pCurr = pHead;

    TNode<T>* tmp = obj.pFirst;
    while (tmp != obj.pStop) {
        InsertLast(tmp->data);
        tmp = tmp->pNext;
    }
}

template <typename T>
TRingList<T>::~TRingList() {
    Clear();
    delete pHead;
}

template <typename T>
TNode<T>* TRingList<T>::Search(const T& data) {
    TNode<T>* tmp = pFirst;
    while (tmp != pHead) {
        if (tmp->data == data) {
            return tmp;
        }
        tmp = tmp->pNext;
    }
    return nullptr;  // Элемент не найден
}

template <typename T>
void TRingList<T>::InsertFirst(const T& data) {
    TNode<T>* tmp = new TNode<T>(data, pHead->pNext);
    pHead->pNext = tmp;
    if (pFirst == pHead) {
        pLast = tmp;
    }
    pFirst = tmp;
    Reset();
}

template <typename T>
void TRingList<T>::InsertLast(const T& data) {
    TNode<T>* tmp = new TNode<T>(data, pHead);
    pLast->pNext = tmp;
    pLast = tmp;
    if (pFirst == pHead) {
        pFirst = tmp;
    }
    Reset();
}

template <typename T>
void TRingList<T>::InsertBefore(const T& data) {
    if (pCurr == pHead) {
        InsertLast(data);
        return;
    }

    TNode<T>* before = pHead;
    while (before->pNext != pCurr) {
        before = before->pNext;
    }

    TNode<T>* tmp = new TNode<T>(data, pCurr);
    before->pNext = tmp;

    if (pCurr == pFirst) {
        pFirst = tmp;
    }

    Reset();
}

template <typename T>
void TRingList<T>::InsertAfter(const T& data) {
    TNode<T>* tmp = new TNode<T>(data, pCurr->pNext);
    pCurr->pNext = tmp;
    if (pCurr == pLast) {
        pLast = tmp;
    }
    Reset();
}

template <typename T>
void TRingList<T>::InsertBefore(const T& data, const T& before) {
    pCurr = Search(before);
    if (pCurr == nullptr) {
        std::string exp = "Error: Element not found";
        throw exp;
    }

    InsertBefore(data);
    Reset();
}

template <typename T>
void TRingList<T>::InsertAfter(const T& data, const T& after) {
    pCurr = Search(after);
    if (pCurr == nullptr) {
        std::string exp = "Error: Element not found";
        throw exp;
    }

    InsertAfter(data);
    Reset();
}

template <typename T>
void TRingList<T>::Remove(const T& data) {
    TNode<T>* pNode = pHead->pNext;
    TNode<T>* pPrev = pHead;

    while (pNode != pHead && pNode->data != data) {
        pPrev = pNode;
        pNode = pNode->pNext;
    }

    if (pNode == pHead) {
        std::string exp = "Error: data not found";
        throw exp;
    }

    pPrev->pNext = pNode->pNext;

    if (pNode == pLast) {
        pLast = pPrev;
    }

    if (pNode == pFirst) {
        pFirst = pNode->pNext;
    }

    delete pNode;
    Reset();
}

template <typename T>
void TRingList<T>::Clear() {
    TNode<T>* tmp = pHead->pNext;
    while (tmp != pHead) {
        TNode<T>* next = tmp->pNext;
        delete tmp;
        tmp = next;
    }
    pHead->pNext = pHead;
    pFirst = pHead;
    pLast = pHead;
    Reset();
}

template <typename T>
bool TRingList<T>::IsEmpty() const {
    return (pHead->pNext == pHead);
}

template <typename T>
void TRingList<T>::Reset() {
    pCurr = pHead->pNext;
}

template <typename T>
void TRingList<T>::Next(const int count) {
    for (int i = 0; i < count; ++i) {
        if (pCurr != pHead) {
            pCurr = pCurr->pNext;
        }
    }
}

template <typename T>
bool TRingList<T>::IsEnded() const {
    return (pCurr == pHead);
}

#endif // !TRINGLIST_H