#pragma once

// move TList and THeadRingList to different files

template <typename TData>
struct TNode {
  TData data;
  TNode* pNext;

  TNode() {
    this->data = TData();
    this->pNext = nullptr;
  }

  TNode(const TData& data, TNode* pNext = nullptr) {
    this->data = data;
    this->pNext = pNext;
  }
};

// Add pPrev
// Rewrite Search (it should memorize previous TNode)

// Add RemoveFirst
// It will be redifined in THeadRingList
// SO Remove - Not!

// Delete Getters and Setters!!!
template <typename TData>
class TList {
protected:
  TNode<TData>* pFirst;
  TNode<TData>* pLast;
  TNode<TData>* pCurr;
  TNode<TData>* pStop;

public:
  TList();
  TList (const TList<TData>&);
  TList (TNode<TData>*);
  ~TList();
  TNode<TData>* Search (const TData&);
  virtual void InsertFirst (const TData&);
  virtual void InsertLast (const TData&);
  void InsertBefore (const TData&, const TData&);
  void InsertAfter (const TData&, const TData&);
  virtual void Remove (const TData&);
  void Clear();
  void Reset();
  void Next();
  TNode<TData>* GetCurr() const;
  ///
  TNode<TData>* GetFirst() const;
  TNode<TData>* GetLast() const;
  TNode<TData>* GetStop() const;
  ///

  ///
  void SetCurr(const TNode<TData>* node);
  void SetFirst(const TNode<TData>* node);
  void SetLast(const TNode<TData>* node);
  void SetStop(const TNode<TData>* node);
  ///
  bool IsEnded() const;
  bool IsEmpty() const;
  bool IsFull() const;
};

template <typename TData>
class THeadRingList : public TList<TData> {
protected:
  TNode<TData>* pHead;

public:
  THeadRingList();
  THeadRingList(const THeadRingList<TData>& ringL);
  ~THeadRingList();

  ///
  TNode<TData>* GetHead() const {
    return pHead;
  }
  void SetHead(const TNode<TData>* node) {
    pHead->data = node->data;
    pHead->pNext = node->pNext;
  }
  ///

  void Remove (const TData& data);
  void InsertFirst(const TData& data);
  void InsertLast(const TData& data);
};

// TLIST:
template <typename TData>
TList<TData>::TList() {
  pFirst = nullptr;
  pLast = nullptr;
  pCurr = nullptr;
  pStop = nullptr;
}

template <typename TData>
bool TList<TData>::IsEmpty() const {
  return pFirst == nullptr;
}

template <typename TData>
TList<TData>::TList(const TList& l) {
  if (l.IsEmpty())
	{
		pFirst=nullptr;
		pLast=nullptr;
		pCurr=nullptr;
		pStop=nullptr;
    return;
	}

	pFirst = new TNode<TData>(l.pFirst->data);
	TNode<TData>* tmp = pFirst; 
  TNode<TData>* ltmp = l.pFirst->pNext;
	while(ltmp != l.pStop)
	{
		tmp->pNext = new TNode<TData>(ltmp->data);
		tmp = tmp->pNext;
		ltmp = ltmp->pNext;
	}
	pLast = tmp;
	pCurr = pFirst;
	pStop = nullptr;
}

template <typename TData>
TList<TData>::TList(TNode<TData>* pNode) {
  pFirst = pNode;
  TNode<TData>* tmp = pNode;
  while (tmp->pNext != nullptr)
    tmp = tmp->pNext;
  pLast = tmp;
  pCurr = pFirst;
  pStop = nullptr;
}

template <typename TData>
void TList<TData>::Clear() {
  if (pFirst == nullptr)
    return;
  TNode<TData>* curr = pFirst;
  TNode<TData>* next = pFirst->pNext;
  while (next != pStop) {
    delete curr;
    curr = next;
    next = curr->pNext;
  }
  delete curr;
  pCurr = nullptr;
  pFirst = nullptr;
  pLast = nullptr;
}

template <typename TData>
TList<TData>::~TList() {
  Clear();
}

template <typename TData>
bool TList<TData>::IsFull() const {
  TNode<TData>* tmp = new TNode<TData>();
  if (tmp == nullptr)
    return true;
  delete tmp;
  return false;
}

template <typename TData>
bool TList<TData>::IsEnded()const {
  return pCurr == pStop;
}

template <typename TData>
TNode<TData>* TList<TData>::Search(const TData& data) {
  TNode<TData>* curr = pFirst;
  while (curr != pStop && curr->data != data) {
    curr = curr->pNext;
  }
  return curr;
}

template <typename TData>
void TList<TData>::InsertFirst(const TData& data) {
  TNode<TData>* new_first = new TNode<TData>(data, pFirst);
  pFirst = new_first;
  if (pLast == nullptr) {
    pLast = pFirst;
  }
  pCurr = pFirst;
}

