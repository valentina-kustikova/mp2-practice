#pragma once
#include <iostream>
#include <string>
#include "stack.h"
#include "list.h"


template <typename TElem> 
class list_stack : public Stack <TElem> {
private:
	TList<TElem> elems;
public:
	list_stack() { elems = TList<TElem>::TList(); };

	list_stack(const list_stack<TElem>& ls)
	{
		elems = ls.elems;
	}

	bool is_empty() const {
		return (elems.get_head()==nullptr);
	}

	bool is_full() const {
		return false; // !!!
	}

	void Push(const TElem& e) {
		if (is_full())
		{
			throw "Stack is full.";
		}
		ListNode<TElem>* temp = new ListNode<TElem>(e);
		elems.insert_Front(temp);
	}
	void pop() {
		if (is_empty()) {
			throw "Stack is empty.";
		}
		elems.Remove_First();
	}
	TElem Top() const {
		if (is_empty()) {
			throw "Stack is empty";
		}
		return elems.get_head()->val;
	}
	const list_stack <TElem>& operator= (const list_stack <TElem>& ls) {
		if (this == &ls)
		{
			return *this;
		}
		elems = ls.elems;
		return *this;
	}
	bool operator== (const list_stack <TElem>& ls)const {
		return (elems == ls.elems);
	}
	bool operator!= (const list_stack <TElem>& ls)const {
		return !(*this == ls);
	}
};