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

    TNode(TKey B)
    {
        key = TKey(B);
        pNext = nullptr;
    }

    const TNode<TKey>& operator= (const TNode<TKey>& node)
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
        TNode<TKey>* current_origin = list.pFirst->pNext;
        TNode<TKey>* current_copy = pFirst;
        while (current_origin != nullptr)
        {
            current_copy->pNext = new TNode<TKey>(current_origin->key);
            current_copy = current_copy->pNext;
            current_origin = current_origin->pNext;
        }
    }

    ~TList()
    {
        TNode<TKey>* current = pFirst; 
        while (current != nullptr) 
        {
            TNode<TKey>* tmp = current->pNext; 
            delete current; 
            current = tmp; 
        }
        pFirst = nullptr;
    }

    TNode<TKey>* search(TKey t_key)
    {
        TNode<TKey>* current = pFirst;
        while (current != nullptr)
        {
            if (current->key == t_key)
            {
                return current;
            }
            current = current->pNext;
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
            throw "EMPTY NODE";
        }
        
        TNode<TKey>* current = pFirst;
        if (current == nullptr)
        {
            pFirst = newNode;
            return;
        }
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = newNode;
    }


    void push_after(TNode<TKey>* newNode, TKey t_key)
    {
        TNode<TKey>* current = this->search(t_key);
        if (current == nullptr)
        {
            throw "KEY NOT FOUND";
        }
        newNode->pNext = current->pNext;
        current->pNext = newNode;
    }

    void push_before(TNode<TKey>* newNode, TKey t_key)
    {
        TNode<TKey>* current = pFirst, * prev = nullptr;
        if (current->key == t_key)
        {
            push_front(newNode);
            return;
        }
        
        while (current != nullptr && current->key != t_key)
        {
            prev = current;
            current = current->pNext;
        }

        if (current == nullptr && current->key != t_key)
        {
            throw "KEY NOT FOUND";
        }

        TNode<TKey>* tmp = current;
        prev->pNext = newNode;
        newNode->pNext = tmp;
    }

    void remove(TKey t_key)
    {
        TNode<TKey>* current = pFirst, * prev = nullptr;
        if (search(t_key) == nullptr)
        {
            throw "KEY NOT FOUND";
        }
        if (pFirst->key == t_key)
        {
            pFirst = current->pNext;
            return;
        }
        while (current != nullptr && current->key != t_key)
        {
            prev = current;
            current = current->pNext;
        }
        prev->pNext = current->pNext; 
    }

    int size()const
    {
        TNode<TKey>* current = pFirst;
        int sz = 1;
        while (current->pNext != nullptr)
        {
            sz++;
            current = current->pNext;
        }
        return sz;
    }

    TKey first()const
    {
        if (pFirst == nullptr)
        {
            throw "EMPTY LIST";
        }
        return pFirst->key;
    }

    bool empty()const
    {
        return pFirst == nullptr;
    }

    const TList <TKey>& operator= (const TList <TKey>& list)
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
        TNode<TKey>* current_origin = list.pFirst->pNext;
        TNode<TKey>* current_copy = pFirst;
        
        while (current_origin != nullptr)
        {
            current_copy->pNext = new TNode<TKey>(current_origin->key);
            current_copy = current_copy->pNext;
            current_origin = current_origin->pNext;
        }
        return *this;
    }

    bool operator== (const TList <TKey>& list)const
    {
        if (list.size() != size())
        {
            return false;
        }
        TNode<TKey>* current_origin = list.pFirst;
        TNode<TKey>* current = pFirst;
        if (current == nullptr && current_origin == nullptr)
        {
            return true;
        }
        while (current_origin != nullptr && current != nullptr)
        {
            if (current->key != current_origin->key)
            {
                return false;
            }
            current = current->pNext;
            current_origin = current_origin->pNext;
        }
        return true;
    }


    bool operator != (const TList <TKey>& list)const
    {
        return !(*this = list);
    }
};