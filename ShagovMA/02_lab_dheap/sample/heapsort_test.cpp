#include "..\include\kruskal's_algorithm.h"
#include <iostream>
#include <time.h>

int main()
{
	std::cout << "DHeap algorithms tests:\n";
	std::cout << "<----------------------------------------------------------------------------->\n";
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
	std::cout << "Attempt to create heap1(Elements):\n";
	try
	{
		DHeap<float> heap1(elements, size);
		std::cout << "heap1 created successfully" << std::endl;
		std::cout << "Attempt to output heap1(Elements):\n";
		std::cout << heap1;
		std::cout << "Attempt to sort heap1(Elements):\n";
		heap1.sort();
		std::cout << "Sorted heap1:" << std::endl;
		std::cout << heap1;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
	}
}