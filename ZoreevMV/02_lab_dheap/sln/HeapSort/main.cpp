#include <iostream>
#include <time.h>
#include <random>


#include "TGenerator.h"
#include "THeapSort.h"

int main()
{
    size_t size;
    int max;
    std::cout << "Heap sort Demo" << std::endl;
    std::cout << "Please, input array size and top range" << std::endl;
    std::cin >> size >> max;
    int* array = TGenerator::getRandomArray(size, max);
    std::cout << "Initial array:" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    THeapSort::sort(size, array);
    std::cout << "Final array:" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}