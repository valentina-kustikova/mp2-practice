#include "List.h"

template <typename T>
List<T>::List() {
    pFirst = nullptr;
    size = 0;
}

template <typename T>
List<T>::~List() {
    TNode* curr = pFirst;
    while (curr != nullptr) {
        TNode* tmp = curr;
        curr = curr->pNext;
        delete tmp->data;
        delete tmp;
    }
}

template <typename T>
void List<T>::print(TNode* pFirst) {
    TNode* tmp = pFirst;
    while (tmp != nullptr) {
        std::cout << tmp->key << std::endl;
        tmp = tmp->pNext;
    }
}

template <typename T>
typename List<T>::TNode* List<T>::search(TNode* pFirst, int key) {
    TNode* curr = pFirst;
    while (curr != nullptr) {
        if (curr->key == key) {
            return curr;
        }
        curr = curr->pNext;
    }
    return nullptr;
}

template <typename T>
void List<T>::pushFront(TNode*& pFirst, TNode* pNode) {
    if (pFirst == nullptr) {
        throw std::exception("pFirst nullptr");
    }
    pNode->pNext = pFirst;
    pFirst = pNode;
}

template <typename T>
void List<T>::pushBack(TNode*& pFirst, TNode* pNode) {
    if (pFirst == nullptr) {
        pFirst = pNode;
        return;
    }
    TNode* curr = pFirst;
    while (curr->pNext != nullptr) {
        curr = curr->pNext;
    }
    curr->pNext = pNode;
}

template <typename T>
void List<T>::inseartAfter(TNode*& pFirst, TNode* pNode, int key) {
    TNode* curr = search(pFirst, key);
    if (curr == nullptr) {
        throw std::exception("curr nullptr");
    }
    pNode->pNext = curr->pNext;
    curr->pNext = pNode;
}

template <typename T>
void List<T>::inseartBefore(TNode*& pFirst, TNode* pNode, int key) {
    TNode* prev = nullptr, * curr = pFirst;
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
void List<T>::remove(TNode*& pFirst, TNode* pNode, int key) {
    if (pFirst == nullptr) {
        throw std::exception("pFirst nullptr");
    }
    TNode* prev = nullptr, * curr = pFirst;
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
