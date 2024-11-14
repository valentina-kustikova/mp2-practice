#include "postfix_form.h"
using namespace std;

int main()
{
    ArrayStack<int> s1(1);
    string tmp = "A+B+C*D";
    string s1 = postfix_form(tmp);
    return 0;
}
