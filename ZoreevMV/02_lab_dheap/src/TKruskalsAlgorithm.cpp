#include "TKruskalsAlgorithm.h"

TGraph TKruskalsAlgorithm::findTree(const TGraph& graph)
{
    if (!graph.connected()) throw TWrongGraphException();
    TSet vertices(graph.getVerticiesCount());
    for (size_t i = 0; i < graph.getVerticiesCount(); i++)
        vertices.createSubset(i);
    TEdge* temp_edges = new TEdge[graph.getEdgesCount()];
    TEdge* result_edges = new TEdge[graph.getVerticiesCount()];
    for (size_t i = 0; i < graph.getEdgesCount(); i++)
        temp_edges[i] = graph.edges[i];
    THeap<TEdge> edges(graph.getEdgesCount(), graph.getEdgesCount(), temp_edges);

    size_t i = 0;
    while ((i != graph.getVerticiesCount() -1))
    {
        TEdge temp = edges.getMinKey();
        edges.removeMinKey();
        if (vertices.getSubsetName(temp.from) != vertices.getSubsetName(temp.to))
        {
            vertices.uniteSubsets(temp.from, temp.to);
            result_edges[i++] = temp;
        }
    }

    TGraph result(graph.getVerticiesCount(), result_edges, graph.getVerticiesCount() - 1);

    delete[] temp_edges;
    delete[] result_edges;

    return result;
}