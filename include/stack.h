#pragma once
#include "list.h"
#include <iostream>
using namespace std;

template <typename T>
class stack
{
	list<T>* values;
public:
	stack();
	~stack();
	stack(const stack<T>& a);
	void Push(T a);
	void Pop();
	T Top();//h
	bool IsFull() const;
	bool IsEmpty() const;
};


template <typename T>
stack<T>::stack() {
	values = new list<T>();
};

template <typename T>
stack<T>::~stack() {
	delete values;
};

template <typename T>
stack<T>::stack(const stack<T>& a) {
	values = new list<T>(*(a.values));
};

template <typename T>
void stack<T>::Push(T a) {
	if (IsFull())
		throw "Stack is full";
	values->Add(a);
};

template <typename T>
void stack<T>::Pop() {
	if (IsEmpty())
		throw "Stack is empty";
	T key = values->GetRoot()->Key;//get-
	values->Remove(key);
}

template <typename T>
T stack<T>::Top() {
	return values->GetRoot()->Key;
}
;

template <typename T>
bool stack<T>::IsEmpty() const {
	return values->Size() == 0;
};

template <typename T>
bool stack<T>::IsFull() const {
	T Key = -1;
	try {
		values->Add(Key);
		values->Remove(Key);
	}
	catch (...) { return true; }
	return false;

};
