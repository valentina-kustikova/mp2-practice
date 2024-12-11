#include <iostream>
#include "postfix_form.h"
#include <unordered_map>
#include <string>
#include <vector>


#include <sstream>
#include <cctype> 

using namespace std;



ArithmeticExpression::ArithmeticExpression(const string& s1, STACK_IMPL impl1) {
    expr = convert(s1);
    impl = impl1;
}


vector<string> ArithmeticExpression::convert(const string& input) {
    string expr = removeSpaces(input);
    vector<string> tokens;
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
            tokens.push_back(ss.str());
            tokens.push_back(std::string(1, c));
            ss.str(""); //очистка
        }
        else if (c == '(' || c == ')') {
            if (!ss.str().empty()) {
                tokens.push_back(ss.str());
                ss.str(""); //очистка
            }
            tokens.push_back(std::string(1, c));
        }
        else if (std::isdigit(c) || c == '.') { //Handle numbers with decimal points
            ss << c;
        }
        else if (!std::isspace(c)) { // Handle other characters (variables, etc.)
            ss << c;
        }
    }

    if (!ss.str().empty()) {
        tokens.push_back(ss.str());
    }

    return tokens;
        //string expr = removeSpaces(input);
        //vector<string> answ;
        //string name; // название переменной/операция

        //for (int i = 0; i < expr.size(); i++) {
        //    char el = expr[i];

        //    if (el == '(') {
        //        if (name.size() != 0) {
        //             
        //            answ.push_back(name); //
        //            name.clear();
        //        }
        //        continue;
        //    }

        //    if (is_op(el)) {
        //        if (i == (input.size()-1)) {
        //            throw "wrong expression";
        //        }
        //        if (el == '-' && '1' <= input[i + 1] && input[i + 1] <= '9') {
        //            name.push_back(el);
        //            continue;
        //        }
        //        else if (el == '-' && input[i + 1] == '0') {
        //            throw "wrong expression";
        //        }
        //        if (is_op(input[i - 1])) {
        //            if (el == '-' && '1' <= input[i + 1] && input[i + 1] <= '9') {
        //                name.push_back(el);
        //                continue;
        //            }
        //            if (input[i + 1] == '0') {
        //                throw "wrong expression";
        //            }
        //        }


        //        if (name.size() != 0) {
        //            
        //            answ.push_back(name);
        //            answ.push_back(string(1, el));

        //            name.clear();
        //        }

        //        continue;
        //    }

        //    if (el == ')') {
        //        if (name.size() != 0) {

        //            answ.push_back(name);

        //            name.clear();
        //        }
        //        continue;
        //    }

        //    if (el == ' ') {
        //        if (name.size() != 0) {
        //             
        //            answ.push_back(name); 
        //            name.clear();
        //        }
        //        continue;
        //    }

        //    name.push_back(el);
        //}
        //answ.push_back(name);
        //return answ;
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
    else if (el == '-') {
        return 2;
    }
    else if (el == '+') {
        return 1;
    }
    return 0;

    // операция - имеет свой приоритет
    // тк постфиксная форма не будет
    // строиться правильно


    /*if (el == '*' || el == '/') {
        return 3;
    }
    else if (el == '+' || el == '-') {
        return 2;
    }
    return 1;*/
}




//unordered_map<string, double> fill_variables(const vector<string>&);
//double compute(const vector<string>&, const unordered_map<string, double>&);


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
//double make_op(double a, double b, char op) {
//    switch (op)
//    {
//    case '+': return a + b;
//    case '-': return a - b;
//    case '*': return a * b;
//    case '/': return a / b;
//    default:
//        break;
//    }
//}
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
