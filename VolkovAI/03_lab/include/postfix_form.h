#pragma once
#include <vector>
#include <map>
#include <string>
#include "array_stack.h"
#include "list_stack.h"
#include <iostream>

using namespace std;

enum Stack_type {
    array_stack = 0,
    list_stack = 1
};

class ReversePolishNotation {
private:
    string infix;
    string postfix;
    Stack_type type;
    map<string, int> priorts;
    map<string, double> operands;
    vector<string> lexems;
    void convert_expression_to_RPN();
};