#include "talgorithm.h"
#include "tstack.h"
#include <iostream>
#include <string>
#include <stdexcept>

int Postfix::GetPriority(const char op)
{
    switch (op)
    {
    case '(':
        return 1;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    default:
        throw "Error. Incorrect symbol.";
    }
}

bool Postfix::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

bool Postfix::isOperator(const std::string& str) {
    return (str == "+" || str == "-" || str == "*" || str == "/" || str == "(" || str == ")");
}

// cout for struct Postfix
std::ostream& operator<<(std::ostream& out, const Postfix& op)
{
    out << op.s_postfix;
    return out;
};

//for class Postfix

Postfix::Postfix()
{
    postfixArray = std::vector<std::string>();
    s_postfix = "";
    operands = std::map<std::string, double>();
}

Postfix::Postfix(const std::vector<std::string>& postf)
{
    postfixArray = postf;
    s_postfix = "";
    for (int i = 0; i < postf.size(); i++)
    {
        s_postfix += postf[i];
        s_postfix += " ";

        if (!isOperator(postf[i]) && operands.find(postf[i]) == operands.end()) {
            double value = INFINITY;

            try {
                value = std::stof(postf[i]);
            }
            catch (std::invalid_argument const& ex)
            {
            };

            // put new unique operand to map
            operands[postf[i]] = value;
        }
    }
}

void Postfix::setValues()
{
    for (auto& operand : operands)
    {
        if (operand.second == INFINITY) {
            operand.second = getValue(operand.first);
        }
    }
};

double Postfix::getValue(const std::string& name)
{
    std::cout << "Enter variable value for \"" << name << "\"" << std::endl;
    double value = INFINITY;
    std::cin >> value;

    return value;
};

double Postfix::calculateOperator(char operator_, double a, double b) const
{
    switch (operator_)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            throw "Division by zero";
        return a / b;
    }
}

double Postfix::calculate()
{
    TStack<double> S; //store value
    for (int i = 0; i < postfixArray.size(); i++)
    {
        if (!isOperator(postfixArray[i])) // if operand
        {
            S.Push(operands[postfixArray[i]]);
        }
        else // if operator 
        {
            double b = S.Pop();
            double a = S.Pop();
            S.Push(calculateOperator(postfixArray[i][0], a, b));
        }
    }

    return S.Pop();
}

// Get string name of operand in source string s
std::pair<std::string, int> Postfix::getOperand(const std::string& s, int pos)
{
    std::string operandName = "";

    while (pos < s.size() && !isOperator(s[pos]))
    {
        operandName += s[pos];
        pos++;
    }

    return {operandName, pos};
}


Postfix Postfix::ConvertToPol(const std::string& s)
{
    int open = 0;
    int close = 0;
    TStack<std::string> S1(s.size());  //store operand
    TStack<char> S2(s.size());  // store operations
    for (int i = 0; i < s.size(); i++)
    {
        if (!isOperator(s[i]))
        {
            std::pair<std::string, int> op = getOperand(s, i);
            S1.Push(op.first);
            i = op.second - 1;
        }
        else if(isOperator(s[i]))
        {
            if (S2.isEmpty() || s[i] == '(')
            {
                S2.Push(s[i]);
                continue;
            }
            if (s[i] == ')')
            {
                while (!S2.isEmpty())
                {
                    char operation = S2.Pop();
                    if (operation != '(')
                    {
                        S1.Push(std::string(1, operation));
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if (GetPriority(s[i]) > GetPriority(S2.Top()))
                {
                    S2.Push(s[i]);
                }
                else {
                    while (!S2.isEmpty())
                    {
                        char operation = S2.Top();
                        if (GetPriority(operation) >= GetPriority(s[i]))
                        {
                            S1.Push(std::string(1, S2.Pop()));
                        }
                        else {
                            break;
                        }
                    }
                    S2.Push(s[i]);
                }
            }
        }
        else {
            throw "Uncorrect symbol";
        }

    }
    while (!S2.isEmpty())
    {
        S1.Push(std::string(1, S2.Pop()));
    } 

    // we got a postfix entry on stack 1, now convert it to a string
   
    std::vector<std::string> result_inverse;
    std::vector<std::string> result;

    while (!S1.isEmpty())
    {
        result_inverse.push_back(S1.Pop());
    }
    for (int i = result_inverse.size() - 1; i >= 0; i--)
    {
        result.push_back(result_inverse[i]);
    }

    Postfix postForm(result);

    return postForm;
}

int Postfix::getCountNotSpecified() {
    int count = 0;
    for (auto& operand : operands)
    {
        if (operand.second == INFINITY) {
            count += 1;
        }
    }

    return count;
}

void Postfix::setValuesFromVector(const std::vector<double>& values) {
    int countOfNotSpecified = getCountNotSpecified();
    if (countOfNotSpecified != values.size())
    {
        std::cout << "Number of provided values not equal number of not specified values\n";
        return;
    }

    int posValues = 0;
    for (auto& operand : operands)
    {
        if (operand.second == INFINITY) {
            operand.second = values[posValues++];
        }
    }
}