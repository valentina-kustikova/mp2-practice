#include <iostream>
#include "postfix_form.h"
#include <unordered_map>
#include <string>
#include <vector>
#include "array_stack.h"
#include "list_stack.h"

#include <sstream>
#include <cctype> 

using namespace std;



ArithmeticExpression::ArithmeticExpression(const string& s1, STACK_IMPL impl1) {
    expr = convert(s1);
    impl = impl1;
}


vector<string> ArithmeticExpression::convert(const string& input) {
    string expr = removeSpaces(input);
    vector<string> answ;
    stringstream ss; 

    for (size_t i = 0; i < expr.length(); ++i) {
        char c = expr[i];

        if (is_op(c)) {
            // проверка на - перед const
            if (ss.str().empty()) { 
                if (c == '-') {
                    ss << c;
                    continue;
                }
                else {
                    throw "wrong expression";
                }
            }
            answ.push_back(ss.str());
            answ.push_back(std::string(1, c));
            ss.str(""); //очистка
        }
        else if (c == '(' || c == ')') {
            if (!ss.str().empty()) {
                answ.push_back(ss.str());
                ss.str(""); //очистка
            }
            answ.push_back(std::string(1, c));
        }
        else if (std::isdigit(c) || c == '.') { //проверка на число double
            ss << c;
        }
        else if (!std::isspace(c)) { 
            ss << c;
        }

    }

    if (!ss.str().empty()) {
        answ.push_back(ss.str());
    }

    return answ; 
}



// chatgpt
std::string removeSpaces(const std::string& str) {
    std::string result = str; 
    result.erase(std::remove_if(result.begin(), result.end(), 
        [](char c) { return std::isspace(c); }), result.end());
    return result;
}



bool is_op(char el) {
    return el == '*' || el == '/' || el == '+' || el == '-';
}

bool is_op(string el) {
    return el == "*" || el == "/" || el == "+" || el == "-";
}

int op_priority(char el) {
    if (el == '*' || el == '/') {
        return 3;
    }
    else if (el == '-' || el == '+') {
        return 2;

    }
    return 1;

    // операция - имеет свой приоритет
    // тк постфиксная форма не будет
    // строиться правильно
}

int op_priority(string el) {
    if (el == "*" || el == "/") {
        return 3;
    }
    else if (el == "-" || el == "+") {
        return 2;
    }
    return 1;

    // операция - имеет свой приоритет
    // тк постфиксная форма не будет
    // строиться правильно
}

double make_op(double a, double b, string op) {
    switch (op[0])
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default:
        break;
    }
}



unordered_map<string, double> ArithmeticExpression::fill_variables() {
    unordered_map<string, double> values;
    for (string s : expr) {
        if (is_op(s) || s == "(" || s == ")") {
            continue;
        }
        if (values.find(s) == values.end()) {
            if (s[0] == '-' || '0' <= s[0] && s[0] <= '9') {
                values[s] = stoi(s);
                continue;
            }

            cout << "Type value: \n";
            cout << s << " = ";
            double val;
            cin >> val;
            values[s] = val;
        }
    }
    return values;
}




