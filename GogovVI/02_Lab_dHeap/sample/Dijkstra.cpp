#include <iostream>
#include "DijkstraAlgorithm.h"

int main()
{
	TGraph graph, result;
	Edge edgeGraph[13] = {
		Edge(0,1,5),
		Edge(0,2,8),
		Edge(0,3,11),
		Edge(1,2,2),
		Edge(1,4,4),
		Edge(2,3,3),
		Edge(2,4,2),
		Edge(3,5,8),
		Edge(4,5,6),
		Edge(4,7,1),
		Edge(5,6,13),
		Edge(5,7,24),
		Edge(6,7,5),
	};
	try
	{
		graph = TGraph(edgeGraph, 13, 8);
	}
	catch (const char* message)
	{
		std::cout << message;
	}
	std::cout << "Graph: \n" << graph;

	std::vector<std::vector<int>> path;
	std::cout << "Dijkstra's algorithm:\n";
	float* result_dist;
	try
	{
		DijkstraAlgorithm::dijkstraAlgorithm(graph, path, result_dist);
		for (int i = 0; i < path.size(); i++)
		{
			int current_size = path[i].size();
			for (int j = 0; j < current_size; j++)
			{
				if (j != current_size - 1)
					std::cout << path[i][j] << "-";
				else
					std::cout << path[i][j] << " Distance: " << result_dist[path[i][j]];
			}
			std::cout << std::endl;
		}
		delete[] result_dist;
		path.clear();
	}
	catch (const char* message)
	{
		std::cout << message;
	}
	std::cout << "-------------------------------------------------------------------\n";
	std::cout << "Dijkstra's algorithm:\n";
	try
	{
		std::cin >> graph;
		std::cout << graph;
		DijkstraAlgorithm::dijkstraAlgorithm(graph, path, result_dist);
		for (int i = 0; i < path.size(); i++)
		{
			int current_size = path[i].size();
			for (int j = 0; j < current_size; j++)
			{
				if (j != current_size - 1)
					std::cout << path[i][j] << "-";
				else
					std::cout << path[i][j] << " Distance: " << result_dist[path[i][j]];
			}
			std::cout << std::endl;
		}
		delete[] result_dist;
		path.clear();
	}
	catch (const char* message)
	{
		std::cout << message;
	}
}