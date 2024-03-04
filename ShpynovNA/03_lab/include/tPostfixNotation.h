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
    string expression;                      //string that was recieved
    vector<operand> vars;                   //stores variables
    vector<string> expression_refined;      //separated each unit
    vector<string> expression_postfixed;    //postfixed expression,  
    int get_operator_priority(const string op);
    bool is_operator(const int i) const;
    bool is_operator(char c) const;
    bool is_operator(const string c) const;
    void divide_string();
    void add_a_new_variable(const string n);    
    double operation(double a, char op, double b);
    void create_postfixed_expression(TStack<string>& S);
public:

    void get_values_for_variables();
    void postfix_notation();
    int get_variables_amount(){
        return vars.size();
    }
    double calculate_the_result();
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

    bool evaluate_operator(const int i) const {
        return is_operator(i);
    }
    bool evaluate_operator(char i) const {
        return is_operator(i);
    }
    bool evaluate_operator(const string i) const {
        return is_operator(i);
    }
    double test_operation(double a, char op, double b) {
        return operation(a, op, b);
    }
    bool check_postfixed(vector<string> a) {
        return (a == expression_postfixed);
    }
    bool check_refined(vector<string> a) {
        return (a == expression_refined);
    }
};

#endif