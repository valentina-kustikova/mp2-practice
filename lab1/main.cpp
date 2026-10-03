#include <iostream>

using namespace std;

class Complex {
    
private:
    double re;
    double im;
public:
    
    Complex(double, double);
    Complex(const Complex&);
    Complex operator +(const Complex&);
    Complex operator -(const Complex&);
    Complex operator *(const Complex&);
    Complex operator *(double);
    Complex& operator++();
    Complex operator++(int);
    bool operator ==(const Complex&);
    bool operator !=(const Complex&);
    const Complex operator =(const Complex&);
    friend std::ostream& operator << (std::ostream& out, const Complex& complex) {
        if (complex.im > 0) {
            out << complex.re << " + " << complex.im << "i" << endl;
        }
        else if (complex.im == 0) {
            out << complex.re << endl;
        }
        else {
            out << complex.re << " - " << abs(complex.im) << "i" << endl;
        }
        return out;
    }
};

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}
Complex::Complex(const Complex& complex) {
    this->re = complex.re;
    this->im = complex.im;
}
Complex Complex::operator +(const Complex& complex) {
    this->re += complex.re;
    this->im += complex.im;
    return *this;
}

Complex Complex::operator -(const Complex& complex) {
    this->re -= complex.re;
    this->im -= complex.im;
    return *this;
}


Complex Complex::operator *(const Complex& c) {
    double newRe = re * c.re - im * c.im;
    double newIm = re * c.im + im * c.re;   
    return Complex(newRe, newIm);
}

Complex Complex::operator *(double number) {
    this->re *= number;
    this->im *= number;
    return *this;
}

bool Complex::operator ==(const Complex& complex) {
    return ((this->re == complex.re) && (this->im == complex.im));
}

const Complex Complex:: operator =(const Complex& complex) {
    this->re = complex.re;
    this->im = complex.im;
    return *this;
}

Complex& Complex::operator++() {
    ++re;
    ++im;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    ++re;
    ++im;
    return temp;
}

bool Complex::operator !=(const Complex& complex) {
    return !((this->re == complex.re) && (this->im == complex.im));
}

int main() {
    
    Complex a(1, 2);
    Complex b(3, -8);
    cout << "a = " << a;
    cout << "b = " << b;

    Complex copy(a);
    cout << "copy = " << copy;

    Complex a2(1, 2), b2(3, -8);
    Complex sum = a2 + b2;
    cout << "sum = " << sum;

    Complex a3(5, 5), b3(2, 3);
    Complex diff = a3 - b3;
    cout << "diff = " << diff;

    Complex a4(1, 2), b4(3, 4);
    Complex prod = a4 * b4;
    cout << "prod = " << prod;

    Complex a5(1, 2);
    Complex scaled = a5 * 3.0;
    cout << "scaled = " << scaled;

    Complex x(1, 2), y(1, 2), z(5, 5);
    cout << "x == y : " << (x == y) << endl;
    cout << "x == z : " << (x == z) << endl;
    cout << "x != y : " << (x != y) << endl;
    cout << "x != z : " << (x != z) << endl;

    Complex p(1, 2);
    Complex q = ++p;
    cout << "p = " << p;
    cout << "q = " << q;

    Complex m(1, 2);
    Complex n = m++;
    cout << "m = " << m;
    cout << "n = " << n;

    Complex r(0, 0), s(7, -3);
    r = s;
    cout << "r = " << r;
}