double ArithmeticExpression::compute(
    const unordered_map<string, double>& values) {

    vector<string> pf;
    if (impl == ARRAY_STACK) {
        ArrayStack<string> op;
        

        for (string el : expr) {

            // является операндом/числом
            if (!is_op(el) && el != "(" && el != ")") {
                pf.push_back(el);
                continue;
            } 

            // является оператором
            if (is_op(el)) {
                if (op.IsEmpty()) {
                    op.push(el);
                    continue;
                }
                else {


                    while (!op.IsEmpty() && op_priority(el) <= op_priority(op.Top())) {
                        pf.push_back(op.Top());
                        op.pop();
                    }
                    op.push(el);
                    continue;
                }
            }

            if (el == "(") {
                op.push(el);
                continue;
            }
            if (el == ")") {
                while (op.Top() != "(") {
                    pf.push_back(op.Top());
                    op.pop();
                }
                op.pop();
                continue;
            }


        }
        while (!op.IsEmpty()) {
            pf.push_back(op.Top());
            op.pop();
        }
        

    }
    else {
        ListStack<string> op;


        for (string el : expr) {

            // является операндом/числом
            if (!is_op(el) && el != "(" && el != ")") {
                pf.push_back(el);
                continue;
            }

            // является оператором
            if (is_op(el)) {
                if (op.IsEmpty()) {
                    op.push(el);
                    continue;
                }
                else {


                    while (!op.IsEmpty() && op_priority(el) <= op_priority(op.Top())) {
                        pf.push_back(op.Top());
                        op.pop();
                    }
                    op.push(el);
                    continue;
                }
            }

            if (el == "(") {
                op.push(el);
                continue;
            }
            if (el == ")") {
                while (op.Top() != "(") {
                    pf.push_back(op.Top());
                    op.pop();
                }
                op.pop();
                continue;
            }


        }
        while (!op.IsEmpty()) {
            pf.push_back(op.Top());
            op.pop();
        }
    }
    cout << "\nPostfix form:\n";
    for (string el : pf) {
        cout << el << " ";
    }
    cout << '\n';

    unordered_map<string, double> vals = values;
    vals = fill_variables();

    double answ = 0;


    if (impl == ARRAY_STACK) {
        ArrayStack<double> variables;
        for (string el : pf) {
            if (is_op(el)) {
                double b = variables.Top();
                variables.pop();
                double a = variables.Top();
                variables.pop();

                variables.push(make_op(a,b,el));
                continue;
            }
            variables.push(vals[el]);

        }
        answ = variables.Top();
    }
    else {
        ListStack<double> variables;
        for (string el : pf) {
            if (is_op(el)) {
                double b = variables.Top();
                variables.pop();
                double a = variables.Top();
                variables.pop();

                variables.push(make_op(a, b, el));
                continue;
            }
            variables.push(vals[el]);

        }
        answ = variables.Top();
    }


    return answ;
}


















//string postfixform(string input, ArrayStack<string>& names) {
//    input.push_back(' ');
//
//    ArrayStack<char> op; // (1)
//    string name;
//    string answ;
//    for (int i = 0; i < input.size(); i++) {
//        char el = input[i];
//
//        if (el == '(') {
//            if (name.size() != 0) {
//                 
//                answ += name; //
//                 
//                name.clear();
//            }
//            op.push(el);
//            continue;
//        }
//
//        if (is_op(el)) {
//            if (i == (input.size()-1)) {
//                throw "wrong expression";
//            }
//            if (el == '-' && '1' <= input[i + 1] && input[i + 1] <= '9') {
//                name.push_back(el);
//                continue;
//            }
//            else if (el == '-' && input[i + 1] == '0') {
//                throw "wrong expression";
//            }
//            if (is_op(input[i - 1])) {
//                if (el == '-' && '1' <= input[i + 1] && input[i + 1] <= '9') {
//                    name.push_back(el);
//                    continue;
//                }
//                if (input[i + 1] == '0') {
//                    throw "wrong expression";
//                }
//            }
//
//
//            if (name.size() != 0) {
//                 
//                answ += name; //
//                 
//                name.clear();
//            }
//
//            while (!op.IsEmpty() && op_priority(el) < op_priority(op.Top())) {
//                string tmp;
//                tmp.push_back(op.Top());
//                 
//                answ.push_back(op.Top()); //
//                 
//                op.pop();
//            }
//
//            op.push(el);
//            continue;
//        }
//
//        if (el == ')') {
//            if (name.size() != 0) {
//                 
//                answ += name; //
//                 
//                name.clear();
//            }
//
//            while (!op.IsEmpty() && op.Top() != '(') {
//                string tmp;
//                tmp.push_back(op.Top());
//                 
//                answ.push_back(op.Top()); //
//                 
//                op.pop();
//            }
//            /*if (op.IsEmpty()) {
//                throw "wrong expression";
//            }*/
//            op.pop();
//            continue;
//        }
//
//        if (el == ' ') {
//            if (name.size() != 0) {
//                 
//                answ += name; //
//                answ += " ";
//                name.clear();
//            }
//            continue;
//        }
//
//        name.push_back(el);
//    }
//
//    while (!op.IsEmpty()) {
//        string tmp;
//        tmp.push_back(op.Top());
//         
//        answ.push_back(op.Top()); //
//         
//        op.pop();
//    }
//
//    input.pop_back();
//    return answ;
//}
//
//

