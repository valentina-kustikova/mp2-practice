#include "postfix_exp.h"
#include <iostream>

int main() {
  try {
    Postfix_notation first_exp("(a-c/d)+(a*(c+b))");
    std::cout << first_exp.get_postfix();
  }
  catch (const std::exception ex) {
    std::cout << ex.what();
  }
  
  

  return 0;
}