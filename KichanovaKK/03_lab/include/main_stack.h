#pragma once
template <typename T>
class MainStack {
public:
    virtual void Push(const T& val) = 0;
    virtual T Pop() = 0;
    virtual T Top() const = 0;
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
};