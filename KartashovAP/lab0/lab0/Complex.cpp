#include "Complex.h"

Complex::Complex() : re(0.0), im(0.0) {}

Complex::Complex(double real) : re(real), im(0.0) {}

Complex::Complex(double real, double imag) : re(real), im(imag) {}

Complex::Complex(const Complex& other) : re(other.re), im(other.im) {}

double Complex::modulus() const {
    return sqrt(re * re + im * im);
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(re - other.re, im - other.im);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(re * other.re - im * other.im,
        re * other.im + im * other.re);
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.re * other.re + other.im * other.im;
    if (denom == 0.0) {
        cerr << "ќшибка: деление на ноль!" << endl;
        return Complex(0, 0);
    }
    return Complex((re * other.re + im * other.im) / denom, (im * other.re - re * other.im) / denom);
}

Complex& Complex::operator++() {
    re += 1.0;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    re += 1.0;
    return temp;
}

Complex& Complex::operator--() {
    re -= 1.0;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(*this);
    re -= 1.0;
    return temp;
}

bool Complex::operator==(const Complex& other) const {
    return re == other.re && im == other.im;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Complex& c) {
    os << "(" << c.re;
    if (c.im >= 0) os << " + " << c.im << "i)";
    else           os << " - " << -c.im << "i)";
    return os;
}

istream& operator>>(istream& is, Complex& c) {
    cout << "¬ведите действительную часть: ";
    is >> c.re;
    cout << "¬ведите мнимую часть: ";
    is >> c.im;
    return is;
}