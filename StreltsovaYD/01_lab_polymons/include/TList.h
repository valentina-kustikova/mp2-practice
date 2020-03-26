#pragma once
#ifndef _TLIST_H_
#define _TLIST_H_
#include <iostream>
#include "Monom.h"

using namespace std;

template <typename TKey, typename TData>
class TList
{
private:
	TNode<TKey, TData>* pFirst;
	TNode<TKey, TData>* pPrev;
	TNode<TKey, TData>* pCurr;
	TNode<TKey, TData>* pNext;
public:
	TList();
	TList(TNode<TKey, TData>* a);
	TList(const TList<TKey, TData>& a);
	~TList();

	bool IsEnded() const;
	void Next();
	void Reset();

	TNode<TKey, TData>* Search(TKey _key);
	void PushFront(TKey _key, TData* _data);
	void PushFront(const TNode<TKey, TData>& a);
	void PushBack(TKey _key, TData* _data);
	void PushBack(const TNode<TKey, TData>& a);
	void InsertBefore(TKey search_key, TKey ins_key, TData* _data);
	void InsertBefore(TKey search_key, const TNode<TKey, TData>& a);
	void InsertAfter(TKey search_key, TKey ins_key, TData* _data);
	void InsertAfter(TKey search_key, const TNode<TKey, TData>& a);
	void Remove(TKey _key);

	TKey GetCurrKey() const;
	TData GetCurrData() const;
	TNode<TKey, TData>* GetCurrpNext() const;

	friend ostream& operator<<(ostream& out, TList<TKey, TData>& a)
	{
		TNode<TKey, TData>* curr = a.pCurr;
		TNode<TKey, TData>* prev = a.pPrev;
		TNode<TKey, TData>* next = a.pNext;
		a.Reset();
		while (!a.IsEnded())
		{
			out << a.pCurr->key << " - " << a.pCurr->Data[0] << endl;
			a.Next();
		}
		out << endl;
		a.pCurr = curr;
		a.pPrev = prev;
		a.pNext = next;
		return out;
	}
};

template <typename TKey, typename TData>
TList<TKey, TData>::TList()
{
	pFirst = NULL;
	pPrev = NULL;
	pCurr = NULL;
	pNext = NULL;
};
template <>
TList<unsigned int, double>::TList()
{
	pFirst = NULL;
	pPrev = NULL;
	pCurr = NULL;
	pNext = NULL;
};
template <typename TKey, typename TData>
TList<TKey, TData>::TList(TNode<TKey, TData>* a)
{
	pPrev = NULL;
	pCurr = NULL;
	pNext = NULL;
	if (a == NULL)
		pFirst = NULL;
	else
	{
		pFirst = new TNode<TKey, TData>(*a);
		pCurr = pFirst;
		TNode<TKey, TData>* tmp = a->pNext;
		while (tmp != NULL)
		{
			pCurr->pNext = new TNode<TKey, TData>(*tmp);
			pCurr = pCurr->pNext;
			tmp = tmp->pNext;
		}
		Reset();
	}
};
template <typename TKey, typename TData>
TList<TKey, TData>::TList(const TList<TKey, TData>& a)
{
	pPrev = NULL;
	pCurr = NULL;
	pNext = NULL;
	if (a.pFirst == NULL)
		pFirst = NULL;
	else
	{
		pFirst = new TNode<TKey, TData>(*(a.pFirst));
		pCurr = pFirst;
		TNode<TKey, TData>* tmp = a.pFirst;
		tmp = tmp->pNext;
		while (tmp != NULL)
		{
			pCurr->pNext = new TNode<TKey, TData>(*tmp);
			pCurr = pCurr->pNext;
			tmp = tmp->pNext;
		}
		Reset();
	}
};
template <typename TKey, typename TData>
TList<TKey, TData>::~TList()
{
	TNode<TKey, TData>* tmp = pFirst, * next;
	while (tmp != nullptr)
	{
		next = tmp->pNext;
		delete tmp;
		tmp = next;
	}
};

template <typename TKey, typename TData>
bool TList<TKey, TData>::IsEnded() const
{
	return (pCurr == NULL);
};
template <typename TKey, typename TData>
void TList<TKey, TData>::Next()
{
	if (IsEnded())
		throw "Error: list is empty";
	pPrev = pCurr;
	pCurr = pNext;
	if (pNext != NULL)
		pNext = pNext->pNext;
	else pNext = NULL;
};
template <typename TKey, typename TData>
void TList<TKey, TData>::Reset()
{
	pPrev = NULL;
	pCurr = pFirst;
	if (pFirst != NULL)
		pNext = pCurr->pNext;
	else
		pNext = NULL;
};

