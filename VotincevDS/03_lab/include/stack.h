#pragma once
#include <iostream>
#include <string>

template <typename T>
class Stack {
public:
    virtual void push(const T& elem) = 0;
    virtual void pop() = 0;
    virtual T Top() = 0;
    // IsFull не нужен,тк у ListStack нет ограничения
    virtual bool IsEmpty() = 0;
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
    ListNode(const T& x) : val(x), next(nullptr) {}
};



template <typename T>
class ListStack : public Stack<T> {
private:
    ListNode<T>* node;
public:
    
    ListStack() : node(nullptr) {}

    ListStack(const ListStack<T>& s) {
        if (s.node == nullptr) {
            node = nullptr;
            return;
        }
        node = new ListNode<T>(s.node->val);
        ListNode<T>* nodecurr = node;
        ListNode<T>* scurr = s.node;
        while (scurr != nullptr) {
            nodecurr->next = new ListNode<T>(scurr->val);
            scurr = scurr->next;
        }
    };


    ~ListStack() {
        while (!IsEmpty()) {
            pop();
        }
    }

    void push(const T& el) {
        if (IsEmpty()) {
            node = new ListNode<T>(el);
            return;
        }
        ListNode<T>* tmp = new ListNode<T>(el);
        tmp->next = node;
        node = tmp;
    }

    void pop() {
        if (IsEmpty()) {
            throw "stack is empty";
        }
        ListNode<T>* tmp = node;
        node = node->next;
        delete tmp;
    }

    T Top() {
        if (IsEmpty()) {
            throw "stack is empty";
        }
        return this->node->val;
    }



    bool IsEmpty() { return node == nullptr; };


    const ListStack<T>& operator=(const ListStack<T>& s) {
        if (this == &s) {
            return *this;
        }

        if (!IsEmpty()) {
            ListNode<T>* tmp = this->node;
            while (tmp != nullptr) {
                delete node;
                node = tmp;
                tmp = tmp->next;
            }
        }

        node = new ListNode<T>(s.node->val);
        ListNode<T>* nodecurr = node;
        ListNode<T>* scurr = s.node;
        while (scurr != nullptr) {
            nodecurr->next = new ListNode<T>(scurr->val);
            scurr = scurr->next;
        }

    }
    

    bool operator==(const ListStack<T>& s) {
        ListNode<T>* thiscurr = node;
        ListNode<T>* scurr = s.node;
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
};