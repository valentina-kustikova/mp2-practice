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
	catch(const char* k)
	{
		std::cout << k << std::endl;
	}
	
	std::cout << "Kruskal's algorithm tests:\n";
	std::cout << "<----------------------------------------------------------------------------->\n";
	Graph graph1, graph2, result;
	Edge edgeGraph1[11] = 
	{
		Edge(0,1,8), Edge(1,5,2), Edge(5,0,2),
		Edge(0,4,3), Edge(1,4,0), Edge(1,3,1),
		Edge(3,4,3), Edge(3,2,5), Edge(1,2,10),
		Edge(4,2,2), Edge(2,5,9)
	};
	std::cout << "Attempt to create graph1: " << std::endl;
	try
	{
		graph1 = Graph(edgeGraph1, 6, 11);
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	std::cout << "graph1:" << std::endl << graph1;
	std::cout << "<----------------------------------------------------------------------------->\n";
	std::cout << "Kruskal's algorithm for the graph1:" << std::endl;
	try
	{
		result = KruskalAlgorithm::kruskalAlgorithm(graph1);
		std::cout << result;
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	std::cout << "<----------------------------------------------------------------------------->\n";
	std::cout << "Attempt to enter a graph2:" << std::endl;
	try
	{
		std::cin >> graph2;
		std::cout << "graph2" << std::endl;
		std::cout << graph2;
	}
	catch (const char* k)
	{
		std::cout << k;
		return 0;
	}
	std::cout << "<----------------------------------------------------------------------------->\n";
	std::cout << "Kruskal's algorithm for the graph2:" << std::endl;
	try
	{
		result = KruskalAlgorithm::kruskalAlgorithm(graph2);
		std::cout << result;
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	std::cout << "<----------------------------------------------------------------------------->\n";
}