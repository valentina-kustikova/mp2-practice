#ifndef TRINGLIST_H
#define TRINGLIST_H

#include <iostream>
#include "tlist.h"



using namespace std;


template<typename T>
class TRingList : public TList<T>
{
private:

	TNode<T>* pHead;

public:

	TRingList();
	TRingList(TNode<T>* _pFirst);
	TRingList(const TRingList<T>& obj);
	virtual ~TRingList();

	void InsertFirst(const T& data);
	void InsertLast(const T& data);
	void Remove(const T& data);
	void removeCurrentNode();

};




template<typename T>
TRingList<T>::TRingList() : TList<T>()
{
	pHead = new TNode<T>(T());
	pStop = pHead;
	pFirst = pHead;
	pHead->pNext = pFirst;
	pLast = pHead;
	pCurr = pHead;


}

template<typename T>
TRingList<T>::TRingList(TNode<T>* _pFirst) : TList<T>(_pFirst)
{
	pHead = new TNode<T>(T());
	pHead->pNext = this->pFirst;
	if (_pFirst == nullptr)
	{
		pLast->pNext = pHead;
	}
	else
	{
		pHead->pNext = pHead;
	}
	
}

template<typename T>
TRingList<T>::TRingList(const TRingList<T>& obj) : TList<T>(obj)
{

	/*if (obj.pFirst == obj.pStop)
		return;
	pHead = new TNode<T>(T());
	pHead->pNext = pFirst;
	pLast->pNext = pHead;
	pStop = pHead;*/

	pHead = new TNode<T>(T());
	if (obj.pFirst == obj.pStop)
	{
		pFirst = pHead;
		pHead->pNext = pFirst;
		pLast = pHead;
		pCurr = pHead;
		pStop = pHead;
		return;
	}
	pHead = new TNode<T>(T());
	pHead->pNext = pFirst;
	pLast->pNext = pHead;
	pStop = pHead;

}

template<typename T>
TRingList<T>::~TRingList()
{
	if (pHead)
		delete pHead;
}

template<typename T>
void TRingList<T>::InsertFirst(const T& data)
{
	TList<T>::InsertFirst(data);
	this->pHead->pNext = this->pFirst;
	this->pStop = this->pHead;
	this->pLast->pNext = this->pStop;
}

template<typename T>
void TRingList<T>::InsertLast(const T& data)
{
	TList<T>::InsertLast(data);
	this->pHead->pNext = this->pFirst;
	this->pStop = this->pHead;
	this->pLast->pNext = this->pStop;
}

template<typename T>
void TRingList<T>::Remove(const T& data)
{
	TList<T>::Remove(data);
	if (this->pFirst != this->pStop && this->pFirst != nullptr)
	{
		this->pLast->pNext = this->pHead;
	}

}

template<typename T>
void TRingList<T>::removeCurrentNode()
{
	TList<T>::removeCurrentNode();
	if (this->pFirst != this->pStop /*&& this->pFirst != nullptr*/) //???
	{
		this->pLast->pNext = this->pHead;
	}
}


#endif
