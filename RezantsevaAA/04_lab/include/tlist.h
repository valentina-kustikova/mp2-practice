
#ifndef __TLIST_H__
#define __TLIST_H__

//шаблон "структуры" звена
template <class T>
class TNode
{
public:
    T key;
    TNode<T>* pNext;
public:
    TNode(T k = 0, TNode<T>* n = 0) //конструктор
    {
        key = k;
        pNext = n;
    }
    TNode(const TNode<T>& pNode) // 
    {
        key = pNode->key;
        pNext = 0;
    }
    T GetData()
    {
        return key;
    }
    TNode<T>* GetNext()
    {
        return  pNext;
    }
    void SetData(T d)
    {
        key = d;
    }
    void SetNext(TNode<T>* next)
    {
        pNext = next;
    }
};

#endif