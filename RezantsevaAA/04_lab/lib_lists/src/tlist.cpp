#include "tlist.h"
/*
TList::TList() {

}

TList::TList(const TNode* pFirst_) {
    pFirst = (TNode*)pFirst_;
    pCur = pFirst;
    while (pCur->pNext != nullptr)
    {
        Next();
    }
    pLast = pCur;
    pCur = pFirst;
    pStop = pPrev = nullptr;
}

TList::TList(const TList& pList) {
    if (pList.pFirst == nullptr)
    {
        return;
    }
    TNode* oldCurrent = pList.pFirst;
    pFirst = new TNode(*pList.pFirst);
    TNode* newCurrent = pFirst;
    oldCurrent = oldCurrent->pNext;
    while (oldCurrent != pList.pStop)
    {
        newCurrent->pNext = new TNode(oldCurrent->data);
        newCurrent = newCurrent->pNext;
        oldCurrent = oldCurrent->pNext;
    }
    pLast = newCurrent;
    pStop = pLast->pNext;
    pCur = pFirst;
    pStop = nullptr;
}

void TList::Clear() {
    if (pFirst == nullptr)
    {
        return;
    }
    pCur = pFirst;
    TNode* tmp = pCur;
    while (pCur != pStop) {
        pCur = pCur->pNext;
        delete tmp;
        tmp = pCur;
    }
    pCur = pStop;
    pLast = pStop;
    pFirst = pStop;
}

TList::~TList()
{
    Clear();
}

//Functions
std::ostream& operator<<(std::ostream& out, const TList& list) {
    TNode* tmp = list.pFirst;
    while (tmp != list.pStop)
    {
        out << tmp->data << " ";
        tmp = tmp->pNext;
    }
    return out;
}
void TList::Next() {
    if (pCur == pStop)
    {
        return;
    }
    pPrev = pCur;
    pCur = pCur->pNext;
}
bool TList::is_Full() const {
    try
    {
        TNode* tmp = new TNode();
        if (tmp == 0)
            return 1;
        else
        {
            delete tmp;
            return 0;
        }
    }
    catch (...)
    {
        return 0;
    }
    return true;
}
bool TList::is_Empty() const {
    if (pFirst == pStop)
        return true;
    else
        return false;
}

TNode* TList::Search(const PTData& data_) {
    pCur = pFirst;
    while ((pCur != pStop) && (pCur->data != data_))
    {
        Next(); //pCur = pCur->pNext;
    }
    return pCur;
}

void TList::Remove(const PTData& data_) {
    if (data_ != nullptr) {
       pCur = Search(data_);
       delete pCur->data;
       delete pCur;
    }
}

//INSERT
void TList::InsertFirst(const PTData& data_) {
    if (is_Full()) {
        throw "Error. Memory is not enough";
    }
    TNode* newNode = new TNode(data_, nullptr);

    if (pFirst != pStop)
    {
        TNode* oldPFirst = pFirst;
        pFirst = newNode;
        pFirst->pNext = oldPFirst;

    }
    else {
        pFirst = newNode;
    }
    pCur = pFirst;
    if (pLast == pStop) {
        pLast = pFirst;
    };
}
void TList::InsertLast(const PTData& data_) {
    if (is_Empty())
    {
        InsertFirst(data_);
        pLast = pFirst;
        return;
    }
    TNode* newNode = new TNode(data_, nullptr);
    pLast->pNext = newNode;
}
void TList::InsertBefore(const PTData& data_, const PTData& NextData) {
    if (is_Empty()) {
        throw "Error. List is empty.";
    }
    pCur = pFirst;
    TNode* pPrev = nullptr;
    while ((pCur->pNext != pStop) && (pCur->data!= NextData))
    {
        pPrev = pCur;
        Next();
    }
    if ((pCur->pNext == pStop) && (pCur->data != NextData))
    {
        throw "Error. Key not found.";
    }
    TNode* newNode = new TNode(data_, pCur);

    // list have only 1 node
    if (pPrev == pStop) {
        pFirst = newNode;
    }
    else {
        pPrev->pNext = newNode;
    }
    pCur = pFirst;
}

void TList::InsertAfter(const PTData& data_, const PTData& PrevData) {
    TNode* prNode = Search(PrevData);
    if (prNode == pStop)
    {
        return;
    }
    TNode* tmp = new TNode(data_, prNode->pNext);
    prNode->pNext = tmp;
}

//Get & Reset

TNode* TList::GetCurrent() const{
    return pCur;
}

const int TList::GetSize() const {
    return ListLen;
}

void TList::Reset() {
    if (is_Empty()) {
        pCur = pStop;
    }
    else {
        pCur = pFirst;
    }
    return;
}

bool TList::is_End() const{
    return pCur == pStop;
}
//Insert
void TList::InsertBeforeCurrent(const PTData& data_) {  //????
    if (is_Empty()) {
        InsertFirst(data_);
    }
    else if (is_End()) {
        InsertLast(data_);
    }
    else {
        TNode* newNode = new TNode(data_, pCur); //pCur->pNext;
        if (newNode == NULL) {
            throw "Error. List doesn't have memory";
        }
        else {
            pCur = newNode;
            pPrev->SetNext(newNode);
            ListLen++;
        }
    }
    pCur = pFirst;
}

void TList::InsertAfterCurrent(const PTData& data_) { //????
    if (is_Empty()) {
        InsertFirst(data_);
    }
    else if (is_End()) {
        InsertLast(data_);
    }
    else {
        TNode* newNode = new TNode(data_, pCur->pNext); //pCur->pNext;
        if (newNode == NULL) {
            throw "Error. List doesn't have memory";
        }
        else {
            pCur->SetNext(newNode); //pCur->pNext = newNode
            pCur = newNode;
            ListLen++;
        }
    }
}


TNode* TList::GetPStop()const {
    return pStop;
}
TNode* TList::GetPFirst()const {
    return pFirst;
}

void TList::SetPStop(TNode* _pStop) {
    pStop = _pStop;
}
void TList::SetPLast(TNode* _pLast) {
    pLast = _pLast;
}
*/