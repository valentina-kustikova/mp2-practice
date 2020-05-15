#pragma once
#include "DHeap.h"

class HeapsortAlgorithm
{
public:
	template <typename TData>
	static void heapsort(DHeap<TData>& heap);
};

template<typename TData>
void HeapsortAlgorithm::heapsort(DHeap<TData>& heap)
{
	while (heap.size > 1)
	{
		heap.transpose(0, heap.size - 1);
		heap.size--;
		heap.dipDown(0);
	}
	heap.size = heap.max_size;
}
