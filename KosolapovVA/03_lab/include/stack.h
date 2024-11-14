#ifndef Stack_H
#define Stack_H

#include <iostream>
template <typename T>
class Stack
{
public:
    virtual void Pop()=0;
    virtual void Push(const T&el)=0;
    virtual T Top()=0;
    virtual bool IsEmpty()=0;
    virtual bool IsFull()=0;
};

template <typename T>
class ArrStack :public Stack<T>
{
private:
    int top;
    size_t max_sz;
    T* pMem;
public:
    ArrStack():top(-1), max_sz(0){}

    ArrStack(int sz) :top(-1), max_sz(sz)
    {
        pMem = new T[sz];
    }

    ~ArrStack()
    {
        delete[] pMem;
    }

    void Pop()
    {
        if (IsEmpty())
            throw std::exception("Stack is Empty");
        top--;
    }

    void Push(const T& el)
    {
        if (IsFull())
        {
            max_sz = max_sz + 8;
            T* tmp = pMem;
            pMem = new T[max_sz];
            std::copy(tmp, tmp + max_sz, pMem);
        }
        top++;
        pMem[top] = el;
    }

    T Top()
    {
        if (IsEmpty())
            throw std::exception("Stack is Empty");
        return pMem[top];
    }

    bool IsEmpty() { return top == -1; }

    bool IsFull() { return top == (max_sz - 1); }
};

#endif 
