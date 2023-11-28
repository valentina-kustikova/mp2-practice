#ifndef _TSTACK_H
#define _TSTACK_H

#include <iostream>
using namespace std;

template <typename T>
class TStack {

private:

	int maxSize;
	int top;
	T* elem;
	int step = 10;

public:

	TStack(int maxSize = 50);//конструктор
	TStack(const TStack<T>& s);//конструктор
	virtual ~TStack(); //деструктор
	void Realloc(int step);

	bool IsEmpty(void) const; // контроль пустоты
	bool IsFull(void) const; // контроль переполнения

	void Push(const T& Val);// добавить значение
	void Pop(void); // извлечь значение
	T Top();

};

template <typename T>
TStack <T> ::TStack(int maxSize)
{
	if (maxSize <= 0)
		throw"Error";
	this->maxSize = maxSize;
	top = -1;
	elem = new T[maxSize];
}

template <typename T>
TStack <T> ::TStack(const TStack<T>& s)
{
	maxSize = s.maxSize;
	top = s.top;
	elem = new T[maxSize];
	for (int i = 0; i <= top; i++)
		elem[i] = s.elem[i];
}

template <class T>
TStack <T>::~TStack()
{
	if (elem != NULL)
	{
		delete[] elem;
		elem = NULL;
		maxSize = 0;
	}
}

template <class T>
void TStack<T>::Realloc(int step)
{
	if (step <= 0)
		throw "Error";
	T* tmp = new T[step + maxSize];
	for (int i = 0; i < maxSize; i++)
		tmp[i] = elem[i];

	delete[] elem;
	elem = tmp;
	maxSize = maxSize + step;
}

template <class T>
bool TStack<T>::IsEmpty(void) const
{
	return(top == -1);
}

template <class T>
bool TStack<T>::IsFull(void) const
{
	return(top == maxSize - 1);
}

template <class T>
void TStack<T>::Push(const T& Val)
{
	if (IsFull())
	{
		Realloc(10);
	}
	top++;
	elem[top] = Val;
}

template <class T>
void TStack<T>::Pop(void)
{
	if (IsEmpty())
		throw "Error";
	top--;
}

template <class T>
T TStack<T>::Top()
{
	if (IsEmpty())
		throw "Error";
	return elem[top];

}

#endif