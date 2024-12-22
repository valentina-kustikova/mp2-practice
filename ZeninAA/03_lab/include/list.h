#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

template <typename T>
class List
{
private:
    struct Node
    {
        Node* pNext;
        T data;
        Node() :data(0), pNext(nullptr) {}
        Node(const T& x) : data(x), pNext(nullptr) {}
    };
    Node* pFirst;
    int size;
public:
    List() : pFirst(nullptr), size(0) {}
    List(const List<T>& list);
    ~List();
    const List& operator=(const List<T>& list);
    bool operator==(const List<T>& list);
    T operator[](const int idx);
    void PushFront(const T& val);
    void PushBack(const T& val);
    void PopBack();
    void PopFront();
    void Delete();
    bool IsEmpty();
    int GetSize(); 
};


template <typename T>
int List<T>::GetSize() { return size; }
template <typename T>
List<T>::List(const List<T>& list) :size(list.size), pFirst(nullptr)
{
    if (list.pFirst == nullptr) {
        return;
    }
        
    pFirst = new Node{ *list.pFirst };
    Node* pNew = pFirst;
    while (pNew->pNext != nullptr)
    {
        pNew->pNext = new Node{ *pNew->pNext };
        pNew = pNew->pNext;
    }
}
template <typename T>
void List<T>::Delete()
{
    Node* tmp;
    while (pFirst != nullptr)
    {
        tmp = pFirst->pNext;
        delete pFirst;
        pFirst = tmp;
    }
    size = 0;
}
template <typename T>
List<T>::~List()
{
    Delete();
}
template <typename T>
const List<T>& List<T>::operator=(const List<T>& list)
{
    if (this != &list)
    {
        this->Delete(); 
        pFirst = new Node{ *list.pFirst };
        Node* pNew = pFirst;
        while (pNew->pNext != nullptr)
        {
            pNew->pNext = new Node{ *pNew->pNext };
            pNew = pNew->pNext;
        }
        size = list.size;
    }
    return *this;

}
template <typename T>
bool List<T>::operator==(const List<T>& list)
{
    Node* curr1 = pFirst;
    Node* curr2 = list.pFirst;
    if (size != list.size)
    {
        return 0;
    }
    if (curr1 != nullptr && curr2 != nullptr)
    {
        while (curr1 != nullptr && curr2 != nullptr)
        {
            if (curr1->data != curr2->data)
                return 0;
            curr1 = curr1->pNext;
            curr2 = curr2->pNext;
        }
    }
    return 1;

}
template <typename T>
T List<T>::operator[](const int idx)
{
    if (idx >= size) {
        throw std::exception("INDEX ERROR"); 
    }
        
    Node* curr = pFirst;
    for (int i = 0; i < idx; i++)
    {
        curr = curr->pNext;
    }
    return curr->data;
}
template <typename T>
void List<T>::PushBack(const T& val)
{
    Node* node = new Node(val);
    if (pFirst == nullptr)
    {
        pFirst = node;
        size++;
        return;
    }
    Node* curr = pFirst;
    while (curr->pNext != nullptr) {
        curr = curr->pNext;
    }
        
    curr->pNext = node;
    size++;
}

template<typename T>
void List<T>::PushFront(const T& val)
{
    Node* node = new Node(val);
    if (pFirst == nullptr)
    {
        pFirst = node;
        size++;
        return;
    }
    Node* tmp = pFirst;
    pFirst = node;
    pFirst->pNext = tmp;
    size++;
}

template <typename T>
void List<T>::PopBack()
{
    if (IsEmpty()) {
        throw std::exception("ERROR");
    }
        
    Node* curr = pFirst->pNext;
    Node* prevcurr = pFirst;
    if (curr == nullptr)
    {
        delete pFirst;
        pFirst = nullptr;
        size--;
        return;
    }
    while (curr->pNext != nullptr)
    {
        prevcurr = curr;
        curr = curr->pNext;
    }
    delete curr;
    prevcurr->pNext = nullptr;
    size--;
}
template <typename T>
void List<T>::PopFront()
{
    if (IsEmpty()) {
        throw std::exception("ERROR");
    }

    Node* tmp = pFirst->pNext;
    delete pFirst;
    pFirst = tmp;
    size--;
}
template <typename T>
bool List<T>::IsEmpty()
{
    return (size == 0);
}
#endif 