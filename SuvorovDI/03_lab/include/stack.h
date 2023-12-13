#pragma once
#include <iostream>
#include <vector>

template <typename ValueType>
class Stack {
private:
  int top;
  std::vector<ValueType> stack;
public:
  Stack() : top(-1) {}
  Stack(const Stack<ValueType>& s) : top(s.top), stack(s.stack) {}

  void Pop() {
    if (isEmpty())
      throw std::exception("The stack is empty\n");
    stack.pop_back();
    top--;
  }
  ValueType Top() const {
    if (isEmpty())
      throw std::exception("The stack is empty\n");

    return stack[top];
  }
  void Push(const ValueType& elem) {
    stack.push_back(elem);
    top++;
  }

  bool isEmpty() const {return top == -1;}
};