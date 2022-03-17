#include "polynom.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void menu() {
    cout << "1. Add polynom" << endl;
    cout << "2. Delete polynom" << endl;
    cout << "3. Print polynoms" << endl;
    cout << "4. Execute expression" << endl;
    cout << "0. Exit" << endl;
}

void user_request() {
    int user_req = -1;
    vector<Polynom> polynoms;
    string poly_name, poly;
    do {
        menu();
        cin >> user_req;
        cout << endl;
        switch (user_req) {
            case 1: {
                cout << "Input polynom name: ";
//            getline(cin, poly_name);
                cin >> poly_name;
                cout << "Input polynom value: ";
//            getline(cin, poly);
                cin >> poly;
                Polynom polynom(move(poly_name));
                polynom.check_string(poly);
                polynom.parse();
                polynoms.push_back(polynom);
                break;
            }
            case 2: {
                cout << "Which polynom would you like to delete: ";
                cin >> poly_name;
                polynoms.erase(
                        remove_if(polynoms.begin(), polynoms.end(), [poly_name](const Polynom &p) {
                            return poly_name == p.get_name();
                        }),
                        polynoms.end());
                break;
            }
            case 3: {
                if (polynoms.empty()) {
                    cout << "You haven't any polynom yet!" << endl;
                } else {
                    for (const auto &i: polynoms) {
                        cout << i << endl;
                    }
                }
                break;
            }
            case 4: {
                string expr_str;
                Polynom expr_poly_res;
                vector<Polynom> expr_poly;
                vector<char> exp_operators;
                vector<string> exp_poly_names;

                cout << "Input expression with polynoms without brackets: ";
                cin >> expr_str;

                size_t index = 0;
                while ((index = expr_str.find_first_of("+-*")) != std::string::npos) {
                    exp_operators.push_back(expr_str[index]);
                    exp_poly_names.push_back(expr_str.substr(0, index));
                    expr_str.erase(0, index + 1);
                }
                exp_poly_names.push_back(expr_str);

                bool find = false;
                for (const auto &name: exp_poly_names) {
                    for (size_t i = 0; !find && i < polynoms.size(); ++i) {
                        if (name == polynoms[i].get_name()) {
                            find = true;
                            expr_poly.push_back(polynoms[i]);
                        }
                    }
                    if (!find) {
                        cout << name << "was not found!";
                        break;
                    }
                    find = false;
                }

                index = 0;
                expr_poly_res = expr_poly[index];
                ++index;
                for (char oper: exp_operators) {
                    switch (oper) {
                        case '+': {
                            expr_poly_res = expr_poly_res + expr_poly[index];
                            break;
                        }
                        case '-': {
                            expr_poly_res = expr_poly_res - expr_poly[index];
                            break;
                        }
                        case '*': {
                            expr_poly_res = expr_poly_res * expr_poly[index];
                            break;
                        }
                    }
                    ++index;
                }
                cout << expr_poly_res << endl;
                polynoms.push_back(expr_poly_res);

                break;
            }
            case 0: {
                cout << "EXIT" << endl;
                break;
            }
            default: {
                cout << "You input wrong value!" << endl;
                break;
            }
        }
        poly_name.clear();
        poly.clear();
    } while (user_req != 0);
}

int main() {
    try {
        user_request();
    } catch (const std::exception &_exception) {
        std::cout << _exception.what();
    }

    return 0;
}