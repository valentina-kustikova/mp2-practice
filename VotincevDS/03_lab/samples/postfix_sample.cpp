#include "postfix_form.h"
using namespace std;

int main()
{
    // -1+33-A*-5+AA-A/(A-AA)
    string tmp = "-1--2--3--4+-5-6";
    /*cout << "Type expression: \n";
    getline(cin,tmp);*/
    ArrayStack<string> s2;
    string pf = postfixform(tmp,s2);
    cout << tmp << '\n';
    cout << pf << '\n';
    cout << "Result: " << solvepf(s2);
    return 0;
}
