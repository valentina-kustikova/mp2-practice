/*  ----------------- *
 *     DON'T COPY!    *
 *  LIFE-THREATENING! *
 *  ----------------- */

#ifndef _TBINARYTREEITERATOR_H_
#define _TBINARYTREEITERATOR_H_

#include "TBinaryTreeNode.h"

template<typename TKey, typename TData>
struct TPair
{
    TKey key;
    TData* data;
};

template <typename Tree>
class TBinaryTreeIterator
{
    template<typename, typename> friend class TBinaryTree;
    const Tree* owningTree;
    typename Tree::Node* node;
    TBinaryTreeIterator(const Tree* owningTree_, typename Tree::Node* node_);

public:
    TBinaryTreeIterator(const TBinaryTreeIterator<Tree>& other);
    bool operator!=(const TBinaryTreeIterator<Tree>& other) const;
    bool operator==(const TBinaryTreeIterator<Tree>& other) const;
    typename Tree::Pair operator*() const;
    TBinaryTreeIterator<Tree>& toLeft();
    TBinaryTreeIterator<Tree>& toRight();
    TBinaryTreeIterator<Tree>& toParent();    
    TBinaryTreeIterator<Tree> left() const;
    TBinaryTreeIterator<Tree> right() const;
    TBinaryTreeIterator<Tree> parent() const;
    bool hasSameOwner(const TBinaryTreeIterator<Tree>& other) const;
    bool hasOwner() const;
    bool isAccessible() const;
    bool hasLeft() const;
    bool hasRight() const;
    bool hasParent() const;
    bool hasSameParent(const TBinaryTreeIterator& other) const;    
    typename Tree::Key key() const;
    typename Tree::Data*& data();
    typename Tree::Data* data() const;
    TBinaryTreeIterator<Tree>& setKey(const typename Tree::Key& key_);
};

template <typename Tree>
TBinaryTreeIterator<Tree>::TBinaryTreeIterator(const Tree* owningTree_, typename Tree::Node* node_)
    : owningTree(owningTree_), node(node_)
{
}

template <typename Tree>
TBinaryTreeIterator<Tree>::TBinaryTreeIterator(const TBinaryTreeIterator<Tree>& other)
    : owningTree(other.owningTree), node(other.node)
{
}

template <typename Tree>
bool TBinaryTreeIterator<Tree>::operator!=(const TBinaryTreeIterator<Tree>& other) const
{
    return (node != other.node) || (owningTree != other.owningTree);
}

template <typename Tree>
bool TBinaryTreeIterator<Tree>::operator==(const TBinaryTreeIterator<Tree>& other) const
{
    return (node == other.node) && (owningTree == other.owningTree);
}

template <typename Tree>
typename Tree::Pair TBinaryTreeIterator<Tree>::operator*() const
{
    return typename Tree::Pair(node->key, node->data);
}

template <typename Tree>
TBinaryTreeIterator<Tree>& TBinaryTreeIterator<Tree>::toLeft()
{
    if (node != nullptr)
        node = node->left;
    return *this;
}

template <typename Tree>
TBinaryTreeIterator<Tree>& TBinaryTreeIterator<Tree>::toRight()
{
    if (node != nullptr)
        node = node->right;
    return *this;
}

template <typename Tree>
TBinaryTreeIterator<Tree>& TBinaryTreeIterator<Tree>::toParent()
{
    if (node != nullptr)
        node = node->parent;
    return *this;
}

template <typename Tree>
TBinaryTreeIterator<Tree> TBinaryTreeIterator<Tree>::left() const
{
    return TBinaryTreeIterator<Tree>(owningTree, node != nullptr ? node->left : nullptr);
}

template <typename Tree>
TBinaryTreeIterator<Tree> TBinaryTreeIterator<Tree>::right() const
{
    return TBinaryTreeIterator<Tree>(owningTree, node != nullptr ? node->right : nullptr);
}

template <typename Tree>
TBinaryTreeIterator<Tree> TBinaryTreeIterator<Tree>::parent() const
{
    return TBinaryTreeIterator<Tree>(owningTree, node != nullptr ? node->parent : nullptr);
}

template <typename Tree>
bool TBinaryTreeIterator<Tree>::hasSameOwner(const TBinaryTreeIterator<Tree>& other) const
{
    return owningTree == other.owningTree;
}

template <typename Tree>
bool TBinaryTreeIterator<Tree>::hasOwner() const
{
    return owningTree != nullptr;
}

template <typename Tree>
bool TBinaryTreeIterator<Tree>::isAccessible() const
{
    return node != nullptr;
}

template <typename Tree>
bool TBinaryTreeIterator<Tree>::hasLeft() const
{
    return isAccessible() && (node->left != nullptr);
}

template <typename Tree>
bool TBinaryTreeIterator<Tree>::hasRight() const
{
    return isAccessible() && (node->right != nullptr);
}

template <typename Tree>
bool TBinaryTreeIterator<Tree>::hasParent() const
{
    return isAccessible() && (node->parent != nullptr);
}

template <typename Tree>
bool TBinaryTreeIterator<Tree>::hasSameParent(const TBinaryTreeIterator& other) const
{
    return isAccessible() && other.isAccessible() && (node->parent == other.node->parent);
}

template <typename Tree>
typename Tree::Key TBinaryTreeIterator<Tree>::key() const
{
    return node->key;
}

template <typename Tree>
typename Tree::Data*& TBinaryTreeIterator<Tree>::data()
{
    return node->data;
}

template <typename Tree>
typename Tree::Data* TBinaryTreeIterator<Tree>::data() const
{
    return node->data;
}

template <typename Tree>
TBinaryTreeIterator<Tree>& TBinaryTreeIterator<Tree>::setKey(const typename Tree::Key& key_)
{
    if (node == nullptr)
        return *this; // throw ???
    typename Tree::Data* data = node->data;
    const_cast<Tree*>(owningTree)->remove(node->key);  // bedy  s
    const_cast<Tree*>(owningTree)->insert(key_, data); // bashkoi
    // TODO
    return *this;
}

#endif
