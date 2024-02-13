#include <iostream>
#include "talgorithm.h"
#include <set>
#include <string>

vector<string> Talgorithm::splitTalgorithm(const string& expression) {
    vector<string> result;
    string currentToken;

    for (char ch : expression) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
            if (!currentToken.empty()) {
                result.push_back(currentToken);
                currentToken.clear();
            }
            result.push_back(string(1, ch));
        }
        else if (isspace(ch)) {
            continue;
        }
        else {
            currentToken += string(1,ch);
        }
    }
    if (!currentToken.empty()) {
        result.push_back(currentToken);
    }
    return result;
}

int Talgorithm::getPrecedence(const string& op) {
    if (op == "+" || op == "-") {
        return 1;
    }
    else if (op == "*" || op == "/") {
        return 2;
    }
    return 0;
}
bool Talgorithm::isOperator(const string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

void Talgorithm::isValidTalgorithm(const vector<string>& infixTalgorithm) {
    if (isOperator(infixTalgorithm[0])) throw invalid_argument("Ошибка1: \n");
    else if (isOperator(infixTalgorithm[infixTalgorithm.size() - 1])) throw invalid_argument("Ошибка2: \n");
    else {
        for (int i = 0; i < infixTalgorithm.size() - 1; i++) {
            if (isOperator(infixTalgorithm[i]) && isOperator(infixTalgorithm[i + 1])) throw invalid_argument("Ошибка3: \n");
            if (infixTalgorithm[i] == "/" && infixTalgorithm[i + 1] == "0") throw invalid_argument("Ошибка4: \n");
        }
    }
}


map<string, double> Talgorithm::getOperandValues(const vector<string>& tokens) {
    map<string, double> operandValues;

    for (const auto& token : tokens) {
        if (token != "+" && token != "-" && token != "*" && token != "/" && token != "(" && token != ")") {
            if (operandValues.find(token) == operandValues.end()) {
                double value;
                if (token.find_first_not_of("0123456789.") == string::npos) {
                    operandValues[token] = stod(token);
                    continue;
                }
                cout << "Enter operand value " << token << ": ";
                cin >> value;
                operandValues[token] = value;
            }
        }
    }
    return operandValues;
}

Stack<string> Talgorithm::infixToPostfix(const vector<string>& infixTalgorithm) {
    Stack<string>operands;
    Stack<string> operators;

    for (const string& token : infixTalgorithm) {
        if (isalnum(token[0])) {
            operands.push(token);
        }
        else if (isOperator(token)) {
            while (!operators.isEmpty() && getPrecedence(operators.top()) >= getPrecedence(token)) {
                operands.push(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
        else if (token == "(") {
            operators.push(token);
        }
        else if (token == ")") {
            while (!operators.isEmpty() && operators.top() != "(") {
                operands.push(operators.top());
                operators.pop();
            }
            operators.pop();
        }
    }

    while (!operators.isEmpty()) {
        operands.push(operators.top());
        operators.pop();
    }

    Stack<string> tmp;
    string result_inverse = "";
    tmp = operands;
    while (!tmp.isEmpty())
    {
        result_inverse += tmp.pop();
    }
    string result = "";
    for (int i = result_inverse.size() - 1; i >= 0; i--)
    {
        result.push_back(result_inverse[i]);
    }

    cout << result << endl;
    
    return operands;
}

double Talgorithm::evaluatePostfixTalgorithm(const map<string, double>& operandValues, Stack<string>& postfixTalgorithm) {
    Stack<double> resultStack;
    Stack<string> tmp = postfixTalgorithm;
    while (!postfixTalgorithm.isEmpty()) {
        postfixTalgorithm.pop();
    }
    while (!tmp.isEmpty()) {
        string str = tmp.top();
        postfixTalgorithm.push(str);
        tmp.pop();
    }

    while (!postfixTalgorithm.isEmpty()) {
        const string token = postfixTalgorithm.top();
        postfixTalgorithm.pop();

        if (!(isOperator(token))) {
            if (operandValues.find(token) != operandValues.end()) {
                resultStack.push(operandValues.at(token));
            }
            else {
                cerr << "Error: operands value '" << token << "' not exist.\n";
                return 0.0;
            }
        }
        else {
            double operand2 = resultStack.top();
            resultStack.pop();

            double operand1 = resultStack.top();
            resultStack.pop();

            if (token == "+") {
                resultStack.push(operand1 + operand2);
            }
            else if (token == "-") {
                resultStack.push(operand1 - operand2);
            }
            else if (token == "*") {
                resultStack.push(operand1 * operand2);
            }
            else if (token == "/") {
                if (operand2 == 0) {
                    cerr << "ERROR: divizion by zero.\n";
                    return 0.0;
                }
                resultStack.push(operand1 / operand2);
            }
        }
    }
    return resultStack.top();
}