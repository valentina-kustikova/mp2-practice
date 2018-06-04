#pragma once
#include"PriorityQueue.h"
#include"Dheap.h"
template<typename T>
class DHeapBasePriorityQueue {
private:
	Dheap<T>*Dheap;
public:
	DheapBasePriorityQueue();
	virtual T get();
	virtual void put(T);
};

template<typename T>
DHeapBasePriorityQueue<T>::DheapBasePriorityQueue()
{
	Dheap = new Dheap<T>;
}

template<typename T>
T DHeapBasePriorityQueue<T>::get()
{
	T res = Dheap->getlast();
	Dheap->remove(Dheap->find(res));
	return res;
}

template<typename T>
void DHeapBasePriorityQueue<T>::put(T a)
{
	Dheap->insert(a);
}
