#pragma once
#include <iostream>
#include "main_stack.h"


using namespace std;
template<typename T>

class stack : public MainStack<T> {
private:
    size_t maxsize;
    int top;
    T* elem;
public:
    stack(int _maxsize = 1) :top(-1), maxsize(_maxsize), elem(new T[maxsize]) {}
    stack(const stack& s);
    ~stack();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(const T& val);
    T Top() const;
    T Pop();
    const stack<T>& operator=(const stack<T>& s);
};

template<typename T>
stack<T>::stack(const stack& s) {
    maxsize = s.maxsize;
    elem = new T[maxsize];
    top = s.top;
    for (int i = 0; i <= top; i++) {
        elem[i] = s.elem[i];
    }
}
template<typename T>
stack<T>::~stack() {
    delete[]elem;
}
template<typename T>
bool stack<T>:: IsEmpty() const {
    return top == -1;
}
template<typename T>
bool stack<T>::IsFull() const {
    return top == maxsize - 1;
}
template<typename T>
void stack<T>::Push(const T& val) {
    if (IsFull()) {
        T* tmp = new T[maxsize * 2];
        std::copy(elem, elem + maxsize, tmp);
        delete[]elem;
        elem = tmp;
        maxsize *= 2;
    }
    elem[++top] = val;
}
template<typename T>
T stack<T>::Top() const {
    if (IsEmpty())
        throw("Stack is Empty");
    return elem[top];
}
template<typename T>
T stack<T>::Pop() {
    if (IsEmpty())
        throw("Stack is Empty");
    return elem[top--];
}
template<typename T>
const stack<T>& stack<T>:: operator=(const stack<T>& s)
{
    if (this != &s)
    {
        return *this;
    }
    if (maxsize != s.maxsize)
    {
        delete[] elem;
        maxsize = s.maxsize;
        elem = new T[maxsize];
    }
    top = s.top;
    for (int i = 0; i <= top; i++)
    {
        elem[i] = s.elem[i];
    }

    return *this;
}