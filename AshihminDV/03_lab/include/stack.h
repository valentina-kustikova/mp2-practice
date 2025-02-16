#pragma once
const int MAX_STACK_SIZE = 100;

template<typename TElem>
class Stack
{
public:
	virtual ~Stack() {};
	virtual void Push(const TElem& el) = 0;
	virtual TElem Top() const = 0;
	virtual void pop() = 0;
	virtual bool is_full() const = 0;
	virtual bool is_empty() const = 0;
};