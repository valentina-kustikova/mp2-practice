#ifndef _TSTACK_H
#define _TSTACK_H

#include <iostream>
using namespace std;

template <typename T>
class TStack {
private:
	int maxSize;
	int top;
	T* elems;

	void Realloc(int extraSize = 10);
public:
	TStack(int _maxSize = 50);
	TStack(const TStack<T>& s, int extraSize = 0);
	virtual ~TStack();

	bool IsEmpty(void) const noexcept;
	bool IsFull(void) const noexcept;

	T Top();

	void Push(const T& e);
	void Pop();
};

template <typename T>
void TStack<T>::Realloc(int extraSize) {
	if (extraSize <= 0) {
		string exp = "Error: extraSize must be bigger than 0.";
		throw exp;
	}
	T* tmp = new T[maxSize + extraSize];
	for (int i = 0; i < maxSize; i++)
		tmp[i] = elems[i];

	delete[] elems;
	maxSize = maxSize + extraSize;
	elems = tmp;
}

template <typename T>
TStack<T>::TStack(int _maxSize) {
	if (_maxSize <= 0) {
		string exp = "Error: maxSize must be bigger than 0.";
		throw exp;
	}
	maxSize = _maxSize;
	top = -1;
	elems = new T[maxSize];
}
template <typename T>
TStack<T>::TStack(const TStack<T>& s, int extraSize) {
	if (extraSize < 0) {
		string exp = "Error: Stack extra size less than 0.";
		throw exp;
	}
	maxSize = s.maxSize + extraSize;
	top = s.top;
	elems = new T[maxSize];

	for (int i = 0; i <= top; i++)
		elems[i] = s.elems[i];
}
template <typename T>
TStack<T>::~TStack() {
	delete[] elems;
}

template <typename T>
bool TStack<T>::IsEmpty(void) const noexcept {
	return (top == -1);
}
template <typename T>
bool TStack<T>::IsFull(void) const noexcept {
	return (top == maxSize - 1);
}

template <typename T>
T TStack<T>::Top() {
	if (IsEmpty()) {
		string exp = "Error: stack is empty.";
		throw exp;
	}
	return elems[top];
}

template <typename T>
void TStack<T>::Push(const T& e) {
	//if (IsFull()) throw "Error: stack is full.";
	if (IsFull()) Realloc(maxSize / 2);
	elems[++top] = e;
}
template <typename T>
void TStack<T>::Pop() {
	if (IsEmpty()) {
		string exp = "Error: stack is empty.";
		throw exp;
	}
	top--;
}

#endif // !_TSTACK_H
