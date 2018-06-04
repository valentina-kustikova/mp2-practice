#pragma once
#include"PQueue.h"
#include"Dheap.h"

using namespace std;

template <typename T>
class DQueue:public PQueue<T> {
private:
	Dheap<T>*heap;
public:
	DQueue(int);
	DQueue(Dheap<T>&);
	virtual ~DQueue() {};
	void print();
	
	void push(T);
	void pop();
	T checktop();
	bool IsFull();
	bool IsEmpty();
	void refresh();
};

template<typename T>
 DQueue<T>::DQueue(int d)
{
	 heap = new Dheap<T>(d);

}

 template<typename T>
DQueue<T>::DQueue(Dheap<T>& a)
 {
	heap = new Dheap<T>(a);
 }

template<typename T>
 void DQueue<T>::print()
{
	 heap->psevdoprint();
}

template<typename T>
void DQueue<T>::push(T elem)
{
	heap->insert(elem);
}

template<typename T>
void DQueue<T>::pop()

{
	if (heap->IsEmpty())
		throw"Pqueue is empty";
	 heap->remove(0);
}

 template<typename T>
 T DQueue<T>::checktop()
 {
	 return heap->checktop();
 }

 template<typename T>
 bool DQueue<T>::IsFull() {
	 if (heap->IsFull())
		 throw "Pqueue is full";
	 return heap->IsFull();

 }
 template<typename T>
 bool DQueue<T>::IsEmpty() {

	 return heap->IsEmpty();
 }

 template<typename T>
void DQueue<T>::refresh()
 {
	heap->hilling();
 }
