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


    bool IsEmpty() const;
    bool IsFull() const;
    void push(const T& elem);
    void pop();
    T Top() const;

    const ListStack<T>& operator=(const ListStack<T>& s);

    size_t size() const;

    bool operator==(const ListStack<T>& s);


};

template <typename T>
ListStack<T>::ListStack() {
    elems = List<T>::List();
}

template <typename T>
size_t ListStack<T>::size() const {
    return elems.size();
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
        throw "stack is full";  // todo
    }
    elems.push(el);
}



template <typename T>
void ListStack<T>::pop() {
    if (IsEmpty())
    {
        throw "cant pop in empty stack"; // todo
    }
    elems.RemoveFirst();

}

template <typename T>
T ListStack<T>::Top() const {
    if (IsEmpty()) {
        throw "stack is empty";
    }
    return elems.get_val();
}


template <typename T>
bool ListStack<T>::IsEmpty() const { return elems.get_head() == nullptr; };

template <typename T>
bool ListStack<T>::IsFull() const {
    ListNode<int>* tmp;
    tmp = new ListNode<int>(1);
    if (tmp == nullptr)
    {
        return true;
    }
    delete tmp;
    return false;
};

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

template <typename T>
bool ListStack<T>::operator==(const ListStack<T>& s) {
    return elems == s.elems;


}