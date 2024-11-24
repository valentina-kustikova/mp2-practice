#pragma once
#include <iostream>
#include <string>

template <typename T>
class Stack {
public:
    virtual void push(const T& elem) = 0;
    virtual void pop() = 0;
    virtual T Top() = 0;
    virtual bool IsEmpty() = 0;
    virtual bool IsFull() = 0;
};






template <typename T>
class ArrayStack : public Stack<T> {
private:
    int top;
    size_t maxsz;
    T* arr;
public:
    ArrayStack() : top(-1), maxsz(0),arr(nullptr) {};
    ArrayStack(int sz) : top(-1)
    {
        if (sz <= 0) {
            throw "size must be greater than 0";
        }
        maxsz = sz;
        arr = new T[sz];
    };

    ArrayStack(const ArrayStack<T>& s) {
        top = s.top;
        maxsz = s.maxsz;
        arr = new T[maxsz];
        for (int i = 0; i < maxsz; i++) {
            arr[i] = s.arr[i];
        }
    };

    ~ArrayStack() {
        delete[] arr;
    }

    void push(const T& elem)  {

        if (IsFull()) {
            
            T* tmp = arr;
            arr = new T[(maxsz + 1) * 3];
            std::copy(tmp,tmp + maxsz,arr);
            maxsz = (maxsz + 1) * 3;            
        }

        top++;
        arr[top] = elem;
        
    }


    void pop()   {
        if (IsEmpty()) {
            throw "stack is empty";
        }
        top--;
    };
    T Top()  {
        if (IsEmpty()) {
            throw "stack is empty";
        }
        return arr[top];
    };
    bool IsEmpty()  { return top == -1; };
    bool IsFull()  { return top == maxsz-1; };

    const ArrayStack<T>& operator=(const ArrayStack<T>& s) {
        if (this == &s) {
            return *this;
        }
        if (maxsz != s.maxsz) {
            if (maxsz != 0) {
                delete[] arr;
            }
            maxsz = s.maxsz;
            arr = new T[maxsz];
        }
        top = s.top;
        for (int i = 0; i < maxsz; i++) {
            arr[i] = s.arr[i];
        }
        return *this;
    }

    bool operator==(const ArrayStack<T>& s) {
        if (maxsz != s.maxsz || top != s.top) {
            return 0;
        }
        for (int i = 0; i < maxsz; i++) {
            if (arr[i] != s.arr[i]) {
                return 0;
            }
        }
        return 1;
    }
};




template <typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(T x) : val(x), next(nullptr) {}
};



template <typename T>
class ListStack : public Stack<T> {
private:
    ListNode* node;
public:
    
    void push(T el) {
        if (IsEmpty()) {
            node = new ListNode(el);
            return;
        }
        ListNode* tmp = new ListNode(el);
        tmp->next = node;
        node = tmp;
    }

    void pop() {
        if (IsEmpty()) {
            throw "stack is empty"
        }
        ListNode* tmp = node;
        node = node->next;
        delete tmp;
    }

    ~ListStack() {
        while (node != nullptr) {
            ListNode* tmp = node;
            node = node->next;
            delete tmp;
        }
    }

    bool IsEmpty() { return node == nullptr; };

};