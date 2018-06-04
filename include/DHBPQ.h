#pragma once
#include "priority_queue.h"
#include "dheap.h"

template <typename T>
class DHBPQ : public priority_queue<T>
{
	dheap<T> heap;
public:
	DHBPQ() = default;
	DHBPQ(vector<T> elems, int d);
	bool is_full() const override;
	bool is_empty() const override;
	void push(T a) override;
	T pop() override;
};

template <typename T>
DHBPQ<T>::DHBPQ(vector<T> elems, int d) {
	heap = dheap<T>(elems, d);
}

template <typename T>
bool DHBPQ<T>::is_full() const {
	return false;
}

template <typename T>
bool DHBPQ<T>::is_empty() const {
	return heap.is_empty();
}

template <typename T>
void DHBPQ<T>::push(T a) {
	heap.insert(a);
}

template <typename T>
T DHBPQ<T>::pop() {
	T a = heap.get_min_value();
	return a;
}
