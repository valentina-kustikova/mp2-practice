#pragma once
#include<iostream>
#include"Node.h"
using namespace std;
template<class TKey, class TData>
class TList
{
private: // 
	TNode<TKey, TData> *pFirst;
	TNode<TKey, TData> *pPrev;
	TNode<TKey, TData> *pNext;
	TNode<TKey, TData> *pCur;
public:
	TList();
	TList(const TList<TKey, TData>&);
	TList(const TNode<TKey, TData>*);
	~TList();
	TNode<TKey, TData>* Search(TKey);
	void InsertStart(TKey, TData*);
	void InsertEnd(TKey, TData*);
	void InsertBefore(TKey, TKey, TData*);
	void InsertAfter(TKey, TKey, TData*);
	void Delete(TKey);
	void Reset();
	bool IsEnded()const;
	void Next();
	TKey Get_pFirst_key();
	TKey Get_pCur_key();
	TData Get_pCur_data();
	friend ostream& operator <<(ostream& o, TList<TKey, TData> &list)
	{
		if (list.pFirst == nullptr)
		{
			throw "Empty list";
		}
		TNode<TKey, TData>* tmp0 = list.pCur;
		TNode<TKey, TData>* tmp1 = list.pPrev;
		TNode<TKey, TData>* tmp2 = list.pNext;
		list.Reset();
		while (list.pCur != nullptr)
		{
			o << list.pCur->key << " " << *list.pCur->pData << endl;
			list.Next();
		}
		list.pCur = tmp0;
		list.pPrev = tmp1;
		list.pNext = tmp2;
		return o;
	}
};

