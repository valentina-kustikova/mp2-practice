#include "stackArray.h"

template <typename T>
stackArray<T>::stackArray() : top(-1), maxsize(0), elems(nullptr) {};

template <typename T>
stackArray<T>::stackArray(int maxsize) {
    this->maxsize = maxsize;
    top = -1;
    this->elems = new T[maxsize];
}

template <typename T>
stackArray<T>::stackArray(const stackArray& s) {
    top = s.top;
    this->maxsize = s.maxsize;
    elems = new T[this->maxsize];
    for (int i = 0; i <= top; i++) {
        elems[i] = s.elems[i];
    }
}

template <typename T>
stackArray<T>::~stackArray() {
    delete[] elems;
}

template <typename T>
bool stackArray<T>::IsFull() const {
    return (top == maxsize - 1);
}

template <typename T>
bool stackArray<T>::IsEmpty() const {
    return (top == -1);
}

template <typename T>
void stackArray<T>::Push(const T& val) {
    if (IsFull()) {
        throw std::exception("Full");
    }
    elems[++top] = val;
}

template <typename T>
void stackArray<T>::Pop() {
    if (IsEmpty()) {
        throw std::exception("Empty");
    }
    top--;
}

template <typename T>
T stackArray<T>::Top() const {
    if (IsEmpty()) {
        throw std::exception("Empty");
    }
    return elems[top];
}

template <typename T>
const stackArray<T>& stackArray<T>::operator = (const stackArray<T>& s) {
    if (this == &s) {
        return *this;
    }
    if (this->maxsize != s.maxsize) {
        delete[] elems;
        maxsize = s.maxsize;
        elems = new T[maxsize];
    }
    top = s.top;
    for (int i = 0; i <= top; i++) {
        elems[i] = s.elems[i];
    }
    return *this;
}

template <typename T>
bool stackArray<T>::operator==(const stackArray<T>& s) const {
    if (this->maxsize != s.maxsize || this->top != s.top) {
        return false;
    }
    for (int i = 0; i < this->maxsize; i++) {
        if (this->elems[i] != s.elems[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool stackArray<T>::operator!=(const stackArray<T>& s) const {
    return !(*this == s);
}

template <typename T>
int stackArray<T>::Size() const {
    return top + 1;
}