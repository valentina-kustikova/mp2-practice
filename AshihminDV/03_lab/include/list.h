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
class TList
{
private:
    ListNode<T>* pFirst;
    ListNode<T>* pLast;
    ListNode<T>* pCurr;
public:

    TList() {
        pFirst = nullptr;
        pLast = nullptr;
        pCurr = nullptr;
    }
    TList(const T& x) {
        pFirst = new ListNode<T>(x);
        pLast = pFirst;
        pCurr = pFirst;
    }
    TList(const TList<T>& list) {
        if (list.pFirst == nullptr) {
            return;
        }

        pFirst = new ListNode<T>(list.pFirst->val);
        ListNode<T>* curr = list.pFirst;
        while (curr->next != nullptr) {
            curr->next = new ListNode<T>(list.pFirst->val);
            curr = curr->next;
        }
        pLast = curr;
    }

    ~TList() {

        if (pFirst == nullptr) {
            return;
        }

        while (pFirst->next != nullptr) {
            ListNode<T>* curr = pFirst;
            pFirst = pFirst->next;
            delete curr;
        }
        pFirst = nullptr;
        pLast = nullptr;
        pCurr = nullptr;
    }


    ListNode<T>* get_head() const {
        return pFirst;
    }
    ListNode<T>* get_end() const {
        return pLast;
    }
    ListNode<T>* get_curr() const {
        return pCurr;
    }

