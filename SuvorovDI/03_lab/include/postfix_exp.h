#pragma once
#include <iostream>
#include "stack.h"

class Postfix_notation {
private:
  std::string original_exp;
  std::string postfix_exp;

  const std::pair<char, int> priorities[6] = {
    {'*', 3},
    {'/', 3},
    {'+', 2},
    {'-', 2},
    {'(', 1},
    {'=', 0}
  };

  int get_priority(const char op);
  int get_postfix_length(const std::string exp) const;
  std::string conversion_to_postfix(const std::string exp);

public:
  Postfix_notation(const std::string exp);
  std::string get_postfix() const;
};

int Postfix_notation::get_postfix_length(const std::string exp) const {
    int len = 0;
    for (int i = 0; i < exp.length(); i++)
        if (exp[i] != '(' && exp[i] != ')')
            len++;
    return len;
}

std::string Postfix_notation::get_postfix() const {
    return postfix_exp;
}

Postfix_notation::Postfix_notation(const std::string exp) {
  original_exp = exp;
  postfix_exp = conversion_to_postfix(exp);
}

int Postfix_notation::get_priority(const char op) {
  for (int i = 0; i < 6; i++) {
    if (op == priorities[i].first) {
      return priorities[i].second;
    }
  }
  throw std::exception("No such operation\n");
}

std::string Postfix_notation::conversion_to_postfix(const std::string exp) {
  Stack<char> operations;
  Stack<char> operands;

  for (int i = 0; i < exp.length(); i++) {
    bool is_operation = false;
    for (int op = 0; op < 6; op++)
      if (exp[i] == priorities[op].first || exp[i] == ')') {
        is_operation = true;
        break;
      }
    
    if (is_operation) {
      if (exp[i] == ')') {
        while ( !operations.isEmpty() && operations.Top() != '(' ) {
          operands.Push(operations.Top());
          operations.Pop();
        }
        if (!operations.isEmpty() && operations.Top() == '(')
          operations.Pop(); // Delete '('
      }
      else if (!operations.isEmpty() && get_priority(operations.Top()) > get_priority(exp[i])) {
        while (!operations.isEmpty() && get_priority(operations.Top()) >= get_priority(exp[i])) {
          operands.Push(operations.Top());
          operations.Pop();
        }
        operations.Push(exp[i]);
      }
      else {
        operations.Push(exp[i]);
      }
    }
    else {
      operands.Push(exp[i]);
    }
  }
  while (!operations.isEmpty()) {
      operands.Push(operations.Top());
      operations.Pop();
  }

  std::string res(get_postfix_length(exp), ' ');
  
  for (int i = get_postfix_length(exp) - 1; i >= 0; i--) {
    res[i] = operands.Top();
    operands.Pop();
  }

  return res;
}