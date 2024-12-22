#ifndef LIST_STACK_H
#define LIST_STACK_H
#include "stack.h"
#include "list.h"
template <typename T>
class ListStack: public Stack<T>
{
private:
    List<T> stack;
public:
    ListStack() {};
    ListStack(const ListStack& s) :stack(s.stack) {};
    ~ListStack();
    void Pop();
    void Push(const T& el);
    T Top();
    bool IsEmpty();
    bool IsFull() { return 0; };
};

template <typename T>
ListStack<T>::~ListStack()
{
    while (!stack.IsEmpty())
    {
        stack.PopBack();
    }
}
template <typename T>
void ListStack<T>::Pop()
{
    stack.PopBack();
}
template <typename T>
void ListStack<T>::Push(const T& el)
{
    stack.PushBack(el);
}
template <typename T>
T ListStack<T>::Top()
{
    return stack[stack.GetSZ() - 1];
}
template <typename T>
bool ListStack<T>::IsEmpty()
{
    return (stack.IsEmpty());
}
#endif // !LIST_STACK_H
