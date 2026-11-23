#ifndef __STACK_H__
#define __STACK_H__
#include<stdexcept>

template<typename T>
class Stack
{
	size_t size;
	int top_index;
	T* st;
public:
	Stack(int sz)
		:top_index(-1)
	{
		if (sz <= 0)
			throw std::invalid_argument("Stack size should be greater than zero");
		size = static_cast<size_t>(sz);
		st = new T[size];
	}

	Stack(const Stack& s)
		:size(s.size), top_index(s.top_index), st(new T[size])
	{
		for (int i = 0; i <= top_index; i++)
		{
			st[i] = s.st[i];
		}
	}

	Stack(Stack&& s)
		:size(s.size), top_index(s.top_index), st(s.st)
	{
		s.size = 0; s.top_index = -1;
		s.st = nullptr;
	}

	~Stack()
	{
		size = 0; top_index = -1;
		delete[]st;
	}

	bool is_full() const
	{ 
		return top_index == size - 1; 
	}

	bool is_empty() const
	{
		return top_index == -1; 
	}
	
	void push(const T& x)
	{
		if (is_full()) throw std::out_of_range("Stack overflow");
		st[++top_index] = x;
	}

	void pop()
	{
		if (is_empty()) throw std::out_of_range("Stack is empty");
		top_index--;
	}

	T top() const
	{
		if (is_empty()) throw std::out_of_range("Stack is empty");
		return st[top_index];
	}

	const Stack& operator=(const Stack& s)
	{
		if (this == &s) return *this;
		if (s.size != size)
		{
			T* tmp = new T[s.size];
			delete[]st;
			st = tmp;
			size = s.size; 
		}
		top_index = s.top_index;
		for (int i = 0; i <= top_index; i++)
		{
			st[i] = s.st[i];
		}
		return *this;
	}

	Stack& operator=(Stack&& s)
	{
		if (this == &s) return *this;
		delete[]st;
		st = s.st; s.st = nullptr;
		size = s.size; s.size = 0;
		top_index = s.top_index;
		s.top_index = -1;
		return *this;
	}
	
	bool operator==(const Stack& s) const
	{
		if (this == &s) return true;
		if (size != s.size) return false;
		if (top_index != s.top_index) return false;
		for (int i = 0; i <= top_index; i++)
		{
			if (st[i] != s.st[i]) return false;
		}
		return true;
	}

	bool operator!=(const Stack& s) const
	{
		return !(*this == s);
	}
};

#endif