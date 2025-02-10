#ifndef STACK_H
#define STACK_H

#pragma once


template <typename TElem> class Stack {
public:
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual void push(const TElem &e) = 0;
    virtual void pop() = 0;
    virtual TElem showTop() const = 0;
};
#endif //STACK_H
