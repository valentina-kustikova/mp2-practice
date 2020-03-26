#pragma once
#include"List.h"
template<typename ValType>
class TStack
{
public:
	virtual bool IsFull() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual void Push(ValType) = 0;
	virtual void Pop() = 0;
	virtual ValType Top() const = 0;
};
///////////////////////////////////
template<typename ValType>
class TArrayStack : public TStack<typename ValType>
{
private:
	int size;
	ValType * elements;
	int top;
public:
	TArrayStack(int _size = 15);
	TArrayStack(const TArrayStack<ValType>&);
	~TArrayStack();
	bool IsFull() const;
	bool IsEmpty() const;
	void Push(ValType);
	void Pop();
	ValType Top() const;
};

template <class ValType>
TArrayStack <ValType> ::TArrayStack(int _size)
{
	size = _size;
	top = -1;
	elements = new ValType[size];
	for (int i = 0; i < size; i++)
		elements[i] = 0;
}
template <class ValType>
TArrayStack <ValType> ::TArrayStack(const TArrayStack<ValType>& a)
{
	size = a.size;
	top = a.top;
	elements = new ValType[size];
	for (int i = 0; i < size; i++)
		elements[i] = a.elements[i];
}
template <class ValType>
TArrayStack<ValType>::~TArrayStack()
{
	size = 0;
	top = -1;
	delete[] elements;
}
template <class ValType>
bool TArrayStack<ValType>::IsFull() const
{
	return (top == size);
}
template <class ValType>
bool TArrayStack <ValType> ::IsEmpty() const
{
	return (top == -1);
}
template <class ValType>
void TArrayStack <ValType> ::Push(ValType a)
{
	if (IsFull())
		throw "Full Stack";
	elements[++top] = a;
}
template <class ValType>
void TArrayStack <ValType> ::Pop()
{
	if (IsEmpty())
		throw "Empty Stack";
	top--;
}
template <class ValType>
ValType TArrayStack <ValType> ::Top() const
{
	if (IsEmpty())
		throw "Empty Stack";
	return elements[top];
}
///////////////////////////////////
template<typename ValType>
class TListStack : public TStack<typename ValType>
{
private:
	TList<ValType, ValType>* list;
public:
	TListStack();
	TListStack(const TListStack<ValType>&);
	~TListStack();
	bool IsFull() const;
	bool IsEmpty() const;
	void Push(ValType);
	void Pop();
	ValType Top() const;
};
template<typename ValType>
TListStack<ValType>::TListStack()
{
	list = new TList<ValType, ValType>;
}
template<typename ValType>
TListStack<ValType>::TListStack(const TListStack<ValType>& copy)
{
	list = copy;
}
template<typename ValType>
TListStack<ValType>::~TListStack()
{
	delete[] list;
}
template<typename ValType>
bool TListStack<ValType>::IsFull() const
{
	TNode<ValType, ValType>* node = new TNode<ValType, ValType>;
	if (node)
	{
		delete node;
		return false;
	}
	else
		return true;
}
template<typename ValType>
bool TListStack<ValType>::IsEmpty() const
{
	return list->IsEnded();
}
template<typename ValType>
void TListStack<ValType>::Push(ValType key)
{
	if (IsFull())
		throw"cant complete push, full list";
	list->InsertStart(key, nullptr);
}
template<typename ValType>
void TListStack<ValType>::Pop()
{
	if (IsEmpty())
		throw"cant complete pop, empty list";
	list->Delete(list->Get_pFirst_key());
}
template<typename ValType>
ValType TListStack<ValType>::Top() const
{
	if (IsEmpty())
		throw"cant return top, empty list";
	return list->Get_pFirst_key();
}


