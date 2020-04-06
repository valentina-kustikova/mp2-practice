#ifndef TNODE_H
#define TNODE_H

#include <iostream>

using namespace std;

template<typename TData, typename TKey>
class TNode
{
public:
    TData* pData;
    TKey key;
    TNode* pNext;

    TNode();
    TNode(TKey, TData*, TNode* _pNext = nullptr);
    TNode(const TNode&);
    friend std::ostream& operator << (std::ostream& out, TNode<TData, TKey>& node)
    {
        out << node.key << " - " << node.pData;
        return out;
    }
};

#endif