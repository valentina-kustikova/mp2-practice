#include "postfix_form.h"
#include "Astack.h"
#include "Lstack.h"
#include "stack.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;
#define N 30

string PostfixForm::getInfix() const
{
    return infix;
}
string PostfixForm::getPostfix() const
{
    return postfix;
}

string setInfix()
{
    string infix;
    cout << "Enter the arithmetic expression:" << endl;
    cin >> infix;
    return infix;
}
double do_operation(char operation, double a, double b)
{
    switch (operation)
    {
    case '+':
        return (a + b);
    case '-':
        return (b - a);
    case '*':
        return (a * b);
    case '/':
        return (b / a);
    default:
        break;
    }
}
char setStackType()
{
    char t;
    cout << "Press A for ArrayStack, L for ListStack:";
    cin >> t;
    switch (t)
    {
    case 'A':
        return 'A';
    case 'L':
        return 'L';
    default:
        throw "Incorrect stack type";
    }
    
}

void PostfixForm::parse()
{
    string tocken;
    char c;
    for (int i = 0; i < infix.size(); i++)
    {
        c = infix[i];
        if (i == 0 && c == '-')
        {
            tocken += c;
            continue;
        }
        if (strchr("+-*/()", c) != nullptr)
        {
            if (!(tocken.empty()))
            {
                lexems.push_back(tocken);
            }
            tocken = c;
            lexems.push_back(tocken);
            tocken.clear();
        }
        else
        {
            tocken += c;
        }

    }
    lexems.push_back(tocken);
    return;
}
void PostfixForm::to_postfix()
{
    stack<string> *operations, *operands;
    allocStack(operands, stackType);
    allocStack(operations, stackType);
    parse();

    string c, x;
    for (int i = 0; i < lexems.size(); i++)
    {
        c = lexems[i];
        if (c.find("+") != -1 || c.find("-") != -1 || c.find("*") != -1 || c.find("/") != -1)
        {
            if (c.size() > 1)
            {
                operands->push(c);
                continue;
            }
            if (!(operations->is_empty()) && priorts[c] < priorts[operations->show_top()])
            {
                while (!(operations->is_empty()) && priorts[c] < priorts[operations->show_top()])
                {
                    operands->push(operations->show_top());
                    operations->pop();
                }
                operations->push(c);
            }
            else
            {
                operations->push(c);
            }
        }
        if (c == "(")
        {
            operations->push(c);
        }
        if (c == ")")
        {
            x = operations->show_top();
            while (x != "(")
            {
                operands->push(x);
                operations->pop();
                x = operations->show_top();
            }
            operations->pop();
        }
        if (c.find("+") == -1 && c.find("-") == -1 && c.find("*") == -1 &&
            c.find("/") == -1 && c.find("(") == -1 && c.find(")") == -1)
        {
            operands->push(c);
        }
    }
    while (!(operations->is_empty()))
    {
        operands->push(operations->show_top());
        operations->pop();
    }
    while (!(operands->is_empty()))
    {
        postfix = operands->show_top() + " " + postfix;
        operands->pop();
    }
    return;
}
void PostfixForm::setOperands()
{
    string name;
    double val;
    int flag = 0;
    for (int i = 0; i < lexems.size(); i++)
    {
        name = lexems[i];
        try {
            stof(name);
        }
        catch (const invalid_argument& e) {
            if (name.find("+") == -1 && name.find("-") == -1 && name.find("*") == -1 &&
                name.find("/") == -1)
            {
                if (operands.find(name) == operands.end()) {
                    cout << "Enter value of the " << name << endl;
                    cin >> val;
                    operands[name] = val;
                }
            }
        }
    }
    return;
}
double PostfixForm::calculate()
{
    stack<double> *s;
    allocStack(s, stackType);
    int d = 0;
    char c = ' ';
    string c1, c2;
    double a, b;
    for (int i = 0; i < postfix.size(); i++)
    {
        for (int j = i; j < postfix.size(); j++)
        {
            c1 = postfix[j];
            if (c1 == " ")
            {
                break;
            }
            c2 += c1;
            d++;
        }
        i += d;
        if (c2.size() == 1)
        {
            c = c2[0];
        }
        if (strchr("+-*/", c) != nullptr)
        {
            a = s->show_top();
            s->pop();
            b = s->show_top();
            s->pop();
            s->push(do_operation(c, a, b));
            
        }
        else if (operands.count(c2) == 1)
        {
            s->push(operands[c2]);
        }
        else
        {
                s->push(stof(c2));
        }
        c2.clear();
        d = 0;
    }
    return s->show_top();
}

template <typename TElem>
void allocStack(stack<TElem>*& s, char stackType)
{
    switch (stackType)
    {
    case 'A':
        s = new Astack<TElem>(N);
        break;
    case 'L':
        s = new Lstack<TElem>();
        break;
    }
    return;
}