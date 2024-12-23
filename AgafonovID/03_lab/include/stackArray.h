#pragma once
#include <iostream>
#include "stack.h"

template<typename T>
class stackArray : public Stack<T> {
private:
    int maxsize;
    int top;
    T* elems;
public:
    stackArray();
    stackArray(int maxsize);
    stackArray(const stackArray& s);
    ~stackArray();
    const stackArray<T>& operator=(const stackArray<T>& s);
    void Push(const T& val);
    void Pop();
    T Top() const;
    int Size() const;

    bool IsFull() const;
    bool IsEmpty() const;

    bool operator==(const stackArray<T>& s) const;
    bool operator!=(const stackArray<T>& s) const;

};