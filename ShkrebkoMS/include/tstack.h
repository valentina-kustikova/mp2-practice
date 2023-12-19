	#ifndef _STACK_H
#define _STACK_H

#include <iostream>

using namespace std;

template <typename T> class Stack {
private:
	int top;
	int maxSize;
	T* elems;
public:
	Stack(int size = 10);
	Stack(const Stack<T>& s);
	~Stack();
	T Pop();
	T Top();
	void Push(const T e);
	bool IsFull()const { return top == maxSize - 1; }
	bool IsEmpty()const { return top == -1; }
	int GetTop() { return top; }




};

template <typename T>
Stack<T>::Stack(int size) {
	if (size <= 0) {
		throw "Negative or zero size!";
	}
	top = -1;
	maxSize = size;
	elems = new T[maxSize];
}




template <typename T>
Stack<T>::Stack(const Stack <T>& s) {
	top = s.top;
	maxSize = s.maxSize;
	elems = new T[maxSize];
	for (int i = 0; i <= top; i++) {
		elems[i] = s.elems[i];
	}
}

template <typename T>
Stack<T>::~Stack() {
	delete[] elems;
	maxSize = 0;
	top = -1;
}

template <typename T>
T Stack<T>::Top() {
	if (IsEmpty()) {
		throw "Stack is empty!";
	}
	else {
		return elems[top];
	}
}


template <typename T>
void Stack<T>::Push(const T e) {
	if (IsFull()) {
		throw "Stack is full!";
	}
	else {
		elems[++top] = e;
	}
}


template <typename T>
T Stack<T>::Pop() {
	if (IsEmpty()) {
		throw "Stack is empty!";
	}
	else {

		return elems[top--];
	}
}

#endif
