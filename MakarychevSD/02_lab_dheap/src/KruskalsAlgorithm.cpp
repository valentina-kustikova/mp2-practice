#include "KruskalsAlgorithm.h"

Graph KruskalsAlgorithm::MinWeightTree(const Graph& G)
{
	if (!G.IsConnected())
		throw M_Exeption("the graph is disconnected");
	int numGEdges = G.GetnumEdges();
	int numGVertex = G.GetnumVertex();
	DivSets coll(numGVertex);
	for (int i = 0; i < numGVertex; i++)
		coll.MakeSingletone(i);
	WeightedEdge* TmpEdges = new WeightedEdge[numGEdges];
	WeightedEdge* ResultEdges = new WeightedEdge[numGVertex - 1];
	for (int i = 0; i < numGEdges; i++)
		TmpEdges[i] = G.Edges[i];
	THeap<WeightedEdge> e(3, numGEdges, numGEdges, TmpEdges);
	e.Hilling();
	int i = 0;
	while (i != numGVertex - 1)
	{
		WeightedEdge G = e.GetRoot();
		if (coll.Def(G.GetbeginV()) != coll.Def(G.GetendV()))
		{
			coll.UnSets(G.GetbeginV(), G.GetendV());
			ResultEdges[i] = G;
			i++;
		}
		e.RemoveMin();
	}
	Graph ResultGraph(numGVertex, numGVertex - 1, ResultEdges);
	delete[] TmpEdges;
	delete[] ResultEdges;
	return ResultGraph;
}