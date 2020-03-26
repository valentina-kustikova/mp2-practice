#include "TGenerator.h"

int* TGenerator::getRandomArray(size_t size, int max)
{
    if (size == 0) throw TException(BadSize, __LINE__);
    srand(time(0));
    int* result = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        result[i] = rand() % max;
    }
    return result;
}

TGraph TGenerator::getRandomConnectedGraph(size_t size)
{
    if (size < 3) throw TException(BadSize, __LINE__);
    srand(time(0));
    TGraph result(size);
    for (size_t i = 0; i < size - 1; i++)
    {
        TEdge edge = { i, i + 1, rand() % size};
        result.insertEdge(edge);
    }
    size_t count = rand() % (size * (size - 1) / 2 - size + 1);
    for (size_t i = 0; i < count; i++)
    {
        try
        {
            TEdge edge = { rand() % size, rand() % size, rand() % size };
            result.insertEdge(edge);
        }
        catch (TException exception) {}; //На случай, плохого случайного ребра
    }
    return result;
}