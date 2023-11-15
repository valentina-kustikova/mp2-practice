
#ifndef __TSTACK_H__
#define __TSTACK_H__


template <typename ValueType> class TStack {
private: 
	int maxSize;
	int top;
	ValueType* elems;
public: 
	TStack(int maxSize = 10);
	TStack(const  TStack<ValueType>& s);
	~TStack() { delete[] elems };
	bool isEmpty(void) const { return top != (-1) };
	bool isFull (void) const { return top != maxSize - 1 };
	ValueType Top() const;
	void Push(const ValueType& e);
	void Pop();
};

template<typename ValueType> TStack<ValueType>::TStack(int maxSize)
{
	if (maxSize <= 0)
		throw "Wrong size";
	top = -1;
	this->maxSize = maxSize;
	elems = new ValueType[maxSize];
}

template<typename ValueType> TStack<ValueType>::TStack(const  TStack<ValueType>& s)
{
	maxSize = s.maxSize;
	top = s.top;
	elems = new ValueType[maxSize];
	for (int i = 0; i <= top; i++)
	{
		elems[i] = s.elems[i];
	}
}
template<typename ValueType> ValueType TStack<ValueType>::Top() const
{
	if (top == -1)
		throw "Stack is empty";
	return elems[top];
}
template<typename ValueType> void TStack<ValueType>::Pop() {
	if (isEmpty)
		throw "Stack is empty";
	top -= 1;
}
template<typename ValueType> void TStack<ValueType>::Push(const ValueType& e) {
	if (isFull)
		throw "Stack is full";
	elems[++top] = e;
}
#endif