

#pragma once
using namespace std;
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept> // ��� ����������
#include "stack.h"
#include "stack_array.h" // ��� ����� �� �������
#include "List_stack.h" // ��� ����� �� ������
#include "List.h" 
#include <iostream>
#include <map>


template <typename T>
class PostfixForm {
public:
    // �����������, ��������� ��� ����� � ������ (��� Array_Stack)
    PostfixForm(bool useArrayStack, int arrayStackSize = 100);
    ~PostfixForm();

    string InfixToPostfix(const  string& infix); // �������������� � ����������� ������
    string GetPostfix() const;// ����� ����������� ������
    T �alculatePostfix(const string& postfix) const; // �� string � ��������
    map<char, T> GetVariableValues(const string& postfix) const;
    map<char, double> operands;
private:
    Stack<T>* stack;// ��� ����� ��� ����������
    string postfixResult;// ��������� ����������� ������ 

    bool isOperator(char c) const;// �������� �������� ��
    int Priority(char op) const;// ����������  ��������� ��������
    T ToDoOperation(T operand1, T operand2, char operation) const;//���������� �������� ����� ����� ����������
};


template <typename T>
PostfixForm<T>::PostfixForm(bool useArrayStack, int arrayStackSize) : postfixResult("")
{
    stack = nullptr;
    try {
        if (useArrayStack) {
            stack = new Array_Stack<T>(arrayStackSize);
        }
        else {
            stack = new ListStack<T>();
        }
    }
    catch (...) {
        delete stack;
        throw;
    }
}

template <typename T>
PostfixForm<T>::~PostfixForm() {
    delete stack;
}

template <typename T>
bool PostfixForm<T>::isOperator(char c) const
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

template <typename T>
int PostfixForm<T>::Priority(char operation) const {
    if (operation == '*' || operation == '/') {
        return 2;
    }
    if (operation == '+' || operation == '-') {
        return 1;
    }
    return 0;
}


template <typename T>
string PostfixForm<T>::InfixToPostfix(const string& infix) {
    string postfix_res = "";
    Array_Stack<char> stack(infix.size());

    for (size_t i = 0; i < infix.size(); ++i) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix_res += c;
            postfix_res += " ";
        }
        else if (c == '(') {
            stack.Push(c);
        }
        else if (c == ')') {
            while (!stack.IsEmpty() && stack.Top() != '(') {
                postfix_res += stack.Top();
                postfix_res += " ";
                stack.Pop();
            }
            if (!stack.IsEmpty())
                stack.Pop(); //������� '('
            else
                throw ("problem with parentheses");
        }
        else if (isOperator(c)) {
            while (!stack.IsEmpty() && Priority(stack.Top()) >= Priority(c)) {
                postfix_res += stack.Top();
                postfix_res += " ";
                stack.Pop();
            }
            stack.Push(c);
        }
        else if (c != ' ') {
            throw ("Invalid character in infix expression");
        }

    }
    while (!stack.IsEmpty()) {
        if (stack.Top() == '(')
            throw ("problem with parentheses");
        postfix_res += stack.Top();
        postfix_res += " ";
        stack.Pop();
    }

    return postfix_res;
}

template <typename T>
string PostfixForm<T>::GetPostfix() const {
    return postfixResult;
}

template <typename T>
T PostfixForm<T>::ToDoOperation(T operand1, T operand2, char operation) const {
    switch (operation) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 == 0) {
            throw ("Division by zero");
        }
        return operand1 / operand2;
    default:
        throw ("Invalid operator");
    }
}

template <typename T>
T PostfixForm<T>::�alculatePostfix(const string& postfix) const {
    stringstream ss(postfix);
    string token;
    Stack<T>* evaluationStack = nullptr;

    if (dynamic_cast<Array_Stack<T>*>(stack)) {
        evaluationStack = new Array_Stack<T>(postfix.length());
    }
    else {
        evaluationStack = new ListStack<T>();
    }

    try {
        while (ss >> token) {
            T number;
            try {
                size_t pos;
                number = stod(token, &pos);// ������ � �����

                // ���������, ��� ��� ������ ���� ������������� � �����
                if (pos != token.length()) {
              
                    throw invalid_argument("Not a number"); // �������� ����������� ����������, ����� ����������� ��� ����.
                }

                evaluationStack->Push(number);
            }
            catch (const invalid_argument& e) {
                //  ���������, �������� �� ����� ���������� ��� ����������
                if (token.length() == 1 && isOperator(token[0])) {
                    if (evaluationStack->Size() < 2) {
                        delete evaluationStack;
                        throw runtime_error("Not enough operands for operator " + token);
                    }
                    T operand2 = evaluationStack->Top();
                    evaluationStack->Pop();
                    T operand1 = evaluationStack->Top();
                    evaluationStack->Pop();

                    try {
                        T result = ToDoOperation(operand1, operand2, token[0]);
                        evaluationStack->Push(result);
                    }
                    catch (const runtime_error& e) {
                        delete evaluationStack;
                        throw;
                    }
                }
                else if (token.length() == 1 && isalpha(token[0])) { // ���������, �������� �� ����� ����������
                    if (operands.count(token[0]) > 0) {
                        evaluationStack->Push(static_cast<T>(operands.at(token[0]))); // ����������� double � ���� T
                    }
                    else {
                        delete evaluationStack;
                        throw runtime_error("Undefined variable: " + token);
                    }
                }
                else {
                    delete evaluationStack;
                    throw runtime_error("Invalid token in postfix expression: " + token);
                }
            }
        }

        if (evaluationStack->Size() == 1) {
            T result = evaluationStack->Top();
            evaluationStack->Pop();
            delete evaluationStack;
            return result;
        }
        else {
            delete evaluationStack;
            throw runtime_error("Too many operands in postfix expression");
        }
    }
    catch (...) {
        delete evaluationStack;
        throw;
    }
}


template <typename T>
map<char, T> PostfixForm<T>::GetVariableValues(const std::string& postfix) const {
    map<char, T> values;
    for (char c : postfix) {
        if (isalpha(c) && values.find(c) == values.end()) {
            T value;
            cout << "Enter value for '" << c << "': ";
            cin >> value;

            // ���������, ��� ���� �������
            if (cin.fail()) {
                cerr << "Invalid input. Please enter a valid number." << std::endl;
                cin.clear();  
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����� �����
                value = 0; //�������� �� ���������
            }

            values[c] = value;
        }
    }
    return values;
}