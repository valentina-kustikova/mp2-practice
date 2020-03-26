#pragma once

#include <time.h>
#include <random>

#include "TGraph.h"
#include "TException.h"

static class TGenerator
{
public:
    //Возврат массива размера size заполненого случайными значениями меньше max
    static int* getRandomArray(size_t size, int max);
    //Возврат случайного связного графа, содержаего гамильтонов цикл
    static TGraph getRandomConnectedGraph(size_t size);
};

