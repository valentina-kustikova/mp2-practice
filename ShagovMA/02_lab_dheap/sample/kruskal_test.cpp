#include "kruskal's_algorithm.h"
#include <iostream>
#include <time.h>

int main()
{	
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
	bool flag = false;
	try
	{
		std::cin >> graph2;
		std::cout << "graph2" << std::endl;
		std::cout << graph2;
	}
	catch (const char* k)
	{
		std::cout << k << std::endl;
		flag == true;

	}
	std::cout << "<----------------------------------------------------------------------------->\n";
	std::cout << "Kruskal's algorithm for the graph2:" << std::endl;
	if (flag == false)
	{
		try
		{
			result = KruskalAlgorithm::kruskalAlgorithm(graph2);
			std::cout << result;
		}
		catch (const char* k)
		{
			std::cout << k;
		}
	}
	std::cout << "<----------------------------------------------------------------------------->\n";
}