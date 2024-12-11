#pragma once

template <typename T>
class Stack {
public:
    virtual void push(const T& elem) = 0;
    virtual void pop() = 0;
    virtual T Top() const = 0;
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
};


// тут все сделано


