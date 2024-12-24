#pragma once
#include <iostream>
#include "list.h"

using namespace std;


template <typename TElem>
class stack
{
public:
    virtual void push(const TElem& e) = 0;
    virtual void pop() = 0;
    virtual bool is_empty()const = 0;
    virtual bool is_full()const = 0;
    virtual TElem show_top()const = 0;
};