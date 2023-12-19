#include "postfix_exp.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::string exp;
    std::cout << "Enter your expression : ";
    std::getline(std::cin, exp);

    ArithmeticExp expr(exp);
    std::cout << expr.GetOriginal() << std::endl;
    std::cout << expr.GetPostfix() << std::endl;

    if (expr.GetPostfix() != "there are invalid characters...") {
        std::vector<std::string> operands = expr.GetOperands();

        std::map<std::string, double> values;
        double val;
        for (const std::string op : operands) {
            std::cout << "Enter value of " << op << ": ";
            std::cin >> val;
            values[op] = val;
        }

        std::cout << expr.Calculate(values) << std::endl;
    }
    
    return 0;
}