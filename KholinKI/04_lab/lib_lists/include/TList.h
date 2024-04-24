#ifndef _TLIST_H
#define _TLIST_H
#include "Node.h"

template<typename T> class TList {
protected:
	Node<T>* pCurr;
public:
	Node<T>* pFirst;
	Node<T>* pPrev;
	Node<T>* pLast;
	Node<T>* pStop;
public:
	TList();
	TList(Node<T>* pFirst_);
	TList(const TList<T>& list);
	virtual ~TList();

	Node<T>* search(const T& data_);
 	virtual void insert_first(const T& data_);
	void insert_last(const T& data_);
	void insert_before(const T& data_, const T& next_data_);
	void insert_after(const T& data_, const T& next_data_);
	void insertion_sort(const T& data);
	virtual void remove(const T& data_);
	int  GetSize()const;
	bool IsEmpty()const;
	bool IsFull()const;
	virtual void clear();
	void reset();
	void Sort();
	void next();
	bool Is_Ended() const;
	void swap(Node<T>*& pNode1, Node<T>*& pNode2);
	Node<T>* getCurrent() const{ return pCurr; }
	Node<T>* getPFirst()const { return pFirst; }
	
	friend ostream& operator<<(ostream& ostr, const TList<T>& l) {
		Node<T>* tmp = l.pCurr;
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


template<typename T>
TList<T>::TList() {
	pFirst = nullptr;
	pLast = nullptr;
	pCurr = nullptr;
	pStop = nullptr;
	pPrev = nullptr;
}

template<typename T>
TList<T>::TList(Node<T>* pFirst_) {
	if (pFirst_ == nullptr)
	{
		pFirst = nullptr;
		return;
	}
	pFirst = new Node<T>(pFirst_->data);
	pCurr = pFirst;
	Node<T>* tmp = pFirst->pNext;
	while (tmp != nullptr) {
		pCurr->pNext = new Node<T>(tmp->data);
		pCurr = pCurr->pNext;
		tmp = tmp->pNext;
	}
	pLast = pCurr;
	pStop = nullptr;
	pCurr = pFirst;
	pPrev = nullptr;
}

template<typename T>
TList<T>::TList(const TList<T>& list) { 
	if (list.IsEmpty()) {
		return;
	}
	pFirst = new Node<T>(list.pFirst->data);
	Node<T>* tmp = list.pFirst->pNext;
	pCurr = pFirst;
	while (tmp != list.pStop) {
    	pCurr->pNext = new Node<T>(tmp->data);
		pCurr = pCurr->pNext;
		tmp = tmp->pNext;
	}
	pStop = nullptr;
	pLast = pCurr;
	pCurr = pFirst;
	pPrev = nullptr;
}

template<typename T>
TList<T>::~TList() {
	clear();
}


template<typename T>
Node<T>* TList<T>::search(const T& data_) {
	pCurr = pFirst;
	pPrev = nullptr;

	if (pFirst == nullptr) {
		return nullptr;
	}

	while (pCurr != pStop && pCurr->data != data_) {
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}

	if (pCurr == pStop) {
		return nullptr;
	}

	return pCurr;
}


template<typename T>
void TList<T>::insert_first(const T& data_) {
	Node<T>* tmp = new Node<T>(data_);
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

template<typename T>
void TList<T>::insert_last(const T& data_) {
	if (IsEmpty()) {
		insert_first(data_);
		return;
	}
	
	Node<T>* tmp = pLast;

	Node<T>* new_node = new Node<T>(data_);
	new_node->pNext = pStop;
	tmp->pNext = new_node;
	pLast = new_node;
}

template<typename T>
void TList<T>::insert_before(const T& data_, const T& next_data_) {
	if (IsEmpty()) {
		throw "Data not found!";
	}

	Node<T>* tmp = search(next_data_);
	if (tmp == nullptr) {
		throw "Data not found!";
	}

	Node<T>* node = new Node<T>(data_);
	if (tmp == pFirst) {
		insert_first(data_);
	}
	else {
		node->pNext = tmp;
		pPrev->pNext = node;
	}
	reset();
}

template<typename T>
void TList<T>::insert_after(const T& data_, const T& next_data_) {
	Node<T>* tmp = search(next_data_);
	if (tmp == nullptr) {
		throw "Data not found!";
	}

	if (tmp->pNext == pStop) {
		insert_last(data_);
	}
	else {
		Node<T>* node = new Node<T>(data_);
		node->pNext = tmp->pNext;
		tmp->pNext = node;
	}
	reset();
}

template<typename T>
void TList<T>::insertion_sort(const T& data) {
	while (!Is_Ended() && getCurrent()->data <= data)
	{
		next();
	}
	if (Is_Ended())
	{
		insert_last(data);
	}
	else
	{
		insert_before(data, getCurrent()->data);
	}
	reset();
}

template<typename T>
void TList<T>::remove(const T& data_) {
	Node<T>* tmp = search(data_);
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

template<typename T>
void TList<T>::Sort() {
	int size = GetSize();
	while (pCurr != pStop) {
		Node<T>* min = getCurrent();
		Node<T>* pJ = getCurrent()->pNext;
		while (pJ != pStop) {
			if (pJ->data <= min->data) {
				min = pJ;
			}
			pJ = pJ->pNext;
		}
		swap(pCurr, min);
		next();
	}
	reset();
}

template<typename T>
void TList<T>::clear() { 
	if (IsEmpty()) {
		return;
	}
	Node<T>* tmp = pFirst;
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

template<typename T>
void TList<T>::swap(Node<T>*& pNode1, Node<T>*& pNode2) {
	T tmp = pNode1->data;
	pNode1->data = pNode2->data;
	pNode2->data = tmp;
}

template<typename T>
int TList<T>::GetSize()const {
	if (IsEmpty()) {
		return 0;
	}
	int count = 0;
	Node<T>* tmp = pFirst;
	while (tmp != pStop) {
		count++;
		tmp = tmp->pNext;
	}
	return count;
}

template<typename T>
bool TList<T>::IsEmpty()const {
	return (pFirst == nullptr) ? true : false;
}

template<typename T>
bool TList<T>::IsFull()const {
	Node<T>* tmp = new Node<T>();
	if (tmp == nullptr) {
		return true;
	}
	else { return false; }
}

template<typename T>
void TList<T>::reset() {
	pCurr = pFirst;
	pPrev = nullptr;
}

template<typename T>
void TList<T>::next() {
	pPrev = pCurr;
	pCurr = pCurr->pNext;
}

template<typename T>
bool TList<T>::Is_Ended()const {
	return (pCurr == pStop) ? true : false;
}

#endif
