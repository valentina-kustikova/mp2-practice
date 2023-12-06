#ifndef _STACK_H
#define _STACK_H

#include <iostream>

using namespace std;

template <typename T> class Stack {
private:
	int top;
	int mem_size;
	T* pMem;
public:
	Stack(int size = 25);
	Stack(const Stack<T>& obj);
	~Stack();

	T Top();
	size_t Size()const noexcept { return top + 1; }
	int GetTop() { return top; }

	bool IsEmpty()const { return top == -1; }
	bool IsFull()const { return top == mem_size - 1; }

	void Push(const T val);
	T Pop();

	friend istream& operator>>(istream& istr, Stack<T>& st) {
		T elem;
		istr >> elem;
		st.Push(elem);
		return istr;
	}
};

template <typename T>
Stack<T>::Stack(int size) {
	if (size <= 0) {
		throw "Negative or zero size!";
	}
	top = -1;
	mem_size = size;
	pMem = new T[mem_size];
}




template <typename T>
Stack<T>::Stack(const Stack <T>& obj) {
	top = obj.top;
	mem_size = obj.mem_size;
	pMem = new T[mem_size];
	for(int i = 0; i <= top;i++){
		pMem[i] = obj.pMem[i];
	}
	cout << "Сработал конструктор копирования!" << endl;
}


template <typename T>
T Stack<T>::Top() {
	if (IsEmpty()) {
		throw "Stack is empty!";
	}
	else {
		return pMem[top];
	}
}


template <typename T>
void Stack<T>::Push(const T val) {
	if (IsFull()) {
		throw "Stack is full!";
	}
	else {
		pMem[++top] = val;
	}
}


template <typename T>
T Stack<T>::Pop() {
	if (IsEmpty()) {
		throw "Stack is empty!";
	}
	else {

		return pMem[top--];
	}
}

template <typename T>
Stack<T>::~Stack() {
	delete[] pMem;
	mem_size = 0; 
	top = -1;
	cout << "Сработал деструктор!" << endl;
}

#endif