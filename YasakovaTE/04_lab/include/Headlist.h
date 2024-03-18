#pragma once
#include "node.h"
#include "list.h"
#include "ostream"

template <typename T>
class THeadList : public TList<T> {
private:
	TNode<T>* head;
public:
	THeadList();
	THeadList(const THeadList&);
	~THeadList();
	virtual void InsFirst(const T& _data);
	virtual void DelFirst();
	void Insert(const T& _data);
	void InsertInEnd(const T& _data);
	void Clean();
	void Delete(const T& d);

	THeadList& operator=(const THeadList& List);
	friend std::ostream& operator<<(std::ostream& os, const THeadList& l) {
		os << "[ ";
		TNode<T>* temp = l.first;
		while (temp != nullptr) {
			os << temp->data << " ";
			temp = temp->pNext;
		}
		os << "]";
		return os;
	}
};

template <typename T>
THeadList<T>::THeadList() : TList<T>() {
	head = new TNode<T>(T());
	head->pNext = this->first;
}

template <typename T>
THeadList<T>::THeadList(const THeadList& List) : TList<T>() {
	this->first = new TNode<T>(List.first->data, List.first->pNext);
	this->current = this->first;
	head = new TNode<T>(T());
	head->pNext = this->first;
}

template <typename T>
THeadList<T>::~THeadList() {
	delete head;
}

template <typename T>
void THeadList<T>::InsFirst(const T& _data) {
	TList<T>::InsFirst(_data);
	head->pNext = first;
}

template <typename T>
void THeadList<T>::DelFirst() {
	TList<T>::DelFirst();
	head->pNext = first;
}

template <typename T>
void THeadList<T>::Insert(const T& _data) {
	TList<T>::Insert(_data);
	head->pNext = first;
}

template <typename T>
void THeadList<T>::InsertInEnd(const T& _data) {
	TList<T>::InsertInEnd(_data);
	head->pNext = first;
}

template <typename T>
void THeadList<T>::Clean() {
	TList<T>::Clean();
	head->pNext = nullptr;
}

template <typename T>
void THeadList<T>::Delete(const T& d) {
	TList<T>::Delete(d);
	head->pNext = first;
}

template <typename T>
THeadList<T>& THeadList<T>::operator=(const THeadList& List) {
	if (this != &List) {
		TList<T>::operator=(List);
		head->pNext = this->first;
	}
	return *this;
}