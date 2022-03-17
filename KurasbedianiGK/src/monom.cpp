// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "monom.h"
#include <cmath>

Monom::Monom(double _coefficient, const Power &_power) {
    if (_power.x > 9 || _power.x < 0) {
        throw std::out_of_range("Wrong power of monom at x!");
    }
    if (_power.y > 9 || _power.y < 0) {
        throw std::out_of_range("Wrong power of monom at y!");
    }
    if (_power.z > 9 || _power.z < 0) {
        throw std::out_of_range("Wrong power of monom at z!");
    }

    coefficient = _coefficient;
    power = _power;
}

Monom::Monom(const Monom &_monom) : coefficient(_monom.coefficient), power(_monom.power) {}

double Monom::get_coefficient() const {
    return coefficient;
}

void Monom::set_coefficient(double _coefficient) {
    coefficient = _coefficient;
}

const Power &Monom::get_power() const {
    return power;
}

void Monom::set_power(const Power &_power) {
    if (_power.x > 9 || _power.x < 0) {
        throw std::out_of_range("Wrong power of monom at x!");
    }
    if (_power.y > 9 || _power.y < 0) {
        throw std::out_of_range("Wrong power of monom at y!");
    }
    if (_power.z > 9 || _power.z < 0) {
        throw std::out_of_range("Wrong power of monom at z!");
    }
    power = _power;
}

bool Monom::operator==(const Monom &rhs) const {
    return fabs(coefficient - rhs.coefficient) < 1e-8 &&
           power == rhs.power;
}

bool Monom::operator!=(const Monom &rhs) const {
    return !(rhs == *this);
}

Monom &Monom::operator=(const Monom &rhs) {
    if (rhs != *this) {
        coefficient = rhs.coefficient;
        power = rhs.power;
    }
    return *this;
}

bool Monom::operator<(const Monom &rhs) const {
    if (power == rhs.power) {
        return coefficient < rhs.coefficient;
    }
    return power < rhs.power;
}

bool Monom::operator>(const Monom &rhs) const {
    return rhs < *this;
}

bool Monom::operator<=(const Monom &rhs) const {
    return !(rhs < *this);
}

bool Monom::operator>=(const Monom &rhs) const {
    return !(*this < rhs);
}


Monom Monom::operator+(const Monom &rhs) const {
    if (power == rhs.power) {
        return Monom(coefficient + rhs.coefficient, power);
    } else
        throw std::logic_error("Can't add two monoms with different powers");
}

Monom Monom::operator-(const Monom &rhs) const {
    if (power == rhs.power) {
        return Monom(coefficient - rhs.coefficient, power);
    } else
        throw std::logic_error("Can't subtract two monoms with different powers");
}

Monom Monom::operator*(const Monom &rhs) const {
    if (power.x + rhs.power.x > 9) {
        throw std::out_of_range("Power of x in resulting monom more than 9");
    }
    if (power.y + rhs.power.y > 9) {
        throw std::out_of_range("Power of y in resulting monom more than 9");
    }
    if (power.z + rhs.power.z > 9) {
        throw std::out_of_range("Power of z in resulting monom more than 9");
    }
    if (power == Power{0, 0, 0} && rhs.power != Power{0, 0, 0}) {
        return coefficient * rhs;
    } else if (power != Power{0, 0, 0} && rhs.power == Power{0, 0, 0}) {
        return *this * rhs.coefficient;
    } else if (power == Power{0, 0, 0} && rhs.power == Power{0, 0, 0}) {
        return Monom(coefficient * rhs.coefficient, Power{0, 0, 0});
    } else {
        return Monom(coefficient * rhs.coefficient, power + rhs.power);
    }
}

Monom Monom::operator*(double _coefficient) const {
    return Monom(coefficient * _coefficient, power);
}

Monom operator*(double _coefficient, const Monom &rhs) {
    return Monom(rhs.coefficient * _coefficient, rhs.power);
}

std::string Monom::beautifyPower(int _power) {
    switch (_power) {
        /* case 0:
             return "\u2070";
         case 1:
             return "\u00B9";*/
        case 2:
            return "\u00B2";
        case 3:
            return "\u00B3";
        case 4:
            return "\u2074";
        case 5:
            return "\u2075";
        case 6:
            return "\u2076";
        case 7:
            return "\u2077";
        case 8:
            return "\u2078";
        case 9:
            return "\u2079";
        default:
            return "";
    }
}

std::ostream &operator<<(std::ostream &os, const Monom &_monom) {
    std::string xAndPowerOfX = (_monom.power.x != 0) ? "x" + Monom::beautifyPower(_monom.power.x) : "";
    std::string yAndPowerOfy = (_monom.power.y != 0) ? "y" + Monom::beautifyPower(_monom.power.y) : "";
    std::string zAndPowerOfZ = (_monom.power.z != 0) ? "z" + Monom::beautifyPower(_monom.power.z) : "";

    if (_monom.coefficient > 1e-8) {
        os << '+';
        if (fabs(_monom.coefficient - 1.0) > 1e-8 || _monom.power == Power{0, 0, 0}) {
            os << _monom.coefficient;
        }
        os << xAndPowerOfX << yAndPowerOfy << zAndPowerOfZ;
    } else {
        if (fabs(_monom.coefficient + 1.0) > 1e-8 || _monom.power == Power{0, 0, 0}) {
            os << _monom.coefficient;
        } else {
            os << '-';
        }
        os << xAndPowerOfX << yAndPowerOfy << zAndPowerOfZ;
    }

    return os;
}