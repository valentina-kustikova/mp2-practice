#include "talgorithm.h"
#include "tstack.h"
#include <iostream>
#include <string>
#include <stdexcept>

int Polsk::GetPriority(const char op)
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

bool  Polsk::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

//for struct Operand
std::ostream& operator<<(std::ostream& out, const Operand& op)
{
    out << op.name;
    return out;
};

void Operand::SetValue()
{
    std::cout << "Enter variable value for \"" << name << "\"" << std::endl;
    std::cin >> value;
};

bool Operand::isSpecified() {
    if ((value == INFINITY) && (isSign == false)) {
        return false;
    }

    return true;
}

//for class Postfix

Postfix::Postfix()
{
    operands = std::vector<Operand>();
    s_postfix = "";
}

Postfix::Postfix(std::vector<Operand> postf)
{
    operands = postf;
    s_postfix = "";
    for (int i = 0; i < postf.size(); i++)
    {
        s_postfix += postf[i].name;
        s_postfix += " ";
    }
}

void Postfix::setValues()
{
    std::map <std::string, double> readyOperands;
    for (int i = 0; i < operands.size(); i++)
    {
        if (!operands[i].isSpecified())
        {
            if (readyOperands.find(operands[i].name) != readyOperands.end()) //found a match 
            {
                operands[i].value = readyOperands[operands[i].name];
            }
            else
            {
                operands[i].SetValue();
                readyOperands[operands[i].name] = operands[i].value;
            }
        }

    }
};

double Postfix::calculateOperator(char operator_, double a, double b)
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
        return a / b;
    }
}

double Postfix::calculate()
{
    TStack<double> S; //store value
    for (int i = 0; i < operands.size(); i++)
    {
        if (operands[i].isSign == false) // if operand
        {
            S.Push(operands[i].value);
        }
        else //if operator 
        {
            double b = S.Pop();
            double a = S.Pop();
            S.Push(calculateOperator(operands[i].name[0], a, b));
        }
    }
    return S.Pop();
}

//namespace Polsk

std::pair<Operand, int> Polsk::getOperand(std::string s, int pos)
{
    Operand tmp;
    tmp.isSign = false;
    tmp.name = "";
    tmp.value = INFINITY;

    while (pos < s.size() && !isOperator(s[pos]))
    {
        tmp.name += s[pos];
        pos++;
    }
    try {
        tmp.value = std::stof(tmp.name);
    }
    catch (std::invalid_argument const& ex)
    {
    };

    return {tmp, pos};
}

Postfix Polsk::ConvertToPol(std::string s)
{
    int open = 0;
    int close = 0;
    TStack<Operand> S1(s.size());  //store operand
    TStack<char> S2(s.size());  // store operations
    for (int i = 0; i < s.size(); i++)
    {
        if (!isOperator(s[i]))
        {
            std::pair<Operand, int> op = getOperand(s, i);
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
                    Operand elem;
                    elem.name = S2.Pop();
                    if (elem.name != "(")
                    {
                        S1.Push(elem);
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
                        char elem = S2.Top();
                        if (GetPriority(elem) >= GetPriority(s[i]))
                        {
                            Operand a;
                            a.name = S2.Pop();
                            S1.Push(a);
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
        Operand b;
        b.name = S2.Pop();
        S1.Push(b);
    } 

    // we got a postfix entry on stack 1, now convert it to a string
   
    std::vector<Operand> result_inverse;
    std::vector<Operand> result;

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
    std::set<std::string> unique;
    for (int i = 0; i < operands.size(); i++)
    {
        if ((!operands[i].isSpecified()) && (unique.find(operands[i].name) == unique.end()))
        {
            count += 1;
            unique.insert(operands[i].name);
        }
    }

    return count;
}

void Postfix::setValuesFromVector(const std::vector<double>& values) {
    int countOfNotSpecified = getCountNotSpecified();
    std::map <std::string, double> readyOperands;
    std::cout << countOfNotSpecified << " " << values.size() << '\n';
    if (countOfNotSpecified != values.size())
    {
        std::cout << "Number of provided values not equal number of not specified values\n";
        return;
    }

    int posValues = 0;
    for (int i = 0; i < operands.size(); i++)
    {
        if (!operands[i].isSpecified()) {
            if (readyOperands.find(operands[i].name) != readyOperands.end()) //нашли совпадение 
            {
                operands[i].value = readyOperands[operands[i].name];
            }
            else
            {
                operands[i].value = values[posValues++];
                readyOperands[operands[i].name] = operands[i].value;
            }
        }
    }   
}