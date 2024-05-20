#ifndef _TL
#define _TL

#include <iostream>
#include <string>

using namespace std;

template <typename TData>class TNode {
public:
	TData data;
	TNode* pNext;

	TNode() {
		data = TData();
		pNext = nullptr;
	}
	TNode(const TData& d, TNode* pN = nullptr) {
		data = d;
		pNext = pN;
	}
	TNode(const TNode& Node) {
		data = Node.data;
		pNext = Node.pNext;
	}
};

template <typename TData>class TList {
protected:
	TNode<TData>* pFirst;
	TNode<TData>* pLast;
	TNode<TData>* pStop;
	TNode<TData>* pPrev;
	TNode<TData>* pCurrent;
public:
	TList() {
		pFirst = nullptr;
		pLast = nullptr;
		pCurrent = nullptr;
		pStop = nullptr;
		pPrev = nullptr;
	}
	TList(const TList<TData>&);
	TList(TNode<TData>*);

	virtual ~TList() {clear();}

	virtual void InsertFirst(const TData&);
	void InsertLast(const TData&);
	void InsertBefore(const TData& after, const TData& ND);
	void InsertAfter(const TData& previous, const TData& ND);
	void DeleteNode(TNode<TData>* node);
	void DeleteCurrentNode() {DeleteNode(pCurrent);}

	bool operator==(const TList<TData>& l) const;

	TNode<TData>* GetCurrent() {return pCurrent;}

	bool IsEnded() const { return pCurrent == pStop; }
	bool IsEmpty() const {return pFirst == nullptr;} 

	TNode<TData>* Search(const TData& d);
	TNode<TData>* Search(const TNode<TData>* node);

	void next() {
		if ((pCurrent == pStop) ||(pCurrent == nullptr))
			throw;
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	void reset() {
	pCurrent = pFirst;
	pPrev = nullptr;
	}
	virtual void clear();
};


template <typename TData> TList<TData>::TList(const TList<TData>& l) {
	if (l.IsEmpty())
	{
		pFirst = nullptr;
		pLast = nullptr;
		pCurrent = nullptr;
		pStop = nullptr;
		return;
	}
	pFirst = new TNode<TData>(*l.pFirst);
	pCurrent = pFirst;
	pStop = nullptr;
	TNode<TData>* tmpNode = pFirst;
	TNode<TData>* tmpNode1 = pFirst->pNext;
	while (tmpNode1 != nullptr) {
		tmpNode->pNext = new TNode<TData>(tmpNode1->data);
		tmpNode = tmpNode->pNext;
		tmpNode1 = tmpNode1->pNext;
	}
	pLast = tmpNode;

}
template <typename TData> TList<TData>::TList(TNode<TData>* d) {
	pFirst = d;
	TNode<TData>* tmpNode = d;
	while (tmpNode->pNext != nullptr) {
		tmpNode = tmpNode->pNext;
	}
	pLast = tmpNode;
	pCurrent = pFirst;
	pStop = nullptr;
}

template <typename TData> TNode<TData>* TList<TData>::Search(const TData& d) {
	reset();
	while ((pCurrent != pStop) && (pCurrent->data != d))
		next();
	return (pCurrent == pStop) ? nullptr : pCurrent;
}
template <typename TData> TNode<TData>* TList<TData>::Search(const TNode<TData>* node) {
	return Search(node->data);
}


template <typename TData> void TList<TData>::InsertFirst(const TData& d) {
	TNode<TData>* nFirst = new TNode<TData>(d, pFirst);
	pFirst = nFirst;
	if (pLast == nullptr) {
		pLast = pFirst;
	}
	pCurrent = pFirst;
}
template <typename TData> void TList<TData>::InsertLast(const TData& d) {
	if (IsEmpty()) {
		InsertFirst(d);
		return;
	}
	TNode<TData>* nLast = new TNode<TData>(d, pStop);
	pLast->pNext = nLast;
	pLast = nLast;
	pCurrent = nLast;
}
template <typename TData> void TList<TData>::InsertBefore(const TData& after, const TData& ND) {
	TNode<TData>* TNow = Search(after);
	if (TNow == nullptr) {
		throw std::exception("Element not found");
	}
	pPrev->pNext = new TNode<TData>(ND, TNow);
	return;
}
template <typename TData> void TList<TData>::InsertAfter(const TData& prev, const TData& ND) {
	TNode<TData>* TNow = Search(prev);
	if (TNow->pNext == pStop) {
		throw std::exception("Element not found");
	}
	TNode<TData>* nNode = new TNode<TData>(ND, TNow->pNext);
	TNow->pNext = nNode;
}
template <typename TData> void TList<TData>::DeleteNode(TNode<TData>* node) {
	if (pFirst == nullptr)
		throw std::exception("Element not found");
	if (pFirst == node)
	{
		pFirst = pFirst->pNext;
		delete node;
		return;
	}
	Search(node);

	pPrev->pNext = pCurrent->pNext;
	if (pCurrent->pNext == pStop) {
		pLast = pPrev;
	}
	delete pCurrent;
	pCurrent = pPrev->pNext;
}


template <typename TData> void TList<TData>::clear() {
	if (pFirst == nullptr)
		return;
	TNode<TData>* TNow = pFirst;
	TNode<TData>* TNext = pFirst->pNext;
	while (TNext != pStop) {
		delete TNow;
		TNow = TNext;
		TNext = TNow->pNext;
	}

	pFirst = nullptr;
	pLast = nullptr;
	pCurrent = nullptr;
	pStop = nullptr;

}
template <typename TData> bool TList<TData>::operator==(const TList<TData>& l) const {
	TList<TData> tmpThis = TList<TData>(*this);
	TList<TData> tmpL = TList<TData>(l);
	tmpThis.reset();
	tmpL.reset();
	while ((!tmpThis.IsEnded()) && (!tmpL.IsEnded())) {
		if (tmpThis.GetCurrent()->data != tmpL.GetCurrent()->data)
			return false;
		tmpThis.next();
		tmpL.next();
	}
	if (!tmpThis.IsEnded() || !tmpL.IsEnded())
		return false;
	return true;
}
#endif