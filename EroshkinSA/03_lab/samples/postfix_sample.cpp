#include <iostream>
#include <string>
#include "postfix_form.h"

using namespace std;

int main()
{
    try {
        string s;
        cout << "Insert expression: ";
        getline(cin, s);
        ArithmeticExpression one(s);
        cout << "Original expression: " << s << '\n';
        cout << "Postfix form: " << one.GetPostfixForm() << '\n';
        //one.GetValues();
        vector<pair<char, double>> values;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                bool f = 0;
                for (int j = 0; j < values.size(); j++) {
                    if (values[j].first == s[i]) {
                        f = 1;
                        break;
                    }
                }
                if (!f) {
                    double tmp;
                    cout << "Insert value of " << s[i] << ": ";
                    cin >> tmp;
                    values.push_back({ s[i], tmp });
                }
            }
        }
        cout << s << " = " << one.compute(values) << endl;
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
    return 0;
}
