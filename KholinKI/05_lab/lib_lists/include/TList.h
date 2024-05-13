#ifndef _TLIST_H
#define _TLIST_H
#include "Node.h"

template<typename TKey,typename TData> class TList {
protected:
	Node<TKey,TData>* pCurr;
public:
	Node<TKey, TData>* pFirst;
	Node<TKey, TData>* pPrev;
	Node<TKey, TData>* pLast;
	Node<TKey, TData>* pStop;
public:
	TList();
	TList(Node<TKey, TData>* pFirst_);
	TList(const TList<TKey, TData>& list);
	virtual ~TList();

	Node<TKey, TData>* search(const TKey& key_);
 	virtual void insert_first(const TKey& key_,const TData* data_);
	void insert_last(const TKey& key_, const TData* data_);
	void insert_before(const TKey& key_, const TData* data_, const TKey& next_key_);
	void insert_after(const TKey& key_, const TData* data_, const TKey& next_key_);
	void insertion_sort(const TKey& key_, const TData* data_);
	virtual void remove(const TKey& key_);
	int  GetSize()const;
	bool IsEmpty()const;
	bool IsFull()const;
	void clear();
	void reset();
	void next();
	bool Is_Ended() const;
	void swap(Node<TKey, TData>*& pNode1, Node<TKey, TData>*& pNode2);
	Node<TKey,TData>* getCurrent() const{ return pCurr; }
	
	friend ostream& operator<<(ostream& ostr, const TList<TKey, TData>& l) {
		Node<TKey,TData>* tmp = l.pCurr;
		int number = 1;
		while (tmp != l.pStop) {
			cout << "The structure of list" << endl;
			cout << "|										" << endl;
			cout << "|	Current node " << number << ":" << "		" << endl;
			cout << "|										" << endl;
			cout << "|	data: " << tmp->data << "			" << endl;
			cout << "|										" << endl;
			cout << "===========================================================================" << endl;
			number++;
			tmp = tmp->pNext;
		}
		return ostr;
	}
	
};


template<typename TKey, typename TData>
TList<TKey, TData>::TList() {
	pFirst = nullptr;
	pLast = nullptr;
	pCurr = nullptr;
	pStop = nullptr;
	pPrev = nullptr;
}

template<typename TKey, typename TData>
TList<TKey, TData>::TList(Node<TKey, TData>* pFirst_) {
	if (pFirst_ == nullptr)
	{
		pFirst = nullptr;
		return;
	}
	pFirst = new Node<TKey, TData>(pFirst_->key,pFirst_->data);
	pCurr = pFirst;
	Node<TKey,TData>* tmp = pFirst->pNext;
	while (tmp != nullptr) {
		pCurr->pNext = new Node<TKey, TData >(tmp->key,tmp->data);
		pCurr = pCurr->pNext;
		tmp = tmp->pNext;
	}
	pLast = pCurr;
	pStop = nullptr;
	pCurr = pFirst;
	pPrev = nullptr;
}

template<typename TKey, typename TData>
TList<TKey, TData>::TList(const TList<TKey, TData>& list) {
	if (list.IsEmpty()) {
		return;
	}
	pFirst = new Node<TKey, TData>(list.pFirst->key,list.pFirst->data);
	Node<TKey,TData>* tmp = list.pFirst->pNext;
	pCurr = pFirst;
	while (tmp != list.pStop) {
    	pCurr->pNext = new Node<TKey, TData>(tmp->key,tmp->data);
		pCurr = pCurr->pNext;
		tmp = tmp->pNext;
	}
	pStop = nullptr;
	pLast = pCurr;
	pCurr = pFirst;
	pPrev = nullptr;
}

template<typename TKey, typename TData>
TList<TKey, TData>::~TList() {
	clear();
}


template<typename TKey, typename TData>
Node<TKey, TData>* TList<TKey, TData>::search(const TKey& key_) {
	pCurr = pFirst;
	pPrev = nullptr;

	if (pFirst == nullptr) {
		return nullptr;
	}

	while (pCurr != pStop && pCurr->key != key_) {
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}

	if (pCurr == pStop) {
		return nullptr;
	}

	return pCurr;
}


template<typename TKey, typename TData>
void TList<TKey, TData>::insert_first(const TKey& key_, const TData* data_) {
	Node<TKey,TData>* tmp = new Node<TKey, TData>(key_,data_);
	tmp->pNext = pFirst;
	if (pFirst == nullptr) {
		pFirst = tmp;
		pLast = pFirst;
		pCurr = pFirst;
	}
	else {
		pFirst = tmp;
		pCurr = pFirst;
	}
}

