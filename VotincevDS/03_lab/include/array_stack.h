#pragma once
#include <iostream>
#include "stack.h"


template <typename T>
class ArrayStack : public Stack<T> {
private:
    int top;
    size_t maxsz;
    T* arr;
public:
    ArrayStack();
    ArrayStack(int sz);
    ArrayStack(const ArrayStack<T>& s);
    ~ArrayStack();

    bool IsEmpty() const;
    bool IsFull() const;
    void push(const T& elem);
    void pop();
    T Top() const;
    const ArrayStack<T>& operator=(const ArrayStack<T>& s);
    bool operator==(const ArrayStack<T>& s);
};





template <typename T>
ArrayStack<T>::ArrayStack() : top(-1), maxsz(0), arr(nullptr) {};

template <typename T>
ArrayStack<T>::ArrayStack(int sz) : top(-1) {
    if (sz <= 0) {
        throw "size must be greater than 0";
    }
    maxsz = sz;
    arr = new T[sz];
}



template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& s) {
    top = s.top;
    maxsz = s.maxsz;
    arr = new T[maxsz];
    for (int i = 0; i < maxsz; i++) {
        arr[i] = s.arr[i];
    }
}




template <typename T>
ArrayStack<T>::~ArrayStack() {
    delete[] arr;
}

template <typename T>
bool ArrayStack<T>::IsEmpty() const { return top == -1; };

template <typename T>
bool ArrayStack<T>::IsFull() const { return top == maxsz - 1; };





template <typename T>
void ArrayStack<T>::push(const T& elem) {

    if (IsFull()) {

        T* tmp = arr;
        arr = new T[(maxsz + 1) * 3];
        std::copy(tmp, tmp + maxsz, arr);
        maxsz = (maxsz + 1) * 3;
    }

    top++;
    arr[top] = elem;

}

template <typename T>
void ArrayStack<T>::pop() {
    if (IsEmpty()) {
        throw "stack is empty";
    }
    top--;
}

template <typename T>
T ArrayStack<T>::Top() const {

    if (IsEmpty()) {
        throw "stack is empty";
    }
    return arr[top];

}

template <typename T>
const ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& s) {

}

template <typename T>
bool ArrayStack<T>::operator==(const ArrayStack<T>& s) {

}

