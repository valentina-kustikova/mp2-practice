#include "stdafx.h"
#include "THeapSort.h"

void THeapSort::Heap_sort(double* array, int size)
{
	THeap<double> heap(array, size, size, 2); // ������� ���� � �������� 2
	heap.Heaping();
	for (int i = 0; i < size; i++)
	{
		array[i] = heap.GetMinKey();
	}
	// ����� ����� ��������� ������ array, ��������������� �� �����������
}