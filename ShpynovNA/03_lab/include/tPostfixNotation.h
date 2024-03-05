#ifndef TPN_H_
#define TPN_H_

#include "tstack.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct operand {
    string name;
    double value;


    operand(string str, double num = 0) {
        name = str;
        value = num;
    }
};

class tPostfix {
private:
    string expression;                     
    vector<operand> vars;                  
    int get_operator_priority(const string op);
    void divide_string();
    void add_a_new_variable(const string n);    
    
protected:
    vector<string> expression_refined;
    vector<string> expression_postfixed;
    void create_postfixed_expression(TStack<string>& S);
    bool is_operator(const int i) const;
    bool is_operator(char c) const;
    bool is_operator(const string c) const;
    double operation(double a, char op, double b);

public:

    void get_values_for_variables();
    void postfix_notation();
    int get_variables_amount(){
        return vars.size();
    }
    double calculate_the_result();
    tPostfix() {};
    tPostfix(const string& S);
    friend ostream& operator<<(ostream& out, const tPostfix& p) {
        out << "current expression is:" << endl
            << p.expression << ";" << endl << endl;
        out << "postfixed:" << endl;
        for (int i = 0; i < p.expression_postfixed.size(); i++)
            out << p.expression_postfixed[i] << " ";
        out << endl;
        return out;
    }
};

#endif