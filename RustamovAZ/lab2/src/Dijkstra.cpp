#include <cmath>
#include <algorithm>

#include "Dijkstra.h"
#include "TDHeap.h"
#include "Edge.h"
#include "SeparatedSet.h"
#include "Pair.h"

#define D 3

void Dijkstra::Algorithm(const Graph& _graph, const int _start, vector<vector<int> >& _paths, float* _result)
{
    if (_start < 0 || _start >= _graph.GetVerticesCount())
        throw exception("Incorrect start vertexex!");

    if (!_graph.IsConnected())
        throw exception("Graph must be connect connected!");

    int* vertexices = new int[_graph.GetVerticesCount()];
    Pair* pairs = new Pair[_graph.GetVerticesCount()];

    for (int i = 0; i < _graph.GetVerticesCount(); i++)
    {
        pairs[i].distance = numeric_limits<float>::infinity();
        vertexices[i] = _start;
        pairs[i].vertex = i;
    }

    pairs[_start].distance = 0;

    TDHeap<Pair> markQueue(pairs, _graph.GetVerticesCount(), D);
    markQueue.heapify();

    float* adjMatrix = _graph.AdjacencyMatrix();

    while (markQueue.GetSize() != 0)
    {
        Pair mark = markQueue.GetMin();
        markQueue.removeMinKey();

        for (int i = 0; i < _graph.GetVerticesCount(); i++)
        {
            int idx = pairs[i].vertex * _graph.GetVerticesCount() + mark.vertex;

            if ((adjMatrix[idx] >= 0) && (mark.distance + adjMatrix[idx] < pairs[i].distance))
            {
                pairs[i].distance = mark.distance + adjMatrix[idx];
                vertexices[pairs[i].vertex] = mark.vertex;
                adjMatrix[idx] = adjMatrix[mark.vertex * _graph.GetVerticesCount() + pairs[i].vertex] = -1;
            }
        }

        markQueue.heapify();
    }

    for (int i = 0; i < _graph.GetVerticesCount(); i++)
        _result[pairs[i].vertex] = pairs[i].distance;

    _paths.resize(_graph.GetVerticesCount());

    for (int i = 0; i < _graph.GetVerticesCount(); i++)
    {
        int v = vertexices[i];
        int count = 1;
        _paths[i].resize(_graph.GetVerticesCount() - 1);

        while (v != _start)
        {
            _paths[i][count - 1] = v;
            v = vertexices[v];
            count++;
        }

        _paths[i][count - 1] = _start;
        _paths[i].resize(count);
        reverse(_paths[i].begin(), _paths[i].end());
    }

    delete[] vertexices;
    delete[] pairs;
};