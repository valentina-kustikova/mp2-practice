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
        throw TBadIdException();
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

TGraph::TGraph(size_t vertices_count_, size_t edges_count_)
{
    if (edges_count_ < vertices_count_ - 1) throw TBadSizeException();
    if (edges_count_ > vertices_count_ * (vertices_count_  - 1) / 2) throw TBadSizeException();

    vertices_count = vertices_count_;
    edges_count = edges_count_;
    edges = new TEdge[edges_count];
    srand(time(0));

    size_t j = 0;
    
    for (size_t i = 0; i < vertices_count - 1; i++)
    {
        TEdge edge = { i, i + 1, rand() % vertices_count };
        edges[j++] = edge;
    }
    while (j < edges_count)
    {
        TEdge edge = { rand() % vertices_count, rand() % vertices_count, rand() % vertices_count };
        if (this->isCorrect(edge))
        {
            edges[j++] = edge;
        }
    }
}

TGraph::TGraph(size_t vertices_count_, TEdge* edges_ , size_t edges_count_ )
{
    vertices_count = vertices_count_;
    edges_count = edges_count_;
    edges = new TEdge[edges_count];
    for (int i = 0; i < edges_count; i++)
    {
        if (this->isCorrect(edges_[i]))
        {
            edges[i] = edges_[i];
        }
        else
        {
            throw TBadEdgeException();
        }
    }
}

TGraph::TGraph(const TGraph& temp)
{
    edges_count = temp.edges_count;
    vertices_count = temp.vertices_count;
    edges = new TEdge[edges_count];
    for (size_t i = 0; i < edges_count; i++)
    {
        edges[i] = temp.edges[i];
    }
}

TGraph::~TGraph()
{
    delete[] edges;
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

    std::stack<size_t> stack;
    bool* group = new bool[vertices_count];
    for (size_t i = 0; i < vertices_count; i++)
    {
        group[i] = false;
    }
    
    stack.push(0);
    group[0] = true;

    while (!stack.empty())
    {
        size_t vertex = stack.top();
        stack.pop();
        for (size_t i = 0; i < edges_count; i++)
        {
            if (edges[i].incident(vertex) && !group[edges[i][vertex]])
            {
                stack.push(edges[i][vertex]);
                group[edges[i][vertex]] = true;
            }
        }
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
    if (edges_count > verticies_count* (verticies_count - 1) / 2) throw TBadSizeException();
    if (graph.edges != nullptr) delete[] graph.edges;
    graph.edges = new TEdge[edges_count];
    graph.vertices_count = verticies_count;
    graph.edges_count = edges_count;
    for (size_t i = 0; i < edges_count; i++)
    {
        TEdge edge;
        in >> edge;
        graph.edges[i] = edge;
    }
    return in;
}

bool TGraph::isCorrect(const TEdge& edge)
{
    if (edges_count >= vertices_count * (vertices_count - 1) / 2) return false;
    if ((edge.from >= vertices_count) || (edge.to >= vertices_count)) return false;
    if (edge.from == edge.to) return false;
    for (int i = 0; i < edges_count; i++)
    {
        if ((edges[i].incident(edge.from)) && (edges[i].incident(edge.to))) return false;
    }
    return true;
}