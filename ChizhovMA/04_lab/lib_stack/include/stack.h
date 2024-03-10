#ifndef Stack_H
#define Stack_H

#include <iostream>

using namespace std;

template <class T>
class TStack
{
private:
	int maxSize;
	int top;
	T* elems;
public:
	TStack(int maxSize = 10);
	TStack(const TStack<T>& s);
	~TStack();
	const TStack<T>& operator=(const TStack<T>& s);
	bool IsEmpty(void) const;
	bool IsFull(void) const;
	void ResizeStack();
	void ReverseStack();
	T Top() const;
	void Push(const T& elem);
	void Pop();

	friend ostream& operator <<(ostream& out, const TStack& s)
	{
		for (int i = 0; i <= s.top; i++)
			out << s.elems[i] << ' ';
		return out;
	};
};

template <class T>
TStack<T>::TStack<T>(int maxSize)
{
	if (maxSize <= 0)
	{
		string msg = "Error";
		throw msg;
	}
	this->maxSize = maxSize;
	top = -1;
	elems = new T[maxSize];
}

template <class T>
TStack<T>::TStack<T>(const TStack<T>& s)
{
	maxSize = s.maxSize;
	top = s.top;
	elems = new T[maxSize];
	for (int i = 0; i <= top; i++)
		elems[i] = s.elems[i];
}

template <class T>
TStack<T>::~TStack()
{
	delete[] elems;
}

template <class T>
const TStack<T>& TStack<T>::operator=(const TStack<T>& s)
{
	if (this == &s) {
		return *this;
	}

	delete[] elems;
	maxSize = s.maxSize;
	top = s.top;
	elems = new T[maxSize];
	for (int i = 0; i <= top; i++) {
		elems[i] = s.elems[i];
	}

	return *this;
}

template <class T>
bool TStack<T>::IsEmpty(void) const
{
	return (top == -1);
}

template <class T>
bool TStack<T>::IsFull(void) const
{
	if (maxSize - 1 == top)
		return true;
	return false;
}

template <class T>
void TStack<T>::ResizeStack()
{
	int newMaxSize = maxSize * 5; // Увеличиваем размер вдвое
	T* newElems = new T[newMaxSize]; // Создаем новый массив с увеличенным размером

	for (int i = 0; i <= top; i++)
		newElems[i] = elems[i]; // Копируем элементы из старого массива в новый

	delete[] elems; // Удаляем старый массив
	elems = newElems; // Указываем на новый массив
	maxSize = newMaxSize; // Обновляем значение maxSize
}

template <typename T>
void TStack<T>::ReverseStack()
{
	TStack<T> tempStack;
	while (!IsEmpty())
	{
		T element = Top();
		Pop();
		tempStack.Push(element);
	}

	*this = tempStack; // переприсваиваем tempStack в stack, чтобы поменять содержимое стека наоборот
}

template <class T>
T TStack<T>::Top() const
{
	if (top == -1)
	{
		string msg = "Error: stack is empty";
		throw msg;
	}
	return elems[top];
}

template <class T>
void TStack<T>::Push(const T& elem)
{
	if (IsFull())
		ResizeStack();
	elems[++top] = elem;
}

template <class T>
void TStack<T>::Pop()
{
	if (IsEmpty())
	{
		string msg = "Error: stack is empty";
		throw msg;
	}
	top -= 1;
}

#endif //TStack_H
