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
	virtual ~TList();
	void Clear();

	TNode<T>* Search(const T& data_);
	void InsertFirst(const T& data_);
	void InsertBefore(const T& data_, const T& NextData);
	void InsertAfter(const T& data_, const T& BeforeData);
	void InsertBefore(const T& data_); //текущего
	void InsertAfter(const T& data_);  //текущего
	void Remove(const T& data_);


	int GetSize();
	bool IsEmpty();
	bool IsFull();
	bool IsEnded();

	void Reset();
	void Next(const int count = 1);
	TNode<T>* GetCurrent();

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

	if (pFirst_ == nullptr) {
		pFirst = nullptr;
		return;
	}
	pFirst = new TNode<T>(pFirst_->data);
	pStop = nullptr;
	TNode<T>* tmp = pFirst_;
	tmp = tmp->pNext;
	TNode<T>* tmp1 = pFirst;
	while (tmp != pStop) {
		tmp1->pNext = new TNode<T>(tmp->data);
		tmp1 = tmp1->pNext;
		tmp = tmp->pNext;
	}
	pLast = tmp1;
	pLast->pNext = pStop;
	pCurr = pFirst;
	/*
	pStop = nullptr;
	pFirst = pFirst_;
	if (pFirst == pStop) {
		pLast = pStop;
		pCurr = pStop;
		return;
	}
	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop)
		tmp = tmp->pNext;
	pLast = tmp;
	pCurr = pFirst;
	*/
}




template<typename T>
TList<T>::TList(const TList<T>& obj) {
	if (obj.pFirst == nullptr) { return; }
	TNode<T>* tmp = obj.pFirst;
	pFirst = new TNode<T>(obj.pFirst->data);
	TNode<T>* tmp2 = pFirst;
	tmp = tmp->pNext;
	while (tmp != obj.pStop) {
		tmp2->pNext = new TNode<T>(tmp->data);
		tmp2 = tmp2->pNext;
		tmp = tmp->pNext;
	}
	pStop = nullptr;
	pLast = tmp2;
	pLast->pNext = pStop;
	pCurr = pFirst;
}

//деструктор и метод Clear для него

template<typename T>
TList<T>::~TList()
{
	Clear();
}

template<typename T>
void TList<T>::Clear() {
	
	if (IsEmpty()) {
		return;
	}
	if (pFirst == pLast) {
		delete pFirst;
		return;
	}
	while (pFirst != pStop) {
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;                   
		tmp = pFirst;
	}
}

//функции класса

template<typename T>
TNode<T>* TList<T>::Search(const T& data_) {
	TNode<T>* tmp = pFirst;
	while ((tmp != pStop) && (tmp->data != data_)) {
		tmp = tmp->pNext;
	}
	if ((tmp == pStop)) { throw "Not found"; }
	return tmp;
}

template<typename T>
void TList<T>::InsertFirst(const T& data_) {
	
	if (IsEmpty()) {
		pFirst = new TNode<T>(data_, pStop);
		pLast = pFirst;
		pCurr = pFirst;
		return;
	}
	if (IsFull()) {
		throw "List is full";
	}
	TNode<T>* tmp = new TNode<T>(data_, pFirst);
	pFirst = tmp; 
	Reset();
}



template<typename T>
void TList<T>::InsertBefore(const T& data_, const T& NextData) {
	if (IsEmpty()) {
		throw "Node is empty";
	}
	if (IsFull()) {
		throw "List is full";
	}
	TNode<T>* tmp = pFirst, * pPrev = nullptr;
	while ((tmp->pNext != pStop) && (tmp->data != NextData)) {
		pPrev = tmp;
		tmp = tmp->pNext;
	}
	if ((tmp->pNext == pStop) && (tmp->data != NextData)) {
		throw "NextData not is find";
	}
	TNode<T>* tmp1 = new TNode<T>(data_, tmp);
	if (tmp == pFirst) {
		pFirst = tmp1;
		Reset();
		return;
	}
	pPrev->pNext = tmp1;
	Reset();
}

