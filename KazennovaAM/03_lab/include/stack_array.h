#pragma once
#ifndef ARR_STACK_H
#define ARR_STACK_H

#include <stack.h>

template <typename T>
class Array_Stack :public Stack<T>
{
private:
	int top;
	size_t max_size;
	T* elems;
public:
	Array_Stack(int max_size = 100);
	Array_Stack(const Array_Stack<T>& s);
	~Array_Stack();

	void Push(const T&);//добавление в вершину
	T Top() const;//получение из верш
	void Pop();//удаление из верш
	bool IsFull() const;//проверка на поноту
	bool IsEmpty() const;//прверка на пустату
	Array_Stack<T>& operator=(const Array_Stack<T>& s);
	bool operator==(const Array_Stack<T>& other) const;

};


template <typename T>
Array_Stack<T> ::Array_Stack(int max_size = 10) {
	this->max_size = max_size;
	this->elems = new T[max_size];
	top = -1;
}


template <typename T>
Array_Stack<T> ::Array_Stack(const Array_Stack<T>& s) {
	max_size = s.max_size;
	top = s.top;
	elems = new T[max_size];
	for (int i = 0; i <= top; i++) {
		elems[i] = s.elems[i];
	}
}
template <typename T>
Array_Stack<T> ::~Array_Stack() {
	delete[] elems;
}

template <typename T>
bool Array_Stack<T>::IsFull() const {
	return (top == (max_size - 1));
}

template <typename T>
bool Array_Stack<T>::IsEmpty() const {
	return (top == - 1);
}

template <typename T>
void  Array_Stack<T>::Push(const T& elem) {
	if (IsFull()) {
		throw "Stack overflow";
	}
	elems[++top] = elem;
}

template <typename T>
T Array_Stack<T>::Top() const {
	if (IsEmpty()) {
		throw  "stack is empty";
	}
	return elems[top];
}

template <typename T>
void  Array_Stack<T>::Pop() {
	if (IsEmpty()) {
		throw  "Stack underflow";
	}
	top--;
}

template <typename T>
Array_Stack<T>& Array_Stack<T>::operator=(const Array_Stack<T>& s) {
	if (this == &s) {
		return *this;
	}
	if (max_size != s.max_size) {
		delete[] elems;
		max_size = s.max_size;
		elems = new T[max_size];
	}
	top = s.top;
	for (int i = 0; i <= top; ++i) {
		elems[i] = s.elems[i];
	}
	return *this;
}

template <typename T>
bool Array_Stack<T>::operator==(const Array_Stack<T>& other) const {
	if (max_size != other.max_size || top != other.top) {
		return false;
	}
	for (int i = 0; i <= top; ++i) {
		if (elems[i] != other.elems[i]) {
			return false;
		}
	}
	return true;
}
/*
template <typename T>
bool Array_Stack<T>::operator!= (const Array_Stack<T> &T) {
	return(*this == T);
}
*/

#endif // !ARR_STACK_H