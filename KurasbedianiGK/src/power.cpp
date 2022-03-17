// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "power.h"

Power::Power(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}

Power::Power(const Power &power) : x(power.x), y(power.y), z(power.z) {}

Power &Power::operator=(const Power &rhs) {
    if (*this != rhs) {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
    }
    return *this;
}

bool Power::operator==(const Power &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           z == rhs.z;
}

bool Power::operator!=(const Power &rhs) const {
    return !(rhs == *this);
}

bool Power::operator<(const Power &rhs) const {
    if (x < rhs.x)
        return true;
    if (rhs.x < x)
        return false;
    if (y < rhs.y)
        return true;
    if (rhs.y < y)
        return false;
    return z < rhs.z;
}

bool Power::operator>(const Power &rhs) const {
    return rhs < *this;
}

bool Power::operator<=(const Power &rhs) const {
    return !(rhs < *this);
}

bool Power::operator>=(const Power &rhs) const {
    return !(*this < rhs);
}

Power Power::operator+(const Power &rhs) const {
    if (x + rhs.x > 9) {
        throw std::out_of_range("Power of x in resulting monom more than 9");
    }
    if (y + rhs.y > 9) {
        throw std::out_of_range("Power of y in resulting monom more than 9");
    }
    if (z + rhs.z > 9) {
        throw std::out_of_range("Power of z in resulting monom more than 9");
    }
    return Power{x + rhs.x, y + rhs.y, z + rhs.z};
}

std::ostream &operator<<(std::ostream &os, const Power &power) {
    os << "x: " << power.x << " y: " << power.y << " z: " << power.z;
    return os;
}
