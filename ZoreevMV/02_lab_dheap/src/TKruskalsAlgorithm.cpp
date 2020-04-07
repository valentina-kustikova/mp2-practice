#include "TKruskalsAlgorithm.h"

TGraph TKruskalsAlgorithm::findTree(const TGraph& graph)
{
    if (!graph.connected()) throw TException(WrongGraph, __LINE__);
    TSet vertices(graph.getVerticiesCount());
    for (size_t i = 0; i < graph.getVerticiesCount(); i++)
        vertices.createSubset(i);
    TEdge* temp_edges = new TEdge[graph.getEdgesCount()];
    for (size_t i = 0; i < graph.getEdgesCount(); i++)
        temp_edges[i] = graph[i];
    THeap<TEdge> edges(2, graph.getEdgesCount(), graph.getEdgesCount(), temp_edges, false);

    TGraph result(graph.getVerticiesCount());

    while ((result.getEdgesCount() != result.getVerticiesCount() -1))
    {
        TEdge temp = edges.getMinKey();
        edges.removeMinKey();
        if (vertices.getSubsetName(temp.from) != vertices.getSubsetName(temp.to))
        {
            vertices.uniteSubsets(temp.from, temp.to);
            result.insertEdge(temp);
        }
    }

    delete[] temp_edges;

    return result;
}