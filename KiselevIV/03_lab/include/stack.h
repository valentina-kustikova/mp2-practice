#pragma once
#include "list.h"
#include <iostream>
using namespace std;

template <typename TElem>
class stack
{
public:
    virtual void push(const TElem& e) = 0;
    virtual TElem show_top()const = 0;
    virtual void pop() = 0;
    virtual bool is_full()const = 0;
    virtual bool is_empty()const = 0;
};