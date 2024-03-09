#include "SupFunctions.h"

double Quadruple(double base, int degree) {
    int result = base;

    for (int i = 1; i < degree; i++)
    {
        result *= base;
    }

    return result;
}

int min(int x, int y) {
    int min_value;
    if (x > y) {
        return y;
    }
    else if (x < y) {
        return x;
    }
    else if (x == y) {
        return x;
    }
}