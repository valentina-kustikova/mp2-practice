#ifndef ARR_STACK_H
#define ARR_STACK_H

#include <stack.h>

template <typename T>
class ArrayStack :public Stack<T>
{
private:
    int top;
    size_t max_size;
    T* pMem;
public:
    ArrayStack() :top(-1), max_size(0), pMem(nullptr) {}

    ArrayStack(int sz) :top(-1) 
    {
        if (sz < 0)
            throw std::exception("INVALID SIZE"); 
        max_size = sz; 
        pMem = new T[sz];
    }

    ArrayStack(const ArrayStack& s) :top(s.top), max_size(s.max_size)
    {
        pMem = new T[max_size];
        for (int i = 0; i < max_size; i++)
        {
            pMem[i] = s.pMem[i];
        }
    }

    ~ArrayStack()
    {
        delete[] pMem;
    }

    void Pop()
    {
        if (IsEmpty()) {
            throw std::exception("EMPTY");
        }
            
        top--;
    }

    void Push(const T& elem)
    {
        if (IsFull())
        {
            T* tmp = new T[max_size];
            std::copy(pMem, pMem + max_size, tmp);
            max_size += 8;
            pMem = new T[max_size];
            std::copy(tmp, tmp + max_size - 8, pMem);
        }
        top++; 
        pMem[top] = elem;
    }

    T Top()
    {
        if (IsEmpty()) {
            throw std::exception("EMPTY");
        }
            
        return pMem[top];
    }

    bool IsEmpty() { return top == -1; }

    bool IsFull() { return top == (max_size - 1); }  

    const ArrayStack<T>& operator=(const ArrayStack<T>& s)
    {
        if (this == &s)
        {
            return *this;
        }
        if (max_size != s.max_size)
        {
            if (max_size != 0) {
                delete[] pMem; 
            }
            max_size = s.max_size;
            pMem = new T[max_size];
        }
        top = s.top;
        for (int i = 0; i < max_size; i++)
        {
            pMem[i] = s.pMem[i];
        }
        return *this;
    }

    bool operator==(const ArrayStack<T>& s)
    {
        ArrayStack<T> tmp1(*this);
        ArrayStack<T> tmp2(s);
        if (top != s.top)
            return 0;
        if (tmp1.top != -1)
        {
            while (tmp1.top != -1)
            {
                if (tmp1.pMem[tmp1.top] != tmp2.pMem[tmp2.top])
                {
                    return 0;
                }
                tmp1.Pop();
                tmp2.Pop();
            }
        }
        return 1;
    }

};

#endif 