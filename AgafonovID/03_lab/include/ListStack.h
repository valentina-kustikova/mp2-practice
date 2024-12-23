#pragma once
#include "stack.h"
#include "list.h"

template <typename T>
class ListStack : public Stack<T> {
private:
    List<T> stack; 
public:
    ListStack() {};
    ListStack(const ListStack<T>& s);
    ~ListStack();
    bool IsEmpty() const;
    bool IsFull() const;

    void Push(const T& elem);
    void Pop();
    T Top() const;

    const ListStack<T>& operator=(const ListStack<T>& s);
};
