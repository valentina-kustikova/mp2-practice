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
    ListNode* pFirst;
public:

    ~List() {
        List* curr = pFirst, * prev = nullptr;
        while (curr != nullptr) {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
        delete pFirst;
    }



    List<T>* search(T key) {
        List* curr = pFirst;
        while (curr != nullptr) {
            if (curr->val == key) {
                return curr;
            }
            curr = curr->next;
        }
        return curr;
    };

    void pushFront(List<T>* node) {
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

    void pushBack(List<T>* node) {
        if (pFirst == nullptr) {
            pFirst = node;
            return;
        }
        if (node == nullptr) {
            return;
        }

        List* curr = pFirst;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = node;
    };

    void InsertAfter(List<T>* node, T key) {
        List* curr = search(key);
        if (curr == nullptr) {
            throw "this key does not exist";
        }
        node->next = curr->next;
        curr->next = node;
    };

    void InsertBefore(List<T>* node, T key) {
        List* prev = nullptr, *curr = pFirst;
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
        List* prev = nullptr, *curr = pFirst;
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

    int size() {
        List* curr = pFirst;
        int size = 0;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }
        return size;
    };

};