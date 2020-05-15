#include <iostream>
#include "KruskalAlgorithm.h"

int main()
{
	TGraph graph, result;
	Edge edgeGraph[11] = {
		Edge(0,1,8),
		Edge(1,5,2),
		Edge(5,0,2),
		Edge(0,4,3),
		Edge(1,4,0),
		Edge(1,3,1),
		Edge(3,4,3),
		Edge(3,2,5),
		Edge(1,2,10),
		Edge(4,2,2),
		Edge(2,5,9)
	};
	try
	{
		graph = TGraph(edgeGraph, 11, 6);
	}
	catch (const char* message)
	{
		std::cout << message;
	}
	std::cout << "Graph: \n" << graph;
	std::cout << "Kruskal's algorithm:\n";
	try
	{
		result = KruskalAlgorithm::kruskalAlgorithm(graph);
		std::cout << result;
	}
	catch (const char* message)
	{
		std::cout << message;
	}
	std::cout << "-------------------------------------------------------------------\n";
	try
	{
		std::cin >> graph;
		std::cout << "Kruskal's algorithm:\n";
		result = KruskalAlgorithm::kruskalAlgorithm(graph);
		std::cout << result;
	}
	catch (const char* message)
	{
		std::cout << message;
	}
	std::cout << "-------------------------------------------------------------------\n";
}
