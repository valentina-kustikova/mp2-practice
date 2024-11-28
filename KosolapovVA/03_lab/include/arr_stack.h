#ifndef ARR_STACK_H
#define ARR_STACK_H

#include <stack.h>

template <typename T>
class ArrStack :public Stack<T>
{
private:
    int top;
    size_t max_sz;
    T* pMem;
public:
    ArrStack() :top(-1), max_sz(0), pMem(nullptr) {}

    ArrStack(int sz) :top(-1)
    {
        if (sz < 0)
            throw std::exception("Size cannot be negative");
        max_sz = sz;
        pMem = new T[sz];
    }

    ArrStack(const ArrStack& s) :top(s.top), max_sz(s.max_sz)
    {
        pMem = new T[max_sz];
        for (int i = 0; i < max_sz; i++)
        {
            pMem[i] = s.pMem[i];
        }
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

    const ArrStack<T>& operator=(const ArrStack<T>& s)
    {
        if (this != &s)
        {
            if (max_sz != s.max_sz)
            {
                if (max_sz != 0) {
                    delete[] pMem;
                }
                max_sz = s.max_sz;
                pMem = new T[max_sz];
            }
            top = s.top;
            for (int i = 0; i < max_sz; i++)
            {
                pMem[i] = s.pMem[i];
            }
        }
        return *this;
    }

    void Mirror_Stack()
    {
        ArrStack<T> temp(this->max_sz);
        while (!(this->IsEmpty()))
        {
            temp.Push(this->Top());
            this->Pop();
        }
        *this = temp;
    }
};

#endif // !ARR_STACK_H
