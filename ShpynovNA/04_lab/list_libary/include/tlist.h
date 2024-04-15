#ifndef _TL
#define _TL

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
public:
	TNode<TData>* pCurrent;

	TList() {
		pFirst = nullptr;
		pLast = nullptr;
		pCurrent = nullptr;
		pStop = nullptr;
	}
	TList(const TList<TData>&);
	TList(TNode<TData>*);

	~TList() {
		clear();
	}

	virtual void InsertFirst(const TData&);
	virtual void InsertLast(const TData&);
	void InsertBefore(const TData& after, const TData& ND);
	void InsertAfter(const TData& previous, const TData& ND);

	bool IsEnded() const {
		return pCurrent == pStop;
	}
	bool IsEmpty() const {
		return pFirst == nullptr;
	}
	bool IsFull() const {
		return false;
	}

	void next() {
		if (pCurrent == pStop)
			throw;
		pCurrent = pCurrent->pNext;
	}
	void reset() {
		pCurrent = pFirst;
	}
	void clear();
};
template <typename TData> class THeadRingList : public TList<TData> {
public:
	TNode<TData>* pHead;

	THeadRingList():TList<TData>() {
		pHead = new TNode<TData>();
		pStop = pHead;
	}
	THeadRingList(const THeadRingList<TData>& l) :TList<TData>(l) {
		pHead = new TNode<TData>(l.pHead->data, pFirst);
		if (!l.IsEmpty())
			pLast->pNext = pHead;
		pStop = pHead;
	}

	~THeadRingList() {
		delete pHead;
	}

	void InsertFirst(const TData& d) {
		TList<TData>::InsertFirst(d);
		pHead->pNext = pFirst;
		pStop = pHead;
		pLast->pNext = pHead;
	}
	void InsertLast(const TData& d) {
		if (IsEmpty()) {
			THeadRingList<TData>::InsertFirst(d);
			return;
		}
		TList<TData>::InsertLast(d);
	}

	THeadRingList<TData>& operator=(const THeadRingList<TData>& l) {
		pFirst = new TNode<TData>(*l.pFirst);
		pHead = new TNode<TData>();
		pStop = pHead;
		(*this).reset();
		TNode<TData>* tmp = l.pFirst;
		while (tmp->pNext != l.pStop) {
			pCurrent->pNext = new TNode<TData>(*tmp->pNext);
			pCurrent = pCurrent->pNext;
			tmp = tmp->pNext;
		}
		pCurrent->pNext = pStop;
		pLast = pCurrent;
		pCurrent = pFirst;

		return (*this);
	}
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
	pFirst = new TNode<TData>(l.pFirst->data);
	TNode<TData>* tmpNode = l.pFirst;
	TNode<TData>* tmpNode1 = l.pFirst->pNext;
	while (tmpNode1 != l.pStop) {
		tmpNode->pNext = new TNode<TData>(tmpNode1->data);
		tmpNode = tmpNode->pNext;
		tmpNode1 = tmpNode1->pNext;
	}
	pLast = tmpNode;
	pCurrent = pFirst;
	pStop = nullptr;
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
	TNode<TData>* TBefore = nullptr;
	TNode<TData>* TNow = pFirst;
	while ((TNow != pStop) && (TNow->data != after)) {
		TBefore = TNow;
		TNow = TNow->pNext;
	}
	if (TNow == pStop) {
		throw;
	}
	if (TBefore == nullptr) {
		InsertFirst(ND);
		return;
	}
	else {
		TNode<TData>* nNode = new TNode<TData>(ND, TNow);
		TBefore->pNext = nNode;
		return;
	}
}
template <typename TData> void TList<TData>::InsertAfter(const TData& prev, const TData& ND){
	TNode<TData>* TNow = pFirst;
	while ((TNow != pStop) && (TNow->data != prev)) {
		TNow = TNow->pNext;
	}
	if (TNow == nullptr)
		throw;
	if (TNow == pLast) {
		InsertLast(ND);
		return;
	}
	TNode<TData>* nNode = new TNode<TData>(ND, TNow->pNext);
	TNow->pNext = nNode;
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