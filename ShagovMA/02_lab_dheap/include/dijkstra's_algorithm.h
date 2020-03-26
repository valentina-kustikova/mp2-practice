#pragma once
#include "..\include\graph.h"
#include "..\include\DHeap.h"
#include <vector>

class DijkstrasAlgorithm
{
public:
	static void dijkstraAlgorithm(const Graph& graph, int vertex_start, std::vector<std::vector<int>>& path, float*& distGraph);
};

struct Pair
{
	int vertex;
	float weight;
	bool operator<(const Pair& pair);
};