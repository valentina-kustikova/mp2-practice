#pragma once

#include <iostream>
#include "stack.h"

using namespace std;

const int MAX_STACK_SIZE = 100000000;

template <typename T> 
class TStackArray: public TStack<T> { 
private:
	int maxsz;
	int top;
	T* mem;
public:
    TStackArray() : maxsz(0), top(-1), mem(nullptr) {};

    TStackArray(int size = 1) : maxsz(size), top(-1) {
        if (maxsz <= 0 || maxsz >= MAX_STACK_SIZE)
            throw "No correct size";
        mem = new T[maxsz];
    }

    TStackArray(const TStackArray<T>& s) {
        maxsz = s.maxsz;
        top = s.top;
        mem = new T[maxsz];
        for (int i = 0; i < maxsz; i++) {
            mem[i] = s.mem[i];
        }
    }

    ~TStackArray() {
        if (mem != nullptr) {
            delete[] mem;
        }
    }

    T Top() const {
        if (IsEmpty()) throw "Stack is empty";
        return mem[top];
    }

    void Pop() {
        if (IsEmpty()) throw "Stack is empty";
        top--;
    }

    void Push(const T& elem) {
        if (IsFull()) {
            T* tmp = mem;
            mem = new T[(maxsz + 1) * 2];
            std::copy(tmp, tmp + maxsz, mem);
            maxsz = (maxsz + 1) * 2;
        }
        top++;
        mem[top] = elem;
    }

    bool IsEmpty() const {
        return (top == -1);
    }

    bool IsFull() const {
        return (top == maxsz - 1);
    }

    const TStackArray<T>& operator=(const TStackArray<T>& s)
    {
        if (this == &s) return *this;
        if (maxsz != s.maxsz) {
            maxsz = s.maxsz;
            mem = new T[maxsz];
        }
        top = s.top;
        for (int i = 0; i < maxsz; i++) {
            mem[i] = s.mem[i];
        }
        return *this;
    }

    bool operator==(const TStackArray<T>& s) const {
        if (maxsz != s.maxsz || top != s.top) return 0;
        for (int i = 0; i < maxsz; i++) {
            if (mem[i] != s.mem[i]) return 0;
        }
        return 1;
    }

    size_t size() const {
        return maxsz;
    }

    friend ostream& operator<<(ostream& ostr, const TStackArray<T>& s) {
        TStackArray<T>& s1(s);
        while (s1.IsEmpty!=1) {
            ostr >> s1.Top();
            s1.Pop()
        }
        return ostr;
    }

};
