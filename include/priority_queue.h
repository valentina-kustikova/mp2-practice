#pragma once
template <typename T>
class priority_queue
{
public:
	virtual bool is_full() const = 0;
	virtual bool is_empty() const = 0;
	virtual void push(T a) = 0;
	virtual T pop() = 0;
};