    void Next() {
        if (pCurr->next != nullptr)
        {
            pCurr = pCurr->pNext;
        }

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

    void insert_Front(ListNode<T>* node) {
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

    void insert_Back(ListNode<T>* node) {
        if (pFirst == nullptr) {
            pFirst = node;
            return;
        }
        if (node == nullptr) {
            return;
        }
        pLast->next = node;
        pLast = pLast->next;
    };

    void insert_After(ListNode<T>* node, T key) {
        ListNode<T>* curr = search(key);
        if (curr == nullptr) {
            throw "this key does not exist";
        }
        node->next = curr->next;
        curr->next = node;
    };

    void insert_Before(ListNode<T>* node, T key) {
        ListNode<T>* prev = nullptr, * curr = pFirst;
        while ((curr != nullptr) && (curr->val != key)) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            throw "this key does not exist";
        }

        if (prev == nullptr) {
            insert_Front(node);
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

    void Remove_First() {
        ListNode<T>* tmp = pFirst;
        if (tmp == nullptr) {
            throw "empty list";
        }
        pFirst = pFirst->next;
        delete tmp;
    }


    bool operator==(const TList<T>& s) const {

        ListNode<T>* curr1 = this->pFirst, * curr2 = s.pFirst;
        
        while (curr1 != nullptr && curr2 != nullptr) {

            if (curr1->val != curr2->val) {
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        if (curr1 == nullptr && curr2 == nullptr) {
            return true;
        }
        return false;
    }

    bool operator!=(const TList<T>& s) const {
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
    //TList();
    //TList(const T& x);
    //TList(const TList<T>& list);
    //~TList();

    //ListNode<T>* get_head() const {
    //    return pFirst;
    //}
    //ListNode<T>* get_end() const {
    //    return pLast;
    //}
    //ListNode<T>* get_curr() const {
    //    return pCurr;
    //}

    //void Next();

    //ListNode<T>* search(T key);

    //void insert_Front(ListNode<T>* node);

    //void insert_Back(ListNode<T>* node);

    //void insert_After(ListNode<T>* node, T key);

    //void insert_Before(ListNode<T>* node, T key);

    //void remove(T key);

    //size_t size() const;

    //void Remove_First();


    //bool operator==(const TList<T>& s) const;

    //bool operator!=(const TList<T>& s) const;

};


//template<typename T>
//TList<T>::TList() {
//    pFirst = nullptr;
//    pLast = nullptr;
//    pCurr = nullptr;
//}
//
//template<typename T>
//TList<T>::TList(const T& x) {
//    pFirst = new ListNode<T>(x);
//    pLast = pFirst;
//    pCurr = pFirst;
//}
//
//template<typename T>
//TList<T>::TList(const TList<T>& list) {
//    if (list.pFirst == nullptr) {
//        return;
//    }
//
//    pFirst = new ListNode<T>(list.pFirst->val);
//    ListNode<T>* curr = list.pFirst;
//    while (curr->next != nullptr) {
//        curr->next = new ListNode<T>(list.pFirst->val);
//        curr = curr->next;
//    }
//    pLast = curr;
//}
//
//template<typename T>
//TList<T>::~TList() {
//
//    if (pFirst == nullptr) {
//        return;
//    }
//
//    while (pFirst->next != nullptr) {
//        ListNode<T>* curr = pFirst;
//        pFirst = pFirst->next;
//        delete curr;
//    }
//    pFirst = nullptr;
//    pLast = nullptr;
//    pCurr = nullptr;
//}
//
//template<typename T>
//void TList<T>::Next() {
//    if (pCurr->next != nullptr)
//    {
//        pCurr = pCurr->pNext;
//    }
//
//}
//
//template<typename T>
//ListNode<T>*  TList<T>::search(T key) {
//    ListNode<T>* curr = pFirst;
//    while (curr != nullptr) {
//        if (curr->val == key) {
//            return curr;
//        }
//        curr = curr->next;
//    }
//    if (curr == nullptr) {
//        throw "this key does not exist";
//    }
//    return curr;
//};
//
//template<typename T>
//void TList<T>::insert_Front(ListNode<T>* node) {
//    if (pFirst == nullptr) {
//        pFirst = node;
//        return;
//    }
//    if (node == nullptr) {
//        throw "cant push null node in front";
//    }
//    node->next = pFirst;
//    pFirst = node;
//};
//
//template<typename T>
//void TList<T>::insert_Back(ListNode<T>* node) {
//    if (pFirst == nullptr) {
//        pFirst = node;
//        return;
//    }
//    if (node == nullptr) {
//        return;
//    }
//    pLast->next = node;
//    pLast = pLast->next;
//};
//
//template<typename T>
//void TList<T>::insert_After(ListNode<T>* node, T key) {
//    ListNode<T>* curr = search(key);
//    if (curr == nullptr) {
//        throw "this key does not exist";
//    }
//    node->next = curr->next;
//    curr->next = node;
//};
//
//template<typename T>
//void TList<T>::insert_Before(ListNode<T>* node, T key) {
//    ListNode<T>* prev = nullptr, * curr = pFirst;
//    while ((curr != nullptr) && (curr->val != key)) {
//        prev = curr;
//        curr = curr->next;
//    }
//
//    if (curr == nullptr) {
//        throw "this key does not exist";
//    }
//
//    if (prev == nullptr) {
//        insert_Front(node);
//        return;
//    }
//
//    node->next = curr;
//    prev->next = node;
//};
//
//template<typename T>
//void TList<T>::remove(T key) {
//    ListNode<T>* prev = nullptr, * curr = pFirst;
//    while ((curr != nullptr) && (curr->val != key)) {
//        prev = curr;
//        curr = curr->next;
//    }
//
//    if (curr == nullptr) {
//        throw "this key does not exist";
//    }
//
//    if (prev == nullptr) {
//        pFirst = pFirst->next;
//        delete curr;
//        return;
//    }
//    prev->next = curr->next;
//    delete curr;
//};
//
//template<typename T>
//size_t TList<T>::size() const {
//    ListNode<T>* curr = pFirst;
//    size_t size = 0;
//    while (curr != nullptr) {
//        size++;
//        curr = curr->next;
//    }
//    return size;
//};
//
//template<typename T>
//void TList<T>::Remove_First() {
//    ListNode<T>* tmp = pFirst;
//    if (tmp == nullptr) {
//        throw "empty list";
//    }
//    pFirst = pFirst->next;
//    delete tmp;
//}
//
//template<typename T>
//bool TList<T>::operator==(const TList<T>& s) const {
//
//    ListNode<T>* curr1 = this->pFirst, * curr2 = s.pFirst;
//    while (curr1 != nullptr && curr2 != nullptr) {
//        if (curr1->val != curr2->val) {
//            return 0;
//        }
//        curr1 = curr1->next;
//        curr2 = curr2->next;
//    }
//    if (curr1 == nullptr && curr2 == nullptr) {
//        return 1;
//    }
//    return 0;
//}
//
//template<typename T>
//bool TList<T>::operator!=(const TList<T>& s) const {
//    ListNode<T>* curr1 = pFirst, * curr2 = s.pFirst;
//    while (curr1 != nullptr && curr2 != nullptr) {
//        if (curr1->val != curr2->val) {
//            return 1;
//        }
//        curr1 = curr1->next;
//        curr2 = curr2->next;
//    }
//    if (curr1 == nullptr && curr2 == nullptr) {
//        return 0;
//    }
//    return 1;
//}