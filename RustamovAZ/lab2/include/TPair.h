#ifndef _TPAIR_H_
#define _TPAIR_H_

#include "TEdge.h"

struct TPair
{
    int vertex = 0;
    float distance = 0;

    bool operator<(const TPair& other) const;
    bool operator<=(const TPair& other) const;
    bool operator>(const TPair& other) const;
    bool operator>=(const TPair& other) const;
    bool operator==(const TPair& other) const;
    bool operator!=(const TPair& other) const;
};

#endif