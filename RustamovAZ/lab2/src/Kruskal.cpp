#include <cmath>
#include <algorithm>

#include "Kruskal.h"
#include "TDHeap.h"
#include "Edge.h"
#include "SeparatedSet.h"


#define D 3

using namespace std;

void Kruskal::Algorithm(const Graph& _graph, vector<vector<Edge> >& _newGraph)
{
    SeparatedSet vertices(_graph.GetVerticesCount());

    for (int i = 0; i < _graph.GetVerticesCount(); i++)
        vertices.CreateSingleton(i);

    Edge* listOfEdges = new Edge[_graph.GetVerticesCount() * (_graph.GetVerticesCount() - 1) / 2];
    int countOfEdges = 0;

    _graph.ListOfEdges(listOfEdges, countOfEdges);
    if (countOfEdges == 0)
        return;

    TDHeap<Edge> edgesHeap(listOfEdges, countOfEdges, D);
    edgesHeap.heapify();

    Edge* edgesNewGraph = new Edge[_graph.GetVerticesCount() - 1];
    int countOfNewEdges = 0;

    while (edgesHeap.GetSize() != 0)
    {
        Edge edge = edgesHeap.GetMin();
        int setStart = vertices.Definition(edge.startVertex);
        int setEnd = vertices.Definition(edge.endVertex);

        if (setStart != setEnd)
        {
            vertices.Unite(setStart, setEnd);
            edgesNewGraph[countOfNewEdges++] = edge;
        }

        edgesHeap.removeMinKey();
    }

    vector<int> nameOfConnect;

    for (int i = 0; i < countOfNewEdges; i++)
    {
        int j = 0;

        for (j = 0; j < i; j++)
            if (vertices.Definition(edgesNewGraph[i].startVertex) == vertices.Definition(edgesNewGraph[j].startVertex))
                break;

        if (j == i)
            nameOfConnect.push_back(vertices.Definition(edgesNewGraph[i].startVertex));
    }

    _newGraph.resize(nameOfConnect.size());

    for (int i = 0; i < countOfNewEdges; i++)
    {
        for (int j = 0; j < nameOfConnect.size(); j++)
        {
            if (vertices.Definition(edgesNewGraph[i].startVertex) == nameOfConnect[j])
                _newGraph[j].push_back(edgesNewGraph[i]);
        }
    }

    delete[] listOfEdges;
    delete[] edgesNewGraph;
};