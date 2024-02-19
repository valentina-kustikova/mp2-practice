#ifndef __TLIST_H__
#define __TLIST_H__
#include <iostream>
using namespace std;
//шаблон "структуры" звена
template <class T> class TNode {
public:
    T key;
    TNode<T>* pNext;

    TNode(const T& key_ = 0, const TNode<T>* pNext_  = nullptr) //конструктор по умолчанию
    {
        key = key_;
        pNext = (TNode<T>*)pNext_; //const * -> *
    }

    TNode(const TNode<T>& pNode) // конструткор копирования
    {
        key = pNode.key;
        pNext = pNode.pNext;
    }
    /*
    T GetData() //получить ключ 
    {
        return key;
    }

    TNode<T>* GetNext() //получить указатель на след звено
    {
        return  pNext;
    }

    void SetData(T d) //установить ключ (данные)
    {
        key = d;
    }

    void SetNext(TNode<T>* next) //установить ссылку на следующий
    {
        pNext = next;
    }
    */
};

template <class T> class TList {
protected:
    TNode<T>* pFirst = nullptr;
    TNode<T>* pLast = nullptr;
    TNode<T>* pCur = nullptr;   //pCurrent текущий
    TNode<T>* pStop = nullptr;  //значение указателя конца списка =null
   int ListLen = 0;   //длина списка (кол-во звеньев)
public:
    TList();
    TList(const TNode<T>* pFirst_); //конструктор  с параметром
    TList(const TList& pNode);      //конструктор копирования
   
    void Clear();
    ~TList();

    bool is_Full() const;
    bool is_Empty() const;

    TNode<T>* Search(const T& key); //поиск по ключу (данным)
    //INSERT
    void InsertFirst(const T& key_);
    void InsertLast(const T& key_);
    void InsertBefore(const T& key_, const T& NextKey);
    void InsertAfter(const T& key_, const T& PrevKey);
  
    
    template <class T> friend std::ostream& operator<<(std::ostream& out, const TList<T>& list);
    //insert(2)
    // void InsertBefore(const T& key_);
    //void InsertAfter(const T& key_);
  
    //functions
   // void Remove(const T& key_); //
    void Reset(); //установить на начало списка
    void Next(); //сдвиг вправо текущего звена 

    TNode<T>* GetCurrent( ) const; //возвращает текущее звено
    const int GetSize() const; //
   // bool is_End() const; //список завершен?

};


template <class T> std::ostream& operator<<(std::ostream& out, const TList<T>& list) {
    TNode<T>* tmp = list.pFirst;
    while (tmp != list.pStop)
    {
        out << tmp->key << " ";
        tmp = tmp->pNext;
    }
    return out;
}
//REALISATION

template <class T> TList<T>::TList() {
    pFirst = pLast = pCur = pStop = nullptr;
    ListLen = 0;
};

template <class T> TList<T>::TList(const TNode<T>* pFirst_) {
    pFirst = (TNode<T>*)pFirst_;
    pCur = pFirst;
    while (pCur->pNext != nullptr)
    {
        Next();
    }
    pLast = pCur;
    pCur = pFirst;
    pStop = nullptr;
};

template <class T> TList<T>::TList(const TList<T>& pList){
    if (pList.pFirst == nullptr)
    {
        return;
    }
    TNode<T>* oldCurrent = pList.pFirst;
    pFirst = new TNode<T>(*pList.pFirst);
    TNode<T>* newCurrent = pFirst;
    oldCurrent = oldCurrent->pNext;
    while (oldCurrent != pList.pStop)
    {
        newCurrent->pNext = new TNode<T>(oldCurrent->key);
        newCurrent = newCurrent->pNext;
        oldCurrent = oldCurrent->pNext;
    }
    pLast = newCurrent;
    pStop = pLast->pNext;
    pCur = pFirst;
    pStop = nullptr; 
}

template<class T> void TList<T>::Clear() {
    if (pFirst == nullptr)
    {
        return;
    }
    pCur = pFirst;
    TNode<T>* tmp = pCur;
    while (pCur != pStop) {
        pCur = pCur->pNext;
        delete tmp;
        tmp = pCur;
    }
    pCur = pStop;
    pLast = pStop;
    pFirst = pStop;
}

