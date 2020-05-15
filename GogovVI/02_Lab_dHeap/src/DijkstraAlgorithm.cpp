#include "DijkstraAlgorithm.h"

void DijkstraAlgorithm::dijkstraAlgorithm(const TGraph& graph, std::vector<std::vector<int>>& path, float*& resultDist, int vertexStart)
{
	if (graph.vertexCount == 0 || graph.edgesCount == 0 || graph.edges == nullptr)
		throw "Invalid graph.\n";
	float* distTGraph = new float[graph.vertexCount];
	int* up = new int[graph.vertexCount];
	Pair* distMark = new Pair[graph.vertexCount];
	for (int i = 0; i < graph.vertexCount; i++)
	{
		if (i == vertexStart)
			distMark[i].dist = 0;
		else
			distMark[i].dist = FLT_MAX;
		distMark[i].vertex = i;
		up[i] = 0;
	}
	THeap<Pair> marks(distMark, graph.vertexCount, 2);
	while (!marks.IsEmpty())
	{
		Pair minMark = marks.topMin();
		int index = 0, indexK = 0, indexN = 0;
		for (int i = 0; i < graph.edgesCount; i++)
		{
			if (graph.edges[i].IsIncidental(minMark.vertex))
			{
				for (int j = 0; j < marks.GetCurrentSize(); j++)
				{
					if (distMark[j].vertex == graph.edges[i].n)
						indexN = j;
					if (distMark[j].vertex == graph.edges[i].k)
						indexK = j;
				}
				if (minMark.dist + graph.edges[i].weight < distMark[indexN].dist)
				{
					distMark[indexN].dist = minMark.dist + graph.edges[i].weight;
					up[graph.edges[i].n] = minMark.vertex;
				}
				if (minMark.dist + graph.edges[i].weight < distMark[indexK].dist)
				{
					distMark[indexK].dist = minMark.dist + graph.edges[i].weight;
					up[graph.edges[i].k] = minMark.vertex;
				}
			}
		}
		distTGraph[minMark.vertex] = minMark.dist;
		marks.popMin();
	}
	resultDist = new float[graph.vertexCount];
	memcpy(resultDist, distTGraph, sizeof(float) * graph.vertexCount);
	path.resize(graph.vertexCount - 1);
	for (int i = 0; i < graph.vertexCount; i++)
	{
		float maxDistation = distTGraph[0];
		int maxDistationIndex = 0;
		for (int j = 1; j < graph.vertexCount; j++)
			if (maxDistation < distTGraph[j])
			{
				maxDistation = distTGraph[j];
				maxDistationIndex = j;
			}
		distTGraph[maxDistationIndex] = -1;
		if (maxDistationIndex == vertexStart)
			continue;
		int v = maxDistationIndex;
		while (v != vertexStart)
		{
			path[i].push_back(v);
			v = up[v];
		}
		path[i].push_back(vertexStart);
		std::reverse(path[i].begin(), path[i].end());
	}
	delete[] distMark;
	delete[] up;
	delete[] distTGraph;
}