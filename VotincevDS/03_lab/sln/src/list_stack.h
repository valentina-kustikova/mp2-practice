#pragma once
#include <iostream>
#include <string>
#include "stack.h"
#include "list.h"

#define MAX_SIZE 100000

template <typename T>
class ListStack : public Stack<T> {
private:
    List<T>* elems; // List<T> elems;
public:
    ListStack() : elems(nullptr) {}

    ListStack(const ListStack<T>& s);


    ~ListStack();

    void push(const T& el);

    void pop();

    T Top();


    bool IsEmpty();
    bool IsFull();

    const ListStack<T>& operator=(const ListStack<T>& s);


    bool operator==(const ListStack<T>& s);


};



template <typename T>
ListStack<T>::ListStack(const ListStack<T>& s) { 
    if (s.elems == nullptr) {
        elems = nullptr;
        return;
    }
    elems = new ListNode<T>(s.elems->val);
    ListNode<T>* elemscurr = elems;
    ListNode<T>* scurr = s.elems;
    while (scurr != nullptr) {
        elemscurr->next = new ListNode<T>(scurr->val);
        scurr = scurr->next;
    }
};

template <typename T>
ListStack<T>::~ListStack() {
    while (!IsEmpty()) {
        pop();
    }
}


template <typename T>
void ListStack<T>::push(const T& el) {
    if (IsEmpty()) {
        elems = new ListNode<T>(el);
        return;
    }
    // push O(1)
    ListNode<T>* tmp = new ListNode<T>(el);
    tmp->next = elems;
    elems = tmp;
}



template <typename T>
void ListStack<T>::pop() {
    if (IsEmpty()) {
        throw "stack is empty";
    }
    // pop O(1)
    ListNode<T>* tmp = elems;
    elems = elems->next;
    delete tmp;
}

template <typename T>
T ListStack<T>::Top() {
    if (IsEmpty()) {
        throw "stack is empty";
    }
    return this->elems->val;
}


template <typename T>
bool ListStack<T>::IsEmpty() { return elems == nullptr; };

template <typename T>
bool ListStack<T>::IsFull() { return elems->size() < MAX_SIZE };

template <typename T>
const ListStack<T>& ListStack<T>::operator=(const ListStack<T>&s) {
    if (this == &s) {
        return *this;
    }

    if (!IsEmpty()) {
        ListNode<T>* tmp = this->elems;
        while (tmp != nullptr) {
            delete elems;
            elems = tmp;
            tmp = tmp->next;
        }
    }

    elems = new ListNode<T>(s.elems->val);
    ListNode<T>* elemscurr = elems;
    ListNode<T>* scurr = s.elems;
    while (scurr != nullptr) {
        elemscurr->next = new ListNode<T>(scurr->val);
        scurr = scurr->next;
    }

}

template <typename T>
bool ListStack<T>::operator==(const ListStack<T>& s) {
    ListNode<T>* thiscurr = elems;
    ListNode<T>* scurr = s.elems;
    while (thiscurr != nullptr && scurr != nullptr) {
        if (thiscurr->val != scurr->val) {
            return 0;
        }
        thiscurr = thiscurr->next;
        scurr = scurr->next;
    }

    // когда оба nullptr
    if (thiscurr == scurr) {
        return 1;
    }
    return 0;
}