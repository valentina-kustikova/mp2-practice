#pragma once
#include <iostream>
#include "List.h"


using namespace std;

template <typename Tkey>
class Stack
{
private:
	List<Tkey>*elems;
public:
	Stack();//конструктор по умолчанию
	Stack(const Stack&);//конструктор копирования
	~Stack();//деструктор
	void Push(Tkey a);//добавление элемента в стек
	Tkey Pop();//изъятие элемента из стека
	bool IsFull()const;//проверка стека на полноту
	bool IsEmpty()const;//проверка стека на пустоту
	int Size()const;//количество элементов в стеке
	Tkey checktop();//возвращает значение верхнего элемента
	List<Tkey>* GetList();//доступ к elems 
};



template <typename Tkey>
List<Tkey>* Stack<Tkey>::GetList()
{
	return elems;
}

template <typename Tkey>
int Stack<Tkey>::Size()const
{
	return elems->Size();
};

template <typename Tkey>
Tkey Stack<Tkey>::checktop()
{

	if (IsEmpty())
		return '!';
	Tkey res = elems->GetRoot()->Key;
	return res;
};

template <typename Tkey>
Stack<Tkey>::Stack()
{
	elems = new List<Tkey>;
};

template <typename Tkey>
Stack<Tkey>::~Stack()
{
	elems->~List();
};
template <typename Tkey>
bool Stack<Tkey>::IsEmpty()const
{
	return (elems->Size() == 0);
}


template <typename Tkey>
bool Stack<Tkey>::IsFull()const
{
	Tkey Key = 1;
	try
	{
		elems->insertbegin(Key);
		elems->remove(Key);
	}
	catch (...)
	{
		return true;
	}
	return false;

};

template <typename Tkey>
void Stack<Tkey>::Push(Tkey a)
{
	if (IsFull()) {
		throw "Stack is full";
	}
	elems->insertbegin(a);
}

template <typename Tkey>
Tkey Stack<Tkey>::Pop()
{
	if (IsEmpty())
		throw "Stack is empty";
	Tkey Key = elems->GetRoot()->Key;
	elems->remove(Key);
	return Key;
};

template <typename Tkey>
Stack<Tkey>::Stack(const Stack& a)
{
	elems = new List<Tkey>;
	elems(a->GetList());
};