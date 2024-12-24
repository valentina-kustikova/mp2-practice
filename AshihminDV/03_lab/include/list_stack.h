#pragma once
#include <iostream>
#include <string>
#include "stack.h"
#include "list.h"


template <typename T>
class ListStack : public Stack<T> {
private:
    List<T> elems;
public:
    ListStack();
    ListStack(const ListStack<T>& s);
    ~ListStack();

    void push(const T& elem);
    void pop();
    T Top() const;
    bool is_empty() const;
    bool is_full() const;
    const ListStack<T>& operator=(const ListStack<T>& s);
};

template <typename T>
ListStack<T>::ListStack() {
    elems = List<T>::List();
}

template <typename T>
ListStack<T>::ListStack(const ListStack<T>& s) {
    if (s.elems.get_head() == nullptr) {
        return;
    }
    elems = List<T>(s.elems);

};

template <typename T>
ListStack<T>::~ListStack() {
    while (!IsEmpty()) {
        pop();
    }
}


template <typename T>
void ListStack<T>::push(const T& el) {
    if (IsFull())
    {
        throw "stack is full";
    }
    elems.insert_Front(el);
}



template <typename T>
void ListStack<T>::pop() {
    if (IsEmpty())
    {
        throw "cant pop in empty stack";
    }
    elems.RemoveFirst();
}

template <typename T>
T ListStack<T>::Top() const {
    if (IsEmpty()) {
        throw "stack is empty";
    }
    return elems.get_head()->val;
}


template <typename T>
bool ListStack<T>::is_empty() const { return elems.get_head() == nullptr; };

template <typename T>
bool ListStack<T>::is_full() const {
    return false;
};
//??

template <typename T>
const ListStack<T>& ListStack<T>::operator=(const ListStack<T>& s) {
    if (this == &s) {
        return *this;
    }

    if (!IsEmpty()) {
        delete this;
    }

    elems = List<T>(s.elems);
    return *this;
}