#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double re;
    double im;

public:
    Complex();
    Complex(double real);
    Complex(double real, double imag);
    Complex(const Complex& other);

    double modulus() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
};

#endif