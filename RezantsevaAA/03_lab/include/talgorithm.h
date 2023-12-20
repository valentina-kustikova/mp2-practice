
#ifndef __TALGORITHM_H__
#define __TALGORITHM_H__


#include "tstack.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
struct Operand
{
    bool isSign;  //true if operator
    std::string name; //A , B, X1, XY
    double value;
    friend std::ostream& operator<<(std::ostream& out, const Operand& op);
    void SetValue();
    bool isSpecified(); // то есть сделать без этой функции, при создании массива (вектора операндов) сразу заносить только уникальные
    //или использовать мапу
};

class Postfix
{
    //в полях хранить лексему, строку если нужно
private:
    std::vector<Operand> operands; //нужно хранить уникальные операнды
    std::string s_postfix;

    double calculateOperator(char operator_, double a, double b) const;
    int getCountNotSpecified();

    int GetPriority(const char op);
    bool isOperator(char c);
    std::pair<Operand, int> getOperand(std::string s, int pos);
public:
    Postfix(); 
    Postfix(const std::vector<Operand>& postf); // должен принимать строку и делать парсинг, разбивать на лексемы и проверять корректность и т.д
    std::string getStringView() const
    {
        return s_postfix;
    }
    void setValues();    
    double calculate() const;
    void setValuesFromVector(const std::vector<double>& values);
    Postfix ConvertToPol(const std::string& s);
};

#endif
