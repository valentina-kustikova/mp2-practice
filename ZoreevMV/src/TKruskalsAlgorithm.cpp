#include "TKruskalsAlgorithm.h"

TGraph TKruskalsAlgorithm::findTree(const TGraph& graph)
{
    if (!graph.connected()) throw TException(WrongGraph, __LINE__);
    TSet vertices(graph.getVerticiesCount());
    for (int i = 0; i < graph.getVerticiesCount(); i++)
        vertices.createSubset(i);
    THeap<TEdge> edges(2, graph.getEdgesCount(), graph.getEdgesCount(), graph.edges);

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

    return result;
}