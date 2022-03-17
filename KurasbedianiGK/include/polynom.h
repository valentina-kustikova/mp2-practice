#ifndef MP2_LAB4_POLYNOMS_POLYNOM_H
#define MP2_LAB4_POLYNOMS_POLYNOM_H

#include "list.h"
#include <ostream>
#include <string>
#include <utility>
#include <sstream>
#include <vector>

class Polynom {
private:
    List<Monom> poly;
    std::string poly_name;
    std::vector<std::string> vector_lexemes;

public:
    explicit Polynom(const std::string &_poly_name, const List<Monom> &list = List<Monom>()); // const string&

    explicit Polynom(const List<Monom> &list = List<Monom>());

    explicit Polynom(const std::string &_poly_name, const Polynom &polynom);

    Polynom(const Polynom &polynom);

    const List<Monom> &get_poly() const;

    void set_poly(const List<Monom> &_poly);

    const std::string &get_name() const;

    void set_name(const std::string &new_name);

    bool check_string(const std::string &input);

    void parse(); // to private

    Polynom &operator=(const Polynom &rhs);

    Polynom operator+(const Polynom &rhs) const;

    Polynom operator+(double coef) const;

    friend Polynom operator+(double coef, const Polynom &rhs);

    Polynom operator-(const Polynom &rhs) const;

    Polynom operator-(double coef) const;

    friend Polynom operator-(double coef, const Polynom &rhs);

    Polynom operator*(const Polynom &rhs) const;

    Polynom operator*(double coef) const;

    friend Polynom operator*(double coef, const Polynom &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Polynom &polynom);
};

Polynom::Polynom(const std::string &_poly_name, const List<Monom> &list) : poly_name(_poly_name), poly(list) {}

Polynom::Polynom(const List<Monom> &list) : poly(list) {}

Polynom::Polynom(const std::string &_poly_name, const Polynom &polynom) : poly_name(_poly_name),
                                                                          poly(polynom.poly) {}

Polynom::Polynom(const Polynom &polynom) : poly_name(polynom.poly_name), poly(polynom.poly) {}

const List<Monom> &Polynom::get_poly() const {
    return poly;
}


void Polynom::set_poly(const List<Monom> &_poly) {
    poly = _poly;
}


const std::string &Polynom::get_name() const {
    return poly_name;
}


void Polynom::set_name(const std::string &new_name) {
    poly_name = new_name;
}


