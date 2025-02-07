#pragma once

#include <iostream>
#include "stack.h"
#include "list.h"

template <typename T>
class TListStack : public TStack<T> { 
private:
    TList<T> stack;
public:
    TListStack():stack() {}

    TListStack(const TListStack<T>& s) : stack(s.stack) {}

    ~TListStack(){
        while (!stack.IsEmpty()){
            stack.PopBack();
        }
    }

    bool IsEmpty() const {
        return (stack.IsEmpty());
    }

    bool IsFull() const {
        return ~(stack.IsEmpty());
    }

    void Push(const T& data){
        stack.pushFront(data);
    }

    void Pop(){
        stack.PopFront();
    }

    T Top() const{
        TList<T> stack1(stack);
        T tmp;
        while (stack1.getHead()!=nullptr) {
            tmp = stack1.getHead()->Data;
            stack1.PopBack();
        }
        return tmp;
    }

    const TListStack<T>& operator=(const TListStack<T>& s){
        stack = s.stack;
        return *this;
    }

    size_t size() const {
        return stack.size();
    }

    bool operator==(const TListStack<T>& s) const{
        return (stack == s.stack);
    }

    friend ostream& operator<<(ostream& ostr, const TListStack<T>& s) {
        TListStack<T>& s1(s);
        while (s1.IsEmpty != 1) {
            ostr >> s1.Top();
            s1.Pop()
        }
        return ostr;
    }
};
