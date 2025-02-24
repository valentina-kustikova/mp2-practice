#include "stack.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

class Postfix {
    std::vector<std::string> postfix_;
    enum stack_type type_;

    void infixToPostfix(std::string s);
    int prec(char c);
    int do_operation(int& num1, int& num2, std::string& operation);
    bool isOperation(std::string& symbol);

public:

    Postfix(std::string& infix, enum stack_type type = stack_type::array);
    std::string Get();
    int Calculate(std::unordered_map<std::string, int> operands = {});
};

