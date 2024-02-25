#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

template <typename ValueType>
class TStack {
private:
	size_t maxSize;
	int top;
	ValueType* elems;
public:
	TStack(size_t maxSize = 10);
	TStack(const TStack<ValueType>& s);
	~TStack();
	void Push(const ValueType& e);
	void Pop();
	ValueType Top() const;
	bool IsEmpty() const;
};

template <typename ValueType>
TStack<ValueType>::TStack(size_t _maxSize) {
	if (maxSize <= 0)
		throw std::exception("negative or zero max size");
	maxSize = _maxSize;
	top = -1;
	elems = new ValueType[maxSize];
}

template <typename ValueType>
TStack<ValueType>::TStack(const TStack<ValueType>& s) {
	maxSize = s.maxSize;
	top = s.top;
	elems = new ValueType[maxSize];
	for (int i = 0; i < maxSize; i++)
		elems[i] = s.elems[i];
}

template <typename ValueType>
TStack<ValueType>::~TStack<ValueType>() {
	delete[] elems;
}

template <typename ValueType>
void TStack<ValueType>::Push(const ValueType& e) {
	if (top == maxSize - 1) {
		ValueType* tmp = new ValueType[maxSize * 2];
		std::copy(elems, elems + maxSize, tmp);
		delete[] elems;
		elems = tmp;
		maxSize *= 2;
	}
	elems[++top] = e;
}

template <typename ValueType>
void TStack<ValueType>::Pop() {
	if (IsEmpty())
		throw std::exception("got empty stack");
	top--;
}

template <typename ValueType>
ValueType TStack<ValueType>::Top() const {
	if (IsEmpty())
		throw std::exception("got empty stack");
	return elems[top];
}

template <typename ValueType>
bool TStack<ValueType>::IsEmpty() const {
	return (top == -1);
}

#endif
