#include "..\include\kruskal's_algorithm.h"
#include "..\include\DHeap.h"
#include "..\include\divided_set.h"

Graph KruskalAlgorithm::kruskalAlgorithm(const Graph & graph)
{
	DividedSet vertex(graph.vertex_count);
	Graph result;
	result.edges = new Edge[graph.vertex_count - 1];
	result.edges_count = graph.vertex_count - 1;
	result.vertex_count = graph.vertex_count;
	for (int i = 0; i < graph.vertex_count; i++)
	{
		vertex.createSingleton(i);
	}
	DHeap<Edge> edges(graph.edges, graph.edges_count);
	int t_count = 0;
	while ((t_count != graph.vertex_count - 1) && (!edges.IsEmpty()))
	{
		Edge edge = edges.popMin();
		int BSet = vertex.findSet(edge.k), ASet = vertex.findSet(edge.n);
		if (ASet != BSet)
		{
			vertex.createUnitedSet(ASet, BSet);
			result.edges[t_count] = edge;
			t_count++;
		}
	}
	return result;
}