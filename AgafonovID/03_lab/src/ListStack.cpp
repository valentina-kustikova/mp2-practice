#include "ListStack.h"

/*template <typename T>
ListStack<T>::ListStack(const ListStack<T>& s) : stack(s.stack) {}

template <typename T>
ListStack<T>::~ListStack() {}

template <typename T>
bool ListStack<T>::IsEmpty() const {
    return (stack.IsEmpty());
}

template <typename T>
bool ListStack<T>::IsFull() const {
    return false;
}

template <typename T>
void ListStack<T>::Push(const T& elem) {
    typename List<T>::TNode* node = new typename List<T>::TNode(0, elem);
    stack.pushBack(stack.pFirst, node);
}

template <typename T>
void ListStack<T>::Pop() {
    if (stack.IsEmpty()) {
        throw std::exception("Stack is empty");
    }
    typename List<T>::TNode* curr = stack.pFirst;
    typename List<T>::TNode* prev = nullptr;
    while (curr->pNext != nullptr) {
        prev = curr;
        curr = curr->pNext;
    }
    if (prev == nullptr) {
        stack.pFirst = nullptr;
    }
    else {
        prev->pNext = nullptr;
    }
    delete curr;
}

template <typename T>
T ListStack<T>::Top() const {
    if (stack.IsEmpty()) {
        throw std::exception("Stack is empty");
    }
    typename List<T>::TNode* curr = stack.pFirst;
    while (curr->pNext != nullptr) {
        curr = curr->pNext;
    }
    return curr->data;
}

template <typename T>
const ListStack<T>& ListStack<T>::operator=(const ListStack<T>& s) {
    if (this == &s) {
        return *this;
    }
    stack = s.stack;
    return *this;
}

template <typename T>
bool ListStack<T>::operator==(const ListStack<T>& s) {
    return (stack == s.stack);
}
*/