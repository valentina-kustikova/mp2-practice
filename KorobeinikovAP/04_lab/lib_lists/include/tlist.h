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
	TList(const TNode<T>* pFirst_);
	TList(const TList<T>& obj);
	~TList();
	TNode * Search(const T& data_);
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
	TNode* GetCurrent();
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
TList<T>::TList(const TNode<T>* pFirst_) {
	pFirst = pFirst_;
	pStop = nullptr;
	TNode* tmp = pFirst;
	while (tmp->pNext != pStop) {
		tmp = tmp->pNext;
	}
	pLast = tmp;
	pCurr = pFirst;
}


//ошибка в том, что конструктор копирования для узла не сделать, надо исправить, но это быстро

template<typename T>
TList<T>::TList(const TList<T>& obj) {
	if (obj.pFirst == nullptr) { return; }
	TNode* tmp = obj.pFirst;
	pFirst = new TNode<T>(obj.pFirst);
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

#endif // !1
