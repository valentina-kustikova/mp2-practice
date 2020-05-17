#ifndef _BALANCETREETABLE_H_
#define _BALANCETREETABLE_H_

#include "binarytreetable.h"
#include "tbalancenode.h"

#include <queue>

template<typename TKey, class TData>
class TBalanceTreeTable : public TBinaryTreeTable<TKey, TData>
{
public:
    void InsertRecord(const TKey _key, TData* _data = nullptr) override;
    void RemoveRecord(const TKey _key) override;

private:
    int InsBalanceTree(TBalanceNode<TKey, TData>** _node, const TKey _key, TData* _data = nullptr);
    int LeftTreeBalancing(TBalanceNode<TKey, TData>** _node);
    int RightTreeBalancing(TBalanceNode<TKey, TData>** _node);
};
//-----------------------------------------------

template<typename TKey, class TData>
void TBalanceTreeTable<TKey, TData>::InsertRecord(const TKey _key, TData* _data)
{
    if (this->IsFull())
        throw Exception("Balance Binary Tree Table is full!");
    
    InsBalanceTree((TBalanceNode<TKey, TData>**)(&(this->root)), _key, _data);
};

template<typename TKey, class TData>
void TBalanceTreeTable<TKey, TData>::RemoveRecord(const TKey _key)
{
    if (this->IsEmpty())
        throw Exception("Balance Binary Tree Table is empty!");

    struct Balance
    {
        TBalanceNode<TKey, TData>** node;
        bool branch; // 0 - left, 1 - right
    };

    bool flag = true;
    stack<Balance> s;
    TBalanceNode<TKey, TData>** node = (TBalanceNode<TKey, TData>**)&(this->root);
    
    while ((*node))
    {
        if ((*node)->GetKey() > _key)
        {
            s.push({ node, 0 });
            node = (TBalanceNode<TKey, TData>**)&((*node)->pLeft);
        }
        else if ((*node)->GetKey() < _key)
        {
            s.push({ node, 1 });
            node = (TBalanceNode<TKey, TData>**)&((*node)->pRight);
        }
        else
        {
            (this->dataCount)--;
            
            flag = false;
            TBalanceNode<TKey, TData>* left = (TBalanceNode<TKey, TData>*)(*node)->pLeft;
            TBalanceNode<TKey, TData>* right = (TBalanceNode<TKey, TData>*)(*node)->pRight;
            int bal = (*node)->GetBalance();
            

            if (!left)
            {
                if(right)
                    right->pParent = (*node)->pParent;
                
                if ((*node)->pParent)
                    if ((*node) == (*node)->pParent->pLeft)
                        (*node)->pParent->pLeft = right;
                    else (*node)->pParent->pRight = right;
                
                delete (*node);
                *node = right;
            }
            else if (!right)
            {
                left->pParent = (*node)->pParent;

                if ((*node)->pParent)
                    if ((*node) == (*node)->pParent->pLeft)
                        (*node)->pParent->pLeft = left;
                    else (*node)->pParent->pRight = left;

                delete (*node);
                *node = left;
            }
            else if (!(right->pLeft))
            {
                right->pLeft = left;
                left->pParent = right;

                if ((*node) == (*node)->pParent->pLeft)
                    (*node)->pParent->pLeft = right;
                else (*node)->pParent->pRight = right;

                *node = right;
                right->SetBalance(bal);
                s.push({ node, 1 });
            }
            else
            {
                TBalanceNode<TKey, TData>** q = (TBalanceNode<TKey, TData>**)&(right->pLeft);
                queue<TBalanceNode<TKey, TData>**> qu;
                
                while (((*q)->pLeft))
                {
                    qu.push(q);
                    q = (TBalanceNode<TKey, TData>**)&((*q)->pLeft);
                }
                
                (*node)->SetKey((*q)->GetKey());
                (*node)->SetData((*q)->GetData());

                if ((*q)->pRight)
                    (*q)->pRight->pParent = right;
                right->pLeft = (*q)->pRight;
                
                delete(*q);

                (*node)->SetBalance(bal);
                s.push({ node, 1 });
                s.push({ (TBalanceNode<TKey, TData>**)&((*node)->pRight), 0 });
                
                while (qu.size())
                {
                    s.push({ qu.front(), 0 });
                    qu.pop();
                }
            }
            break;
        }
    }

    while (s.size() && (!flag))
    {
        Balance b = s.top();
        s.pop();
        if (b.branch)
            flag = LeftTreeBalancing(b.node);
        else
            flag = RightTreeBalancing(b.node);
    }
};

