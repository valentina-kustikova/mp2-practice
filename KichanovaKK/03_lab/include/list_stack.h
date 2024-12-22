#pragma once
#include <iostream>
#include "main_stack.h"
#include "list.h"

using namespace std;
template<typename T>

class liststack : public MainStack<T> {
private:
    TList<T> elems;
public:
    liststack(){}
    liststack(const liststack<T>& s) : elems(s.elems) {}
    ~liststack();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(const T& val);
    T Top() const;
    T Pop();
    const liststack<T>& operator=(const liststack<T>& s);
    int Size() const;
};

template<typename T>
liststack<T>::~liststack() {

}
template<typename T>
bool liststack<T>::IsEmpty() const {
    return elems.IsEmpty();
}
template<typename T>
bool liststack<T>::IsFull() const {
    return false;
}
template<typename T>
void liststack<T>::Push(const T& val) {
    TNode<T>* newNode = new TNode<T>(val);
    elems.PushFront(newNode);
}
template<typename T>
T liststack<T>::Top() const {
    if (elems.IsEmpty()) {
        throw "Stack is empty";
    }
    return elems.reset();
}
template<typename T>
T liststack<T>::Pop() {
    if (elems.IsEmpty()) {
        throw "Stack is empty";
    }
    T val = elems.reset();
    elems.remove(val);
    return val;
}
template<typename T>
const liststack<T>& liststack<T>:: operator=(const liststack<T>& s)
{
    elems = s.elems;
    return *this;
}
template <typename T>
int liststack<T>::Size() const {
    return elems.Size(); 
}