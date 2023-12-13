#include "postfix_exp.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::string exp;
    std::cout << "Enter your expression : ";
    std::cin >> exp;

    ArithmeticExp expr(exp);
    std::cout << expr.GetOriginal() << std::endl;
    std::cout << expr.GetPostfix() << std::endl;
    std::vector<char> operands = expr.GetOperands();

    std::map<char, double> values;
    double val;
    for (const char op : operands) {
        std::cout << "Enter value of " << op << ": ";
        std::cin >> val;
        values[op] = val;
    }

    std::cout << expr.Calculate(values) << std::endl;
    
    return 0;
}