template <typename TData>
void TList<TData>::InsertLast(const TData& data) {
  if (IsEmpty()) {
    InsertFirst(data);
    return;
  }
  TNode<TData>* new_last = new TNode<TData>(data, pStop);
  pLast->pNext = new_last;
  pLast = new_last;
  pCurr = new_last;
}

template <typename TData>
void TList<TData>::InsertBefore(const TData& who, const TData& where) {
  TNode<TData>* prev = nullptr;
  TNode<TData>* curr = pFirst;
  while (curr != pStop && curr->data != where) {
    prev = curr;
    curr = curr->pNext;
  }
  if (curr == pStop) {
    throw std::exception("no elements");
  }
  if (prev == nullptr) {
    InsertFirst(who);
    return;
  }
  TNode<TData>* new_node = new TNode<TData>(who, curr);
  prev->pNext = new_node;
}

template <typename TData>
void TList<TData>::InsertAfter(const TData& who, const TData& where) {
  TNode<TData>* pWhere = Search(where);
  if (pWhere == nullptr) {
    throw std::exception("no elements");
  }
  if (pWhere == pLast) {
    InsertLast(who);
    return;
  }
  TNode<TData>* new_node = new TNode<TData>(who, pWhere->pNext);
  pWhere->pNext = new_node;
}

template <typename TData>
void TList<TData>::Remove(const TData& v)
{
	TNode<TData>* prev = nullptr;
	TNode<TData>* curr = pFirst;
	while (curr != pStop && curr->data != v)
	{
		prev = curr;
		curr = curr->pNext;
	}
	if (curr == pStop)
		throw std::exception("NoSuchElement");
	if (curr == pFirst && curr->pNext == pStop)
	{
		Clear();
		return;
	}
	if (curr == pFirst)
	{
		pFirst = pFirst->pNext;
		delete curr;
		return;
	}
	if (curr == pLast)
	{
		prev->pNext = pStop;
		delete curr;
		return;
	}
	prev->pNext = curr->pNext;
	delete curr;
}

template <typename TData>
void TList<TData>::Reset() {
  pCurr = pFirst;
}

template <typename TData>
void TList<TData>::Next() {
  if (pCurr == pStop)
    throw std::exception("end of the list");
  pCurr = pCurr->pNext;
}

template <typename TData>
TNode<TData>* TList<TData>::GetCurr() const {
  return pCurr;
}

template <typename TData>
TNode<TData>* TList<TData>::GetFirst() const {
  return pFirst;
}

template <typename TData>
TNode<TData>* TList<TData>::GetLast() const {
  return pLast;
}

template <typename TData>
TNode<TData>* TList<TData>::GetStop() const {
  return pStop;
}

template <typename TData>
void TList<TData>::SetCurr(const TNode<TData>* node) {
  pCurr->data = node->data;
  pCurr->pNext = node->pNext;
}

template <typename TData>
void TList<TData>::SetFirst(const TNode<TData>* node) {
  pFirst->data = node->data;
  pFirst->pNext = node->pNext;
}

template <typename TData>
void TList<TData>::SetLast(const TNode<TData>* node) {
  pLast->data = node->data;
  pLast->pNext = node->pNext;
}

template <typename TData>
void TList<TData>::SetStop(const TNode<TData>* node) {
  pStop->data = node->data;
  pStop->pNext = node->pNext;
}

// ----------------------------------------------------------------------------
template <typename TData>
THeadRingList<TData>::THeadRingList() : TList<TData>() {
  pHead = new TNode<TData>();
  pStop = pHead;
}

template <typename TData>
THeadRingList<TData>::THeadRingList(const THeadRingList<TData>& ringL) : TList<TData>(ringL) {
  pHead = new TNode<TData>(ringL.pHead->data, pFirst);
  if (!ringL.IsEmpty())
    pLast->pNext = pHead;
  pStop = pHead;
}

template <typename TData>
THeadRingList<TData>::~THeadRingList() {
  delete pHead;
}

template <typename TData>
void THeadRingList<TData>::InsertFirst(const TData& data) {
  TList<TData>::InsertFirst(data);
  pHead->pNext = pFirst;
  pStop = pHead;
  pLast->pNext = pHead;
}

template <typename TData>
void THeadRingList<TData>::InsertLast(const TData& data) {
  if (IsEmpty()) {
    THeadRingList<TData>::InsertFirst(data);
    return;
  }
  TList<TData>::InsertLast(data);
}

template <typename TData>
void THeadRingList<TData>::Remove(const TData& v)
{
  TNode<TData>* curr = pFirst;
  if (curr->data == v) {
    pFirst = pFirst->pNext;
    pHead->pNext = pFirst;
		delete curr;
    return;
  }
  TList<TData>::Remove(v);
}
