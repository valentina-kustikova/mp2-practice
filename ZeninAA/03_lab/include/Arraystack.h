#pragma once
#include "stack.h"
#include <iostream>
using namespace std;
template <typename TElem>
class Arraystack : public stack<TElem>
{
private:

    int maxSz;
    TElem* el;
    int top;


public:


    Arraystack(int maxSz)
    {
        if (maxSz <= 0)
        {
            throw "WRONG STACK SIZE";
        }
        this->maxSz = maxSz; 
        el = new TElem[maxSz];
        top = -1;
    }

    Arraystack(const Arraystack<TElem>& s) 
    {
        maxSz = s.maxSz;  
        el = new TElem[maxSz];
        top = s.top;
        for (int i = 0; i < maxSz; i++)
        {
            el[i] = s.el[i];
        }
    }

    ~Arraystack()
    {
        delete[] el;
    }

    void push(const TElem& n)
    {
        if (is_full())
        {
            throw "FULL STACK";
        }
        el[++top] = n;
    }


    TElem show_top()const
    {
        if (is_empty())
        {
            throw "EMPTY STACK";
        }
        return el[top];
    }


    void pop()
    {
        if (is_empty())
        {
            throw "EMPTY STACK";
        }
        top--;
    }

    bool is_full()const
    {
        return top == maxSz - 1;
    }

    bool is_empty()const
    {
        return top == -1;
    }

    const Arraystack <TElem>& operator= (const Arraystack <TElem>& s)
    {
        if (this == &s)
        {
            return *this;
        }
        if (maxSz != s.maxSz)
        {
            maxSz = s.maxSz;
            el = new TElem[maxSz];
        }
        top = s.top;
        for (int i = 0; i < top + 1; i++)
        {
            el[i] = s.el[i];
        }
        return *this;
    }

    bool operator == (const Arraystack <TElem>& s)const
    {
        if (top != s.top || maxSz != s.maxSz)
        {
            return 0;
        }
        for (int i = 0; i < top + 1; i++)
        {
            if (el[i] != s.el[i])
            {
                return 0;
            }
        }
        return 1;
    }

    bool operator != (const Arraystack <TElem>& s)const
    {
        return !(*this == s);
    }
};