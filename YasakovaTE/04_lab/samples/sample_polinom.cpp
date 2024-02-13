#include "talgorithm.h"
#include <iostream>
int main() {
    try {
        string inputTalgorithm;
        cout << "Enter expression: ";
        getline(cin, inputTalgorithm);

        vector<string> tokens = Talgorithm::splitTalgorithm(inputTalgorithm);

        Talgorithm::isValidTalgorithm(tokens);

        Stack<string> res = Talgorithm::infixToPostfix(tokens);

        map<string, double> opVal = Talgorithm::getOperandValues(tokens);
        cout << Talgorithm::evaluatePostfixTalgorithm(opVal, res);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}