//

//
//bool is_number(string s) {
//    if ('0' <= s[0] && s[0] <= '9' ||
//        s[0] == '-' && '0' <= s[1] && s[1] <= '9') {
//        return 1;
//    }
//    return 0;
//}
//
//
//
//
//double solvepf(ArrayStack<string> pf) {
//    ArrayStack<double> vars; // variables
//    ArrayStack<string> rpf; // reversed pf
//    unordered_map<string, double> values;
//    while (!pf.IsEmpty()) {
//        rpf.push(pf.Top());
//        pf.pop();
//    }
//
//
//    while (!rpf.IsEmpty()) {
//        if (is_op(rpf.Top())) {
//            double b = vars.Top();
//            vars.pop();
//            double a = vars.Top();
//            vars.pop();
//            vars.push(make_op(a, b, rpf.Top()[0]));
//            rpf.pop();
//             
//        }
//        else {
//            if (values.find(rpf.Top()) != values.end()) {
//                vars.push(values[rpf.Top()]);
//                rpf.pop();
//                continue;
//            }
//            else {
//                if (is_number(rpf.Top())) {
//                    vars.push(stod(rpf.Top()));
//                    rpf.pop();
//                } else if (values.find(rpf.Top()) == values.end()) {
//                    cout << "Type value of " << rpf.Top() << '\n';
//                    cin >> values[rpf.Top()];
//                    vars.push(values[rpf.Top()]);
//                    rpf.pop();
//                    
//                }            
//            }
//        }
//    }  
//    return vars.Top();
//}
//
//
//
//double test_solvepf(ArrayStack<string> pf, unordered_map<string, double> v) {
//    ArrayStack<double> vars; // variables
//    ArrayStack<string> rpf; // reversed pf
//    unordered_map<string, double> values = v;
//    while (!pf.IsEmpty()) {
//        rpf.push(pf.Top());
//        pf.pop();
//    }
//
//
//    while (!rpf.IsEmpty()) {
//        if (is_op(rpf.Top())) {
//            double b = vars.Top();
//            vars.pop();
//            double a = vars.Top();
//            vars.pop();
//            vars.push(make_op(a, b, rpf.Top()[0]));
//            rpf.pop();
//
//        }
//        else {
//            if (values.find(rpf.Top()) != values.end()) {
//                vars.push(values[rpf.Top()]);
//                rpf.pop();
//                continue;
//            }
//            else {
//                if (is_number(rpf.Top())) {
//                    vars.push(stod(rpf.Top()));
//                    rpf.pop();
//                }
//                else if (values.find(rpf.Top()) == values.end()) {
//                    cout << "Type value of " << rpf.Top() << '\n';
//                    cin >> values[rpf.Top()];
//                    vars.push(values[rpf.Top()]);
//                    rpf.pop();
//
//                }
//            }
//        }
//    }
//    return vars.Top();
//}







//
//                  ListStack
//


