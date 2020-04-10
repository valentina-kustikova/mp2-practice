#include "TGraph.h"

bool TEdge::incident(size_t vertex)
{
    return ((from == vertex) || (to == vertex));
}

TEdge& TEdge::operator=(const TEdge& temp)
{
    from = temp.from;
    to = temp.to;
    weight = temp.weight;
    return *this;
}

bool TEdge::operator<(const TEdge& temp) const
{
    return (weight < temp.weight);
}

bool TEdge::operator==(const TEdge& temp) const
{
    return (weight == temp.weight);
}

bool TEdge::operator>(const TEdge& temp) const
{
    return (weight > temp.weight);
}

bool TEdge::operator<=(const TEdge& temp) const
{
    return (weight <= temp.weight);
}

bool TEdge::operator>=(const TEdge& temp) const
{
    return (weight >= temp.weight);
}

size_t TEdge::operator[](size_t id) const
{
    if (id == from)
    {
        return to;
    }
    else if (id == to)
    {
        return from;
    }
    else
    {
        throw TBadIdException;
    }
}

std::ostream& operator<<(std::ostream& out, const TEdge& edge)
{
    out << "(" << edge.from << ", " << edge.to << ")" << "[" << edge.weight << "]";
    return out;
}

std::istream& operator>>(std::istream& in, TEdge& edge)
{
    in >> edge.from >> edge.to >> edge.weight;
    return in;
}


TGraph::TGraph(size_t vertices_count_)
{
    vertices_count = vertices_count_;
    edges_count = 0;
    edges = new TEdge[vertices_count * (vertices_count - 1) / 2];
}

TGraph::TGraph(size_t vertices_count_, TEdge* edges_ , size_t edges_count_ )
{
    vertices_count = vertices_count_;
    edges_count = edges_count_;
    edges = new TEdge[vertices_count * (vertices_count - 1) / 2];
    for (int i = 0; i < edges_count; i++)
    {
        insertEdge(edges_[i]);
    }
}

TGraph::TGraph(const TGraph& temp)
{
    edges_count = temp.edges_count;
    vertices_count = temp.vertices_count;
    edges = new TEdge[vertices_count * (vertices_count - 1) / 2];
    for (size_t i = 0; i < edges_count; i++)
    {
        edges[i] = temp.edges[i];
    }
}

TGraph::~TGraph()
{
    delete[] edges;
}

void TGraph::insertEdge(const TEdge& edge)
{
    if (edges_count >= vertices_count * (vertices_count - 1) / 2) throw TException(ContainerIsFull, __LINE__);
    if ((edge.from >= vertices_count) || (edge.to >= vertices_count)) throw TException(BadEdge, __LINE__);
    if (edge.from == edge.to) throw TException(BadEdge, __LINE__);
    for (int i = 0; i < edges_count; i++)
    {
        if ((edges[i].incident(edge.from)) && (edges[i].incident(edge.to))) return;
    }
    edges[edges_count] = edge;
    edges_count++;
    return;
}

size_t TGraph::getVerticiesCount() const
{
    return vertices_count;
}

size_t TGraph::getEdgesCount() const
{
    return edges_count;
}

bool TGraph::connected() const
{
    if (vertices_count == 0) return true;

    std::stack<size_t> queue;
    bool* group = new bool[vertices_count];
    for (size_t i = 0; i < vertices_count; i++)
    {
        group[i] = 0;
    }
    
    queue.push(0);
    group[0] = true;

    while (!queue.empty())
    {
        size_t vertex = queue.top();
        for (size_t i = 0; i < edges_count; i++)
        {
            if (edges[i].incident(vertex) && !group[edges[i][vertex]])
            {
                queue.push(edges[i][vertex]);
                group[edges[i][vertex]] = true;
            }
        }
        queue.pop();
    }

    for (size_t i = 0; i < vertices_count; i++)
    {
        if (!group[i])
        {
            delete[] group;
            return false;
        }
    }
    delete[] group;
    return true;
}

TGraph& TGraph::operator=(const TGraph& temp)
{
    if (&temp == this) return *this;
    edges_count = temp.edges_count;
    vertices_count = temp.vertices_count;
    if (edges != nullptr) delete[] edges;
    edges = new TEdge[vertices_count * (vertices_count - 1) / 2];
    for (size_t i = 0; i < edges_count; i++)
    {
        edges[i] = temp.edges[i];
    }
    return *this;
}

TEdge TGraph::operator[](size_t id) const
{
    if (id < edges_count)
    {
        return edges[id];
    }
    else
    {
        throw TException(BadId, __LINE__);
    }
}

std::ostream& operator<<(std::ostream& out, const TGraph& graph)
{
    for (int i = 0; i < graph.edges_count; i++)
    {
        out << graph.edges[i] << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, TGraph& graph)
{
    size_t verticies_count, edges_count;
    in >> verticies_count >> edges_count;
    if (edges_count > verticies_count* (verticies_count - 1) / 2) throw TException(BadSize, __LINE__);
    graph = TGraph(verticies_count);
    for (size_t i = 0; i < edges_count; i++)
    {
        TEdge edge;
        in >> edge;
        graph.insertEdge(edge);
    }
    return in;
}