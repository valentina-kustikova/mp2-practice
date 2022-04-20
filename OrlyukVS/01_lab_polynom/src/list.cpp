//#include "list.h"

////звено
//template<typename TData>
//TNode<TData>::TNode(const TNode& copy)
//{
//	this->data = copy.data;
//	this->pNext = nullptr;
//}
//
//template<typename TData>
//TNode<TData>::TNode()
//{
//	pNext = nullptr;
//}
//
//template<typename TData>
//TNode<TData>::TNode(TData data1, TNode<TData>* pNext1 = nullptr)
//{
//	data = data1;
//	pNext = pNext1;
//}
//
//template<typename TData>
//bool TNode<TData>::operator==(const TNode<TData>& n) const
//{
//	return (data == n.data && pNext ==n.data);
//}
//
//
//template<typename TData>
//bool TNode<TData>::operator!=(const TNode<TData>& n)const
//{
//	return !(*this == n);
//}
//
//
////список
//template<typename TData>
//TList<TData>::TList()
//{
//	pFirst = pLast = pCurr = pPrev = nullptr;
//	length = 0;
//}
//
//template<typename TData>
//TList<TData>::~TList()
//{
//	while (pFirst != nullptr)
//	{
//		TNode<T>* temp = pFirst;
//		pFirst = pFirst->pNext;
//		delete tmp;
//	}
//}
//
//template<typename TData>
//TNode<TData>* TList<TData>::Search(TData* const data1)
//{
//	TNode<TData>* node = pFirst;
//	while (node && node->data != data1) node = node->pNext;
//	return (node && node->data == data1) ? node : nullptr;
//}
//
//template<typename TData>
//void TList<TData>::InsertToHead(const TData& data1)
//{
//	TNode<TData>* node = new TNode<TData>(data1);
//	node->pNext = pFirst;
//	pFirst = node;
//	length++;
//	if (length == 1)
//	{
//		pLast = pFirst;
//	}
//}
//
//template<typename TData>
//void TList<TData>::InsertToTail(const TData& data1)
//{
//	TNode<TData>* node = new TNode<TData>(data1);
//	if (IsEmpty())
//	{
//		pFirst = node;
//		pLast = node;
//		length++;
//	}
//	pLast->pNext = node;
//	pLast = node;
//}
//
//template<typename TData>
//void TList<TData>::Insert(TData data1)
//{
//	if (pCurr == pFirst)
//	{
//		InsertToHead(data1);
//		pPrev = pFirst;
//	}
//	else if (pCurr == pLast)
//	{
//		InsertToTail(data1);
//		pPrev = pLast;
//	}
//	else
//	{
//		TNode<TData>* node = new TNode<TData>(data1);
//		node->pNext = pCurr;
//		pPrev->pNext = node;
//		pCurr = node;
//		length++;
//	}
//}
//
//template<typename TData>
//void TList<TData>::RemoveFirst()
//{
//	setlocale(LC_ALL, "Russian");
//	if (IsEmpty())
//		throw("Список пуст");
//	else
//	TNode<TData>* node = pFirst;
//	pFirst = node->pNext;
//	delete node;
//	length--;
//}
//
//template<typename TData>
//void TList<TData>::RemoveLast()
//{
//	if(IsEmpty())
//		throw("Список пуст");
//	if (pFisrt == pLast)
//	{
//		RemoveFirst();
//	}
//	TNode<TData>* node = pFirst;
//	while (node->pNext != pLast) node = node->pNext;
//	node->pNext = nullptr;
//	delete pLast;
//	pLast = node;
//	length--;
//}
//
//template<typename TData>
//void TList<TData>::Remove(TNode<TData>* pFirst, TNode<TData>* pLast)
//{
//	if (IsEmpty())
//		throw("Список пуст");
//	if (pCurr == pFirst)
//	{
//		RemoveFirst();
//		pPrev = nullptr;
//		pCurr = pFirst;
//	}
//	else if (pCurr == pLast)
//	{
//		RemoveLast();
//		pCurr = pLast;
//	}
//	else
//	{
//		TNode<TData>* node = pCurr;
//		pCurr = pCurr->pNext;
//		pPrev->pNext = pCurr;
//		delete node;
//		length--;
//	}
//}
//
//template<typename TData>
//void TList<TData>::Next()
//{
//	pCurr = pCurr->pNext;
//}
//
//template<typename TData>
//void TList<TData>::Reset()
//{
//	pPrev = nullptr;
//	pCurr = pFirst;
//}
//
//template<typename TData>
//bool TList<TData>::IsEnded() const
//{
//	return (pCurr == pLast);
//}
//
//template<typename TData>
//bool TList<TData>::IsEmpty() const
//{
//	return (pFirst == nullptr);
//}
//
//template<typename TData>
//bool TList<TData>::operator==(const TList<TData>& list) const
//{
//	return false;
//}
//
//template<typename TData>
//bool TList<TData>::operator!=(const TList<TData>& list) const
//{
//	return false;
//}
//
//template<typename TData>
//TNode<TData>* TList<TData>::GetCur() const
//{
//	if (pCurr = nullptr)
//		throw("Нельзя получить значение");
//	else
//		return (pCurr->data);
//}
//
//
//
//
