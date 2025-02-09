#include "stack.h"
#include "Liststack.h"
#include "postfix_form.h"
#include "Arraystack.h"


#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;
#define N 40


string PostfixForm::getPostfix() const
{
    return postfix;
}

string PostfixForm::getInfix() const
{
    return infix;
}

string setInfix()
{
    string infix;
    cout << "Input:" << endl;
    cin >> infix;
    return infix;
}

void PostfixForm::parsing()
{
    string token;
    char c;
    for (size_t i = 0; i < infix.size(); ++i)
    {
        c = infix[i];

        if (i == 0 && c == '-')
        {
            token += c;
            continue;
        }

        if (string("+-*/()").find(c) != string::npos)
        {
            if (!token.empty())
            {
                lex.push_back(token);
            }
            lex.push_back(string(1, c));
            token.clear();
        }
        else
        {
            token += c;
        }
    }

    if (!token.empty())
    {
        lex.push_back(token);
    }
}

void PostfixForm::to_postfix() {
    stack<string>* operations, * operands;
    allocateStack(operands, type_of_stack);
    allocateStack(operations, type_of_stack);
    parsing();

    string currentToken, tempToken;

    for (size_t i = 0; i < lex.size(); i++) {
        currentToken = lex[i];

        if (currentToken == "+" || currentToken == "-" || currentToken == "*" || currentToken == "/") {

            if (currentToken.length() > 1) {
                operands->push(currentToken);
                continue;
            }

            while (!operations->is_empty() && priority[currentToken] < priority[operations->show_top()]) {
                operands->push(operations->show_top());
                operations->pop();
            }
            operations->push(currentToken);
        }

        else if (currentToken == ")") {
            tempToken = operations->show_top();
            while (tempToken != "(") {
                operands->push(tempToken);
                operations->pop();
                tempToken = operations->show_top();
            }
            operations->pop();
        }


        else if (currentToken == "(") {
            operations->push(currentToken);
        }


        else {
            operands->push(currentToken);
        }
    }
    while (!operations->is_empty()) {
        operands->push(operations->show_top());
        operations->pop();
    }
    while (!operands->is_empty()) {
        postfix = operands->show_top() + " " + postfix;
        operands->pop();
    }

    return;
}

void PostfixForm::setOp()
{
    for (const auto& name : lex)
    {
        double value;
        if (isOperand(name))
        {
            if (operands.find(name) == operands.end())
            {
                cout << "Input value of " << name << ": ";
                cin >> value;
                operands[name] = value;
            }
        }
    }
}

void PostfixForm::setOp(map<string, double> operndes) {
    operands = operndes;
}


bool PostfixForm::isOperand(const string& name) const
{
    try {
        stof(name);
        return false; 
    }
    catch (const invalid_argument&) {
        
        return (name.find_first_of("+-*/()") == string::npos); 
    }
}

double PostfixForm::count()
{
    stack<double>* s;
    allocateStack(s, type_of_stack); 
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
            s->push(do_op(c, a, b));

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

double do_op(char op, double A, double B)
{
    switch (op)
    {
    case '-':
        return (B - A);
    case '+':
        return (A + B);
    case '*':
        return (A * B);
    case '/':
        return (B / A);
    default:
        break;
    }
}

char set_type_of_stack()
{
    char t;
    cout << "Input L for Liststack OR input A for Arraystack: ";
    cin >> t;
    switch (t)
    {
    case 'L':
        return 'L';
    case 'A':
        return 'A';
    default:
        throw "We don't have this type of stack";
    }

}

template <typename TElem>
void allocateStack(stack<TElem>*& s, char type_of_stack)
{
    switch (type_of_stack)
    {
    case 'L':
        s = new Liststack<TElem>();
        break;
    case 'A':
        s = new Arraystack<TElem>(N);  
        break;
    }
    return;
}