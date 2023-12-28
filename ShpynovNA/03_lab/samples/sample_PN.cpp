#include "tPostfixNotation.h"
#include <vector>
int main()
{
    try {
        cout << "enter your expression:" << endl;
        string S;
        cin >> S;
        tPostfix P(S);
        cout << "your expression in postfix notation:" << endl << P << endl;
        cout << "now you can enter your variables' values and get a result" << endl;
        P.get_values_for_variables();
        cout << P.calculate_the_result();
    }
    catch (const char* s){
        cout << s << endl;
    }
}