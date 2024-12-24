#include "List.h"

template <typename T>
List<T>::List() {
    pFirst = nullptr;
}

template <typename T>
List<T>::List(const T& x) {
    pFirst = new ListNode<T>(x);
}

template <typename T>
List<T>::~List() {
    while (pFirst != nullptr) {
        TNode<T>* tmp = pFirst;
        pFirst = pFirst->pNext;
        delete tmp;
    }
}

template <typename T>
const List<T>& List<T>::operator=(const List<T>& list) {
    if (this == &list) {
        return *this;
    }
    if (this != &list) {
        TNode* curr = pFirst;
        while (curr != nullptr) {
            TNode* tmp = curr;
            curr = curr->pNext;
            delete tmp->data;
            delete tmp;
        }
        pFirst = new TNode<T>{ *list.pFirst };
        TNode<T>* tmp = pFirst;
        while (tmp->pNext != nullptr) {
            tmp->pNext = new TNode{ *tmp->pNext };
            tmp = tmp->pNext;
        }
        sz = list.sz;
    }
    return *this;

}
template <typename T>
bool List<T>::operator==(const List<T>& list) {
    TNode* curr1 = pFirst, * curr2 = list.pFirst;;
    if (sz != list.sz) {
        return false;
    }
    if (curr1 != nullptr && curr2 != nullptr) {
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->data != curr2->data) {
                return false;
            }
            curr1 = curr1->pNext;
            curr2 = curr2->pNext;
        }
    }
    return true;

}

template <typename T>
void List<T>::pushFront(TNode<T>* pNode) {
    if (pFirst == nullptr) {
        pFirst = pNode;
        return;
    }
    pNode->pNext = pFirst;
    pFirst = pNode;
}

template <typename T>
void List<T>::pushBack(TNode<T>* pNode) {
    if (pFirst == nullptr) {
        pFirst = pNode;
        return;
    }
    TNode<T>* curr = pFirst;
    while (curr->pNext != nullptr) {
        curr = curr->pNext;
    }
    curr->pNext = pNode;
}

template <typename T>
void List<T>::insertAfter(TNode<T>* pNode, int key) {
    TNode<T>* curr = pFirst;
    while ((curr != nullptr) && (curr->key != key)) {
        curr = curr->pNext;
    }
    if (curr == nullptr) {
        throw std::exception("curr nullptr");
    }
    pNode->pNext = curr->pNext;
    curr->pNext = pNode;
}

template <typename T>
void List<T>::insertBefore(TNode<T>* pNode, int key) {
    TNode<T>* prev = nullptr, * curr = pFirst;
    while (curr != nullptr && curr->key != key) {
        prev = curr;
        curr = curr->pNext;
    }
    if (curr == nullptr) {
        throw std::exception("Key not found");
    }
    if (prev == nullptr) {
        pNode->pNext = pFirst;
        pFirst = pNode;
        return;
    }
    pNode->pNext = curr;
    prev->pNext = pNode;
}

template <typename T>
void List<T>::remove(int key) {
    if (pFirst == nullptr) {
        throw std::exception("pFirst nullptr");
    }
    TNode<T>* prev = nullptr, * curr = pFirst;
    while (curr != nullptr && curr->key != key) {
        prev = curr;
        curr = curr->pNext;
    }
    if (curr == nullptr) {
        throw std::exception("Key not found");
    }
    if (prev == nullptr) {
        pFirst = pFirst->pNext;
        delete curr;
        return;
    }
    prev->pNext = curr->pNext;
    delete curr;
}

template <typename T>
T List<T>::reset() const {
    if (pFirst == nullptr) {
        throw "Error";
    }
    return pFirst->key;
}

template <typename T>
bool List<T>::IsEmpty() const {
    return (pFirst == nullptr);
}

template <typename T>
void List<T>::removefirst() {
    TNode<T>* tmp = pFirst;
    if (tmp == nullptr) {
        throw "empty list";
    }
    pFirst = pFirst->next;
    delete tmp;
}

template <typename T>
int List<T>::Size() {
    TNode<T>* curr = pFirst;
    int sz = 0;
    while (curr != nullptr) {
        curr = curr->pNext;
        sz++;
    }
    return sz;
}