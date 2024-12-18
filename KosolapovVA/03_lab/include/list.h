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
        TNode() : val(0), next(nullptr) {}
        TNode(const T& x) : val(x), next(nullptr) {}
    };
    TNode* pFirst;
    size_t sz;
public:
    List() : pFirst(nullptr), sz(0){}
    List(const List<T>& list);
    //List(List&& list) noexcept;
    ~List();
    const List& operator=(const List<T>& list);
    bool operator==(const List<T>& list);
    //List& operator=(List&& list) noexcept;





};

template <typename T>
List<T>::List(const List<T> &list):sz(v.sz),pFirst(nullptr)
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
template <typename T>
const List<T>& List<T>::operator=(const List<T>& list)
{
    //
}
template <typename T>
bool List<T>::operator==(const List<T>& list)
{
    TNode* curr = pFirst;
    while (curr != nullptr)
    {
        if()
    }
}
#endif // !LIST_H