template<typename TKey, typename TData>
void TList<TKey, TData>::insert_last(const TKey& key_, const TData* data_) {
	if (IsEmpty()) {
		insert_first(data_);
		return;
	}
	
	Node<TKey, TData>* tmp = pLast;

	Node<TKey, TData>* new_node = new Node<TKey, TData>(key_,data_);
	new_node->pNext = pStop;
	tmp->pNext = new_node;
	pLast = new_node;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::insert_before(const TKey& key_, const TData* data_, const TKey& next_key_) {
	if (IsEmpty()) {
		throw "Data not found!";
	}

	Node<TKey, TData>* tmp = search(next_key_);
	if (tmp == nullptr) {
		throw "Data not found!";
	}

	Node<TKey, TData>* node = new Node<TKey, TData>(key_,data_);
	if (tmp == pFirst) {
		insert_first(key_,data_);
	}
	else {
		node->pNext = tmp;
		pPrev->pNext = node;
	}
	reset();
}

template<typename TKey, typename TData>
void TList<TKey, TData>::insert_after(const TKey& key_, const TData* data_, const TKey& next_key_) {
	Node<TKey,TData>* tmp = search(next_key_);
	if (tmp == nullptr) {
		throw "Data not found!";
	}

	if (tmp->pNext == pStop) {
		insert_last(key_,data_);
	}
	else {
		Node<TKey, TData>* node = new Node<TKey, TData>(key_,data_);
		node->pNext = tmp->pNext;
		tmp->pNext = node;
	}
	reset();
}

template<typename TKey, typename TData>
void TList<TKey,TData>::insertion_sort(const TKey& key_, const TData* data_) {
	while (!Is_Ended() && getCurrent()->key <= key_)
	{
		next();
	}
	if (Is_Ended())
	{
		insert_last(key_,data_);
	}
	else
	{
		insert_before(key_,data_, getCurrent()->data);
	}
	reset();
}

template<typename TKey, typename TData>
void TList<TKey,TData>::remove(const TKey& key_) {
	Node<TKey,TData>* tmp = search(key_);
	if (tmp == nullptr) {
		throw "Data not found!";
	}
	
	if (tmp == pFirst) {
		pFirst = pFirst->pNext;
		pCurr = pFirst;
		tmp->pNext = nullptr;
		delete tmp;
	}
	else {
		if (tmp->pNext == pStop) {
			pLast = pPrev;
		}

		pPrev->pNext = tmp->pNext;
		tmp->pNext = nullptr;
		delete tmp;
	}
}

template<typename TKey, typename TData>
void TList<TKey,TData>::clear() {
	if (IsEmpty()) {
		return;
	}
	Node<TKey,TData>* tmp = pFirst;
	while (tmp != pStop) {
		pFirst = pFirst->pNext;
		tmp->pNext = nullptr;
		delete tmp;
		tmp = pFirst;
	}
	pFirst = nullptr;
	pCurr = nullptr;
	pPrev = nullptr;
	pLast = nullptr;
}

template<typename TKey, typename TData>
void TList<TKey,TData>::swap(Node<TKey,TData>*& pNode1, Node<TKey,TData>*& pNode2) {
	TKey tmp_key = pNode1->key;
	TData* tmp_data = pNode1->data;
	pNode1->key = pNode2->key;
	pNode1->data = pNode2->data;
	pNode2->key = tmp_key;
	pNode2->data = tmp_data;
}

template<typename TKey, typename TData>
int TList<TKey,TData>::GetSize()const {
	if (IsEmpty()) {
		return 0;
	}
	int count = 0;
	Node<TKey,TData>* tmp = pFirst;
	while (tmp != pStop) {
		count++;
		tmp = tmp->pNext;
	}
	return count;
}

template<typename TKey, typename TData>
bool TList<TKey,TData>::IsEmpty()const {
	return (pFirst == nullptr) ? true : false;
}

template<typename TKey, typename TData>
bool TList<TKey,TData>::IsFull()const {
	Node<TKey,TData>* tmp = new Node<TKey,TData>();
	if (tmp == nullptr) {
		return true;
	}
	else { return false; }
}

template<typename TKey, typename TData>
void TList<TKey,TData>::reset() {
	pCurr = pFirst;
	pPrev = nullptr;
}

template<typename TKey, typename TData>
void TList<TKey,TData>::next() {
	pPrev = pCurr;
	pCurr = pCurr->pNext;
}

template<typename TKey, typename TData>
bool TList<TKey,TData>::Is_Ended()const {
	return (pCurr == pStop) ? true : false;
}

#endif
