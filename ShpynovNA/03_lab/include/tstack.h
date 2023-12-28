#ifndef TSTACK_H_
#define TSTACK_H_
#include <iostream>
#include <vector>
using namespace std;
template <typename T> class TStack {
private:
    int max_size;
    int current_amount;
    T* elements;
public:
    TStack();
    TStack(int size = 20);
    ~TStack();

    bool is_full() const;
    bool is_empty() const;

    T& top();
    void add(const T& elem);
    int get_size() {
        return current_amount;
    }
    void del() ;
};

template <typename T> TStack<T>::TStack(){}
template <typename T> TStack<T>::TStack(int size) {
    if (size <= 0) {
        throw "size must be positive";
    }
    max_size = size;
    current_amount = -1;
    elements = new T[size];
}

template <typename T> TStack<T>::~TStack(){
    delete[] elements;
}

template <typename T> T& TStack<T>::top(){
    if (is_empty())
        throw "no elements in this stack";
    return elements[current_amount];
}

template <typename T> void TStack<T>::del() {
    if (is_empty())
        throw "no elements in this stack";
    current_amount--;
}

template <typename T> void TStack<T>::add(const T& elem) {
    if (is_full())
        throw "this stack is full";
    elements[++current_amount] = elem;
}

template <typename T> bool TStack<T>::is_full() const {
    return (current_amount == max_size - 1);
}

template <typename T> bool TStack<T>::is_empty() const {
    return (current_amount == -1);
}

#endif