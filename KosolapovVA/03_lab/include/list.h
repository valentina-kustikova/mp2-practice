#ifndef LIST_H
#define LIST_H



template <typename T>
class List
{
private:
    struct TNode
    {
        TNode* pNext;
        T data;
        int key;
    };
    TNode* pFirst;
    size_t sz;
public:
    List();
    List(const List& list);
    ~List();



};
template <typename T>
List<T>::List()
{
    pFirst == nullptr;
    sz = 0;
}
template <typename T>
List<T>::List(const List &list):sz(v.sz), pFirst(nullptr)
{
    if (list.pFirst == nullptr)
        return;
    pFirst = new TNode{ *list.pFirst };
    TNode* pNew = pFirst;
    while (pNew->pNext != nullptr)
    {
        pNew->pNext = new TNode{ *pNew->pNext };
        pNew = pNew->pNext;
    }
}
template <typename T>
List<T>::~List()
{
    TNode* tmp;
    while (pFirst != nullptr)
    {
        tmp = pFirst->pNext;
        delete pFirst;
        pFirst = tmp;
    }
}


#endif // !LIST_H