bool Polynom::check_string(const std::string &input_str) {
    using namespace std;

    int state = 0;
    string lexeme;
    string input{input_str};
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    size_t string_size = input.size();

    if (!input.empty()) {
        for (size_t i = 0; i < string_size; ++i) {
            char current_symbol = input[i];
            switch (state) {
                case 0: {
                    if (current_symbol == '+' || current_symbol == '-') {
                        state = 1;
                    } else if (isdigit(current_symbol)) {
                        state = 2;
                    } else if (current_symbol == 'x' || current_symbol == 'y' || current_symbol == 'z') {
                        state = 5;
                    } else {
                        throw runtime_error("Invalid character at position " + to_string(i + 1));
                    }
                    lexeme += current_symbol;
                    if ((current_symbol == '+' || current_symbol == '-')
                        && i != string_size - 1 && !isdigit(input[i + 1])) {
                        lexeme += '1';
                    }
                    break;
                }
                case 1: {
                    if (isdigit(current_symbol)) {
                        state = 2;
                    } else if (current_symbol == 'x' || current_symbol == 'y' || current_symbol == 'z') {
                        state = 5;
                    } else {
                        throw runtime_error("Invalid character at position " + to_string(i + 1));;
                    }
                    lexeme += current_symbol;
                    break;
                }
                case 2: {
                    if (current_symbol == '+' || current_symbol == '-') {
                        state = 1;
                        vector_lexemes.push_back(lexeme);
                        lexeme.clear();
                        lexeme += current_symbol;
                        if (i != string_size - 1 && !isdigit(input[i + 1])) {
                            lexeme += '1';
                        }
                    } else if (isdigit(current_symbol)) {
                        state = 2;
                        lexeme += current_symbol;
                    } else if (current_symbol == '.') {
                        state = 3;
                        lexeme += current_symbol;
                    } else if (current_symbol == 'x' || current_symbol == 'y' || current_symbol == 'z') {
                        state = 5;
                        lexeme += current_symbol;
                    } else {
                        throw runtime_error("Invalid character at position " + to_string(i + 1));;
                    }
                    break;
                }
                case 3: {
                    if (isdigit(current_symbol)) {
                        state = 4;
                    } else {
                        throw runtime_error("Invalid character at position " + to_string(i + 1));;
                    }
                    lexeme += current_symbol;
                    break;
                }
                case 4: {
                    if (current_symbol == '+' || current_symbol == '-') {
                        state = 1;
                        vector_lexemes.push_back(lexeme);
                        lexeme.clear();
                        lexeme += current_symbol;
                        if (i != string_size - 1 && !isdigit(input[i + 1])) {
                            lexeme += '1';
                        }
                    } else if (isdigit(current_symbol)) {
                        state = 2;
                        lexeme += current_symbol;
                    } else if (current_symbol == 'x' || current_symbol == 'y' || current_symbol == 'z') {
                        state = 5;
                        lexeme += current_symbol;
                    } else {
                        throw runtime_error("Invalid character at position " + to_string(i + 1));;
                    }
                    break;
                }
                case 5: {
                    if (current_symbol == '+' || current_symbol == '-') {
                        state = 1;
                        vector_lexemes.push_back(lexeme);
                        lexeme.clear();
                        lexeme += current_symbol;
                        if (i != string_size - 1 && !isdigit(input[i + 1])) {
                            lexeme += '1';
                        }
                    } else if (current_symbol == '^') {
                        state = 6;
                        lexeme += current_symbol;
                    } else {
                        throw runtime_error("Invalid character at position " + to_string(i + 1));;
                    }
                    break;
                }
                case 6: {
                    if (isdigit(current_symbol)) {
                        state = 7;
                    } else {
                        throw runtime_error("Invalid character at position " + to_string(i + 1));;
                    }
                    lexeme += current_symbol;
                    break;
                }
                case 7: {
                    if (current_symbol == '+' || current_symbol == '-') {
                        state = 1;
                        vector_lexemes.push_back(lexeme);
                        lexeme.clear();
                        lexeme += current_symbol;
                        if (i != string_size - 1 && !isdigit(input[i + 1])) {
                            lexeme += '1';
                        }
                    } else if (current_symbol == 'x' || current_symbol == 'y' || current_symbol == 'z') {
                        state = 5;
                        lexeme += current_symbol;
                    } else {
                        throw runtime_error("Invalid character at position " + to_string(i + 1));;
                    }
                    break;
                }
            }
        }
        vector_lexemes.push_back(lexeme);
        lexeme.clear();
        if (state == 1 || state == 3 || state == 6) {
            throw runtime_error("Invalid last character");
        }
    }
    if (vector_lexemes.empty()) {
        throw runtime_error("Empty poly");
    }
    return true;
}


void Polynom::parse() {
    using namespace std;
    for (const auto &lex: vector_lexemes) {
        auto pos_first_num = lex.find_first_of("+-0123456789");
        auto pos_first_var = lex.find_first_of("xyz");
        auto pos_x = lex.find('x');
        auto pos_y = lex.find('y');
        auto pos_z = lex.find('z');
        auto pos_x_with_power = lex.find("x^");
        auto pos_y_with_power = lex.find("y^");
        auto pos_z_with_power = lex.find("z^");

        double coef = [=] {
            if (pos_first_num == pos_x_with_power + 2 ||
                pos_first_num == pos_x_with_power ||
                pos_first_num == pos_y_with_power + 2 ||
                pos_first_num == pos_y_with_power ||
                pos_first_num == pos_z_with_power + 2 ||
                pos_first_num == pos_z_with_power) {
                return 1.0;
            } else {
                return stod(lex.substr(pos_first_num, pos_first_var - pos_first_num));
            }
        }();
        int power_x = [=] {
            if (pos_x == string::npos) {
                return 0;
            } else {
                if (pos_x_with_power == string::npos) {
                    return 1;
                } else {
                    stringstream s;
                    s << lex[pos_x_with_power + 2];
                    int res = -1;
                    s >> res;
                    return res;
                }
            }
        }();
        int power_y = [=] {
            if (pos_y == string::npos) {
                return 0;
            } else {
                if (pos_y_with_power == string::npos) {
                    return 1;
                } else {
                    stringstream s;
                    s << lex[pos_y_with_power + 2];
                    int res = -1;
                    s >> res;
                    return res;
                }
            }
        }();
        int power_z = [=] {
            if (pos_z == string::npos) {
                return 0;
            } else {
                if (pos_z_with_power == string::npos) {
                    return 1;
                } else {
                    stringstream s;
                    s << lex[pos_z_with_power + 2];
                    int res = -1;
                    s >> res;
                    return res;
                }
            }
        }();

        poly.insert(Monom{coef, Power{power_x, power_y, power_z}});
    }
}

