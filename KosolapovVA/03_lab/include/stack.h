#ifndef Stack_H
#define Stack_H

#include <iostream>
template <typename T>
class Stack
{
protected:
    T* pMem;
    int top;
public:
    Stack(int i);
    ~Stack();
    void Pop();
    void Push(T el);
    bool IsEmpty();
};
#endif 
