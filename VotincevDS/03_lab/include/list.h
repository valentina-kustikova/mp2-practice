#pragma once
#include <iostream>

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
private:
    T val;
    ListNode<T>* pFirst;
    
public:
    


    List() : pFirst(nullptr), val(0) {}
    List(const T& x) : val(x), pFirst(nullptr) {}
    ~List() {
        ListNode<T>* curr = pFirst, * prev = nullptr;
        while (curr != nullptr) {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
        delete pFirst;
    }

    T get_val() const {
        return val;
    }

    ListNode<T>* get_head() const {
        return pFirst;
    }

    void push(const T& key) {
        ListNode<T>* tmp = new ListNode<T>(key);
        pushFront(tmp);
    }

    ListNode<T>* search(T key) {
        ListNode<T>* curr = pFirst;
        while (curr != nullptr) {
            if (curr->val == key) {
                return curr;
            }
            curr = curr->next;
        }
        return curr;
    };

    void pushFront(ListNode<T>* node) {
        if (pFirst == nullptr) {
            pFirst = node;
            return;
        }
        if (node == nullptr) {
            throw "cant push null node in front";
        }
        node->next = pFirst;
        pFirst = node;
    };

    void pushBack(ListNode<T>* node) {
        if (pFirst == nullptr) {
            pFirst = node;
            return;
        }
        if (node == nullptr) {
            return;
        }

        ListNode<T>* curr = pFirst;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = node;
    };

    void InsertAfter(ListNode<T>* node, T key) {
        ListNode<T>* curr = search(key);
        if (curr == nullptr) {
            throw "this key does not exist";
        }
        node->next = curr->next;
        curr->next = node;
    };

    void InsertBefore(ListNode<T>* node, T key) {
        ListNode<T>* prev = nullptr, * curr = pFirst;
        while ((curr != nullptr) && (curr->key != key)) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            throw "this key does not exist";
        }

        if (prev == nullptr) {
            pushFront(node);
            return;
        }

        node->next = curr;
        prev->next = node;
    };

    void remove(T key) {
        ListNode<T>* prev = nullptr, * curr = pFirst;
        while ((curr != nullptr) && (curr->key != key)) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            throw "this key does not exist";
        }

        if (prev == nullptr) {
            pFirst = pFirst->next;
            delete curr;
            return;
        }
        prev->next = curr->next;
        delete curr;
    };

    size_t size() const {
        ListNode<T>* curr = pFirst;
        size_t size = 0;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }
        return size;
    };


    void next() {
        ListNode<T>* tmp = pFirst;
        if (tmp == nullptr) {
            throw "empty list";
        }
        pFirst = pFirst->next;
        delete tmp;
    }

};