template<typename T>
void TList<T>::InsertAfter(const T& data_, const T& BeforeData) {
	if (IsEmpty()) {
		throw "Node is empty";
	}
	if (IsFull()) {
		throw "List is full";
	}
	TNode<T>* tmp = pFirst->pNext, * pPrev = pFirst;
	while ((tmp != pStop) && (pPrev->data != BeforeData)) {
		pPrev = tmp;
		tmp = tmp->pNext;
	}
	if ((tmp == pStop) && (pPrev->data != BeforeData)) {
		throw "BeforeData not is find";
	}
	TNode<T>* tmp1 = new TNode<T>(data_, tmp);
	pPrev->pNext = tmp1;
	Reset();
} 

template<typename T>
void TList<T>::InsertBefore(const T& data_){
	if (IsEmpty()) {
		throw "Node is empty";
	}
	if (IsFull()) {
		throw "List is full";
	}
	TNode<T>* tmp = pFirst, * pPrev = nullptr;
	while ((tmp->pNext != pStop) && (tmp->data != pCurr->data)) {
		pPrev = tmp;
		tmp = tmp->pNext;
	}
	if ((tmp->pNext == pStop) && (tmp->data != pCurr->data)) {
		throw "Current not is find";
	}
	TNode<T>* tmp1 = new TNode<T>(data_, tmp);
	if (tmp == pFirst) {
		pFirst = tmp1;
		Reset();
		return;
	}
	pPrev->pNext = tmp1;
	Reset();

} 

template<typename T>
void TList<T>::InsertAfter(const T& data_) {
	if (IsEmpty()) {
		throw "Node is empty";
	}
	if (IsFull()) {
		throw "List is full";
	}
	TNode<T>* tmp = pFirst->pNext, * pPrev = pFirst;
	while ((tmp != pStop) && (pPrev->data != pCurr->data)) {
		pPrev = tmp;
		tmp = tmp->pNext;
	}
	if ((tmp == pStop) && (pPrev->data != pCurr->data)) {
		throw "Current not is find";
	}

	if (tmp == pStop) {
		TNode<T>* tmp1 = new TNode<T>(data_, tmp);
		pPrev->pNext = tmp1;
		pLast = pPrev->pNext;
		Reset();
		return;
	}

	TNode<T>* tmp1 = new TNode<T>(data_, tmp);
	pPrev->pNext = tmp1;

	Reset();
}


template<typename T>
void TList<T>::Remove(const T& data_) {
	if (pFirst == nullptr) {
		throw "Node is empty";
	}
	TNode<T>* tmp = pFirst, * pPrev = nullptr;
	while ((tmp->pNext != pStop) && (tmp->data != data_)) {
		pPrev = tmp;
		tmp = tmp->pNext;
	}
	if ((tmp->pNext == pStop) && (tmp->data != data_)) {
		throw "Node with this data not is find";
	}
	if (tmp == pFirst) {
		pFirst = tmp->pNext;
		delete tmp;
		pCurr = pFirst;
		return;
	}
	if (tmp == pLast) {
		pPrev->pNext = pStop;
		delete tmp;
		pLast = pPrev;
		return;
	}
	pPrev->pNext = tmp->pNext;
	delete tmp;
}


template<typename T>
int TList<T>::GetSize() {
	if (IsEmpty()) {
		return 0;
	}
	TNode<T>* tmp = pFirst;
	int i = 0;
	while (tmp != pStop) {
		tmp = tmp->pNext;
		i++;
	}
	return i;
}

template<typename T>
bool TList<T>::IsEmpty() {
	if (pFirst == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
bool TList<T>::IsFull() {
	TNode <T>* tmp = new TNode<T>();
	if (tmp == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
void TList<T>::Reset() {
	pCurr = pFirst;
}

template<typename T>
bool TList<T>::IsEnded() {
	if (pCurr == pLast) {
		return true;
	}
	else {
		return false;
	}
}



template<typename T>
TNode<T>* TList<T>::GetCurrent() {
	return pCurr;
}


template <typename T>
void TList<T>::Next(const int count) {
	if (count <= 0) {
		string exp = "Error: count can't be less than 0";
		throw exp;
	}

	for (int i = 0; i < count; i++) {
		//if (!IsEnded() || pCurr != pStop) pCurr = pCurr->pNext;
		if (!IsEnded()) pCurr = pCurr->pNext;
		else Reset();
	}
}


#endif // !1
