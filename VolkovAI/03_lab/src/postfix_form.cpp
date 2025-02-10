#include "postfix_form.h"

void menu() {
    setlocale(LC_ALL, "Russian");
    string expression;
    cout << "Введите инфиксное выражение: ";
    cin >> expression;

    int stack_choice;
    cout << "Выберите тип стека (0 - стек на массивах, 1 - стек на списках): ";
    cin >> stack_choice;

    if (stack_choice != 0 && stack_choice != 1) {
        throw invalid_argument("Некорректный выбор стека.");
    }
    ReversePolishNotation rpn(expression, static_cast<Stack_type>(stack_choice));

    cout << "Постфиксная запись: " << rpn.get_postfix() << endl;

    map<string, double> values;
    for (int i = 0; i < expression.size(); i++) {
        char ch = expression[i];
        if (isalpha(ch) && !values.count(string(1, ch))) {
            double value;
            cout << "Введите значение для переменной " << ch << ": ";
            cin >> value;
            values[string(1, ch)] = value;
        }
    }

    double result = rpn.evaluate_postfix(values);
    cout << "Результат: " << result << endl;
}

void ReversePolishNotation::convert_expression_to_RPN() {
    Stack<string>* operator_stack, * operands_stack;
    stack_allocate(operator_stack, type);
    stack_allocate(operands_stack, type);

    infix_handling();
    to_RPN(*operator_stack, *operands_stack);

    delete operator_stack;
    delete operands_stack;
}
void ReversePolishNotation::infix_handling() {
    string token;
    char c;
    for (size_t i = 0; i < infix.size(); i++) {
        c = infix[i];
        if (i == 0 && c == '-') {
            token += c;
        }
        if (strchr("+-*/()", c) != nullptr) {
            if (!(token.empty())) {
                symbols.push_back(token);
            }
            token = c;
            symbols.push_back(token);
            token.clear();
        }
        else {
            token += c;
        }

    }
    symbols.push_back(token);
    return;
}

void ReversePolishNotation::to_RPN(Stack<string>& operator_stack, Stack<string>& operand_stack) {
    string symbol;
    for (size_t i = 0; i < symbols.size(); i++) {
        symbol = symbols[i];

        if (isdigit(symbol[0]) || isalpha(symbol[0])) {
            operand_stack.push(symbol);
            continue;
        }
        if (symbol == "(") {
            operator_stack.push(symbol);
            continue;
        }
        if (symbol == ")") {
            while (!operator_stack.isEmpty() && operator_stack.showTop() != "(") {
                operand_stack.push(operator_stack.showTop());
                operator_stack.pop();
            }
            operator_stack.pop();
            continue;
        }

        if (priorities.count(symbol)) {
            if (symbol.size() > 1) { // отрицательные
                operand_stack.push(symbol);
                continue;
            }
            while (!operator_stack.isEmpty() && priorities[symbol] <= priorities[operator_stack.showTop()]) {
                operand_stack.push(operator_stack.showTop());
                operator_stack.pop();
            }
            operator_stack.push(symbol);
            continue;
        }
    }

    while (!operator_stack.isEmpty()) {
        operand_stack.push(operator_stack.showTop());
        operator_stack.pop();
    }

    while (!operand_stack.isEmpty()) {
        postfix = operand_stack.showTop() + postfix;
        operand_stack.pop();
    }
}

double ReversePolishNotation::evaluate_postfix(const map<string, double>& values) {
    Stack<double>* stack;
    stack_allocate(stack, type);

    string symbol;
    for (size_t i = 0; i < postfix.size(); i++) {
        symbol = get_postfix()[i]; 
        if (isdigit(symbol[0]) || (symbol.size() > 1 && symbol[0] == '-')) {
            stack->push(stod(symbol));
        }
        else if (values.count(symbol)) {
            stack->push(values.at(symbol));
        }
        else if (symbol == "(" || symbol == ")") {
            continue; 
        }
        else {
            double b = stack->showTop(); stack->pop();
            double a = stack->showTop(); stack->pop();

            if (symbol == "+") stack->push(a + b);
            else if (symbol == "-") stack->push(a - b);
            else if (symbol == "*") stack->push(a * b);
            else if (symbol == "/") stack->push(a / b);
        }
    }
    double result = stack->showTop();
    stack->pop();
    delete stack;
    return result;
}

string ReversePolishNotation::get_postfix() const {
    return postfix;
}