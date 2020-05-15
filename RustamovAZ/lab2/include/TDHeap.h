#ifndef __TDHEAP__H__
#define __TDHEAP__H__

#include <exception>
#include <cmath>
#include <algorithm>

using namespace std;

template<typename T>
class TDHeap
{
private:
    int base;
    int maxSize;
    int size;
    T* keys;
public:
    TDHeap(const TDHeap<T>& temp) = default;
    TDHeap(T * _keys, int _size, int _base = 2);
    ~TDHeap() = default;

    int GetSize() const;
    T GetMin() const;

    int minChild(int _parent)const;
    void Push(const T _newkey);
    void transpose(int a, int b);
    void shiftUp(int _key);
    void shiftDown(int _key);
    void removeMinKey();
    void heapify();
};

template<typename T>
TDHeap<T>::TDHeap(T* _keys, int _size, int _base)
{
    if (_size <= 0 || _base <= 0 || _keys == nullptr )
        throw exception("Incorrect input for DHeap");
    base = _base;
    maxSize = _size;
    size = _size;
    keys = _keys;
    heapify();
}

template<typename T>
int TDHeap<T>::GetSize() const
{
    return size;
}

template<typename T>
T TDHeap<T>::GetMin() const
{
    return keys[0];
}

template<typename T>
inline int TDHeap<T>::minChild(int parentKey) const
{
    if ((parentKey <= 0) || (parentKey > maxSize))
        throw std::exception("Key is out of range");
    if (parentKey * base + 1 >= size)
        return (-1);
    int childFirst = parentKey * base + 1;
    int childLast = min(parentKey * base + base, size - 1);
    int childMin = childFirst;
    for (int j = childFirst; j <= childLast; j++)
    {
        if (keys[childMin] > keys[j])
            childMin = j;
    }

    return childMin;
}

template<typename T>
inline void TDHeap<T>::Push(const T _newkey)
{
    keys[size++] = _newkey;
    heapify();
}

template<typename T>
void TDHeap<T>::transpose(int i, int j)
{
    if ((i < 0) || (i >= size) || (j < 0) || (j >= size))
        throw std::exception("Key is out of range");
    T tmp = keys[i];
    keys[i] = keys[j];
    keys[j] = tmp;
}

template<typename T>
void TDHeap<T>::shiftUp(int _key)
{
    if (_key < 0 || _key > size)
        throw std::exception("Key is out of range");
    while (_key > 0)
    {
        int parentKey = (_key - 1) / base;
        if (keys[parentKey] > keys[_key])
        {
            transpose(parentKey, _key);
            _key = parentKey;
        }
        else break;
    }
}

template<typename T>
void TDHeap<T>::shiftDown(int _key)
{
    if (_key < 0 || _key > size)
        throw std::exception("Key is out of range");
    int minChildKey = minChild(_key);
    while ((minChildKey != -1) && (keys[minChildKey] < keys[_key]))
    {
        transpose(minChildKey, _key);
        _key = minChildKey;
        minChildKey = minChild(_key);
    }
}

template<typename T>
void TDHeap<T>::removeMinKey()
{
    transpose(0, size - 1);
    size--;
    shiftDown(0);
}

template<typename T>
void TDHeap<T>::heapify()
{
    for (int i = size - 1; i >= 0; i--)
        shiftDown(i);
}

#endif 