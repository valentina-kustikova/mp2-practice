#pragma once

#include <iostream>

using namespace std;

template <typename T>
struct TNode {
    T Data;
    TNode* pNext;

    TNode() : Data(-1), pNext(nullptr) {}
    TNode(const T& data) : Data(data), pNext(nullptr) {}
};

template <typename T>
class TList {
private:
    TNode<T>* pFirst;
public:
    TList() : pFirst() {}

    TList(const T& data) {
        pFirst = new TNode<T>(data);
    }

    TList(const TList<T>& list) : pFirst(nullptr) {
        if (list.pFirst == nullptr) {
            pFirst = nullptr;
            return;
        }
        pFirst = new TNode<T>(list.pFirst->Data);
        TNode<T>* curr = pFirst;
        TNode<T>* listcurr = list.pFirst->pNext;

        while (listcurr != nullptr) {
            curr->pNext = new TNode<T>(listcurr->Data);
            curr = curr->pNext;
            listcurr = listcurr->pNext;
        }
    }

    ~TList() {
        TNode<T>* tmp;
        while (pFirst != nullptr)
        {
            tmp = pFirst->pNext;
            delete pFirst;
            pFirst = tmp;
        }
    }

    const TList<T>& operator=(const TList& list) {
        if (this == &list) {
            return *this;
        }
        while (pFirst) {
            TNode<T>* tmp = pFirst;
            pFirst = pFirst->pNext;
            delete tmp;
        }
        pFirst = nullptr;
        TNode<T>* curr = list.pFirst;
        while (curr) {
            pushBack(curr->Data);
            curr = curr->pNext;
        }
        return *this;
    }

    bool operator==(const TList<T>& list) const {
        if (size() != list.size()) return 0;
        TNode<T>* curr = pFirst;
        TNode<T>* listcurr = list.pFirst;
        while (listcurr) {
            if (curr->Data != listcurr->Data) {
                return 0;
            }
            curr = curr->pNext;
            listcurr = listcurr->pNext;
        }
        return 1;
    }

    void pushFront(const T& data) {
        TNode<T>* node = new TNode<T>(data);
        if (pFirst == nullptr) {
            pFirst = node;
            return;
        }
        if (node == nullptr) {
            throw "node is empty";
        }
        node->pNext = pFirst;
        pFirst = node;
    }

    void pushBack(const T& data) {
        TNode<T>* node = new TNode<T>(data);
        if (pFirst == nullptr) {
            pFirst = node;
            return;
        }
        if (node == nullptr) return;
        TNode<T>* curr = pFirst;
        while (curr->pNext != nullptr) {
            curr = curr->pNext;
        }
        curr->pNext = node;
    }

    void PopBack() {
        if (IsEmpty()) throw "List is empty";
        TNode<T>* curr = pFirst->pNext;
        TNode<T>* prevcurr = pFirst;
        if (curr == nullptr) {
            delete pFirst;
            pFirst = nullptr;
            return;
        }
        while (curr->pNext != nullptr) {
            prevcurr = curr;
            curr = curr->pNext;
        }
        delete curr;
        prevcurr->pNext = nullptr;
    }

    void PopFront() {
        if (IsEmpty()) throw "List is empty";
        TNode<T>* tmp = pFirst->pNext;
        delete pFirst;
        pFirst = tmp;
    }

    bool IsEmpty() const {
        if (pFirst == nullptr) return 1;
        return 0;
    }

    T getData() const {
        return pFirst->Data;
    }

    TNode<T>* getHead() const {
        return pFirst;
    }

    size_t size() const {
        TNode<T>* curr = pFirst;
        size_t n = 0;
        while (curr != nullptr) {
            n++;
            curr = curr->pNext;
        }
        return n;
    }
};