template<typename TKey, class TData>
int TBalanceTreeTable<TKey, TData>::InsBalanceTree(TBalanceNode<TKey, TData>** _node, const TKey _key, TData* _data)
{
    int height = 0;

    if (!(*_node))
    {
        *_node = new TBalanceNode<TKey, TData>(_key, _data);
        height = 1;
        this->dataCount++;
    }
    else if (_key < (*_node)->GetKey())
    {
        if (InsBalanceTree((TBalanceNode<TKey, TData>**)(&((*_node)->pLeft)), _key, _data) == 1)
        {
            (*_node)->pLeft->pParent = (*_node);
            height = LeftTreeBalancing(_node);
        }
        else (*_node)->pLeft->pParent = (*_node);
    }
    else
    {
        if (InsBalanceTree((TBalanceNode<TKey, TData>**)(&((*_node)->pRight)), _key, _data) == 1)
        {
            (*_node)->pRight->pParent = (*_node);
            height = RightTreeBalancing(_node);
        }
        else (*_node)->pRight->pParent = (*_node);
    }

    return height;
};

template<typename TKey, class TData>
int TBalanceTreeTable<TKey, TData>::LeftTreeBalancing(TBalanceNode<TKey, TData>** _node)
{
    int height = 0;

    switch ((*_node)->GetBalance())
    {
    case 0:
        (*_node)->SetBalance(-1);
        height = 1;
        break;
    case 1:
        (*_node)->SetBalance(0);
        height = 0;
        break;
    case -1:
        TBalanceNode<TKey, TData>* left = (TBalanceNode<TKey, TData>*)((*_node)->pLeft);

        if (left->GetBalance() == -1)
        {
            (*_node)->pLeft = left->pRight;
            if(left->pRight)
                left->pRight->pParent = (*_node);
            left->pRight = (*_node);
            left->pParent = (*_node)->pParent;
            (*_node)->pParent = left;
            (*_node)->SetBalance(0);
            (*_node) = left;
        }
        else
        {
            TBalanceNode<TKey, TData>* right = (TBalanceNode<TKey, TData>*)(left->pRight);
            left->pRight = right->pLeft;
            if(right->pLeft)
                right->pLeft->pParent = left;
            right->pLeft = left;
            left->pParent = right;
            (*_node)->pLeft = right->pRight;
            if(right->pRight)
                right->pRight->pParent = (*_node);
            right->pRight = (*_node);
            right->pParent = (*_node)->pParent;
            (*_node)->pParent = right;
            if (right->GetBalance() == -1)
                (*_node)->SetBalance(1);
            else
                (*_node)->SetBalance(0);
            if (right->GetBalance() == 1)
                (*_node)->SetBalance(-1);
            else
                (*_node)->SetBalance(0);
            (*_node) = right;
        }

        (*_node)->SetBalance(0);
        height = 0;
        break;
    }

    return height;
};

template<typename TKey, class TData>
int TBalanceTreeTable<TKey, TData>::RightTreeBalancing(TBalanceNode<TKey, TData>** _node)
{
    int height = 0;

    switch ((*_node)->GetBalance())
    {
    case -1:
        (*_node)->SetBalance(0);
        height = 0;
        break;
    case 0:
        (*_node)->SetBalance(1);
        height = 1;
        break;
    case 1:
        TBalanceNode<TKey, TData> * right = (TBalanceNode<TKey, TData>*)((*_node)->pRight);

        if (right->GetBalance() == -1)
        {
            TBalanceNode<TKey, TData>* left = (TBalanceNode<TKey, TData>*)(right->pLeft);
            right->pLeft = left->pRight;
            if(left->pRight)
                left->pRight->pParent = right;
            left->pRight = right;
            right->pParent = left;
            (*_node)->pRight = left->pLeft;
            if(left->pLeft)
                left->pLeft->pParent = (*_node);
            left->pLeft = (*_node);
            left->pParent = (*_node);
            (*_node)->pParent = left;
            if (left->GetBalance() == -1)
                (*_node)->SetBalance(1);
            else
                (*_node)->SetBalance(0);
            if (right->GetBalance() == 1)
                (*_node)->SetBalance(-1);
            else
                (*_node)->SetBalance(0);
            (*_node) = left;
        }
        else
        {
            (*_node)->pRight = right->pLeft;
            if (right->pLeft)
                right->pLeft->pParent = (*_node);
            right->pLeft = (*_node);
            right->pParent = (*_node)->pParent;
            (*_node)->pParent = right;
            (*_node)->SetBalance(0);
            (*_node) = right;
        }

        (*_node)->SetBalance(0);
        height = 0;
        break;
    }

    return height;
};

#endif