#pragma once
#ifndef LIST_STACK_H
#define LIST_STACK_H
#include "stack.h"
#include "list.h"

template <typename TElem> class list_stack : public Stack <TElem> {
private:
	TList<TElem> elems;
public:
	list_stack() {};
	list_stack(const list_stack<TElem>& ls)
	{
		elems = ls.elems;
	}
	bool isEmpty() const {
		return elems.isEmpty();
	}
	bool isFull() const {
		try
		{
			TNode<TElem>* newNode = new TNode<TElem>();
			if (newNode == nullptr)
			{
				return true;
			}
			delete newNode;
		}
		catch (...)
		{
			return true;
		}
		return false;
	}
	
	void push(const TElem& e) {
		if (isFull())
		{
			throw "Stack is full.";
		}
		TNode<TElem>* temp = new TNode<TElem>(e);
		elems.push_front(temp);
	}
	void pop() {
		if (isEmpty()) {
			throw "Stack is empty.";
		}
		elems.remove(elems.first_value());
	}
	TElem showTop() const {
		if (isEmpty()) {
			throw "Stack is empty";
		}
		return elems.first_value();
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

#endif