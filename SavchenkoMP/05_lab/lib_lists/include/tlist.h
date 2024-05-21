#ifndef TLIST_H
#define TLIST_H

#include "tnode.h"

template <typename T>
class TList {
protected:
	TNode<T>* pFirst;
	TNode<T>* pLast;
	TNode<T>* pCurr;
	TNode<T>* pStop;

public:
	TList();
	TList(TNode<T>* _pFirst);
	TList(const TList<T>& list);
	virtual ~TList();

	virtual TNode<T>* find(const T& data);
	virtual void insert_first(const T& data);
	virtual void insert_last(const T& data);
	virtual void insert_before(const T& data);
	virtual void insert_after(const T& data);
	virtual void insert_before(const T& data, const T& before);
	virtual void insert_after(const T& data, const T& after);
	virtual void remove(const T& data);
	virtual void clear();

	virtual size_t size() const;
	bool full() const;
	virtual bool empty() const;

	virtual void reset();
	TNode<T>* get_curr() const;
	virtual void next(const int count = 1);
	virtual bool ended() const;

	TNode<T>* first() const;
	TNode<T>* last() const;
};

template <typename T>
TList<T>::TList() {
	pStop = nullptr;
	pFirst = pStop;
	pLast = pStop;
	pCurr = pStop;

	reset();
}

template <typename T>
TList<T>::TList(TNode<T>* _pFirst) {
	pStop = nullptr;
	pFirst = _pFirst;
	if (pFirst == pStop) {
		pLast = pStop;
		pCurr = pStop;

		reset();
		return;
	}

	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop)
		tmp = tmp->pNext;
	pLast = tmp;

	reset();
}

template <typename T>
TList<T>::TList(const TList<T>& obj) {
	if (obj.pFirst == obj.pStop) {
		pStop = nullptr;
		pFirst = pStop;
		pLast = pStop;
		pCurr = pFirst;

		reset();
		return;
	}

	pFirst = new TNode<T>(obj.pFirst->data);
	TNode<T>* tmp = obj.pFirst;
	TNode<T>* pNode = pFirst;

	while (tmp->pNext != obj.pStop) {
		pNode->pNext = new TNode<T>(tmp->pNext->data);
		pNode = pNode->pNext;
		tmp = tmp->pNext;
	}
	pLast = pNode;
	pStop = pLast->pNext;
	pCurr = pFirst;

	reset();
}

template <typename T>
TList<T>::~TList() {
	clear();
}



template <typename T>
TNode<T>* TList<T>::find(const T& data) { 
	TNode<T>* tmp = pFirst;
	while (tmp != pStop && tmp->data != data)
		tmp = tmp->pNext;
	if (tmp == pStop) tmp = nullptr; 
	return tmp;
}

template <typename T>
void TList<T>::insert_first(const T& data) {
	TNode<T>* tmp = new TNode<T>(data, pFirst);
	if (pFirst == pStop) pLast = tmp;
	pFirst = tmp;

	reset();
}

template <typename T>
void TList<T>::insert_last(const T& data) {
	if (pFirst == pStop) {
		insert_first(data);
		return;
	}
	TNode<T>* tmp = new TNode<T>(data, pStop);
	pLast->pNext = tmp;
	pLast = pLast->pNext;

	reset();
}

/////////////////////////////////
template <typename T>
void TList<T>::insert_before(const T& data) {
	if (pCurr == nullptr) {
		std::string exp = "Error: data not found";
		throw exp;
	}

	if (pCurr == pFirst) {
		insert_first(data);
		return;
	}

	TNode<T>* before = pFirst;
	while (before->pNext != pCurr)
		before = before->pNext;

	TNode<T>* tmp = new TNode<T>(data, pCurr);
	before->pNext = tmp;

	reset();
}

template <typename T>
void TList<T>::insert_after(const T& data) {
	if (pCurr == nullptr) {
		std::string exp = "Error: data not found";
		throw exp;
	}

	if (ended()) {
		insert_last(data);
		return;
	}

	TNode<T>* tmp = new TNode<T>(data, pCurr->pNext);
	pCurr->pNext = tmp;

	reset();
}
/////////////////////////////////

template <typename T>
void TList<T>::insert_before(const T& data, const T& before) {
	pCurr = find(before);

	insert_before(data);

	reset();
}

template <typename T>
void TList<T>::insert_after(const T& data, const T& after) {
	pCurr = find(after);

	insert_after(data);

	reset();
}

/////////////////////////////////


template <typename T>
void TList<T>::remove(const T& data) {
	if (pFirst == pStop) {
		std::string exp = "Error: list is empty";
		throw exp;
	}

	TNode<T>* pNode = pFirst, * pPrev = nullptr;
	while (pNode->pNext != pStop && pNode->data != data) {
		pPrev = pNode;
		pNode = pNode->pNext;
	}

	if (pNode->pNext == pStop && pNode->data != data) {
		std::string exp = "Error: data not found";
		throw exp;
	}

	if (pCurr == pNode) reset();

	if (pPrev == nullptr) {
		pFirst = pNode->pNext;
		delete pNode;
		return;
	}

	pPrev->pNext = pNode->pNext;
	delete pNode;
}


template <typename T>
void TList<T>::clear() {
	TNode<T>* tmp = pFirst;
	while (pFirst != pStop) {
		pFirst = tmp->pNext;
		delete tmp;
		tmp = pFirst;
	}
	pLast = pStop;
	pCurr = pStop;
}



template <typename T>
size_t TList<T>::size() const {
	size_t size = 0;
	TNode<T>* tmp = pFirst;
	while (tmp != pStop) {
		tmp = tmp->pNext;
		++size;
	}
	return size;
}

template <typename T>
bool TList<T>::full() const {
	TNode<T>* tmp = new TNode<T>;
	if (tmp != pStop) {
		return false;
	}
	else {
		return true;
	}
}

template <typename T>
bool TList<T>::empty() const {
	return (pFirst == pStop);
}



template <typename T>
void TList<T>::reset() {
	pCurr = pFirst;
}

template <typename T>
TNode<T>* TList<T>::get_curr() const {
	return pCurr;
}

template <typename T>
void TList<T>::next(const int count) {
	if (count <= 0) {
		std::string exp = "Error: count can't be less than 0";
		throw exp;
	}

	for (int i = 0; i < count; i++) {
		if (!ended()) pCurr = pCurr->pNext;
		else reset();
	}
}

template <typename T>
bool TList<T>::ended() const {
	return (pCurr == pStop);
}

template <typename T>
TNode<T>* TList<T>::first() const {
	return pFirst;
}
template <typename T>
TNode<T>* TList<T>::last() const {
	return pLast;
}

#endif // !TLIST_H
