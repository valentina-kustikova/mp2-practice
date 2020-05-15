#ifndef __HEAPSORT__H__
#define __HEAPSORT__H__

#include "TDHeap.h"

#define D 3

using namespace std;

template<typename T>
class HeapSort
{
public:
    static void Sort(T*, int);
};

template<typename T>
void HeapSort<T>::Sort(T* _arr, int _size)
{
    if (_size < 0)
        throw exception("Incorrect size");
    if (_arr == nullptr || _size == 0)
        throw exception("Array is empty");

    DHeap<T> heap(_size, _size, D, _arr);
    heap.heapify();

    for (int i = 0; i < _size; i++)
    {
        heap.removeMinKey();
    }
        
};

#endif