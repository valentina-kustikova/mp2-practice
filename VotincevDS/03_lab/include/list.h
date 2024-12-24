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
    ListNode<T>* pFirst;
public:

    List() {
        pFirst = nullptr;
    }
    List(const T& x) {
        pFirst = new ListNode<T>(x);
    }
    List(const List<T>& list) {
        if (list.pFirst == nullptr) {
            return;
        }

        pFirst = new ListNode<T>(list.pFirst->val);
        ListNode<T>* curr = list.pFirst;
        while (curr->next != nullptr) {
            curr->next = new ListNode<T>(list.pFirst->val);
            curr = curr->next;
        }
    }

    ~List() {

        if (pFirst == nullptr) {
            return;
        }

        while (pFirst->next != nullptr) {
            ListNode<T>* curr = pFirst;
            pFirst = pFirst->next;
            delete curr;
        }
        pFirst = nullptr;

    }

    const List<T>& operator=(const List <T>& list) {
        if (this == &list)
        {
            return *this;
        }
        if (list.pFirst == nullptr)
        {
            pFirst = nullptr;
            return *this;
        }
        pFirst = new ListNode<T>(list.pFirst->val);
        ListNode<T>* curr = list.pFirst->next;
        ListNode<T>* currl = pFirst;

        while (curr != nullptr)
        {
            currl->next = new ListNode<T>(curr->val);
            currl = currl->next;
            curr = curr->next;
        }
        return *this;
    }



    T get_val() const {
        return pFirst->val;
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
        if (curr == nullptr) {
            throw "this key does not exist";
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
        while ((curr != nullptr) && (curr->val != key)) {
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
        while ((curr != nullptr) && (curr->val != key)) {
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

    void RemoveFirst() { // RemoveFirst
        ListNode<T>* tmp = pFirst;
        if (tmp == nullptr) {
            throw "empty list";
        }
        pFirst = pFirst->next;
        delete tmp;
    }


    bool operator==(const List<T>& s) const {

        ListNode<T>* curr1 = this->pFirst, * curr2 = s.pFirst;
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val != curr2->val) {
                return 0;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        if (curr1 == nullptr && curr2 == nullptr) {
            return 1;
        }
        return 0;
    }

    bool operator!=(const List<T>& s) const {
        ListNode<T>* curr1 = pFirst, * curr2 = s.pFirst;
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val != curr2->val) {
                return 1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        if (curr1 == nullptr && curr2 == nullptr) {
            return 0;
        }
        return 1;
    }

};

