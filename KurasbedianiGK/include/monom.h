#ifndef MP2_LAB4_POLYNOMS_MONOM_H
#define MP2_LAB4_POLYNOMS_MONOM_H

#include "power.h"
#include <ostream>

class Monom {
private:
    double coefficient;
    Power power;
public:
    explicit Monom(double _coefficient = 0.0, const Power &_power = Power{0, 0, 0});

    Monom(const Monom &_monom);

    ~Monom() = default;

    double get_coefficient() const;

    void set_coefficient(double _coefficient);

    const Power &get_power() const;

    void set_power(const Power &_power);

    bool operator==(const Monom &rhs) const;

    bool operator!=(const Monom &rhs) const;

    Monom &operator=(const Monom &rhs);

    bool operator<(const Monom &rhs) const;

    bool operator>(const Monom &rhs) const;

    bool operator<=(const Monom &rhs) const;

    bool operator>=(const Monom &rhs) const;

    Monom operator+(const Monom &rhs) const;

    Monom operator-(const Monom &rhs) const;

    Monom operator*(const Monom &rhs) const;

    Monom operator*(double _coefficient) const;

    friend Monom operator*(double _coefficient, const Monom &rhs);

    static std::string beautifyPower(int _power);

    friend std::ostream &operator<<(std::ostream &os, const Monom &_monom);
};

#endif //MP2_LAB4_POLYNOMS_MONOM_H
