#ifndef _TPAIR_H_
#define _TPAIR_H_

#include "Edge.h"

struct Pair
{
    int vertex = 0;
    float distance = 0;

    bool operator<(const Pair& other) const;
    bool operator<=(const Pair& other) const;
    bool operator>(const Pair& other) const;
    bool operator>=(const Pair& other) const;
    bool operator==(const Pair& other) const;
    bool operator!=(const Pair& other) const;
};

#endif