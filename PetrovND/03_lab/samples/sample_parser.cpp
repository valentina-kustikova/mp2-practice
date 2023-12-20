#include "parser.h"
#include <iostream>
int main() {
    try {
        string inputExpression;
        cout << "Enter expression: ";
        getline(cin, inputExpression);

        vector<string> tokens = Parser::splitExpression(inputExpression);

        Parser::isValidExpression(tokens);

        vector<string> res = Parser::infixToPostfix(tokens);

        map<string, double> opVal = Parser::getOperandValues(tokens);
        cout << Parser::evaluatePostfixExpression(opVal, res);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}