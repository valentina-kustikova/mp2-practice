#pragma once
#include <iostream>
#include <string>
#include "stack.h"
#include "list.h"

#define MAX_SIZE 100000 // !!!!

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
    
}

template <typename T>
size_t ListStack<T>::size() const { 
    return elems.size();
}

template <typename T>
ListStack<T>::ListStack(const ListStack<T>& s) {
    if (s.elems == nullptr) {
        elems = nullptr;
        return;
    }
    elems = new List<T>(s.elems.get_val());//
    List<T> elemscurr = elems;
    List<T> scurr = s.elems;
    while (scurr != nullptr) {
        elemscurr.RemoveFirst = new List<T>(scurr.get_val());
        scurr = scurr.RemoveFirst;
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
    elems.push(el);
}



template <typename T>
void ListStack<T>::pop() {
    
    elems.RemoveFirst(); // RemoveFirst

}

template <typename T>
T ListStack<T>::Top() const {
    if (IsEmpty()) {
        throw "stack is empty";
    }
    return elems.get_val();
}


template <typename T>
bool ListStack<T>::IsEmpty() const { return elems.size() == 0; };

template <typename T>
bool ListStack<T>::IsFull() const { return size() < MAX_SIZE; };

template <typename T>
const ListStack<T>& ListStack<T>::operator=(const ListStack<T>& s) {
    if (this == &s) {
        return *this;
    }

    if (!IsEmpty()) {
        List<T> tmp = this.elems;
        while (tmp != nullptr) {
            delete elems;
            elems = tmp;
            tmp = tmp.RemoveFirst;
        }
    }

    elems = new List<T>(s.elems.get_val());
    List<T> elemscurr = elems;
    List<T> scurr = s.elems;
    while (scurr != nullptr) {
        elemscurr.RemoveFirst = new List<T>(scurr.get_val());
        scurr = scurr.RemoveFirst;
    }

}

template <typename T>
bool ListStack<T>::operator==(const ListStack<T>& s) {
    List<T> thiscurr = elems;
    List<T> scurr = s.elems;
    while (thiscurr != nullptr && scurr != nullptr) {
        if (thiscurr.get_val() != scurr.get_val()) {
            return 0;
        }
        thiscurr = thiscurr.RemoveFirst;
        scurr = scurr.RemoveFirst;
    }

    // когда оба nullptr
    if (thiscurr == scurr) {
        return 1;
    }
    return 0;
}


