#ifndef __TALGORITHM_H__
#define __TALGORITHM_H__

#include "tstack.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

class Postfix
{
    friend class PostfixTest;
private:
    std::vector<std::string> postfixArray; // хранит постфиксный вид
    std::string s_postfix; // хранит строковое представление постфиксной записи
    std::map<std::string, double> operands; // хранит уникальные операнды


    double calculateOperator(char operator_, double a, double b) const;
    int getCountNotSpecified();

    int GetPriority(const char op);
    bool isOperator(char c);
    bool isOperator(const std::string& str);
    std::pair<std::string, int> getOperand(const std::string& s, int pos); 


public:
    Postfix(); 
    Postfix(const std::vector<std::string>& postf); 
    std::string getStringView() const
    {
        return s_postfix;
    }
    void setValues(); // задать значение для 1 операнда
    double getValue(const std::string& name);  // задать значения для всех операндов
    double calculate();
    void setValuesFromVector(const std::vector<double>& values);
    Postfix ConvertToPol(const std::string& s);

    friend std::ostream& operator<<(std::ostream& out, const Postfix& op);
};

#endif
