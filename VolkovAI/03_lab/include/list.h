#ifndef LIST_H
#define LIST_H

#pragma once
template <typename TElem> struct TNode {
	TElem value;
	TNode* pNext;
	TNode() : value(TElem()), pNext(nullptr) {}
	TNode(const TElem& elem) : value(elem), pNext(nullptr) {}
	TNode<TElem>& operator= (const TNode<TElem>& node) noexcept {
		if (this == &node) {
			return *this;
		}
		value = node.value;
		pNext = node.pNext;
		return *this;
	}
};

template <typename TElem> class TList {
private:
	TNode<TElem>* pFirst;
public:
	TList() : pFirst(nullptr) {}
	TList(const TList& list){
		if (list.pFirst == nullptr) {
			pFirst = nullptr;
			return;
		}
		pFirst = new TNode<TElem>(list.pFirst->value);
		TNode<TElem>* curr = pFirst;
		TNode<TElem>* curr_copy = list.pFirst->pNext;
		while (curr_copy != nullptr) {
			curr->pNext = new TNode<TElem>(curr_copy->value);
			curr = curr->pNext;
			curr_copy = curr_copy->pNext;
		}
	}
	~TList() {
		TNode<TElem>* curr = pFirst;
		TNode<TElem>* prev = nullptr;
		while (curr != nullptr) {
			prev = curr;
			curr = curr->pNext;
			delete prev;
		}
		pFirst = nullptr;
	}
	bool isEmpty() const {
		return pFirst == nullptr;
	}
	TElem first_value() const {
		if (pFirst == nullptr) {
			throw "PFirst is nullptr.";
		}
		return pFirst->value;
	}
	void push_front(TNode<TElem>* Node) {
		if (Node == nullptr) {
			throw "Trying to insert Node, that is nullptr.";
		}
		if (isEmpty()) {
			pFirst = Node;
			return;
		}
		Node->pNext = pFirst;
		pFirst = Node;
	}
	void push_back(TNode<TElem>* Node) {
		if (Node == nullptr) {
			throw "Trying to insert Node, that is nullptr.";
		}
		if (isEmpty()) {
			pFirst = Node;
			return;
		}
		TNode <TElem>* curr = pFirst;
		while (curr->pNext != nullptr) {
			curr = curr->pNext;
		}
		curr->pNext = Node;
	}
	TNode<TElem>* search(TElem value) {
		TNode<TElem>* curr = pFirst;
		while (curr != nullptr) {
			if (curr->value == value) {
				return curr;
			}
			curr = curr->pNext;
		}
		throw "There's no node with entered value.";
	}
	void insert_before(TNode <TElem>* Node, TElem val) {
		TNode <TElem>* prev = pFirst;
		TNode <TElem>* searching_node = search(val);
		if (searching_node == pFirst) {
			Node->pNext = pFirst;
			pFirst = Node;
			return;
		}
		while (prev->pNext != searching_node) {
			prev = prev->pNext;
		}
		Node->pNext = searching_node;
		prev->pNext = Node;
	}
	void insert_after(TNode <TElem>* Node, TElem val) {
		TNode<TElem>* searching_node = search(val);
		Node->pNext = searching_node->pNext;
		searching_node->pNext = Node;
	}
	void remove(TElem val) {
		TNode <TElem>* prev = pFirst;
		if (pFirst->value == val) {
			pFirst = prev->pNext;
			return;
		}
		TNode <TElem>* searching_node = search(val);
		while (prev->pNext != searching_node) {
			prev = prev->pNext;
		}
		prev->pNext = searching_node->pNext;
		delete searching_node;
	}
	size_t size() const {
		size_t size = 0;
		TNode<TElem>* curr = pFirst;
		while (curr != nullptr) {
			size++;
			curr = curr->pNext;
		}
		return size;
	}
	TList <TElem>& operator= (const TList <TElem>& list) noexcept {
		if (this == &list) {
			return *this;
		}
		if (list.isEmpty()) {
			pFirst = nullptr;
			return *this;
		}
		while (!isEmpty()) {
			TNode<TElem>* curr = pFirst;
			pFirst = pFirst->pNext;
			delete curr;
		}
		pFirst = new TNode<TElem>(list.pFirst->value);
		TNode<TElem>* currentThis = pFirst;
		TNode<TElem>* currentList = list.pFirst->pNext;
		while (currentList != nullptr) {
			currentThis->pNext = new TNode<TElem>(currentList->value);
			currentThis = currentThis->pNext;
			currentList = currentList->pNext;
		}
		return *this;
	}
	bool operator== (const TList <TElem>& list) const {
		if (list.size() != size()) {
			return false;
		}
		TNode<TElem>* currlist = list.pFirst;
		TNode<TElem>* curr = pFirst;
		if (curr == nullptr && currlist == nullptr) {
			return true;
		}
		while (curr != nullptr && currlist != nullptr) {
			if (currlist->value != curr->value) {
				return false;
			}
			curr = curr->pNext;
			currlist = currlist->pNext;
		}
		return true;
	}
	bool operator!= (const TList <TElem>& list) const {
		return !(*this = list);
	}
};
#endif //LIST_H
