#pragma once
#include"Monom.h"
template<class TKey, class TData, class TTipe>
class TList
{
private:  
	TTipe *pFirst;
	TTipe *pPrev;
	TTipe *pNext;
	TTipe *pCur;
public:
	TList();
	TList(const TList<TKey, TData, TTipe>&);
	TList(const TTipe*);
	~TList();
	TTipe* Search(TKey);
	void InsertStart(TKey, TData);
	void InsertEnd(TKey, TData);
	void InsertBefore(TKey, TKey, TData);
	void InsertAfter(TKey, TKey, TData);
	void Delete(TKey);
	void Reset();
	bool IsEnded()const;
	void Next();
	TKey Get_pFirst_key() const;
	TKey Get_pCur_key() const;
	TData Get_pCur_data() const;
	TTipe* GetpCur() const;
	friend ostream& operator <<(ostream& o, TList<TKey, TData, TTipe> &list) //
	{
		if (list.pFirst == nullptr)
		{
			throw "Empty list";
		}
		TTipe* tmp0 = list.pCur;
		TTipe* tmp1 = list.pPrev;
		TTipe* tmp2 = list.pNext;
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

template<class TKey, class TData, class TTipe>
TList<TKey, TData, TTipe>::TList()
{
	pFirst = nullptr;
	pPrev = nullptr;
	pCur = nullptr;
	pNext = nullptr;
}
template<class TKey, class TData, class TTipe>
TList<TKey, TData, TTipe>::TList(const TList<TKey, TData, TTipe>& list)
{
	if (list.pFirst == nullptr)
	{
		TList();
		return;
	}
	pFirst = new TTipe(*list.pFirst);
	TTipe* node = list.pFirst->pNext;
	TTipe* copy = pFirst;
	while (node != nullptr)
	{
		TTipe* tmp = new TTipe(node->key, node->pData);
		copy->pNext = tmp;
		copy = tmp;
		node = node->pNext;
	}
	Reset();
}
template<class TKey, class TData, class TTipe>
TList<TKey, TData, TTipe>::TList(const TTipe* node)
{
	if (node == nullptr)
		throw"empty node";
	pFirst = new TTipe(*node);
	TTipe* _node = node->pNext;
	TTipe* copy = pFirst;
	while (_node != nullptr)
	{
		TTipe* tmp = new TTipe(_node->key, _node->pData);
		copy->pNext = tmp;
		copy = tmp;
		_node = _node->pNext;
	}
	Reset();
}
template<class TKey, class TData, class TTipe>
TList<TKey, TData, TTipe>::~TList()
{
	TTipe* copy = pFirst;
	while (copy != 0)
	{
		TTipe* copy1 = copy->pNext;
		delete copy;
		copy = copy1;
	}
}
template<class TKey, class TData, class TTipe>
void TList<TKey, TData, TTipe>::Reset()
{
	pPrev = nullptr;
	pCur = pFirst;
	if (pFirst != nullptr)
		pNext = pCur->pNext;
	else
		pNext = nullptr;
}
template<class TKey, class TData, class TTipe>
bool TList<TKey, TData, TTipe>::IsEnded() const
{
	return(pCur == nullptr);
}
template<class TKey, class TData, class TTipe>
void TList<TKey, TData, TTipe>::Next()
{
	if (IsEnded())
		throw"cant complete Next";
	pPrev = pCur;
	pCur = pNext;
	if (pNext != nullptr)
		pNext = pNext->pNext;
}
template<class TKey, class TData, class TTipe>
TTipe* TList<TKey, TData, TTipe>::Search(TKey key)
{
	if (pFirst == nullptr)
		throw "empty list";
	TTipe* tmp0 = pCur;
	TTipe* tmp1 = pPrev;
	TTipe* tmp2 = pNext;
	Reset();
	while (!IsEnded() && (pCur->key != key))
		Next();
	if (pCur == nullptr)
		throw "node is not found";
	TTipe* tmp = pCur;
	pCur = tmp0;
	pPrev = tmp1;
	pNext = tmp2;
	return tmp;
}
template<class TKey, class TData, class TTipe>
void TList<TKey, TData, TTipe>::InsertStart(TKey key, TData data)
{
	if (pFirst == nullptr)
	{
		TTipe* tmp = new TTipe(key, data);
		pFirst = tmp;
		pCur = pFirst;
		return;
	}
	TTipe* tmp = new TTipe(key, data, pFirst);
	pFirst = tmp;
	if (pCur == pFirst->pNext)
		pPrev = pFirst;
}
template<class TKey, class TData, class TTipe>
void TList<TKey, TData, TTipe>::InsertEnd(TKey key, TData data)
{
	if (pFirst == nullptr)
	{
		InsertStart(key, data);
		return;
	}
	TTipe* tmp0 = pCur;
	TTipe* tmp1 = pPrev;
	TTipe* tmp2 = pNext;
	Reset();
	while (!IsEnded())
		Next();
	TTipe* tmp = new TTipe(key, data);
	pPrev->pNext = tmp;
	if (tmp0 == pPrev)
	{
		pNext = pPrev->pNext;
		pCur = tmp0;
		pPrev = tmp1;
	}
	else
		if (tmp0 == nullptr)
	{
		pCur = tmp0;
		pPrev = pPrev->pNext;
		pNext = tmp2;
	}
		else
		{
			pCur = tmp0;
			pPrev = tmp1;
			pNext = tmp2;
		}
}
template<class TKey, class TData, class TTipe>
void TList<TKey, TData, TTipe>::InsertBefore(TKey key, TKey newkey, TData data)
{
	if (pFirst == nullptr)
		throw "can`t insert in empty list";//
	TTipe* tmp0 = pCur;
	TTipe* tmp1 = pPrev;
	TTipe* tmp2 = pNext;
	Reset();
	while (!IsEnded() && (pCur->key != key))
		Next();
	if (pCur == nullptr)
		throw "key is not found";
	TTipe* tmp = new TTipe(newkey, data, pPrev);
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
template<class TKey, class TData, class TTipe>
void TList<TKey, TData, TTipe>::InsertAfter(TKey key, TKey newkey, TData data)
{
	if (pFirst == nullptr)
		throw "can`t insert in empty list";//
	TTipe* tmp0 = pCur;
	TTipe* tmp1 = pPrev;
	TTipe* tmp2 = pNext;
	Reset();
	while (!IsEnded() && (pCur->key != key))
		Next();
	if (pCur == nullptr)
		throw "key is not found";
	TTipe* tmp = new TTipe(newkey, data, pNext);
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
template<class TKey, class TData, class TTipe>
void TList<TKey, TData, TTipe>::Delete(TKey key)
{
	if (pFirst == nullptr) throw"can`t delete element in empty stack";
	if (pFirst->key == key)
	{
		TTipe* copy_next = pFirst->pNext;
		if (pCur == pFirst)
			pCur = nullptr;
		if (pPrev == pFirst)
			pPrev = nullptr;
		delete pFirst;
		pFirst = copy_next;
		return;
	}
	TTipe* copy_prev = pFirst;
	while ((copy_prev->pNext != nullptr) && (copy_prev->pNext->key != key)) 
	{
		copy_prev = copy_prev->pNext;
	}
	if (copy_prev->pNext == nullptr) throw "can`t delete because key is not found";
	TTipe* copy_next1 = copy_prev->pNext->pNext;
	if (pCur == copy_prev->pNext) pCur = nullptr;
	if (pPrev == copy_prev->pNext) pPrev = copy_prev;
	if (pNext == copy_prev->pNext) pNext = copy_next1;
	delete copy_prev->pNext;
	copy_prev->pNext = copy_next1;
}
template<class TKey, class TData, class TTipe>
TKey TList<TKey, TData, TTipe>::Get_pFirst_key() const
{
	return pFirst->key;
}
template<class TKey, class TData, class TTipe>
TKey TList<TKey, TData, TTipe>::Get_pCur_key() const
{
	return pCur->key;
}
template<class TKey, class TData, class TTipe>
TData TList<TKey, TData, TTipe>::Get_pCur_data() const
{
	return *pCur->pData;
}
template<class TKey, class TData, class TTipe>
TTipe* TList<TKey, TData, TTipe>::GetpCur() const
{
	return pCur;
}
