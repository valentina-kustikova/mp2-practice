#include <iostream>
#include "HeapSort.h"
#include "time.h"

int main()
{
	srand((unsigned int)time(0));
	int size = 5 + rand() % 10;
	float* elements = new float[size];
	std::cout << "Elements: ";
	for (int i = 0; i < size; i++)
	{
		elements[i] = 1 + rand() / (RAND_MAX / (100 - 1));
		std::cout << elements[i] << "|";
	}
	std::cout << std::endl;
	try
	{
		THeap<float> heapElements = THeap<float>(elements, size);
		std::cout << "Heap: " << heapElements;
		std::cout << "Heap sort: ";
		HeapSort::heapSort(heapElements);
		std::cout << heapElements;
	}
	catch (const char* message)
	{
		std::cout << message;
	}

	delete[] elements;
}