#include "heapsort.h"
#include "exceptions.h"

#include <cmath>
#include <iostream>
#include <time.h>

using namespace std;

void Test_RandomArray()
{
    cout << endl << "RANDOM ARRAY IN [A, B]" << endl;
    float a, b;
    int size = 0;

    cout << "Enter the array size: ";
    cin >> size;
    if (size <= 0)
        throw Exception("Size must be positive!");

    cout << "Enter the A: ";
    cin >> a;
    cout << "Enter the B: ";
    cin >> b;
    if (a >= b)
        throw Exception("A < B!");

    float* elements = new float[size];
    for (int i = 0; i < size; i++)
    {
        elements[i] = (a * 10 + rand() % (int)(b * 10 - a * 10 + 1)) / 10;
        cout << elements[i] << " ";
    }

    cout << endl << "Sorting..." << endl;

    HeapSort<float>::Sort(elements, size);
    for (int i = 0; i < size; i++)
        cout << elements[i] << " ";

    cout << endl;
};

void Test_IncorrectSize()
{
    cout << endl << "INCORRECT SIZE -100 OF RANDOM ARRAY IN [-20; 20] " << endl;
    int* elements = new int[10];

    for (int i = 0; i < 10; i++)
    {
        elements[i] = rand() % 41 - 20;
        cout << elements[i] << " ";
    }
    cout << endl << "Size = -100" << endl;
    cout << "Sorting..." << endl;

    HeapSort<int>::Sort(elements, -100);

    for (int i = 0; i < 10; i++)
        cout << elements[i] << " ";

    cout << endl;
};
//----------------------------------------------------

void main()
{
    srand((unsigned int)time(0));

    cout << "##### HEAPSORT TESTS ######" << endl;

    try
    {
        Test_RandomArray();
    }
    catch (const Exception & ex)
    {
        cout << "[ERROR] " << ex.what() << endl << endl;
    }

    try
    {
        Test_IncorrectSize();
    }
    catch (const Exception & ex)
    {
        cout << "[ERROR] " << ex.what() << endl << endl;
    }
}