#ifndef _TSTACK_H
#define _TSTACK_H

using namespace std;

template <class Type>
class TStack {
private:
	int maxSize;
	int top;
	Type* elems;
public:
	TStack(int maxSize1 = 100);
	TStack(const TStack<Type>& s);
	~TStack();

	Type Top() const;

	bool IsEmpty() const;
	bool IsFull() const;

	void Push(const Type& elem);
	void Pop();
};

template <class Type>
TStack<Type>::TStack(int maxSize1)
{
	if (maxSize1 < 1) 
		throw exception("Size should be > 0");
	
	maxSize = maxSize1;
	elems = new Type[maxSize];
	top = -1;
}

template <class Type>
TStack<Type>::TStack(const TStack<Type>& s)
{


	maxSize = s.maxSize;
	top = s.top;

	elems = new Type[maxSize];
	for (int i = 0; i <= top; i++)
	{
		elems[i] = s.elems[i];
	}
}

template <class Type>
TStack<Type>::~TStack() 
{
	if (elems != nullptr)
		delete[] elems;
}

template <class Type>
bool TStack<Type>::IsFull() const 
{
	return top + 1 == maxSize;
}

template <class Type>
bool TStack<Type>::IsEmpty() const 
{
	return top == -1;
}

template <class Type>
Type TStack<Type>::Top() const
{
	if (top == -1)
		throw exception("Stack is empty");
	
	return elems[top];
}

template <class Type>
void TStack<Type>::Push(const Type& elem)
{
	if (top + 1 == maxSize)
		throw exception("Stack is full");
	elems[++top] = elem;
}

template <class Type>
void TStack<Type>::Pop() 
{
	if (top-- == -1)
		throw exception("Stack is empty");
}

#endif // !_TSTACK_H