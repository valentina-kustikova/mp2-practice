#ifndef TLIST_H    
#define TLIST_H

#include<iostream>
#include "TNode.h"
#include"Exception.h"

using namespace std;

template<class TKey, class TData>
class TList
{
private:
	TNode<TKey, TData>* pFirst;
	TNode<TKey, TData>* pCurrent;
	TNode<TKey, TData>* pPrevious;
	TNode<TKey, TData>* pNext;
	void Sort();
	void BringingSimilar();
public:
	TList();
	TList(const TList&);
	TList(const TNode<TKey, TData>*);
	~TList();
	TNode<TKey, TData>* Search(TKey);
	void InsertBegin(TKey, TData);
	void InsertBegin(TNode<TKey, TData>*);
	void InsertEnd(TKey, TData);
	void InsertEnd(TNode<TKey, TData>*);
	void InsertAfter(TKey, TNode<TKey, TData>*);
	void InsertBefore(TKey, TNode<TKey, TData>*);
	void Remove(TKey);

	bool IsEmpty()const;
	bool IsEnded()const;
	void Reset();
	void Next();

	TNode<TKey, TData>* GetFirst()const;
	TNode<TKey, TData>* GetCurrent()const;
	TNode<TKey, TData>* GetNext()const;
	TNode<TKey, TData>* GetPrev()const;

	friend ostream& operator <<(std::ostream& out, const TList<TKey, TData> node)
	{
		TNode<TKey, TData>* tmp = node.pFirst;
		while (tmp != nullptr)
		{
			out << "Key = " << tmp->key << endl;
			tmp = tmp->pNext;
		}
		return out;
	}

	friend class Polinom;
};

template<class TKey, class TData>
TList<TKey, TData> ::TList()
{
	pFirst = nullptr;
	pCurrent = nullptr;
	pPrevious = nullptr;
	pNext = nullptr;
}

template<class TKey, class TData>
TList<TKey, TData> ::TList(const TNode<TKey, TData>* first)
{
	pPrevious = nullptr;
	pNext = nullptr;
	pCurrent = nullptr;
	if (first == nullptr)
		pFirst == nullptr;
	else
	{
		TNode<TKey, TData>* node = new TNode<TKey, TData>(*first);
		pFirst = node;
		TNode<TKey, TData>* prev = pFirst;
		TNode<TKey, TData>* it = first->pNext;
		while (it)
		{
			TNode<TKey, TData>* tmp = new TNode<TKey, TData>(*it);
			prev->pNext = it;
			prev = tmp;
			it = it->pNext;
		}
		prev->pNext = nullptr;
		pCurrent = pFirst;
		pNext = pCurrent->pNext;
	}
}

template<class TKey, class TData>
TList<TKey, TData> ::TList(const TList& list)
{
	if (list.pFirst == nullptr)
	{
		pFirst = nullptr;
		pCurrent = nullptr;
		pPrevious = nullptr;
		pNext = nullptr;
	}
	else
	{
		pFirst = new TNode<TKey, TData>(*list.pFirst);
		pPrevious = nullptr;
		pCurrent = pFirst;
		pNext = pFirst->pNext;
		TNode<TKey, TData>* tmp1(pFirst), * tmp2(list.pFirst);
		while (tmp2->pNext != nullptr)
		{
			tmp1->pNext = new TNode<TKey, TData>(*(tmp2->pNext));
			tmp2 = tmp2->pNext;
			tmp1 = tmp1->pNext;
		}
		tmp1->pNext = nullptr;
	}

}

template<class TKey, class TData>
TList<TKey, TData> ::~TList()
{
	while (pFirst != nullptr)
	{
		pNext = pFirst->pNext;
		delete pFirst;
		pFirst = pNext;
	}
	pCurrent = nullptr;
	pPrevious = nullptr;
	pNext = nullptr;
}

template<class TKey, class TData>
void TList<TKey, TData> ::Sort()
{
	if (pFirst == nullptr)
		return;
	if (pFirst->pNext == nullptr)
		return;
	TNode<TKey, TData>* a, * b, * p, * h = NULL;
	for (TNode<TKey, TData>* i = pFirst; i != NULL; )
	{
		a = i;
		i = i->pNext;
		b = h;
		for (p = NULL; (b != NULL) && (a->key < b->key); ) {
			p = b;
			b = b->pNext;
		}

		if (p == NULL) {
			a->pNext = h;
			h = a;
		}
		else {
			a->pNext = b;
			p->pNext = a;
		}
	}
	if (h != NULL)
		pFirst = h;
	Reset();
}

template<class TKey, class TData>
void TList<TKey, TData>::BringingSimilar()
{
	Reset();
	TNode<TKey, TData>* tmp = pNext;
	while (!IsEnded())
	{
		while (tmp->pNext->key != pCurrent->key)
		{
			if (pCurrent == tmp->pNext)
			{
				Next();
				continue;
			}
			pCurrent->pData += tmp->pNext->pData;
			TNode<TKey, TData>* node = tmp->pNext;
			tmp->pNext = tmp->pNext->pNext;
			delete node;
			Next();
		}
	}
}


template<class TKey, class TData>
TNode<TKey, TData>* TList<TKey, TData> ::Search(TKey key)
{
	if (pFirst == nullptr)
		throw M_Exeption("list is empty");
	TNode<TKey, TData>* tmp = pFirst;
	while ((tmp != nullptr) && (tmp->key != key))
		tmp = tmp->pNext;
	if (tmp == nullptr)
		cout << "there is no such key";
	return tmp;
}

