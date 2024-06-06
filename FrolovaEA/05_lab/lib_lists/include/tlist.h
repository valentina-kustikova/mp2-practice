#ifndef TLIST_H
#define TLIST_H

#include <iostream>
#include "tnode.h"

using namespace std;

template <typename T>
class TList
{
protected:

	TNode<T>* pFirst;
	TNode<T>* pLast;
	TNode<T>* pCurr;
	TNode<T>* pStop;

public:
	TList();
	TList(TNode<T>* _pFirst);
	TList(const TList<T>& obj);
	virtual ~TList();

	bool IsEmpty() const;
	bool IsFull() const;
	bool Is_End() const;

	TNode<T>* Search(const T& data);
	TNode<T>* GetCurrent() const;
	void sort();

	virtual void InsertFirst(const T& data);

	virtual void InsertLast(const T& data);
	const TList<T>& operator=(const TList<T>& p);
	void InsertBefore(const T& data);
	void InsertAfter(const T& data);
	void InsertBefore(const T& data, const T& NextData);
	void InsertAfter(const T& data, const T& PreviousData);
	virtual void Remove(const T& data);
	virtual void removeCurrentNode();
	void pop_front();
	int GetSize() const;

	void Clear();
	void Reset();
	void Next();

	
	friend ostream& operator<<(ostream& out, TList<T>& list)
	{
		TNode<T>* tmp = list.pFirst;
		if (list.IsEmpty())
		{
			out << "empty list\n";
			return out;
		}
		while (tmp != list.pStop)
		{
			out << tmp->key << " ";
			tmp = tmp->pNext;
		}
		out << endl;
		return out;
	}

};

template<typename T>
TList<T>::TList()
{
	pStop = nullptr;
	pFirst = pStop;
	pLast = pStop;
	pCurr = pStop;
}

template<typename T>
TList<T>::TList(TNode<T>* _pFirst)
{
	pStop = nullptr;
	pFirst = _pFirst;
	if (pFirst == pStop)
	{
		pLast = pStop;
		pCurr = pStop;
		return;
	}
	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop)
	{
		tmp = tmp->pNext;
	}
	pLast = tmp;

}

template<typename T>
TList<T>::TList(const TList<T>& obj)
{
	TNode<T>* tmp = obj.pFirst;
	if (obj.pFirst == obj.pStop)
	{
		pStop = nullptr;
		pFirst = pStop;
		pLast = pStop;
		pCurr = pFirst;
		return;
	}

	pFirst = new TNode<T>(obj.pFirst->key);

	TNode<T>* tmp2 = pFirst;
	tmp = tmp->pNext;

	while (tmp != obj.pStop)
	{
		tmp2->pNext = new TNode<T>(tmp->key);
		tmp2 = tmp2->pNext;
		tmp = tmp->pNext;
	}

	pLast = tmp2;
	pStop = nullptr;
	pCurr = pFirst;

}

template<typename T>
TList<T>::~TList()
{
	Clear();
}

template<typename T>
bool TList<T>::IsEmpty() const
{
	if (pFirst == pStop) return true;
	else return false;
}

template<typename T>
bool TList<T>::IsFull() const
{
	TNode<T>* tmp = new TNode<T>;
	if (tmp != nullptr)
	{
		delete tmp;
		return false;
	}
	else return true;
}

template<typename T>
bool TList<T>::Is_End() const
{
	//	if (pCurr == pLast) return true;
	if (pCurr == pStop) return true;
	else return false;
}

template<typename T>
TNode<T>* TList<T>::Search(const T& data)
{
	if (pFirst == nullptr) return nullptr;

	TNode<T>* tmp = pFirst;
	while (tmp->pNext != pStop)
	{
		if (tmp->key == data)
		{
			break;
		}
		tmp = tmp->pNext;
	}
	if (tmp->pNext == pStop && tmp->key != data)
	{
		return nullptr;
	}
	return tmp;
}

template<typename T>
TNode<T>* TList<T>::GetCurrent() const
{
	return pCurr;
}

template<typename T>
void TList<T>::sort()
{
	TNode<T>* tmp1 = pFirst;

	while (tmp1->pNext != pStop)
	{
		TNode<T>* tmp2 = tmp1->pNext;
		while (tmp2 != pStop)
		{
			if (tmp1->key < tmp2->key)
			{
				T elem = tmp1->key;
				tmp1->key = tmp2->key;
				tmp2->key = elem;
			}
			tmp2 = tmp2->pNext;
		}
		tmp1 = tmp1->pNext;
	}
}

template<typename T>
void TList<T>::InsertFirst(const T& data)
{
	pFirst = new TNode<T>(data, pFirst);
	if (pFirst->pNext == pStop)
	{
		pLast = pFirst;
	}
	pCurr = pFirst;
}

template<typename T>
void TList<T>::InsertLast(const T& data)
{
	if (pFirst == pStop)
	{
		InsertFirst(data);
	}
	else
	{
		TNode<T>* tmp = new TNode<T>(data, pStop);
		pLast->pNext = tmp;
		pLast = tmp;
	}
	if (pCurr == pStop) Reset();
}

