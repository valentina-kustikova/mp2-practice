#ifndef _TAVLTREENODE_H_
#define _TAVLTREENODE_H_

#include "TBinaryTreeNode.h"

using TBalanceFactor = int;

template <typename TKey, typename TData>
class TAVLTreeNode : public TBinaryTreeNode<TKey, TData>
{    
public:
    using BaseType = TBinaryTreeNode<TKey, TData>;
protected:
    template<typename, typename> friend class TAVLTree;
    TBalanceFactor balance_;
public:
    explicit TAVLTreeNode(TKey key_, TData* data_ = nullptr,
        BaseType* parent_ = nullptr, BaseType* left_ = nullptr,
        BaseType* right_ = nullptr);
    TAVLTreeNode(TKey key_, TBalanceFactor balance_, TData* data_ = nullptr,
        BaseType* parent_ = nullptr, BaseType* left_ = nullptr,
        BaseType* right_ = nullptr);
};

template<typename TKey, typename TData>
TAVLTreeNode<TKey, TData>::TAVLTreeNode(TKey key_, TData* data_,
    BaseType* parent_, BaseType* left_, BaseType* right_)
    : TBinaryTreeNode(key_, data_, parent_, left_, right_)
{
}

template<typename TKey, typename TData>
TAVLTreeNode<TKey, TData>::TAVLTreeNode(TKey key_, TBalanceFactor balance,
    TData* data_, BaseType* parent_, BaseType* left_,
    BaseType* right_)
    : TBinaryTreeNode(key_, data_, parent_, left_, right_), balance(balance_)
{
}

#endif