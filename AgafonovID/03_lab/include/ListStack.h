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

    bool IsEmpty() const { return stack.IsEmpty(); }
    bool IsFull() const { return false; }

    void Push(const T& elem);
    void Pop();
    T Top() const;

    const ListStack<T>& operator=(const ListStack<T>& s);
    bool operator==(const ListStack<T>& s);
};

template <typename T>
ListStack<T>::ListStack(const ListStack<T>& s) : stack(s.stack) {}

template <typename T>
ListStack<T>::~ListStack() {}

template <typename T>
void ListStack<T>::Push(const T& elem) {
    TNode<T>* Node = new TNode<T>(elem);
    stack.pushFront(Node);
}

template <typename T>
void ListStack<T>::Pop() {
    if (stack.IsEmpty()) {
        throw std::exception("Stack is empty");
    }
    stack.removefirst();
}

template <typename T>
T ListStack<T>::Top() const {
    if (stack.IsEmpty()) {
        throw std::exception("Stack is empty");
    }   
    return stack.reset();
}

template <typename T>
const ListStack<T>& ListStack<T>::operator=(const ListStack<T>& s) {
    if (this == &s) {
        return *this;
    }
    stack = s.stack;
    return *this;
}

template <typename T>
bool ListStack<T>::operator==(const ListStack<T>& s) {
    return (stack == s.stack);
}