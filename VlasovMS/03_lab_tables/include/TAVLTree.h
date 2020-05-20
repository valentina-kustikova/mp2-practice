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
    TAVLTree() = default;
    TAVLTree(const TAVLTree& other);
    TAVLTree(TAVLTree&& other);
    ~TAVLTree() = default;

    using BaseType::find;
    void insert(const TKey& key, TData* data = nullptr);
    void remove(const TKey& key);
    void remove(Iterator& iter);

    using BaseType::root;
    using BaseType::null;
    using BaseType::owns;
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
TAVLTree<TKey, TData>::TAVLTree(const TAVLTree& other)
    : BaseType(other)
{
    // TODO
}

template<typename TKey, typename TData>
TAVLTree<TKey, TData>::TAVLTree(TAVLTree&& other)
{
    root_ = other.root_;
    other.root_ = nullptr;
}

template<typename TKey, typename TData>
void TAVLTree<TKey, TData>::insert(const TKey& key, TData* data)
{
    Node* node = new Node(key, data);
    if (root_ == nullptr)
    {
        root_ = node;
        return;
    }
    Node* temp = root_;
    Node* parent = nullptr;
    while (temp != nullptr)
    {
        parent = temp;
        if (node->key < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    node->parent = parent;
    if (node->key < parent->key)
        parent->left = node;
    else
        parent->right = node;
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