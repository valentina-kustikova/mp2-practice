#include "THeapSort.h"

void THeapSort::sort(size_t size, int* array)
{
    THeap<int> heap(2, size, size, array, false);
    for (size_t i = 0; i < size; i++)
    {
        heap.removeMinKey();
    }
}
