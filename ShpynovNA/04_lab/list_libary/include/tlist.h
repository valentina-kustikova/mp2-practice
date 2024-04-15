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
	TNode<TData>* pCurrent;
public:
	TList() {
		pFirst = nullptr;
		pLast = nullptr;
		pCurrent = nullptr;
		pStop = nullptr;
	}
	TList(const TList<TData>&);
	TList(TNode<TData>*);

	~TList() {clear();}

	virtual void InsertFirst(const TData&);
	virtual void InsertLast(const TData&);
	void InsertBefore(const TData& after, const TData& ND);
	void InsertAfter(const TData& previous, const TData& ND);

	TNode<TData>* GetCurrent() {return pCurrent;}

	bool IsEnded() const { return pCurrent == pStop; }
	bool IsEmpty() const {return pFirst == nullptr;} 

	virtual TNode<TData>* Search(const TData& d) ;

	void next() {
		if (pCurrent == pStop)
			throw;
		pCurrent = pCurrent->pNext;
	}
	void reset() {pCurrent = pFirst;}
	void clear();
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
	TNode<TData>* TBefore = nullptr;
	TNode<TData>* TNow = pFirst;
	while ((TNow != pStop) && (TNow->data != d)) {
		TBefore = TNow;
		TNow = TNow->pNext;
	}
	if (TNow == pStop)
		throw;
	return TBefore;
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
		InsertFirst(ND);
		return;
	}
	else {
		TNode<TData>* nNode = new TNode<TData>(ND, TNow->pNext);
		TNow->pNext = nNode;
		return;
	}
}
template <typename TData> void TList<TData>::InsertAfter(const TData& prev, const TData& ND) {
	TNode<TData>* TNow = Search(prev);
	if (TNow->pNext == pStop) {
		InsertLast(ND);
		return;
	}
	else {
		TNow = TNow->pNext;
		TNode<TData>* nNode = new TNode<TData>(ND, TNow->pNext);
		TNow->pNext = nNode;
	}
}

template <typename TData> void TList<TData>::clear() {
	if (pFirst == nullptr)
		return;
	TNode<TData>* TNow = pFirst;
	TNode<TData>* TNext = pFirst->pNext;
	while (TNext != pStop) {
		TNow = nullptr;
		TNow = TNext;
		TNext = TNow->pNext;
	}

	pFirst = nullptr;
	pLast = nullptr;
	pCurrent = nullptr;
	pStop = nullptr;
}
#endif