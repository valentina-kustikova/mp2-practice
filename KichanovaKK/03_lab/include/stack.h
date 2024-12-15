#pragma once
#include <iostream>

using namespace std;
template<typename T>

class stack { //объ€влени€ отдельно
private:
    size_t maxsize;
    int top;
    T* elem;
public:
    stack(int _maxsize = 1) :top(-1), maxsize(_maxsize), elem(new T[maxsize]) {}
    stack(const stack& s) {
        maxsize = s.maxsize;
        elem = new T[maxsize];
        top = s.top;
        for (int i = 0; i <= top; i++) {
            elem[i] = s.elem[i];
        }
    }
    ~stack() {
        delete[]elem;
    }
    bool IsEmpty() const {
        return top == -1;
    }
    bool IsFull() const {
        return top == maxsize - 1;
    }
    void Push(const T& val) {
        if (IsFull()) {
            T* tmp = new T[maxsize * 2];
            std::copy(elem, elem + maxsize, tmp);
            delete[]elem;
            elem = tmp;
            maxsize *= 2;
        }
        elem[++top] = val;
    }
    T Top() const {
        if (IsEmpty())
            throw("Stack is Empty");
        return elem[top];
    }
    void Pop() {
        if (IsEmpty())
            throw("Stack is Empty");
        top--;
    }
    const stack<T>& operator=(const stack<T>& s)
    {
        if (this == &s)
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
};