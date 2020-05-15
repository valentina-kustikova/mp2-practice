#include "KruskalAlgorithm.h"

TGraph KruskalAlgorithm::kruskalAlgorithm(const TGraph& graph)
{
	if (graph.vertexCount == 0 || graph.edgesCount == 0 || graph.edges == nullptr)
		throw "Invalid graph.\n";
	TSplitSet vertex(graph.vertexCount);
	TGraph result;
	result.vertexCount = graph.vertexCount;
	result.edges = new Edge[graph.vertexCount - 1];
	for (int i = 0; i < graph.vertexCount; i++)
	{
		vertex.createSingleton((i));
	}
	THeap<Edge> tEdges(graph.edges, graph.edgesCount, 2);
	int tCount = 0;
	while ((tCount != graph.vertexCount - 1) && (!tEdges.IsEmpty()))
	{
		Edge edge = tEdges.popMin();
		int firstSet = vertex.findSet(edge.k), secondSet = vertex.findSet(edge.n);
		if (firstSet != secondSet)
		{
			vertex.createUnitedSet(firstSet, secondSet);
			result.edges[tCount] = edge;
			tCount++;
		}
	}
	result.edgesCount = tCount;
	return result;
}