template<class T> TList<T>::~TList() {
    Clear();
}

//FUnCTIONS

template<class T> bool TList<T>::is_Full() const{
    try
    {
        TNode<T>* tmp = new TNode<T>();
        if (tmp == 0)
            return 1;
        else
        {
            delete tmp;
            return 0;
        }
    }
    catch (...)
    {
        return 0;
    }
    return true;
}

template<class T> bool TList<T>::is_Empty() const {
    if (pFirst == pStop)
        return true;
    else
        return false;
}

template<class T> TNode<T>* TList<T>::Search(const T& key_) {
    pCur = pFirst;
    while ((pCur != pStop) && (pCur->key != key_))
    {
       Next(); //pCur = pCur->pNext;
    }
    return pCur;
}


template<class T> const int TList<T>::GetSize() const {
    return ListLen;
}

template<class T> TNode<T>* TList<T>::GetCurrent() const {
    return pCur;
}

template<class T> void TList<T>::Reset() {
    if (is_Empty()) {
        pCur = pStop;
    }
    else {
        pCur = pFirst;
    }
    return;
}

template<class T> void TList<T>::Next() {
    if (pCur == pStop)
    {
        return;
    }
    pCur = pCur->pNext;
}

//INSERT
template<class T> void TList<T>::InsertFirst(const T& key_) {
    if (is_Full()) {
        throw "Error. Memory is not enough";
    }
    TNode<T>* newNode = new TNode<T>(key_, nullptr);

    if (pFirst != pStop)
    {
        TNode<T>* oldPFirst = pFirst;
        pFirst = newNode;
        pFirst->pNext = oldPFirst;
        
    }
    else {
        pFirst = newNode;
    }
    pCur = pFirst;
    if (pLast == pStop) {
        pLast = pFirst;
    };
}

template<class T> void TList<T>::InsertLast(const T& key_) {
    if (is_Empty())
    {
        InsertFirst(key_);
        pLast = pFirst;
        return;
    }
    TNode<T>* newNode = new TNode<T>(key_, nullptr);
    pLast->pNext = newNode;
}

//изменить эти инсерты
template<class T> void TList<T>::InsertBefore(const T& key_, const T& NextKey) {
    if (is_Empty()) {
        throw "Error. List is empty.";
    }
    pCur = pFirst;
    TNode<T>* pPrev = nullptr;
    while ((pCur->pNext != pStop) && (pCur->key != NextKey))
    {
        pPrev = pCur;
        Next();
    }
    if ((pCur->pNext == pStop) && (pCur->key != NextKey))
    {
        throw "Error. Key not found.";
    }
    TNode<T>* newNode = new TNode<T>(key_, pCur);

    // list have only 1 node
    if (pPrev == pStop) {
        pFirst = newNode;
    }
    else {
        pPrev->pNext = newNode;
    }
    pCur = pFirst;
}
/* 
template<class T> void TList<T>::InsertBefore(const T& key_, const T& NextKey) {
    if (is_Empty()) {
        return;
    }
    TNode<T>* pNode = pFirst;
    TNode<T>* pPrev = nullptr;
    while ((pNode->pNext != pStop) && (pNode->key != NextKey))
    {
        pPrev = pNode;
        pNode = pNode->pNext;
    }
    if ((pNode->pNext == pStop) && (pNode->key != NextKey))
    {
        return;
    }
    TNode<T>* newNode = new TNode<T>(key_, pNode);

    // list have only 1 node
    if (pPrev == pStop) {
        pFirst = newNode;
    }
    else {
        pPrev->pNext = newNode;
    }
}
*/
template<class T> void TList<T>::InsertAfter(const T& key_, const T& PrevKey) {
    TNode<T>* prNode = Search(PrevKey);
    if (prNode == pStop)
    {
        return;
    }
    TNode<T>* tmp = new TNode<T>(key_, prNode->pNext);
    prNode->pNext = tmp;
}
#endif