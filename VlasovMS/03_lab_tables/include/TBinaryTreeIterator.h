/*  ----------------- *
 *     DON'T COPY!    *
 *  LIFE-THREATENING! *
 *  ----------------- */

#ifndef _TBINARYTREEITERATOR_H_
#define _TBINARYTREEITERATOR_H_

#include "TBinaryTreeNode.h"

template <typename Tree>
class TBinaryTreeIterator
{
    template<typename, typename> friend class TBinaryTree;
    const Tree* owningTree;
    typename Tree::Node* node;
    
    TBinaryTreeIterator(const Tree* owningTree_, typename Tree::Node* node_)
    {
        owningTree = owningTree_;
        node = node_;
    }
public:
    
    TBinaryTreeIterator(const TBinaryTreeIterator<Tree>& other)
    {
        owningTree = other.owningTree;
        node = other.node;
    }
    
    bool operator!=(const TBinaryTreeIterator<Tree>& other) const
    {
        return (node != other.node) || (owningTree != other.owningTree);
    }
     
    bool operator==(const TBinaryTreeIterator<Tree>& other) const
    {
        return (node == other.node) && (owningTree == other.owningTree);
    }

    
    TBinaryTreeIterator<Tree>& toLeft()
    {
        if (node != nullptr)
            node = node->left;
        return *this;
    }
    
    TBinaryTreeIterator<Tree>& toRight()
    {
        if (node != nullptr)
            node = node->right;
        return *this;
    }
    
    TBinaryTreeIterator<Tree>& toParent()
    {
        if (node != nullptr)
            node = node->parent;
        return *this;
    }

    
    TBinaryTreeIterator<Tree> left() const
    {
        return TBinaryTreeIterator<Tree>(owningTree, node != nullptr ? node->left : nullptr);
    }
    
    TBinaryTreeIterator<Tree> right() const
    {
        return TBinaryTreeIterator<Tree>(owningTree, node != nullptr ? node->right : nullptr);
    }
    
    TBinaryTreeIterator<Tree> parent() const
    {
        return TBinaryTreeIterator<Tree>(owningTree, node != nullptr ? node->parent : nullptr);
    }

    
    bool hasSameOwner(const TBinaryTreeIterator<Tree>& other) const
    {
        return owningTree == other.owningTree;
    }
    
    bool hasOwner() const
    {
        return owningTree != nullptr;
    }
    
    bool isAccessible() const
    {
        return node != nullptr;
    }

    bool hasLeft() const
    {
        return isAccessible() && (node->left != nullptr);
    }

    bool hasRight() const
    {
        return isAccessible() && (node->right != nullptr);
    }

    bool hasParent() const
    {
        return isAccessible() && (node->parent != nullptr);
    }

    bool hasSameParent(const TBinaryTreeIterator& other) const
    {
        return isAccessible() && other.isAccessible() && (node->parent == other.node->parent);
    }

    
    typename Tree::Key key() const
    {
        return node->key;
    }
    
    typename Tree::Data*& data()
    {
        return node->data;
    }
    
    typename Tree::Data* data() const
    {
        return node->data;
    }

    TBinaryTreeIterator<Tree>& setKey(const typename Tree::Key& key_)
    {
        if (node == nullptr)
            return *this; // throw ???
        typename Tree::Data* data = node->data;
        const_cast<Tree*>(owningTree)->remove(node->key);  // bedy  s
        const_cast<Tree*>(owningTree)->insert(key_, data); // bashkoi
        // TODO
        return *this;
    }
};

#endif
