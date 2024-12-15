/*#pragma once
#include <iostream>
#include "stack.h"

using namespace std;
template<typename T>
class AriExpress {
protected:
    string infix;
    string postfix;
    map<char, int> priority;
public:
    AriExpress(string infx) : infix(infx) {
        priority = { {'(', 0}, {')', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
        to_postfix();
    }
    void to_postfix() {
       

    }
    string get_infix() const { return infix; }
    string get_postfix() const { return postfix; }
};*/