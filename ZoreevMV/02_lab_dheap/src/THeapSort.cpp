#include "THeapSort.h"

void THeapSort::sort(size_t size, int* array)
{
    THeap<int> heap(size, size, array);
    for (size_t i = 0; i < size; i++)
    {
        heap.removeMinKey();
    }
}
