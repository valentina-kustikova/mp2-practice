#ifndef _TNODE_H_
#define _TNODE_H_

template <class TKey, class TData>
class TNode
{
public:
    TKey key;
    TData pData;
    TNode<TKey, TData>* pNext;
    TNode(); 
    TNode(const TNode&); //конструктор копирования
    TNode(TKey, TData, TNode* next = NULL); //к-р с пар-ом, прин указ на звено 
    ~TNode();
};

template <class TKey, class TData>
TNode<TKey, TData>::TNode()
{
    key = 0;
    pData = 0;
    pNext = 0;
}
template <class TKey, class TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& tmp)
{
    key = tmp.key;
    pData = tmp.pData;
    pNext = tmp.pNext;
}
template <class TKey, class TData>
TNode<TKey, TData>::TNode(TKey k, TData d, TNode* next)
{
    key = k;
    pData = d;
    pNext = next;
}
template <class TKey, class TData>
TNode<TKey, TData>::~TNode()
{}

#endif 

