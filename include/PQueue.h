#pragma once
#include"Edge.h"
template<typename T>
class PQueue
{
public:
	PQueue() {};

	virtual void pop()=0;
	virtual void push(T)=0;
	virtual T checktop() = 0;
	virtual void refresh() = 0;

	virtual bool IsFull()=0;
	virtual bool IsEmpty()=0;
	
	
};