template<typename T>
const TList<T>& TList<T>::operator=(const TList<T>& p)
{
	if (p.pFirst == p.pStop)
	{
		throw"Error";
	}

	if (this == &p) // ѕроверка на самоприсваивание
	{
		return *this;
	}

	Clear();

	TNode<T>* pNode = p.pFirst;
	while (pNode != p.pStop)
	{
		InsertLast(pNode->key);
		pNode = pNode->pNext;
	}

	return *this;
}

template<typename T>
void TList<T>::InsertBefore(const T& data)
{
	if (pCurr == pStop)
	{
		throw"change position";
	}
	if (pCurr == pFirst)
	{
		InsertFirst(data);
	}
	else
	{

		TNode<T>* tmp = pFirst;
		while (tmp->pNext != pCurr)
		{
			tmp = tmp->pNext;
		}
		tmp->pNext = new TNode<T>(data, pCurr);
	}
}

template<typename T>
void TList<T>::InsertAfter(const T& data)
{
	if (pCurr == pStop)
	{
		throw"change position";
	}
	if (Is_End())
	{
		InsertLast(data);

	}
	else
	{
		pCurr->pNext = new TNode<T>(data, pCurr->pNext);
	}

}

template<typename T>
void TList<T>::InsertBefore(const T& data, const T& NextData)
{
	TNode<T>* tmp = pFirst;
	TNode<T>* Before = nullptr;

	while (tmp != pStop && tmp->key != NextData)
	{
		Before = tmp;
		tmp = tmp->pNext;
	}
	if (tmp == pStop)
	{
		throw"Not found";
	}
	if (tmp == pFirst)
	{
		InsertFirst(data);
		return;
	}

	Before->pNext = new TNode<T>(data, tmp);

	if (pCurr == pStop) Reset();

}

template<typename T>
void TList<T>::InsertAfter(const T& data, const T& PreviousData)
{
	TNode<T>* tmp = pFirst;

	while (tmp != pStop && tmp->key != PreviousData)
	{
		tmp = tmp->pNext;
	}

	if (tmp == pStop)
	{
		throw"Not found";
	}

	if (tmp == pLast)
	{
		InsertLast(data);
		return;
	}

	tmp->pNext = new TNode<T>(data, tmp->pNext);

}

template<typename T>
void TList<T>::Remove(const T& data)
{
	if (pFirst == pStop)
	{
		throw"List is empty";
	}

	TNode<T>* tmp = pFirst;
	TNode<T>* previous = nullptr;
	//tmp->pNext != pStop
	while (tmp->pNext!= pStop && tmp->key != data)
	{
		previous = tmp;
		tmp = tmp->pNext;
	}
	//tmp->pNext == pStop
	if (tmp->pNext== pStop && tmp->key != data)
	{
		throw "Not found";
	}
	if (previous == nullptr)
	{
		pFirst = tmp->pNext;
		delete tmp;
		return;
	}
	previous->pNext = tmp->pNext;
	delete tmp;

}

template<typename T>
void TList<T>::removeCurrentNode()
{
	if (pCurr == nullptr) {
		return; // Ќичего не делаем, если текущий указатель равен nullptr
	}

	TNode<T>* pPrev = nullptr;
	TNode<T>* pNode = pFirst;

	while (pNode != nullptr && pNode != pCurr) {
		pPrev = pNode;
		pNode = pNode->pNext;
	}

	if (pNode == nullptr) {
		return; // ”зел не найден, ничего не делаем
	}

	if (pPrev != nullptr) {
		pPrev->pNext = pCurr->pNext;
	}
	else {
		pFirst = pCurr->pNext;
	}

	if (pLast == pCurr) {
		pLast = pPrev;
	}

	TNode<T>* temp = pCurr;
	pCurr = pCurr->pNext; // ѕеремещаем указатель на следующий узел
	if (pCurr == pStop) Reset();
	delete temp;
}

template<typename T>
void TList<T>::pop_front()
{
	if (pFirst == pStop)
	{
		throw"list is empty";
	}
	TNode<T>* tmp = pFirst;
	pFirst = pFirst->pNext;
	delete tmp;
	//	pCurr = pFirst;
}

template<typename T>
int TList<T>::GetSize() const
{
	int size = 0;
	TNode<T>* tmp = pFirst;
	while (tmp != pStop)
	{
		tmp = tmp->pNext;
		size++;
	}
	return size;
}

template<typename T>
void TList<T>::Clear()
{
	while (GetSize())
	{
		pop_front();
	}
}

template<typename T>
void TList<T>::Reset()
{
	pCurr = pFirst;
}

template<typename T>
void TList<T>::Next()
{
	if (!Is_End() && pCurr != pStop)
	{
		pCurr = pCurr->pNext;
	}
	else
	{
		Reset();
	}
}





#endif

