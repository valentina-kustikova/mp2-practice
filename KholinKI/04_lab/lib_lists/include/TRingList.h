#ifndef _TRINGLIST_H
#define _TRINGLIST_H

#include "TList.h"

template <typename T>
class TRingList : public TList<T> {
protected:
	Node<T>* pHead;
public:
	TRingList();
	TRingList(Node<T>* pFirst);
	TRingList(const TRingList<T>& rList);
	virtual ~TRingList();

	void insert_first(const T& data_) override;
	void insert_before(const T& data_, const T& next_data_) override;
	void remove(const T& data_) override;
};

template<typename T>		
TRingList<T>::TRingList():TList(){
	pHead = new Node<T>();
	pHead->pNext = pFirst;
	pStop = pHead;
}

template <typename T>
TRingList<T>::TRingList(Node<T>* pFirst) : TList<T>(pFirst) {
	pHead = new Node<T>();
	pHead->pNext = this->pFirst;
	pStop = pHead;
	if (pFirst == nullptr) {
		return;
	}
	Node<T>* tmp = this->pFirst;

	while (tmp->pNext != nullptr) {
		tmp = tmp->pNext;
	}

	tmp->pNext = pHead;
	pLast = tmp;
}

template <typename T>
TRingList<T>::TRingList(const TRingList<T>& rList) : TList<T>(rList) {
	if (rList.pFirst == rList.pHead) {
		pHead = new Node<T>();
		pFirst = nullptr;
		pHead->pNext = pFirst;
		pStop = pHead;
		return;
	}
	pHead = new Node<T>();
	pHead->pNext = pFirst;
	pLast->pNext = pHead;
	pStop = pHead;
}

template<typename T>
TRingList<T>::~TRingList() {
	pHead->pNext = nullptr;
	delete pHead;
}

template<typename T>
void TRingList<T>::insert_first(const T& data_) {
	Node<T>* tmp = new Node<T>(data_);
	tmp->pNext = pFirst;
	if (pFirst == nullptr) {
		pFirst = tmp;
		pFirst->pNext = pHead;
		pHead->pNext = pFirst;
		pLast = pFirst;
		pCurr = pFirst;
	}
	else {
		pFirst = tmp;
		pHead->pNext = pFirst;
		pCurr = pFirst;
	}
}

template<typename T>
void TRingList<T>::insert_before(const T& data_, const T& next_data_) {
	if (pFirst == nullptr) {
		insert_first(data_);
	}
	Node<T>* tmp = pFirst;
	Node<T>* pPrev = pHead;
	while (tmp->data != next_data_ && tmp != pStop) {
		pPrev = tmp;
		tmp = tmp->pNext;
	}
	if (tmp->data != next_data_ && tmp == pStop) {
		throw "Data not found!";
	}
	Node<T>* node = new Node<T>(data_);
	if (tmp == pFirst) {
		insert_first(data_);
	}
	else {
		node->pNext = tmp;
		pPrev->pNext = node;
	}
}

template<typename T>
void TRingList<T>::remove(const T& data_) {
	if (pFirst == nullptr) {
		return;
	}
	else {
		Node<T>* tmp = pFirst;
		Node<T>* pPrev = pHead;

		while (tmp->data != data_ && tmp != pStop) {
			pPrev = tmp;
			tmp = tmp->pNext;
		}
		if (tmp->data != data_ && tmp == pStop) {
			throw "Data not found!";
		}
		if (pPrev == pHead) {
			pFirst = pFirst->pNext;
			pCurr = pFirst;
			pPrev->pNext = pFirst;
			tmp->pNext = nullptr;
			delete tmp;
		}
		else {
			pPrev->pNext = tmp->pNext;
			if (tmp->pNext == pStop) {
				pLast = pPrev;
			}
			tmp->pNext = nullptr;
			delete tmp;
		}
	}
}





#endif