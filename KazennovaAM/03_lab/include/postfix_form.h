#pragma once
using namespace std;
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept> // Для исключений
#include "stack.h"
#include "stack_array.h" // Для стека на массиве
#include "List_stack.h" // Для стека на списке
#include "List.h" 
#include <iostream>
#include <map>


template <typename T>
class PostfixForm {
public:
    // Конструктор, принимает тип стека и размер (для Array_Stack)
    PostfixForm(bool useArrayStack, int arrayStackSize = 100);
    ~PostfixForm();

    string InfixToPostfix(const  string& infix); // Преобразование в постфиксную запись
    string GetPostfix() const;// Вывод постфиксной записи
    T EvaluatePostfix(const string& postfix) const; // 
    map<char, T> GetVariableValues(const string& postfix) const;
private:
    Stack<T>* stack;// Тип стека для вычислений
    string postfixResult;// Результат постфиксной записи 

    bool isOperator(char c) const;// Проверка на оператор
    int Priority(char op) const;// Приоритет оператора
    T ToDoOperation(T operand1, T operand2, char operation) const;
    // Выполнение операции
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
    std::string postfix_res = "";
    Array_Stack<char> brackets_stack(infix.size());

    for (size_t i = 0; i < infix.size(); ++i) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix_res += c;
            postfix_res += " ";
        }
        else if (c == '(') {
            brackets_stack.Push(c);
        }
        else if (c == ')') {
            while (!brackets_stack.IsEmpty() && brackets_stack.Top() != '(') {
                postfix_res += brackets_stack.Top();
                postfix_res += " ";
                brackets_stack.Pop();
            }
            if (!brackets_stack.IsEmpty())
                brackets_stack.Pop(); //удаляем '('
            else
                throw ("Unbalanced parentheses");
        }
        else if (isOperator(c)) {
            while (!brackets_stack.IsEmpty() && Priority(brackets_stack.Top()) >= Priority(c)) {
                postfix_res += brackets_stack.Top();
                postfix_res += " ";
                brackets_stack.Pop();
            }
            brackets_stack.Push(c);
        }
        else if (c != ' ') {
            throw ("Invalid character in infix expression");
        }

    }
    while (!brackets_stack.IsEmpty()) {
        if (brackets_stack.Top() == '(')
            throw ("Unbalanced parentheses");
        postfix_res += brackets_stack.Top();
        postfix_res += " ";
        brackets_stack.Pop();
    }
   
    return postfix_res;
}

template <typename T>
std::string PostfixForm<T>::GetPostfix() const {
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
T PostfixForm<T>::EvaluatePostfix(const string& postfix) const {
    stringstream ss(postfix);
    string token;
    Stack<T>* evaluationStack = nullptr;

    if (dynamic_cast<Array_Stack<T>*>(stack)) {
        evaluationStack = new Array_Stack<T>(postfix.length());
    }
    else {
        evaluationStack = new ListStack<T>();
    }


    while (ss >> token) {
        if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1]))) { // Проверяем, является ли token числом (поддержка многозначных чисел)
            T number;
            try {
                number = std::stod(token);
            }
            catch (const std::invalid_argument& e) {
                delete evaluationStack;
                throw runtime_error("Invalid number in postfix expression: " + std::string(e.what()));
            }
            evaluationStack->Push(number);
        }
        else if (isOperator(token[0])) {
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
        else {
            delete evaluationStack;
            throw ("Invalid token in postfix expression: " + token);
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
        throw ("Too many operands in postfix expression");
    }
}
template <typename T>
map<char, T> PostfixForm<T>::GetVariableValues(const string& postfix) const {
    map<char, T> values;
    for (char c : postfix) {
        if (isalpha(c) && values.find(c) == values.end()) {
            T value;
            cout << "Enter value for '" << c << "': ";
            cin >> value;
            values[c] = value;
        }
    }
    return values;
}

