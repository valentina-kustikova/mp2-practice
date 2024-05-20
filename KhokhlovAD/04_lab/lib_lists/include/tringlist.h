#ifndef _TRINGLIST_
#define _TRINGLIST_
#include "tlist.h"


template <typename T>
class TRingList : public TList<T>
{
private:
	TNode<T>* pHead;
public:
	TRingList();
	TRingList(const T& data);
	TRingList(const TNode<T>* pF);
	TRingList(const TRingList<T>& ringList);

	~TRingList();
	void clear();

	void InsertFirst(const T& data);
	void DeleteFirst();
	const TRingList<T>& operator=(const TRingList<T>& pRingList);
};

template <typename T> 
TRingList<T>::TRingList() {
	pHead = new TNode<T>(T());
	this->pStop = pHead;
	pHead->pNext = this->pFirst;
	this->pFirst = pHead;
	this->pLast = pHead;
	this->pCurr = pHead;
	this->pPrev = pHead;
}

template <typename T>
TRingList<T>::TRingList(const T& data)
{
	pHead = new TNode<T>(T());
	this->pStop = pHead;
	pHead->pNext = this->pFirst;
	this->pFirst = new TNode<T>(data);
	this->pLast = pHead;
	this->pFirst->pNext = pLast;
	this->pCurr = pFirst;
	this->pPrev = pHead;
}

template <typename T>
TRingList<T>::TRingList(const TNode<T>* pF)
{
	pHead = new TNode<T>(T());
	pCurr = nullptr;
	if (pF != nullptr) {
		pFirst = new TNode<T>(pF->data);
		pHead->pNext = pFirst;
		pCurr = pFirst;
		pPrev = pHead;
		pStop = pHead;
		TNode<T>* tmp = pFirst;
		while (tmp->pNext != nullptr && tmp->pNext != pFirst) {
			tmp = new TNode<T>(tmp->pNext->data);
			pCurr->pNext = tmp;
			pCurr = tmp;
		}
		if (tmp->pNext == nullptr) {
			tmp->pNext = pHead;
			pLast = tmp;
		}
	}
}

template <typename T>
TRingList<T>::TRingList(const TRingList<T>& obj)
{
	pHead = new TNode<T>(T());
	pHead->pNext = this->pFirst;
	this->pStop = pHead;

	if (obj.pFirst == obj.pStop)
	{
		this->pFirst = pHead;
		this->pLast = pHead;
		this->pCurr = pHead;
	}
	else
	{
		this->pFirst = new TNode<T>(obj.pFirst->data);
		TNode<T>* tmp = obj.pFirst;
		TNode<T>* tmp_1 = this->pFirst;

		while (tmp->pNext != obj.pStop)
		{
			tmp_1->pNext = new TNode<T>(tmp->pNext->data);
			tmp_1 = tmp_1->pNext;
			tmp = tmp->pNext;
		}
		this->pLast = tmp_1;
		this->pLast->pNext = this->pStop;
		this->pCurr = this->pFirst;
	}
}


template <typename T>
void TRingList<T>::clear()
{
	TList<T>::clear();
	pHead->pNext = pHead;
}

template <typename T>
TRingList<T>::~TRingList() { 
	clear();
	delete pHead;
}

template<typename T>
void TRingList<T>::InsertFirst(const T& data) 
{
	TList<T>::InsertFirst(data);
	pHead->pNext = pFirst;
}

template <typename T>
void TRingList<T>::DeleteFirst() 
{
	TList<T>::DeleteFirst();
	pHead->pNext = pFirst;
}
template <typename T>
const TRingList<T>& TRingList<T>::operator=(const TRingList<T>& pRingList) {
	TList<T>::operator=(pRingList);
	pHead = new TNode<T>(T());
	pHead->pNext = this->pFirst;
	
	return *this;
}
#endif