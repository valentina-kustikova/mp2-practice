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
	TRingList(const TNode<T>* pF);
	TRingList(const TRingList<T>& obj);

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
TRingList<T>::TRingList(const TNode<T>* pF) : TList<T>::TList(pF) 
{
	pHead = new TNode<T>(T());
	pStop = pHead;
	pHead->pNext = pFirst;
	pPrev = pHead;
	pLast->pNext = pStop;
}

template <typename T>
TRingList<T>::TRingList(const TRingList<T>& obj) : TList<T>::TList(obj)
{
	pHead = new TNode<T>(T());
	pStop = pHead;
	if (obj.pFirst == obj.pStop)
	{
		this->pFirst = pHead;
		this->pLast = pHead;
		this->pCurr = pHead;
		this->pPrev = pHead;
	}
	pPrev = pStop;
	pHead->pNext = pFirst;
	pLast->pNext = pStop;
}

template <typename T>
void TRingList<T>::clear()
{
	TList<T>::clear();
	pHead->pNext = pHead;
}

template <typename T>
TRingList<T>::~TRingList() { 
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
	pHead->pNext = this->pFirst;
	
	return *this;
}
#endif