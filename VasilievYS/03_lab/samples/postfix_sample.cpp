#include"postfix_form.h"
#include<iostream>
using namespace std;
int main()
{
    cout << "Arithmetic expression calculator\n";
    cout << "Enter your expression: ";
    string line;
    getline(cin, line);
    try 
    {
        ArithmeticExpression exp(line);
        string postfix = exp.GetPostfix();
        cout << "Postfix form: " << postfix << '\n';
        double res = exp.Compute(exp.MakeVectorPair());
        cout << "Result:" << res;
    }
    catch (const exception& ex)
    {
        cout << ex.what();
    }
    return 0;
}
