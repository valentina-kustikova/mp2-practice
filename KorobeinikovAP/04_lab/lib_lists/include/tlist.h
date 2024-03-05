#ifndef __TLIST_H__
#define __TLIST_H__

#include "tnode.h"

template <typename T>
class TList {
protected:
	TNode<T>* pFirst;
	TNode<T>* pCurr;
	TNode<T>* pLast;
	TNode<T>* pStop;
public:
	TList();
	TList(TNode<T>* pFirst_);
	TList(const TList<T>& obj);
	~TList();
	TNode<T>* Search(const T& data_);
	void InsertFirst(const T& data_);
	void InsertBefore(const T& data_, const T& NextData);
	void InsertAfter(const T& data_, const T& BeforeData);
	void InsertBefore(const T& data_); //текущего
	void InsertAfter(const T& data_);  //текущего
	void Remove(const T& data_);
	void Clear();
	int GetSize();
	bool IsEmpty();
	bool IsFull();
	void Reset();
	TNode<T>* GetCurrent();
	void IsEnted();
};

//конструкторы

template<typename T>
TList<T>::TList() {
	pFirst = nullptr;
	pCurr = nullptr;
	pLast = nullptr;
	pStop = nullptr;
}



template<typename T>
TList<T>::TList(TNode<T>* pFirst_) {
	pFirst = pFirst_;
	pStop = nullptr;
	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop) {
		tmp = tmp->pNext;
	}
	pLast = tmp;
	pCurr = pFirst;
}


template<typename T>
TList<T>::TList(const TList<T>& obj) {
	if (obj.pFirst == nullptr) { return; }
	TNode<T>* tmp = obj.pFirst;
	pFirst = new TNode<T>(obj.data);
	TNode<T>* tmp2 = pFirst;
	tmp = tmp->pNext;
	while (tmp != obj.stop) {
		tmp2->pNext = new TNode<T>(tmp->data);
		tmp2 = tmp2->pNext;
		tmp = tmp->pNext;
	}
	pLast = tmp2;
	pStop = pLast->pNext;
	pCurr = pFirst;
}

//деструктор

template<typename T>
TList<T>::~TList()
{
	//Clear();
}

template<typename T>
void TList<T>::Clear() {

}


#endif // !1
