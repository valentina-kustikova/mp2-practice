#include "postfix_form.h"



PostfixFormArray::PostfixFormArray(string in){
    map<string, int> operationPriority{
        {"(", 0},
        {"+", 1},
        {"-", 1},
        {"*", 2},
        {"/", 2}
    };
    inf_form = in;
    TArrayStack<string> stack(in.size());
    TArrayStack<string> stack2(in.size());
    post_form = "";
    for (int i = 0; i < in.size(); i++) {
        char c = in[i];
        if (isdigit(c))
        {
            string num = "";
            while (isdigit(c)) {//точно проверить
                char c = in[i];
                if (isdigit(c)) {
                    num += c;
                    i++;
                }
                else
                {
                    i--;
                    post_form += num;
                    break;
                }
            }
        }
        else if (c == ')')
        {
            while ((!(stack.IsEmpty())) && stack.Top() != string("(")) {
                post_form += stack.Top();
                stack.pop();
            }
            stack.pop();
        }
        else
        {
            string op;
            op[0] = c;
            while ((!(stack.IsEmpty())) && (operationPriority[stack.Top()] >= operationPriority[op])) {
                string tmp = stack.Top();
                post_form += tmp;
                stack.pop();
            }
            stack.push(op);
        }
    }
    while (!(stack.IsEmpty())) {
        post_form += stack.Top();
        stack.pop();
    }

};