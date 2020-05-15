#include <cmath>
#include <iostream>
#include <time.h>

#include "heapsort.h"

using namespace std;

void main()
{
    cout << "HeapSort Demo" << endl;
    srand((unsigned int)time(0));

    try
    {
        float min, max;
        int size = 0;

        cout << "Input the array size: ";
        cin >> size;
        if (size <= 0)
            throw exception("Incorrect size");

        cout << "Input the minimum: ";
        cin >> min;
        cout << "Input the maximum: ";
        cin >> max;
        if (min >= max)
            throw exception("Incorrect borders");

        cout << "Initial array: " << endl;
        float* elements = new float[size];
        for (int i = 0; i < size; i++)
        {
            elements[i] = (min * 10 + rand() % (int)(max * 10 - min * 10 + 1)) / 10;
            cout << elements[i] << " ";
        }

        cout << endl << "Sorted array: " << endl;
        HeapSort<float>::Sort(elements, size);
        for (int i = 0; i < size; i++)
            cout << elements[i] << " ";

        cout << endl;
    }
    catch (const exception& ex)
    {
        cout << "Error: " << ex.what() << endl << endl;
    }
}