#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include "stack.h"
#pragma once

template <typename TElem> class array_stack : public Stack <TElem> {
private:
	int maxSize;
	TElem* elems;
	int top;
public:
	array_stack(int maxSize) {
		if (maxSize <= 0) {
			throw "Size can't be less than zero.";
		}
		this->maxSize = maxSize;
		elems = new TElem[maxSize];
		top = -1;
	}
	array_stack(const array_stack<TElem>& as) {
		maxSize = as.maxSize;
		elems = new TElem[maxSize];
		top = as.top; 
		for (int i = 0; i < maxSize; i++) {
			elems[i] = as.elems[i];
		}
	}
	~array_stack() {
		delete [] elems;
	}
	bool isEmpty() const {
		return top == -1;
	}
	bool isFull() const {
		return top == maxSize - 1;
	}
	void push(const TElem& e) {
		if (isFull()) {
			throw "Stack is full.";
		}
		elems[++top] = e;
	}
	void pop() {
		if (isEmpty()) {
			throw "Stack is empty.";
		}
		top--;
	}
	TElem showTop() const {
		if (isEmpty()) {
			throw "Stack is empty";
		}
		return elems[top];
	}
	const array_stack <TElem>& operator= (const array_stack <TElem>& as) {
		if (this == &as) {
			return *this;
		}
		if (maxSize != as.maxSize) {
			maxSize = as.maxSize;
			elems = new TElem[maxSize];
		}
		top = as.top;
		for (int i = 0; i < top + 1; i++) {
			elems[i] = as.elems[i];
		}
		return *this;
	}
	bool operator== (const array_stack <TElem>& as) const {
		if (maxSize != as.maxSize || top != as.top) {
			return 0;
		}
		for (int i = 0; i < top + 1; i++) {
			if (elems[i] != as.elems[i]) {
				return 0;
			}
		}
		return 1;
	}
	bool operator!= (const array_stack <TElem>& as) const {
		return !(*this == as);
	}
};

#endif