//string postfixform(string input, ListStack<string>& names) {
//    input.push_back(' ');
//
//    ListStack<char> op; // (1)
//    string name;
//    string answ;
//    for (int i = 0; i < input.size(); i++) {
//        char el = input[i];
//
//        if (el == '(') {
//            if (name.size() != 0) {
//                 
//                answ += name; //
//                 
//                name.clear();
//            }
//            op.push(el);
//            continue;
//        }
//
//        if (is_op(el)) {
//            if (i == (input.size() - 1)) {
//                throw "wrong expression";
//            }
//            if (el == '-' && '1' <= input[i + 1] && input[i + 1] <= '9') {
//                name.push_back(el);
//                continue;
//            }
//            else if (el == '-' && input[i + 1] == '0') {
//                throw "wrong expression";
//            }
//            if (is_op(input[i - 1])) {
//                if (el == '-' && '1' <= input[i + 1] && input[i + 1] <= '9') {
//                    name.push_back(el);
//                    continue;
//                }
//                if (input[i + 1] == '0') {
//                    throw "wrong expression";
//                }
//            }
//
//
//            if (name.size() != 0) {
//                 
//                answ += name; //
//                 
//                name.clear();
//            }
//
//            while (!op.IsEmpty() && op_priority(el) < op_priority(op.Top())) {
//                string tmp;
//                tmp.push_back(op.Top());
//                 
//                answ.push_back(op.Top()); //
//                 
//                op.pop();
//            }
//
//            op.push(el);
//            continue;
//        }
//
//        if (el == ')') {
//            if (name.size() != 0) {
//                 
//                answ += name; //
//                 
//                name.clear();
//            }
//
//            while (!op.IsEmpty() && op.Top() != '(') {
//                string tmp;
//                tmp.push_back(op.Top());
//                 
//                answ.push_back(op.Top()); //
//                 
//                op.pop();
//            }
//            /*if (op.IsEmpty()) {
//                throw "wrong expression";
//            }*/
//            op.pop();
//            continue;
//        }
//
//        if (el == ' ') {
//            if (name.size() != 0) {
//                 
//                answ += name; //
//                answ += " ";
//                name.clear();
//            }
//            continue;
//        }
//
//        name.push_back(el);
//    }
//
//    while (!op.IsEmpty()) {
//        string tmp;
//        tmp.push_back(op.Top());
//         
//        answ.push_back(op.Top()); //
//         
//        op.pop();
//    }
//
//    input.pop_back();
//    return answ;
//}
//
//
//
//double solvepf(ListStack<string>& pf) {
//    ListStack<double> vars; // variables
//    ListStack<string> rpf; // reversed pf
//    unordered_map<string, double> values;
//    while (!pf.IsEmpty()) {
//        rpf.push(pf.Top());
//        pf.pop();
//    }
//
//
//    while (!rpf.IsEmpty()) {
//        if (is_op(rpf.Top())) {
//            double b = vars.Top();
//            vars.pop();
//            double a = vars.Top();
//            vars.pop();
//            vars.push(make_op(a, b, rpf.Top()[0]));
//            rpf.pop();
//
//        }
//        else {
//            if (values.find(rpf.Top()) != values.end()) {
//                vars.push(values[rpf.Top()]);
//                rpf.pop();
//                continue;
//            }
//            else {
//                if (is_number(rpf.Top())) {
//                    vars.push(stod(rpf.Top()));
//                    rpf.pop();
//                }
//                else if (values.find(rpf.Top()) == values.end()) {
//                    cout << "Type value of " << rpf.Top() << '\n';
//                    cin >> values[rpf.Top()];
//                    vars.push(values[rpf.Top()]);
//                    rpf.pop();
//
//                }
//            }
//        }
//    }
//
//    return vars.Top();
//}
//
//
//
//double test_solvepf(ListStack<string>& pf, unordered_map<string, double> v) {
//    ListStack<double> vars; // variables
//    ListStack<string> rpf; // reversed pf
//    unordered_map<string, double> values = v;
//    while (!pf.IsEmpty()) {
//        rpf.push(pf.Top());
//        pf.pop();
//    }
//
//
//    while (!rpf.IsEmpty()) {
//        if (is_op(rpf.Top())) {
//            double b = vars.Top();
//            vars.pop();
//            double a = vars.Top();
//            vars.pop();
//            vars.push(make_op(a, b, rpf.Top()[0]));
//            rpf.pop();
//
//        }
//        else {
//            if (values.find(rpf.Top()) != values.end()) {
//                vars.push(values[rpf.Top()]);
//                rpf.pop();
//                continue;
//            }
//            else {
//                if (is_number(rpf.Top())) {
//                    vars.push(stod(rpf.Top()));
//                    rpf.pop();
//                }
//                else if (values.find(rpf.Top()) == values.end()) {
//                    cout << "Type value of " << rpf.Top() << '\n';
//                    cin >> values[rpf.Top()];
//                    vars.push(values[rpf.Top()]);
//                    rpf.pop();
//
//                }
//            }
//        }
//    }
//    return vars.Top();
//}
