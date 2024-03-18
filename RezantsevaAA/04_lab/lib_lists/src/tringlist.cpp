#include "tringlist.h"
/*
TRingList::TRingList(const TNode* pFirst_) {
    if (pFirst != nullptr) {
        TNode* pHead = new TNode();
        pHead->pNext = pFirst;
        SetPStop(pHead);
        TNode* tmp = pFirst;

        while (tmp->pNext != nullptr) {
            tmp = tmp->pNext;
        }

        tmp->pNext = pHead;
        SetPLast(tmp);
    }
}

TRingList::TRingList() {
    pHead->pNext = pFirst;
    pLast->pNext = pHead;
    pStop = pHead;
    Reset();
}

TRingList::TRingList(const TList* List) {
    TRingList rl = new TList(*List);
    pFirst = rl.pCur;
    TRingList();
    pCur = pFirst;
   
}
//?
TRingList::TRingList(const TRingList& ringList) {
    if (ringList.pFirst == nullptr)
    {
        return;
    }
    TNode* oldCurrent = ringList.pFirst;
    pHead = nullptr;
    pHead->pNext = new TNode(*ringList.pFirst);
    TNode* newCurrent = pHead->pNext;
    oldCurrent = oldCurrent->pNext;
    while (oldCurrent != ringList.pStop)
    {
        newCurrent->pNext = new TNode(oldCurrent->data);
        newCurrent = newCurrent->pNext;
        oldCurrent = oldCurrent->pNext;
    }
    pLast = newCurrent;
    pLast->pNext = pHead;
    pStop = pLast->pNext;
    pStop = pHead;
    pCur = pFirst;
}
*/