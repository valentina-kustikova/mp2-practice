#pragma once
#include <iostream>

template <typename TData>
class TNode
{
public: 
	TData data;
	TNode<TData>* pNext;
	TNode();
	TNode(TData data1, TNode<TData>* pNext1 = nullptr);
	TNode(TNode& copy);
	bool operator = (const TNode<TData>& n)const;
	bool operator == (const TNode<TData>& n)const;
	bool operator != (const TNode<TData>& n)const;
};

template <typename TData>
class TList
{
protected:
	TNode<TData>* pFirst;
	TNode<TData>* pLast;
	TNode<TData>* pCurr;
	TNode<TData>* pPrev;
	TNode<TData>* pStop;
	int length;

public:
	//Конструкторы
	TList();
    ~TList();
	//Операции над списком
	TNode<TData>* Search(TData& const data1);
	 void InsertToHead(const TData& data1);
	 void InsertToTail(const TData& data1);
	 void Insert(const TData& data1);
	 void RemoveFirst();
	 void RemoveLast();
	 void Remove(TNode<TData>* node);
	 void Remove(TNode<TData>* pFirst, TNode<TData>* pLast);
	//Навигация
	 void Next();
	 void Reset();//переход в начало списка
	 bool IsEnded() const;
	 bool IsEmpty() const;
	 TList<TData>& operator=(const TList<TData>& list);
	bool operator==(const TList<TData>& list) const;
	 bool operator!=(const TList<TData>& list) const;
	TNode<TData>* GetCur() const;
};

//звено

template<typename TData>
TNode<TData>::TNode()
{
	pNext = nullptr;
}

template<typename TData>
TNode<TData>::TNode(TNode& copy)
{
	data = copy.data;
	pNext = nullptr;
}

template<typename TData>
TNode<TData>::TNode(TData data1, TNode<TData>* pNext1 = nullptr)
{
	data = data1;
	pNext = pNext1;
}

template<typename TData>
inline bool TNode<TData>::operator=(const TNode<TData>& n) const
{
	return (data = n.data && pNext = n.pNext);
}

template<typename TData>
bool TNode<TData>::operator==(const TNode<TData>& n) const
{
	return (data == n.data && pNext == n.data);
}

template<typename TData>
bool TNode<TData>::operator!=(const TNode<TData>& n)const
{
	return !(*this == n);
}


//список
template<typename TData>
TList<TData>::TList()
{
	pFirst = pLast = pStop = nullptr;
	length = 0;
	Reset();
}

template<typename TData>
TList<TData>::~TList()
{
	while (pFirst != pStop)
	{
		TNode<TData>* node = pFirst;
		pFirst = pFirst->pNext;
		delete node;
	}
}

template<typename TData>
inline void TList<TData>::InsertToHead(const TData& data1)
{
	TNode<TData>* node = new TNode<TData>(data1);
	pFirst = node;
	if (node == nullptr)
		throw std::exception("Error: List is empty");
	else
	{
		pFirst = node;
		length++;
		if (length == 1)
		{
			pLast = node;
			Reset();
		}
	}
}

template<typename TData>
void TList<TData>::InsertToTail(const TData& data1)
{
	TNode<TData>* node = new TNode<TData>(data1);
	if (node == pStop)
		throw std::exception("Error: List is end");
	else
	{
		if (pLast != pStop)
			pLast = node;
		length++;
		if (length == 1)
		{
			pFirst = node;
			Reset();
		}
	}
}

template<typename TData>
void TList<TData>::Insert(const TData& data1)
{
	if (IsEmpty() || pCurr == pFirst)
		InsertToHead(data1);
	else if (IsEnded())
		InsertToTail(data1);
	else if (pPrev == pStop)
		throw std::exception("Error: List is empty");
	else
	{
		TNode<TData>* node = new TNode<TData>(data1);
		pCurr = node;
		if (node == pStop)
			throw std::exception("Error: List is empty");
		else
		{
			pCurr = node;
			length++;
		}
	}
}

template<typename TData>
void TList<TData>::RemoveFirst()
{
	TNode<TData>* node = pFirst;
	if (IsEmpty())
	throw std::exception("Error: List is empty");
	else
		pFirst = node->pNext;
		delete node;
		length--;
}

template<typename TData>
void TList<TData>::RemoveLast()
{
	if (IsEmpty())
		throw std::exception("Error: List is empty");
	if (pFirst == pLast)
	{
		RemoveFirst();
	}
	else
	{
		TNode<TData>* node = pFirst;
		while (node->pNext != pLast) node = node->pNext;
		node->pNext = pStop;
		delete pLast;
		pLast = node;
		length--;
	}
}

template<typename TData>
inline void TList<TData>::Remove(TNode<TData>* node)
{
	TNode<TData>* n;
	while (pCurr->pNext != node)
	{
		Next();
	}
	pCurr->pNext = node->pNext;
	delete node;
	length--;
}

template<typename TData>
void TList<TData>::Remove(TNode<TData>* pFirst, TNode<TData>* pLast)
{
	if (IsEmpty())
		throw std::exception("Error: List is empty");
	if (pCurr == pFirst)
	{
		RemoveFirst();
		pPrev = pStop;
		pCurr = pFirst;
	}
	else if (pCurr == pLast)
	{
		RemoveLast();
		pCurr = pLast;
	}
	else
	{
		TNode<TData>* node = pCurr;
		pCurr = pCurr->pNext;
		pPrev->pNext = pCurr;
		delete node;
		length--;
	}
}

template<typename TData>
TNode<TData>* TList<TData>::Search(TData& const data1)
{
	TNode<TData>* node = pFirst;
	while (node && node->data != data1) node = node->pNext;
	return (node && node->data == data1) ? node : nullptr;
}

template<typename TData>
bool TList<TData>::IsEmpty() const
{
	return (pFirst == pStop);
}

template<typename TData>
inline TList<TData>& TList<TData>::operator=(const TList<TData>& list)
{
	TNode<TData>* node1 = list.pCurr;
	TNode<TData>* node2 = pCurr;
	while (node1->pNext != list.pCurr)
	{
		node1 = node1->pNext;
		node2->pNext = new TNode<TData>(node1->data);
		node2 = node2->pNext;
	}
	node2->pNext = pCurr;
	node1 = pCurr;
	return *this;
}

template<typename TData>
inline bool TList<TData>::operator==(const TList<TData>& list) const
{
	bool f = true;
	if (this != &list)
	{
		TNode<TData>* node1 = pCurr;
		TNode<TData>* node2 = list.pCurr;
		while (node1->data == node2->data)
		{
			node1 = node1->pNext;
			node2 = node2->pNext;
		}
		if (node1 != pCurr || node2 != list.pCurr)
		{
			return false;
		}
	}
	return f;
}

template<typename TData>
inline bool TList<TData>::operator!=(const TList<TData>& list) const
{
	return !(*this == list);
}

template<typename TData>
inline TNode<TData>* TList<TData>::GetCur() const
{
	if (pCurr == pStop)
		throw std::exception("Error: Node is not");
	else
		return pCurr;
}

template<typename TData>
void TList<TData>::Reset()
{
	pPrev = pStop;
	if (IsEmpty())
	{
		pCurr = pStop;
	}
	else
	{
		pCurr = pFirst;
	}
}

template<typename TData>
void TList<TData>::Next()
{
	if (pCurr == pStop)
		throw std::exception("Error: List is empty");
	else
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}
}

template<typename TData>
bool TList<TData>::IsEnded() const
{
	return (pCurr == pStop);
}
