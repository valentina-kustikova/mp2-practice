#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

using namespace std;

template <typename T> 
class TStack
{
private:
	int maxsize;
	int top;
	T* elems;
public:
	TStack(int maxsize = 10);
	TStack(const TStack& s);
	~TStack();
	bool  IsEmpty(void) const;
	bool IsFull(void) const;
	T Top() const;
	void Push(const T& e);
	void Pop();
};

//конструкторы 

template <typename T>
TStack<T>::TStack(int maxsize) {
	if (maxsize <= 0) {
		throw "maxsize < 0";
	}
	top = -1;
	this->maxsize = maxsize;
	elems = new T[maxsize];
}

template <typename T>
TStack<T>::TStack(const TStack<T>& s) {
	top = s.top;
	maxsize = s.maxsize;
	elems = new T[maxsize];
	for (int i = 0; i <= top; i++) {
		elems[i] = s.elems[i];
	}
}

//деструктор

template <typename T> 
TStack<T>:: ~TStack() {
	delete[] elems;
	maxsize = 0;
	top = -1;
}


//Проверка на пустоту и полноту

template <typename T>
bool TStack<T>::IsEmpty(void) const {
	if (top == -1) {
		return true;
	}
	return false;
}


template <typename T>
bool TStack<T>::IsFull(void) const {
	if (top == maxsize - 1) {
		return true;
	}
	return false;
}

//Получение верхнего элемента из стека

template <typename T>
T TStack<T>::Top() const {
	if (top != -1) {
		return elems[top];
	}
	else throw "stack is empty";
}

//Добавление элемента на верхушку стека

template <typename T>
void TStack<T>::Push(const T& e) {
	if (IsFull()) {
		T* tmp_elem = new T[maxsize + 10];
		for (int i = 0; i < maxsize; ++i) {
			tmp_elem[i] = elems[i];
		}
		delete[] elems;
		elems = tmp_elem;
		maxsize = maxsize + 10;
	}
	elems[++top] = e;
}

template <typename T>
void TStack<T>::Pop() {
	if (IsEmpty()) {
		throw "Stack is empty";
	}
	top -= 1;
}


#endif
