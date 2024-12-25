#pragma once
#include <iostream>
using namespace std;

template <typename TKey>
struct TNode
{
    TKey key;
    TNode* pNext;
    TNode()
    {
        key = TKey();
        pNext = nullptr;
    }
    TNode(TKey a)
    {
        key = TKey(a);
        pNext = nullptr;
    }
    const TNode<TKey>& operator = (const TNode<TKey>& node)
    {
        if (this == &node)
        {
            return *this;
        }
        key = node.key;
        pNext = node.pNext;
        return *this;
    }

};

template <typename TKey>
class TList
{
private:
    TNode<TKey>* pFirst;
public:
    TList()
    {
        pFirst = nullptr;
    }
    TList(const TList& list)
    {
        if (list.pFirst == nullptr)
        {
            pFirst = nullptr;
            return;
        }
        pFirst = new TNode<TKey>(list.pFirst->key);
        TNode<TKey>* curr_origin = list.pFirst->pNext;
        TNode<TKey>* curr_copy = pFirst;

        while (curr_origin != nullptr)
        {
            curr_copy->pNext = new TNode<TKey>(curr_origin->key);
            curr_copy = curr_copy->pNext;
            curr_origin = curr_origin->pNext;
        }
    }
    ~TList()
    {
        TNode<TKey>* curr = pFirst;
        while (curr != nullptr)
        {
            TNode<TKey>* tmp = curr->pNext;
            delete curr;
            curr = tmp;
        }
        pFirst = nullptr;
    }

    TNode<TKey>* search(TKey target_key)
    {
        TNode<TKey>* curr = pFirst;
        while (curr != nullptr)
        {
            if (curr->key == target_key)
            {
                return curr;
            }
            curr = curr->pNext;
        }
        return nullptr;
    }
    void push_front(TNode<TKey>* newNode)
    {
        if (pFirst == nullptr)
        {
            pFirst = newNode;
            return;
        }
        newNode->pNext = pFirst;
        pFirst = newNode;
    }
    void push_back(TNode<TKey>* newNode)
    {
        if (newNode == nullptr)
        {
            throw "node is empty!";
        }
        TNode<TKey>* curr = pFirst;
        if (curr == nullptr)
        {
            pFirst = newNode;
            return;
        }
        while (curr->pNext != nullptr)
        {
            curr = curr->pNext;
        }
        curr->pNext = newNode;
    }
    void push_after(TNode<TKey>* newNode, TKey target_key)
    {
        TNode<TKey>* curr = this->search(target_key);
        if (curr == nullptr)
        {
            throw "no key found!";
        }
        newNode->pNext = curr->pNext;
        curr->pNext = newNode;
    }
    void push_before(TNode<TKey>* newNode, TKey target_key)
    {
        TNode<TKey>* curr = pFirst, * prev = nullptr;
        if (curr->key == target_key)
        {
            push_front(newNode);
            return;
        }
        while (curr != nullptr && curr->key != target_key)
        {
            prev = curr;
            curr = curr->pNext;
        }
        if (curr == nullptr && curr->key != target_key)
        {
            throw "no key found!";
        }
        TNode<TKey>* tmp = curr;
        prev->pNext = newNode;
        newNode->pNext = tmp;
    }
    void remove(TKey target_key)
    {
        TNode<TKey>* curr = pFirst, * prev = nullptr;
        if (search(target_key) == nullptr)
        {
            throw "no key found!";
        }
        if (pFirst->key == target_key)
        {
            pFirst = curr->pNext;
            return;
        }
        while (curr != nullptr && curr->key != target_key)
        {
            prev = curr;
            curr = curr->pNext;
        }
        prev->pNext = curr->pNext;

    }
    int size()const
    {
        TNode<TKey>* curr = pFirst;
        int sz = 1;
        while (curr->pNext != nullptr)
        {
            sz++;
            curr = curr->pNext;
        }
        return sz;
    }
    TKey first()const
    {
        if (pFirst == nullptr)
        {
            throw "list is empty";
        }
        return pFirst->key;
    }
    bool empty()const
    {
        return pFirst == nullptr;
    }
    const TList <TKey>& operator = (const TList <TKey>& list)
    {
        if (this == &list)
        {
            return *this;
        }
        if (list.pFirst == nullptr)
        {
            pFirst = nullptr;
            return *this;
        }
        pFirst = new TNode<TKey>(list.pFirst->key);
        TNode<TKey>* curr_origin = list.pFirst->pNext;
        TNode<TKey>* curr_copy = pFirst;

        while (curr_origin != nullptr)
        {
            curr_copy->pNext = new TNode<TKey>(curr_origin->key);
            curr_copy = curr_copy->pNext;
            curr_origin = curr_origin->pNext;
        }
        return *this;
    }
    bool operator == (const TList <TKey>& list)const
    {
        if (list.size() != size())
        {
            return false;
        }
        TNode<TKey>* curr_origin = list.pFirst;
        TNode<TKey>* curr = pFirst;
        if (curr_origin == nullptr && curr == nullptr)
        {
            return true;
        }
        while (curr_origin != nullptr && curr != nullptr)
        {
            if (curr->key != curr_origin->key)
            {
                return false;
            }
            curr = curr->pNext;
            curr_origin = curr_origin->pNext;
        }
        return true;
    }
    bool operator != (const TList <TKey>& list)const
    {
        return !(*this = list);
    }
};