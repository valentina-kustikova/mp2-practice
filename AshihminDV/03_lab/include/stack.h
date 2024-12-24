#pragma once
const int MAX_STACK_SIZE = 100;

template<typename TElem>
class Stack
{
public:
	virtual void Push(const TElem& el) = 0;
	virtual TElem Top() const = 0;
	virtual void pop() = 0;
	virtual bool is_full() const = 0;
	virtual bool is_empty() const = 0;
};

//array stack 

template<typename TElem>
class array_stack : public Stack<TElem>
{
	TElem* elems;
	size_t max_size;
	int top;
public:
	array_stack();
	array_stack(int sz);
	~array_stack();

	void Push(const TElem& el);
	TElem Top() const;
	void pop();
	bool is_full() const;
	bool is_empty() const;
	array_stack& operator=(array_stack<TElem>& st);
};
template<typename TElem>
array_stack<TElem>::array_stack() : max_size(0), top(-1), elems(nullptr)
{ }

template<typename TElem>
array_stack<TElem>::array_stack(int sz) : top(-1)
{
	if (sz < 1)
	{
		throw "Array_stack must be > 0";
	}
	this->max_size = sz;
	this->elems = new TElem[sz];
}
template<typename TElem>
array_stack<TElem>::~array_stack()
{
	if (elems != nullptr)
	{
		delete[] elems;
	}
}

template<typename TElem>
void array_stack<TElem>::Push(const TElem& el)
{
	if (this->is_full())
	{
		throw "Stack is full";
	}
	this->elems[++top] = el;
}

template<typename TElem>
TElem array_stack<TElem>::Top()const
{
	if (this->is_empty())
	{
		throw "Stack is empty";
	}
	return this->elems[top];
}

template<typename TElem>
void array_stack<TElem>::pop()
{
	if (this->is_empty())
	{
		throw "Stack is empty";
	}
	top--;
}

template<typename TElem>
bool array_stack<TElem>::is_full()const
{
	if (this->top == (this->max_size - 1))
	{
		return true;
	}
	return false;
}
template<typename TElem>
bool array_stack<TElem>::is_empty()const
{
	if (top == -1)
	{
		return true;
	}
	return false;
}

template<typename TElem>
array_stack<TElem>& array_stack<TElem>::operator=(array_stack<TElem>& st)
{
	if (this == &st)
	{
		return *this;
	}
	if (st.max_size != this->max_size)
	{
		delete[]elems;
		this->max_size = st.max_size;
		this->elems = new TElem[max_size];
		this->top = st.top;
	}
	for (int i = 0; i < this->top; i++)
	{
		this->elems[i] = st.elems[i];
	}
	return *this;
}

