#include "stack.h"

template <typename T>
Stack<T>::Stack(int maxsize) {
    this->maxsize = maxsize;
    top = -1;
    this->elems = new T[maxsize];
}

template <typename T>
Stack<T>::Stack(const Stack& s) {
    this->maxsize = s.maxsize;
    elems = new T[this->maxsize];
    top = s.top;
    for (int i = 0; i <= top; i++) {
        elems[i] = s.elems[i];
    }
}

template <typename T>
Stack<T>::~Stack() {
    delete[] elems;
}

template <typename T>
bool Stack<T>::IsFull() const {
    return (top == maxsize);
}

template <typename T>
bool Stack<T>::IsEmpty() const {
    return (top == -1);
}

template <typename T>
void Stack<T>::Push(const T& val) {
    if (IsFull()) {
        throw std::exception("Full");
    }
    elems[++top] = val;
}

template <typename T>
void Stack<T>::Pop() {
    if (IsEmpty()) {
        throw std::exception("Empty");
    }
    top--;
}

template <typename T>
T Stack<T>::Top() const {
    if (IsEmpty()) {
        throw std::exception("Empty");
    }
    return elems[top];
}

template <typename T>
const Stack<T>& Stack<T>::operator = (const Stack<T>& s) {
    if (this == &s) {
        return *this;
    }
    if (this->maxsize != s.maxsize) {
        delete[] elems;
        maxsize = s.maxsize;
        elems = new T[maxsize];
        top = s.top;
        for (int i = 0; i <= top; i++) {
            elems[i] = s.elems[i];
        }
    }
    return *this;
}

template <typename T>
bool Stack<T>::operator==(const Stack<T>& s) const {
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
bool Stack<T>::operator!=(const Stack<T>& s) const {
    return !(*this == s);
}