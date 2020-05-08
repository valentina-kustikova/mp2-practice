#ifndef _BINARYTREETABLE_H_
#define _BINARYTREETABLE_H_

#include <stack>

#include "tnode.h"
#include "table.h"

template<typename TKey, class TData>
class TBinaryTreeTable: public TTable<TKey, TData>
{
protected:
    TNode<TKey, TData>* root;
    TNode<TKey, TData>* pCurrent;
    stack<TNode<TKey, TData>* > iterator;

public:
    TBinaryTreeTable() : TTable<TKey, TData>(), root(nullptr), pCurrent(nullptr) {};
    ~TBinaryTreeTable();

    virtual bool IsFull() const override;

    TNode<TKey, TData>* SearchKey(const TKey _key) const;
    TNode<TKey, TData>* SearchMaxKey(TNode<TKey, TData>* _root) const;
    TNode<TKey, TData>* SearchMinKey(TNode<TKey, TData>* _root) const;
    TNode<TKey, TData>* SearchNext(TNode<TKey, TData>* _tnode) const;
    TNode<TKey, TData>* SearchNext(const TKey _key) const;
    TNode<TKey, TData>* SearchPrev(TNode<TKey, TData>* _tnode) const;
    TNode<TKey, TData>* SearchPrev(const TKey _key) const;
    
    virtual bool Reset() override;
    virtual bool GetNext() override;
    virtual bool IsTabEnded() const override{ return this->currPos >= this->dataCount; }

    TTabRecord<TKey, TData>* FindRecord(const TKey _key) override;
    void InsertRecord(TNode<TKey, TData>* _tnode);
    virtual void InsertRecord(const TKey _key, TData* _pData = nullptr) override;
    void RemoveRecord(TNode<TKey, TData>* _tnode);
    virtual void RemoveRecord(const TKey _key) override;

    TNode<TKey, TData>* GetRoot() const { return root; }
    virtual TTabRecord<TKey, TData>* GetRecord() const override;
    virtual TKey GetKey() const override;
    virtual TData* GetData() const override;
};
//---------------------------------------------------------

template<typename TKey, class TData>
TBinaryTreeTable<TKey, TData>::~TBinaryTreeTable()
{
    if (root)
    {
        stack<TNode<TKey, TData>* > mainStack, helpStack;
        helpStack.push(root);

        while (!helpStack.empty())
        {
            TNode<TKey, TData>* node = helpStack.top();
            helpStack.pop();

            if (!node->pLeft)
                helpStack.push(node->pLeft);
            if (!node->pRight)
                helpStack.push(node->pRight);

            mainStack.push(node);
        }

        while (!mainStack.empty())
        {
            TNode<TKey, TData>* node = mainStack.top();
            mainStack.pop();
            delete node;
        }

        pCurrent = nullptr;
    }
};
//---------------------------------------------------------

template<typename TKey, class TData>
bool TBinaryTreeTable<TKey, TData>::IsFull() const
{
    TNode<TKey, TData>* tmp = new TNode<TKey, TData>;
    
    if (tmp)
    {
        delete tmp;
        return false;
    }
    else return true;
};

template<typename TKey, class TData>
TNode<TKey, TData>* TBinaryTreeTable<TKey, TData>::SearchKey(const TKey _key) const
{
    TNode<TKey, TData>* current = root;
    
    while ((current != nullptr) && (current->GetKey() != _key))
    {
        if (_key < current->GetKey())
            current = current->GetLeft();
        else current = current->GetRight();
    }

    return current;
};

template<typename TKey, class TData>
TNode<TKey, TData>* TBinaryTreeTable<TKey, TData>::SearchMaxKey(TNode<TKey, TData>* _root) const
{
    TNode<TKey, TData>* current = _root;

    while (current->pRight != nullptr)
        current = current->pRight;

    return current;
};

template<typename TKey, class TData>
TNode<TKey, TData>* TBinaryTreeTable<TKey, TData>::SearchMinKey(TNode<TKey, TData>* _root) const
{
    TNode<TKey, TData>* current = _root;

    while (current->pLeft != nullptr)
        current = current->pLeft;

    return current;
};

template<typename TKey, class TData>
TNode<TKey, TData>* TBinaryTreeTable<TKey, TData>::SearchNext(TNode<TKey, TData>* _tnode) const
{
    TNode<TKey, TData>* next = nullptr;

    if (_tnode->pRight != nullptr)
    {
        next = SearchMinKey(_tnode->pRight);
        return next;
    }

    next = _tnode->pParent;
    TNode<TKey, TData>* tmp = _tnode;

    while ((next != nullptr) && (tmp == next->pRight))
    {
        tmp = next;
        next = next->pParent;
    }

    return next;
};

template<typename TKey, class TData>
TNode<TKey, TData>* TBinaryTreeTable<TKey, TData>::SearchNext(const TKey _key) const
{
    TNode<TKey, TData>* current = SearchKey(_key);
    return SearchNext(current);
};

