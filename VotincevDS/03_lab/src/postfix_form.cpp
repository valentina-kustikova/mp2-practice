#include "postfix_form.h"


using namespace std;

template<typename T>
string postfix_form(string& input) {
    vector<string> elems;
    ArrayStack op<char>, names<string>;
    string name;
    for (int i = 0; i < input.size; i++) {
        char el = input[i];
        if (el == ' ') {
            i++;
            names.push(name);
            continue;
        }
        if (is_op(el)) {
            op.push(el);
            continue;
        }
        name.push_back(el);
    }

    return "";
}


bool is_op(char el) {
    return el == '*' || el == '\\' || el == '+' || el == '-' || el == '(';
}

