#ifndef LIST_STACK_H
#define LIST_STACK_H
#include "stack.h"
#include "List.h"
template <typename T>
class ListStack : public Stack<T>
{
private:
    List<T> stack;
public:
    ListStack() {}; 
    ListStack(const ListStack& s) :stack(s.stack) {};
    ~ListStack();
    void Pop();
    void Push(const T& el);
    T Top() const;
    bool IsEmpty() const;
    bool IsFull() const { return 0; };
    const ListStack<T>& operator=(const ListStack<T>& s);
    bool operator==(const ListStack<T>& s) const;
    int Size() const override { return stack.GetSZ(); } // ���������� GetSZ() �� List
};

template <typename T>
ListStack<T>::~ListStack() = default;

template <typename T>
void ListStack<T>::Pop() {
    if (IsEmpty()) {
        throw std::runtime_error("Stack is empty. Cannot Pop.");
    }
    stack.PopFront(); // ������� � ������, ��� ��� � ������ ������� ������� � ������
}

template <typename T>
void ListStack<T>::Push(const T& el) {
    stack.PushFront(el); // ��������� � ������, ��� ��� � ������ ������� ��������� � ������
}

template <typename T>
T ListStack<T>::Top() const{
    if (IsEmpty()) {
        throw ("Stack is empty. Cannot get Top.");
    }
    return stack[0];  // ���������� ������ �������, ��� ��� ��������� � ������
}

template <typename T>
bool ListStack<T>::IsEmpty() const {
    return stack.IsEmpty();
}

template <typename T>
const ListStack<T>& ListStack<T>::operator=(const ListStack<T>& s) {
    if (this != &s) {
        stack = s.stack;
    }
    return *this;
}
template <typename T>
bool ListStack<T>::operator==(const ListStack<T>& s) const {
    return stack == s.stack;
}

#endif