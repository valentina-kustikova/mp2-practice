#ifndef _TSTACK_
#define _TSTACK_

#include <iostream>

using namespace std;

template <class ValType>
class TStack {
private:
	ValType* elems;
	int MaxSize;
	int top;
public:
	TStack(int MaxSize = 10);
	TStack(const TStack<ValType>& s);
	~TStack();
	bool isEmpty()const; 
	bool isFull()const; 
	ValType Top()const;  
	void push(const ValType& elem);
	ValType Pop(); 
};

template <class ValType>
TStack<ValType>::TStack(int MaxSize)
{
	if (MaxSize < 0)
		throw "invalide size";
	top = -1;
	this->MaxSize = MaxSize;
	elems = new ValType[MaxSize];
}

template <class ValType>
TStack<ValType>::TStack(const TStack<ValType>& s)
{
	MaxSize = s.MaxSize;
	top = s.top;
	elems = new ValType[MaxSize];
	for (int i = 0; i <= top; i++)
		elems[i] = s.elems[i];
}

template <class ValType>
TStack<ValType>::~TStack()
{
	if (elems != nullptr)
		delete[] elems;
}

template <class ValType>
bool TStack<ValType>::isEmpty()const
{
	return top == -1;
}

template <class ValType>
bool TStack<ValType>::isFull()const
{
	return top + 1 == MaxSize;
}

template <class ValType>
ValType TStack<ValType>::Top()const
{
	if (top == -1)
		throw "stack is empty";
	return elems[top];
}

template <class ValType>
void TStack<ValType>::push(const ValType& elem)
{
	if (top + 1 == MaxSize)
		throw "stack is full";
	elems[++top] = elem;
}

template <class ValType>
ValType TStack<ValType>::Pop()
{
	if (top--  == -1)
		throw "stack is empty";
	return elems[top + 1];
}
#endif