template<typename TKey, class TData>
TNode<TKey, TData>* TBinaryTreeTable<TKey, TData>::SearchPrev(TNode<TKey, TData>* _tnode) const
{
    TNode<TKey, TData>* prev = nullptr;

    if (_tnode->pLeft != nullptr)
    {
        prev = SearchMaxKey(_tnode->pLeft);
        return prev;
    }

    prev = _tnode->pParent;
    TNode<TKey, TData>* tmp = _tnode;

    while ((prev != nullptr) && (tmp == prev->pLeft))
    {
        tmp = prev;
        prev = prev->pParent;
    }

    return prev;
};

template<typename TKey, class TData>
TNode<TKey, TData>* TBinaryTreeTable<TKey, TData>::SearchPrev(const TKey _key) const
{
    TNode<TKey, TData>* current = SearchKey(_key);
    return SearchPrev(current);
};

template<typename TKey, class TData>
bool TBinaryTreeTable<TKey, TData>::Reset()
{
    TNode<TKey, TData>* node = root;
    pCurrent = root;
    this->currPos = 0;

    while (node)
    {
        iterator.push(node);
        pCurrent = node;
        node = node->GetLeft();
    }

    return this->IsTabEnded();
};

template<typename TKey, class TData>
bool TBinaryTreeTable<TKey, TData>::GetNext()
{
    if ((!this->IsTabEnded()) && (pCurrent))
    {
        pCurrent = pCurrent->GetRight();
        TNode<TKey, TData>* node = pCurrent;
        iterator.pop();

        while (node)
        {
            iterator.push(node);
            pCurrent = node;
            node = node->GetLeft();
        }

        if ((!pCurrent) && (!iterator.empty()))
            pCurrent = iterator.top();
    }

    this->currPos++;

    return this->IsTabEnded();
};

template<typename TKey, class TData>
TTabRecord<TKey, TData>* TBinaryTreeTable<TKey, TData>::FindRecord(const TKey _key)
{
    TNode<TKey, TData>* node = SearchKey(_key);
    return node;
};

template<typename TKey, class TData>
void TBinaryTreeTable<TKey, TData>::InsertRecord(TNode<TKey, TData>* _tnode)
{
    if (this->IsFull())
        throw Exception("Binary Tree Table is full!");

    if (root == nullptr)
    {
        root = _tnode;
        this->dataCount++;
        return;
    }

    TNode<TKey, TData>* x = root;
    TNode<TKey, TData>* y = nullptr;

    while (x != nullptr)
    {
        y = x;
        if (_tnode->GetKey() < x->GetKey())
            x = x->GetLeft();
        else x = x->GetRight();
    }
    
    _tnode->pParent = y;
    
    if (_tnode->GetKey() < y->GetKey())
        y->pLeft = _tnode;
    else y->pRight = _tnode;

    this->dataCount++;
};

template<typename TKey, class TData>
void TBinaryTreeTable<TKey, TData>::InsertRecord(const TKey _key, TData* _pData)
{
    TNode<TKey, TData>* newTNode = new TNode<TKey, TData>(_key, _pData);
    InsertRecord(newTNode);
};

template<typename TKey, class TData>
void TBinaryTreeTable<TKey, TData>::RemoveRecord(TNode<TKey, TData>* _tnode)
{
    if (this->IsEmpty())
        throw Exception("Binary Tree Table is empty!");

    if ((_tnode == root) && (!root->GetLeft()) && (!root->GetRight()))
    {
        delete root;
        root = nullptr;
        this->dataCount--;

        return;
    }

    TNode<TKey, TData>* y = nullptr;
    TNode<TKey, TData>* x = nullptr;

    if ((_tnode->pLeft != nullptr) && (_tnode->pRight != nullptr))
        y = SearchNext(_tnode);
    else
        y = _tnode;
    
    if (y->pLeft != nullptr)
        x = y->pLeft;
    else
        x = y->pRight;

    if (x != nullptr) 
        x->pParent = y->pParent;
    
    if (y->pParent != nullptr)
    {
        if (y == y->pParent->pLeft) 
            y->pParent->pLeft = x;
        else 
            y->pParent->pRight = x;
    }

    if (y != _tnode)
    {
        _tnode->key = y->key;
        delete _tnode->data;
        _tnode->data = y->data;
    }

    this->dataCount--;
};

template<typename TKey, class TData>
void TBinaryTreeTable<TKey, TData>::RemoveRecord(const TKey _key)
{
    TNode<TKey, TData>* newTNode = SearchKey(_key);
    RemoveRecord(newTNode);
};

template<typename TKey, class TData>
TTabRecord<TKey, TData>* TBinaryTreeTable<TKey, TData>::GetRecord() const
{
    return pCurrent;
};

template<typename TKey, class TData>
TKey TBinaryTreeTable<TKey, TData>::GetKey() const
{
    return pCurrent->GetKey();
};

template<typename TKey, class TData>
TData* TBinaryTreeTable<TKey, TData>::GetData() const
{
    return pCurrent->GetData();
};

#endif