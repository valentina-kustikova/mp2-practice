#include "stdafx.h"
#include "KruskalsAlgorithm.h"

Graph KruskalsAlgorithm::CreateGraph(const Graph& graph)
{
	// 1
	Set singletons(graph.GetCountVertices());
	for (int i = 0; i < graph.GetCountVertices(); i++)
		singletons.CreateOneElemSubset(i);
	// 2
	THeap<Edge> edges_set
	(graph.edges, graph.GetCountEdges(), graph.GetCountEdges(), 2);
	Graph result(graph.GetCountVertices());
	while (!edges_set.Empty()
		&& (result.GetCountEdges() != result.GetCountVertices() - 1))
	{
		// 3
		Edge e = edges_set.GetMinKey();
		// 4 - 6
		if (singletons.GetNameOfSubset(e.start)
			!= singletons.GetNameOfSubset(e.end))
		{
			singletons.UnitedSubsets(e.start, e.end);
			result.InsertEdge(e);
		}
	}
	return result;
}