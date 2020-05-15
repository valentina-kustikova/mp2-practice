#include "dijkstra's_algorithm.h"

int main()
{
	std::cout << "Dijkstra's algorithm tests:\n";
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
	std::cout << "Dijkstra's algorithm for the graph1:" << std::endl;
	try
	{
		std::vector<std::vector<int>> paths;
		float* dist;
		std::cout << "Enter start vertex" << std::endl;
		int start_vertex;
		std::cin >> start_vertex;
		DijkstrasAlgorithm::dijkstraAlgorithm(graph1, start_vertex, paths, dist);
		for (int i = 0; i < graph1.vertex_count; i++)
		{
			std::cout << "Path from " << start_vertex << " to " << i << ": ";
			for (int j = 0; j < paths[i].size() - 1; j++)
			{
				std::cout << paths[i][j] << "-";

			}
			std::cout << paths[i][paths[i].size() - 1];
			std::cout << " distance: " << dist[i];
			std::cout << std::endl;
		}
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
	std::cout << "Dijkstra's algorithm for the graph2:" << std::endl;
	try
	{
		std::vector<std::vector<int>> paths;
		float* dist;
		std::cout << "Enter start vertex" << std::endl;
		int start_vertex;
		std::cin >> start_vertex;
		DijkstrasAlgorithm::dijkstraAlgorithm(graph2, start_vertex, paths, dist);
		for (int i = 0; i < graph2.vertex_count; i++)
		{
			std::cout << "Path from " << start_vertex << " to " << i << ": ";
			for (int j = 0; j < paths[i].size() - 1; j++)
			{
				std::cout << paths[i][j] << "-";
			}
			std::cout << paths[i][paths[i].size() - 1];
			std::cout << " distance: " << dist[i];
			std::cout << std::endl;
		}
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	std::cout << "<----------------------------------------------------------------------------->\n";
}