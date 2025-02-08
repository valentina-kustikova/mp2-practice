#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

template <typename T>
class List
{
private:
    struct TNode
    {
        TNode* pNext;
        T data;
        TNode() :data(0), pNext(nullptr) {}
        TNode(const T& x) : data(x), pNext(nullptr) {}
    };
    TNode* pFirst;
    int sz;
public:
    List() : pFirst(nullptr), sz(0) {}
    List(const List<T>& list);
    ~List();
    
    
    void PushFront(const T& val);
    void PushBack(const T& val);
    void PopBack();
    void PopFront();
    void DelList();
    bool IsEmpty() const;
    int GetSZ() const;
    const List& operator=(const List<T>& list);
    bool operator==(const List<T>& list) const;
};

template <typename T>
List<T>::List(const List<T>& list) {
    pFirst = nullptr;
    sz = 0;
    TNode* curr = list.pFirst;
    while (curr != nullptr) {
        PushBack(curr->data);
        curr = curr->pNext;
    }
}

template <typename T>
List<T>::~List() {
    DelList();
}


template <typename T>
void List<T>::PushFront(const T& val) {
    TNode* newNode = new TNode(val);
    newNode->pNext = pFirst;
    pFirst = newNode;
    sz++;
}


template <typename T>
void List<T>::PushBack(const T& val) {
    TNode* newNode = new TNode(val);
    if (pFirst == nullptr) {
        pFirst = newNode;
    }
    else {
        TNode* curr = pFirst;
        while (curr->pNext != nullptr) {
            curr = curr->pNext;
        }
        curr->pNext = newNode;
    }
    sz++;
}


template <typename T>
void List<T>::PopBack() {
    if (pFirst == nullptr) return;
    if (pFirst->pNext == nullptr) {
        delete pFirst;
        pFirst = nullptr;
        sz = 0;
        return;
    }
    TNode* curr = pFirst;
    while (curr->pNext->pNext != nullptr) {
        curr = curr->pNext;
    }
    delete curr->pNext;
    curr->pNext = nullptr;
    sz--;
}


template <typename T>
void List<T>::PopFront() {
    if (pFirst == nullptr) return;
    TNode* temp = pFirst;
    pFirst = pFirst->pNext;
    delete temp;
    sz--;
}


template <typename T>
void List<T>::DelList() {
    while (pFirst != nullptr) {
        PopFront();
    }
}


template <typename T>
bool List<T>::IsEmpty() const {
    return pFirst == nullptr;
}

template <typename T>
int List<T>::GetSZ() const {
    return sz;
}



template <typename T>
const List<T>& List<T>::operator=(const List<T>& list) {
    if (this == &list) {
        return *this;
    }
    DelList();
    TNode* curr = list.pFirst;
    while (curr != nullptr) {
        PushBack(curr->data);
        curr = curr->pNext;
    }
    return *this;
}


template <typename T>
bool List<T>::operator==(const List<T>& list) const {
    if (sz != list.sz) return false;
    TNode* curr = pFirst;
    TNode* curr2 = list.pFirst;
    while (curr != nullptr) {
        if (curr->data != curr2->data) return false;
        curr = curr->pNext;
        curr2 = curr2->pNext;
    }
    return true;
}

#endif