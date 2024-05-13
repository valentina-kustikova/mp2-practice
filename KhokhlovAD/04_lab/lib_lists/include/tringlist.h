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
	void InsertFirst(const T& data);
	void DeleteFirst();
	const TRingList<T>& operator=(const TRingList<T>& pRingList);
	TRingList<T>&  Copy();
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
TRingList<T>::~TRingList() {
	if (pFirst == nullptr) 
		throw std::exception("ERROR: list already empty");
	TNode<T>* tmp = pFirst;
	while (pFirst != pHead) {
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
	if (pFirst == pStop)
	{
		delete pHead;
		pHead = nullptr;
		pFirst = nullptr;
		pPrev = nullptr;
		pLast = nullptr;
		pCurr = nullptr;
		pStop = nullptr;
		return;
	}
	delete tmp;
	delete pHead;
	pHead = nullptr;
	pFirst = nullptr;
	pPrev = nullptr;
	pLast = nullptr;
	pCurr = nullptr;
	pStop = nullptr;
}

template<typename T>
void TRingList<T>::InsertFirst(const T& data)
{
	TNode<T>* tmp = new TNode<T>(data);
	tmp->pNext = pFirst;
	if (this->pFirst == this->pStop)
	{
		this->pLast = tmp;
	}
	this->pFirst = tmp;
	this->pCurr = this->pFirst;
}

template <typename T>
void TRingList<T>::DeleteFirst()
{
	if (IsEmpty())
		throw std::exception("empty list(DelF)");
	if (pFirst == pLast)
	{
		*this = TRingList<T>(T());
		return;
	}
	TNode<T>* tmp = pFirst->pNext;
	delete pFirst;
	pFirst = tmp;
	pCurr = pFirst;
	pHead->pNext = pFirst;
}
template <typename T>
const TRingList<T>& TRingList<T>::operator=(const TRingList<T>& pRingList)
{

	pHead = new TNode<T>(T());
	pHead->pNext = this->pFirst;
	this->pStop = pHead;

	if (pRingList.pFirst == pRingList.pStop)
	{
		this->pFirst = pHead;
		this->pLast = pHead;
		this->pCurr = pHead;
	}
	else
	{
		this->pFirst = new TNode<T>(pRingList.pFirst->data);
		TNode<T>* tmp = pRingList.pFirst;
		TNode<T>* tmp_1 = this->pFirst;

		while (tmp->pNext != pRingList.pStop)
		{
			tmp_1->pNext = new TNode<T>(tmp->pNext->data);
			tmp_1 = tmp_1->pNext;
			tmp = tmp->pNext;
		}
		this->pLast = tmp_1;
		this->pLast->pNext = this->pStop;
		this->pCurr = this->pFirst;
	}
	return *this;
}

template <typename T>
TRingList<T>& TRingList<T>::Copy()
{
	return *this;
}
#endif