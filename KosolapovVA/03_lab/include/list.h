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
    List() : pFirst(nullptr), sz(0){}
    List(const List<T>& list);
    ~List();
    const List& operator=(const List<T>& list);
    bool operator==(const List<T>& list);
    T operator[](const int idx);
    void PushFront(const T& val);
    void PushBack(const T& val);
    void PopBack();
    void PopFront();
    bool IsEmpty();
    int GetSZ();
};


template <typename T>
int List<T>::GetSZ() { return sz;}
template <typename T>
List<T>::List(const List<T> &list):sz(v.sz),pFirst(nullptr)
{
    if (list.pFirst == nullptr)
        return;
    pFirst = new TNode{ *list.pFirst };
    TNode* pNew = pFirst;
    while (pNew->pNext != nullptr)
    {
        pNew->pNext = new TNode{ *pNew->pNext };
        pNew = pNew->pNext;
    }
}
template <typename T>
List<T>::~List()
{
    TNode* tmp;
    while (pFirst != nullptr)
    {
        tmp = pFirst->pNext;
        delete pFirst;
        pFirst = tmp;
    }
}
template <typename T>
const List<T>& List<T>::operator=(const List<T>& list)
{
    if (this != &list)
    {
        List tmp(list);
        swap(*this, tmp);
    }
    return *this;

}
template <typename T>
bool List<T>::operator==(const List<T>& list)
{
    TNode* curr1 = pFirst;
    TNode* curr2 = list.pFirst;
    if (sz != list.sz)
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
    if (idx >= sz)
        throw std::exception("Invalid list index");
    TNode* curr = pFirst;
    for (int i = 0; i < idx; i++)
    {
        curr = curr->pNext;
    }
    return curr->data;
}
template <typename T>
void List<T>::PushBack(const T& val)
{
    TNode* node = new TNode(val);
    if (pFirst == nullptr)
    {
        pFirst = node;
        sz++;
        return;
    }
    TNode* curr = pFirst;
    while (curr->pNext != nullptr)
        curr = curr->pNext;
    curr->pNext = node;
    sz++;
}

template<typename T>
void List<T>::PushFront(const T& val)
{
    TNode* node = new TNode(val);
    if (pFirst == nullptr)
    {
        pFirst = node;
        sz++;
        return;
    }
    TNode* tmp = pFirst;
    pFirst = node;
    pFirst->pNext = tmp;    
    sz++;
}

template <typename T>
void List<T>::PopBack()
{
    if (IsEmpty())
        throw std::exception("Error");
    TNode* curr = pFirst->pNext;
    TNode* prevcurr = pFirst;
    if (curr == nullptr)
    {
        delete pFirst;
        pFirst = nullptr;
        sz--;
        return;
    }
    while (curr->pNext != nullptr)
    {
        prevcurr = curr;
        curr = curr->pNext;
    }
    delete curr;
    prevcurr->pNext = nullptr;
    sz--;
}
template <typename T>
void List<T>::PopFront()
{
    if (IsEmpty())
        throw std::exception("Error");
    TNode* tmp = pFirst->pNext;
    delete pFirst;
    pFirst = tmp;
    sz--;
}
template <typename T>
bool List<T>::IsEmpty()
{
    return (sz == 0);
}
#endif // !LIST_H
