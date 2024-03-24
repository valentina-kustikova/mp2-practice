#ifndef _TLIST_H
#define _TLIST_H
#include "Node.h"

template<typename T> class TList {
public:
	Node<T>* pFirst;
	Node<T>* pLast;
	Node<T>* pCurr;
	Node<T>* pStop;
public:
	TList();
	TList(Node<T>* pFirst_);
	TList(const TList<T>& list);
	virtual ~TList();

	virtual Node<T>* search(const T& data_);

 	virtual void insert_first(const T& data_);
	virtual void insert_last(const T& data_);
	virtual void insert_before(const T& data_, const T& next_data_);
	virtual void insert_after(const T& data_, const T& next_data_);
	virtual void remove(const T& data_);
	virtual int GetSize()const;
	virtual bool IsEmpty()const;
	virtual bool IsFull()const;
	virtual void clear();
	virtual void reset();
	virtual void next();
	virtual bool Is_End() const;
	
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
}

template<typename T>
TList<T>::TList(const TList<T>& list) {
	if (list.pFirst == list.pStop) {
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
}

template<typename T>
TList<T>::~TList() {
	clear();
}


template<typename T>
Node<T>* TList<T>::search(const T& data_) {
	Node<T>* tmp = pFirst;
	while (tmp->pNext != pStop && tmp->data != data_) {
		tmp = tmp->pNext;
	}
	if (tmp->pNext == pStop && tmp->data != data_) {
		return nullptr;
	}
	return tmp;
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
	if (pFirst == nullptr) {
		insert_first(data_);
	}
	Node<T>* tmp = pFirst;
	while (tmp->pNext != pStop) {
		tmp = tmp->pNext;
	}
	Node<T>* new_node = new Node<T>(data_);
	new_node->pNext = pStop;
	tmp->pNext = new_node;
	
	pLast = tmp->pNext;
}

template<typename T>
void TList<T>::insert_before(const T& data_, const T& next_data_) {
	if (pFirst == nullptr) {
		insert_first(data_);
	}
	Node<T>* tmp = pFirst;
	Node<T>* pPrev = nullptr;
	while (tmp->data != next_data_ && tmp != pStop) {
		pPrev = tmp;
		tmp = tmp->pNext;
	}
	if (tmp->data != next_data_ && tmp == pStop) {
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
}

template<typename T>
void TList<T>::insert_after(const T& data_, const T& next_data_) {
	if (pFirst == nullptr) {
		insert_first(data_);
	}
	Node<T>* tmp = pFirst;
	while (tmp->data != next_data_ && tmp != pStop) {
		tmp = tmp->pNext;
	}
	if (tmp->data != next_data_ && tmp == pStop) {
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
}

template<typename T>
void TList<T>::remove(const T& data_) {
	if (pFirst == nullptr) {
		return;
	}
	else {
		Node<T>* tmp = pFirst;
		Node<T>* pPrev = nullptr;

		while (tmp->data != data_ && tmp != pStop) {
			pPrev = tmp;
			tmp = tmp->pNext;
		}
		if (tmp->data != data_ && tmp == pStop) {
			throw "Data not found!";
		}
		if (pPrev == nullptr) {
			pFirst = pFirst->pNext;
			pCurr = pFirst;
			tmp->pNext = nullptr;
			delete tmp;
		}
		else {
			pPrev->pNext = tmp->pNext;
			if (tmp->pNext == pStop) {
				pLast = pPrev;
			}
			tmp->pNext = nullptr;
			delete tmp;
			
		}
	}
}

template<typename T>
void TList<T>::clear() {
	if (pFirst == nullptr) {
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
	pLast = nullptr;
	pStop = nullptr;
}

template<typename T>
int TList<T>::GetSize()const {
	if (pFirst == nullptr) {
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
	return pFirst == nullptr ? true : false;
}

template<typename T>
bool TList<T>::IsFull()const {
	Node<T>* tmp = new Node<T>();
	if (tmp == nullptr) {
		throw "Failed allocate memory!";
	}
	else { return false; }
}

template<typename T>
void TList<T>::reset() {
	pCurr = pFirst;
}

template<typename T>
void TList<T>::next() {
	pCurr = pCurr->pNext;
}

template<typename T>
bool TList<T>::Is_End()const {
	return pCurr == pStop ? true : false;
}


#endif
