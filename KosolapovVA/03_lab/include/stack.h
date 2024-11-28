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
#endif 
