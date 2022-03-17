#ifndef MP2_LAB4_POLYNOMS_POWER_H
#define MP2_LAB4_POLYNOMS_POWER_H

#include <ostream>

struct Power {
    int x;
    int y;
    int z;

    explicit Power(int _x = -1, int _y = -1, int _z = -1);

    Power(const Power &power);

    Power &operator=(const Power &rhs);

    bool operator==(const Power &rhs) const;

    bool operator!=(const Power &rhs) const;

    bool operator<(const Power &rhs) const;

    bool operator>(const Power &rhs) const;

    bool operator<=(const Power &rhs) const;

    bool operator>=(const Power &rhs) const;

    Power operator+(const Power &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Power &power);
};


#endif //MP2_LAB4_POLYNOMS_POWER_H