Polynom &Polynom::operator=(const Polynom &rhs) {
    if (this != &rhs) {
        poly_name = rhs.poly_name;
        poly = rhs.poly;
    }
    return *this;
}

Polynom Polynom::operator+(const Polynom &rhs) const {
    if (poly.get_size() == 0 && rhs.poly.get_size() == 0) {
        return Polynom();
    } else if (poly.get_size() == 0 && rhs.poly.get_size() != 0) {
        return rhs;
    } else if (poly.get_size() != 0 && rhs.poly.get_size() == 0) {
        return *this;
    } else {
        Polynom res{poly_name + '+' + rhs.poly_name, *this};
        Node<Monom> *tmp = rhs.poly.get_head();
        while (tmp) {
            res.poly.insert(tmp->data);
            tmp = tmp->next;
        }
        delete tmp;
        return res;
    }
}


Polynom Polynom::operator+(double coef) const {
    return Polynom(poly_name + '+' + std::to_string(coef),
                   *this + Polynom(List<Monom>(new Node<Monom>(Monom(coef, Power{0, 0, 0}), nullptr))));
}


Polynom operator+(double coef, const Polynom &rhs) {
    return rhs + coef;
}


Polynom Polynom::operator-(const Polynom &rhs) const {
    Polynom res{'(' + poly_name + ')' + '-' + '(' + rhs.poly_name + ')', *this};
    Node<Monom> *tmp = rhs.poly.get_head();
    while (tmp) {
        res.poly.insert(-1.0 * tmp->data);
        tmp = tmp->next;
    }
    delete tmp;
    return res;
}


Polynom Polynom::operator-(double coef) const {
    return Polynom('(' + poly_name + ')' + '-' + '(' + std::to_string(coef) + ')',
                   *this - Polynom(List<Monom>(new Node<Monom>(Monom(coef, Power{0, 0, 0}), nullptr))));
}


Polynom operator-(double coef, const Polynom &rhs) {
    return Polynom('(' + std::to_string(coef) + ')' + '-' + '(' + rhs.poly_name + ')',
                   Polynom(List<Monom>(new Node<Monom>(Monom(coef, Power{0, 0, 0}), nullptr))) - rhs);
}


Polynom Polynom::operator*(const Polynom &rhs) const {
    Polynom res{'(' + poly_name + ')' + '*' + '(' + rhs.poly_name + ')'};
    Node<Monom> *tmpThis = poly.get_head();
    while (tmpThis) {
        Node<Monom> *tmpList = rhs.poly.get_head();
        while (tmpList) {
            res.poly.insert(tmpThis->data * tmpList->data);
            tmpList = tmpList->next;
        }
        tmpThis = tmpThis->next;
    }
    delete tmpThis;
    return res;
}


Polynom Polynom::operator*(double coef) const {
    return Polynom('(' + poly_name + ')' + '*' + std::to_string(coef),
                   *this * Polynom(List<Monom>(new Node<Monom>(Monom(coef, Power{0, 0, 0}), nullptr))));
}


Polynom operator*(double coef, const Polynom &rhs) {
    return Polynom(std::to_string(coef) + '*' + '(' + rhs.poly_name + ')',
                   rhs * Polynom(List<Monom>(new Node<Monom>(Monom(coef, Power{0, 0, 0}), nullptr))));
}


std::ostream &operator<<(std::ostream &os, const Polynom &polynom) {
    os << '"' << polynom.poly_name << '"' << " : " << polynom.poly;
    return os;
}

#endif //MP2_LAB4_POLYNOMS_POLYNOM_H
