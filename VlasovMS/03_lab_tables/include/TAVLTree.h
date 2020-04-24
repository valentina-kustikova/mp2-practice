#ifndef _TAVLTREE_H_
#define _TAVLTREE_H_

#include "TBinaryTree.h"
#include "TAVLTreeNode.h"

template <typename TKey, typename TData>
class TAVLTree : public TBinaryTree<TKey, TData>
{
public:
    using BaseType = TBinaryTree<TKey, TData>;
    using Node = TAVLTreeNode<TKey, TData>;
    using Iterator = TBinaryTreeIterator<TAVLTree<TKey, TData>>;
    using Key = TKey;
    using Data = TData;
    using Pair = TPair<TKey, TData>;
protected:
    using BaseType::root_;
    TBalanceFactor leftBalancing(Node* node);
    TBalanceFactor rightBalancing(Node* node);
public:
    TAVLTree();
    TAVLTree(const TAVLTree& other);
    TAVLTree(TAVLTree&& other);
    ~TAVLTree();

    void insert(const TKey& key, TData* data = nullptr);
    void remove(const TKey& key);
    void remove(Iterator& iter);
};

template<typename TKey, typename TData>
TBalanceFactor TAVLTree<TKey, TData>::leftBalancing(Node* node)
{
    // TODO
    return TBalanceFactor();
}

template<typename TKey, typename TData>
TBalanceFactor TAVLTree<TKey, TData>::rightBalancing(Node* node)
{
    // TODO
    return TBalanceFactor();
}

template<typename TKey, typename TData>
TAVLTree<TKey, TData>::TAVLTree()
    : BaseType()
{
}

template<typename TKey, typename TData>
TAVLTree<TKey, TData>::TAVLTree(const TAVLTree& other)
    : BaseType()
{
    // TODO
}

template<typename TKey, typename TData>
TAVLTree<TKey, TData>::TAVLTree(TAVLTree&& other)
    : BaseType(other)
{
}

template<typename TKey, typename TData>
TAVLTree<TKey, TData>::~TAVLTree()
{
    // TODO
}

template<typename TKey, typename TData>
void TAVLTree<TKey, TData>::insert(const TKey& key, TData* data)
{
    // TODO
}

template<typename TKey, typename TData>
void TAVLTree<TKey, TData>::remove(const TKey& key)
{
    // TODO
}

template<typename TKey, typename TData>
void TAVLTree<TKey, TData>::remove(Iterator& iter)
{
    // TODO
}

#endif