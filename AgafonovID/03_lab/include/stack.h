#pragma once

#include <iostream>
#include <string>

template <typename T>
class Stack {
public:
    virtual void Push(const T& val) = 0;
    virtual void Pop() = 0;
    virtual T Top() const = 0;
    virtual bool IsFull() const = 0;
    virtual bool IsEmpty() const = 0;
};
