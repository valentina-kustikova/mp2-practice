#ifndef _TLIST_H
#define _TLIST_H
#include "Node.h"

template<typename T> class TList {
	
private:
	Node<T>* pFirst;
	Node<T>* pLast;
	Node<T>* pCurr;
	Node<T>* pStop;
public:
	TList();
	TList(Node<T>* pFirst_);
	TList(const TList<T>& list);
	~TList();

	Node<T>* search(const T& data_);
	void insert_first(const T& data_);
	void insert_last(const T& data_);
	void insert_before(const T& data_, const T& next_data_);
	void insert_after(const T& data_, const T& next_data_);
	void remove(const T& data_);
	void clear();
	int GetSize()const;
	bool IsEmpty()const;
	bool IsFull()const;
	void reset();
	Node<T>* GetCurrent()const;
	Node<T>* GetPStop()const;
	Node<T> * GetPFirst()const;
	void SetPStop(Node<T>* new_pStop);
	void SetPLast(Node<T>* new_pLast);
	void next();
	bool Is_End();

	
	friend ostream& operator<<(ostream& ostr, const TList<T>& l) {
		Node<T>* tmp = l.GetCurrent();
		int number = 1;
		while (tmp != l.GetPStop()) {
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
	pFirst = pFirst_;
	pCurr = pFirst;
	Node<T>* tmp = pFirst;
	if (pFirst_ != nullptr) {
		while (tmp->pNext != nullptr) {
			tmp = tmp->pNext;
		}
	}
	pLast = tmp;
	pStop = nullptr;
}

template<typename T>
TList<T>::TList(const TList<T>& list) {
	if (list.pFirst == nullptr) {
		return;
	}
	pFirst = new Node<T>(list.pFirst->data);
	Node<T>* tmp1 = list.pFirst;
	Node<T>* tmp2 = pFirst;
	pCurr = tmp2;
	while (tmp1 != list.pStop) {
		tmp1 = tmp1->pNext;
		tmp2->pNext = new Node<T>(tmp1->data);
		tmp2 = tmp2->pNext;
	}
	pLast = tmp2;
	pStop = nullptr;
	pLast->pNext = pStop;
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
	if (pFirst == pStop) {
		pFirst = tmp;
		pFirst->pNext = pStop;
		pLast = pFirst;
		pCurr = pFirst;
	}
	else {
		tmp->pNext = pFirst;
		pFirst = tmp;
		pCurr = pFirst;
	}

}

template<typename T>
void TList<T>::insert_last(const T& data_) {
	if (pFirst == pStop) {
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
	Node<T>* pPrev = pStop;
	while (tmp->data != next_data_ && tmp != pStop) {
		pPrev = tmp;
		tmp = tmp->pNext;
	}
	if (tmp->data != next_data_ && tmp == pStop) {
		throw "Data not found!";
	}
	Node<T>* node = new Node<T>(data_);
	node->pNext = tmp;
	if (pPrev == pStop) {
		pFirst = node;
	}
	else pPrev->pNext = node;
}

template<typename T>
void TList<T>::insert_after(const T& data_, const T& next_data_) {//доработать
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
	Node<T>* node = new Node<T>(data_);
	node->pNext = tmp->pNext;
	tmp->pNext = node;
}

template<typename T>
void TList<T>::remove(const T& data_) {//удаление первого и последнего #тесты
	Node<T>* tmp = pFirst;
	Node<T>* pPrev = pStop;
	
	while (tmp->data != data_ && tmp != pStop) {
		pPrev = tmp;
		tmp = tmp->pNext;
	}
	if (tmp->data != data_ && tmp == pStop) {
		throw "Data not found!";
	}
	if (pPrev == pStop) {
		pFirst = pFirst->pNext;
		pCurr = pFirst;
		if(pStop != nullptr){
			pPrev->pNext = pFirst;
		}
		tmp->pNext = nullptr;
		delete tmp;
	}
	//условие,когда дошли до конца и нашли данные(отсутствует)
	else { 
		pPrev->pNext = tmp->pNext; 
		tmp->pNext = nullptr; 
		delete tmp;
	}
	if (pFirst == pStop) {
		pFirst == nullptr;
		pCurr = nullptr;
		pLast = nullptr;
	}
}

template<typename T>
void TList<T>::clear() {
	Node<T>* tmp = pFirst;
	if (tmp != nullptr) {//если список непустой
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
	if (pStop != nullptr) {//если существует только фиктивный блок
		pStop == nullptr;
	}
}

template<typename T>
int TList<T>::GetSize()const {
	int count = 0;
	Node<T>* tmp = pFirst;
	if (tmp == nullptr) {
		return 0;
	}
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
Node<T>* TList<T>::GetCurrent()const {
	return pCurr;
}

template<typename T>
Node<T>* TList<T>::GetPFirst()const {
	return pFirst;
}


template<typename T>
Node<T>* TList<T>::GetPStop()const {
	return pStop;
}

template<typename T>
void TList<T>::SetPStop(Node<T>* new_pStop) {
	pStop = new_pStop;
}
template<typename T>
void TList<T>::SetPLast(Node<T>* new_pLast) {
	pLast = new_pLast;
}


template<typename T>
void TList<T>::next() {
	pCurr = pCurr->pNext;
}

template<typename T>
bool TList<T>::Is_End() {
	return pCurr == pStop ? true : false;
}
#endif