template<class TKey, class TData>
TList<TKey, TData >::TList()
{
	pFirst = nullptr;
	pPrev = nullptr;
	pCur = nullptr;
	pNext = nullptr;
}
template<class TKey, class TData>
TList<TKey, TData>::TList(const TList<TKey, TData>& list)
{
	if (list.pFirst == nullptr)
		throw "empty list";
	pFirst = new TNode<TKey, TData>(*list.pFirst);
	TNode<TKey, TData>* node = list.pFirst->pNext;
	TNode<TKey, TData>* copy = pFirst;
	while (node != nullptr)
	{
		TNode<TKey, TData>* tmp = new TNode<TKey, TData>(node->key, node->pData);//
		copy->pNext = tmp;
		copy = tmp;
		node = node->pNext;
	}
	Reset();
}
template<class TKey, class TData>
TList<TKey, TData>::TList(const TNode<TKey, TData>* node)
{
	if (node == nullptr)
		throw"empty node";
	pFirst = new TNode<TKey, TData>(*node);
	TNode<TKey, TData>* _node = node->pNext;
	TNode<TKey, TData>* copy = pFirst;
	while (_node != nullptr)
	{
		TNode<TKey, TData>* tmp = new TNode<TKey, TData>(_node->key, _node->pData);//
		copy->pNext = tmp;
		copy = tmp;
		_node = _node->pNext;
	}
	Reset();
}
template<class TKey, class TData>
TList<TKey, TData>::~TList()
{
	while (!IsEnded())
	{
		Next();
		delete[] pPrev;
	}
	delete[] pCur;
}
template<class TKey, class TData>
void TList<TKey, TData>::Reset()
{
	pPrev = nullptr;
	pCur = pFirst;
	if (pFirst != nullptr)
		pNext = pCur->pNext;
	else
		pNext = nullptr;
}
template<class TKey, class TData>
bool TList<TKey, TData>::IsEnded() const
{
	return(pCur == nullptr);
}
template<class TKey, class TData>
void TList<TKey, TData>::Next()
{
	if (IsEnded())
		throw"cant complete Next";
	pPrev = pCur;
	pCur = pNext;
	if (pNext != nullptr)
		pNext = pNext->pNext;
}
template<class TKey, class TData>
typename TNode<TKey, TData>* TList<TKey, TData>::Search(TKey key)
{
	if (pFirst == nullptr)
		throw "empty list";
	TNode<TKey, TData>* tmp0 = pCur;
	TNode<TKey, TData>* tmp1 = pPrev;
	TNode<TKey, TData>* tmp2 = pNext;
	Reset();
	while (!IsEnded() && (pCur->key != key))
		Next();
	if (pCur == nullptr)
		throw "node is not found";
	TNode<TKey, TData>* tmp = pCur;
	pCur = tmp0;
	pPrev = tmp1;
	pNext = tmp2;
	return tmp;
}
template<class TKey, class TData>
void TList<TKey, TData>::InsertStart(TKey key, TData* data)
{
	if (pFirst == nullptr)
	{
		TNode<TKey, TData>* tmp = new TNode<TKey, TData>(key, data);
		pFirst = tmp;
		pCur = pFirst;
		return;
	}
	TNode<TKey, TData>* tmp = new TNode<TKey, TData>(key, data, pFirst);//
	pFirst = tmp;
	if (pCur == pFirst->pNext)
		pPrev = pFirst;
}
template<class TKey, class TData>
void TList<TKey, TData>::InsertEnd(TKey key, TData* data)
{
	if (pFirst == nullptr)
	{
		InsertStart(key, data);//
	}
	TNode<TKey, TData>* tmp0 = pCur;
	TNode<TKey, TData>* tmp1 = pPrev;
	TNode<TKey, TData>* tmp2 = pNext;
	while (!IsEnded())
		Next();
	TNode<TKey, TData>* tmp = new TNode<TKey, TData>(key, data);
	pPrev->pNext = tmp;
	if (tmp0 == pPrev)
	{
		pNext = pPrev->pNext;
		pCur = tmp0;
		pPrev = tmp1;
	}
}
template<class TKey, class TData>
void TList<TKey, TData>::InsertBefore(TKey key, TKey newkey, TData* data)
{
	if (pFirst == nullptr)
		throw "can`t insert in empty list";//
	TNode<TKey, TData>* tmp0 = pCur;
	TNode<TKey, TData>* tmp1 = pPrev;
	TNode<TKey, TData>* tmp2 = pNext;
	Reset();
	while (!IsEnded() && (pCur->key != key))
		Next();
	if (pCur == nullptr)
		throw "key is not found";
	TNode<TKey, TData>* tmp = new TNode<TKey, TData>(newkey, data, pCur);
	pPrev->pNext = tmp;
	if (pCur == tmp0)
	{
		pPrev = pPrev->pNext;
		pNext = tmp2;
	}
	else if (pPrev == tmp0)
	{
		pNext = pPrev->pNext;
		pCur = tmp0;
		pPrev = tmp1;
	}
	else
	{
		pCur = tmp0;
		pPrev = tmp1;
		pNext = tmp2;
	}
}
template<class TKey, class TData>
void TList<TKey, TData>::InsertAfter(TKey key, TKey newkey, TData* data)
{
	if (pFirst == nullptr)
		throw "can`t insert in empty list";//
	TNode<TKey, TData>* tmp0 = pCur;
	TNode<TKey, TData>* tmp1 = pPrev;
	TNode<TKey, TData>* tmp2 = pNext;
	Reset();
	while (!IsEnded() && (pCur->key != key))
		Next();
	if (pCur == nullptr)
		throw "key is not found";
	TNode<TKey, TData>* tmp = new TNode<TKey, TData>(newkey, data, pNext);
	pCur->pNext = tmp;
	if (pCur == tmp0)
	{
		pNext = pCur->pNext;
		pPrev = tmp1;
	}
	else if (pNext == tmp0)
	{
		pPrev = pCur->pNext;
		pCur = tmp0;
		pNext = tmp2;
	}
	else
	{
		pCur = tmp0;
		pPrev = tmp1;
		pNext = tmp2;
	}
}
template<class TKey, class TData>
void TList<TKey, TData>::Delete(TKey key)
{
	if (pFirst == nullptr) throw"can`t delete element in empty stack";
	if (pFirst->key == key)
	{
		TNode<TKey, TData> * copy_next = pFirst->pNext;
		if (pCur == pFirst)
			pCur = nullptr;
		if (pPrev == pFirst)
			pPrev = nullptr;
		delete pFirst;
		pFirst = copy_next;
		return;
	}
	TNode<TKey, TData> * copy_prev = pFirst;
	while ((copy_prev->pNext != nullptr) && (copy_prev->pNext->key != key)) ///
	{
		copy_prev = copy_prev->pNext;
	}
	if (copy_prev->pNext == nullptr) throw "can`t delete because key is not found";
	TNode<TKey, TData> * copy_next1 = copy_prev->pNext->pNext;
	if (pCur == copy_prev->pNext) pCur = nullptr;
	if (pPrev == copy_prev->pNext) pPrev = copy_prev;
	if (pNext == copy_prev->pNext) pNext = copy_next1;
	delete copy_prev->pNext;
	copy_prev->pNext = copy_next1;
}
template<class TKey, class TData>
TKey TList<TKey, TData>::Get_pFirst_key()
{
	return pFirst->key;
}
template<class TKey, class TData>
TKey TList<TKey, TData>::Get_pCur_key()
{
	return pCur->key;
}
template<class TKey, class TData>
TData TList<TKey, TData>::Get_pCur_data()
{
	return *pCur->pData;
}