template <typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData>::Search(TKey _key)
{
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* next = pNext;
	TNode<TKey, TData>* curr = pCurr;
	Reset();
	while ((!IsEnded()) && (pCurr->key != _key))
		Next();
	TNode<TKey, TData>* node;
	if (IsEnded())
		node = NULL;
	else node = pCurr;
	pCurr = curr;
	pPrev = prev;
	pNext = next;
	return node;
};
template <>
TNode<unsigned int, double>* TList<unsigned int, double>::Search(unsigned int _conv)
{
	Monom* prev = pPrev;
	Monom* next = pNext;
	Monom* curr = pCurr;
	Reset();
	while ((!IsEnded()) && (pCurr->conv != _conv))
		Next();
	Monom* node;
	if (IsEnded())
		node = NULL;
	else node = pCurr;
	pCurr = curr;
	pPrev = prev;
	pNext = next;
	return node;
};
template <typename TKey, typename TData>
void TList<TKey, TData>::PushFront(TKey _key, TData* _data)
{
	if (pFirst == NULL)
	{
		pFirst = new TNode<TKey, TData>(_key, _data);
		pCurr = pFirst;
		return;
	};
	TNode<TKey, TData>* tmp = new TNode<TKey, TData>(_key, _data, pFirst);
	if (pCurr == pFirst)
		pPrev = tmp;
	pFirst = tmp;
};
template <typename TKey, typename TData>
void TList<TKey, TData>::PushFront(const TNode<TKey, TData>& a)
{
	if (pFirst == NULL)
	{
		pFirst = new TNode<TKey, TData>(a);
		pCurr = pFirst;
		return;
	};
	TNode<TKey, TData>* tmp = new TNode<TKey, TData>(a);
	if (pCurr == pFirst)
		pPrev = tmp;
	pFirst = tmp;
};
template <typename TKey, typename TData>
void TList<TKey, TData>::PushBack(TKey _key, TData* _data)
{
	if (pFirst == NULL)
	{
		pFirst = new TNode<TKey, TData>(_key, _data);
		pCurr = pFirst;
		return;
	}
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* curr = pCurr;
	TNode<TKey, TData>* next = pNext;
	while (!IsEnded())
		Next();
	pCurr = new TNode<TKey, TData>(_key, _data);
	pPrev->pNext = pCurr;
	if (curr == pPrev)
		pNext = pCurr;
	else
		pNext = next;
	pPrev = prev;
	pCurr = curr;
};
template <typename TKey, typename TData>
void TList<TKey, TData>::PushBack(const TNode<TKey, TData>& a)
{
	if (pFirst == NULL)
	{
		pFirst = new TNode<TKey, TData>(a);
		pCurr = pFirst;
		return;
	}
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* curr = pCurr;
	TNode<TKey, TData>* next = pNext;
	while (!IsEnded())
		Next();
	pCurr = new TNode<TKey, TData>(a);
	pPrev->pNext = pCurr;
	if (curr == pPrev)
		pNext = pCurr;
	else
		pNext = next;
	pPrev = prev;
	pCurr = curr;
};
template <typename TKey, typename TData>
void TList<TKey, TData>::InsertBefore(TKey search_key, TKey ins_key, TData* _data)
{
	if (pFirst == NULL)
		throw "Error: list is empty";
	if (pFirst->key == search_key)
	{
		PushFront(ins_key, _data);
		return;
	}
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* next = pNext;
	TNode<TKey, TData>* curr = pCurr;
	Reset();
	TNode<TKey, TData>* tmp = Search(search_key);
	if (tmp == NULL)
		throw "Error: there is no element with this key";
	while (pCurr != tmp)
		Next();
	TNode<TKey, TData>* node = new TNode<TKey, TData>(ins_key, _data, pCurr);
	pPrev->pNext = node;
	if (curr == pPrev)
		pNext = node;
	else
		pNext = next;
	if (curr == pCurr)
		pPrev = node;
	else
		pPrev = prev;
	pCurr = curr;
};
template <typename TKey, typename TData>
void TList<TKey, TData>::InsertBefore(TKey search_key, const TNode<TKey, TData>& a)
{
	if (pFirst == NULL)
		throw "Error: list is empty";
	if (pFirst->key == search_key)
	{
		PushFront(a);
		return;
	}
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* next = pNext;
	TNode<TKey, TData>* curr = pCurr;
	Reset();
	TNode<TKey, TData>* tmp = Search(search_key);
	if (tmp == NULL)
		throw "Error: there is no element with this key";
	while (pCurr != tmp)
		Next();
	TNode<TKey, TData>* node = new TNode<TKey, TData>(a.key, a.Data, pCurr);
	pPrev->pNext = node;
	if (curr == pPrev)
		pNext = node;
	else
		pNext = next;
	if (curr == pCurr)
		pPrev = node;
	else
		pPrev = prev;
	pCurr = curr;
};
template <typename TKey, typename TData>
void TList<TKey, TData>::InsertAfter(TKey search_key, TKey ins_key, TData* _data)
{
	if (pFirst == NULL)
		throw "Error: list is empty";
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* next = pNext;
	TNode<TKey, TData>* curr = pCurr;
	Reset();
	TNode<TKey, TData>* tmp = Search(search_key);
	if (tmp == NULL)
		throw "Error: there is no element with this key";
	while (pCurr != tmp)
		Next();
	TNode<TKey, TData>* node = new TNode<TKey, TData>(ins_key, _data, pNext);
	pCurr->pNext = node;
	if (curr == pCurr)
		pNext = node;
	else
		pNext = next;
	if (curr == pNext)
		pPrev = node;
	else
		pPrev = prev;
	pCurr = curr;
};
template <typename TKey, typename TData>
void TList<TKey, TData>::InsertAfter(TKey search_key, const TNode<TKey, TData>& a)
{
	if (pFirst == NULL)
		throw "Error: list is empty";
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* next = pNext;
	TNode<TKey, TData>* curr = pCurr;
	Reset();
	TNode<TKey, TData>* tmp = Search(search_key);
	if (tmp == NULL)
		throw "Error: there is no element with this key";
	while (pCurr != tmp)
		Next();
	TNode<TKey, TData>* node = new TNode<TKey, TData>(a.key, a.Data, pNext);
	pCurr->pNext = node;
	if (curr == pCurr)
		pNext = node;
	else
		pNext = next;
	if (curr == pNext)
		pPrev = node;
	else
		pPrev = prev;
	pCurr = curr;
};
template <typename TKey, typename TData>
void TList<TKey, TData>::Remove(TKey _key)
{
	if (pFirst == NULL)
		throw "Error: list is empty";
	if (pFirst->key == _key)
	{
		if (pCurr == pFirst)
		{
			pCurr = pNext;
			if (pNext != NULL)
				pNext = pNext->pNext;
			else
				pNext = NULL;
			delete pFirst;
			pFirst = pCurr;
			return;
		}
		if (pCurr == pFirst->pNext)
		{
			pPrev = NULL;
			delete pFirst;
			pFirst = pCurr;
			return;
		}
		delete pFirst;
		return;
	}
	TNode<TKey, TData>* curr = pCurr;
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* next = pNext;
	Reset();
	TNode<TKey, TData>* tmp = Search(_key);
	if (tmp == NULL)
		throw "Error: there is no element with this key";
	while (pCurr != tmp)
		Next();
	pPrev->pNext = pNext;
	if ((curr == pCurr) || (curr == pNext))
	{
		pCurr = pNext;
		pNext = pCurr->pNext;
		delete tmp;
		return;
	}
	if (curr == pPrev)
	{
		pCurr = pPrev;
		pPrev = prev;
		pNext = pCurr->pNext;
		delete tmp;
		return;
	}
	pNext = next;
	pCurr = curr;
	delete tmp;
	return;
};
template <>
void TList<unsigned int, double>::Remove(unsigned int _conv)
{
	if (pFirst == NULL)
		throw "Error: list is empty";
	if (pFirst->conv == _conv)
	{
		if (pCurr == pFirst)
		{
			pCurr = pNext;
			if (pNext != NULL)
				pNext = pNext->pNext;
			else
				pNext = NULL;
			delete pFirst;
			pFirst = pCurr;
			return;
		}
		if (pCurr == pFirst->pNext)
		{
			pPrev = NULL;
			delete pFirst;
			pFirst = pCurr;
			return;
		}
		Monom* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		return;
	}
	Monom* curr = pCurr;
	Monom* prev = pPrev;
	Monom* next = pNext;
	Reset();
	Monom* tmp = Search(_conv);
	if (tmp == NULL)
		throw "Error: there is no element with this key";
	while (pCurr != tmp)
		Next();
	pPrev->pNext = pNext;
	if ((curr == pCurr) || (curr == pNext))
	{
		pCurr = pNext;
		if (pCurr != NULL)
			pNext = pCurr->pNext;
		else
			pNext = NULL;
		delete tmp;
		return;
	}
	if (curr == pPrev)
	{
		pCurr = pPrev;
		pPrev = prev;
		pNext = pCurr->pNext;
		delete tmp;
		return;
	}
	pNext = next;
	pCurr = curr;
	delete tmp;
	return;
};

template <typename TKey, typename TData>
TKey TList<TKey, TData>::GetCurrKey() const
{
	if (pCurr == NULL)
		throw "Error: list is empty";
	return pCurr->key;
};
template <>
unsigned int TList<unsigned int, double>::GetCurrKey() const
{
	if (pCurr == NULL)
		throw "Error: list is empty";
	return pCurr->conv;
};
template <typename TKey, typename TData>
TData TList<TKey, TData>::GetCurrData() const
{
	if (pCurr == NULL)
		throw "Error: list is empty";
	return pCurr->Data;
};
template <>
double TList<unsigned int, double>::GetCurrData() const
{
	if (pCurr == NULL)
		throw "Error: list is empty";
	return pCurr->coef;
}
template <typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData>::GetCurrpNext() const
{
	if (pCurr == NULL)
		throw "Error: list is empty";
	return pCurr->pNext;
};
#endif