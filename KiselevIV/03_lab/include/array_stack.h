#pragma once
#include "stack.h"
#include <iostream>
using namespace std;

template <typename TElem>
class array_stack : public stack<TElem>
{
private:
    int maxSize;
    TElem* elems;
    int top;
public:
    array_stack(int maxSize)
    {
        if (maxSize <= 0)
        {
            throw "stack shoud have positive size!";
        }
        this->maxSize = maxSize;
        elems = new TElem[maxSize];
        top = -1;
    }


    array_stack(const array_stack<TElem>& s)
    {
        maxSize = s.maxSize;
        elems = new TElem[maxSize];
        top = s.top;
        for (int i = 0; i < maxSize; i++)
        {
            elems[i] = s.elems[i];
        }
    }
    ~array_stack()
    {
        delete[] elems;
    }
    void push(const TElem& e)
    {
        if (is_full())
        {
            throw "stack is full";
        }
        elems[++top] = e;
    }
    TElem show_top()const
    {
        if (is_empty())
        {
            throw "stack is empty";
        }
        return elems[top];
    }
    void pop()
    {
        if (is_empty())
        {
            throw "stack is empty";
        }
        top--;
    }
    bool is_full()const
    {
        return top == maxSize - 1;
    }
    bool is_empty()const
    {
        return top == -1;
    }
    const array_stack <TElem>& operator = (const array_stack <TElem>& s)
    {
        if (this == &s)
        {
            return *this;
        }
        if (maxSize != s.maxSize)
        {
            maxSize = s.maxSize;
            elems = new TElem[maxSize];
        }
        top = s.top;
        for (int i = 0; i < top + 1; i++)
        {
            elems[i] = s.elems[i];
        }
        return *this;
    }
    bool operator == (const array_stack <TElem>& s)const
    {
        if (maxSize != s.maxSize || top != s.top)
        {
            return 0;
        }
        for (int i = 0; i < top + 1; i++)
        {
            if (elems[i] != s.elems[i])
            {
                return 0;
            }
        }
        return 1;
    }
    bool operator != (const array_stack <TElem>& s)const
    {
        return !(*this == s);
    }
};