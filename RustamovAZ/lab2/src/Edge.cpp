#include "Edge.h"

Edge::Edge(int _startVertex, int _endVertex, int _weight)
{
    if (_startVertex <= _endVertex)
    {
        startVertex = _startVertex;
        endVertex = _endVertex;
        weight = _weight;
    }
    else
    {
        startVertex = _endVertex;
        endVertex = _startVertex;
        weight = _weight;
    }
    }

bool Edge::isIncidental(const Edge& other) const
{
    return isIncidental(other.startVertex) || isIncidental(other.endVertex);
}

bool Edge::isIncidental(int vertex) const
{
    return (startVertex == vertex) || (endVertex == vertex);
}

bool Edge::operator==(const Edge& edge) const
{
    return (weight == edge.weight) && ((startVertex == edge.startVertex) && (endVertex == edge.endVertex));
}

bool Edge::operator>(const Edge& edge) const
{
    return weight > edge.weight;
}

bool Edge::operator<(const Edge& edge) const
{
    return weight < edge.weight;
}

bool Edge::operator>=(const Edge& edge) const
{
    return weight >= edge.weight;
}

bool Edge::operator<=(const Edge& edge) const
{
    return weight <= edge.weight;
}

ostream& operator<<(ostream& _out, const Edge& _edge)
{
    _out << "Start: " << _edge.startVertex << " End: " << _edge.endVertex << " Weight: " << _edge.weight;

    return _out;
};
