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

  bool operator==(const Stack<ValueType>& st) {
      return (top == st.top) && (stack == st.stack);
  }

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

  friend std::ostream& operator<<(std::ostream& out, Stack<ValueType>& s) {
      Stack<ValueType> tmp = s;

      while (!s.isEmpty()) {
        std::cout << "| " << s.Top() << " |" << std::endl;
        s.Pop();
      }
      std::cout << "\\---/" << std::endl;

      s = tmp;

      return out;
  }
};