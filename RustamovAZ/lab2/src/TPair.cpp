#include "Pair.h"

bool Pair::operator<(const Pair& other) const
{
    return distance < other.distance;
}

bool Pair::operator<=(const Pair& other) const
{
    return distance <= other.distance;
}

bool Pair::operator>(const Pair& other) const
{
    return distance > other.distance;
}

bool Pair::operator>=(const Pair& other) const
{
    return distance >= other.distance;
}

bool Pair::operator==(const Pair& other) const
{
    return (vertex == other.vertex) && (distance == other.distance);
}

bool Pair::operator!=(const Pair& other) const
{
    return !(*this == other);
}