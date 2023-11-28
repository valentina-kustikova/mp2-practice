#ifndef _STACK_H
#define _STACK_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
const int _maxSize = 25;

template <typename T>
class TStack {
private:
	int maxSize;
	int top;
	T* elems;
public:
	TStack(int Size=_maxSize);
	TStack(const TStack<T>& stack);
	~TStack();
	T Pop();
	T Top() const;
	void Push(const T& elm);
	bool IsEmpty(void) const;
	bool IsFull(void) const;
};

template <typename T>
TStack<T>::TStack( int Size) {
	if (Size <= 0) throw "maxSize must be bigger than 0.";
	maxSize = Size;
	top = -1;
	elems = new T[maxSize];
}

template <typename T>
TStack<T>::TStack(const TStack<T>& stack) {
	maxSize = stack.maxSize;
	top = stack.top;
	elems = new T[maxSize];
	for (int i = 0; i <= top; i++) {
		elems[i] = stack.elems[i];
	}
}

template <typename T>
TStack<T>::~TStack() {
	delete[] elems;
	top = -1;
	maxSize = 0;
}

template <typename T>
bool TStack<T>::IsFull(void) const {
	return (top == maxSize - 1);
}

template <typename T>
bool TStack<T>::IsEmpty(void) const {
	return (top == -1);
}

template <typename T>
T TStack<T>::Top() const {
	if (IsEmpty()) { throw "Stack is empty."; }
	else {
		return elems[top]; 
	}
}

template <typename T>
void TStack<T>::Push(const T& elm) {
	if (IsFull()) throw "Stack is full.";
	else { elems[++top] = elm; }
}

template <typename T>
T TStack<T>::Pop() {
	if (IsEmpty()) {
		throw "Stack is empty!";
	}
	else {

		return elems[top--];
	}
}

#endif 