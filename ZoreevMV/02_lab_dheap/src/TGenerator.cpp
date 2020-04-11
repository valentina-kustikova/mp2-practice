#include "TGenerator.h"

int* TGenerator::getRandomArray(size_t size, int max)
{
    if (size == 0) throw TBadSizeException();
    srand(time(0));
    int* result = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        result[i] = rand() % max;
    }
    return result;
}

