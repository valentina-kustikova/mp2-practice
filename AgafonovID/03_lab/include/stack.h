#pragma once

#include <iostream>

template<typename T>
class Stack {
private:
    int maxsize;
    int top;
    T* elems;
public:
    Stack(int maxsize);
    Stack(const Stack& s);
    ~Stack();
    const Stack<T>& operator=(const Stack<T>& s);

    void Push(const T& val);
    void Pop();
    T Top() const;

    bool IsFull() const;
    bool IsEmpty() const;

    bool operator==(const Stack<T>& s) const;
    bool operator!=(const Stack<T>& s) const;
};