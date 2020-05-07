#include "HeapSort.h"

void PyramSort::Sort(float* arr, int size)
{
	if (arr == nullptr)
		throw  M_Exeption("Array is empty");
	if (size <= 0)
		throw  M_Exeption("Incorrect size");
	THeap<float> heap(2, size, size, arr);
	heap.Hilling();
	while (heap.GetSize() > 1)
		heap.RemoveMin();
}