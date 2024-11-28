#pragma once
#include <iostream>
#include <string>

template <typename T>
class Stack {
public:
    virtual void push(const T& elem) = 0;
    virtual void pop() = 0;
    virtual T Top() const = 0;
    virtual bool IsEmpty() const = 0;
    // IsFull не нужен,тк у ListStack нет ограничения
    // (он есть у ArrayStack)
};

template <typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(const T& x) : val(x), next(nullptr) {}
};

template<typename T>
class List
{
    ////
};



template <typename T>
class ListStack : public Stack<T> {
private:
    ListNode<T>* node; // List<T> elems;
public:
    
    ListStack() : node(nullptr) {}

    ListStack(const ListStack<T>& s) { // elems = s.elems
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
        // push O(1)
        ListNode<T>* tmp = new ListNode<T>(el);
        tmp->next = node;
        node = tmp;
    }

    void pop() {
        if (IsEmpty()) {
            throw "stack is empty";
        }
        // pop O(1)
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