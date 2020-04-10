#include "TDijkstrasAlgorithm.h"

bool VertexDistance::operator<(const VertexDistance& temp)
{
    return (distance < temp.distance);
}

bool VertexDistance::operator>(const VertexDistance& temp)
{
    return (distance > temp.distance);
}

bool VertexDistance::operator==(const VertexDistance& temp)
{
    return (distance == temp.distance);
}


TGraph TDijkstrasAlgorithm::findTree(const TGraph& graph, size_t root)
{
    if (!graph.connected()) throw TWrongGraphException();
    VertexDistance* distance = new VertexDistance[graph.getVerticiesCount()];
    size_t* parent = new size_t[graph.getVerticiesCount()];

    for (size_t i = 0; i < graph.getVerticiesCount(); i++)
    {
        parent[i] = 0;
        distance[i].vertex = i;
        distance[i].distance = SIZE_MAX;
    }
    distance[root].distance = 0;

    THeap<VertexDistance> queue(graph.getVerticiesCount(), graph.getVerticiesCount(), distance);

    while (!queue.empty())
    {
        VertexDistance min = queue.getMinKey();
        for (size_t i = 0; i < graph.getEdgesCount(); i++)
        {
            if (graph.edges[i].incident(min.vertex))
            {
                size_t min_id, inc_id;             //Индексы вершиин в массиве dist
                size_t inc = graph.edges[i][min.vertex]; //Имя смежной вершины
                for (size_t i = 0; i < graph.getVerticiesCount(); i++)
                {
                    if (distance[i].vertex == min.vertex) min_id = i;
                    if (distance[i].vertex == inc) inc_id = i;
                }
                if (distance[min_id].distance + graph.edges[i].weight < distance[inc_id].distance)
                {
                    distance[inc_id].distance = distance[min_id].distance + graph.edges[i].weight;
                    parent[inc] = min.vertex;
                }
            }
        }
        queue.removeMinKey();
    }

    TEdge *edges = new TEdge[graph.getVerticiesCount()];
    size_t j = 0;

    for (size_t i = 0; i < root; i++)
    {
        TEdge temp;
        temp.from = parent[i];
        temp.to = i;
        double distance_from, distance_to;
        for (size_t i = 0; i < graph.getVerticiesCount(); i++)
        {
            if (distance[i].vertex == temp.from) distance_from = distance[i].distance;
            if (distance[i].vertex == temp.to) distance_to = distance[i].distance;
        }
        temp.weight = distance_to - distance_from;
        edges[j++] = temp;
    }
    for (size_t i = root + 1; i < graph.getVerticiesCount(); i++)
    {
        TEdge temp;
        temp.from = parent[i];
        temp.to = i;
        double distance_from, distance_to;
        for (size_t i = 0; i < graph.getVerticiesCount(); i++)
        {
            if (distance[i].vertex == temp.from) distance_from = distance[i].distance;
            if (distance[i].vertex == temp.to) distance_to = distance[i].distance;
        }
        temp.weight = distance_to - distance_from;
        edges[j++] = temp;
    }

    TGraph result(graph.getVerticiesCount(), edges, graph.getVerticiesCount() - 1);

    delete[] distance;
    delete[] parent;
    delete[] edges;

    return result;
}