#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_
#include "DHeap.h"

template<class T>
class Heapsort
{
public:
    static void HeapSort(T*, int n);
};

template<class T>
void Heapsort<T>::HeapSort(T* a, int n)
{
    TDHeap<T> heap(n, 3, a, n);
    heap.Hilling();

    for(int i = 0; i < n; i++)
        heap.DeleteMin();
};

#endif
