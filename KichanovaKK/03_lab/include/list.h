#pragma once
template <typename T>
struct TNode {
    T key;
    TNode* pNext;
    TNode() :key(0), pNext(nullptr) {}
    TNode(const T& x) : key(x), pNext(nullptr) {}
};
template <typename T>
class TList {
private:
    TNode<T>* pFirst;
public:
    TList() : pFirst(nullptr){}
    TList(const T& x) : pFirst(x) {};
    ~TList();
    void PushFront(TNode<T>* newNode);
    void PushBack(TNode<T>* newNode);
    void insertAfter(TNode<T>* newNode, int rkey);
    void insertBefore(TNode<T>* newNode, int rkey);
    void remove(T rkey);
    bool IsEmpty() const;
    int Size();
    T reset() const;
};

template <typename T>
TList<T>::~TList() {
    TNode<T>* tmp = pFirst;
    while (tmp != nullptr) {
        TNode<T>* next = tmp->pNext;
        delete tmp;
        tmp = next; 
    }
    pFirst = nullptr;
}

template <typename T>
void TList<T>::PushFront(TNode<T>* newNode) {
    if (newNode == nullptr) {
        throw "nullptr";
    }
    newNode->pNext = pFirst;
    pFirst = newNode;
}
template <typename T>
void TList<T>::PushBack(TNode<T>* newNode) {
    TNode<T>* tmp = pFirst;
    if (pFirst == nullptr) {
        pFirst = newNode;
        return;
    }
    while (tmp->pNext != nullptr) {
        tmp = tmp->pNext;
    }
    tmp->pNext = newNode;

}
template <typename T>
void TList<T>::insertAfter(TNode<T>* newNode, int rkey) {
    TNode<T>* tmp = pFirst;
    while ((tmp != nullptr) && (tmp->key != rkey)) {
        tmp = tmp->pNext;
    }
    if (tmp == nullptr) {
        throw "Error";
    }
    NewNode->pNext = tmp->pNext;
    tmp->pNext = newNode;
}
template <typename T>
void TList<T>::insertBefore(TNode<T>* newNode, int rkey) {
    TNode<T>* prev = nullptr;
    TNode<T>* tmp = pFirst;
    while ((tmp != nullptr) && (tmp->key != rkey)) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == nullptr) {
        throw "error";
    }

    if (prev == nullptr) {
        PushFront(newNode);
        return;
    }

    newNode->pNext = tmp;
    prev->pNext = newNode;
}
template <typename T>
void TList<T>::remove(T rkey) {
    TNode<T>* prev = nullptr;
    TNode<T>* tmp = pFirst;
    while ((tmp != nullptr) && (tmp->key != rkey)) {
        prev = tmp;
        tmp = tmp->pNext;
    }
    if (tmp == nullptr) {
        throw("error");
    }
    if (prev == nullptr) {
        pFirst = pFirst->pNext;
        delete tmp;
        return;
    }
    prev->pNext = tmp->pNext;
    delete tmp;
}
template <typename T>
bool TList<T>::IsEmpty() const {
    return(pFirst == nullptr);
}
template <typename T>
int TList<T>::Size() {
    TNode<T>* tmp = pFirst;
    int c = 0;
    while (tmp != nullptr) {
        tmp = tmp->pNext;
        c++;
    }
    return c;
}
template <typename T>
T TList<T>::reset() const {
    if (pFirst == nullptr) {
        throw "Error";
    }
    return pFirst->key;
}
