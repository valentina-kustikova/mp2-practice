#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_
#include "THeap.h"

class HeapSort
{
public:
	template <typename TData>
	static void heapSort(THeap<TData> heap);
};

template<typename TData>
void HeapSort::heapSort(THeap<TData> heap)
{
	heap.hilling();
	while (heap.current_size > 1)
	{
		heap.transpose(0, heap.current_size - 1);
		heap.current_size--;
		heap.dipDown(0);
	}
}

#endif //!_HEAPSORT_H_