template<class TKey, class TData>
void TList<TKey, TData> ::InsertBegin(TKey NewKey, TData NewData)
{
	TNode<TKey, TData>* tmp = new TNode<TKey, TData>(NewKey, NewData, pFirst);
	if (pCurrent == pFirst)
		pPrevious = tmp;
	pFirst = tmp;
	return;
}

template<class TKey, class TData>
void TList<TKey, TData> ::InsertBegin(TNode<TKey, TData>* node)
{
	InsertBegin(node->key, node->pData);
}

template<class TKey, class TData>
void TList<TKey, TData> ::InsertEnd(TKey NewKey, TData NewData)
{
	if (pFirst == nullptr)
	{
		InsertBegin(NewKey, NewData);
		Reset();
		return;
	}
	TNode<TKey, TData>* tmp = pFirst;
	while (tmp->pNext != 0)
		tmp = tmp->pNext;
	tmp->pNext = new TNode<TKey, TData>(NewKey, NewData);
	if (pCurrent == tmp)
		pNext = tmp->pNext;
	tmp->pNext->pNext = nullptr;
	return;
}

template<class TKey, class TData>
void TList<TKey, TData> ::InsertEnd(TNode<TKey, TData>* node)
{
	InsertEnd(node->key, node->pData);
}

template<class TKey, class TData>
void TList<TKey, TData> ::InsertAfter(TKey SearchKey, TNode<TKey, TData>* node)
{
	if (pFirst == nullptr)
		throw M_Exeption("list is empty");
	TNode<TKey, TData>* tmp = pFirst;
	while (tmp != nullptr && tmp->key != SearchKey)
		tmp = tmp->pNext;
	if (tmp == nullptr)
	{
		cout << "there is no such key" << endl;
		return;
	}
	TNode<TKey, TData>* NewNode = new TNode<TKey, TData>(node->key, node->pData, tmp->pNext);
	if (pCurrent == tmp)
		pNext = NewNode;
	if (pCurrent == tmp->pNext)
		pPrevious = NewNode;
	tmp->pNext = NewNode;
	return;
}

template<class TKey, class TData>
void TList<TKey, TData> ::InsertBefore(TKey SearchKey, TNode<TKey, TData>* node)
{
	if (pFirst == nullptr)
		throw M_Exeption("list is empty");
	if (pFirst->key == SearchKey)
	{
		InsertBegin(node->key, node->pData);
		return;
	}
	TNode<TKey, TData>* tmp = pFirst;
	while (tmp != nullptr && tmp->pNext->key != SearchKey)
		tmp = tmp->pNext;
	if (tmp == nullptr)
	{
		cout << "there is no such key" << endl;
		return;
	}
	TNode<TKey, TData>* NewNode = new TNode<TKey, TData>(node->key, node->pData, tmp->pNext);
	if (pCurrent == tmp->pNext)
		pPrevious = NewNode;
	if (pCurrent == tmp)
		pNext = NewNode;
	tmp->pNext = NewNode;
}

template<class TKey, class TData>
void TList<TKey, TData> ::Remove(TKey SearchKey)
{
	if (pFirst == nullptr)
		throw M_Exeption("list is empty");
	if (pFirst->key == SearchKey)
	{
		TNode<TKey, TData>* tmp = pFirst;
		pFirst = pFirst->pNext;
		if (pCurrent == pFirst)
			pPrevious = nullptr;
		delete tmp;
		Reset();
		return;
	}
	TNode<TKey, TData>* tmp = pFirst;
	while (tmp != nullptr && tmp->pNext->key != SearchKey)
		tmp = tmp->pNext;
	if (tmp == nullptr)
	{
		cout << "there is no such key for remove" << endl;
		return;
	}
	TNode<TKey, TData>* node = tmp->pNext;
	tmp->pNext = tmp->pNext->pNext;
	if (pCurrent == node)
		Reset();
	if (pCurrent == tmp)
		pNext = tmp->pNext;
	if (pCurrent == tmp->pNext)
		pPrevious = tmp;
	delete node;
}

template<class TKey, class TData>
bool TList<TKey, TData> ::IsEmpty()const
{
	return(pFirst == nullptr);
}

template<class TKey, class TData>
bool TList<TKey, TData> ::IsEnded()const
{
	return(pCurrent == nullptr);
}

template<class TKey, class TData>
void TList<TKey, TData> ::Reset()
{
	if (pFirst == nullptr)
		return;
	pCurrent = pFirst;
	pPrevious = nullptr;
	pNext = pCurrent->pNext;
}

template<class TKey, class TData>
void TList<TKey, TData> ::Next()
{
	if (IsEnded())
		throw M_Exeption("end of list");
	pPrevious = pCurrent;
	pCurrent = pNext;
	if (pNext != nullptr)
		pNext = pNext->pNext;
}

template<class TKey, class TData>
TNode<TKey, TData>* TList<TKey, TData> ::GetFirst()const
{
	return pFirst;
}

template<class TKey, class TData>
TNode<TKey, TData>* TList<TKey, TData> ::GetCurrent()const
{
	return pCurrent;
}

template<class TKey, class TData>
TNode<TKey, TData>* TList<TKey, TData> ::GetNext()const
{
	return pNext;
}

template<class TKey, class TData>
TNode<TKey, TData>* TList<TKey, TData> ::GetPrev()const
{
	return  pPrevious;
}

#endif 
